#include <iostream>
#include <fstream>

#include "exceptionHandler/error.h"
#include "cpr/cpr.h"
#include "gumbo.h"

#include <chrono>




std::ofstream writeCsv("links.csv");


std::string extract_html_page()
{
	cpr::Url url = cpr::Url{
		//"https://en.wikipedia.org/wiki/Poppy_seed_defence" 
	"https://www.canuckaudiomart.com/classifieds/19-headphones/"
	};
	cpr::Response response = cpr::Get(url);

	if (Error::httpCheck(response.status_code, response.error)) {
		throw Error(response.error.message, errorTypes::HTTP);
	}
	std::ofstream outfile;
	outfile.open("outfile.txt", std::ios::out | std::ios::trunc);
	outfile << response.text << std::endl;
	outfile.close();
	//std::cout << response.text << std::endl;
	return response.text;
}

void search_for_title(GumboNode* node)
{
	if (node->type != GUMBO_NODE_ELEMENT) return;

	if (node->v.element.tag == GUMBO_TAG_H1)
	{
		GumboNode* title_text = static_cast<GumboNode*>(node->v.element.children.data[0]);
		//const char* name = gumbo_normalized_tagname(GUMBO_TAG_H1);
		//std::cout << name << "\n";
		if (title_text->type == GUMBO_NODE_TEXT)
		{
			std::cout << title_text->v.text.text << "\n";
		}
		else throw Error("title node is of wrong type");
		return;
	}

	GumboVector* children = &node->v.element.children;
	for (unsigned int i = 0; i < children->length; i++)
		search_for_title(static_cast<GumboNode*>(children->data[i]));
}


void filter_tablerows(GumboNode* trow)
{
	if (trow->type != GUMBO_NODE_ELEMENT) return;

	
}

void search_for_product_links(GumboNode* node)
{
	if (node->type != GumboNodeType::GUMBO_NODE_ELEMENT) return;

	if (node->v.element.tag == GUMBO_TAG_TBODY)
	{
		//revise: do some extra checking to exclude ads outside of CANADA
		

		GumboVector* children = &node->v.element.children;
		for (unsigned int i = 0; i < children->length; i++) {
			filter_tablerows(static_cast<GumboNode*>(children->data[i]));
		}
		


	}

}

void search_for_links(GumboNode* node)
{
	if (node->type != GUMBO_NODE_ELEMENT)
		return;

	if (node->v.element.tag == GUMBO_TAG_A)
	{
		GumboAttribute* href = gumbo_get_attribute(&node->v.element.attributes, "href");
		if (href)
		{
			std::string link = href->value;
			if (link.rfind("/wiki") == 0)
				writeCsv << "article," << link << "\n";
			else if (link.rfind("#cite") == 0)
				writeCsv << "cite," << link << "\n";
			else
				writeCsv << "other," << link << "\n";
		}
	}

	GumboVector* children = &node->v.element.children;
	for (unsigned int i = 0; i < children->length; i++)
	{
		search_for_links(static_cast<GumboNode*>(children->data[i]));
	}
}

int main()
{
	try {
		std::string page_content = extract_html_page();
		GumboOutput* parsed_response = gumbo_parse(page_content.c_str());
		search_for_title(parsed_response->root);

		writeCsv << "type,link" << "\n";
		search_for_links(parsed_response->root);
		writeCsv.close();
		// free the allocated memory
		gumbo_destroy_output(&kGumboDefaultOptions, parsed_response);
	}
	catch (Error& e) {
		e.printErrorMsg();
		const errorMessage& em = e.errorMsg();
		if (em.code == errorTypes::FATAL) {
			throw Error("This wasn't supposed to happen", errorTypes::FATAL);
		}
	}

}




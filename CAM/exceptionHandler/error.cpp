#include "error.h"

bool Error::httpInformational = false;

Error::Error(std::string& msg, errorTypes code) :
	msg{ msg }, code{ code }
{
}


const errorMessage& Error::errorMsg() {
	return errorMessage{ msg, code };
}


bool Error::httpCheck(long num, cpr::Error error) {
	if (!error) return false;
	std::cerr << "An HTTP error has occurred.\n"
		<< "Status Code: " << num << "\n"
		<< "Error Message: " << error.message << "\n";
	return true;
}

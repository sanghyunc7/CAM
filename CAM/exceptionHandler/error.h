#pragma once
#include <exception>
#include <string>
#include "errorTypes.h"
#include <iostream>
#include "cpr/cpr.h"


struct errorMessage {
	std::string msg;
	errorTypes code;
};

class Error : public std::exception
{	
protected:
	std::string msg;
	errorTypes code;

public:
	Error(std::string msg, errorTypes code = errorTypes::DEFAULT);
	const errorMessage& errorMsg();
	void printErrorMsg();
	// decide whether to consider http code 1XX as an error
	static bool httpInformational;

	// returns true if there is an httpError
	static bool httpCheck(long num, cpr::Error error);
};

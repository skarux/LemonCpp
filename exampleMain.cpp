#include <string>
#include "parser.hpp"

int main(int argc, char** argv)
{	
	std::string* extraParam =  new std::string("\"I am the extra parameter\"");
	LPMyParser parser;

	parser.parse( FIRST, new std::string("Ciao"), extraParam);
	parser.parse( SECOND, new std::string("come"), extraParam);
	parser.parse( THIRD, new std::string("va?"), extraParam);
	parser.parse( 0, NULL, extraParam);
	
	delete extraParam;
	
	return 0;
}


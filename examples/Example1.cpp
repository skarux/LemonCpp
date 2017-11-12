
/*
 * EXAMPLE .1
 * Lemon CPP parser example
 * with an extra parameter
 *
 */

#include <string>
#include "ParserExample1.hpp"

int main(int argc, char** argv)
{
	// extra parameter declaration; only a simple string in this case
	std::string* extraParam =  new std::string("\"I am the extra parameter\"");

	// parser declaration
	LP_PARSER_TYPE_P parser = new LP_PARSER_TYPE(extraParam);

	// add some token
	parser->parse( FIRST,  new std::string("Ciao"));
	parser->parse( SECOND, new std::string("come"));
	parser->parse( THIRD,  new std::string("va?"));
	parser->parse( 0, NULL);
	
	// flush memory
	delete parser;
	delete extraParam;
	
	return 0;
}

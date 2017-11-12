
/*
 * EXAMPLE .2
 * Lemon CPP parser example
 * without extra parameters
 *
 */

#include <string>
#include "ParserExample2.hpp"

int main(int argc, char** argv)
{
	// parser declaration
	LP_PARSER_TYPE_P parser = new LP_PARSER_TYPE();

	// add some token
	parser->parse( FIRST,  new std::string("Ciao"));
	parser->parse( SECOND, new std::string("come"));
	parser->parse( THIRD,  new std::string("va?"));
	parser->parse( 0, NULL);
	
	// flush memory
	delete parser;
	
	return 0;
}


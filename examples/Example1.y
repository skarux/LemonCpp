
%include 
{
	#include <string>
	#include <iostream>
	#include <assert.h>

	/* this can't be written in a %code block because otherwise it is added at the end of the parser */
	void stringDestructor(std::string* t)
	{
		delete t;
	}
}

%include_hpp
{
#include <iostream>
}

/* an extra parameter that will be available in each rule; it should be a pointer */
%extra_argument{ std::string* translation_params }

%syntax_error 
{  
	std::cerr << "Syntax error on token " << yymajor << std::endl;
}

/* define types for non-terminal symbols */
/*%type nonTerminalSymb1	{ MyClass* }*/
%type declaration { std::string* }

/* define destructors for non terminal symbols (if needed) */
/* !ATTENTION! it will be called as soon as an action is completed */
/*%destructor  nonTerminalSymb1 { token_destructor($$); }*/
/*%destructor  nonTerminalSymb2 { token_destructor($$); }*/
/*%destructor  nonTerminalSymb3 { token_destructor($$); }*/
%destructor declaration { stringDestructor($$); }

/* terminal symbols type; they all have the same type (it should be a pointer for objects) */
%token_type{std::string*}

/* Parser prefix; it will be added to both #define, class and function names */
%name{Parser}

/* Parser class name prefix: it will be added only in front of the class name;
 * if it is omitted it will be substituted by "Lp" */
%name_prefix{My}



/**********************************************************
                GRAMMAR DEFINITION SECTION
***********************************************************/
    
program ::= newLineList .

/* newLineList = zero or more new lines */
newLineList ::= .
newLineList ::= newLineList declaration(s5) .
{
	std::cout << "This is a non terminal value: " << *s5 << std::endl;
	std::cout << "This is the extra parameter: " << *translation_params << std::endl;
}

declaration(sRet) ::= FIRST(s1) SECOND(s2) THIRD(s3) .
{
	std::cout 	<< "S1: " 	<< *s1 
				<< "; S2: " << *s2 
				<< "; S3:" 	<< *s3 
				<< std::endl;
				
	std::cout << "This is the extra parameter: " << *translation_params << std::endl;
	
	sRet = new std::string(*s1);
	*sRet += " " + *s2 + " " + *s3;
	
	delete s1;
	delete s2;
	delete s3;
}



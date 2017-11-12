/********************************************************/
/* parser class body ( added at the end of parser.cpp ) */
/********************************************************/

$Parse::$Parse()
{
	this->parser = ParseAlloc();
	this->extra = NULL;
}

#ifdef ParseARG_NAME
$Parse::$Parse(ParseARG_SPDECL)
{
	this->parser = ParseAlloc();
	this->extra = ParseARG_NAME;
}

void $Parse::setExtraParameter(ParseARG_SPDECL)
{
	this->extra = ParseARG_NAME;
}
#endif

$Parse::~$Parse()
{
	ParseFree(this->parser);
}

/**
	@arg token:			an input terminal symbol
	@arg tokenValue:	the associated value (the type is the one declared in the parser source)
	@arg ARG_PDECL:		if an extra structure it is passed it will be added as 3rd parameter
*/

void $Parse::parse(int token, ParseTOKENTYPE tokenValue ParseARG_PDECL)
{
#ifdef ParseARG_NAME
	Parse(this->parser, token, tokenValue, ParseARG_NAME);
#else
	Parse(this->parser, token, tokenValue);
#endif
}

#ifdef ParseARG_NAME
/* parse function with extra argument expected from the local attribute */
void $Parse::parse(int token, ParseTOKENTYPE tokenValue)
{
	if(this->extra == NULL)
	{
		throw LP_ERR_MISSING_EXTRA;
	}
	Parse(this->parser, token, tokenValue, (ParseARG_TYPE)this->extra);
}
#endif

int $Parse::stackPeak()
{
#ifdef YYTRACKMAXSTACKDEPTH
	return ParseStackPeak(this->parser);
#else
	fprintf(stderr, "StackPeak not implemented\n");
	return -1;
#endif
}

#ifndef NDEBUG
void $Parse::trace(FILE *TraceFILE, char *zTracePrompt)
{
	ParseTrace(TraceFILE, zTracePrompt);
}
#endif

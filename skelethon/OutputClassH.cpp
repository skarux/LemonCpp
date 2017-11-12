
/********************************************************/
/*                parser class declaration              */
/********************************************************/

/* parser type */
#define LP_PARSER_TYPE 		$Parse
#define LP_PARSER_TYPE_P 	$Parse*

class $Parse
{
public:
	$Parse();
#ifdef ParseARG_SPDECL
	$Parse(ParseARG_SPDECL);
#endif
	~$Parse();

	/* exception errors */
	typedef enum
	{
		LP_ERR_MISSING_EXTRA
	} LP_EXCEPTIONS;

	/**
		Parse;
		@arg token:           an input terminal symbol
		@arg tokenValue:      terminal symbol value
		@arg ParseARG_PDECL:  if an extra structure it is passed it will be added as 3rd parameter
	*/
#ifdef ParseARG_SPDECL
	void parse(int token, ParseTOKENTYPE yyminor);
	void setExtraParameter(ParseARG_SPDECL);
#endif
	void parse(int token, ParseTOKENTYPE yyminor ParseARG_PDECL);
	int stackPeak();
	void trace(FILE *TraceFILE, char *zTracePrompt);
	
private:
	void* parser; 	/* the actual parser object */
	void* extra;	/* the extra arument, if present */
	
};
	
	

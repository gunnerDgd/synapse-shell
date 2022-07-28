#include <shell/grammar/details/shell_grammar_parse.h>
#include <string.h>

char*
	__synapse_shell_grammar_parse_next
		(__synapse_shell_grammar_string* pString)
{
	char* ptr_parsed
			= pString->str_memory;
	
	pString->str_memory
		= strtok(NULL, " ");
	return
		ptr_parsed;
}

int
	__synapse_shell_grammar_parse_multple
		(__synapse_shell_grammar_string* pString, int pVectorCount, char** pVector)
{
	int
		cnt_parsed = 0;

	for( ;
			cnt_parsed < pVectorCount 
				&& (pVector[cnt_parsed]
						= __synapse_shell_grammar_parse_next
								(pString));
			cnt_parsed++);

	return
		cnt_parsed;
}

char*
	__synapse_shell_grammar_parse_next_delim
		(__synapse_shell_grammar_string* pString, const char* pDelim)
{
	char* ptr_parsed
			= pString->str_memory;
	
	pString->str_memory
		= strtok(NULL, pDelim);
	return
		ptr_parsed;
}

int
	__synapse_shell_grammar_parse_multple_delim
		(__synapse_shell_grammar_string* pString, 
			const char* pDelim, int pVectorCount, char** pVector)
{
	int
		cnt_parsed = 0;
	for( ;
			cnt_parsed < pVectorCount 
				&& (pVector[cnt_parsed]
						= __synapse_shell_grammar_parse_next_delim
								(pString, pDelim));
			cnt_parsed++);

	return
		cnt_parsed;
}
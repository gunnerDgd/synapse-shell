#include <shell/grammar/grammar_parse.h>
#include <shell/grammar/details/shell_grammar_parse.h>

char*
	synapse_shell_grammar_parse_next
		(synapse_shell_grammar_string pString)
{
	return
		__synapse_shell_grammar_parse_next
			(synapse_shell_opaque_handle_reference
				(pString));
}

int
	synapse_shell_grammar_parse_multiple
		(synapse_shell_grammar_string pString, 
				int pVectorCount, char** pVector)
{
	return
		__synapse_shell_grammar_parse_multple
			(synapse_shell_opaque_handle_reference
				(pString), pVectorCount, pVector);
}

char*
	synapse_shell_grammar_parse_next_delim
		(synapse_shell_grammar_string pString, const char* pDelim)
{
	return
		__synapse_shell_grammar_parse_next_delim
			(synapse_shell_opaque_handle_reference
				(pString), pDelim);
}

int
	synapse_shell_grammar_parse_multiple_delim
		(synapse_shell_grammar_string pString, 
				const char* pDelim, int pVectorCount, char** pVector)
{
	return
		__synapse_shell_grammar_parse_multple_delim
			(synapse_shell_opaque_handle_reference
				(pString), pDelim, pVectorCount, pVector);
}
#include <shell/grammar/grammar_string.h>
#include <shell/grammar/details/shell_grammar_string.h>

synapse_shell_grammar_string
	synapse_shell_grammar_string_initialize
		(char* pString, size_t pStringLength, const char* pDelim)
{
	synapse_shell_opaque_handle_init
		(synapse_shell_grammar_string, hnd_string,
			__synapse_shell_grammar_string_initialize
				(pString, pStringLength, pDelim));

	return
		hnd_string;
}

void
	synapse_shell_grammar_string_cleanup
		(synapse_shell_grammar_string pString)
{
	__synapse_shell_grammar_string_cleanup
		(synapse_shell_opaque_handle_reference
			(pString));
}

synapse_shell_dll
size_t
	synapse_shell_grammer_string_length
		(synapse_shell_grammar_string pString)
{
	return
		synapse_shell_opaque_handle_cast
			(pString, __synapse_shell_grammar_string*)
				->str_memory_size;
}
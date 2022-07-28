#include <shell/grammar/details/shell_grammar_string.h>
#include <synapse/memory/memory.h>

#include <stdlib.h>
#include <string.h>

__synapse_shell_grammar_string*
	__synapse_shell_grammar_string_initialize
		(char* pChar, size_t pCharSize, const char* pDelim)
{
	__synapse_shell_grammar_string*
		ptr_string
			= synapse_system_allocate
					(sizeof(__synapse_shell_grammar_string));

	ptr_string->str_memory
		= pChar;
	ptr_string->str_memory_size
		= pCharSize;

	ptr_string->str_memory
		= strtok
			(ptr_string->str_memory, "\n");
	ptr_string->str_memory
		= strtok
			(ptr_string->str_memory, 
				(pDelim) ? pDelim : " ");

	return
		ptr_string;
}

void
	__synapse_shell_grammar_string_cleanup
		(__synapse_shell_grammar_string* pString)
{
	synapse_system_deallocate
		(pString);
}
#pragma once
#include <shell/grammar/details/shell_grammar_type.h>

__synapse_shell_grammar_string*
	__synapse_shell_grammar_string_initialize
		(char*, size_t, const char*);

void
	__synapse_shell_grammar_string_cleanup
		(__synapse_shell_grammar_string*);
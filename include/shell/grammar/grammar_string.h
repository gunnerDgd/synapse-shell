#pragma once
#include <string.h>
#include <shell/grammar/grammar_type.h>

synapse_shell_grammar_string
	synapse_shell_grammar_string_initialize
		(char*, size_t, const char*);

void
	synapse_shell_grammar_string_cleanup
		(synapse_shell_grammar_string);

synapse_shell_dll
size_t
	synapse_shell_grammer_string_length
		(synapse_shell_grammar_string);
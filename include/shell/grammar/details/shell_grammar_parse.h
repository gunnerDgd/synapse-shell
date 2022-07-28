#pragma once
#include <string.h>
#include <shell/grammar/details/shell_grammar_type.h>

char*
	__synapse_shell_grammar_parse_next
		(__synapse_shell_grammar_string*);

int
	__synapse_shell_grammar_parse_multple
		(__synapse_shell_grammar_string*, int, char**);

char*
	__synapse_shell_grammar_parse_next_delim
		(__synapse_shell_grammar_string*, const char*);

int
	__synapse_shell_grammar_parse_multple_delim
		(__synapse_shell_grammar_string*, const char*, int, char**);
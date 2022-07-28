#pragma once
#include <shell/grammar/grammar_type.h>

synapse_shell_dll
char*
	synapse_shell_grammar_parse_next
		(synapse_shell_grammar_string);

synapse_shell_dll
int
	synapse_shell_grammar_parse_multiple
		(synapse_shell_grammar_string, int, char**);

synapse_shell_dll
char*
	synapse_shell_grammar_parse_next_delim
		(synapse_shell_grammar_string, const char*);

synapse_shell_dll
int
	synapse_shell_grammar_parse_multiple_delim
		(synapse_shell_grammar_string, const char*, int, char**);
#pragma once

#include <shell/grammar/grammar_string.h>
#include <shell/grammar/grammar_parse.h>

#include <shell/stream/stream_io.h>

#include <synapse/modules/modules.h>

void
	synapse_builtin_modman_main
		(synapse_shell_stream,
				synapse_shell_grammar_string);

int
	add_module
		(synapse_shell_grammar_string, const char*);

int
	attach_module
		(synapse_shell_grammar_string, const char*);

int
	detach_module
		(synapse_shell_grammar_string, const char*);

int
	reload_module
		(synapse_shell_grammar_string, const char*);
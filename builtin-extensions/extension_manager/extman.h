#pragma once
#include <shell/extension/extension.h>

#include <shell/grammar/grammar_parse.h>
#include <shell/grammar/grammar_string.h>

#include <shell/stream/stream_io.h>
#include <shell/stream/stream_stdio.h>

void
	synapse_builtin_extman_main
		(synapse_shell_stream,
			synapse_shell_grammar_string);

void
	add_extension
		(synapse_shell_grammar_string, const char*);

void
	delete_extension
		(synapse_shell_grammar_string, const char*);
#pragma once

#include <synapse/modules/interface/modules.h>

#include <shell/stream/stream_io.h>
#include <shell/stream/stream_stdio.h>

#include <shell/grammar/grammar_parse.h>
#include <shell/grammar/grammar_string.h>

#include <shell/extension/extension.h>

_declspec(dllexport)
	int
		synapse_modules_initialize
			(synapse_modules_metadata*, synapse_modules_traits*);

_declspec(dllexport)
	void
		synapse_modules_cleanup
			();

void
	synapse_shell_main
		(int pArgCount, char** pArgVector);

int
	synapse_shell_exec
		(synapse_shell_stream, synapse_shell_grammar_string);
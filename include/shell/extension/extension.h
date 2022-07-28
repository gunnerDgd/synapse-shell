#pragma once
#include <shell/extension/extension_type.h>
#include <shell/stream/stream_io.h>

void
	synapse_shell_extension_probe_initialize
		();

void
	synapse_shell_extension_probe_cleanup
		();

synapse_shell_extension
	synapse_shell_extension_add
		( const char*, const char*);

int
	synapse_shell_extension_delete
		(synapse_shell_extension);

synapse_shell_extension
	synapse_shell_extension_retrieve
		( const char*);

int
	synapse_shell_extension_execute
		(synapse_shell_extension, synapse_shell_stream, synapse_shell_grammar_string);


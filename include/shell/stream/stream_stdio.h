#pragma once
#include <shell/stream/stream_type.h>
#include <shell/defines/export.h>

synapse_shell_stream
	synapse_shell_stream_stdio_initialize
		(const char*, const char*);

void
	synapse_shell_stream_stdio_cleanup
		(synapse_shell_stream);
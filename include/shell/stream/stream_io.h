#pragma once
#include <shell/defines/export.h>
#include <shell/stream/stream_type.h>

synapse_shell_dll
size_t
	synapse_shell_stream_read_from
		(synapse_shell_stream, void*, size_t);

synapse_shell_dll
void
	synapse_shell_stream_formatted_read
		(synapse_shell_stream, const char*, int, ...);

synapse_shell_dll
size_t
	synapse_shell_stream_write_to
		(synapse_shell_stream, void*, size_t);

synapse_shell_dll
void
	synapse_shell_stream_formatted_write
		(synapse_shell_stream, const char*, int, ...);
#pragma once
#include <shell/stream/details/shell_stream_type.h>

size_t
	__synapse_shell_stream_read_from
		(__synapse_shell_stream*, void*, size_t);

size_t
	__synapse_shell_stream_write_to
		(__synapse_shell_stream*, void*, size_t);

void
	__synapse_shell_stream_formatted_read
		(__synapse_shell_stream*, const char*, va_list);

void
	__synapse_shell_stream_formatted_write
		(__synapse_shell_stream*, const char*, va_list);
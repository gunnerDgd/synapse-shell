#pragma once
#include <stdlib.h>

typedef struct
	__synapse_shell_stream
{
	void
		*shl_istream_handle,
		*shl_ostream_handle;

	size_t
		(*shl_read_from)
			(struct __synapse_shell_stream*,
					void*, size_t);
	size_t
		(*shl_write_to)
			(struct __synapse_shell_stream*,
					void*, size_t);

	void
		(*shl_formatted_read)
			(struct __synapse_shell_stream*,
					const char*, va_list);
	void
		(*shl_formatted_write)
			(struct __synapse_shell_stream*,
					const char*, va_list);
} __synapse_shell_stream;
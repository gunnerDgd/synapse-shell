#include <shell/stream/stream_io.h>
#include <shell/stream/details/shell_stream_io.h>

#include <string.h>
#include <stdarg.h>

size_t
	synapse_shell_stream_read_from
		(synapse_shell_stream pStream, void* pIoBuffer, size_t pIoSize)
{
	size_t sz_read
		= __synapse_shell_stream_read_from
			(synapse_shell_opaque_handle_reference
				(pStream), pIoBuffer, pIoSize);

	return
		sz_read;
}

size_t
	synapse_shell_stream_write_to
		(synapse_shell_stream pStream, void* pIoBuffer, size_t pIoSize)
{
	return
		__synapse_shell_stream_write_to
			(synapse_shell_opaque_handle_reference
				(pStream), pIoBuffer, pIoSize);
}

synapse_shell_dll
void
	synapse_shell_stream_formatted_read
		(synapse_shell_stream pStream, const char* pFormat, int pArgCount, ...)
{
	va_list ptr_args;
	va_start
		(ptr_args, pArgCount);

	__synapse_shell_stream_formatted_read
		(synapse_shell_opaque_handle_reference
			(pStream), pFormat, ptr_args);
}

synapse_shell_dll
void
	synapse_shell_stream_formatted_write
		(synapse_shell_stream pStream, const char* pFormat, int pArgCount, ...)
{
	va_list ptr_args;
	va_start
		(ptr_args, pArgCount);

	__synapse_shell_stream_formatted_write
		(synapse_shell_opaque_handle_reference
			(pStream), pFormat, ptr_args);
}
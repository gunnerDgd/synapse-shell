#include <shell/stream/details/shell_stream_io.h>

size_t
	__synapse_shell_stream_read_from
		(__synapse_shell_stream* pStream, void* pIoBuffer, size_t pIoSize)
{
	return
		pStream->shl_read_from
			(pStream, pIoBuffer, pIoSize);
}

size_t
	__synapse_shell_stream_write_to
		(__synapse_shell_stream* pStream, void* pIoBuffer, size_t pIoSize)
{
	return
		pStream->shl_write_to
			(pStream, pIoBuffer, pIoSize);
}

void
	__synapse_shell_stream_formatted_read
		(__synapse_shell_stream* pStream, const char* pFormat, va_list pArgument)
{
	pStream->shl_formatted_read
		(pStream, pFormat, pArgument);
}

void
	__synapse_shell_stream_formatted_write
		(__synapse_shell_stream* pStream, const char* pFormat, va_list pArgument)
{
	pStream->shl_formatted_write
		(pStream, pFormat, pArgument);
}
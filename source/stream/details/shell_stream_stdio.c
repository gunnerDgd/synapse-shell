#include <shell/stream/details/shell_stream_stdio.h>
#include <string.h>

size_t
	__stdio_read
		(__synapse_shell_stream* pEndpoint, void* pIoBuffer, size_t pIoBufferSize)
{
	char* 
		ptr_read
			= fgets
				(pIoBuffer, pIoBufferSize, 
						pEndpoint->shl_istream_handle);
	
	return
		strlen(ptr_read);
}

size_t
	__stdio_write
		(__synapse_shell_stream* pEndpoint, void* pIoBuffer, size_t pIoBufferSize)
{
	return
		fputs
			(pIoBuffer, pEndpoint->shl_ostream_handle);
}

void
	__stdio_formatted_read
		(__synapse_shell_stream* pEndpoint, const char* pFormat, va_list pArgument)
{
	vfscanf
		(pEndpoint->shl_istream_handle, pFormat, pArgument);
}

void
	__stdio_formatted_write
		(__synapse_shell_stream* pEndpoint, const char* pFormat, va_list pArgument)
{
	vfprintf
		(pEndpoint->shl_ostream_handle, pFormat, pArgument);
}

__synapse_shell_stream*
	__synapse_shell_endpoint_stdio_initialize
		(const char* pIstreamName, const char* pOstreamName)
{
	__synapse_shell_stream*
		ptr_endpoint
			= malloc(sizeof(__synapse_shell_stream));

	if((pIstreamName && pOstreamName) &&
			!(strcmp(pIstreamName, pOstreamName)))
					return NULL;

	ptr_endpoint
		->shl_istream_handle
			= (pIstreamName) 
					? fopen(pIstreamName, "w+") : stdin;
	ptr_endpoint
		->shl_ostream_handle
			= (pOstreamName) 
					? fopen(pOstreamName, "w+") : stdout;
	ptr_endpoint
		->shl_read_from
			= &__stdio_read;
	ptr_endpoint
		->shl_write_to
			= &__stdio_write;
	ptr_endpoint
		->shl_formatted_read
			= &__stdio_formatted_read;
	ptr_endpoint
		->shl_formatted_write
			= &__stdio_formatted_write;

	return
		ptr_endpoint;
}

void
	__synapse_shell_endpoint_stdio_cleanup
		(__synapse_shell_stream* pEndpoint)
{
	if(pEndpoint->shl_istream_handle != stdin)
		fclose
			(pEndpoint->shl_istream_handle);

	if(pEndpoint->shl_ostream_handle != stdout)
		fclose
			(pEndpoint->shl_ostream_handle);

	free
		(pEndpoint);
}
#include <shell/stream/stream_stdio.h>
#include <shell/stream/details/shell_stream_stdio.h>

synapse_shell_stream
	synapse_shell_stream_stdio_initialize
		(const char* pIStream, const char* pOStream)
{
	synapse_shell_opaque_handle_init
		(synapse_shell_stream, hnd_stream,
			__synapse_shell_endpoint_stdio_initialize
					(pIStream, pOStream));

	return
		hnd_stream;
}

void
	synapse_shell_stream_stdio_cleanup
		(synapse_shell_stream pStream)
{
	__synapse_shell_endpoint_stdio_cleanup
		(synapse_shell_opaque_handle_reference
			(pStream));
}
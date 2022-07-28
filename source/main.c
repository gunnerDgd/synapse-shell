#include <shell/init.h>
#include <stdbool.h>

static synapse_shell_stream
			__synapse_shell_iostream;
char
			__synapse_shell_iostream_buffer[1024];

const char*  __synapse_shell_init_message = 
"\n\
====================================================================================\n\
| Welcome to Synapse Experimetal 1 Build.                                          |\n\
| This Build is For Test Purpose, May Have Lots of Unstable Features.              |\n\
| Do not Use This for Actual Development Process. Just for Debugging and Testing !!|\n\
| Build Date : 2022/07/24                                                          |\n\
====================================================================================\n\n";

void
	synapse_shell_initialize
		(int, char**);

void
	synapse_shell_main
		(int, char**);

void
	synapse_shell_cleanup
		();

int
	synapse_shell_exec
		(synapse_shell_stream, synapse_shell_grammar_string);

void
	synapse_shell_initialize(int pArgCount, char** pArgVector)
{
	if (pArgCount == 0)
		__synapse_shell_iostream
			= synapse_shell_stream_stdio_initialize
					(0, 0);
	else
		__synapse_shell_iostream
			= synapse_shell_stream_stdio_initialize
				((strcmp(pArgVector[0], "standard_input"))
						? NULL : pArgVector[0],
				 (strcmp(pArgVector[1], "standard_output"))
						? NULL : pArgVector[1]);

	synapse_shell_extension_probe_initialize();
	synapse_shell_stream_write_to
		(__synapse_shell_iostream,
			(void*)__synapse_shell_init_message, 
					strlen(__synapse_shell_init_message));
}

void
	synapse_shell_cleanup
		()
{
	synapse_shell_extension_probe_cleanup();
	synapse_shell_stream_stdio_cleanup
		(__synapse_shell_iostream);
}

void
	synapse_shell_main
		(int pArgCount, char** pArgVector)
{
	synapse_shell_initialize
		(pArgCount, pArgVector);

	while(true)
	{
		synapse_shell_grammar_string
			shl_string;
		size_t
			shl_string_rdsize = 0;
		int
			shl_exec_result;

		synapse_shell_stream_formatted_write
				(__synapse_shell_iostream,
						"(synapse-shell) >> ", 0);
		
		shl_string_rdsize
			= synapse_shell_stream_read_from
					(__synapse_shell_iostream, 
						__synapse_shell_iostream_buffer, 1024);
		if (shl_string_rdsize <= 1)
			continue;

		shl_string
			= synapse_shell_grammar_string_initialize
						(__synapse_shell_iostream_buffer,
									shl_string_rdsize, " ");

		shl_exec_result
			= synapse_shell_exec
				(__synapse_shell_iostream, shl_string);
		if (shl_exec_result == 0)
			break;
	}
}

int
	synapse_shell_exec
		(synapse_shell_stream pStream, synapse_shell_grammar_string pString)
{
	char*
		ptr_extension_name
			= synapse_shell_grammar_parse_next
				(pString);
	synapse_shell_extension
		ptr_extension;

	if (strcmp(ptr_extension_name, "exit") == 0)
		return 0;

	ptr_extension
		= synapse_shell_extension_retrieve
			(ptr_extension_name);

	if(synapse_shell_extension_execute
			(ptr_extension, pStream, pString) == -1)
		synapse_shell_stream_formatted_write
			(pStream, "\n[synapse-shell][error] Failed to Execute \"%s\"\n",
				1, ptr_extension_name);

	return 1;
}
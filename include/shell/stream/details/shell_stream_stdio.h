#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <shell/stream/details/shell_stream_type.h>

__synapse_shell_stream*
	__synapse_shell_endpoint_stdio_initialize
		(const char*, const char*);

void
	__synapse_shell_endpoint_stdio_cleanup
		(__synapse_shell_stream*);
#pragma once
#include <shell/grammar/grammar_string.h>
#include <shell/stream/stream_io.h>

#include <synapse/structure/list/double_linked.h>
#include <synapse/memory/memory.h>

#include <Windows.h>

typedef struct
	__synapse_shell_extension
{
	HMODULE
		shl_ext_handle;
	synapse_double_linked_node
		shl_ext_probe_handle;

	const char*
		shl_ext_name;
	void
	  (*shl_ext_exec)
			(synapse_shell_stream, synapse_shell_grammar_string);
} __synapse_shell_extension;

typedef struct
	__synapse_shell_extension_probe
{
	synapse_memory_manager*
		shl_ext_probe_mman;
	synapse_double_linked
		shl_ext_probe_handle;
} __synapse_shell_extension_probe;
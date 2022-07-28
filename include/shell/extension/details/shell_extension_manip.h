#pragma once
#include <shell/extension/details/shell_extension_type.h>

__synapse_shell_extension*
	__synapse_shell_extension_probe_add
		(__synapse_shell_extension_probe*, 
				const char*, const char*);

void
	__synapse_shell_extension_probe_delete
		(__synapse_shell_extension_probe*,
				__synapse_shell_extension*);

__synapse_shell_extension*
	__synapse_shell_extension_probe_retrieve
		(__synapse_shell_extension_probe*, const char*);
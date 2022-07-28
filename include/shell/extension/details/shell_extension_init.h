#pragma once
#include <shell/extension/details/shell_extension_type.h>

__synapse_shell_extension_probe*
	__synapse_shell_extension_probe_initialize
		();

void
	__synapse_shell_extension_probe_cleanup
		(__synapse_shell_extension_probe*);
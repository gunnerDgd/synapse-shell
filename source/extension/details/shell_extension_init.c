#include <shell/extension/details/shell_extension_init.h>
#include <shell/extension/details/shell_extension_manip.h>

#include <stdlib.h>

#include <shell/extension/module_manager/modman.h>
#include <shell/extension/extension_manager/extman.h>

__synapse_shell_extension_probe*
	__synapse_shell_extension_probe_initialize
		()
{
	__synapse_shell_extension_probe*
		ptr_probe
			= synapse_system_allocate
				(sizeof(__synapse_shell_extension_probe));

	ptr_probe->shl_ext_probe_mman
		= synapse_system_memory_manager();
	ptr_probe->shl_ext_probe_handle
		= synapse_initialize_double_linked
				(ptr_probe->shl_ext_probe_mman);

	__synapse_shell_extension_probe_add_builtin
		(ptr_probe, "modman", &synapse_builtin_modman_main);
	__synapse_shell_extension_probe_add_builtin
		(ptr_probe, "extman", &synapse_builtin_extman_main);

	return
		ptr_probe;
}

void
	__synapse_shell_extension_probe_cleanup
		(__synapse_shell_extension_probe* pProbe)
{
	synapse_cleanup_double_linked
		(pProbe->shl_ext_probe_handle);
	synapse_system_deallocate
		(pProbe);
}
#include <shell/init.h>

#include <synapse/component/component.h>
#include <synapse/modules/modules.h>

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

static synapse_component_interface
			__synapse_shell_interface;

static const char*
			 __synapse_shell_modulename
					= "synapse_main_module";


_declspec(dllexport)
	int
		synapse_modules_initialize
			(synapse_modules_metadata* pMetadata, synapse_modules_traits* pTraits)
{
	pMetadata->modules_name
		= __synapse_shell_modulename;
	pMetadata->modules_name_length
		= strlen(__synapse_shell_modulename);
	pMetadata->modules_version[0]
		= 1;

	pTraits->attach = NULL;
	pTraits->detach = NULL;
	pTraits->reload = NULL;

	__synapse_shell_interface
		= synapse_register_interface
				("synapse_main_module");
	synapse_register_interface_attribute
		(__synapse_shell_interface,
			"synapse_main_module_entry", &synapse_shell_main, NULL);

	return 0;
}

_declspec(dllexport)
	void
		synapse_modules_cleanup
			()
{
}
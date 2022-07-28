#include <shell/extension/details/shell_extension_manip.h>
#include <synapse/memory/memory.h>

__synapse_shell_extension*
	__synapse_shell_extension_probe_add
		(__synapse_shell_extension_probe* pProbe,
				const char* pExtensionPath, const char* pExtensionName)
{
	__synapse_shell_extension*
		ptr_extension;

	if (!pExtensionPath || !pExtensionName)
		return NULL;

	if(__synapse_shell_extension_probe_retrieve
			(pProbe, pExtensionName))
				return NULL;
		
	ptr_extension
		= synapse_system_allocate
				(sizeof(__synapse_shell_extension));
	ptr_extension->shl_ext_handle
		= LoadLibraryA(pExtensionPath);

	if (!ptr_extension->shl_ext_handle)
		goto __add_failed;

	ptr_extension->shl_ext_exec
		= GetProcAddress
			(ptr_extension->shl_ext_handle, "synapse_extension_main");

	if (!ptr_extension->shl_ext_exec)
		goto __add_failed;

	ptr_extension->shl_ext_name
		= pExtensionName;
	ptr_extension->shl_ext_probe_handle
		= synapse_double_linked_insert_back
				(pProbe->shl_ext_probe_handle,
					&ptr_extension, sizeof(__synapse_shell_extension*));

	return ptr_extension;

__add_failed:
	synapse_system_deallocate
		(ptr_extension);
	return NULL;
}

void
	__synapse_shell_extension_probe_delete
		(__synapse_shell_extension_probe* pProbe,
				__synapse_shell_extension* pExtension)
{
	if (!pExtension)
		return;

	synapse_double_linked_erase_at
		(pProbe->shl_ext_probe_handle,
			pExtension->shl_ext_probe_handle);
	
	FreeLibrary
		(pExtension->shl_ext_handle);
	synapse_system_deallocate
		(pExtension);
}

__synapse_shell_extension*
	__synapse_shell_extension_probe_retrieve
		(__synapse_shell_extension_probe* pProbe, const char* pName)
{
	synapse_double_linked_node
		ptr_seek
			= synapse_double_linked_node_begin
					(pProbe->shl_ext_probe_handle);

	for( ; ptr_seek.opaque
		 ; ptr_seek 
				= synapse_double_linked_node_next
								(ptr_seek))
	{
		__synapse_shell_extension*
			ptr_extension
				= *(__synapse_shell_extension**)
						synapse_double_linked_node_data
							(ptr_seek);

		if(strcmp
				(ptr_extension->shl_ext_name,
						pName) == 0)
							return ptr_extension;
	}

	return NULL;
}
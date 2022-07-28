#include <shell/extension/extension.h>

#include <shell/extension/details/shell_extension_init.h>
#include <shell/extension/details/shell_extension_manip.h>

static synapse_shell_extension_probe
			__synapse_shell_extension_probe_handle;

void
	synapse_shell_extension_probe_initialize
		()
{
	synapse_shell_opaque_handle_reference
		(__synapse_shell_extension_probe_handle)
			= __synapse_shell_extension_probe_initialize();
}

void
	synapse_shell_extension_probe_cleanup
		()
{
	__synapse_shell_extension_probe_cleanup
		(synapse_shell_opaque_handle_reference
			(__synapse_shell_extension_probe_handle));
}

synapse_shell_extension
	synapse_shell_extension_add
		(const char* pPath, const char* pName)
{
	synapse_shell_opaque_handle_init
		(synapse_shell_extension, hnd_extension,
			__synapse_shell_extension_probe_add
				(synapse_shell_opaque_handle_reference
					(__synapse_shell_extension_probe_handle), 
						pPath, pName));

	return
		hnd_extension;
}

synapse_shell_extension
	synapse_shell_extension_retrieve
		(const char* pName)
{
	synapse_shell_opaque_handle_init
		(synapse_shell_extension, hnd_extension,
			__synapse_shell_extension_probe_retrieve
				(synapse_shell_opaque_handle_reference
					(__synapse_shell_extension_probe_handle), pName));

	return
		hnd_extension;
}

int
	synapse_shell_extension_execute
		(synapse_shell_extension pExtension, 
			synapse_shell_stream pStream, synapse_shell_grammar_string pGrammar)
{
	__synapse_shell_extension*
		ptr_extension;
	
	if (!pExtension.opaque)
		return -1;

	ptr_extension
		= synapse_shell_opaque_handle_reference
				(pExtension);

	ptr_extension->shl_ext_exec
		(pStream, pGrammar);
	return 0;
}

int
	synapse_shell_extension_delete
		(synapse_shell_extension pExtension)
{
	if (!pExtension.opaque)
		return -1;

	__synapse_shell_extension_probe_delete
		(synapse_shell_opaque_handle_reference
			(__synapse_shell_extension_probe_handle),
		 synapse_shell_opaque_handle_reference
			(pExtension));

	return 0;
}
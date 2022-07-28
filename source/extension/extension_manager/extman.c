#include <shell/extension/extension_manager/extman.h>

static synapse_shell_stream
			__attached_stream;

void
	synapse_builtin_extman_main
		(synapse_shell_stream pStream,
			synapse_shell_grammar_string pString)
{
	const char*
		ptr_command
			= synapse_shell_grammar_parse_next
					(pString);

	if (!ptr_command)
		return;

	__attached_stream
		= pStream;
	
	if(strcmp
			(ptr_command, "add") == 0)
				add_extension
					(pString, 
						synapse_shell_grammar_parse_next
							(pString));
	if(strcmp
			(ptr_command, "delete") == 0)
				delete_extension
					(pString, 
						synapse_shell_grammar_parse_next
							(pString));
}

void
	add_extension
		(synapse_shell_grammar_string pString, 
			const char* pModuleName)
{
	synapse_shell_extension
		ext_added
			= synapse_shell_extension_add
					(pModuleName,
						synapse_shell_grammar_parse_next
							(pString));

	if(!synapse_shell_opaque_handle_reference
			(ext_added)) {
		synapse_shell_stream_formatted_write
			(__attached_stream,
				"[synapse-shell][extension-manager][error] Failed to Load Module \"%s\"\n",
					1, pModuleName);
	}
}

void
	delete_extension
		(synapse_shell_grammar_string pString, 
			const char* pModuleName)
{
	synapse_shell_extension
		ext_delete
			= synapse_shell_extension_retrieve
					(pModuleName);

	if(!synapse_shell_opaque_handle_reference
			(ext_delete)) {
		synapse_shell_stream_formatted_write
			(__attached_stream,
				"[synapse-shell][extension-manager][error] Failed to Delete Module \"%s\"\n",
					1, pModuleName);

		return;
	}
	
	synapse_shell_extension_delete
		(ext_delete);
}
#include <shell/extension/module_manager/modman.h>

static synapse_shell_stream
			__attached_stream;

void
	synapse_builtin_modman_main
		(synapse_shell_stream pStream,
				synapse_shell_grammar_string pCommand)
{
	char* ptr_command
			= synapse_shell_grammar_parse_next
				(pCommand);
	int   res_command;

	__attached_stream
		= pStream;

	if (!ptr_command)
		return;

	if(strcmp(ptr_command, "add") == 0)
		res_command 
			= add_module
				(pCommand,
					synapse_shell_grammar_parse_next
						(pCommand));
	if(strcmp(ptr_command, "attach") == 0)
		res_command
			= attach_module
				(pCommand,
					synapse_shell_grammar_parse_next
						(pCommand));
	if(strcmp(ptr_command, "detach") == 0)
		res_command
			= detach_module
				(pCommand,
					synapse_shell_grammar_parse_next
						(pCommand));
	if(strcmp(ptr_command, "reload") == 0)
		res_command
			= reload_module
				(pCommand,
					synapse_shell_grammar_parse_next
						(pCommand));
}

int
	add_module
		(synapse_shell_grammar_string pCommand, const char* pModuleName)
{
	synapse_modules
		hnd_module
			= synapse_load_modules
					(pModuleName);

	if (!hnd_module.opaque) {
		synapse_shell_stream_formatted_write
			(__attached_stream,
				"[synapse-shell][module-manager][error] Failed to Load Module \"%s\".\n",
					1, pModuleName);
		return 0;
	}
	else
		return 1;
}

int
	attach_module
		(synapse_shell_grammar_string pString, const char* pModuleName)
{
	synapse_modules
		hnd_module
			= synapse_import_modules
					(pModuleName);

	if (!hnd_module.opaque 
			|| synapse_attach_modules(hnd_module) == -1) {
		synapse_shell_stream_formatted_write
			(__attached_stream,
				"[synapse-shell][module-manager][error] Failed to Attach Module \"%s\".\n",
					1, pModuleName);

		return 0;
	}

	
	return 1;
}

int
	detach_module
		(synapse_shell_grammar_string pString, const char* pModuleName)
{
	synapse_modules
		hnd_module
			= synapse_import_modules
					(pModuleName);

	if (!hnd_module.opaque
			|| synapse_detach_modules(hnd_module) == -1) {
		synapse_shell_stream_formatted_write
			(__attached_stream,
				"[synapse-shell][module-manager][error] Failed to Detach Module \"%s\".\n",
					1, pModuleName);

		return 0;
	}

	return 1;
}

int
	reload_module
		(synapse_shell_grammar_string pString, const char* pModuleName)
{
	synapse_modules
		hnd_module
			= synapse_import_modules
					(pModuleName);

	if (!hnd_module.opaque
			|| synapse_reload_modules(hnd_module) == -1) {
		synapse_shell_stream_formatted_write
			(__attached_stream,
				"[synapse-shell][module-manager][error] Failed to Reload Module \"%s\".\n",
					1, pModuleName);

		return 0;
	}

	return 1;
}
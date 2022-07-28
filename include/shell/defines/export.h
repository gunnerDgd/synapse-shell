#pragma once
#ifdef synapse_shell_export_mode
#define synapse_shell_dll _declspec(dllexport)
#else
#define synapse_shell_dll _declspec(dllimport)
#endif
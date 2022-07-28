#pragma once
#include <stdint.h>

#define synapse_shell_opaque_handle_declare(pName)\
	typedef struct pName\
	{\
		void* opaque;\
	} pName;

#define synapse_shell_opaque_handle_reference(pObject)\
	(pObject.opaque)

#define synapse_shell_opaque_handle_init(pType, pName, pValue)\
	pType pName = { .opaque = pValue }

#define synapse_shell_opaque_handle_cast(pObject, pType)\
	((pType)(pObject.opaque))
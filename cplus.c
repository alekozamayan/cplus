#include "cplus.h"

#ifdef CREATE_VTABLE_DEFS

ObjectVTABLE CP_ObjectVTABLE = {(ObjectVTABLE*)0,
				(void (*)(Object * me))&Object_abstract};

void Object_abstract(void)
{
    while(1)
    {
        /*Abstract function call trap. Check your stack pointer.*/
    }
}

int Object_isKindOf__(Object const *me, struct ObjectVTABLETag const *vtable)
{
    int returnVal = 0;
    ObjectVTABLE* vptr = me->vptr__;

    /*Iterate until virtual table pointers match*/
    do
    {
        if(vtable == vptr)
        {
            returnVal = 1;
            break;
        }
        else
        {
            vptr = vptr->super__;
        }
    }
    while(((ObjectVTABLE*)0) != vptr);

    return returnVal;
}

#endif
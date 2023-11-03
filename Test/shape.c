#include "Test/shape.h"

/* Shape class -------------------------------------------------------------*/
BEGIN_VTABLE(Shape, Object)
	VMETHOD(Object, xtor) = (void (*)(Object *))&Shape_xtor_;
	VMETHOD(Shape, area)  = (double (*)(Shape *))&Object_abstract;
	VMETHOD(Shape, scale) = (void (*)(Shape *, double))&Object_abstract;
END_VTABLE

/*..........................................................................*/
 void Shape_ctor_(Shape *me, char *name) 
 {
	Object_ctor_(&me->super_); /* construct superclass */
	VHOOK(Shape); /* hook Shape class */
	CPString_ctor1(&me->name, name); /* construct member */
}

/*..........................................................................*/
void Shape_xtor_(Shape *me) 
{
	CPString_xtor(&me->name); /* destroy member */
	Object_xtor_(&me->super_); /* destroy superclass */
}
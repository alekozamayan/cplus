#include "Test/circle.h"

/*..........................................................................*/
BEGIN_VTABLE(Circle, Shape)
	VMETHOD(Shape, area)  = (double (*)(Shape *))&Circle_area;
	VMETHOD(Shape, scale) = (void (*)(Shape *, double))&Circle_scale;
END_VTABLE

/*..........................................................................*/
void Circle_ctor(Circle *me, char *name, double r)
{
	Shape_ctor_(&me->super_, name); /* construct superclass */
	VHOOK(Circle); /* hook Circle class */
	me->r__ = r; /* initialise member(s) */
}

/*..........................................................................*/
double Circle_area(Circle *me)
{
	return 3.141592535 * me->r__ * me->r__; /* pi * r-squared */
}

/*..........................................................................*/
void Circle_scale(Circle *me, double mag)
{
	me->r__ *= mag;
}
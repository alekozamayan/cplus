#include "Test/rect.h"

/*..........................................................................*/
BEGIN_VTABLE(Rect, Shape)
	VMETHOD(Shape, area) = (double (*)(Shape *))&Rect_area;
	VMETHOD(Shape, scale) = (void (*)(Shape *, double))&Rect_scale;
END_VTABLE

/*..........................................................................*/
void Rect_ctor(Rect *me, char *name, double w, double h) 
{
	Shape_ctor_(&me->super_, name); /* construct superclass */
	VHOOK(Rect); /* hook Rect class */
	me->h__ = h; /* initialise member(s) */
	me->w__ = w;
}

/*..........................................................................*/
double Rect_area(Rect *me) 
{
	return me->w__ * me->h__;
}

/*..........................................................................*/
void Rect_scale(Rect *me, double mag) 
{
	me->w__ *= mag;
	me->h__ *= mag;
}
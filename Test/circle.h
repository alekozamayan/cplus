#ifndef CIRCLE_H
#define CIRCLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cplus.h"
#include "Test/shape.h"

SUBCLASS(Circle, Shape) /* Class Circle extends Shape */
	double r__; /* private radius */
VTABLE(Circle, Shape) /* make sure Circle has a virtual table */
METHODS
	void 	Circle_ctor(Circle *me, char *name, double r);
	double 	Circle_area(Circle *me);
	void 	Circle_scale(Circle *me, double mag);
END_CLASS

#ifdef __cplusplus
}
#endif

#endif /*CIRCLE_H*/
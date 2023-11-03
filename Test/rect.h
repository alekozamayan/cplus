#ifndef RECT_H
#define RECT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cplus.h"
#include "Test/shape.h"

SUBCLASS(Rect, Shape) /* Class Rect extends Shape */
	double w__; /* private width */
	double h__; /* private height */
VTABLE(Rect, Shape)
METHODS
	void Rect_ctor(Rect *me, char *name, double w, double h);
	double Rect_area(Rect *me);
	void Rect_scale(Rect *me, double mag);
END_CLASS

#ifdef __cplusplus
}
#endif

#endif /*RECT_H*/
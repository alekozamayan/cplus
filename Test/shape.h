#ifndef SHAPE_H
#define SHAPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cplus.h"
#include "Test/cpstring.h"

SUBCLASS(Shape, Object)
	CPString name; /* public shape's name */
VTABLE(Shape, Object)
	double (*area)(Shape *me); /* pure virtual! */
	void (*scale)(Shape *me, double mag); /* pure virtual! */
METHODS
	void Shape_ctor_(Shape *me, char *name); /* protected Ctor */
	void Shape_xtor_(Shape *me); /* protected Xtor */
END_CLASS

#ifdef __cplusplus
}
#endif

#endif /*SHAPE_H*/

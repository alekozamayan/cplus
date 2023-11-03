#include "cplus.h"
#include "Test/shape.h"
#include "Test/circle.h"
#include "Test/rect.h"
#include <stdio.h>
#include <assert.h>

enum { NRECT = 4 };

/* tests for Shape =========================================================*/
void test_area(Shape *s)
{
	assert(Object_IS_KIND_OF(s, Shape));
	printf("name=\"%s\", area()=%.2f, ",
	CPString_toChar(&s->name), /* static binding */
	VCALL(Shape, area, s)END_CALL); /* dynamic binding */
}

/*..........................................................................*/
void test_scale(Shape *s)
{
	double mag = 2.0;
	assert(Object_IS_KIND_OF(s, Shape));
	printf("scale(%.0f), ", mag);
	VCALL(Shape, scale, s), mag END_CALL; /* dynamic binding */
}

int main() 
{
    Circle circle; /* Circle instance on the stack frame */
	Circle *c;
	Rect r[NRECT];
	int i;
	
	/* construct objects... */
	Circle_ctor(&circle, "Circle", 1.0);
	c = &circle;
	
	for (i = 0; i < NRECT; i++) 
	{
		char name[20];
		sprintf(name, "Rectangle-%d", i); /* prepare the name */
		Rect_ctor(&r[i], name, (double)i, 1.0); /* construct Rect */
	}
	/* test the Circle ... */
	test_area((Shape *)c);
	test_scale(&c->super_);
	test_area((Shape *)c);
	printf("\n");
	
	/* test the Rectangles ... */
	for (i = 0; i < NRECT; i++) 
	{
		test_area((Shape *)&r[i]);
		test_scale(&r[i].super_);
		test_area((Shape *)&r[i]);
		printf("\n");
	}
	
	/* detstroy objects ... */
	VCALL(Object, xtor, c)END_CALL; /* destroy the Circle, dynamic binding */
	
	for (i = 0; i < NRECT; i++) 
	{
		VCALL(Object, xtor, &r[i])END_CALL; /* destroy the Rectangles ...*/
	}
	
	return 0;
}

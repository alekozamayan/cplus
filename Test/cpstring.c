#include "Test/cpstring.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/* String class ------------------------------------------------------------*/
void CPString_ctor1(CPString *me, char const *str)
{
	me->buf__ = (char *)malloc(strlen(str) + 1);
	assert(me->buf__ != (char *)0);
	strcpy(me->buf__, str);
}

/*..........................................................................*/
void CPString_ctor2(CPString *me, CPString *other)
{
	CPString_ctor1(me, CPString_toChar(other));
}

/*..........................................................................*/
char const *CPString_toChar(CPString *me)
{
	return me->buf__;
}

/*..........................................................................*/
void CPString_xtor(CPString *me)
{
	free(me->buf__); /* release buffer */
}
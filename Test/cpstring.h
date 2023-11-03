#ifndef CPSTRING_H
#define CPSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cplus.h"

CLASS(CPString)
	char *buf__; /* private character buffer */
METHODS
	void CPString_ctor1(CPString *me, char const *str); /* public Ctor1 */
	void CPString_ctor2(CPString *me, CPString *other); /* public Ctor2 */
	void CPString_xtor(CPString *me); /* public Xtor */
	char const *CPString_toChar(CPString *me); /* to-char conversion */
END_CLASS

#ifdef __cplusplus
}
#endif

#endif /*CPSTRING_H*/
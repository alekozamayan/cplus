/* 

This header file contains C Plus macro definitions.
Implemented through the source manual:
Miro Samek (Ph.D), "C+" 3.0 Programmer's Manual, Rev. C May 2007

 Authors:  akozan
 
 Change Log:
 18.11.2019 first release
 ----------------------------------------------------------------------------*/
#ifndef CPlus_H
#define CPlus_H

#ifdef __cplusplus
extern "C" {
#endif

/*This definition is used for enabling creation of Virtual Table definitions.
Commenting out would save a few bytes (by excluding Object_abstract function,
static CP_ObjectVTABLE object and Object_isKindOf__ function), however, it is
left to user's decision.
If you are not going to use virtual functions in your project, you may comment
out this macro.*/
#define CREATE_VTABLE_DEFS

/*Glue macros are created to enforce preprocessor to process multiple glue
operators (##) in a defined order. Since there is no specification about
process order of multiple glue operators used in a macro, we need to
encapsulate one glue operator in a macro and call it repeatedly in need.*/
#define GLUE2SUB(a, b)    a##b /*This macro is for eliminating nested
                                preprocessing issues.*/
#define GLUE2(a,b)     GLUE2SUB(a,b)
#define GLUE3(a, b, c) GLUE2(GLUE2SUB(a,b),c)


/*---------------------------------------------------------------------------*/
/*Class and Subclass definition macros*/
/*---------------------------------------------------------------------------*/
#define CLASS(class_) \
    typedef struct GLUE2(class_, Tag) class_; \
    struct GLUE2(class_, Tag) { 

#define SUBCLASS(class_, superclass_) \
    CLASS(class_) \
    superclass_ super_;

#define METHODS };

#define END_CLASS 
/*---------------------------------------------------------------------------*/



#ifdef CREATE_VTABLE_DEFS
/*---------------------------------------------------------------------------*/
/*Virtual Table definition and implementation macros*/
/*---------------------------------------------------------------------------*/
#define VTABLE(class_, superclass_) \
	};\
    typedef struct GLUE2(class_, VTABLETag) GLUE2(class_, VTABLE);\
    /*Object class descriptor*/\
    extern GLUE2(class_, VTABLE) GLUE3(CP_,class_,VTABLE);\
    struct GLUE2(class_, VTABLETag) {\
    /*Field of superclass' VTBL*/\
        GLUE2(superclass_, VTABLE) super_;
		
#define VPTR(class_, obj_) \
    ((GLUE2(class_, VTABLE) *)(((Object *)(obj_))->vptr__))
		
#define BEGIN_VTABLE(class_, superclass_) \
    GLUE2(class_, VTABLE) GLUE3(CP_,class_,VTABLE); \
    static ObjectVTABLE *GLUE2(class_, VTABLECtor)(class_ *t) {\
	    GLUE2(class_, VTABLE) *me = &GLUE3(CP_,class_,VTABLE);\
        *(GLUE2(superclass_, VTABLE) *)me = *VPTR(superclass_, t); \
        ((ObjectVTABLE*)me)->super__ = VPTR(Object, t);

#define END_VTABLE \
        return (ObjectVTABLE*)me; \
    }
		
#define VMETHOD(class_, meth_) \
    ((GLUE2(class_, VTABLE) *)me)->meth_

#define VHOOK(class_) \
    if (((ObjectVTABLE *)&GLUE3(CP_,class_,VTABLE))->super__ == 0) \
        ((Object *)me)->vptr__ = GLUE2(class_, VTABLECtor)(me); \
    else \
        (((Object *)me)->vptr__ = (ObjectVTABLE *)&GLUE3(CP_,class_,VTABLE))
		

#define VCALL(class_, meth_, obj_) \
    (*VPTR(class_, obj_)->meth_)((class_*)(obj_)
	
#define END_CALL )
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*Object abstract class definition*/
/*---------------------------------------------------------------------------*/
CLASS(Object)
    struct ObjectVTABLETag *vptr__; /*private virtual pointer*/
METHODS
    /*protected constructor 'inline'...*/
    #define Object_ctor_(me_) ((me_)->vptr__ = &CP_ObjectVTABLE, (me_))

    /*protected destructor 'inline'...*/
    #define Object_xtor_(me_) ((void)0)

    /*dummy implementation for abstract methods */
    void Object_abstract(void);

    /*Run Time Type Identification (RTTI)*/
    #define Object_IS_KIND_OF(me_, class_) \
       Object_isKindOf__((Object *)(me_), (struct ObjectVTABLETag*)(&GLUE3(CP_,class_,VTABLE)))

    int Object_isKindOf__(Object const *me, struct ObjectVTABLETag const *vtable);
END_CLASS

CLASS(ObjectVTABLE)
    ObjectVTABLE *super__; /*pointer to superclass' VTBL*/
    void (*xtor)(Object * me); /*public virtual destructor*/
METHODS
END_CLASS

extern ObjectVTABLE CP_ObjectVTABLE; /*Object class descriptor*/
/*---------------------------------------------------------------------------*/

#endif

#ifdef __cplusplus
}
#endif

#endif


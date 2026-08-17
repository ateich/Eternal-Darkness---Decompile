extern void* lbl_8064D098;
extern void* memset(void*, int, unsigned long);
extern void fn_8017CE74(void*, void*);

void fn_80149EB8(void* object)
{
    if (object != 0) {
        memset(object, 0, 200);
        fn_8017CE74(lbl_8064D098, object);
    }
}

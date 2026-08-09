extern void* lbl_8064C734;

extern void* fn_8017CDB4(void*);
extern void fn_8017CE74(void*, void*);

int fn_800382C0(void)
{
    int result = 0;
    void* object = fn_8017CDB4(lbl_8064C734);

    if (object != 0) {
        result = 1;
        fn_8017CE74(lbl_8064C734, object);
    }
    return result;
}

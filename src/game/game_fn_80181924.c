extern void* lbl_8064D238;
extern unsigned char lbl_80606334[];

extern void* fn_8018038C(void*, void*);
extern void fn_8018199C(void*, void*, void*, void*);

void* fn_80181924(void* arg0, void* arg1, void* arg2)
{
    void* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_8018199C(result, arg0, arg1, arg2);
    }
    return result;
}

extern void* lbl_8064C4E4;
extern void* fn_80201BD0(void* object);
extern int fn_80038308(void* object, int channel, short* value);

short fn_800509DC(void)
{
    short result = -1;
    void* object = fn_80201BD0(lbl_8064C4E4);

    if (object != 0) {
        fn_80038308(object, 3, &result);
    }
    return result;
}

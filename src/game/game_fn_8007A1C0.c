extern void *fn_80200C38(int value);
extern void fn_801A7588(void *object, int value);
extern void fn_80066888(void *owner, void *object, float first, float second);
extern const float lbl_8064E950;
extern const float lbl_8064E954;

void fn_8007A1C0(void *owner, void *state, int value)
{
    void *object = fn_80200C38(value);

    if (*(unsigned char *)((char *)state + 0x40) == 0) {
        fn_801A7588(object, 2);
        *(unsigned char *)((char *)state + 0x40) = 0x41;
        fn_80066888(owner, object, lbl_8064E950, lbl_8064E954);
    }
}

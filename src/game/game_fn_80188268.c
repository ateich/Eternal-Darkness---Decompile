typedef signed int s32;

extern s32 lbl_8064D248;
extern void* lbl_80606460[];

void fn_80188268(void* object)
{
    s32 index = lbl_8064D248;
    lbl_8064D248 = index + 1;
    lbl_80606460[index] = object;
}

typedef signed char s8;

extern int lbl_803003C8[];
extern int lbl_8064C98C;
extern void* fn_80201814();
extern void* fn_80201B8C();

int fn_800AD2DC(int object)
{
    int result = 1;
    if (lbl_803003C8[2] == 13 && object == lbl_8064C98C) {
        char* runtime = fn_80201814(lbl_8064C98C);
        char* state_object = *(char**)((char*)fn_80201B8C(runtime) + 0x58);
        s8 state = state_object[0x42];
        if (state == 1 || state == 2) {
            result = 0;
        }
    }
    return result;
}

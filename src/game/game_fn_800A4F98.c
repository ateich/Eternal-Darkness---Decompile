typedef unsigned char u8;

typedef struct Runtime800A4F98 {
    u8 pad0[0x9E];
    u8 state;
} Runtime800A4F98;

extern int lbl_8064C544;
extern void *fn_80201814();
extern void *fn_80201B8C();

int fn_800A4F98(int mode)
{
    void* object;
    Runtime800A4F98* runtime;
    int matches;
    int result;

    switch (mode) {
    case 0:
        return lbl_8064C544 & -(fn_80201814((void*)lbl_8064C544) != 0);
    case 1:
        object = fn_80201814((void*)lbl_8064C544);
        runtime = object != 0 ? ((Runtime800A4F98*)fn_80201B8C(object)) : 0;
        matches = runtime != 0 && runtime->state == 1;
        result = -matches;
        result |= matches;
        result >>= 31;
        result &= lbl_8064C544;
        return result;
    case 2:
        object = fn_80201814((void*)lbl_8064C544);
        runtime = object != 0 ? ((Runtime800A4F98*)fn_80201B8C(object)) : 0;
        matches = runtime != 0 && runtime->state == 2;
        result = -matches;
        result |= matches;
        result >>= 31;
        result &= lbl_8064C544;
        return result;
    default:
        return 0;
    }
}

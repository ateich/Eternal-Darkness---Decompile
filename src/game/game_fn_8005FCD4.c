typedef int s32;

extern s32 lbl_8064D18C;

extern s32 fn_800CB098(s32, s32, s32, s32, s32, s32);
extern s32 fn_8005EF94(void *, s32, s32 *, s32, s32);

void fn_8005FCD4(s32 unused, void *object)
{
    s32 result;
    s32 count;

    if (fn_800CB098(-1, 4, -1, lbl_8064D18C, 0, 0) > 1) {
        result = 1;
    } else {
        fn_8005EF94(object, 0x1DB, &count, 0, 0);
        switch (count) {
        case 1:
            result = 3;
            break;
        case 2:
            result = 2;
            break;
        default:
            result = 1;
            break;
        }
    }

    fn_8005EF94(object, 0x1DB, 0, 1, result);
}

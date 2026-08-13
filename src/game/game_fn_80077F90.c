typedef signed int s32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern char lbl_802FC5BC[];
extern Vec3 lbl_80244814;
extern float lbl_8064E8F8;
extern float lbl_8064E8C4;
extern float lbl_8064E8FC;

extern s32 fn_8012FD1C(void *object, s32 index, Vec3 *output);
extern void fn_8014D478();
extern void fn_800CEA1C(s32 kind, s32 value, Vec3 *a, Vec3 *b, s32 c, s32 d,
                        void *data, float x, float y, float z);

void fn_80077F90(void *object)
{
    Vec3 position;

    if (fn_8012FD1C(object, 1, &position) != 0) {
        fn_8014D478(object, &position, &lbl_80244814, 8, 4,
                    lbl_802FC5BC + 0x18, 3);
        fn_800CEA1C(0x17, 3, &position, &lbl_80244814, 2, 3,
                    lbl_802FC5BC + 0x18,
                    lbl_8064E8F8, lbl_8064E8C4, lbl_8064E8FC);
    }
}

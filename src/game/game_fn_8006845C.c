typedef signed int s32;

extern s32 *fn_800681C8(void);
extern int fn_80201B54();
extern void *fn_80201814();

void fn_8006845C(void *object)
{
    s32 *objects;
    s32 owner;
    s32 i;

    objects = fn_800681C8();
    owner = fn_80201B54(object);

    for (i = 0; i < 12; i++) {
        void *candidate;
        s32 *owners;
        s32 j;

        if (objects[i] == 0) {
            continue;
        }
        candidate = fn_80201814(objects[i]);
        if (candidate == 0) {
            objects[i] = 0;
            continue;
        }
        owners = fn_800681C8();
        if (owners == 0) {
            continue;
        }
        for (j = 0; j < 12; j++) {
            if (owners[j] == owner) {
                owners[j] = 0;
            }
        }
    }
}

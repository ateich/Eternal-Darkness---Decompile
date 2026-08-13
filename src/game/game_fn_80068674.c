typedef signed int s32;

extern s32 *fn_800681C8(void);
extern void *fn_80201814();
extern s32 fn_80201B64(void *object);
extern int fn_80201B54();

s32 fn_80068674(void *object, s32 excluded_id)
{
    s32 *objects;
    s32 total;
    s32 i;

    objects = fn_800681C8();
    total = 0;
    if (objects != 0) {
        for (i = 0; i < 12; i++) {
            void *candidate;

            if (objects[i] == 0 || objects[i] == excluded_id) {
                continue;
            }
            candidate = fn_80201814(objects[i]);
            if (candidate == 0) {
                objects[i] = 0;
                continue;
            }
            total += fn_80201B64(candidate) == 0x22;
            total += fn_80068674(candidate, fn_80201B54(object));
        }
    }
    return total;
}

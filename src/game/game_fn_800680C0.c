typedef signed int s32;

extern s32 lbl_8064C89C;
extern s32 *fn_800681C8(void);
extern void *fn_80201814(s32 object_id);
extern s32 fn_80201B54(void *object);

s32 fn_800680C0(void *object, s32 excluded_id)
{
    s32 *slots;
    s32 count;
    s32 index;
    s32 offset;
    void *child;

    slots = fn_800681C8();
    count = 0;
    fn_80201B54(object);
    lbl_8064C89C++;

    if (lbl_8064C89C > 12) {
    }
    if (slots == 0) {
    }

    index = 0;
    offset = 0;
    while (slots != 0 && index < 12) {
        s32 *slot = (s32 *)((unsigned char *)slots + offset);
        if (*slot != 0 && *slot != excluded_id) {
            child = fn_80201814(*slot);
            if (child != 0) {
                count++;
                count += fn_800680C0(child, fn_80201B54(object));
            } else {
                *slot = 0;
            }
        }
        index++;
        offset += 4;
    }

    lbl_8064C89C--;
    return count;
}

typedef signed int s32;

typedef struct Entry80201814 Entry80201814;

extern s32 lbl_8064C89C;
extern s32 *fn_800681C8(void);
extern Entry80201814 *fn_80201814(int id);
extern int fn_80201B54(int *object);

/* The retail build retains the empty branches from two stripped assertions. */
s32 fn_800680C0(void *object, s32 excluded_id)
{
    s32 *slots;
    s32 index;
    s32 count;

    slots = fn_800681C8();
    count = 0;
    fn_80201B54(object);
    lbl_8064C89C++;
    if (lbl_8064C89C > 12) {
        /* ASM: nop preserves a stripped assertion; an empty C branch is removed. */
        asm { nop }
    }
    if (slots == 0) {
        /* ASM: nop preserves a stripped assertion; an empty C branch is removed. */
        asm { nop }
    }

    index = 0;
    while (slots != 0 && index < 12) {
        s32 slot = slots[index];

        if (slot != 0 && excluded_id != slot) {
            Entry80201814 *child = fn_80201814(slot);
            if (child != 0) {
                count++;
                count += fn_800680C0(child, fn_80201B54(object));
            } else {
                slots[index] = 0;
            }
        }
        index++;
    }

    lbl_8064C89C--;
    return count;
}

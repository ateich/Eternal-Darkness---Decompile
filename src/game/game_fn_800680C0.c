typedef signed int s32;

extern s32 lbl_8064C89C;
extern s32 *fn_800681C8(void);
extern void *fn_80201814();
extern int fn_80201B54();

/* NonMatching: retail retains two stripped assertion guards and advances a
 * separate byte offset. The bounded, narrow subscript preserves indexed access
 * without keeping both raw and aligned offsets live across recursive calls. */
s32 fn_800680C0(void *object, s32 excluded_id)
{
    s32 *slots;
    s32 index;
    s32 count;

    slots = fn_800681C8();
    count = 0;
    fn_80201B54(object);
    lbl_8064C89C++;

    index = 0;
    while (slots != 0 && index < 12) {
        if (slots[(unsigned short)index] != 0 &&
            slots[(unsigned short)index] != excluded_id) {
            void *child = fn_80201814(slots[(unsigned short)index]);
            if (child != 0) {
                count++;
                count += fn_800680C0(child, fn_80201B54(object));
            } else {
                slots[(unsigned short)index] = 0;
            }
        }
        index++;
    }

    lbl_8064C89C--;
    return count;
}

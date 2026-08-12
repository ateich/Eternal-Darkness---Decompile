typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

typedef struct RelationEntry {
    s32 primary;
    s32 secondary;
    s32 tertiary;
} RelationEntry;

extern s32 fn_80035628(void *object);
extern void *fn_80201B8C();
extern RelationEntry lbl_8023BA64[];

s16 fn_8006534C(void *first, void *second, s16 value)
{
    s32 first_index;
    s32 second_index;
    u8 *first_info;
    u8 *second_info;

    if (first != 0 && second != 0) {
        first_index = fn_80035628(first);
        second_index = fn_80035628(second);
        first_info = fn_80201B8C(first);
        second_info = fn_80201B8C(second);
        if (first_info != 0 && second_info != 0 && first_info[0x9E] == 2 &&
            second_info[0x9E] == 2) {
            if (second_index == lbl_8023BA64[first_index].secondary) {
                /* Same relation: preserve the requested value. */
            } else if (second_index == lbl_8023BA64[first_index].tertiary) {
                value = (s16)(value * 3);
            } else if (second_index == lbl_8023BA64[first_index].primary) {
                value = (s16)(value >> 1);
            }
        }
    }
    return value;
}

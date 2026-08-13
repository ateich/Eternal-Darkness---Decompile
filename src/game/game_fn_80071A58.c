typedef unsigned char u8;

typedef struct GlobalState {
    u8 pad_00[8];
    unsigned int level;
} GlobalState;

extern GlobalState lbl_803003C8;
extern void *fn_80201B9C();

void fn_80071A58(u8 *flags)
{
    fn_80201B9C();
    *flags = 1;

    switch (lbl_803003C8.level) {
    case 0:
    case 4:
    case 5:
    case 7:
    case 10:
        *flags |= 4;
        break;
    case 6:
    case 8:
    case 11:
        *flags |= 6;
        break;
    }
}

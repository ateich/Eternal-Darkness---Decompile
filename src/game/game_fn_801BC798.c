typedef unsigned short u16;

typedef struct ResourceEntry8 {
    u16 id;
    u16 count;
    void* value;
} ResourceEntry8;

extern ResourceEntry8 lbl_80626948[];
extern u16 lbl_8064D3FA;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

int fn_801BC798(u16 id)
{
    int index;

    index = 0;
    while (index < lbl_8064D3FA && lbl_80626948[index].id != id) {
        index++;
    }

    if (index != lbl_8064D3FA) {
        int move_index;

        fn_801CE2B8();
        for (move_index = index + 1; move_index < lbl_8064D3FA; move_index++) {
            lbl_80626948[move_index - 1] = lbl_80626948[move_index];
        }
        lbl_8064D3FA--;
        fn_801CE280();
        return 1;
    }
    return 0;
}

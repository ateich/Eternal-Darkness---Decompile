typedef unsigned int u32;
typedef unsigned short u16;

extern int lbl_8064C6FC;
extern void* fn_80201B3C();
extern void* fn_80201B9C();
extern void* fn_80201BC0(void*);
extern int fn_80201B4C(void*);
extern unsigned int fn_80036D5C(void*);

u16 fn_80028B44(void)
{
    u16 count = 0;
    void* head = fn_80201B3C();
    void* item = fn_80201B9C();

    while (item != 0) {
        if (item != head && fn_80201B4C(item) == 1 &&
            (fn_80036D5C(item) & 0x04000000)) {
            count++;
        }
        item = fn_80201BC0(item);
    }
    if (count != 0) {
        lbl_8064C6FC = 2;
    }
    return count;
}

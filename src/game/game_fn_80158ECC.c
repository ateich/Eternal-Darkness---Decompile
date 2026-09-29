typedef signed short s16;
typedef unsigned int u32;

typedef struct Entry {
    s16 id;
    s16 state;
    void* value04;
    void* value08;
    char pad0C[0xC];
} Entry;

extern Entry lbl_805B6F80[];
extern int fn_80158E88(int);
extern int fn_80159EEC(void);
extern void fn_80159DD0(int, int);
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);

int fn_80158ECC(int id)
{
    int index = fn_80158E88(id);

    if (index == -1) {
        u32 interrupts;
        index = fn_80159EEC();
        interrupts = OSDisableInterrupts();
        lbl_805B6F80[index].id = id;
        lbl_805B6F80[index].state = 0;
        lbl_805B6F80[index].value08 = 0;
        lbl_805B6F80[index].value04 = 0;
        OSRestoreInterrupts(interrupts);
    }
    if (lbl_805B6F80[index].state == 0) {
        fn_80159DD0(id, index);
    }
    return index;
}

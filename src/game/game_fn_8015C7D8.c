typedef struct Entry {
    short id;
    short state;
    void* value04;
    void* value08;
    int counter;
    unsigned char tail[8];
} Entry;

extern Entry lbl_805B6F80[];
extern int lbl_8064D18C;
extern int fn_80158E88(int);
extern void fn_80159E0C(void);
extern int fn_80159EEC(void);
extern unsigned int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(unsigned int);
extern void fn_8015C020(int);

void fn_8015C7D8(int id)
{
    int index;
    unsigned int interrupts;

    if (fn_80158E88(id) == -1) {
        index = fn_80158E88(lbl_8064D18C);
        fn_80159E0C();
        if (index != -1)
            lbl_805B6F80[index].counter = 0;

        index = fn_80159EEC();
        interrupts = OSDisableInterrupts();
        lbl_805B6F80[index].id = id;
        lbl_805B6F80[index].state = 0;
        lbl_805B6F80[index].value08 = 0;
        lbl_805B6F80[index].value04 = 0;
        OSRestoreInterrupts(interrupts);
        fn_8015C020(0);
    }
}

extern int lbl_8064C55C;
extern int lbl_8064D18C;
extern int fn_80200C38();
extern int fn_80201EB8();
extern unsigned short fn_8012DBE8(void*, int, void*);
extern void fn_800DD314(void*, int, int, int);

void fn_8009073C(void* object, void* actor, void* arg3)
{
    unsigned char state[4];
    int value = fn_80200C38(arg3);
    int associated = fn_80201EB8(object);

    if (associated == lbl_8064D18C && lbl_8064C55C == 0) {
        fn_8012DBE8(actor, 15, state);
        if (state[3] == 0 || state[3] == 0xFD) {
            if (value != 0) {
                fn_800DD314(object, 15, 0xFD, 0xFD);
            } else {
                fn_800DD314(object, 15, 0xFD, 0);
            }
        }
    }
}

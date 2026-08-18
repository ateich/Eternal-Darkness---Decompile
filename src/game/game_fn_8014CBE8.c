typedef unsigned char u8;

extern float lbl_8064CF04;
extern float lbl_806504F8;
extern void* lbl_8064C4E0;
extern int lbl_802FC5BC[];

extern void fn_80201BC8(void*);
extern void* fn_80149D98(void (*)(void));
extern void fn_80149D64(void*);
extern int fn_80201B54(void*);
extern int fn_801E79FC(void*, int);
extern void fn_8014DB5C(void);

void fn_8014CBE8(void* owner, int kind, int value, int* source)
{
    void* state;

    fn_80201BC8(owner);
    if (!(lbl_8064CF04 >= lbl_806504F8)) {
        state = fn_80149D98(fn_8014DB5C);
        if (state != 0) {
            fn_80149D64(state);
            *(u8*)((char*)state + 0x1328) = 4;
            *(int*)((char*)state + 0x38C) = 0;
            *(u8*)((char*)state + 0x398) = 1;
            *(u8*)((char*)state + 0x399) = 1;
            *(u8*)((char*)state + 0x39A) = 5;
            *(int*)((char*)state + 0x39C) = value;
            *(int*)((char*)state + 0x3A0) = kind;
            *(int*)((char*)state + 0x394) = fn_80201B54(owner);
            *(int*)((char*)state + 0x3A4) = *source;
            if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0)
                *(int*)((char*)state + 0x3A4) = lbl_802FC5BC[9];
        }
    }
}

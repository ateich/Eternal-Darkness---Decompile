typedef unsigned char u8;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void* lbl_8064C4E0;
extern int lbl_802FC5BC[];

extern void fn_8014DA68(void);
extern void* fn_80149D98(void (*)(void));
extern void fn_80149D64(void*);
extern int fn_80201A84(void*);
extern int fn_801E79FC(void*, int);

void fn_8014D98C(void* owner, Vec3* position, Vec3* velocity,
                 int kind, u8 variant, int* source)
{
    void* state;

    state = fn_80149D98(fn_8014DA68);
    if (state != 0) {
        fn_80149D64(state);
        *(u8*)((char*)state + 0x1328) = 4;
        *(int*)((char*)state + 8) = -1;
        if (owner != 0)
            *(int*)((char*)state + 8) = fn_80201A84(owner);
        *(Vec3*)((char*)state + 0x14) = *position;
        *(Vec3*)((char*)state + 0x20) = *velocity;
        *(int*)((char*)state + 0xC) = kind;
        *(u8*)((char*)state + 0x2C) = variant;
        *(int*)((char*)state + 0x10) = *source;
        if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0)
            *(int*)((char*)state + 0x10) = lbl_802FC5BC[9];
    }
}

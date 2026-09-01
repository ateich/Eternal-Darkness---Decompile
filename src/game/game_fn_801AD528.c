typedef unsigned char u8;
typedef unsigned short u16;

typedef struct EffectSlot {
    int object_id;
    int handle;
    int resource;
    u8 x;
    u8 y;
    u8 active;
    u8 pad[5];
} EffectSlot;

typedef struct EffectNode EffectNode;

extern volatile EffectSlot lbl_8060B204[2];
extern int fn_801AD7C0(int, int);
extern EffectNode* fn_801AD4B4(int, int, int, u16);
extern void fn_801AD404(u8, u8, int);
extern void fn_801AD490(void);

void fn_801AD528(int index, int timer)
{
    int offset = index * sizeof(EffectSlot);
    volatile int* handle;
    volatile u8* active = (volatile u8*)lbl_8060B204 + offset + 0xe;

    if (*active == 1) {
        handle = (volatile int*)((volatile u8*)lbl_8060B204 + offset + 4);
        *handle = fn_801AD7C0(*handle, 2);
        fn_801AD4B4(*(int*)((u8*)lbl_8060B204 + offset), *handle,
                    *(int*)((u8*)lbl_8060B204 + offset + 8), 0);
        fn_801AD404(*((u8*)lbl_8060B204 + offset + 12),
                     *((u8*)lbl_8060B204 + offset + 13), timer);
        *active = 0;
    } else {
        fn_801AD490();
        fn_801AD404(100, 100, 1);
    }
}

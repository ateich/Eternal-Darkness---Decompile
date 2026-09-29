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

extern EffectSlot lbl_8060B204[2];
extern int fn_801AD7C0(int, int);
extern EffectNode* fn_801AD4B4(int, int, int, u16);
extern void fn_801AD404(u8, u8, int);
extern void fn_801AD490(void);

void fn_801AD528(int index, int timer)
{
    if (lbl_8060B204[index].active == 1) {
        lbl_8060B204[index].handle = fn_801AD7C0(lbl_8060B204[index].handle, 2);
        fn_801AD4B4(lbl_8060B204[index].object_id, lbl_8060B204[index].handle,
                    lbl_8060B204[index].resource, 0);
        fn_801AD404(lbl_8060B204[index].x, lbl_8060B204[index].y, timer);
        lbl_8060B204[index].active = 0;
    } else {
        fn_801AD490();
        fn_801AD404(100, 100, 1);
    }
}

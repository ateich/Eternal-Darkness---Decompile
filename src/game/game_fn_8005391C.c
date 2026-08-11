typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

typedef struct TransitionState {
    u8 pad000[0x1C8];
    s32 elapsed;
    u8 pad1CC[14];
    u8 type;
    u8 pad1DB[9];
    u8 restore;
} TransitionState;

typedef struct TransitionDescriptor {
    u8 pad00[0x20];
    s16 restore;
    u8 pad22[6];
} TransitionDescriptor;

extern TransitionState lbl_8030F540;
extern TransitionDescriptor lbl_80241DE8[];
extern void* lbl_8064C85C;
extern s32 lbl_8064C854;
extern s32 lbl_8064D780;
extern s32 lbl_8064C600;
extern void fn_80144680(void*);
extern void fn_801F550C(void);
extern int fn_801E8328();

void fn_8005391C(s16 value)
{
    fn_80144680(lbl_8064C85C);

    if (value == 1 && lbl_80241DE8[lbl_8030F540.type].restore != -1) {
        lbl_8030F540.restore = 1;
    }

    lbl_8064C854 = 0;
    lbl_8030F540.elapsed = -2;
    if (lbl_8064D780 != 0 && value == 1) {
        fn_801F550C();
        lbl_8064D780 = 0;
    }
    lbl_8064C600 = 1;
    fn_801E8328(0x17, 0);
}

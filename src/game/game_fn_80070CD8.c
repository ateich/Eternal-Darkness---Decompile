typedef unsigned char u8;

typedef struct ObjectData {
    u8 pad_00[0x9E];
    u8 state;
    u8 mode;
} ObjectData;

typedef struct GlobalState {
    u8 pad_00[8];
    int level;
} GlobalState;

extern GlobalState lbl_803003C8;
extern void *lbl_8064C4E0;
extern int lbl_8064D18C;
extern void fn_80201B44(int);
extern void fn_80201814(void);
extern ObjectData *fn_80201B8C(void);
extern int fn_801E79FC(void *, int);
extern int fn_8015E4E8(void);
extern void *fn_8007D944(void);
extern int fn_800460EC(void);
extern int fn_801D10B8(void);
extern int fn_8006B96C(int, int);
extern int fn_800AF6D4(void);
extern int fn_800AF6DC(void);

int fn_80070CD8(int flags)
{
    ObjectData *data;

    fn_80201B44(flags);
    fn_80201814();
    data = fn_80201B8C();
    if (flags & 4) return 1;
    if (lbl_803003C8.level == 5 && fn_801E79FC(lbl_8064C4E0, 0x373) != 0) return 0;
    if (fn_8015E4E8() != 0) return 0;
    if (fn_8007D944() != 0) return 0;
    if (data->state == 1 && (data->mode == 3 || data->mode == 6 || data->mode == 4)) return 0;
    if (fn_800460EC() != 0) return 0;
    if ((flags & 1) == 0 && fn_801D10B8() != 0) return 0;
    if (fn_8006B96C(lbl_8064D18C, 5) != -1) return 0;
    if (flags & 2) {
        if (fn_800AF6D4() != 0) return 0;
        if (fn_800AF6DC() != 0) return 0;
    }
    return 1;
}

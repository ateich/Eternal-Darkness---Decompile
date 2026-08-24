typedef unsigned char u8;
typedef int s32;

extern int fn_80201B54();
extern s32 fn_800460EC(void);
extern void fn_800D6974(void *, void *);
extern s32 fn_802006D4(s32, s32, s32, s32, s32);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

void fn_800D8828(void *object, void *other)
{
    s32 ready = 1;
    s32 other_id = ((s32)fn_80201B54(other));

    if (((((u8 *)object)[0x2A2] >> 7) & 1) != 0 || fn_800460EC() != 0) {
        ready = 0;
    }
    if (ready != 0) {
        fn_800D6974(object, other);
        fn_802006D4(other_id, other_id, -1, -1, 0);
        fn_80201D2C(other, 1);
        fn_80201D14(other, 1);
    }
}

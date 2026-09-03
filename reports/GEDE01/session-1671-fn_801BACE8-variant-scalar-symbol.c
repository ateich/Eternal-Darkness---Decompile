/* Remediation-2 replayable reenactment; the exact remediation-1 temporary source was lost. */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct StreamSlot {
    u32 id;
    u32 flags;
    u8 state;
    u8 pad09[0x3F];
    u32 voice;
    u32 parameter;
    u8 pad50[0x10];
    u32 cache;
} StreamSlot;

extern StreamSlot lbl_8061AE48[];
extern u32 lbl_80619C20[];
extern float lbl_80650F18;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern int fn_801B9D1C(u32);
extern void fn_801CCB98(u32, u32);

static inline u32 find_stream(u32 id)
{
    u32 i;

    for (i = 0; i < 64; i++) {
        if (lbl_8061AE48[i].state != 0 && lbl_8061AE48[i].id == id) {
            return i;
        }
    }
    return -1;
}

void fn_801BACE8(u32 id, u32 parameter)
{
    u32 offset;
    int index;
    u32 cache;

    fn_801CE2B8();
    index = find_stream(id);
    if (index != (u32)-1) {
        offset = index * sizeof(StreamSlot);
        lbl_8061AE48[index].parameter = parameter;
        if (lbl_8061AE48[index].state == 2) {
            fn_801CCB98(lbl_8061AE48[index].voice,
                        (int)((float)lbl_80619C20[0] * lbl_80650F18 /
                              (float)parameter));
        }
        cache = lbl_8061AE48[index].cache;
        if (cache != (u32)-1) {
            fn_801CE2B8();
            index = fn_801B9D1C(cache);
            if (index != (u32)-1) {
                lbl_8061AE48[index].parameter = parameter;
                if (lbl_8061AE48[index].state == 2) {
                    fn_801CCB98(lbl_8061AE48[index].voice,
                                (int)((float)lbl_80619C20[0] * lbl_80650F18 /
                                      (float)parameter));
                }
                cache = lbl_8061AE48[index].cache;
                if (cache != (u32)-1) {
                    fn_801BACE8(cache, parameter);
                }
            }
            fn_801CE280();
        }
    }
    fn_801CE280();
}

typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct FirstEntry {
    u8 pad_00[0x19];
    u8 kind;
    u8 pad_1A[2];
    s16 id;
    u8 pad_1E[0xA];
} FirstEntry;

typedef struct SecondEntry {
    u8 pad_00[8];
    s16 kind;
    u8 pad_0A[4];
    s16 id;
    u8 pad_10[8];
} SecondEntry;

extern const char lbl_8023BEF8[];
extern FirstEntry lbl_80241DE8[];
extern SecondEntry lbl_802417D0[];
extern void* lbl_8024E388[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801E7974(void*, int);

s32 fn_800169FC(void* script)
{
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    {
        void** objects = lbl_8024E388;
        FirstEntry* first = lbl_80241DE8;
        s32 i;

        for (i = 0; i < 173; i++, first++) {
            if (first->id != -1) {
                if (first->kind == 0) {
                    fn_801E7974(objects[0], first->id);
                } else {
                    fn_801E7974(
                        *(void**)((u8*)objects + first->kind * 4 - 4),
                        first->id);
                }
            }
        }
    }

    {
        void** objects = lbl_8024E388;
        SecondEntry* second = lbl_802417D0;
        s32 i;

        for (i = 0; i < 51; i++, second++) {
            if (second->id != -1) {
                s32 kind = (u8)second->kind;
                if (kind == 0xFF) {
                    fn_801E7974(objects[0], second->id);
                } else {
                    fn_801E7974(*(void**)((u8*)objects + kind * 4 - 4),
                                second->id);
                }
            }
        }
    }

    return 0;
}

typedef unsigned char u8;

typedef struct Entry801A7098 {
    u8 pad0[0x64];
    int field64;
    u8 pad68[0x10];
    unsigned int flags78;
    u8 pad7C[0x20];
    unsigned int field9C;
} Entry801A7098;

extern Entry801A7098* lbl_80607C10[];
extern void* lbl_8064D274;
extern void* fn_80201814(unsigned int);
extern void* fn_80201BC8(void*);
extern int fn_80126070(void*);
extern void fn_80128618(void*, Entry801A7098*);
extern Entry801A7098* fn_8017CDB4(void*);

Entry801A7098* fn_801A7098(void)
{
    int i;
    Entry801A7098* entry;
    Entry801A7098* best = 0;
    void* first;
    void* second;

    for (i = 0; i < 40; i++) {
        entry = lbl_80607C10[i];
        if (entry != 0 && !(entry->flags78 & 1) &&
            (best == 0 || best->field64 < entry->field64)) {
            first = fn_80201814(entry->field9C);
            if (first != 0) {
                second = fn_80201BC8(first);
            } else {
                second = 0;
            }
            if (first != 0 && second != 0 && fn_80126070(second) == 0) {
                best = entry;
            }
        }
    }
    if (best != 0) {
        first = fn_80201814(best->field9C);
        if (first != 0) {
            second = fn_80201BC8(first);
            fn_80128618(second, best);
        }
        best = fn_8017CDB4(lbl_8064D274);
    }
    return best;
}

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct RuntimeEntry {
    unsigned char pad_00[0x2C];
    u32 id;
    unsigned char pad_30[0x38];
    u32 flags;
    unsigned char pad_6C[8];
} RuntimeEntry;

typedef struct RuntimeInfo {
    unsigned char pad_00[0xB0];
    u16 count;
    u16 pad_B2;
    RuntimeEntry* entries;
} RuntimeInfo;

extern RuntimeInfo* fn_8015C28C(int);
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern u32 fn_800F5C54(double);
extern void fn_8016A830(void*, double);
extern void fn_8016A7D8(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];
extern const double lbl_806506D8;

int fn_80172ACC(void* state)
{
    RuntimeInfo* info = fn_8015C28C(2);
    int i;
    u32 id;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    id = fn_800F5C54(fn_8016A694(state, 1));
    for (i = 0; i < info->count; i++) {
        RuntimeEntry* entry = &info->entries[i];
        if (id == entry->id && (entry->flags & 1) != 0) {
            fn_8016A830(state, lbl_806506D8);
            return 1;
        }
    }

    fn_8016A7D8(state);
    return 1;
}

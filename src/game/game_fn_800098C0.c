typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

#pragma use_lmw_stmw on

typedef struct Player {
    unsigned char pad0[0xB0];
    u16 count;
    unsigned char padB2[2];
    unsigned char* entries;
} Player;

extern const char lbl_8023BEF8[];

extern unsigned int fn_800F5C54();
extern Player* fn_8015C28C(s32);
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A830(void*, double);
extern void fn_8016A7D8(void*);
extern u16 fn_80034054(void*, s32);

s32 fn_800098C0(void* script)
{
    Player* player;
    u32 object_id;
    s32 entry_offset;
    s32 i;
    s32 value;

    player = fn_8015C28C(2);
    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    object_id = fn_800F5C54(fn_8016A694(script, 1));
    value = (s32)fn_8016A694(script, 2);
    i = 0;
    entry_offset = 0;
    for (; i < player->count; entry_offset += 0x74, i++) {
        void* entry;
        s32 result;

        entry = player->entries + entry_offset;
        if (object_id != *(u32*)((unsigned char*)entry + 0x2C)) {
            continue;
        }

        result = fn_80034054(entry, value);
        if (result > 0) {
            fn_8016A830(script, (double)result);
            return 1;
        }
    }

    fn_8016A7D8(script);
    return 1;
}

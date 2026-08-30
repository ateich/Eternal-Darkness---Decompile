typedef unsigned int u32;

typedef struct EventEntry {
    u32 mask;
    u32 enabled;
    void (*callback)(void);
    u32 argument;
    u32 count;
    u32 field14;
    u32 field18;
    u32 field1C;
} EventEntry;

extern EventEntry lbl_80607AE0[7];
extern void memcpy(void*, const void*, u32);
extern void fn_801A5EC4(void);
extern void fn_801A5F20(void);
extern void fn_801A5F30(void);
extern void fn_801A5ED4(void);
extern void fn_801A5EB4(void);
extern void fn_801A664C(void);
extern void fn_801A6654(void);

void fn_801A6C58(void)
{
    EventEntry entries[7] = {
        { 0x100, 0, fn_801A5EC4, 0, 1, 0, 0, 0 },
        { 0x10, 0, fn_801A5F20, 0, 1, 0, 0, 0 },
        { 0x10, 1, fn_801A5F30, 0, 1, 0, 0, 0 },
        { 0x100, 1, fn_801A5ED4, 0, 1, 0, 0, 0 },
        { 0x200, 0, fn_801A5EB4, 0, 1, 0, 0, 0 },
        { 0x30000, 1, fn_801A664C, 0, 30, 0, 0, 0 },
        { 0xC0000, 1, fn_801A6654, 0, 30, 0, 0, 0 },
    };

    memcpy(lbl_80607AE0, entries, sizeof(entries));
}

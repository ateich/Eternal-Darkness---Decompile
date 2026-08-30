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

extern EventEntry lbl_806079C0[9];
extern void memcpy(void*, const void*, u32);
extern void fn_801A5EC4(void);
extern void fn_801A5ED4(void);
extern void fn_801A5F20(void);
extern void fn_801A5F30(void);
extern void fn_801A5EB4(void);
extern void fn_801A5F40(void);
extern void fn_801A5F54(void);
extern void fn_801A5F90(void);
extern void fn_801A5FA0(void);

void fn_801A6CB4(void)
{
    EventEntry entries[9] = {
        { 0x100, 0, fn_801A5EC4, 0, 1, 0, 0, 0 },
        { 0x100, 1, fn_801A5ED4, 0, 1, 0, 0, 0 },
        { 0x10, 0, fn_801A5F20, 0, 1, 0, 0, 0 },
        { 0x10, 1, fn_801A5F30, 0, 1, 0, 0, 0 },
        { 0x200, 0, fn_801A5EB4, 0, 1, 0, 0, 0 },
        { 0x30000, 1, fn_801A5F40, 0, 72, 0, 0, 0 },
        { 0xC0000, 1, fn_801A5F54, 0, 72, 0, 0, 0 },
        { 0x400, 1, fn_801A5F90, 0, 1, 0, 0, 0 },
        { 0x1000000, 1, fn_801A5FA0, 0, 1, 0, 0, 0 },
    };

    memcpy(lbl_806079C0, entries, sizeof(entries));
}

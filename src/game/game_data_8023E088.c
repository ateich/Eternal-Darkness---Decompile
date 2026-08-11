typedef int s32;
typedef unsigned int u32;

typedef void (*EventCallback)(s32, u32);

typedef struct EventRecord {
    u32 type;
    u32 flags;
    EventCallback callback;
    u32 value;
    u32 parameter;
    u32 reserved[3];
} EventRecord;

extern void fn_80027C38(s32, u32);
extern void fn_801E5D38(s32, u32);
extern void fn_80006D50(s32, u32);

/* Event descriptors used by the advanced-button interaction flow. */
#pragma force_active on
EventRecord lbl_8023E088[3] = {
    {0x00000200, 0, fn_80027C38, 0, 1, {0, 0, 0}},
    {0x000C0000, 1, fn_801E5D38, 0, 0x0000FFFB, {0, 0, 0}},
    {0x00001000, 0, fn_80006D50, 0, 1, {0, 0, 0}},
};
#pragma force_active reset

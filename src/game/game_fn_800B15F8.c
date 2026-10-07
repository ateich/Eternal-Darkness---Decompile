#include "src/game/types.h"

typedef struct RuntimeInfo {
    u8 pad00[0x2E];
    u8 flags2E;
    u8 pad2F;
    u32 size;
    u16 flags34;
    u16 flags36;
    u32 field38;
} RuntimeInfo;

extern void* memset(void*, int, u32);
extern void* memcpy(void*, const void*, u32);
extern u32 strlen(const char*);
extern u32 fn_800244C4(void*, u32, u32);
extern u8 lbl_80246F80[];

u16 fn_800B15F8(const char* first, const char* second, u8* data,
                 u32 value, RuntimeInfo* runtime)
{
    u16 offset;

    runtime->field38 = 0;
    memset(data, 0, 0x20);
    memcpy(data, first, strlen(first));
    memset(data + 0x20, 0, 0x20);
    memcpy(data + 0x20, second, strlen(second));
    offset = fn_800244C4(lbl_80246F80, (u32)(data + 0x40), value) + 0x40;
    runtime->flags2E = (runtime->flags2E & ~3) | 1;
    runtime->size = 0x40;
    runtime->flags2E &= ~4;
    runtime->flags34 = (runtime->flags34 & ~3) | 1;
    runtime->flags36 = (runtime->flags36 & ~3) | 3;
    runtime->flags36 &= ~0xC;
    return offset;
}

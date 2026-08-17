typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Slot { void* owner; u32 capacity; void* data; u32 x; u32 y; unsigned short tag; u8 state; } Slot;

extern Slot* lbl_8064CF88;
extern char* lbl_8064CF80;
extern int lbl_8064CFAC;
extern u32 lbl_8064CFB0;
extern u8 lbl_8064CFA4;

/* NonMatching: honest reconstruction of the pool reset. Retail uses MWCC's
 * eight-way unrolled loop to clear owner and state fields. */
u32 fn_80135748(u32* end_out)
{
    int i;
    u32 aligned = (lbl_8064CF88->capacity + 31) & ~31;
    u32 end = (u32)(lbl_8064CF80 + lbl_8064CFB0) - aligned;
    lbl_8064CFA4 = 1;
    if (end_out != 0) *end_out = end;
    for (i = 0; i < lbl_8064CFAC; i++) {
        lbl_8064CF88[i].state = 0;
        lbl_8064CF88[i].owner = 0;
    }
    return aligned;
}

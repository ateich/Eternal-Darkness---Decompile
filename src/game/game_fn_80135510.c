typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Group { u32 count; u32 width; } Group;
typedef struct Slot { void* owner; u32 capacity; void* data; u32 x; u32 y; unsigned short tag; u8 state; } Slot;

extern int lbl_8064CF84;
extern int lbl_8064CF8C;
extern Group* lbl_8064CF90;
extern u32 lbl_8064CF94;
extern Slot* lbl_8064CF88;
extern void* lbl_8064CF80;
extern int lbl_8064CF9C;
extern int lbl_8064CFA0;
extern u8 lbl_8064CFA4;
extern u32 lbl_8064CFAC;
extern u32 lbl_8064CFB0;
extern Group lbl_8024EEB8[];
extern char lbl_8024EEF8[];

extern void* fn_801FEA8C(u32, int, char*, int);
extern void* memset(void*, int, unsigned long);
extern int fn_801358B4(int);
extern void fn_80134FD8(Slot*, u32, void*);

/* NonMatching: honest reconstruction of the one-time pool allocation and
 * group partitioning. The retail compiler fully unrolls the eight-group sum. */
void fn_80135510(void)
{
    int i;
    u32 j;
    u32 offset = 0;
    u32 record_offset = 0;

    if (lbl_8064CF84 == 0) {
        lbl_8064CF8C = 8;
        lbl_8064CF84 = 1;
        lbl_8064CF90 = lbl_8024EEB8;
        lbl_8064CFB0 = 0;
        lbl_8064CFAC = 0;
        for (i = 0; i < 8; i++) {
            lbl_8064CFB0 += lbl_8064CF90[i].count * lbl_8064CF90[i].width;
            lbl_8064CFAC += lbl_8064CF90[i].count;
        }
        lbl_8064CF88 = fn_801FEA8C(0x360, 1, lbl_8024EEF8, 0x329);
        memset(lbl_8064CF88, 0, 0x90);
        lbl_8064CF80 = fn_801FEA8C(lbl_8064CFB0, 1, lbl_8024EEF8, 0x32D);
    }
    lbl_8064CFA0 = 0;
    lbl_8064CF9C = 0;
    lbl_8064CFA4 = 0;
    fn_801358B4(1);
    lbl_8064CF94 = 0;
    for (i = 0; i < lbl_8064CF8C; i++) {
        Group* group = &lbl_8064CF90[i];
        if (lbl_8064CF94 < group->width) lbl_8064CF94 = group->width;
        for (j = 0; j < group->count; j++) {
            fn_80134FD8((Slot*)((char*)lbl_8064CF88 + record_offset),
                        group->width, (char*)lbl_8064CF80 + offset);
            record_offset += 0x18;
            offset += group->width;
        }
    }
}

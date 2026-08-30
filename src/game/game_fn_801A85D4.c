typedef unsigned short u16;
typedef unsigned long u32;

typedef struct Descriptor801A85D4 {
    u32 words[8];
} Descriptor801A85D4;

extern const Descriptor801A85D4 lbl_8023B2D0;

extern void fn_801EDA7C(Descriptor801A85D4*, u32, u32, u32);

void fn_801A85D4(u32* value, u16 first, u16 second, u32 word6)
{
    /* NonMatching: size-exact behavior-complete C. Canonical GC/1.3
     * schedules the aggregate copy and saved input value differently. */
    u32 last = *value;
    Descriptor801A85D4 descriptor = lbl_8023B2D0;

    ((u16*)&descriptor)[0] = first;
    ((u16*)&descriptor)[5] = second;
    descriptor.words[6] = word6;
    descriptor.words[7] = last;
    fn_801EDA7C(&descriptor, 0, 0x2BF, 0);
}

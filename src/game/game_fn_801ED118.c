typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

extern u8 lbl_80639260[];
extern s32 lbl_8064D634;
extern s32 lbl_8064D63C;
extern s32 lbl_8064D680;
extern s32 lbl_8064D684;
extern s32 lbl_8064D6B0;

typedef struct Record16 { s32 value[4]; } Record16;
typedef struct Record24 { s32 pad0; s32 a; s32 b; s32 c; u8 flag; u8 pad11[3]; s32 d; } Record24;
typedef struct Record8 { s32 a; s32 b; } Record8;

/* NonMatching: behavior-complete initialization reconstructed from retail.
 * Field stores and pointer increments follow retail's record-loop schedule,
 * but GC/1.3 still keeps its pointers in volatile registers while retail uses
 * r25-r31 and a 0x30-byte frame, leaving this function 64 bytes shorter. */
void fn_801ED118(void)
{
    u8* base = lbl_80639260;
    s32 i;

    {
        s16* half = (s16*)(base + 0x21D8);
        s32* word = (s32*)(base + 0x21F8);
        for (i = 0; i < 11; i++) {
            half[i] = -1;
            word[i] = -1;
        }
    }
    lbl_8064D634 = -1;
    *(s32*)(base + 0x21F0) = 0;
    lbl_8064D63C = 0;

    {
        s32* a = (s32*)(base + 0x2238);
        s32* z = (s32*)(base + 0x2278);
        s32* c = (s32*)(base + 0x22F8);
        s32* d = (s32*)(base + 0x2338);
        s32* e = (s32*)(base + 0x2378);
        s32* f = (s32*)(base + 0x2938);
        s32* g = (s32*)(base + 0x2978);
        s32* h = (s32*)(base + 0x29B8);
        Record16* r16a = (Record16*)(base + 0x23B8);
        Record16* r16b = (Record16*)(base + 0x24B8);
        Record24* r24a = (Record24*)(base + 0x25B8);
        Record24* r24b = (Record24*)(base + 0x2738);
        Record8* r8 = (Record8*)(base + 0x28B8);
        s32* b = (s32*)(base + 0x22B8);
        for (i = 0; i < 8; i++) {
            *a++ = -1;
            *z++ = 0;
            *c++ = -1;
            *d++ = -1;
            *e++ = -1;
            *f++ = -1;
            *g++ = -1;
            *h++ = -1;
        }

        for (i = 0; i < 16; i++) {
            r24a->a = -1;
            r24b->a = -1;
            r16a->value[0] = -1;
            r16b->value[0] = -1;
            r24a->b = -1;
            r24b->b = -1;
            r16a->value[1] = -1;
            r16b->value[1] = -1;
            r24a->c = -1;
            r24b->c = -1;
            r16a->value[2] = -1;
            r16b->value[2] = -1;
            r24a->flag = 255;
            r24b->flag = 255;
            r8->a = -1;
            *b++ = -1;
            r16a->value[3] = -1;
            r16b->value[3] = -1;
            r24a->d = -1;
            r24b->d = -1;
            r8->b = -1;
            r16a++;
            r16b++;
            r24a++;
            r24b++;
            r8++;
        }
    }
    for (i = 0; i < 16; i++) {
        ((s32*)(base + 0x29F8))[i] = -1;
    }
    lbl_8064D6B0 = -1;
    lbl_8064D684 = 0;
    lbl_8064D680 = 0;
}

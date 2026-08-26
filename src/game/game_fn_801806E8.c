typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_801F5C74(void*);
extern void fn_8017CE74(void*, void*);
extern volatile u32 lbl_8064D230;
extern volatile u32 lbl_8064D234;
extern u8 lbl_80606334[];

typedef struct SourceSet {
    void* source[4];
} SourceSet;

void fn_801806E8(u8* object, void* target, SourceSet* sources)
{
    fn_801F5C74(object + 0x6C);
    fn_8017CE74(sources->source[0], *(void**)(object + 0x4C));
    fn_8017CE74(sources->source[1], *(void**)(object + 0x50));
    fn_8017CE74(sources->source[2], *(void**)(object + 0x58));
    fn_8017CE74(sources->source[3], *(void**)(object + 0x54));

    *(u32*)(object + 0x148) = 0;
    *(u32*)(object + 0x14C) = 0;
    *(u32*)(object + 0x34) = 0;
    *(u16*)(object + 0x22) = 1;
    fn_8017CE74(target, object);

    if (sources == (SourceSet*)lbl_80606334) {
        lbl_8064D230--;
        goto done;
    }
    lbl_8064D234--;
done:
    ;
}

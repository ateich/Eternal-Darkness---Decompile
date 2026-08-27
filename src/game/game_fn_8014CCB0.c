typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

#pragma options align=packed
typedef struct Work {
    u8 kind;
    u8 pad01[0x1C];
    int owner;
    u8 pad21[0x77];
} Work;
#pragma options align=reset

extern Vec3 lbl_8023A738;
extern float lbl_8064CF04;
extern float lbl_806504F8;
extern float lbl_806504FC;
extern float lbl_80650500;
extern void* lbl_8064C4E0;
extern int lbl_802FC5BC[];

extern void fn_8012B690(void*, Vec3*, Vec3*);
extern unsigned int fn_800FBFB0(void);
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern void fn_8017EA58(Work*);
extern int fn_801E79FC(void*, int);
extern void* fn_80148008(Vec3*, u16*, Work*, void (*)(void));
extern void *fn_80156938();
extern void fn_8017FF1C(void*, int);
extern void fn_80183DD4(Work*);
extern void fn_8017EAA8(void);
extern void fn_80183EE0(void);

/*
 * Honest NonMatching reconstruction of the two effect-spawn paths. The
 * retail function overlays several packed work records in one 0xE0-byte
 * frame; this spelling keeps their behavior and lifetimes explicit.
 */
void fn_8014CCB0(void* context, int* source, unsigned int packed)
{
    u16 range[2];
    Vec3 second_position;
    Vec3 first_position;
    Vec3 position;
    Vec3 basis = lbl_8023A738;
    Work work;
    unsigned int kind;
    void* object;

    if (!(lbl_8064CF04 >= lbl_806504F8)) {
        fn_8012B690(context, &basis, &position);
        range[0] = 8 - (fn_800FBFB0() & 0xF);
        range[1] = 8 - (fn_800FBFB0() & 0xF);
        fn_8017EA58(&work);
        work.owner = *source;
        if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0)
            work.owner = lbl_802FC5BC[9];

        if (lbl_8064CF04 >= lbl_806504FC) {
            kind = (packed >> 2) & 0x3F;
            if ((int)kind <= 0)
                kind = packed & 0xFF;
        } else if (lbl_8064CF04 >= lbl_80650500) {
            kind = (packed >> 1) & 0x7F;
            if ((int)kind <= 0)
                kind = packed & 0xFF;
        } else {
            kind = packed & 0xFF;
        }

        work.kind = kind;
        first_position = position;
        object = fn_80148008(&first_position, range, &work, fn_8017EAA8);
        if (object != 0)
            fn_8017FF1C(fn_80156938(object), 4);
        fn_80183DD4(&work);

        work.owner = *source;
        if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0)
            work.owner = lbl_802FC5BC[9];
        work.kind = 1;
        second_position = position;
        object = fn_80148008(&second_position, range, &work, fn_80183EE0);
        if (object != 0)
            fn_8017FF1C(fn_80156938(object), 4);
    }
}

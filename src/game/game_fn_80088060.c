typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Owner { u8 pad[0x160]; u16 count; } Owner;
typedef struct Work {
    u8 pad38[0x38]; int object_id; u8 pad3C[0xC4 - 0x3C]; Owner* owner;
} Work;

extern void *fn_80201814();
extern int lbl_8064C824;
extern void fn_801A6E04(int);
extern void* fn_8004918C(void);
extern int fn_801A7778(void);
extern int fn_801A7780(void*);
extern int fn_801A76B8(void*);
extern int fn_801578AC(void);
extern unsigned int fn_800FBFB0(void);
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern void *fn_8006ED3C();
extern void fn_80088D04(void);
extern void* lbl_8064C8C4;
extern u8 lbl_8064C91C;
extern u8 lbl_8064C91D;
extern u16 lbl_8031D3B8[];

int fn_80088060(Work* work)
{
    u16* table = lbl_8031D3B8;
    void* object;
    int kind;
    int i;
    int index;

    fn_80201814(work->object_id);
    fn_801A6E04(lbl_8064C824);
    object = fn_8004918C();
    fn_801A7778();
    kind = fn_801578AC();
    lbl_8064C91C = 1;
    if (fn_801A7780(object) & 8) {
        if (kind == 0x40) {
            lbl_8064C91C = 5;
            if ((u8)fn_801A76B8(object) > 1)
                lbl_8064C91C = 10;
        } else {
            lbl_8064C91C = 5;
        }
    } else {
        if ((kind == 2 || kind == 0x80) && work->owner->count > 1)
            lbl_8064C91C = 2;
        else if ((kind == 4 || kind == 8) && work->owner->count > 2)
            lbl_8064C91C = 3;
    }
    if (work->owner->count != 0) {
        for (i = 1; i < lbl_8064C91C; i++) {
            table[i] = fn_800FBFB0() % 0x200;
            table[i + 10] = fn_800FBFB0() % 0x160;
            table[i + 20] = 0x80 - (fn_800FBFB0() & 0x3F);
        }
    }
    fn_8006ED3C(work, 7, &index);
    lbl_8064C8C4 = fn_80088D04;
    if (lbl_8064C91D & 1) {
        ((u8*)work)[index * 0x2C + 0x6A] = 1;
        ((u8*)work)[index * 0x2C + 0x6B] = 4;
    } else {
        ((u8*)work)[index * 0x2C + 0x6A] = 2;
        ((u8*)work)[index * 0x2C + 0x6B] = 2;
    }
    return 1;
}

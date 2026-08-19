typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Color { u8 r, g, b, a; } Color;
typedef struct EffectDesc { u8 bytes[0x40]; } EffectDesc;

extern int lbl_8064D18C;
extern Color lbl_80651C80;
extern Color lbl_806505F0;
extern u32 lbl_806505F4;
extern u16 lbl_806505F8;
extern float lbl_806505FC;
extern void fn_80149E28(void*);
extern void fn_8011F114();
extern void fn_8012DBE8(void*, int, Color*);
extern void fn_8012C62C(void*, int, Color*, Color*, Color*, int);
extern void fn_801A19BC(EffectDesc*);
extern int fn_800FBFB0(void);
extern void fn_8011F598(void*, int, int, int, void*, int);
extern void* fn_80148008(void*, void*, EffectDesc*, void*);
extern void fn_801A1BD0(void);
extern void *fn_80156938();
extern void fn_80180374(void*, int);
extern void fn_80180384(void*, int);

void fn_801547CC(void* work)
{
    void* object = *(void**)((char*)work + 8);
    u8 index;
    Color source, first, second, third;
    u8 position[0x30];
    u8 result[0x28];
    u8 key[6];
    EffectDesc desc;
    void* effect;

    if (*(int*)((char*)work + 0x1324) != lbl_8064D18C) {
        fn_80149E28(work);
        return;
    }
    if (*(u8*)((char*)work + 0xF) == 0) {
        index = *(u8*)((char*)work + 0xD);
        fn_8011F114(position, object);
        fn_8012DBE8(object, index, &source);
        first = source;
        second = lbl_80651C80;
        third = lbl_806505F0;
        fn_8012C62C(object, index, &first, &second, &third, 6);
        *(u8*)((char*)work + 0xF) = 1;
        *(u8*)((char*)work + 0xC) = 0;
    }
    if (*(u8*)((char*)work + 0xC) == 0) {
        *(u32*)key = lbl_806505F4;
        *(u16*)(key + 4) = lbl_806505F8;
        index = *(u8*)((char*)work + 0xD);
        fn_801A19BC(&desc);
        *(u16*)(desc.bytes + 6) = 80;
        *(float*)(desc.bytes + 20) = lbl_806505FC;
        desc.bytes[25] = (fn_800FBFB0() + 45) & 31;
        fn_8011F598(object, *(u8*)((char*)work + 0xE), -1, index,
                     result, 1);
        effect = fn_80148008(result + 8, key, &desc, fn_801A1BD0);
        if (effect != 0 && (effect = fn_80156938(effect)) != 0) {
            fn_80180374(effect, 255);
            fn_80180384(effect, 20);
        }
        *(u8*)((char*)work + 0xE) += 1;
        *(u8*)((char*)work + 0xC) = (fn_800FBFB0() + 1) & 7;
    } else {
        *(u8*)((char*)work + 0xC) -= 1;
    }
    if (*(u8*)((char*)work + 0xE) == 14)
        fn_80149E28(work);
}

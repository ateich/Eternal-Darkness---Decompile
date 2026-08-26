typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

extern int lbl_8064D18C;
extern Color lbl_80651C78;
extern Color lbl_80651C7C;
extern Color lbl_806505E0;
extern u32 lbl_806505E4;
extern u32 lbl_806505E8;
extern u32 lbl_806505EC;

extern void fn_80149E28(void* work);
extern unsigned short fn_8012DBE8(void* object, int index, Color* color);
extern void* fn_8012C62C(void* object, int index, Color* first, Color* second,
                        Color* third, int mode);
extern void fn_8012C774(void* object, u32* first, u32* second, u32* third,
                        int mode);
extern void fn_801A0450(void);
extern void fn_80154754(void* object, int count);

void fn_801545E4(void* work)
{
    int index;
    Color source;
    Color first;
    Color fourth;
    Color third;
    Color second;
    Color fifth;
    u32 c;
    u32 b;
    u32 a;

    if (*(int*)((char*)work + 0x1324) != lbl_8064D18C) {
        fn_80149E28(work);
        for (index = 8; index <= 14; index++) {
            fn_8012DBE8(*(void**)((char*)work + 8), index, &source);
            fifth = lbl_80651C7C;
            fourth = lbl_80651C78;
            fifth.r = source.r;
            fifth.g = source.g;
            fifth.b = source.b;
            fourth.r = source.r;
            fourth.g = source.g;
            fourth.b = source.b;
            second = fifth;
            third = lbl_806505E0;
            first = fourth;
            fn_8012C62C(*(void**)((char*)work + 8), index, &first, &third,
                        &second, 6);
        }
    } else {
        if (*(u8*)((char*)work + 0xF) == 0) {
            a = lbl_806505EC;
            b = lbl_806505E8;
            c = lbl_806505E4;
            fn_8012C774(*(void**)((char*)work + 8), &c, &b, &a, 6);
            fn_801A0450();
            *(u8*)((char*)work + 0xF) = 1;
        }
        if (*(u8*)((char*)work + 0xE) >= 8) {
            if (*(u16*)((char*)work + 0x132C) % 35 == 0) {
                fn_80154754(*(void**)((char*)work + 8),
                            *(u8*)((char*)work + 0xE));
                *(u8*)((char*)work + 0xE) -= 1;
            }
        } else {
            fn_80149E28(work);
        }
    }
}

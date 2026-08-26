typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_8017E1B0(void*, void*);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern void fn_8018EC8C(void);
extern void fn_8018EACC(void);

int fn_80182290(u8* object)
{
    int frame = *(u16*)(object + 0xA);

    if (frame < object[0x8C]) {
        int count;
        u8* item;
        int i;

        item = *(u8**)(object + 0x4C);
        i = 0;
        count = object[1];

        for (; i < count; item += 0x38, i++) {
            fn_8017E1B0(item + 0xA, item + 0x10);
        }
    } else {
        if ((u32)frame >= *(u16*)(object + 0xC)) {
            fn_8018E230(object + 0x60, object + 0x5F, 1,
                        object[2], object[4], 0);
        }

        if (*(int*)(object + 0x90) != 0) {
            *(void (**)(void))(object + 0x14C) = fn_8018EC8C;
        } else {
            *(void (**)(void))(object + 0x14C) = fn_8018EACC;
        }
    }

    (*(u16*)(object + 0xA))++;
    return 0;
}

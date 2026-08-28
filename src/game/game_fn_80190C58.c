typedef unsigned char u8;
typedef unsigned short u16;

extern u8 fn_8018E26C(void*, void*);
extern void fn_8018E230(void*, void*, int, int, int, int);
extern int fn_80190D0C(void*);
extern int fn_8019B8B4(void*);

int fn_80190C58(u8* data)
{
    u8* object = *(u8**)(data + 0x4C);

    if (!fn_8018E26C(object, object + 0x2B)) {
        u16 duration = *(u16*)(data + 0xC);

        if (duration != 0) {
            if (*(u16*)(data + 0xA) < duration) {
                *(void**)(data + 0x14C) = fn_80190D0C;
            } else {
                fn_8018E230(object, object + 0x2B, 1, data[2], data[4], 0);
                *(void**)(data + 0x14C) = fn_8019B8B4;
            }
        } else {
            *(void**)(data + 0x14C) = 0;
        }
    }
    (*(u16*)(data + 0xA))++;
    return 0;
}

typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8018E230(u8*, u8*, int, u8, u8, int);
extern u8 fn_8018E26C(u8*, u8*);

int fn_801842A8(u8* self)
{
    u8* target = *(u8**)(self + 0x4C);

    if (target[0x21] > self[0x8D]) {
        if ((*(u16*)(self + 0xA) & 3) == 0) {
            target[0x21] += self[0x8C];
        }
    } else {
        target[0x21] += self[0x8C];
        if (target[0x21] == self[0x8D]) {
            self[0x8C] = 1;
        }
    }

    if (self[0x60] == 0) {
        fn_8018E230(self + 0x60, self + 0x5F, 1, self[2], self[4], 0);
    } else if (!fn_8018E26C(self + 0x60, self + 0x5F)) {
        *(u16*)(self + 0x22) = 8;
    }

    (*(u16*)(self + 0xA))++;
    return 0;
}

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* memcpy(void*, const void*, unsigned long);
extern int fn_80180430(void*, u8);
extern void fn_80180518(void*, u8, int);
extern int fn_80180454(void*);
extern int fn_8018E26C(void*, void*);
extern int fn_8017DD28(void*, void*, void*);
extern void fn_8018E230(void*, void*, int, int, int, int);
extern void fn_8018F014(void*, u16);
extern void fn_80180554(void*, void*, void*, void*, int, int);
extern void* fn_80185108(void*);
extern void fn_801851A0(void*, void*);

int fn_801A48EC(u8* object)
{
    u8* state = object + 0x8c;
    u8* channel = *(u8**)(object + 0x4c);
    int i = 0;
    u8 count = object[1];

    for (; i < count; i++) {
        if (fn_80180430(object + 0x24, (u8)i)) {
            if (channel[0] != 0) {
                fn_8018E26C(channel, channel + 0x2b);
                if (channel[0x2b] == 0)
                    fn_80180518(object + 0x24, (u8)i, 0);
            } else if (fn_8017DD28(channel + 0xa, object + 0x10,
                                  channel + 0x10)) {
                if (*(int*)(state + 4) == 0 ||
                    (*(int*)state == 0 &&
                     *(u16*)(object + 0xa) >= *(u16*)(object + 0xc))) {
                    fn_8018E230(channel, channel + 0x2b, 1,
                                channel[0x2b], -17, 0);
                } else {
                    u16 position[3];
                    void* value;
                    memcpy(position, state + 0x10, 6);
                    fn_8018F014(position, *(u16*)(state + 0xe));
                    fn_80180554(channel, position, object + 0x16,
                                object + 0x1c, 0, 0);
                    fn_8018E230(channel, channel + 0x2b, 1, 0,
                                object[4], 0xcc);
                    value = *(void**)(state + 0x1c + i * 4);
                    fn_80185108(value);
                    fn_801851A0(value, position);
                }
            }
        }
        channel += 0x38;
    }
    if (fn_80180454(object + 0x24) != 0 ||
        (*(int*)state == 0 &&
         *(u16*)(object + 0xa) >= *(u16*)(object + 0xc) + 100)) {
        *(u16*)(object + 0x22) = 8;
    }
    (*(u16*)(object + 0xa))++;
    return 0;
}

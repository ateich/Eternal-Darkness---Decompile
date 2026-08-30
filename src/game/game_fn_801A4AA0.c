typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct QueryResult {
    u32 header[2];
    float position[3];
    float direction[3];
    float value;
} QueryResult;

extern void* fn_80201890(u32);
extern int fn_80180430(void*, u8);
extern void fn_80180518(void*, u8, int);
extern int fn_80180454(void*);
extern int fn_8018E26C(void*, void*);
extern int fn_8017DD28(void*, void*, void*);
extern void fn_8018E230(void*, void*, int, int, int, int);
extern int fn_8011F598(void*, int, int, int, void*, int);
extern void fn_801A4874(float*, s16*);
extern void fn_80180554(void*, void*, void*, void*, int, int);
extern void* fn_80185108(void*);
extern void fn_801851A0(void*, void*);

int fn_801A4AA0(u8* object)
{
    u8* state = object + 0x8c;
    void* source = fn_80201890(*(u32*)(object + 0xa4));
    u8* channel = *(u8**)(object + 0x4c);
    u8 count = object[1];
    int i;

    for (i = 0; i < count; i++) {
        if (fn_80180430(object + 0x24, (u8)i)) {
            if (channel[0] != 0) {
                fn_8018E26C(channel, channel + 0x2b);
                if (channel[0x2b] == 0)
                    fn_80180518(object + 0x24, (u8)i, 0);
            } else if (fn_8017DD28(channel + 0xa, object + 0x10,
                                  channel + 0x10)) {
                if (source == 0 || *(int*)(state + 4) == 0 ||
                    (*(int*)state == 0 &&
                     *(u16*)(object + 0xa) >= *(u16*)(object + 0xc))) {
                    fn_8018E230(channel, channel + 0x2b, 1,
                                channel[0x2b], -17, 0);
                } else {
                    QueryResult result;
                    s16 coord[3];
                    int previous = -1;
                    int j;
                    void* value;
                    for (j = 0; j <= i; j++) {
                        previous = fn_8011F598(source, 0x10, 0, previous,
                                              &result, 1);
                        if (previous == -1)
                            previous = fn_8011F598(source, 0x10, 0, -1,
                                                  &result, 1);
                    }
                    fn_801A4874(result.position + 0, coord + 0);
                    fn_801A4874(result.position + 1, coord + 1);
                    fn_801A4874(result.position + 2, coord + 2);
                    fn_80180554(channel, coord, object + 0x16,
                                object + 0x1c, 0, 0);
                    fn_8018E230(channel, channel + 0x2b, 1, 0,
                                object[4], 0xcc);
                    value = *(void**)(state + 0x1c + i * 4);
                    fn_80185108(value);
                    fn_801851A0(value, coord);
                }
            }
        }
        channel += 0x38;
    }
    if (fn_80180454(object + 0x24) != 0 ||
        (*(int*)state == 0 &&
         *(u16*)(object + 0xa) >= *(u16*)(object + 0xc) + 100))
        *(u16*)(object + 0x22) = 8;
    (*(u16*)(object + 0xa))++;
    return 0;
}

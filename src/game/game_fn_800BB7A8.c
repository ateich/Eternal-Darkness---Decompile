typedef struct Message {
    unsigned int first;
    unsigned int second;
    float time;
    unsigned char padC[4];
    unsigned int fourth;
    unsigned int fifth;
    unsigned int sixth;
    unsigned char byte;
    unsigned char pad1D[3];
} Message;

typedef struct Source {
    unsigned char byte;
    unsigned char pad1[0xB];
    unsigned int first;
    unsigned int second;
    signed short value;
    unsigned char pad16[0xE];
    unsigned int fourth;
    unsigned int fifth;
    unsigned int sixth;
} Source;

typedef struct Owner {
    unsigned char pad[0x2C];
    Source *source;
} Owner;

extern void *memcpy(void *, const void *, unsigned int);
extern void *fn_80201B54(void *);
extern float fn_80200534(void *, int, int);
extern int fn_80117E58(void);
extern float fn_80200BDC(void);
extern Owner *fn_80201B8C(void *);
extern float lbl_8064F010;
extern double lbl_8064F020;

unsigned short fn_800BB7A8(void *output, void *object)
{
    Message result;
    float tick;
    float time;

    time = fn_80200534(fn_80201B54(object), -1, 0x39);
    tick = fn_80117E58();
    time += fn_80200BDC() - tick;
    if (time >= lbl_8064F010) {
        Source *source = fn_80201B8C(object)->source;
        result.first = source->first;
        result.second = source->second;
        *(signed short *)&result.padC[0] = source->value;
        result.fourth = source->fourth;
        result.fifth = source->fifth;
        result.sixth = source->sixth;
        result.byte = source->byte;
    }
    result.time = time;
    memcpy(output, &result, sizeof(result));
    return sizeof(result);
}

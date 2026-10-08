typedef unsigned char u8;
typedef signed short s16;

typedef struct Entry80201B3C Entry80201B3C;
typedef struct Object Object;

typedef union DataWord {
    int value;
    struct {
        u8 pad00[3];
        u8 index;
    } bytes;
} DataWord;

typedef struct Data {
    DataWord first;
    u8 pad04[0xEC];
    s16 step;
    s16 flags;
    u8 state;
} Data;

typedef struct RuntimeState {
    u8 pad00[0x20];
    Data *data;
} RuntimeState;

extern int lbl_8064D738;

extern int fn_80047178(void);
extern int fn_8012FA54(Object *object, int index);
extern Entry80201B3C *fn_80201B3C(void);
extern void *fn_80201B8C(unsigned char *object);
extern void *fn_80201BC8(void *object);

int fn_800CE7D0(void *object)
{
    u8 *base;
    int buffer;
    int *output;
    Data *data;
    Object *other;

    data = ((RuntimeState *)fn_80201B8C((unsigned char *)object))->data;

    other = fn_80201B3C() != 0
                ? (Object *)fn_80201BC8(fn_80201B3C())
                : (Object *)0;

    if ((fn_80047178() != 0 && fn_8012FA54(other, 15) != 0) ||
        (data->state & 0x10) == 0) {
        buffer = lbl_8064D738;
        base = (u8 *)data + 8;
        data->first.bytes.index += data->step;
        if (data->first.bytes.index == 0) {
            data->flags |= 2;
            data->step = -data->step;
        }

        output = (int *)(base + buffer * 16);
        output[12] = data->first.value;
        output[13] = data->first.value;
        output[14] = data->first.value;
        output[15] = data->first.value;
    }

    return data->flags;
}

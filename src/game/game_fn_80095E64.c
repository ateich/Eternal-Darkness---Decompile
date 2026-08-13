typedef unsigned char u8;

typedef struct Runtime80095E64 {
    u8 pad00[0x68];
    int* values;
} Runtime80095E64;

extern Runtime80095E64* fn_80201B8C(void*);
extern void* fn_80201BC8(void*);
extern int fn_80128EAC(void*);

int fn_80095E64(register void* object, register unsigned int mode)
{
    register int* values;
    register int result = 0;

    values = fn_80201B8C(object)->values;
    switch (mode) {
    case 1:
    case 7:
        result = 1;
        break;
    case 2:
        result = values[0];
        break;
    case 5:
        result = fn_80128EAC(fn_80201BC8(object));
        switch (result) {
        case 46:
        case 47:
        case 157:
            result = fn_80095E64(object, 3);
            break;
        default:
            result = values[1];
            break;
        }
        break;
    case 3: {
        int empty = 0;
        if (values[4] == 0 && values[5] == 0) {
            empty = 1;
        }
        result = !empty;
        break;
    }
    case 6: {
        int empty = 0;
        if (values[8] == 0 && values[9] == 0) {
            empty = 1;
        }
        result = !empty;
        break;
    }
    case 4: {
        int empty = 0;
        if (values[2] == 0 && values[3] == 0) {
            empty = 1;
        }
        result = !empty;
        break;
    }
    }
    return result;
}

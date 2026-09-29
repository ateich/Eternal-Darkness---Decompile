typedef unsigned char u8;

typedef struct Runtime80095E64 {
    u8 pad00[0x68];
    int* values;
} Runtime80095E64;

extern void *fn_80201B8C();
extern void *fn_80201BC8();
extern int fn_80128EAC(void*);

int fn_80095E64(register void* object, register unsigned int mode)
{
    register int* values;
    register int result = 0;

    values = ((Runtime80095E64*)fn_80201B8C(object))->values;
    switch (mode) {
    case 7:
        result = 1;
        break;
    case 1:
        result = values[0];
        break;
    case 2:
        switch (fn_80128EAC(fn_80201BC8(object))) {
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
        if (values[4] != 0) goto case3_done;
        if (values[5] != 0) goto case3_done;
        empty = 1;
case3_done:
        result = empty == 0;
        break;
    }
    case 5: {
        int empty = 0;
        if (values[8] != 0) goto case5_done;
        if (values[9] != 0) goto case5_done;
        empty = 1;
case5_done:
        result = empty == 0;
        break;
    }
    case 6: {
        int empty = 0;
        if (values[6] != 0) goto case6_done;
        if (values[7] != 0) goto case6_done;
        empty = 1;
case6_done:
        result = empty == 0;
        break;
    }
    case 4: {
        int empty = 0;
        if (values[2] != 0) goto case4_done;
        if (values[3] != 0) goto case4_done;
        empty = 1;
case4_done:
        result = empty == 0;
        break;
    }
    }
    return result;
}

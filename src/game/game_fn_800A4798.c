typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Runtime800A4798 {
    u8 pad0[0x94];
    int table_index;
} Runtime800A4798;

typedef struct Range800A4798 {
    int low;
    int high;
    int unused;
} Range800A4798;

extern int fn_801A74C0(void*);
extern Runtime800A4798* fn_80201B8C();
extern void fn_80038464(void*, int, short*);
extern u8 fn_801A7768(void*);
extern int fn_801A7760(void*);
extern void fn_801A7518(void*, int);
extern Range800A4798 lbl_8023BA64[];
extern double lbl_8064EE78;
extern float lbl_8064EE90;
extern float lbl_8064EED4;
extern float lbl_8064EED8;
extern float lbl_8064EEDC;

void fn_800A4798(void* object, void* value)
{
    int result;
    int enabled = (fn_801A74C0(value) >> 16) & 1;
    Runtime800A4798* runtime = fn_80201B8C(object);

    if (enabled) {
        short raw;
        float scaled;
        int current;
        fn_80038464(object, 0, &raw);
        scaled = (float)raw / lbl_8064EED4;
        switch (fn_801A7768(value)) {
        case 2:
            result = (int)(lbl_8064EE90 + scaled / lbl_8064EED4);
            break;
        case 3:
            result = (int)(scaled * lbl_8064EED8 + lbl_8064EE90);
            break;
        case 4:
            result = (int)(lbl_8064EE90 + scaled);
            break;
        }

        current = fn_801A7760(value);
        if (current == lbl_8023BA64[runtime->table_index].high) {
            result = (int)((float)(short)result * lbl_8064EEDC);
            result++;
        } else if (current == lbl_8023BA64[runtime->table_index].low) {
            result = (int)((float)(short)result * lbl_8064EED8);
            result++;
        }
    }
    fn_801A7518(value, result);
}

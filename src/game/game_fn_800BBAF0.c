typedef struct Message { unsigned int value; float time; } Message;
typedef struct Source { unsigned char pad[4]; unsigned int value; } Source;
typedef struct Owner { unsigned char pad[0x34]; Source *source; } Owner;
extern void *memcpy(void *, const void *, unsigned int);
extern int fn_80201B54(); extern float fn_80200534(void *, int, int);
extern int fn_80117E58(void); extern float fn_80200BDC(void); extern void *fn_80201B8C();
extern float lbl_8064F010; extern double lbl_8064F020;
unsigned short fn_800BBAF0(void *output, void *object)
{
    Message result; float tick; float time;
    time = fn_80200534(((void *)fn_80201B54(object)), -1, 0x39);
    tick = fn_80117E58();
    time += fn_80200BDC() - tick;
    if (time >= lbl_8064F010) result.value = ((Owner *)fn_80201B8C(object))->source->value;
    result.time = time; memcpy(output, &result, sizeof(result)); return sizeof(result);
}

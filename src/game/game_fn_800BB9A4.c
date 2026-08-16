typedef struct Message { unsigned int first; unsigned int second; float time; unsigned char byte; unsigned char pad[3]; } Message;
typedef struct Source { unsigned char pad[4]; unsigned int first; unsigned int second; unsigned char padC[6]; unsigned char byte; } Source;
typedef struct Owner { unsigned char pad[0x30]; Source *source; } Owner;
extern void *memcpy(void *, const void *, unsigned int);
extern int fn_80201B54(); extern float fn_80200534(void *, int, int);
extern int fn_80117E58(void); extern float fn_80200BDC(void); extern void *fn_80201B8C();
extern float lbl_8064F010; extern double lbl_8064F020;
unsigned short fn_800BB9A4(void *output, void *object)
{
    Message result; float tick; float time;
    time = fn_80200534(((void *)fn_80201B54(object)), -1, 0x39);
    tick = fn_80117E58();
    time += fn_80200BDC() - tick;
    if (time > lbl_8064F010) { Source *source = ((Owner *)fn_80201B8C(object))->source; result.first = source->first; result.second = source->second; result.byte = source->byte; }
    result.time = time; memcpy(output, &result, sizeof(result)); return sizeof(result);
}

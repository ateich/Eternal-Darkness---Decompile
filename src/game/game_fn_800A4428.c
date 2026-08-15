typedef signed short s16;

extern float lbl_8064EE70;

extern void* fn_80201B54();
extern void* fn_80201B8C();
extern void fn_80038308(void*, int, s16*);
extern void fn_80038464(void*, int, s16*);

int fn_800A4428(void* object, int value)
{
    s16 limit;
    s16 unused;

    fn_80201B54(object);
    fn_80201B8C(object);
    fn_80038308(object, 0, &unused);
    fn_80038464(object, 0, &limit);
    return (int)((lbl_8064EE70 * (float)value) / (float)limit);
}

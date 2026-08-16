extern void* lbl_80331720[6];
extern int fn_801E8D24(void*);
extern void fn_8010C220(int, int, float);
extern double lbl_8064FE78;
extern float lbl_8064FEE4;

void fn_8010F184(short value, int* source)
{
    int offset = fn_801E8D24(lbl_80331720[1]) * 2;
    int index = fn_801E8D24(lbl_80331720[0]);
    index += offset;
    fn_8010C220(index, *source, (float)value / lbl_8064FEE4);
}

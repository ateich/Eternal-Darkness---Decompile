extern float lbl_80650F60;
extern float lbl_80650F64;
extern float lbl_80650F68;

extern float fn_800F5C54(float);
extern float fn_80102408(float, float);

float fn_801C2AAC(int value)
{
    return fn_800F5C54(lbl_80650F60 * fn_80102408(lbl_80650F64, lbl_80650F68 * value));
}

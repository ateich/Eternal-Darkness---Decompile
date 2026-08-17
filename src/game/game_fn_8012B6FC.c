typedef float Matrix8012B6FC[12];

extern void fn_802114E0(Matrix8012B6FC, const void*);
extern void fn_80211710(Matrix8012B6FC, const void*, const void*);

void fn_8012B6FC(void* owner, const void* value, const void* output)
{
    Matrix8012B6FC matrix;

    fn_802114E0(matrix, (char*)owner + 0x2C);
    fn_80211710(matrix, value, output);
}

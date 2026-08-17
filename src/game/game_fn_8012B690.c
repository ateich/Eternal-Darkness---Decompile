typedef float Matrix8012B690[12];

extern void fn_802114E0(Matrix8012B690, const void*);
extern void fn_80211710(Matrix8012B690, const void*, const void*);
extern void fn_80211A48(const void*, const void*, void*);

void fn_8012B690(void* owner, const void* value, void* output)
{
    Matrix8012B690 matrix;

    fn_802114E0(matrix, (char*)owner + 0x2C);
    fn_80211710(matrix, value, output);
    fn_80211A48(owner, output, output);
}

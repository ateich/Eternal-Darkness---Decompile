typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

extern float fn_80211AF0(const Vec4*);

float fn_8017A65C(const Vec4* value)
{
    float length = fn_80211AF0(value);
    return length + value->w * value->w;
}

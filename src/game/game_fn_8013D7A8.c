typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Query { unsigned char pad[0x18]; Vec3 vector; float limit; } Query;

extern int fn_8013DB8C(const void*, const void*, const Query*,
                       const Vec3*, const void*, float*);
extern float lbl_80650350;

int fn_8013D7A8(Query* query, const void* first, const void* second,
                const void* third)
{
    float value;
    if (fn_8013DB8C(first, second, query, &query->vector, third, &value) &&
        value >= lbl_80650350 && value <= query->limit) {
        return 1;
    }
    return 0;
}

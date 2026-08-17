typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Query { unsigned char pad[0x18]; Vec3 vector; float limit; } Query;

extern int fn_8013DE44(const void*, const Vec3*, const void*, float*, int);

int fn_8013D828(Query* query, const void* value)
{
    float amount;
    if (fn_8013DE44(query, &query->vector, value, &amount, 1) &&
        amount <= query->limit) {
        return 1;
    }
    return 0;
}

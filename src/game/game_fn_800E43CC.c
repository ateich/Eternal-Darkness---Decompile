typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct QueryResult {
    int unused[2];
    Vec3 position;
    int trailing[8];
} QueryResult;

extern void fn_8011F6A4(void *, int, int, int, QueryResult *, int);
extern void fn_80152838(Vec3 *, Vec3 *, int);
extern void fn_801AC9F4(int, int, Vec3 *, int);
extern float lbl_8064F6A8;

void fn_800E43CC(void *resource)
{
    QueryResult result;
    Vec3 adjusted;

    fn_8011F6A4(resource, 9, 1, -1, &result, 1);
    adjusted = result.position;
    adjusted.z += lbl_8064F6A8;
    fn_80152838(&result.position, &adjusted, 4);
    fn_801AC9F4(66, 100, &result.position, 2);
}

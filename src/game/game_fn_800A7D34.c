typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct QueryResult {
    int pad0[2];
    Vec3 position;
    int pad14[7];
} QueryResult;

extern void* lbl_8064C988;
extern const float lbl_8064EF1C;
extern void *fn_80201814();
extern void *fn_80201BC8();
extern int fn_8011F598(void*, int, int, int, QueryResult*, int);

void fn_800A7D34(Vec3* first_out, Vec3* second_out, Vec3* center_out)
{
    QueryResult query;
    Vec3 first;
    Vec3 second;
    Vec3 sum;
    void* object = fn_80201814(lbl_8064C988);
    void* actor = fn_80201BC8(object);

    if (fn_8011F598(actor, 2, -1, -1, &query, 1) != -1) {
        first = query.position;
    }
    if (fn_8011F598(actor, 3, -1, -1, &query, 1) != -1) {
        second = query.position;
    }
    if (first_out != 0) {
        *first_out = first;
    }
    if (second_out != 0) {
        *second_out = second;
    }
    if (center_out != 0) {
        sum.x = first.x + second.x;
        sum.y = first.y + second.y;
        sum.z = first.z + second.z;
        center_out->x = sum.x * lbl_8064EF1C;
        center_out->y = sum.y * lbl_8064EF1C;
        center_out->z = sum.z * lbl_8064EF1C;
    }
}

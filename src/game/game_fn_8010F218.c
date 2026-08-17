typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct ScreenPosition {
    int x, y, z;
} ScreenPosition;

typedef struct Entry {
    int unused;
    void* object;
    unsigned char rest[36];
} Entry;

extern void* lbl_80331720[6];
extern Entry lbl_80330E88[];
extern int fn_801E8D24(void*);
extern void fn_8011F114();
extern void fn_8012CEA4(void*, int, Vec4*);
extern void fn_801F6B6C(Vec3*, ScreenPosition*, int, int);

void fn_8010F218(void)
{
    Vec3 position;
    ScreenPosition screen;
    Vec4 direction;
    int offset = fn_801E8D24(lbl_80331720[1]) * 2;
    int index = fn_801E8D24(lbl_80331720[0]);
    Entry* entry = &lbl_80330E88[index + offset];

    fn_8011F114(&position, entry->object);
    fn_8012CEA4(entry->object, 15, &direction);
    fn_801F6B6C(&position, &screen, 0, 0);
}

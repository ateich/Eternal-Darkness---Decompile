typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Contact {
    Vec3 start;
    Vec3 end;
    float radius;
    unsigned char pad1C[12];
    float height;
} Contact;
typedef struct Matrix34 { float m[3][4]; } Matrix34;

extern int lbl_8064B7E8;
extern int lbl_8064B7EC;
extern unsigned int fn_8011FAEC(void*);
extern Matrix34* fn_8011F6F8(void*);
extern Matrix34* fn_8011F6F0(void*);
extern void fn_8013F3C0(Matrix34*, const Vec3*, const Vec3*);
extern int fn_80137350(void*, Matrix34*, void*, void*, void*, void*);
extern int fn_8013A3C8(void*, Contact*, void*, void**);

/* Collision resolution. The matrix/contact setup and both broad-phase queries
 * are recovered; the remaining response-selection loop is still being typed. */
void fn_8013A538(void* object, void* value, Contact* contact, int mode,
                 void* output, void* flags)
{
    Contact working = *contact;
    Matrix34 matrix;
    unsigned char query[56];
    unsigned char best[24];
    void* hit = 0;
    int primary = 0;
    int secondary = 0;

    if ((fn_8011FAEC(object) & 2) == 0 && lbl_8064B7E8 != 0) {
        fn_8013F3C0(&matrix, &working.start, &working.end);
        primary = fn_80137350(object, &matrix, value, query, flags, best);
    }
    if (lbl_8064B7EC != 0 && (fn_8011FAEC(object) & 0x40) != 0) {
        fn_8011F6F0(object);
        fn_8013F3C0(&matrix, &working.start, &working.end);
        secondary = fn_8013A3C8(object, &working, best, &hit);
    }

    if (mode != 0 && (primary != 0 || secondary != 0)) {
        *(int*)output = primary;
        *(int*)flags = secondary;
    }
}

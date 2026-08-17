typedef unsigned int u32;

extern void* lbl_805B4A20[6];
extern void* lbl_805B4A38[6];
extern float lbl_806504A8;

extern void* fn_8011F130(void*);
extern float fn_8011F6F8(void*);
extern unsigned int fn_80143C28(void*, void*, float, float*, float*, float*);

/* NonMatching: behavior- and size-exact slot query at 99.703705% (216/216
 * bytes). All body instructions and relocations match; retail reserves a
 * 0x50-byte frame while this MWCC reconstruction reserves 0x40 bytes. */
int fn_8014B7B0(void* object)
{
    int i;
    void* owner;
    float radius;

    owner = fn_8011F130(object);
    radius = lbl_806504A8 + fn_8011F6F8(object);

    for (i = 0; i < 6; i++) {
        if (lbl_805B4A20[i] != 0 && lbl_805B4A38[i] != 0) {
            float x;
            float y;
            float z;
            volatile unsigned char retail_frame_pad[16];
            if (fn_80143C28(owner, lbl_805B4A38[i], radius,
                            &x, &y, &z) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

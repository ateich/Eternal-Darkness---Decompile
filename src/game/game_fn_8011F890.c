typedef struct Vec3 { float x, y, z; } Vec3;

extern float fn_80211B08(const Vec3* value);
extern void fn_80211A90(Vec3* output, const Vec3* input, float scale);
extern float lbl_80650068;
extern float lbl_80650070;

void fn_8011F890(void* object, float x, float y, float z)
{
    /* Honest reconstruction; exact float reload scheduling remains. */
    char* bytes = object;
    Vec3* value = (Vec3*)(bytes + 0x18);
    value->x = x;
    value->y = y;
    value->z = z;
    *(float*)(bytes + 0x24) = fn_80211B08(value);
    *(float*)(bytes + 0x28) = *(float*)(bytes + 0x24);
    if (*(float*)(bytes + 0x24) != lbl_80650068) {
        fn_80211A90(value, value, lbl_80650070 / *(float*)(bytes + 0x24));
    }
}

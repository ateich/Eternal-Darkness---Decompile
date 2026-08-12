typedef struct Vec3Pad {
    float x;
    float y;
    float z;
    float pad;
} Vec3Pad;

/* Unit-X fallback vector copied by the neighboring game handler. */
const volatile Vec3Pad lbl_802391F8 = { 1.0f, 0.0f, 0.0f, 0.0f };

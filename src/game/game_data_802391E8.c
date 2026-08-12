typedef struct Vec3Pad {
    float x;
    float y;
    float z;
    float pad;
} Vec3Pad;

/* Zero fallback vector copied by the neighboring game handler. */
const volatile Vec3Pad lbl_802391E8 = { 0.0f, 0.0f, 0.0f, 0.0f };

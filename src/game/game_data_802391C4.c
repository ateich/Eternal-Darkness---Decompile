typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

/* Downward offset vector used by the neighboring game handler. */
const volatile Vec3 lbl_802391C4 = {0.0f, -15.0f, 0.0f};

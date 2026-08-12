typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct VectorConstants {
    Vec3 offset;
    Vec3 unitScale;
    Vec3 epsilon;
    Vec3 fineScale;
} VectorConstants;

/* Vector constants used by the neighboring game handlers. */
const volatile VectorConstants lbl_80239194 = {
    {0.0f, -15.0f, 0.0f},
    {1.0f, 1.0f, 1.0f},
    {-0.003f, -0.003f, -0.003f},
    {0.1f, 0.1f, 0.1f},
};

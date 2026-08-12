typedef struct TransformConstantTable {
    float values[105];
} TransformConstantTable;

/* Vector, basis, and transform constants used by the neighboring handlers. */
const volatile TransformConstantTable lbl_80239208 = {{
    0.0f, 0.0f, 1.0f, 0.5f,
    0.5f, 0.5f, 0.0f, -5000.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, -1.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, -1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 1.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
    0.0f, 0.491351992f, -0.142473996f, 0.859229028f,
    1.0f, 0.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, -0.215241f, -0.96894002f,
    -0.121789001f, 0.0f, 0.0f, -1.0f,
    -1.0f, 0.0f, 0.0f, -0.343741f,
    0.916069984f, -0.206536993f, 0.0f, 0.0f,
    -1.0f, 1.0f, 0.0f, 0.0f,
    0.35f, -1.0f, 1.0f, 1.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
    0.0f,
}};

/* Opaque white, red, blue, green, and magenta RGBA colors. */
const volatile unsigned int lbl_802393AC[5] = {
    0xFFFFFFFF,
    0xFF0000FF,
    0x0000FFFF,
    0x00FF00FF,
    0xFF00FFFF,
};

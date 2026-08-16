typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec800A397C {
    float x, y, z;
} Vec800A397C;

typedef struct Data800A397C {
    u8 pad0[0x16];
    u16 effect;
} Data800A397C;

typedef struct Object800A397C {
    u8 pad0[0x264];
    Data800A397C* data;
} Object800A397C;

extern float lbl_8064EEA8;
extern int lbl_8064D18C;
extern void *fn_8011F114();
extern void fn_801AAE68(float, int, int, int, Vec800A397C*, int, int, int,
                        u16, int);

/*
 * Behavior-complete, size-exact reconstruction. The remaining differences are
 * MWCC's scheduling of the Vec3 aggregate copy and volatile r8/r9 selection.
 * Objdiff: 56.62162%, 148/148 bytes, 4/4 relocations equal.
 */
void fn_800A397C(Object800A397C* object, void* unused, void* source)
{
    Vec800A397C temporary;
    Vec800A397C position;

    if (object->data->effect != 0) {
        fn_8011F114(&position, source);
        temporary = position;
        fn_801AAE68(lbl_8064EEA8, object->data->effect, 100, 33, &temporary,
                    2, 2, 0, (u16)lbl_8064D18C, 0);
    }
}

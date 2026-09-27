typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Color {
    u8 r, g, b, a;
} Color;

typedef struct Descriptor801A852C {
    s16 values[12];
    u32 flags;
    Color color;
} Descriptor801A852C;

extern const Descriptor801A852C lbl_8023B2B0;

extern int fn_801EDA7C(s16* values, int context, int flags, void* state);

void fn_801A852C(Color color, int index, int replacement, u32 flags)
{
    Descriptor801A852C descriptor = lbl_8023B2B0;

    if (index != -1) {
        descriptor.values[index] = replacement;
    }
    descriptor.flags = flags;
    descriptor.color = color;
    fn_801EDA7C(descriptor.values, 0, 0x2BF, 0);
}

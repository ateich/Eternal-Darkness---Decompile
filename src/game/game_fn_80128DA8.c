typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    u8 pad0[0x284];
    u32 value284;
    u32 value288;
    u32 value28C;
    u8 pad290[0x46];
    u16 value2D6;
} Owner;

void fn_80128DA8(Owner* source, Owner* destination)
{
    destination->value2D6 = source->value2D6;
    destination->value284 = source->value284;
    destination->value28C = source->value28C;
    destination->value288 = source->value288;
}

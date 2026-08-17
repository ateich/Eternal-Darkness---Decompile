typedef unsigned char u8;

typedef struct Runtime {
    u8 bytes[0x110];
} Runtime;

extern Runtime* fn_80128E30(void*);

void fn_80128DCC(void* sourceOwner, void* destinationOwner)
{
    Runtime* source = fn_80128E30(sourceOwner);
    Runtime* destination = fn_80128E30(destinationOwner);
    *destination = *source;
}

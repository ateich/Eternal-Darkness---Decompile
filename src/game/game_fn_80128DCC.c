typedef unsigned char u8;

typedef struct Runtime {
    u8 bytes[0x110];
} Runtime;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

void fn_80128DCC(void* sourceOwner, void* destinationOwner)
{
    Runtime* source = fn_80128E30(sourceOwner);
    Runtime* destination = fn_80128E30(destinationOwner);
    *destination = *source;
}

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct DBInterface {
    u32 present;
    u32 exception_mask;
    u32 exception_destination;
} DBInterface;

extern DBInterface* __DBInterface;

u32 __DBIsExceptionMarked(u8 exception)
{
    return __DBInterface->exception_mask & (1 << exception);
}

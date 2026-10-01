typedef unsigned int u32;

typedef struct DBInterface {
    u32 present;
    u32 exception_mask;
    u32 exception_destination;
} DBInterface;

extern void __DBExceptionDestination(void);

int DBVerbose;
DBInterface* __DBInterface;

void DBInit(void)
{
    __DBInterface = (DBInterface*)0x80000040;
    ((DBInterface*)0x80000040)->exception_destination = (u32)__DBExceptionDestination - 0x80000000;
    DBVerbose = 1;
}

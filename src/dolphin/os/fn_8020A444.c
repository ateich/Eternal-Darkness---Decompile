typedef unsigned char u8;
typedef void (*OSExceptionHandler)(u8, void*);

extern OSExceptionHandler* OSExceptionTable;

OSExceptionHandler __OSSetExceptionHandler(u8 exception, OSExceptionHandler handler)
{
    OSExceptionHandler oldHandler = OSExceptionTable[exception];
    OSExceptionTable[exception] = handler;
    return oldHandler;
}

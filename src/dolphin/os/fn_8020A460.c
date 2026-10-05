typedef unsigned char u8;
typedef void (*OSExceptionHandler)(u8, void*);

extern OSExceptionHandler* OSExceptionTable_8064D900;

OSExceptionHandler __OSGetExceptionHandler(u8 exception)
{
    return OSExceptionTable_8064D900[exception];
}

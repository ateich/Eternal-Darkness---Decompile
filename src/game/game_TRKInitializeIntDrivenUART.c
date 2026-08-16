typedef void (*TRKEXICallback)(int, void *);
typedef void (*DBCommInit)(void *, TRKEXICallback);

extern DBCommInit gDBCommTable[];
void TRKEXICallBack(int interrupt, void *context);

int TRKInitializeIntDrivenUART(int unused1, int unused2, int unused3,
                              void *context)
{
    gDBCommTable[0](context, TRKEXICallBack);
    return 0;
}

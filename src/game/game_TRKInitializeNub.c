typedef unsigned char u8;
typedef unsigned int u32;

extern int gTRKBigEndian;
extern u8 *gTRKInputPendingPtr;

extern void usr_put_initialize(void);
extern int TRKInitializeEventQueue(void);
extern int TRKInitializeMessageBuffers(void);
extern int TRKInitializeDispatcher(void);
extern int TRKInitializeIntDrivenUART(u32, int, int, u8 **);
extern void TRKTargetSetInputPendingPtr(u8 *);
extern int TRKInitializeSerialHandler(void);
extern int TRKInitializeTarget(void);

int TRKInitializeNub(void)
{
    u8 endian[4];
    register int err = 0;
    int uart_err;
    register int one = 1;

    endian[0] = 0x12;
    endian[1] = 0x34;
    endian[2] = 0x56;
    endian[3] = 0x78;
    gTRKBigEndian = one;

    if (*(u32 *)endian == 0x12345678)
        gTRKBigEndian = one;
    else if (*(u32 *)endian == 0x78563412)
        gTRKBigEndian = err;
    else
        err = one;

    if (err == 0)
        usr_put_initialize();
    if (err == 0)
        err = TRKInitializeEventQueue();
    if (err == 0)
        err = TRKInitializeMessageBuffers();
    if (err == 0)
        err = TRKInitializeDispatcher();
    if (err == 0) {
        uart_err = TRKInitializeIntDrivenUART(0xE100, 1, 0,
                                              &gTRKInputPendingPtr);
        TRKTargetSetInputPendingPtr(gTRKInputPendingPtr);
        if (uart_err != 0)
            err = uart_err;
    }
    if (err == 0)
        err = TRKInitializeSerialHandler();
    if (err == 0)
        err = TRKInitializeTarget();

    return err;
}

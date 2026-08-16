extern void TRKTargetSetStopped(int);
extern void UnreserveEXI2Port(void);
extern void TRKSwapAndGo(void);
extern void ReserveEXI2Port(void);

int TRKTargetContinue(void)
{
    TRKTargetSetStopped(0);
    UnreserveEXI2Port();
    TRKSwapAndGo();
    ReserveEXI2Port();
    return 0;
}

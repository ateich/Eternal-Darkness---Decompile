typedef void (*DBCommCallback)(void);

extern DBCommCallback gDBCommTable[];

void UnreserveEXI2Port(void)
{
    gDBCommTable[6]();
}

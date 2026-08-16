typedef void (*DBCommCallback)(void);

extern DBCommCallback gDBCommTable[];

void ReserveEXI2Port(void)
{
    gDBCommTable[5]();
}

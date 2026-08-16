typedef void (*DBCommCallback)(void);

extern DBCommCallback gDBCommTable[];

void fn_800F5754(void)
{
    gDBCommTable[1]();
}

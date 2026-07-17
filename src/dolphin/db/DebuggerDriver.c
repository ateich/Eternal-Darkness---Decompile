/* Stub debugger transport used when no host debugger is present. */

__declspec(weak) int Hu_IsStub(void)
{
    return 1;
}

void DBInitComm(void)
{
}

void DBInitInterrupts(void)
{
}

int DBQueryData(void)
{
    return 0;
}

int DBRead(void)
{
    return 0;
}

int DBWrite(void)
{
    return 0;
}

void DBOpen(void)
{
}

void DBClose(void)
{
}

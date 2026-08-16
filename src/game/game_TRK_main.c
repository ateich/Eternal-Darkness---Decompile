extern int TRK_mainError;

int TRKInitializeNub(void);
void TRKNubWelcome(void);
void TRKNubMainLoop(void);
int TRKTerminateNub(void);

void TRK_main(void)
{
    TRK_mainError = TRKInitializeNub();
    if (TRK_mainError == 0) {
        TRKNubWelcome();
        TRKNubMainLoop();
    }
    TRK_mainError = TRKTerminateNub();
}

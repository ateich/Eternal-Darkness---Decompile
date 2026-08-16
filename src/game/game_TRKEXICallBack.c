extern void OSEnableScheduler(void);
extern void TRKLoadContext(void *, unsigned int);

void TRKEXICallBack(int interrupt, void *context)
{
    OSEnableScheduler();
    TRKLoadContext(context, 0x500);
}

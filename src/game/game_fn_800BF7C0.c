extern void fn_801A75A0(void *, int);
extern void fn_800C2474(void *, int);
extern void fn_801A74E8(void *, unsigned int);

int fn_800BF7C0(void *object, void *event)
{
    fn_801A75A0(event, 0);
    fn_800C2474(object, 1);
    fn_801A74E8(event, 0x1000000);
    return 1;
}

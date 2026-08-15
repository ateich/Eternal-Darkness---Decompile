extern void *memcpy(void *, const void *, unsigned int);
extern unsigned char *fn_8017BA24(void *);
extern int fn_8017B7DC(void);
extern int fn_8017B7FC(void);
extern void *fn_8017B9C4(void *);
extern unsigned short fn_800B15F8(void *, void *, unsigned char *, int, void *);
extern unsigned char lbl_80247434[];
extern unsigned char lbl_802478A8[];

void fn_800BBF6C(void *object, void *input)
{
    unsigned char *buffer = fn_8017BA24(object);
    int value1 = fn_8017B7DC();
    int value2 = fn_8017B7FC();
    void *runtime = fn_8017B9C4(object);
    unsigned short offset = fn_800B15F8(lbl_80247434, lbl_802478A8,
                                        buffer, value1, runtime);
    (void)value2;
    memcpy(buffer + offset, input, 0x1B8);
}

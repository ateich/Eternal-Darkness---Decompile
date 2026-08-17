typedef unsigned char u8;

extern void fn_80201BD0(void*);
extern void *fn_80201B8C();
extern void fn_8012ADA4(void*, void*);
extern void fn_8012AC74(void*, void*, int);

void fn_8012ABEC(void* owner, void* out)
{
    int flags;
    u8* current;

    fn_80201BD0(owner);
    current = fn_80201B8C();
    flags = 3;
    if (current != 0) {
        current = *(u8**)(current + 0x68);
        if (current != 0 && (*(unsigned int*)(current + 0x2C) & 4) != 0) {
            flags &= ~1;
        }
    }
    fn_8012ADA4(owner, out);
    fn_8012AC74(owner, out, flags);
}

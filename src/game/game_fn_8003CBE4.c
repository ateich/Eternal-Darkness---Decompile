typedef unsigned int u32;

extern void *fn_801294DC(void *, int, int, int);

void fn_8003CBE4(int context, u32 flags, void *resource)
{
    if ((flags & 0x3FF) == 0) {
        fn_801294DC(resource, 0x10, 0x20, 1);
    }
}

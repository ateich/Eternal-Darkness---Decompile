typedef unsigned int u32;

extern void *fn_80156938(void *);
extern u32 fn_80193860(void *);
extern void fn_801938D8(void *, u32);

void fn_800DA278(void *object)
{
    void *unused = 0;
    char *cursor = object;
    void *resource;
    int i = 0;

    do {
        if (*(void **)(cursor + 0x54) != 0) {
            resource = *(void **)((char *)fn_80156938(*(void **)(cursor + 0x54)) + 0x88);
            if (resource != 0) {
                u32 state = fn_80193860(resource);
                fn_801938D8(resource, state | 0x40000);
                *(void **)(cursor + 0x54) = unused;
            }
        }
        i++;
        cursor += 4;
    } while (i < 4);
}

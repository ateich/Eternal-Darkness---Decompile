typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Actor {
    u8 pad0[0x84];
    u16 flags;
} Actor;

typedef struct Entry {
    u8 pad0[0xC0];
    void *actor;
} Entry;

extern Entry lbl_80325850[];
extern void *fn_80201B8C();
extern void *fn_80201B94(void *);
extern int fn_80201C48(void *);
extern int fn_80193860(void *);
extern void fn_801938D8(void *, int);

int fn_800D9D64(void *unused, void *object)
{
    int state;
    u32 cursor = (u32)object;

    (void)unused;
    state = (int)*(Actor **)((unsigned char *)fn_80201B8C((void *)cursor) + 0x64);
    if (fn_80201C48(fn_80201B94((void *)cursor)) != 0 &&
        (((Actor *)state)->flags & 0x10) == 0) {
        state = 0;
        cursor = (u32)lbl_80325850;
        while (state < 4) {
            void *handle = *(void **)((u8 *)((Entry *)cursor)->actor + 0x88);
            if (handle != 0) {
                int flags = fn_80193860(handle);
                fn_801938D8(handle, flags | 0x40000);
            }
            state++;
            cursor += sizeof(Entry);
        }
    }
    return 1;
}

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Work {
    u8 pad[0x6C];
    unsigned int first[4];
    unsigned int second[4];
    u16 third[4];
    u8 flag;
    u8 pad95[0x2F];
    struct Owner* owner;
} Work;

typedef struct Owner {
    u8 pad[0x148];
    u8 flag;
} Owner;

extern void* fn_8006D1DC(int);
extern void fn_8006D198(Work*, void*, int);
extern void fn_8006C9E4(void*, int);
extern void fn_8006BEE4(void*, int);

void fn_800878F4(Work* work)
{
    void* context;
    int i;

    context = fn_8006D1DC(0);
    fn_8006D198(work, context, 1);
    for (i = 0; i < 4; i++) {
        work->first[i] = 0;
        work->second[i] = 0;
        work->third[i] = 0;
    }
    work->flag = 0;
    work->owner->flag = 0;
    fn_8006C9E4(context, 0);
    fn_8006BEE4(context, 0);
}

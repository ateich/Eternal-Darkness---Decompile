typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Context {
    u8 pad[8];
    u16 counter;
} Context;

typedef struct Runtime {
    u8 pad[0x15C];
    u8* memory;
} Runtime;

typedef struct Work {
    u8 bytes[0xC4];
    Runtime* runtime;
} Work;

extern void *fn_8006ED3C();
extern void fn_8006BEE4(Context*, void (*)(void));
extern void fn_8006DEF8(Work*, int, void*, Work*, u16);
extern void fn_8006EA4C(void);
extern void fn_8006EB60(void);
extern void fn_8008A0B4(void);
extern void fn_8008A2E0(void);
extern char* fn_800FD40C(void*, const void*);
extern void* memset(void*, int, unsigned int);
extern const u8 lbl_80245164[];

void fn_80089EE8(Work* work)
{
    int index;
    Context* context = fn_8006ED3C(work, 5, &index);
    u8* memory;

    context->counter = 0;
    memory = work->runtime->memory;
    *(int*)(memory + 0x1780) = -1;
    fn_8006BEE4(context, fn_8006EA4C);

    work->bytes[index * 0x2C + 0x6A] = 0;
    work->bytes[index * 0x2C + 0x6B] = 4;
    memset(memory, 0, 0xB00);
    memset(memory + 0xB00, 0, 0xC40);

    work->bytes[index * 0x2C + 0x6A] = 0;
    work->bytes[index * 0x2C + 0x6B] = 4;
    work->bytes[index * 0x2C + 0x68] = 4;
    fn_8006DEF8(work, 5, fn_8008A0B4, work, 300);

    work->bytes[index * 0x2C + 0x68] = 0;
    fn_8006DEF8(work, 5, fn_8008A2E0, work, 10);
    work->bytes[index * 0x2C + 0x68] = 1;
    fn_8006DEF8(work, 5, fn_8008A0B4, work, 500);
    work->bytes[index * 0x2C + 0x68] = 2;
    fn_8006DEF8(work, 5, fn_8008A2E0, work, 10);

    work->bytes[index * 0x2C + 0x68] = 0;
    fn_8006BEE4(context, fn_8006EB60);
    fn_800FD40C(work->bytes + 0x18, lbl_80245164);
}

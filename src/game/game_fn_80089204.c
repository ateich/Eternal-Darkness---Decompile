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
extern void fn_8006DEF8(Work*, int, void*, Work*, int);
extern void fn_8006EB60(void);
extern void fn_80089394(void);
extern void fn_80089754(void);
extern char* fn_800FD40C(void*, const void*);
extern void* memset(void*, int, unsigned int);
extern const u8 lbl_802450D8[];

void fn_80089204(Work* work)
{
    int index;
    Context* context = fn_8006ED3C(work, 1, &index);
    u8* memory = work->runtime->memory;

    *(int*)(memory + 0x1780) = -1;
    context->counter = 0;
    memory[0x1784] = 0;
    fn_8006BEE4(context, fn_8006EB60);
    work->bytes[index * 0x2C + 0x6A] = 0;
    work->bytes[index * 0x2C + 0x6B] = 4;
    memset(memory, 0, 0xB00);
    memset(memory + 0xB00, 0, 0xC40);
    work->bytes[index * 0x2C + 0x68] = 4;
    fn_8006DEF8(work, 1, fn_80089394, work, 100);
    work->bytes[index * 0x2C + 0x68] = 0;
    fn_8006DEF8(work, 1, fn_80089754, work, 0x3D);
    work->bytes[index * 0x2C + 0x68] = 1;
    fn_8006DEF8(work, 1, fn_80089394, work, 100);
    work->bytes[index * 0x2C + 0x68] = 2;
    fn_8006DEF8(work, 1, fn_80089754, work, 0x3D);
    work->bytes[index * 0x2C + 0x68] = 0;
    fn_800FD40C(work->bytes + 0x18, lbl_802450D8);
}

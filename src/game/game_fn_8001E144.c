typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Context {
    u8 pad00[0xC];
    u32 handle;
    u32 end;
    u32 value;
    u32 argument;
    u8 pad1C[0x14];
    u32 flags;
    u32 resource;
    u16 kind;
    u8 state;
    u8 limit;
} Context;

typedef struct Timings {
    u32 first;
    u32 second;
    u32 third;
    u32 fourth;
} Timings;

typedef struct GlobalState {
    u8 pad00[0x1C];
    Context context;
    u8 object[0x26C];
    Timings timings;
} GlobalState;

typedef struct Block64 { u32 word[16]; } Block64;

extern GlobalState lbl_80302400;
extern u8 lbl_8023D020[];
extern Block64 lbl_80238978;
extern Block64 lbl_80238998;
extern u32 lbl_8064C5E0;
extern u32 lbl_8064C5E8[2];
extern u32 lbl_8064C640;
extern void* lbl_8064C7AC;
extern u32 lbl_8064C794;
extern u32 lbl_8064C248;

extern void fn_8000518C(void*, int, u32);
extern void fn_8001D56C(void);
extern void fn_8001DE68(void);
extern void fn_8001DE84(u32, u32);
extern u32 fn_80024638(void*, void*, u32*);
extern void fn_80023B40(void);
extern void fn_80042E3C(void);
extern void fn_80042EDC(void);
extern void fn_800B177C(u32, void*);
extern void fn_800B2548(u32, u32);
extern void fn_800B689C(u32, u32);
extern void* fn_80138164(void);
extern void* fn_8015AA0C(void);
extern void* fn_8015AA14(void);
extern void fn_8015D458(void*, void*, void*);
extern void fn_8015DAB0(void*);
extern u32 fn_801A98F4(u32, u32);
extern void fn_801A99B4(void);
extern void fn_801AD4B4(u32, u32, u32, u32);
extern void fn_801E6CA0(void*, u32, u32, u32, u32);
extern void fn_801E6F9C(u32);
extern void fn_801E85A8(void);
extern void fn_801EFE84(u32);
extern void fn_8020EF54(void*, void*);
extern void fn_8022A814(u32, u32);

void fn_8001E144(u32 mode)
{
    GlobalState* global = &lbl_80302400;
    Context* context = &global->context;
    u32 size;
    void* start;

    fn_8022A814(0, 0);
    fn_8000518C(context, 0, 0x44);
    context->limit = 200;
    context->kind = 7;
    context->value = 255;
    lbl_8064C5E8[0] = 0;
    lbl_8064C5E8[1] = 0;
    lbl_8064C640 = 0;
    context->argument = mode;
    context->flags = 0;
    fn_8020EF54(global->object, lbl_8023D020 + 0x83C);
    lbl_8064C5E0 = 0;
    fn_8001DE84(3, 0);
    fn_8001DE84(3, 0);
    context->value = 255;
    context->flags |= 0x20;
    global->timings.first = 2000;
    global->timings.second = 1000;
    global->timings.third = 1000;
    global->timings.fourth = 1000;

    if (mode == 0) {
        fn_801AD4B4(7, 0, 0, 0);
        fn_8001D56C();
        fn_801A99B4();
    }
    context->handle = 0;
    context->end = 0;

    switch (mode) {
    case 1:
    case 12:
    case 13:
        fn_8001DE84(1, 0);
        fn_8001DE84(1, 0);
        context->value = 255;
        context->flags |= 1;
        context->flags |= 0x10;
        global->timings.second = 3000;
        global->timings.third = 1500;
        global->timings.fourth = 1500;
        {
            void* start = fn_80138164();
            context->handle = fn_80024638(lbl_8023D020 + 0x848, start, &global->timings.first);
            fn_8015DAB0((void*)context->handle);
            context->end = (u32)start + ((global->timings.first + 31) & ~31);
        }
        if (context->flags & 4) {
            context->resource = fn_801A98F4(629, 100);
            fn_8001DE84(25, 0);
            context->value = 255;
            context->flags |= 1;
        }
        fn_80042EDC();
        fn_80042E3C();
        break;
    case 3:
        start = fn_80138164();
        context->handle = fn_80024638(lbl_8023D020 + 0x848, start, &size);
        fn_8015DAB0((void*)context->handle);
        context->end = (u32)start + ((size + 31) & ~31);
        fn_8015D458(lbl_8023D020 + 0x858, (void*)context->end, fn_8015AA14());
        fn_8015DAB0((void*)context->end);
        context->state = 253;
        break;
    case 4:
        start = fn_80138164();
        context->handle = fn_80024638(lbl_8023D020 + 0x848, start, &size);
        fn_8015DAB0((void*)context->handle);
        context->end = (u32)start + ((size + 31) & ~31);
        fn_8015D458(lbl_8023D020 + 0x858, (void*)context->end, fn_8015AA14());
        fn_8015DAB0((void*)context->end);
        fn_801E6CA0(lbl_8064C7AC, 0, 39, 0, 1);
        fn_801E6F9C(0);
        context->state = 254;
        break;
    case 5:
        {
            void* second = fn_8015AA0C();
            start = fn_80138164();
            context->handle = fn_80024638(lbl_8023D020 + 0x848, start, &size);
            fn_8015DAB0((void*)context->handle);
            context->end = (u32)start + ((size + 31) & ~31);
            fn_8015D458(lbl_8023D020 + 0x858, (void*)context->end, fn_8015AA14());
            fn_8015DAB0((void*)context->end);
            lbl_8064C794 = fn_80024638(lbl_8023D020 + 0x864, second, &size);
        }
        fn_801E85A8();
        lbl_8064C248 = 1;
        fn_800B177C(1, (void*)fn_80023B40);
        fn_800B689C(0, 1);
        fn_800B2548(12, 0);
        *(Block64*)(lbl_8023D020 + 0x75C + 0x60) = lbl_80238978;
        *(Block64*)(lbl_8023D020 + 0x75C + 0x80) = lbl_80238998;
        fn_8001DE84(27, 0);
        fn_8001DE84(6, 0);
        lbl_8064C5E8[0] = 1;
        break;
    case 14:
        start = fn_80138164();
        context->handle = fn_80024638(lbl_8023D020 + 0x848, start, &size);
        fn_8015DAB0((void*)context->handle);
        context->end = (u32)start + ((size + 31) & ~31);
        fn_8015D458(lbl_8023D020 + 0x858, (void*)context->end, fn_8015AA14());
        fn_8015DAB0((void*)context->end);
        context->state = 252;
        fn_8001DE84(27, 0);
        fn_8001DE84(252, 0);
        fn_801EFE84(0);
        break;
    }

    fn_8001DE68();
}

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Context {
    u8 pad[8];
    s16 counter;
} Context;

typedef struct Runtime {
    u8 pad[0x15C];
    u8* memory;
} Runtime;

typedef struct Work {
    u8 bytes[0xC4];
    Runtime* runtime;
} Work;

extern Context* fn_8006ED3C(Work*, int, int*);
extern u32 fn_801809A0(void*);
extern void* fn_80155DB4(void*);
extern int fn_80157034(void*);
extern int fn_80157050(void*);
extern void* fn_80149E04(void);
extern int fn_8017FDF4(void*);
extern void fn_801489B4(void*, void*);
extern void fn_8014E000(void);
extern void fn_80184990(void);
extern void fn_80184740(void*);
extern int fn_801E79FC(void*, int);
extern void fn_80149B38(void*);
extern void fn_801E8328(int, void*);
extern u32 lbl_8064EBA0;
extern void* lbl_8064C4E0;

int fn_80089754(Work* work)
{
    int index;
    u32 color;
    Context* context = fn_8006ED3C(work, 1, &index);
    int result = 0;
    u8* effect;
    u8* memory = work->runtime->memory;
    u32 identifier;

    context->counter++;
    effect = memory + 0xB00;
    if (*(void**)(memory + 0x94) != 0) {
        identifier = fn_801809A0(*(void**)(memory + 0x94));
        if (identifier == *(u32*)(memory + 0x1740)) {
            void* object = fn_80155DB4(*(void**)(memory + 0x94));
            if (object != 0 && fn_80157034(object) == 0 &&
                fn_80157050(*(void**)(memory + 0x94)) == 0) {
                *(void**)(effect + 0xC0) = fn_80149E04();
                if (*(void**)(effect + 0xC0) != 0) {
                    int value;

                    color = lbl_8064EBA0;
                    value = fn_8017FDF4(*(void**)(memory + 0x94));
                    fn_801489B4(effect, *(void**)(effect + 0xC0));
                    *(u32*)(effect + 0x94) = 0;
                    *(void (**)(void))(effect + 0x98) = fn_8014E000;
                    *(void (**)(void))(effect + 0x90) = fn_80184990;
                    fn_80184740(effect);
                    *(u32*)(effect + 0xA8) = identifier;
                    effect[0xBC] = 4;
                    *(signed char*)(effect + 3) = -1;
                    *(s16*)(effect + 4) = -1;
                    effect[0x14] = 0xE0;
                    *(int*)(effect + 0x28) = value;
                    if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0) {
                        ((u8*)&color)[0] = 0;
                        ((u8*)&color)[1] = 0xFA;
                        ((u8*)&color)[2] = 0;
                    }
                    *(u32*)(effect + 0x2C) = color;
                    (*(u8**)(effect + 0xC0))[0] = memory[0];
                    fn_80149B38(*(void**)(effect + 0xC0));
                    fn_801E8328(0x1A, effect);
                    result = 1;
                }
            }
        }
    }
    return result;
}

typedef unsigned char u8;
typedef unsigned short u16;

extern void* fn_80149E04(void*);
extern int fn_80201B54(void*);
extern void fn_80147E88(void*);
extern void fn_801496D8(void*, void*);
extern void* fn_80201B3C(void);
extern void fn_80149B0C(void*, int, int);
extern void fn_801913F4(void*);
extern int fn_801E8328(int, void*);

void fn_8014CE98(void* state, void* owner, int first, int second,
                 void* source, int callback, int callback_arg, u16 value,
                 u8 mode, int* copied_value, int extra, int flag,
                 u8 kind, u8 variant)
{
    void* entry;
    int owner_id;

    entry = *(void**)((char*)state + 0xC0) = fn_80149E04(state);
    if (entry != 0) {
        owner_id = fn_80201B54(owner);
        fn_80147E88(state);
        fn_801496D8(state, entry);
        *(u8*)((char*)state + 0xBC) = 4;
        if (flag != 0)
            *(u8*)((char*)state + 0xBC) |= 8;
        if (owner == fn_80201B3C())
            *(u8*)((char*)state + 0xBC) |= 0x10;
        *(int*)((char*)state + 0xA8) = owner_id;
        fn_80149B0C(entry, first, second);
        fn_801913F4(state);
        *(u8*)((char*)state + 1) = 1;
        *(u16*)((char*)state + 4) = value;
        *(u16*)((char*)state + 6) =
            *(u8*)state * *(u8*)entry - 15;
        *(u8*)((char*)state + 0x14) = 3;
        *(u8*)((char*)state + 0x15) = kind;
        *(u8*)((char*)state + 0x16) = variant;
        *(u8*)((char*)state + 0x17) = 5;
        *(u8*)((char*)state + 0x18) = 1;
        *(u8*)((char*)state + 0x19) = 200;
        *(u8*)((char*)state + 0x1B) = 10;
        *(int*)((char*)state + 0x28) = owner_id;
        *(int*)((char*)state + 0x38) = extra;
        *(int*)((char*)state + 0x2C) = fn_80201B54(source);
        *(int*)((char*)state + 0x30) = callback;
        *(int*)((char*)state + 0x34) = callback_arg;
        *(u8*)((char*)state + 0x1C) = mode;
        *(int*)((char*)state + 0x3C) = *copied_value;
        fn_801E8328(0x11, state);
    }
}

typedef unsigned char u8;
typedef unsigned short u16;

extern void* fn_80149E04(void*);
extern int fn_80201B54(void*);
extern void fn_80147E88(void*);
extern void fn_80149668(void*, void*);
extern void fn_80149B0C(void*, int, int);
extern void fn_801913F4(void*);
extern int fn_801E8328(int, void*);

void fn_8014CFF4(void* state, void* owner, int first, int second,
                 float* position, int extra, int flag)
{
    void* entry;
    int owner_id;

    entry = *(void**)((char*)state + 0xC0) = fn_80149E04(state);
    if (entry != 0) {
        owner_id = fn_80201B54(owner);
        fn_80147E88(state);
        fn_80149668(state, entry);
        *(u8*)((char*)state + 0xBC) = 4;
        if (flag != 0)
            *(u8*)((char*)state + 0xBC) |= 8;
        *(int*)((char*)state + 0xA8) = owner_id;
        fn_80149B0C(entry, first, second);
        fn_801913F4(state);
        *(u16*)((char*)state + 6) = *(u8*)state * *(u8*)entry - 15;
        *(int*)((char*)state + 0x28) = owner_id;
        *(int*)((char*)state + 0x38) = extra;
        *(u16*)((char*)state + 0x1E) = (short)position[0];
        *(u16*)((char*)state + 0x20) = (short)position[1];
        *(u16*)((char*)state + 0x22) = (short)position[2];
        fn_801E8328(0x11, state);
    }
}

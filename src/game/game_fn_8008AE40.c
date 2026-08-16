typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Info {
    u8 pad48[0x48];
    void* field48;
    u8 pad4C[0x14];
    void* field60;
} Info;

extern void* fn_801A7498(void*);
extern void* fn_801A7490(void*);
extern void *fn_80201814();
extern void* fn_800CC458(void*, void*, int);
extern Info*fn_80201B8C();
extern void* fn_80035628(void*);
extern void fn_800355F0(void*, void*);

int fn_8008AE40(void* unused, void* config)
{
    register void* first;
    register void* argument;
    register void* firstObject;
    register void* created;
    register void* transform;

    argument = config;
    first = fn_801A7498(argument);
    firstObject = fn_80201814(first);
    argument = fn_801A7490(argument);

    if (firstObject != 0 && fn_80201814(argument) != 0) {
        created = fn_800CC458(first, argument, 1);
        argument = fn_80201B8C(created);
        first = fn_80201B8C(firstObject);
        transform = fn_80035628(firstObject);
        fn_800355F0(created, transform);
        *(u16*)((u8*)((Info*)argument)->field60 + 0x17C) =
            *(u16*)((u8*)((Info*)first)->field48 + 6);
        if (*(u16*)((u8*)((Info*)argument)->field60 + 0x17C) == 0)
            *(u16*)((u8*)((Info*)argument)->field60 + 0x17C) = 0x968;
    }
    return 1;
}

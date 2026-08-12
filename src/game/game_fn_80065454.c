typedef unsigned char u8;
typedef signed int s32;

extern s32 fn_80066BB8(s32 object, s32 index);
extern s32 fn_80201B5C(s32 context);

s32 fn_80065454(s32 context, s32 object, u8 *entry, s32 enabled)
{
    s32 result = 0;

    if (entry != 0 && entry[0x9E] == 2 && entry[0x9F] == 3 &&
        *(s32 *)(entry + 0x94) == 2 && enabled == 1 &&
        fn_80066BB8(object, 0) == 0 && fn_80201B5C(context) != 0x1C &&
        fn_80201B5C(context) != 0x1B) {
        result = 1;
    }
    return result;
}

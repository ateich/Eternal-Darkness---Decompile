typedef unsigned int u32;

typedef struct Effect Effect;

extern Effect* fn_801AC7BC(u32);
extern void fn_801AB0C4(Effect*, int, int);

void fn_801AC980(u32 key, int value)
{
    Effect* effect = fn_801AC7BC(key);
    if (effect != 0) {
        fn_801AB0C4(effect, value, 4);
    }
}

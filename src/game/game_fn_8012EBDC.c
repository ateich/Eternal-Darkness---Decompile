typedef unsigned char u8;

typedef struct Owner Owner;
typedef struct Object Object;

typedef struct Runtime {
    u8 bytes[0x110];
} Runtime;

typedef struct Resource {
    u8 bytes[4];
    Object* object;
} Resource;

extern Runtime* fn_80128E30(Owner*);
extern unsigned int fn_8011FAEC(void*);
extern void fn_80129DE0(Owner*, Runtime*, int, int);
extern int fn_80134FF8(void*, Object*);

int fn_8012EBDC(Owner* owner)
{
    Runtime* state = fn_80128E30(owner);

    if ((fn_8011FAEC(owner) & 0x400) == 0) {
        fn_80129DE0(owner, state, 0, 0);
    }
    (void)fn_80134FF8(owner, (*(Resource**)(state->bytes + 0xB8))->object);
    return 0;
}

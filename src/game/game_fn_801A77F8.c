typedef unsigned short u16;

typedef struct {
    unsigned char pad[0x12];
    u16 value;
} Result;

extern Result* fn_801A78C0(void*);

u16 fn_801A77F8(void* data) { return fn_801A78C0(data)->value; }

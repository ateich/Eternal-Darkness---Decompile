typedef unsigned char u8;

typedef struct Object800A2D1C {
    u8 pad000[0x160];
    unsigned int handle;
} Object800A2D1C;

extern void* fn_8017FEA4(void);
extern void fn_8017FF14(unsigned int, void*);
extern void fn_80186A58(unsigned int, int);

void fn_800A2D1C(Object800A2D1C* object)
{
    if (object->handle != 0) {
        void* runtime = fn_8017FEA4();
        fn_8017FF14(object->handle, (u8*)runtime + 0x3C);
        fn_80186A58(object->handle, 0);
        object->handle = 0;
    }
}

typedef unsigned char u8;

extern void* fn_80156938(void*);
extern void fn_8019DF5C(void*);
extern void fn_8017FD6C(void*);

void fn_80153140(void* object, int alternate)
{
    void* runtime;
    void* effect;

    if (object != 0) {
        runtime = fn_80156938(object);
        if (runtime != 0) {
            effect = *(void**)((u8*)runtime + 0x88);
            if (effect != 0) {
                if (alternate != 0) {
                    fn_8019DF5C(effect);
                } else {
                    fn_8017FD6C(effect);
                }
            }
        }
    }
}

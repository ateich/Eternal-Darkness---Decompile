typedef unsigned short u16;

extern void* fn_801D3974(void*);
extern int fn_8006749C(void*);
extern void fn_8014C060(void*, int, int, void**, u16, int, int);

void fn_800A1C50(void* object, int value, void* item, int mode)
{
    void* type = fn_801D3974(item);
    u16 id = fn_8006749C(item);
    fn_8014C060(object, 0, value, &type, id, mode, 0);
}

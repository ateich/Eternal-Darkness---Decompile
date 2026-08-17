typedef unsigned short u16;

extern int fn_80128AB8(void*, u16);

int fn_80128B10(void* owner, unsigned int value)
{
    return fn_80128AB8(owner, (u16)value);
}

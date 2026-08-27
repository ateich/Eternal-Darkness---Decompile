typedef unsigned short u16;

extern void fn_80184C7C(void*, void*);

void fn_8018504C(unsigned char* self, void* value)
{
    *(u16*)(self + 0xA4) |= 1;
    fn_80184C7C(self, value);
}

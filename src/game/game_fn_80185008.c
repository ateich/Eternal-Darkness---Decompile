typedef unsigned short u16;

extern void fn_8017FF40(void*, u16, void*);
extern void fn_8018504C(void*, void*);

void fn_80185008(unsigned char* self, void* value)
{
    unsigned char result[8];

    fn_8017FF40(value, *(u16*)(self + 0xAA), result);
    fn_8018504C(self, result);
}

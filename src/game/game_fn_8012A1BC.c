typedef unsigned char u8;
extern u8* fn_8012A13C(void*, int);

int fn_8012A1BC(void* owner, int index)
{
    int result = -1;
    u8* entry = fn_8012A13C(owner, index);
    if (entry != 0) {
        result = *(int*)(*(u8**)(entry + 4) + 8);
    }
    return result;
}

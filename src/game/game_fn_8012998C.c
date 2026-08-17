typedef unsigned char u8;

extern u8* fn_80128E30(void*);

int fn_8012998C(void* owner, float value)
{
    int result = 0;
    u8* entry = fn_80128E30(owner);
    if ((*(unsigned short*)(entry + 0xF8) & 2) != 0) {
        *(float*)(entry + 0xC0) = value;
        result = 1;
    }
    return result;
}

typedef unsigned char u8;

#define FN_80128E30_RETURN u8*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

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

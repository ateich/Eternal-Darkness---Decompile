typedef unsigned char u8;

#define FN_80128E30_RETURN u8*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);
extern int fn_801296E8(u8*, int);

int fn_801296F8(void* owner, int value)
{
    int result = -1;
    u8* entry = fn_80128E30(owner);
    if (entry != 0) {
        result = fn_801296E8(entry, value);
    }
    return result;
}

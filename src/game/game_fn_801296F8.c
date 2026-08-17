typedef unsigned char u8;

extern u8* fn_80128E30(void*);
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

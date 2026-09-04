typedef unsigned char u8;
typedef unsigned short u16;

extern int fn_801C3F6C(u16, u16, void*, void*, u8, void*);

int fn_801C40AC(u16 resource_id, u16 record_id, void* arg2, void* arg3,
                void* arg4)
{
    return fn_801C3F6C(resource_id, record_id, arg2, arg3, 0, arg4);
}

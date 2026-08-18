typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* fn_80201814(u32);
extern void* fn_80155DB4(void);
extern void* fn_80149E04(void);
extern void fn_801541BC(void*, void*, u8, u8);
extern void fn_801A19BC(void*);
extern void fn_80149B0C(void*, u32, u32);
extern void* fn_80148300(void*, void*, void*);
extern void fn_80149EB8(void*);
extern void* memset(void*, int, unsigned int);

void* fn_80154340(u32 object_id, u32 arg1, u32 arg2, u8 byte2, u16 value,
                  u8 byte, u8 kind, float scale)
{
    void* result = 0;
    void* owner;
    void* resource;
    u8 object[0xC0];

    if (fn_80201814(object_id) != 0) {
        owner = fn_80155DB4();
        if (owner != 0) {
            memset(object, 0, sizeof(object));
            resource = fn_80149E04();
            if (resource != 0) {
                fn_801541BC(object, resource, 1, kind);
                fn_801A19BC(object);
                object[0xBC] = byte;
                *(u32*)(object + 0x94) = 0;
                *(u16*)(object + 6) = value;
                *(float*)(object + 0x14) = scale;
                object[0x19] = byte2;
                fn_80149B0C(resource, arg1, arg2);
                result = fn_80148300(owner, object, resource);
                if (result == 0)
                    fn_80149EB8(resource);
            }
        }
    }
    return result;
}

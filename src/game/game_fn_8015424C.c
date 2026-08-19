typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *fn_80201814();
extern void* fn_80155DB4(void);
extern void* fn_80149E04(void);
extern void fn_80147E88(void*);
extern void fn_801541BC(void*, void*, u8, u8);
extern void fn_801A1AB0(void*);
extern void fn_80149B0C(void*, u32, u32);
extern void* fn_80148300(void*, void*, void*);
extern void fn_80149EB8(void*);

void* fn_8015424C(u32 object_id, u32 arg1, u32 arg2, u8 alternate, u16 value,
                  u8 enabled, u8 byte, u8 kind)
{
    void* result = 0;
    void* owner;
    void* resource;
    u8 object[0xC0];

    if (fn_80201814(object_id) != 0) {
        owner = fn_80155DB4();
        if (owner != 0) {
            resource = fn_80149E04();
            if (resource != 0) {
                fn_80147E88(object);
                fn_801541BC(object, resource, alternate, kind);
                object[0xBC] = byte;
                if (value != 0 || (enabled != 0 && alternate != 0 && value == 0)) {
                    fn_801A1AB0(object);
                    *(u16*)(object + 6) = value;
                    *(u32*)(object + 0x94) = 0;
                    object[0x18] = alternate;
                }
                fn_80149B0C(resource, arg1, arg2);
                result = fn_80148300(owner, object, resource);
                if (result == 0)
                    fn_80149EB8(resource);
            }
        }
    }
    return result;
}

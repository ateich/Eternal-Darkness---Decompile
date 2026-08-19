typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern void *fn_80201814();
extern void* fn_80155DB4(void);
extern void* fn_80149E04(void);
extern void fn_80147E88(void*);
extern void fn_80152D84(void*, void*, u8);
extern void fn_80149B0C(void*, void*, void*);
extern void* fn_80148300(void*, void*, void*);
extern void fn_80149EB8(void*);

void* fn_80152BCC(void* gate, void* arg1, void* arg2, u8* overrides,
                  u8 tail0, u8 kind, int copy_color, u8 tail2)
{
    u8 config[0xC0];
    void* result = 0;
    void* owner;
    void* object;
    s16 signed_value;

    if (fn_80201814(gate) != 0) {
        owner = fn_80155DB4();
        if (owner != 0) {
            object = fn_80149E04();
            if (object != 0) {
                fn_80147E88(config);
                fn_80152D84(config, object, kind);
                if (overrides != 0) {
                    *(u16*)(config + 6) = *(u16*)(overrides + 6);
                    if (overrides[2] != 0)
                        config[2] = overrides[2];
                    if (*(s8*)(overrides + 3) != 0)
                        config[3] = overrides[3];
                    signed_value = *(s16*)(overrides + 4);
                    if (signed_value != 0)
                        *(s16*)(config + 4) = signed_value;
                    if (*(u16*)(overrides + 8) != 0)
                        *(u16*)(config + 8) = *(u16*)(overrides + 8);
                    if (overrides[1] != 0)
                        config[1] = overrides[1];
                    if (overrides[0x1C] != 0)
                        config[0x1C] = overrides[0x1C];
                    if (*(u16*)(overrides + 0x14) != 0)
                        *(u16*)(config + 0x14) = *(u16*)(overrides + 0x14);
                    if (overrides[0x1D] != 0)
                        config[0x1D] = overrides[0x1D];
                    if (overrides[0x1C] != 0)
                        config[0x1C] = overrides[0x1C];
                    if (overrides[0x1F] != 0)
                        config[0x1F] = overrides[0x1F];
                    if (overrides[0x20] != 0)
                        config[0x20] = overrides[0x20];
                    if (*(s8*)(overrides + 0x22) != 0)
                        config[0x22] = overrides[0x22];
                    if (copy_color != 0) {
                        config[0x18] = overrides[0x18];
                        config[0x19] = overrides[0x19];
                        config[0x1A] = overrides[0x1A];
                        config[0x1B] = overrides[0x1B];
                    }
                }
                config[0x21] = kind;
                config[0xBC] = tail0;
                config[0xBE] = tail2;
                fn_80149B0C(object, arg1, arg2);
                result = fn_80148300(owner, config, object);
                if (result == 0)
                    fn_80149EB8(object);
            }
        }
    }
    return result;
}

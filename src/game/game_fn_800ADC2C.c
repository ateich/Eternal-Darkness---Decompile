typedef unsigned char u8;

typedef struct Resource800ADC2C {
    u8 pad0[0x2D0];
    int subtype;
    u8 pad2D4[0x28];
    struct Resource800ADC2C* next;
} Resource800ADC2C;

extern Resource800ADC2C* lbl_8064C9C8;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void fn_8020FC0C(Resource800ADC2C*);
extern void fn_8020FE94(Resource800ADC2C*);

void fn_800ADC2C(int alternate)
{
    Resource800ADC2C* resource;
    int interrupts;

    interrupts = OSDisableInterrupts();
    resource = lbl_8064C9C8;
    while (resource != 0) {
        if (resource->subtype != 0) {
            if (alternate != 0) {
                fn_8020FE94(resource);
            } else {
                fn_8020FC0C(resource);
            }
        }
        resource = resource->next;
    }
    OSRestoreInterrupts(interrupts);
}

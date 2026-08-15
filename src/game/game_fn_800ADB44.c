typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Resource800ADB44 {
    u8 pad0[0x2C8];
    u16 kind;
    u8 pad2CA[2];
    int state;
    int subtype;
    u8 pad2D4[0x28];
    struct Resource800ADB44* next;
} Resource800ADB44;

extern Resource800ADB44* lbl_8064C9C8;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);

int fn_800ADB44(int* kind1_count, int* kind2_count, int* kind4_count)
{
    Resource800ADB44* resource;
    int interrupts;
    int special = 0;
    int count1 = 0;
    int count2 = 0;
    int count4 = 0;

    interrupts = OSDisableInterrupts();
    resource = lbl_8064C9C8;
    while (resource != 0) {
        switch (resource->kind) {
        case 1:
            if (resource->state <= 0) {
                count1++;
            }
            break;
        case 2:
            if (resource->state <= 0) {
                count2++;
            }
            break;
        case 4:
            if (resource->state <= 0) {
                if (resource->subtype == 16) {
                    special = 1;
                }
                count4++;
            }
            break;
        case 8:
            break;
        }
        resource = resource->next;
    }
    OSRestoreInterrupts(interrupts);
    *kind1_count = count1;
    *kind2_count = count2;
    *kind4_count = count4;
    return special;
}

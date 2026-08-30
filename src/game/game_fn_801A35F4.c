typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern int lbl_8064D18C;
extern void* fn_8015E780(void);

int fn_801A35F4(u8* object)
{
    float current = *(float*)(object + 0x90);
    if (current < *(float*)(object + 0x8c)) {
        *(float*)(object + 0x90) = current + *(float*)(object + 0x94);
        if (*(float*)(object + 0x90) > *(float*)(object + 0x8c)) {
            *(float*)(object + 0x90) = *(float*)(object + 0x8c);
        }
    } else if (current > *(float*)(object + 0x8c)) {
        *(float*)(object + 0x90) = current - *(float*)(object + 0x94);
        if (*(float*)(object + 0x90) < *(float*)(object + 0x8c)) {
            *(float*)(object + 0x90) = *(float*)(object + 0x8c);
        }
    }

    if (lbl_8064D18C != *(int*)(object + 0x38)) {
        *(u16*)(object + 0x22) = 8;
    }
    if (object[0xe3] != 0 && *(void**)(object + 0x9c) != fn_8015E780()) {
        *(u16*)(object + 0x22) = 8;
    }
    (*(u16*)(object + 0xa))++;
    return 0;
}

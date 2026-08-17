typedef unsigned char u8;
typedef struct PoolSlot { unsigned short value; u8 flags; u8 rest[17]; } PoolSlot;
extern PoolSlot lbl_805B1310[];

int fn_801429A8(void)
{
    int i;
    int result = -1;
    for (i = 0; i < 12; i++) {
        if (!(lbl_805B1310[i].flags & 1)) {
            result = i;
            break;
        }
    }
    return result;
}

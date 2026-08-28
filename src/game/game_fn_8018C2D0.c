typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry8018C2D0 {
    u16 angle;
    u16 zero;
    u16 value;
    u16 scale;
} Entry8018C2D0;

extern u16 lbl_80607120[];

void fn_8018C2D0(Entry8018C2D0* entries, u8 count, u8 value)
{
    int group;
    float angle = 1.0f;
    float step = (float)value / (float)(count - 1);
    Entry8018C2D0* second = (Entry8018C2D0*)((char*)entries + lbl_80607120[1] * 4);

    for (group = 0; group < 2; group++) {
        int i;
        for (i = 0; i < count; i++) {
            entries->angle = (u16)(angle * 325.9493f);
            entries->zero = 0;
            entries->value = value;
            entries->scale = 0x200;
            angle += step;
            entries++;
        }
        entries = second;
    }
}

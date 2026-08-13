typedef unsigned short u16;

typedef struct Record {
    int index;
    unsigned char pad_04[6];
    u16 type;
    unsigned char pad_0c[0x18];
} Record;

extern Record *lbl_8064C8D4;
extern void fn_8006E644(int index, void *owner);

void fn_8006E6EC(void *owner)
{
    int i;
    Record *record;

    i = 0;
    record = lbl_8064C8D4;
    while (i < 0x2C) {
        if (record->type == 4) {
            fn_8006E644(record->index, owner);
        }
        i++;
        record++;
    }
}

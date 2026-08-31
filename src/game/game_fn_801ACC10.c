typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Record {
    u8 pad00[0x74];
    u32 handle;
    u8 pad78[0x17];
    signed char active;
    u8 pad90[2];
    signed char enabled;
    u8 pad93[5];
} Record;

extern Record lbl_806080E0[];
extern void fn_801AF96C(u32);
extern void fn_801B08BC(int, int, int);

void fn_801ACC10(void)
{
    Record* record = lbl_806080E0;
    int i = 0;

    while (i < 80) {
        if (record->active != 0 && record->enabled != 0) {
            fn_801AF96C(record->handle);
            fn_801B08BC(-1, -1, 1);
        }
        i++;
        record++;
    }
}

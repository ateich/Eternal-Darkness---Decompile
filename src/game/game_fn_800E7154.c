typedef struct Entry {
    int id;
    unsigned char pad[8];
    void **object;
} Entry;

extern Entry lbl_80325DB8[10];
extern void *fn_8015C5E4(int, unsigned short *);
extern void fn_800E7770(unsigned char);
extern void fn_800E7838(void);

void fn_800E7154(int id, void *object)
{
    unsigned char i;
    Entry *entry;

    if (fn_8015C5E4(2, 0) != 0) {
        i = 0;
        while (i < 10) {
            entry = &lbl_80325DB8[i];
            if (id == entry->id && object == *entry->object) {
                fn_800E7770(i);
                break;
            } else {
                i++;
            }
        }
        if (i >= 10) {
            fn_800E7838();
            return;
        }
        fn_800E7838();
    }
}

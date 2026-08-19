typedef signed short s16;
typedef unsigned short u16;

typedef struct Entry {
    s16 id;
    u16 value2;
    u16 value4;
    u16 value6;
} Entry;

extern Entry lbl_805FAA60[10];
extern void* memset(void*, int, unsigned long);

void fn_8016AFB0(s16 id)
{
    int i;

    if (id > 0) {
        for (i = 0; i < 10; i++) {
            if (lbl_805FAA60[i].id == id) {
                if (lbl_805FAA60[i].value6 == 0) {
                    memset(&lbl_805FAA60[i], 0, sizeof(Entry));
                }
                break;
            }
        }
    }
}

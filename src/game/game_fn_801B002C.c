typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x144];
    int object;
    u8 pad148[0x36];
    u8 count;
    u8 pad17f;
    u8 active;
} Entry;

extern int fn_801AF180(int, int, int, int, int);
extern int fn_801AFCC8(int, int, int, int, Entry**, Entry**);
extern void fn_801AED2C(int);
extern void fn_801B01F8(Entry*, int, int);

int fn_801B002C(int owner, int wanted, int limit, int enable, int direct)
{
    Entry* choices[2];
    Entry* special;
    int result;
    int mode;

    if (direct == 1) {
        mode = 1;
    } else {
        mode = fn_801AF180(owner, wanted, limit, enable, direct);
    }
    result = fn_801AFCC8(owner, mode, wanted, limit, choices, &special);
    if (result != 0) {
        if (special != 0 || choices[0] != 0 || choices[1] != 0) {
            if (enable != 0) {
                if (special != 0) {
                    special->count = 1;
                    special->active = 1;
                    fn_801AED2C(special->object);
                }
                if (choices[0] != 0) {
                    fn_801B01F8(choices[0], 0, 4);
                }
                if (choices[1] != 0) {
                    fn_801B01F8(choices[1], 0, 4);
                }
            }
        }
    }
    return result;
}

typedef unsigned char u8;
typedef signed char s8;

typedef struct Entry {
    char pad_0[4];
    void* object;
    int type;
    s8 active;
    char pad_D[3];
} Entry;

typedef struct Manager {
    char pad_0[8];
    u8 count;
    char pad_9[3];
    Entry* entries;
} Manager;

extern void* lbl_8064CF58;
extern void *fn_80156938();
extern void fn_80156FF4(void*);
extern void fn_80153104(void*);
extern void fn_801544C4(void*, int);

void fn_80134210(Manager* manager)
{
    int offset = 0;
    void* object;
    int i = 0;

    while (i < manager->count) {
        object = *(void**)((char*)manager->entries + offset + 4);

        if (object != 0) {
            lbl_8064CF58 = fn_80156938(object);
            if (*(s8*)((char*)manager->entries + offset + 0xC) == 0) {
                switch (*(int*)((char*)manager->entries + offset + 8)) {
                case 35:
                case 36:
                case 37:
                case 38:
                case 40:
                case 42:
                case 43:
                    fn_80156FF4(*(void**)((char*)manager->entries + offset + 4));
                    break;
                case 39:
                    fn_80153104(object);
                    break;
                case 41:
                    fn_801544C4(object, 1);
                    break;
                case 44:
                    break;
                }
                *(void**)((char*)manager->entries + offset + 4) = 0;
            }
        }
        offset += 0x10;
        i++;
    }
}

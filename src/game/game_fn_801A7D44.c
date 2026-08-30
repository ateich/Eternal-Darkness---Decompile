typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry801A7D44 {
    u8 pad[0x68];
    int value;
    u8 tail[0x8];
} Entry801A7D44;

typedef struct Object801A7D44 {
    u8 pad[0xB0];
    u16 count;
    u8 padB2[2];
    Entry801A7D44* entries;
} Object801A7D44;

extern Object801A7D44* fn_8015C28C(int);

void fn_801A7D44(void)
{
    Object801A7D44* object = fn_8015C28C(2);
    if (object != 0 && *(signed char*)((u8*)object + 0x8142) != 0 &&
        *(signed char*)((u8*)object + 0x8143) != 0) {
        u16 count = object->count;
        Entry801A7D44* entry = object->entries;
        while (count > 0) {
            entry->value = 0;
            entry++;
            count--;
        }
    }
}

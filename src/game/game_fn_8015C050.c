typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Vec { float x, y, z; } Vec;
typedef struct Item { u8 pad[0x58]; u8 index; u8 tail[3]; } Item;
typedef struct Config { u8 pad[0x24]; Item* items; u8* lookup; u8 pad2[4]; s16* positions; } Config;
extern u16 fn_8015C470(int);
extern Config* fn_8015C390(int);
extern Vec* fn_8011F130(void*);
extern u32 fn_80178F14(s16, s16, s16, int, int, int);

Item* fn_8015C050(void* object)
{
    u16 count = fn_8015C470(2);
    Item* best = 0;
    if (count != 0) {
        Config* config = fn_8015C390(2);
        Item* item = config->items;
        u8* lookup = config->lookup;
        s16* positions = config->positions;
        Vec* position = fn_8011F130(object);
        u32 best_distance = 0x7FFFFFFF;
        int i;
        for (i = 0; i < count; i++, item++) {
            int slot = item->index;
            u16 point = **(u16**)(lookup + slot * 0x38 + 0x2c);
            s16* candidate = positions + point * 3;
            u32 distance;
            fn_80178F14(candidate[0], candidate[1], candidate[2],
                        (int)position->x, (int)position->y, (int)position->z);
            distance = fn_80178F14(candidate[0], candidate[1], candidate[2],
                                   (int)position->x, (int)position->y, (int)position->z);
            if (distance < best_distance) {
                best_distance = distance;
                best = item;
            }
        }
    }
    return best;
}

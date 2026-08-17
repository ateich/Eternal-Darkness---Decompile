typedef unsigned char u8;
typedef unsigned int u32;

typedef struct CopyBlock {
    u32 words[68];
} CopyBlock;

extern void* fn_80128E30(void* object);
extern int fn_80128F40(void* object);

void fn_8011EB24(void* object)
{
    void* source;
    int value;
    void* nested;

    if (*(void**)((u8*)object + 672) != 0) {
        source = fn_80128E30(object);
        value = fn_80128F40(object);
        if (*(int*)((u8*)source + 240) != -1) {
            *(int*)((u8*)object + 608) = value;
            *(CopyBlock*)((u8*)object + 68) = *(CopyBlock*)source;
            nested = *(void**)((u8*)source + 184);
            if (nested != 0) {
                *(u32*)((u8*)object + 308) = *(u32*)nested;
            }
        }
    }
}

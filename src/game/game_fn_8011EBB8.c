typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct CopyBlock {
    u32 words[68];
} CopyBlock;

typedef struct Target {
    CopyBlock block;
    u8 pad[1904];
    u16 count;
    u16 enabled;
} Target;

typedef struct Object {
    u8 pad[64];
    Target* target;
    CopyBlock block;
} Object;

void fn_8011EBB8(Object* object)
{
    object->target->block = object->block;
    object->target->count = 0;
    object->target->enabled = 1;
}

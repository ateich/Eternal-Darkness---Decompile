typedef struct Entry { int value; int object; int resource; int callback; int state; int index; unsigned short flags; unsigned short pad; } Entry;
typedef struct PackedEntry { unsigned char flags; unsigned char index; short value; short object; short pad; int resource; short callback; unsigned short entry_flags; } PackedEntry;

void fn_8011E8D8(PackedEntry* src, Entry* dst)
{
    dst->value = src->value;
    dst->object = src->object;
    dst->resource = src->resource;
    dst->callback = src->callback;
    dst->state = src->flags & 1;
    dst->index = src->index;
    dst->flags = src->entry_flags;
}

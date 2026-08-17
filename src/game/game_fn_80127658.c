typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Table {
    void* pad0;
    void** definitions;
} Table;

typedef struct Runtime {
    u8 pad0[0xB8];
    Table* table;
} Runtime;

typedef struct Owner {
    u8 pad0[0x160];
    void* channels;
} Owner;

typedef struct Channel {
    void* value;
    int direction;
    u8 pad8[4];
    u8 first[0x1C];
    u8 second[0x1C];
} Channel;

typedef struct Definition {
    u16 first_count;
    u16 pad2;
    void* first_entries;
    u16 second_count;
    u16 padA;
    void* second_entries;
} Definition;

extern Runtime* fn_80128E30(Owner*);
extern void fn_80127714(void*, u16, void*, int, void*, int);

void fn_80127658(Owner* owner, int index, void* value, int flag)
{
    Channel* channel;
    Definition* definition;
    Runtime* runtime;

    channel = (Channel*)((u8*)owner->channels + index * 0x4C + 4);
    runtime = fn_80128E30(owner);
    definition = (Definition*)((u8*)*runtime->table->definitions +
                               index * 0x10);
    channel->value = value;
    if (definition->first_count != 0) {
        fn_80127714(definition->first_entries, definition->first_count,
                    channel->first, channel->direction, value, flag);
    }
    if (definition->second_count != 0) {
        fn_80127714(definition->second_entries, definition->second_count,
                    channel->second, channel->direction, value, flag);
    }
}

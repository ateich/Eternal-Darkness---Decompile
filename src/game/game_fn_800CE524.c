typedef unsigned char u8;
typedef signed short s16;

typedef struct Entry {
    s16 pad0;
    s16 first_a;
    s16 neg_a;
    s16 pad6;
    s16 first_b;
    s16 neg_b;
    s16 padC;
    s16 second_a;
    s16 neg_c;
    s16 pad12;
    s16 second_b;
    s16 neg_d;
} Entry;

typedef struct Data {
    u8 pad[0xEC];
    s16 cursor;
    s16 span;
} Data;

typedef struct RuntimeState {
    u8 pad[0x1C];
    Data *data;
} RuntimeState;

extern int lbl_8064D738;
extern void *fn_80201B8C();

void fn_800CE524(void *object)
{
    int index;
    Data *data = ((RuntimeState *)fn_80201B8C(object))->data;
    s16 span = data->span;
    Entry *entry;
    u8 *entries = (u8 *)data + 0x78;
    s16 first;
    s16 second;

    index = lbl_8064D738;

    data->cursor++;
    if (data->cursor > 480) {
        data->cursor = 0;
    }
    entry = (Entry *)(entries + index * sizeof(Entry));
    first = data->cursor;
    second = first + span;
    entry->first_a = first;
    entry->neg_a = -1;
    entry->first_b = first;
    entry->neg_b = -1;
    entry->second_a = second;
    entry->neg_c = -1;
    entry->second_b = second;
    entry->neg_d = -1;
}

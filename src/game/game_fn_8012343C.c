typedef unsigned short u16;

typedef struct Pair {
    u16 first;
    u16 second;
} Pair;

typedef struct Runtime {
    unsigned char pad[0x1E];
    u16 kind;
    unsigned char pad20[0x94];
    Pair* pairs;
} Runtime;

extern volatile float lbl_80650118;
extern int fn_80130998(u16 kind, float value);

int fn_8012343C(Runtime* runtime, int use_first, float value)
{
    int raw_index = fn_80130998(runtime->kind, value);
    int index;
    int result;

    if (use_first != 0) {
        index = raw_index - 1;
        result = runtime->pairs[index].first << 5;
    } else {
        index = raw_index - 1;
        result = runtime->pairs[index].second << 5;
    }

    value = lbl_80650118;
    index = fn_80130998(runtime->kind, value) - 1;
    result += runtime->pairs[index].second << 5;
    return result;
}

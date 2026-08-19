typedef struct OuterObject {
    char pad0[0x28];
    void* object;
} OuterObject;

typedef struct Command {
    int type;
    int first;
    int second;
} Command;

typedef struct Pair {
    int first;
    int second;
} Pair;

extern Pair lbl_8023A798[];
extern void fn_8015EFEC(void*, Command*);
extern void fn_8015F2B0(void*, int*, int);
extern void fn_8015F4D0(OuterObject*, Command*, int);
extern int fn_8015F9B0(void*, int, int);

void fn_8015F7D4(OuterObject* outer, int type, Command* output,
                 Command* input)
{
    void* object = outer->object;

    switch (type) {
    case 12:
        fn_8015EFEC(object, input);
        output->first = input->first;
        fn_8015F2B0(object, &output->second, input->second);
        break;
    case 13:
        fn_8015EFEC(object, input);
        output->second = input->second;
        fn_8015F2B0(object, &output->first, input->first);
        break;
    default:
        fn_8015F4D0(outer, input, 1);
        fn_8015F9B0(object, lbl_8023A798[type].first,
                    lbl_8023A798[type].second);
        break;
    }
}

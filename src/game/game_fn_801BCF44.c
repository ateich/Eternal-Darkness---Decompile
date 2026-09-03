typedef unsigned short u16;

typedef struct IdEntry {
    u16 id;
} IdEntry;

int fn_801BCF44(IdEntry* left, IdEntry* right)
{
    return left->id - right->id;
}

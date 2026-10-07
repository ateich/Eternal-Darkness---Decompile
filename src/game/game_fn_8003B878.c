typedef struct SortCandidate {
    unsigned char padding[4];
    unsigned int key;
} SortCandidate;

int fn_8003B878(const SortCandidate *left, const SortCandidate *right)
{
    int result = 0;

    if (left->key < right->key) {
        result = -1;
    } else if (left->key > right->key) {
        result = 1;
    }
    return result;
}

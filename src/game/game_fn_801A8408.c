typedef struct Node801A8408 Node801A8408;

struct Node801A8408 {
    Node801A8408* next;
    unsigned char pad04[4];
    void* allocation;
    void* argument;
    void (*callback)(void*);
};

extern void* lbl_8064D28C;

extern void fn_801A84C8(Node801A8408*);
extern void fn_8017CE74(void*, void*);

Node801A8408* fn_801A8408(Node801A8408* node)
{
    Node801A8408* next = 0;

    if (node != 0) {
        node->callback(node->argument);
        fn_801A84C8(node);
        next = node->next;
        fn_8017CE74(node->allocation, node->argument);
        fn_8017CE74(lbl_8064D28C, node);
    }

    return next;
}

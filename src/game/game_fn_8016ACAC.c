typedef struct Pair {
    const char* name;
    void* value;
} Pair;

typedef struct Context Context;

extern void fn_8016A950(Context*, void*, int);
extern void fn_8016AB20(Context*, const char*);

void fn_8016ACAC(Context* context, Pair* pairs, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        fn_8016A950(context, pairs[i].value, 0);
        fn_8016AB20(context, pairs[i].name);
    }
}

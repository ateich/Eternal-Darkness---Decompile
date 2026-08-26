typedef unsigned char u8;

#pragma use_lmw_stmw on

extern int fn_8012FA54(u8*, int);
extern void* fn_8012C62C(u8*, int, void*, void*, void*, int);

void fn_8012C774(u8* state, void* a, void* b, void* c, int flags)
{
    int i;
    unsigned int av;
    unsigned int bv;
    unsigned int cv;

    for (i = 0; i < 15; i++) {
        if (fn_8012FA54(state, i)) {
            cv = *(unsigned int*)c;
            bv = *(unsigned int*)b;
            av = *(unsigned int*)a;
            fn_8012C62C(state, i, &av, &bv, &cv, flags);
        }
    }
}

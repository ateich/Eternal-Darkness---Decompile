typedef short s16;

extern int fn_80052310(int type, const s16* position);

int fn_80046378(int type, const s16* position, int unused)
{
    return fn_80052310(type, position);
}

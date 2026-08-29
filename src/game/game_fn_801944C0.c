typedef unsigned char u8;

extern void fn_8019453C(float*, int, void*);

void fn_801944C0(int limit, float* data, void* unused, void* context)
{
    u8 count;
    int column;
    int row;
    register void* saved_context;
    register float* entry;

    count = limit - 4;
    saved_context = context;
    entry = data + ((u8)(limit - 4) * 4 + 9);
    row = 0;
    do {
        column = 0;
        while (column < count) {
            fn_8019453C(entry, 20, saved_context);
            entry += 2;
            column++;
        }
        row++;
        entry += 2;
    } while (row < 2);
}

typedef unsigned short u16;

void fn_80145774(u16* values, int level, int threshold, int increment, int node)
{
    int cursor = node + level;
    while (cursor != 0) {
        values[cursor] += increment;
        cursor >>= 1;
    }
    if (values[1] < threshold)
        return;
    {
        increment = level * 2;
        node = increment - 1;
        for (; node >= level; node--) {
            if (values[node] > 1)
                values[node] >>= 1;
        }
        level--;
        {
            u16* child = values + increment - 2;
            u16* parent = values + level;
            for (; level != 0; level--) {
                *parent = child[0] + child[1];
                child -= 2;
                parent--;
            }
        }
    }
}

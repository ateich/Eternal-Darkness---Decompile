typedef unsigned int u32;

int fn_80180454(u32* words)
{
    int clear = 1;

    if (words[0] != 0) {
        clear = 0;
    } else if (words[1] != 0) {
        clear = 0;
    } else if (words[2] != 0) {
        clear = 0;
    } else if (words[3] != 0) {
        clear = 0;
    }

    return clear;
}

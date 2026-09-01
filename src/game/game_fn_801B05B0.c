typedef struct Entry Entry;

extern Entry* fn_801AF760(int);
extern void fn_801B01F8(Entry*, int, int);

void fn_801B05B0(int handle, int volume)
{
    Entry* entry = fn_801AF760(handle);
    fn_801B01F8(entry, volume, 2);
}

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void fn_80207CC8(s32 chan, u32 dev, u64 *id);

void fn_80207CA0(s32 chan)
{
    u64 id;

    fn_80207CC8(chan, 0, &id);
}

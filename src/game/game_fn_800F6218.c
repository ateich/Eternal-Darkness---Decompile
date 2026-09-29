unsigned long long fn_800F6218(unsigned int hi, unsigned int lo, unsigned int shift)
{
    lo >>= shift;
    lo |= hi << (32 - shift);
    lo |= hi >> (shift - 32);
    hi >>= shift;
    return ((unsigned long long)hi << 32) | lo;
}

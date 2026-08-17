void fn_801285D8(unsigned* value, unsigned kind)
{
    *value &= ~3u;
    *value |= kind & 3;
}

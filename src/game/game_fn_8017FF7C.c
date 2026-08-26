unsigned int fn_8017FF7C(void* object, int index, int slot)
{
    unsigned int (*entries)[14] = *(void**)((char*)object + 0x4C);
    return entries[index][10 + slot];
}

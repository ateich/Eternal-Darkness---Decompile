extern void fn_801563C0(void*);

void fn_8015644C(unsigned int flags, void* object)
{
    if ((flags & 2) != 0 || (flags & 4) != 0)
        fn_801563C0(object);
}

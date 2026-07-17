extern "C" {
int __register_fragment(void* exception_info, void* toc);
void __unregister_fragment(int fragment_id);
void __destroy_global_chain(void);
extern char _eti_init_info[];
}

static int fragmentID = -2;

asm static void* GetR2(void)
{
    nofralloc
    mr r3, r2
    blr
}

extern "C" void __fini_cpp_exceptions(void)
{
    if (fragmentID != -2) {
        __unregister_fragment(fragmentID);
        fragmentID = -2;
    }
}

extern "C" void __init_cpp_exceptions(void)
{
    if (fragmentID == -2) {
        fragmentID = __register_fragment(_eti_init_info, GetR2());
    }
}

#pragma section ".ctors$10"
__declspec(section ".ctors$10")
extern void* const __init_cpp_exceptions_reference = __init_cpp_exceptions;

#pragma section ".dtors$10"
__declspec(section ".dtors$10")
extern void* const __destroy_global_chain_reference = __destroy_global_chain;

#pragma section ".dtors$15"
__declspec(section ".dtors$15")
extern void* const __fini_cpp_exceptions_reference = __fini_cpp_exceptions;

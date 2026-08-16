unsigned long __fwrite(const void* ptr, unsigned long size, unsigned long count, void* stream);

unsigned long fwrite(const void* ptr, unsigned long size, unsigned long count, void* stream)
{
    return __fwrite(ptr, size, count, stream);
}

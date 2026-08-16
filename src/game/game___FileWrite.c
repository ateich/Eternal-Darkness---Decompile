unsigned long fwrite(const void*, unsigned long, unsigned long, void*);

void* __FileWrite(void* stream, const char* source, unsigned long count)
{
    if (fwrite(source, 1, count, stream) == count) {
        return stream;
    }
    return 0;
}

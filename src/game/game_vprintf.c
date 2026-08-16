extern unsigned char __files[];
int fwide(void*, int);
int __FileWrite(void*, const char*, unsigned long);
int __pformatter_800FA174(void*, void*, const char*, void*);

int vprintf(const char* format, void* args)
{
    void* stream = __files + 0x50;

    if (fwide(stream, -1) >= 0) {
        return -1;
    }
    return __pformatter_800FA174(__FileWrite, stream, format, args);
}

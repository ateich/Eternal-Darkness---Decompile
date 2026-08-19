extern void* fn_8015C390(int);

int fn_8015C524(void* target, int selector)
{
    unsigned char* entry = fn_8015C390(selector);
    unsigned int offset;
    int result;
    int i;
    result = -1;
    if (entry != 0) {
        unsigned short count = *(unsigned short*)(entry + 0x58);
        for (i = 0, offset = 0; i < count; offset += 0x2C, i++) {
            if (target == *(void**)(*(unsigned char**)(entry + 0x5C) + offset)) {
                result = i;
                break;
            }
        }
    }
    return result;
}

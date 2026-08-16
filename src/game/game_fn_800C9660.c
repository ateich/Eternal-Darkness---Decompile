typedef unsigned char u8;

extern void *fn_80201BD0(void *);
extern void *fn_80201C24(void *);
extern int fn_80157AB8(void *);

u8 fn_800C9660(void *object)
{
    u8 result = 0;

    if (object != 0) {
        void *first = fn_80201BD0(object);
        if (first != 0) {
            void *second = fn_80201C24(first);
            if (second != 0) {
                result = fn_80157AB8(second);
            }
        }
    }
    return result;
}

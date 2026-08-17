extern void* fn_8015C390(int);
extern void fn_8013B798(void*, void*, int);
extern void* lbl_8064C4E4;

void fn_8013B83C(void* object)
{
    void* list;
    int different;
    int offset;
    int i;

    if (object != 0) {
        list = fn_8015C390(2);
        if (list != 0) {
            i = 0;
            offset = 0;
            different = object != lbl_8064C4E4;
            while (i < *(unsigned short*)((char*)list + 0x10)) {
                fn_8013B798((char*)*(void**)((char*)list + 0x14) + offset,
                            object, different);
                offset += 0x74;
                i++;
            }
        }
    }
}

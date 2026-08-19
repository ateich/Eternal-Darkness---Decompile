typedef struct ResourceHeader {
    void* data;
} ResourceHeader;

extern void fn_8015DAB0(void*);

void fn_8015DA70(ResourceHeader* header, void* data, const signed char* defer_fixups)
{
    if (header->data == 0) {
        header->data = data;
        if (*defer_fixups == 0) {
            fn_8015DAB0(header->data);
        }
    }
}

typedef struct Buffer {
    char data[0x120];
} Buffer;

extern char lbl_8064BA78;
extern void fn_8016A44C(Buffer*, signed char*, void*, void*);
extern int fn_80160DD0(void*, void*, int);

int fn_80160E50(void* object, signed char* text, void* value, void* context)
{
    Buffer buffer;

    if (context == 0) {
        context = &lbl_8064BA78;
    }
    fn_8016A44C(&buffer, text, value, context);
    return fn_80160DD0(object, &buffer, *text == 27);
}

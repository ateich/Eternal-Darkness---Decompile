typedef unsigned int u32;

extern void* fn_80049220(void* object, int index);
extern void* fn_80049304(void* object, void* value);
extern u32 fn_80157994(void* object);
extern void* fn_80201C24(void* object);
extern void fn_802053B0(void* object, void* value);

u32 fn_800496EC(void* object)
{
    u32 result = 0;

    if (object != 0) {
        void* entry = fn_80049220(object, 1);
        void* converted = fn_80049304(object, entry);

        if (converted != 0) {
            void* linked = fn_80201C24(converted);

            fn_802053B0(object, linked);
            result = fn_80157994(fn_80201C24(converted));
        }
    }
    return result;
}

typedef unsigned char u8;

extern void* fn_80201B3C();
extern int fn_80201B44();
extern void* fn_80158598(void* object, int index);
extern int fn_80157E1C(void* object);
extern void* fn_80157E24(void* object, int index);
extern void *fn_80201814();
extern void fn_802020B4(void* object, u8 value);

void fn_80049774(int value)
{
    void* first = fn_80201B3C();
    void* object = (void*)fn_80201B44();

    if (first != 0) {
        u8 byte;
        void* entry = fn_80158598(object, 0);

        if (entry != 0) {
            int count = fn_80157E1C(entry);
            int i;

            byte = value;

            for (i = 0; i < count; i++) {
                void* item = fn_80201814(fn_80157E24(entry, i));

                if (item != 0) {
                    fn_802020B4(item, byte);
                }
            }
        }
    }
}

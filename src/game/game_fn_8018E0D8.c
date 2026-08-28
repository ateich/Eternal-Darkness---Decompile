typedef unsigned char u8;
typedef signed short s16;
extern u8 lbl_8063C068[];
extern void fn_80179B08(void*, float*);
extern void fn_8017ACE0(void*, float*, float*);
extern int fn_801F6D90(s16, s16, s16);
extern int fn_8018D1F0(u8, int);
typedef void (*Callback)(void*, float, float, float, float, float);
void fn_8018E0D8(u8* object, void* context, Callback callback)
{
    float position[3];
    float projected[3];
    int id;
    int radius;
    fn_80179B08(object + 0xA, position);
    fn_8017ACE0(lbl_8063C068, position, projected);
    id = fn_801F6D90(*(s16*)(object + 0xA), *(s16*)(object + 0xC), *(s16*)(object + 0xE));
    radius = fn_8018D1F0(object[0x21], id);
    callback(context, projected[0] - radius, projected[1] - radius,
             projected[0] + radius, projected[1] + radius, projected[2]);
    object[0x2B] = id >= 255 ? 255 : id;
}

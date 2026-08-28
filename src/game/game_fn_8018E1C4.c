typedef unsigned char u8;
extern void fn_8018E230(u8*, u8*, u8, u8, u8, u8);
extern void fn_8018E260(u8*, u8, u8);
void fn_8018E1C4(u8* object, u8 value, u8 count, u8 stride)
{
    u8* data = *(u8**)(object + 0x4C);
    fn_8018E230(data, data + 0x2B, 4, value, count, stride);
    fn_8018E260(data, value, stride);
}

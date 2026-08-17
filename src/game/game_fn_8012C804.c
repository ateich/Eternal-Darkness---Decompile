typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80125ECC(u8*);
extern void fn_8012BFE4(u8*);
extern void fn_8012C478(u8*, int, int);
extern void fn_8012CAC4(u8*, int, void*);

/* Honest reconstruction retained while MWCC scheduling/register allocation is tuned. */
void fn_8012C804(u8* dst, u8* src, int index)
{
    int i;
    fn_80125ECC(dst);
    for (i = 0; i < 32; i++) {
        *(void**)(dst + 0x17C + i * 8) = 0;
        *(u16*)(dst + 0x180 + i * 8) = 0;
    }
    fn_8012BFE4(dst);
    fn_8012CAC4(dst, index, 0);
    *(float*)(dst + 0x278) = *(float*)(src + 0x278);
}

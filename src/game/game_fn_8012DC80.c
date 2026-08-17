typedef unsigned char u8;

int fn_8012DC80(u8* owner)
{
    return *(void**)(owner + 0x240) != 0;
}

typedef struct Vec3s {
    short x;
    short y;
    short z;
} Vec3s;

void fn_8017FF40(void* object, int index, Vec3s* output)
{
    char* source = (char*)*(void**)((char*)object + 0x4C) + index * 0x38;
    output->x = *(short*)(source + 0xA);
    output->y = *(short*)(source + 0xC);
    output->z = *(short*)(source + 0xE);
}

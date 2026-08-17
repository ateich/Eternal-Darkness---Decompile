extern void* fn_801E741C(void* record);

int fn_8011F958(void* object, void* target)
{
    int offset = 0;
    int index = 0;
    while (index < *(unsigned short*)((char*)*(void**)((char*)object + 0x3C) + 0x84)) {
        void* records = *(void**)((char*)*(void**)((char*)object + 0x3C) + 0x88);
        if (target == fn_801E741C((char*)records + offset + 0x38)) {
            return index;
        }
        offset += 0x78;
        index++;
    }
    return -1;
}

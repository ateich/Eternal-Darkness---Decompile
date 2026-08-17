extern float lbl_80650090;

void fn_8011F918(void* object)
{
    char* bytes = object;
    float current = *(float*)(bytes + 0x28);
    if (current < lbl_80650090) {
        *(float*)(bytes + 0x28) = current + *(float*)(bytes + 0x24);
    }
}

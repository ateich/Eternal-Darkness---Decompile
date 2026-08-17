extern void fn_80149E28(void*);
void fn_8014B738(void* object)
{
    switch (*(unsigned short*)((unsigned char*)object + 0x132C)) {
    case 2:
        fn_80149E28(object);
        break;
    }
}

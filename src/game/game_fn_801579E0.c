typedef struct Object { void* primary; void* secondary; int a; int b; unsigned int flags; int first; int second; } Object;

void fn_801579E0(Object* object, int first, int second)
{
    object->first = first;
    object->second = second;
}

typedef struct Entry { int value; void* object; int resource; void* callback; int state; int index; unsigned short flags; unsigned short pad; } Entry;
extern Entry lbl_803324D0;
int fn_8011E86C(void) { return lbl_803324D0.resource; }

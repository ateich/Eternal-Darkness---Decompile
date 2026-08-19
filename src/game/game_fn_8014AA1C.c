typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct Set { u8 count; u8 p1[3]; u16 mask; u16 active; u32 id; u8 pC[0x3C]; u32 value48; u8 p4C[0x3C]; void* objects[16]; } Set;
typedef struct Vec { float x,y,z; } Vec;
extern void *fn_80156938(); extern int fn_80157034(void*); extern u32 fn_80036D5C(void);
extern void fn_8017FD6C(void*); extern void *fn_80201BC8(); extern int fn_8012FA54(void*,u32);
extern int fn_8012DC94(void*,u32); extern void* fn_80193848(void*); extern void *fn_80201814();
extern void* fn_80155DB4(void*); extern u32 fn_80193838(void*); extern int fn_8011F6A4(void*,u32,u32,int,Vec*,int);
extern short* fn_8017FDE4(void*); extern u32 fn_80193840(void*); extern short* fn_801938A8(void*);
extern void fn_8014B604(float*,short*);
void fn_8014AA1C(void* left, void* right) {
    int ready=0,i; Set* source=0; Set* set; u16 bit; Vec v;
    if(!left)return; if(right && !fn_80157034(right) && (source=fn_80156938(right)) && !(fn_80036D5C()&0x04000000)) ready=1;
    if(!(set=fn_80156938(left)))return;
    if(!ready){for(i=0,bit=1;i<set->count;i++,bit<<=1)if((set->mask&bit)&&set->objects[i]){fn_8017FD6C(set->objects[i]);set->mask&=~bit;}return;}
    {void* src=fn_80201BC8(source);for(i=0,bit=1;i<set->count;i++,bit<<=1){int keep=0;void* obj;
      if(!(set->mask&bit)||!(obj=set->objects[i]))continue;
      if(fn_8012FA54(src,set->value48)||!fn_8012DC94(src,set->value48)){void* link=fn_80201814(fn_80193848(obj));
       if(link && !(fn_80036D5C()&0x04000000) && (link=fn_80155DB4(link)) && !fn_80157034(link)) {void* dst=fn_80201BC8(link);u32 id=fn_80193838(obj);
        if(fn_8012FA54(dst,id)||!fn_8012DC94(dst,id)){short* p;fn_8011F6A4(src,set->id,set->value48,-1,&v,1);p=fn_8017FDE4(obj);p[0]=(short)v.x;p[1]=(short)v.y;p[2]=(short)v.z;
         fn_8011F6A4(dst,fn_80193840(obj),id,-1,&v,1);p=fn_801938A8(obj);fn_8014B604(&v.x,p);fn_8014B604(&v.y,p+1);fn_8014B604(&v.z,p+2);keep=1;}}}
      if(!keep){fn_8017FD6C(obj);set->mask&=~bit;}
    }}
}

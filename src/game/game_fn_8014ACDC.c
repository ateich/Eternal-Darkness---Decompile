typedef unsigned char u8; typedef unsigned int u32;
typedef struct Set { u8 count;u8 p1[7];u32 id;u8 pC[0x3C];u32 value48;u8 p4C[0x3C];void* objects[16]; } Set;
typedef struct Vec {float x,y,z;} Vec;
extern Set* fn_80156938(void*);extern void *fn_80201BC8();extern u8 fn_801938A0(void*);extern u8 fn_80193880(void*);
extern int fn_8011F6A4(void*,u32,u32,int,Vec*,int);extern short* fn_8017FDE4(void*);extern short* fn_801938A8(void*);
extern void fn_8014B604(float*,short*);extern void fn_8012DBE8(void*,int,u8*);extern u32 fn_80193860(void*);extern void fn_801938D8(void*,u32);
void fn_8014ACDC(void* left,void* right){Set* rs=fn_80156938(right);Set* ls=fn_80156938(left);int i;Vec v;u8 info[4];
 if(ls)for(i=0;i<ls->count;i++){void* o=ls->objects[i];void* ctx=fn_80201BC8(rs);short* p;
  fn_8011F6A4(ctx,ls->id,ls->value48,(u8)(fn_801938A0(o)-1),&v,1);p=fn_8017FDE4(o);fn_8014B604(&v.x,p);fn_8014B604(&v.y,p+1);fn_8014B604(&v.z,p+2);
  fn_8011F6A4(ctx,ls->id,ls->value48,(u8)(fn_80193880(o)-1),&v,1);p=fn_801938A8(o);fn_8014B604(&v.x,p);fn_8014B604(&v.y,p+1);fn_8014B604(&v.z,p+2);
  fn_8012DBE8(ctx,15,info);if(info[3]<255&&o)fn_801938D8(o,fn_80193860(o)|0x40000);
 }}

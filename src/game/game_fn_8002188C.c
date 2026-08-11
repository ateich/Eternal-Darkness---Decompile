/*
 * Front-end/menu presentation dispatcher.
 *
 * This reconstruction deliberately remains ordinary C.  The retail routine is
 * a large mode dispatcher which composes menu text, controller state, save-game
 * state, and several display-list paths; keeping those paths visible is more
 * useful than hiding the function behind an assembly replacement.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned short ushort;
typedef unsigned int u32;
typedef unsigned int uint;
typedef unsigned long long u64;
typedef int s32;

typedef u8 undefined1;
typedef u32 undefined4;
typedef u64 undefined8;
typedef u64 longlong;

#define CONCAT11(a, b) (((u16)(u8)(a) << 8) | (u8)(b))
#define CONCAT22(a, b) (((u32)(u16)(a) << 16) | (u16)(b))
#define CONCAT31(a, b) (((u32)(a) << 8) | (u8)(b))
#define CONCAT44(a, b) (((u64)(u32)(a) << 32) | (u32)(b))

/* r2/r13 anchors used to retain the recovered small-data field accesses. */
extern u8 lbl_80655C80[];
extern u8 lbl_80652930[];
/* Address-named data objects retained until their owning tables are split. */
extern u32 lbl_8023D020;
extern u32 lbl_8023D2A8;
extern u32 lbl_8023D2AC;
extern u32 lbl_8023D2B0;
extern u32 lbl_8023D2B4;
extern u32 lbl_8023D4C0;
extern u32 lbl_8023D4E0;
extern u32 lbl_8023D4F8;
extern u32 lbl_8023D520;
extern u32 lbl_8023D540;
extern u32 lbl_8023DAB4;
extern u32 lbl_8023DBD0;
extern u32 lbl_8023DBD4;
extern u32 lbl_8023DBD8;
extern u32 lbl_8023DBDC;
extern u32 lbl_8023DBE0;
extern u32 lbl_8023DBE4;
extern u32 lbl_8023DBE8;
extern u32 lbl_8023DBEC;
extern u32 lbl_8023DBF0;
extern u32 lbl_8023DBF4;
extern u32 lbl_802515D0;
extern u32 lbl_80265DA0;
extern u32 lbl_80265FD8;
extern u32 lbl_803003D8;
extern u32 lbl_80301CE0;
extern u32 lbl_80302428;
extern u32 lbl_8030242C;
extern u32 lbl_8063B260;
extern u32 lbl_8063B2A0;
extern u32 lbl_8063B2AC;
extern u32 lbl_8063B2C4;
extern u32 lbl_8063B31C;
extern u32 lbl_8063B35C;
extern u32 lbl_8063B374;

/* Recovered callees use the original ABI; declarations are intentionally loose. */
extern s32 fn_8000518C();
extern s32 fn_8001E134();
extern s32 fn_80021234();
extern s32 fn_80021490();
extern s32 fn_80021714();
extern s32 fn_800217F4();
extern s32 fn_80023230();
extern s32 fn_80042FE8();
extern s32 fn_800472B0();
extern s32 fn_800B193C();
extern s32 fn_800B194C();
extern s32 fn_800B2EC0();
extern s32 fn_8011C900();
extern s32 fn_80144470();
extern s32 fn_801A852C();
extern s32 fn_801A8660();
extern s32 fn_801A872C();
extern void fn_801A8D38(int);
extern s32 fn_801A8F08();
extern s32 fn_801A8FE8();
extern s32 fn_801A90BC();
extern s32 fn_801A9118();
extern s32 fn_801A91D4();
extern s32 fn_801A9250();
extern s32 fn_801AD4B4();
extern s32 fn_801E3A34();
extern s32 fn_801E3AA4();
extern s32 fn_801E5430();
extern s32 fn_801E56AC();
extern s32 fn_801E5AD0();
extern void fn_801E5FB0(void*);
#define fn_801E5FB0(a) fn_801E5FB0((void*)(a))

extern s32 fn_801E5FE4();
extern void* fn_801E6CA0(void*, int, int, int, int);
extern s32 fn_801E7578();
extern s32 fn_801E8D34();
extern s32 fn_801EB080();
extern s32 fn_801EC67C();
extern s32 fn_801EC7F4();
extern s32 fn_801ECB40();
extern s32 fn_801ECC4C();
extern s32 fn_801ED3F4();
extern s32 fn_801ED5F4();
extern s32 fn_801F3960();
extern s32 fn_802119B0();
extern s32 fn_802262B8();
extern s32 fn_802266B0();
extern s32 fn_80226EA0();
extern s32 fn_80226FA4();
extern s32 fn_802276AC();
extern s32 fn_80228474();
extern s32 fn_80228730();
extern s32 fn_80228AFC();
extern s32 fn_80228B98();
extern s32 fn_80229330();
extern s32 fn_80229490();
extern s32 fn_80229664();
extern s32 fn_8022979C();
extern s32 fn_802297C8();
extern s32 fn_80229810();
extern s32 fn_80229B08();
extern s32 fn_80229B88();
extern s32 fn_80229C0C();
extern s32 fn_80229CCC();
extern s32 fn_80229D8C();
extern s32 fn_80229E74();
extern s32 fn_80229F4C();
extern s32 fn_80229FA4();
extern s32 fn_8022A044();
extern s32 fn_8022A118();
extern s32 fn_8022A2F4();
extern s32 fn_8022A5D8();
extern s32 fn_8022B4B8();


/* Retail-owned menu/debug strings. */
extern char s_Abdule_Room_213_8023dc8c[];
extern char s_Alex_Room_94_8023dc2c[];
extern char s_CHOOSE_YOUR_FATE_8023dcb4[];
extern char s_Choose_Room_8023dbf8[];
extern char s_Controller___s_8023dd40[];
extern char s_Do_you_want_to_set_the__ar_Etern_8023dcec[];
extern char s_Edward_Room_271_8023dc3c[];
extern char s_Edward_Room_275_8023dc50[];
extern char s_Edward_Room_278_8023dc64[];
extern char s_Edward_Room_282_8023dc78[];
extern char s_Major_Mike_Room_219_8023dca0[];
extern char s_Room_261_8023dc08[];
extern char s_Room_264_8023dc14[];
extern char s_Room_266_8023dc20[];
extern char s__ac_c__i27_8023dcc8[];
extern char s__agPLAYBACK_8023dd5c[];
extern char s__arRECORD_8023dd50[];
extern char s__au_u__i28_8023dcd4[];
extern char s__awYes__ayNo_8023dd30[];
extern char s__ax_x__i29_8023dce0[];
extern char s__ayYes__awNo_8023dd20[];
 
void fn_8002188C(int param_1,uint param_2,uint param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  char cVar3;
  s32 unaff_r2 = (s32)lbl_80655C80;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  s32 unaff_r13 = (s32)lbl_80652930;
  undefined1 uVar10;
  double dVar11;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  uint local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  float local_8c [4];
  float local_7c;
  undefined1 auStack_74 [68];
  undefined8 local_30;
  longlong local_28;
  
  uVar10 = (undefined1)param_3;
  local_90 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d94) >> 8),uVar10);
  local_94 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d90) >> 8),uVar10);
  fn_801ED3F4(lbl_8030242C);
  fn_801A8D38(5);
  if (param_1 == 0x11) {
LAB_80022ae0:
    if (param_1 == 9) {
      fn_801A91D4(5,param_3,1);
    }
    else {
      fn_801A91D4(0xd,param_3,1);
    }
    fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
    fn_801ED5F4((double)*(float *)(unaff_r2 + -0x7da0),1,0x502,1,0,0);
    local_14c = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d70) >> 8),uVar10);
    local_148 = local_14c;
    fn_801A872C(((ushort)(param_2 << 7) & 0x180) + 0x40,
                 (int)(short)((short)(((int)param_2 >> 2) << 7) + 0x30),0x80,0x80,0xffffffff,4,
                 &local_148);
    fn_801ED5F4((double)*(float *)(unaff_r2 + -0x7dc0),0,2,1,0,0);
    fn_801A8D38(5);
    goto LAB_800231d0;
  }
  if (param_1 < 0x11) {
    if (param_1 != 8) {
      if (param_1 < 8) {
        if (param_1 == 4) {
LAB_80023028:
          if (*(int *)(unaff_r13 + -0x62ac) == 0) {
            *(int *)(unaff_r13 + -0x6380) = *(int *)(unaff_r13 + -0x6380) + 1;
          }
          else {
            local_1a8 = *(undefined4 *)(unaff_r2 + -0x7d6c);
            fn_801F3960(&local_1a8);
            fn_801ED3F4(lbl_80302428);
            local_1b0 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d68) >> 8),uVar10);
            local_1ac = local_1b0;
            fn_801A852C(&local_1ac,0,0,0x80000000);
            fn_801A8FE8(&lbl_802515D0,&lbl_8023D4E0,0,0,5);
          }
        }
        else {
          if (param_1 < 4) {
            if (param_1 != 2) {
              if (1 < param_1) {
                fn_801ED3F4(lbl_80302428);
                if (*(int *)(unaff_r13 + -0x5ddc) == 1) {
                  fn_801A9250(2,param_3,1);
                }
                else {
                  fn_801A91D4(2,param_3,1);
                }
                goto LAB_800231d0;
              }
              if (param_1 < 1) goto LAB_800231d0;
              goto LAB_80023028;
            }
          }
          else {
            if (param_1 == 6) {
              fn_801A9250(0x47,param_3,1);
              fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
              iVar4 = fn_800B193C();
              if (iVar4 != 0) {
                iVar4 = fn_800B194C();
                if (iVar4 == 0xc) {
                  local_b8 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d88) >> 8),uVar10)
                  ;
                  local_b4 = local_b8;
                  fn_801A852C(&local_b4,0,0x48,0x80000000);
                  if (*(int *)(unaff_r13 + -0x5ddc) == 0) {
                    fn_801A8F08(0x8c,0x46,500,0x1aa,0xffffffff,0,5);
                  }
                  else {
                    fn_801A8F08(0x8c,0x46,500,0x1aa,0xffffffff,0,5);
                  }
                }
                fn_800B2EC0(param_3);
              }
              goto LAB_800231d0;
            }
            if (5 < param_1) {
              fn_8001E134(1);
              fn_801A9250(1,param_3,1);
              fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
              if (*(int *)(unaff_r13 + -0x6460) != 0) {
                local_98 = local_90;
                iVar4 = fn_801E7578(lbl_80301CE0);
                if (iVar4 != 0) {
                  local_9c = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d84) >> 8),uVar10)
                  ;
                  local_bc = local_9c;
                  fn_801A852C(&local_bc,0,0x45,0x80000000);
                  fn_801A9118(0,0x10,5);
                  iVar4 = fn_801E7578(lbl_80301CE0);
                  if (1 < iVar4) {
                    local_c0 = local_9c;
                    fn_801A852C(&local_c0,0,0x46,0x80000000);
                    fn_801A9118(0,0xc,5);
                  }
                }
                if ((param_2 == 3) && (iVar4 = fn_801E7578(lbl_80301CE0), 2 < iVar4)) {
                  local_98 = CONCAT22(0xfff9,CONCAT11(0xb7,(undefined1)local_98));
                }
                local_c4 = local_98;
                fn_801A852C(&local_c4,5,(int)(short)((short)param_2 + 6),0x80000000);
                fn_801A9118(0,(param_2 & 0x3fff) << 2,5);
              }
              goto LAB_800231d0;
            }
          }
          if (*(int *)(unaff_r13 + -0x62ac) == 0) {
            *(int *)(unaff_r13 + -0x6380) = *(int *)(unaff_r13 + -0x6380) + 1;
          }
          else {
            fn_801ED3F4(lbl_80302428);
            local_b0 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d8c) >> 8),uVar10);
            local_ac = local_b0;
            fn_801A852C(&local_ac,0,1,0x80000000);
            fn_801A8FE8(&lbl_802515D0,&lbl_8023D4E0,0,0,5);
          }
        }
        goto LAB_800231d0;
      }
      if (param_1 == 0xd) {
        fn_80021490(param_3);
        goto LAB_800231d0;
      }
      if (0xc < param_1) {
        if (param_1 == 0xf) {
          fn_801A91D4(0x18,param_3,1);
          fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
          iVar4 = fn_801E8D34(*(undefined4 *)(unaff_r13 + -0x5b00));
          iVar4 = (iVar4 * 0xff) / 0x32 + (iVar4 * 0xff >> 0x1f);
          cVar3 = -1 - ((char)iVar4 - (char)(iVar4 >> 0x1f));
          local_144 = CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,uVar10));
          local_a8 = local_144;
          iVar4 = fn_801E8D34(*(undefined4 *)(unaff_r13 + -0x5b00));
          iVar4 = (iVar4 * 400) / 0x32 + (iVar4 * 400 >> 0x1f);
          fn_801A8660(0,(int)(short)(0x1b8 - ((short)iVar4 - (short)(iVar4 >> 0x1f))),0x280,4,
                       0xffffffff,&local_144);
        }
        else {
          local_a0 = *(undefined4 *)(unaff_r2 + -0x7d80);
          fn_801A9250(2,param_3,1);
          fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
          if ((lbl_803003D8 & 1) == 0) {
            local_cc = local_a0;
            fn_801A852C(&local_cc,5,0x24,0x80000000);
            fn_801A9118(0,0x50,5);
          }
          else {
            local_c8 = local_a0;
            fn_801A852C(&local_c8,5,0x23,0x80000000);
            fn_801A9118(0,0x4c,5);
          }
          iVar4 = fn_80144470(1);
          if (iVar4 == 0) {
            local_d4 = local_a0;
            fn_801A852C(&local_d4,5,0x23,0x80000000);
            fn_801A9118(0,0x2c,5);
          }
          else {
            local_d0 = local_a0;
            fn_801A852C(&local_d0,5,0x24,0x80000000);
            fn_801A9118(0,0x30,5);
          }
          if (*(int *)(unaff_r13 + -0x5ddc) == 0) {
            local_dc = local_a0;
            fn_801A852C(&local_dc,5,0x25,0x80000000);
            fn_801A9118(0,0x58,5);
          }
          else {
            local_d8 = local_a0;
            fn_801A852C(&local_d8,5,0x27,0x80000000);
            fn_801A9118(0,0x54,5);
          }
          iVar4 = *(int *)(unaff_r13 + -0x56ec);
          if (iVar4 == 1) {
            local_e4 = local_a0;
            fn_801A852C(&local_e4,5,0x2e,0x80000000);
            fn_801A9118(0,0x60,5);
          }
          else if (iVar4 < 1) {
            if (-1 < iVar4) {
              local_e0 = local_a0;
              fn_801A852C(&local_e0,5,0x2d,0x80000000);
              fn_801A9118(0,0x5c,5);
            }
          }
          else if (iVar4 < 3) {
            local_e8 = local_a0;
            fn_801A852C(&local_e8,5,0x2f,0x80000000);
            fn_801A9118(0,100,5);
          }
          switch(param_2) {
          case 0:
            local_ec = local_90;
            fn_801A852C(&local_ec,5,0x30,0x80000000);
            fn_801A9118(0,0x68,5);
            break;
          case 1:
            local_f0 = local_90;
            fn_801A852C(&local_f0,5,0x22,0x80000000);
            fn_801A9118(0,0x44,5);
            if ((lbl_803003D8 & 1) == 0) {
              local_f8 = local_90;
              fn_801A852C(&local_f8,5,0x24,0x80000000);
              fn_801A9118(0,0x50,5);
            }
            else {
              local_f4 = local_90;
              fn_801A852C(&local_f4,5,0x23,0x80000000);
              fn_801A9118(0,0x4c,5);
            }
            break;
          case 2:
            local_fc = local_90;
            fn_801A852C(&local_fc,5,0x26,0x80000000);
            fn_801A9118(0,0x48,5);
            if (*(int *)(unaff_r13 + -0x5ddc) == 0) {
              local_104 = local_90;
              fn_801A852C(&local_104,5,0x25,0x80000000);
              fn_801A9118(0,0x58,5);
            }
            else {
              local_100 = local_90;
              fn_801A852C(&local_100,5,0x27,0x80000000);
              fn_801A9118(0,0x54,5);
            }
            break;
          case 3:
            local_108 = local_90;
            fn_801A852C(&local_108,5,0xe,0x80000000);
            fn_801A9118(0,0x14,5);
            iVar4 = fn_80144470(1);
            if (iVar4 == 0) {
              local_110 = local_90;
              fn_801A852C(&local_110,5,0x23,0x80000000);
              fn_801A9118(0,0x2c,5);
            }
            else {
              local_10c = local_90;
              fn_801A852C(&local_10c,5,0x24,0x80000000);
              fn_801A9118(0,0x30,5);
            }
            break;
          case 4:
            local_114 = local_90;
            fn_801A852C(&local_114,5,0xf,0x80000000);
            fn_801A9118(0,0x18,5);
            break;
          case 5:
            local_118 = local_90;
            fn_801A852C(&local_118,5,0x10,0x80000000);
            fn_801A9118(0,0x1c,5);
            break;
          case 6:
            local_11c = local_90;
            fn_801A852C(&local_11c,5,0x29,0x80000000);
            fn_801A9118(0,0x20,5);
            iVar4 = *(int *)(unaff_r13 + -0x56ec);
            if (iVar4 == 1) {
              local_124 = local_90;
              fn_801A852C(&local_124,5,0x2b,0x80000000);
              fn_801A9118(0,0x60,5);
            }
            else if (iVar4 < 1) {
              if (-1 < iVar4) {
                local_120 = local_90;
                fn_801A852C(&local_120,5,0x2a,0x80000000);
                fn_801A9118(0,0x5c,5);
              }
            }
            else if (iVar4 < 3) {
              local_128 = local_90;
              fn_801A852C(&local_128,5,0x2c,0x80000000);
              fn_801A9118(0,100,5);
            }
          }
          iVar4 = fn_800B193C();
          if (iVar4 != 0) {
            fn_800B2EC0(param_3);
          }
          if (param_1 == 0x10) {
            local_12c = *(undefined4 *)(unaff_r13 + -0x66bc);
            fn_8011C900(0x13,0x14,0x44,&local_12c,0x40,0xfe);
            fn_801A8D38(5);
          }
        }
        goto LAB_800231d0;
      }
      if (param_1 == 0xb) goto LAB_80022e60;
      if (10 < param_1) goto LAB_800231d0;
      if (param_1 < 10) goto LAB_80022ae0;
      uVar5 = fn_801EB080();
      local_a4 = *(undefined4 *)(unaff_r2 + -0x7d7c);
      iVar4 = 0x20;
      if (*(int *)(unaff_r13 + -0x62ec) < 0x20) {
        iVar4 = *(int *)(unaff_r13 + -0x62ec);
      }
      fn_800472B0(1);
      fn_80228B98(&lbl_8063B2A0,0);
      fn_80228B98(&lbl_8063B2C4,4);
      fn_80228B98(&lbl_8063B2AC,2);
      fn_8000518C(local_8c,0,0x18);
      if ((iVar4 == 3) && (*(float *)(unaff_r2 + -0x7dd8) == *(float *)(unaff_r13 + -0x6304))) {
        fn_801AD4B4(0,0,1,0);
      }
      if (*(int *)(&lbl_8023D2B4 + iVar4 * 0x10) == 1) {
        local_7c = *(float *)(unaff_r2 + -0x7dc0) - *(float *)(unaff_r13 + -0x6304);
      }
      else {
        local_7c = *(float *)(unaff_r2 + -0x7dd8);
      }
      iVar7 = 0xff;
      if (*(int *)(unaff_r13 + -0x62f4) < 0xff) {
        iVar7 = *(int *)(unaff_r13 + -0x62f4) + 1;
      }
      *(int *)(unaff_r13 + -0x62f4) = iVar7;
      local_8c[0] = local_7c;
      fn_800217F4((double)*(float *)(unaff_r2 + -0x7dd8),(double)*(float *)(unaff_r2 + -0x7dc0),
                   unaff_r13 + -0x6304,unaff_r13 + -0x6308,*(int *)(&lbl_8023D2B0 + iVar4 * 0x10),
                   unaff_r13 + -0x6300);
      iVar7 = (int)(*(float *)(unaff_r2 + -0x7d60) * *(float *)(unaff_r13 + -0x6304));
      local_30 = (double)(longlong)iVar7;
      local_a4 = CONCAT31(local_a4 >> 8,(char)iVar7);
      fn_80021714();
      fn_801EC67C(&lbl_8023DAB4);
      fn_801EC7F4(&lbl_80265FD8,&lbl_8063B35C);
      fn_801EC7F4(&lbl_80265DA0,&lbl_8063B374);
      if (*(uint *)(unaff_r13 + -0x62ec) < 0x21) {
        *(int *)(unaff_r13 + -0x62e8) = *(int *)(unaff_r13 + -0x62e8) + 1;
      }
      if (*(int *)(&lbl_8023D2B0 + iVar4 * 0x10) + 0xc9 < *(int *)(unaff_r13 + -0x62e8)) {
        if (*(int *)(unaff_r13 + -0x630c) != 0) {
          fn_801E5FB0(*(void**)(unaff_r13 + -0x630c));
        }
        if (*(uint *)(unaff_r13 + -0x62ec) < 0x21) {
          *(uint *)(unaff_r13 + -0x62ec) = *(uint *)(unaff_r13 + -0x62ec) + 1;
        }
        iVar4 = 0x20;
        if (*(int *)(unaff_r13 + -0x62ec) < 0x20) {
          iVar4 = *(int *)(unaff_r13 + -0x62ec);
        }
        uVar2 = iVar4 + 1;
        *(uint *)(unaff_r13 + -0x62f0) = uVar2;
        if (uVar2 < 0x21) {
          uVar6 = *(undefined4 *)(&lbl_8023D2AC + uVar2 * 0x10);
        }
        else {
          uVar6 = 0xffffffff;
        }
        iVar4 = iVar4 * 0x10;
        *(undefined4 *)(unaff_r13 + -0x62f0) = uVar6;
        if (*(int *)(&lbl_8023D2A8 + iVar4) == -1) {
          uVar6 = 0;
        }
        else {
          uVar6 = (unsigned int)fn_801E6CA0((void*)*(undefined4 *)(unaff_r13 + -0x6468),0,
                               *(int *)(&lbl_8023D2A8 + iVar4),0,1);
        }
        iVar7 = *(int *)(&lbl_8023D2AC + iVar4);
        *(undefined4 *)(unaff_r13 + -0x630c) = uVar6;
        *(undefined4 *)(unaff_r13 + -0x62e8) = 0;
        *(undefined4 *)(unaff_r13 + -0x62f8) = *(undefined4 *)(unaff_r13 + -0x62fc);
        if (iVar7 == -1) {
          *(undefined4 *)(unaff_r13 + -0x62fc) = 0xffffffff;
LAB_800224dc:
          if (*(int *)(&lbl_8023D2AC + iVar4) == -1) {
            *(undefined4 *)(unaff_r13 + -0x62fc) = 0xffffffff;
          }
          else if (*(int *)(unaff_r13 + -0x62d8) == *(int *)(&lbl_8023D2AC + iVar4)) {
            *(undefined4 *)(unaff_r13 + -0x62fc) = 1;
          }
          else {
            *(undefined4 *)(unaff_r13 + -0x62fc) = 0xffffffff;
          }
        }
        else {
          if (*(int *)(unaff_r13 + -0x62dc) != iVar7) {
            *(undefined4 *)(unaff_r13 + -0x62fc) = 0xffffffff;
            goto LAB_800224dc;
          }
          *(undefined4 *)(unaff_r13 + -0x62fc) = 0;
        }
        uVar9 = *(uint *)(unaff_r13 + -0x62f8);
        uVar2 = *(uint *)(unaff_r13 + -0x62fc);
        if (uVar9 != uVar2) {
          *(undefined4 *)(unaff_r13 + -0x62f4) = 0;
        }
        if ((uVar2 == 0xffffffff) ||
           (*(int *)(unaff_r13 + -0x62f0) != *(int *)(unaff_r13 + -0x62dc + uVar2 * 4))) {
          iVar4 = *(int *)(unaff_r13 + -0x62f0);
          if (iVar4 == -1) {
            if (uVar9 != 0xffffffff) {
              *(undefined4 *)(unaff_r13 + -0x62dc + uVar9 * 4) = 0xffffffff;
            }
          }
          else if (uVar2 == 0xffffffff) {
            fn_80042FE8(iVar4,0);
          }
          else {
            fn_80042FE8(iVar4,uVar2 ^ 1);
          }
        }
      }
      fn_801E5FE4();
      fn_8022A5D8(1,4,5,0);
      fn_801A8D38(5);
      fn_802119B0((double)*(float *)(unaff_r2 + -0x7dd8),(double)*(float *)(unaff_r2 + -0x7dc4),
                   (double)*(float *)(unaff_r2 + -0x7dd8),(double)*(float *)(unaff_r2 + -0x7dc8),
                   (double)*(float *)(unaff_r2 + -0x7dc0),(double)*(float *)(unaff_r2 + -0x7d5c),
                   auStack_74);
      fn_8022B4B8(auStack_74,1);
      fn_801ED3F4(lbl_8030242C);
      fn_801A91D4(0xb,0xff - (local_a4 & 0xff) & 0xff,1);
      fn_80226EA0(0,0,0x280,0x1e0);
      fn_80226FA4(0x280,0x1e0,4,0);
      fn_802276AC(uVar5,1);
      fn_802266B0();
      fn_80228474(*(int *)(unaff_r13 + -0x5248) * 0x20 + -0x7f9c39c8,uVar5,0x280,0x1e0,4,0,0,0);
      dVar11 = (double)*(float *)(unaff_r2 + -0x7dd8);
      fn_80228730(dVar11,dVar11,dVar11,*(int *)(unaff_r13 + -0x5248) * 0x20 + -0x7f9c39c8,1,1,0,0,0
                  );
      fn_8022A5D8(1,4,5,0);
      if ((*(int *)(unaff_r13 + -0x62f8) != -1) &&
         (iVar4 = *(int *)(unaff_r13 + -0x62f4), iVar4 != 0xff)) {
        fn_801ED3F4(*(undefined4 *)(unaff_r13 + -0x62d4 + *(int *)(unaff_r13 + -0x62f8) * 4));
        local_134 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d78) >> 8),-1 - (char)iVar4
                            );
        local_130 = local_134;
        fn_801A852C(&local_130,0,0,0x80000000);
        if (*(int *)(unaff_r13 + -0x5ddc) == 0) {
          fn_801A8FE8(&lbl_8023D4F8,&lbl_8023D4E0,0,0,5);
        }
        else {
          fn_801A8FE8(&lbl_8023D4F8,&lbl_8023D4C0,0,0,5);
        }
      }
      if ((*(int *)(unaff_r13 + -0x62fc) != -1) &&
         (iVar4 = *(int *)(unaff_r13 + -0x62f4), iVar4 != 0)) {
        fn_801ED3F4(*(undefined4 *)(unaff_r13 + -0x62d4 + *(int *)(unaff_r13 + -0x62fc) * 4));
        local_13c = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d74) >> 8),(char)iVar4);
        local_138 = local_13c;
        fn_801A852C(&local_138,0,0,0x80000000);
        if (*(int *)(unaff_r13 + -0x5ddc) == 0) {
          fn_801A8FE8(&lbl_8023D4F8,&lbl_8023D4E0,0,0,5);
        }
        else {
          fn_801A8FE8(&lbl_8023D4F8,&lbl_8023D4C0,0,0,5);
        }
      }
      fn_80228AFC(*(int *)(unaff_r13 + -0x5248) * 0x20 + -0x7f9c39c8,0);
      fn_80228AFC(&lbl_8063B260,7);
      fn_80228AFC(&lbl_8063B31C,1);
      local_140 = local_a4;
      fn_80229D8C(1,&local_140);
      fn_80229FA4(0,0,1,2,0);
      fn_80229F4C(0,0,0);
      fn_801ECB40(*(int *)(unaff_r13 + -0x5de0) + 1U & 0xff);
      fn_801ECB40(*(uint *)(unaff_r13 + -0x5de0) & 0xff);
      fn_80229E74(0,0xd);
      fn_8022A5D8(1,4,5,3);
      fn_8022A118(0,0,0,0xff);
      fn_80023230(0,1,4,0x3c);
      fn_80229C0C(0,0,0,0,1,0);
      fn_80229CCC(0,0,0,0,1,0);
      fn_80229B88(0,7,4,1,7);
      fn_80229664(0,0,1);
      fn_80229490(0,0,0);
      fn_80229330(1,local_8c,2);
      fn_80229810(0,0,1,0,1);
      fn_802262B8(1);
      fn_8022A2F4(1);
      fn_8022979C(1);
      fn_80229B08(0,0xf,0xe,8,0xf);
      fn_801A8FE8(&lbl_8023D4F8,&lbl_8023D4E0,0,0,5);
      fn_801A8FE8(&lbl_8023D4F8,&lbl_8023D540,0,0,5);
      fn_801A8FE8(&lbl_8023D4F8,&lbl_8023D520,0,0,5);
      fn_80229B08(0,0xf,8,0xc,0xf);
      fn_801A8FE8(&lbl_8023D4F8,&lbl_8023D4E0,0,0,5);
      fn_8022A044(7,0,0,3,0xff);
      fn_801ED3F4(lbl_8030242C);
      fn_801ECC4C();
      fn_8022979C(0);
      fn_802297C8(0);
      fn_8022A5D8(1,4,5,0);
      goto LAB_800231d0;
    }
  }
  else if (param_1 != 0x1e) {
    if (param_1 < 0x1e) {
      if (param_1 == 0x17) goto LAB_800231d0;
      if (param_1 < 0x17) {
        if (param_1 == 0x15) {
          fn_801A91D4(0xd,param_3,1);
          fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
          local_16c = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x439c) >> 8),uVar10);
          puVar1 = (undefined1 *)((int)&lbl_8023DBDC + param_2 * 4 + 2);
          *puVar1 = 0;
          local_168 = local_16c;
          fn_801A8660(100,0xb4,0x1b8,0xdc,0xffffffff,&local_168);
          fn_801E3AA4(0);
          fn_801E5AD0(99);
          local_170 = local_94;
          fn_801E3A34(&local_170);
          fn_801E5430(0x140,0xbe);
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Choose_Room_8023dbf8);
          local_174 = lbl_8023DBDC;
          fn_801E3A34(&local_174);
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Alex_Room_94_8023dc2c);
          local_178 = lbl_8023DBE0;
          fn_801E3A34(&local_178);
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Edward_Room_271_8023dc3c);
          local_17c = lbl_8023DBE4;
          fn_801E3A34(&local_17c);
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Edward_Room_275_8023dc50);
          local_180 = lbl_8023DBE8;
          fn_801E3A34(&local_180);
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Edward_Room_278_8023dc64);
          local_184 = lbl_8023DBEC;
          fn_801E3A34(&local_184);
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Edward_Room_282_8023dc78);
          local_188 = lbl_8023DBF0;
          fn_801E3A34(&local_188);
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Abdule_Room_213_8023dc8c);
          local_18c = lbl_8023DBF4;
          fn_801E3A34(&local_18c);
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Major_Mike_Room_219_8023dca0);
          *puVar1 = 0xff;
          goto LAB_800231d0;
        }
        if (param_1 < 0x15) {
          if (param_1 < 0x14) {
            fn_801ED3F4(lbl_80302428);
            if (*(int *)(unaff_r13 + -0x5ddc) == 1) {
              fn_801A9250(2,param_3,1);
            }
            else {
              fn_801A91D4(2,param_3,1);
            }
            fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
          }
          else {
            fn_801A91D4(0xd,param_3,1);
            fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
            local_154 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x43a0) >> 8),uVar10);
            puVar1 = (undefined1 *)((int)&lbl_8023DBD0 + param_2 * 4 + 2);
            *puVar1 = 0;
            local_150 = local_154;
            fn_801A8660(100,0xb4,0x1b8,0x78,0xffffffff,&local_150);
            fn_801E3AA4(0);
            fn_801E5AD0(99);
            local_158 = local_94;
            fn_801E3A34(&local_158);
            fn_801E5430(0x140,0xbe);
            fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Choose_Room_8023dbf8);
            local_15c = lbl_8023DBD0;
            fn_801E3A34(&local_15c);
            fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Room_261_8023dc08);
            local_160 = lbl_8023DBD4;
            fn_801E3A34(&local_160);
            fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Room_264_8023dc14);
            local_164 = lbl_8023DBD8;
            fn_801E3A34(&local_164);
            fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Room_266_8023dc20);
            *puVar1 = 0xff;
          }
          goto LAB_800231d0;
        }
LAB_80022e60:
        if (param_1 == 0xb) {
          fn_801A91D4(5,param_3,1);
        }
        else {
          fn_801A91D4(0xd,param_3,1);
        }
        fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
        local_194 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x4398) >> 8),uVar10);
        local_190 = local_194;
        fn_801A8660(100,0xb4,0x1b8,0x78,0xffffffff,&local_190);
        fn_801E3AA4(0);
        fn_801E5AD0(99);
        local_198 = local_94;
        fn_801E3A34(&local_198);
        fn_801E5430(0x140,0xbe);
        fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_CHOOSE_YOUR_FATE_8023dcb4);
        iVar4 = param_2 + 1;
        if (iVar4 == 2) {
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s__au_u__i28_8023dcd4);
        }
        else if (iVar4 < 2) {
          if (0 < iVar4) {
            fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s__ac_c__i27_8023dcc8);
          }
        }
        else if (iVar4 < 4) {
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s__ax_x__i29_8023dce0);
        }
        goto LAB_800231d0;
      }
      if (param_1 == 0x1a) {
        fn_801ED3F4(lbl_80302428);
        local_1b8 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x7d64) >> 8),uVar10);
        local_1b4 = local_1b8;
        fn_801A852C(&local_1b4,0,3,0x80000000);
        fn_801A8FE8(&lbl_802515D0,&lbl_8023D4E0,0,0,5);
        goto LAB_800231d0;
      }
      if ((0x19 < param_1) || (0x18 < param_1)) goto LAB_800231d0;
    }
    else {
      if (param_1 == 0xfc) {
        fn_801A91D4(0xd,param_3,1);
        goto LAB_800231d0;
      }
      if (0xfb < param_1) {
        if (param_1 == 0xfe) {
          fn_801A91D4(0x19,param_3,1);
        }
        else if (param_1 < 0xfe) {
          fn_801A91D4(0xc,param_3,1);
        }
        goto LAB_800231d0;
      }
      if (param_1 == 0xfa) {
        fn_801A91D4(5,param_3,1);
        fn_801A90BC(&lbl_802515D0,&lbl_8023D020);
        local_1a0 = CONCAT31((u32)((uint)*(undefined4 *)(unaff_r2 + -0x4394) >> 8),uVar10);
        local_19c = local_1a0;
        fn_801A8660(100,0xb4,0x1b8,0x78,0xffffffff,&local_19c);
        fn_801E3AA4(0);
        fn_801E5AD0(99);
        local_1a4 = local_94;
        fn_801E3A34(&local_1a4);
        fn_801E5430(0x140,0xbe);
        fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),
                     s_Do_you_want_to_set_the__ar_Etern_8023dcec);
        if (param_2 == 1) {
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s__ayYes__awNo_8023dd20);
        }
        else {
          fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s__awYes__ayNo_8023dd30);
        }
        goto LAB_800231d0;
      }
      if (0xf9 < param_1) {
        fn_801A91D4(0xc,0xff,1);
        local_30 = (double)CONCAT44(0x43300000,param_3 & 0xff);
        iVar4 = (int)(*(float *)(unaff_r2 + -0x7d9c) *
                     (float)(local_30 - *(double *)(unaff_r2 + -0x7d58)));
        local_28 = (longlong)iVar4;
        fn_801A91D4(0xb,iVar4,1);
        goto LAB_800231d0;
      }
      if (0x1f < param_1) goto LAB_800231d0;
    }
    goto LAB_80023028;
  }
  fn_80021234(param_3);
LAB_800231d0:
  if (*(int *)(unaff_r13 + -0x63e4) != 0) {
    fn_801E3AA4(0);
    fn_801E5AD0(99);
    fn_801E5430(0x140,0x32);
    pcVar8 = s__agPLAYBACK_8023dd5c;
    if (*(int *)(unaff_r13 + -0x63e4) == 1) {
      pcVar8 = s__arRECORD_8023dd50;
    }
    fn_801E56AC((double)*(float *)(unaff_r2 + -0x7dc0),s_Controller___s_8023dd40,pcVar8);
  }
  return;
}

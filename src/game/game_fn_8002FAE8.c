typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef int bool;
typedef int s32;
#define false 0
#define true 1

extern int lbl_8064D18C;
extern const int lbl_80238CD0[];
extern const double lbl_8064E038;
extern const float lbl_8064E04C, lbl_8064E05C, lbl_8064E064, lbl_8064E070;
extern const float lbl_8064E114, lbl_8064E120, lbl_8064E138, lbl_8064E13C;
extern const float lbl_8064E140, lbl_8064E144, lbl_8064E148, lbl_8064E14C;
extern const float lbl_8064E150, lbl_8064E154, lbl_8064E158;
extern const undefined4 lbl_80651914;
extern const undefined2 lbl_80651918;

extern int fn_80005278();
extern int fn_80031544(); extern int fn_80031694(); extern int fn_800317AC();
extern int fn_80031948(); extern int fn_80031A00(); extern int fn_80031BE0();
extern int fn_80031C78(); extern int fn_80031D24(); extern int fn_80035628(void*);
extern int fn_800359A0(); extern int fn_80066D04(); extern int fn_80071DD8();
extern int fn_800C43AC(); extern int fn_8011EB04(void *); extern void fn_8011F114();
extern int fn_8011F598(); extern int fn_8011F6A4(); extern int fn_8011FAF4();
extern int fn_80120AD0(); extern void fn_8012B690(); extern int fn_8013F4D0();
extern int fn_8014317C(); extern int fn_8014CBC0(); extern int fn_80178E94();
extern int fn_801858E0(); extern int fn_80185AE8(); extern int fn_801A717C();
extern void fn_801A7228(); extern void fn_801A7470(); extern void fn_801A74A0();
extern void fn_801A74A8(); extern int fn_801A74D8(); extern void fn_801A7518();
extern void fn_801A7538(); extern int fn_801A7588(); extern void fn_801A764C();
extern int fn_801A7668(); extern int fn_801A7670(); extern int fn_801AC9F4();
extern int fn_801CEB2C(); extern int fn_801D1B10(); extern int fn_801D38BC();
extern int fn_801D38E8(); extern int fn_801D39E0(); extern int fn_801DD0A8();
extern int fn_801E8328(); extern int fn_801E8328(); extern s32 fn_802006D4();
extern int fn_80200C10(void *); extern int fn_80200C38(); extern void fn_8020104C(int, void*, void*, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void *)(b), (void *)(c), (int)(d), (e))
extern unsigned long long fn_8020123C(); extern void *fn_80201814(); extern int fn_80201AE4(void);
extern int fn_80201B44(); extern int fn_80201B54(); extern int fn_80201B5C(void*);
#define fn_80201B5C(a) fn_80201B5C((void*)(a))
extern void *fn_80201B8C(); extern void *fn_80201B9C(); extern void* fn_80201BC0(void*);
extern void *fn_80201BC8(); extern void fn_80201D14(void *, int); extern void fn_80201D1C(void *, s32);
extern void fn_80201D2C(void *, int); extern void fn_80201D34(void *, s32);
#define FN_80201E78_RETURN void
#define FN_80201E78_PARAMETERS void*, void*
extern FN_80201E78_RETURN fn_80201E78(FN_80201E78_PARAMETERS);
extern int fn_80201EB8(); extern int fn_80202160(); extern int fn_80204578();
extern void fn_80211A6C(); extern float fn_80211B08();

undefined4 fn_8002FAE8(undefined4 param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char cVar17;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  char cVar18;
  short sVar16;
  int extraout_r4;
  int extraout_r4_03;
  undefined4 *puVar19;
  undefined4 unaff_r14;
  undefined4 unaff_r15;
  undefined4 uVar20;
  undefined4 unaff_r16;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 unaff_r17;
  undefined4 uVar23;
  int *piVar24;
  double dVar25;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined2 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0 [3];
  int local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  int local_19c;
  undefined1 auStack_198 [12];
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  int local_180;
  int local_17c;
  float local_178;
  undefined1 auStack_174 [12];
  int local_168;
  int local_164;
  float local_160;
  int local_15c;
  int local_158;
  float local_154;
  int local_150;
  int local_14c;
  int local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int local_120;
  int local_11c;
  int local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined1 auStack_108 [40];
  undefined1 auStack_e0 [40];
  undefined1 auStack_b8 [40];
  undefined1 auStack_90 [8];
  int local_88;
  int local_84;
  int local_80;
  undefined4 local_68;
  uint uStack_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  
  iVar4 = fn_80200C10((void*)param_3);
  iVar5 = (int)fn_80201B8C(param_1);
  piVar24 = *(int **)(iVar5 + 0x40);
  uVar6 = fn_80201B54(param_1);
  cVar17 = fn_80202160(param_1);
  if (param_2 == 0) {
    if (iVar4 == 1) {
      if (piVar24[1] == lbl_8064D18C) {
        if (piVar24[4] < 1) {
          fn_8020123C(0x62,uVar6,uVar6,0);
        }
        else {
          fn_8020104C(0x62,uVar6,uVar6,0,(float)piVar24[4]);
        }
        fn_80201D2C((void*)param_1,1);
        fn_80201D14((void*)param_1,1);
      }
      else {
        fn_8020123C(0x39,uVar6,uVar6,0);
      }
      return 1;
    }
    if (iVar4 == 0x62) {
      if (piVar24[1] == lbl_8064D18C) {
        local_114 = lbl_80238CD0[12];
        local_110 = lbl_80238CD0[13];
        local_10c = lbl_80238CD0[14];
        iVar4 = (int)fn_80201814(piVar24[2]);
        iVar5 = (int)fn_80201814(piVar24[3]);
        if ((iVar4 == 0) || (iVar5 == 0)) {
          fn_8020104C(0x39,uVar6,uVar6,0,lbl_8064E064);
        }
        else {
          local_120 = lbl_80238CD0[15];
          local_11c = lbl_80238CD0[16];
          local_118 = lbl_80238CD0[17];
          fn_80201E78(&local_1b4,(void*)iVar5);
          piVar24[10] = local_1b4;
          piVar24[0xb] = local_1b0;
          piVar24[0xc] = local_1ac;
          uVar7 = (int)fn_80201BC8(iVar4);
          fn_80031544(iVar4,0x13,0);
          iVar8 = fn_80201B5C(iVar5);
          if ((iVar8 != 6) && (iVar8 = fn_80201B5C(iVar5), iVar8 != 0x39)) {
            fn_800317AC(iVar4,*piVar24);
          }
          iVar8 = fn_80201B5C(iVar5);
          if (((iVar8 == 0x39) && (iVar8 = (int)fn_80201BC8(iVar5), iVar8 != 0)) &&
             (iVar8 = fn_8011F6A4(iVar8,0,1,0xffffffff,auStack_90,1), iVar8 != -1)) {
            piVar24[10] = local_88;
            piVar24[0xb] = local_84;
            piVar24[0xc] = local_80;
          }
          if (*piVar24 == 0) {
            uVar9 = fn_80035628((void*)iVar4);
          }
          else {
            uVar9 = fn_801D38E8(piVar24[5]);
          }
          fn_8012B690(uVar7,&local_114,piVar24 + 7);
          if ((lbl_8064D18C != 0x61) ||
             (iVar8 = fn_80201AE4(), piVar24[2] != iVar8)) {
            local_120 = fn_80031BE0(iVar4,0x13,8,piVar24 + 7,uVar7,piVar24 + 0xd);
            local_11c = fn_80031BE0(iVar4,0x13,9,piVar24 + 7,uVar7,piVar24 + 0x10);
            local_118 = fn_80031BE0(iVar4,0x13,0,piVar24 + 7,uVar7,piVar24 + 0x13);
          }
          if (((local_120 == 0) && (local_11c == 0)) && (local_118 == 0)) {
            uVar10 = fn_8011FAF4(uVar7);
            uVar10 = uVar10 & 0x200;
            iVar8 = fn_80201B5C(iVar5);
            if (iVar8 == 0x39) {
              uVar7 = fn_80201B54(iVar5);
              fn_80031A00(0,piVar24 + 0x4a,uVar9,piVar24 + 7,uVar7,0,1,10,3,1,cVar17);
            }
            else {
              uVar21 = 0x14;
              uVar23 = 6;
              if (((uVar10 != 0) || (iVar5 = fn_80066D04(iVar4,8), iVar5 != 0)) &&
                 (iVar5 = fn_8011F598(uVar7,0x13,8,0xffffffff,auStack_b8,1), iVar5 != -1)) {
                fn_80031A00(0,piVar24 + 0x4a,uVar9,piVar24 + 7,piVar24[2],0x13,8,10,3,0,cVar17);
                uVar21 = 10;
                uVar23 = 3;
              }
              if (((uVar10 != 0) || (iVar5 = fn_80066D04(iVar4,9), iVar5 != 0)) &&
                 (iVar5 = fn_8011F598(uVar7,0x13,9,0xffffffff,auStack_e0,1), iVar5 != -1)) {
                fn_80031A00(0,piVar24 + 0x7b,uVar9,piVar24 + 7,piVar24[2],0x13,9,10,3,0,cVar17);
                uVar21 = 10;
                uVar23 = 3;
              }
              if ((uVar10 != 0) || (iVar4 = fn_80066D04(iVar4,0), iVar4 != 0)) {
                fn_80031A00(0,piVar24 + 0x19,uVar9,piVar24 + 7,piVar24[2],0x13,0,uVar21,uVar23,0,
                             cVar17);
              }
            }
            fn_8020104C(99,uVar6,uVar6,0,lbl_8064E140);
            fn_8020104C(0x39,uVar6,uVar6,0,lbl_8064E070);
          }
          else {
            if (local_120 != 0) {
              fn_80031A00(0,piVar24 + 0x4a,uVar9,piVar24 + 0xd,piVar24[2],0x13,8,10,3,0,cVar17);
              fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0xd),lbl_8064E13C);
            }
            if (local_11c != 0) {
              fn_80031A00(0,piVar24 + 0x7b,uVar9,piVar24 + 0x10,piVar24[2],0x13,9,10,3,0,cVar17);
              fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0x10),lbl_8064E13C);
            }
            if (local_118 != 0) {
              fn_80031A00(0,piVar24 + 0x19,uVar9,piVar24 + 0x13,piVar24[2],0x13,0,10,3,0,cVar17);
              fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0x13),lbl_8064E13C);
            }
            fn_8020104C(0x39,uVar6,uVar6,0,lbl_8064E120);
          }
        }
      }
      else {
        fn_8020123C(0x39,uVar6,uVar6,0);
      }
      return 1;
    }
    if (iVar4 == 0x3d) {
      fn_8020123C(0x39,uVar6,uVar6,0);
      return 1;
    }
    if (iVar4 == 0x39) {
      fn_801E8328(2,param_1);
      fn_80201D34((void*)param_1,0);
      fn_80201D1C((void*)param_1,1);
      return 1;
    }
    if (iVar4 == 0x92) {
      uVar6 = fn_80200C38((void*)param_3);
      if (*piVar24 == 0) {
        iVar5 = (int)fn_80201814(piVar24[2]);
        uVar7 = fn_80035628((void*)iVar5);
      }
      else {
        uVar7 = fn_801D38E8(piVar24[5]);
      }
      fn_80031C78(uVar6,uVar7);
      return 1;
    }
  }
  else {
    if (param_2 != 1) {
      return 0;
    }
    if (iVar4 == 99) {
      if (piVar24[1] == lbl_8064D18C) {
        iVar4 = (int)fn_80201814(piVar24[2]);
        if ((iVar4 != 0) && (iVar5 = (int)fn_80201814(piVar24[3]), iVar5 != 0)) {
          bVar2 = false;
          iVar8 = fn_80201B5C(iVar5);
          if ((iVar8 == 0x58) && (iVar5 = (int)fn_80201BC8(iVar5), iVar5 != 0)) {
            iVar8 = fn_8011EB04((void*)iVar5);
            if (iVar8 == 0x132) {
              local_138 = lbl_80238CD0[21];
              local_134 = lbl_80238CD0[22];
              local_130 = lbl_80238CD0[23];
              fn_8012B690(iVar5,&local_138,piVar24 + 10);
              bVar2 = true;
            }
            else if (iVar8 < 0x132) {
              if (iVar8 == 0x130) {
                local_12c = lbl_80238CD0[18];
                local_128 = lbl_80238CD0[19];
                local_124 = lbl_80238CD0[20];
                fn_8012B690(iVar5,&local_12c,piVar24 + 10);
                bVar2 = true;
              }
            }
            else if (iVar8 == 0x134) {
              local_144 = lbl_80238CD0[24];
              local_140 = lbl_80238CD0[25];
              local_13c = lbl_80238CD0[26];
              fn_8012B690(iVar5,&local_144,piVar24 + 10);
              bVar2 = true;
            }
          }
          if ((lbl_8064D18C != 0x61) ||
             (iVar5 = fn_80201AE4(), piVar24[2] != iVar5)) {
            uVar7 = (int)fn_80201BC8(iVar4);
            local_15c = piVar24[7];
            local_158 = piVar24[8];
            local_154 = (float)piVar24[9] + lbl_8064E114;
            local_168 = piVar24[10];
            local_164 = piVar24[0xb];
            local_160 = (float)piVar24[0xc] + lbl_8064E114;
            fn_8013F4D0(auStack_108,&local_15c,&local_168);
            iVar5 = fn_8014317C(auStack_108,&local_150,uVar7,0,0x20);
            if (iVar5 != 0) {
              fVar1 = lbl_8064E114;
              piVar24[10] = local_150;
              piVar24[0xb] = local_14c;
              piVar24[0xc] = local_148;
              piVar24[0xc] = (int)((float)piVar24[0xc] - fVar1);
              piVar24[6] = 1;
              if (lbl_8064D18C == 0x29) {
                piVar24[0xc] = *(const int *)&lbl_8064E138;
              }
            }
          }
          if (bVar2) {
            iVar5 = 1;
          }
          else {
            fn_80211A6C(piVar24 + 7,piVar24 + 10,auStack_174);
            dVar25 = (double)fn_80211B08(auStack_174);
            if ((double)lbl_8064E144 <= dVar25) {
              if ((double)lbl_8064E148 <= dVar25) {
                iVar5 = 2;
              }
              else {
                iVar5 = 1;
              }
            }
            else {
              iVar5 = 0;
            }
          }
          if (*piVar24 == 0) {
            uVar7 = fn_80035628((void*)iVar4);
          }
          else {
            uVar7 = fn_801D38E8(piVar24[5]);
          }
          fn_80031D24(piVar24 + 7,piVar24 + 10,uVar7,1,1,2,0x14,6,iVar5,cVar17);
          fn_8020104C(100,uVar6,uVar6,0,
                       lbl_8064E13C * (float)(iVar5 + 1) - lbl_8064E138);
          fn_801AC9F4(0x4a,100,piVar24 + 7,3);
        }
      }
      else {
        fn_8020123C(0x39,uVar6,uVar6,0);
      }
      return 1;
    }
    if (iVar4 == 100) {
      if (piVar24[1] == lbl_8064D18C) {
        uVar7 = fn_801A717C();
        iVar4 = (int)fn_80201B9C();
        local_1d4 = lbl_80651914;
        local_1d0 = lbl_80651918;
        iVar5 = piVar24[2];
        local_5c = (int)fn_80201814(iVar5);
        if (local_5c != 0) {
          uVar9 = (int)fn_80201BC8();
          if (*piVar24 == 0) {
            iVar8 = fn_80035628((void*)local_5c);
          }
          else {
            iVar8 = fn_801D38E8(piVar24[5]);
          }
          if (*piVar24 == 0) {
            local_1d8 = fn_801D39E0();
            fn_8014CBC0(piVar24 + 0x109);
            *(ushort *)((int)piVar24 + 0x452) = *(ushort *)((int)piVar24 + 0x452) | 2;
            fn_801E2B28(piVar24 + 0x109,piVar24 + 10,&local_1d8,0x20,0x1e);
          }
          local_58 = fn_80201EB8((void *)local_5c);
          if (piVar24[6] == 0) {
            fn_801858E0(piVar24 + 0xdd);
            *(undefined1 *)((int)piVar24 + 0x375) = 0x4b;
            *(undefined1 *)((int)piVar24 + 0x377) = 0xe7;
            fn_801D38BC(iVar8,piVar24 + 0xfb,piVar24 + 0xde);
            *(undefined1 *)(piVar24 + 0xe2) = 0xd;
            local_178 = lbl_8064E144;
            *(ushort *)(piVar24 + 0xe4) = (ushort)*(byte *)((int)piVar24 + 0x375);
            *(byte *)(piVar24 + 0xe3) = *(byte *)(piVar24 + 0xe3) | 2;
            *(undefined1 *)((int)piVar24 + 0x38d) = 8;
            *(short *)(piVar24 + 0xdf) =
                 (short)((int)(0x5f - (uint)*(byte *)((int)piVar24 + 0x375)) /
                        (int)*(char *)(piVar24 + 0xe2));
            *(short *)((int)piVar24 + 0x37a) = *(short *)(piVar24 + 0xdf) + 10;
            piVar24[0x101] = (int)fn_80185AE8;
            local_180 = piVar24[10];
            local_17c = piVar24[0xb];
            piVar24[0x103] = local_180;
            local_178 = (float)piVar24[0xc] + local_178;
            piVar24[0x104] = local_17c;
            piVar24[0x105] = (int)local_178;
            fn_80005278(piVar24 + 0x106,&local_1d4,6);
            piVar24[0x102] = 0;
            *(undefined1 *)((int)piVar24 + 0x41e) = 4;
            if (cVar17 != '\0') {
              *(byte *)((int)piVar24 + 0x41e) = *(byte *)((int)piVar24 + 0x41e) | 8;
            }
            fn_801E8328(0x10,piVar24 + 0xdd);
          }
          fn_801A74A0(uVar7,iVar5);
          fn_801A7588(uVar7,0x8000);
          if (*piVar24 == 0) {
            local_60 = 0;
            if (piVar24[6] == 0) {
              for (; iVar4 != 0; iVar4 = (int)fn_80201BC0((void*)iVar4)) {
                iVar11 = (int)fn_80201BC8(iVar4);
                if (iVar11 == 0) {
                  puVar19 = &local_1cc;
                  local_1cc = lbl_80238CD0[27];
                  local_1c8 = lbl_80238CD0[28];
                  local_1c4 = lbl_80238CD0[29];
                }
                else {
                  fn_8011F114(local_1c0, (void*)iVar11);
                  puVar19 = local_1c0;
                }
                local_18c = *puVar19;
                local_188 = puVar19[1];
                local_184 = puVar19[2];
                iVar12 = fn_80201EB8((void *)iVar4);
                iVar13 = fn_80201B54(iVar4);
                if ((((local_58 == iVar12) &&
                     (uVar10 = fn_80178E94(piVar24 + 10,&local_18c), uVar10 < 0xbe)) &&
                    (local_5c != iVar4)) &&
                   ((extraout_r4 = fn_8020123C(0x65,iVar5,iVar13,0), extraout_r4 == 1 && (piVar24[6] == 0)))) {
                  iVar12 = fn_80066D04(iVar4,2);
                  if (iVar12 == 0) {
                    uVar21 = 1;
                    uVar23 = 1;
                  }
                  else {
                    uVar21 = 2;
                    uVar23 = 2;
                  }
                  iVar12 = fn_80066D04(iVar4,3);
                  if (iVar12 == 0) {
                    uVar22 = 1;
                    uVar20 = 1;
                  }
                  else {
                    uVar22 = 3;
                    uVar20 = 3;
                  }
                  iVar12 = fn_80031BE0(iVar4,0x18,uVar23,piVar24 + 10,uVar9,piVar24 + 0xd);
                  iVar14 = fn_80031BE0(iVar4,0x1a,uVar21,piVar24 + 10,uVar9,piVar24 + 0x10);
                  iVar15 = fn_80031BE0(iVar4,0x19,uVar22,piVar24 + 10,uVar9,piVar24 + 0x13);
                  local_54 = fn_80031BE0(iVar4,0x17,uVar20,piVar24 + 10,uVar9,piVar24 + 0x16);
                  if (((iVar12 == 0) && (iVar14 == 0)) && ((iVar15 == 0 && (local_54 == 0)))) {
                    uVar10 = 0;
                    fn_801A74A8(uVar7,iVar13);
                    fn_801AC9F4(0x4a,100,&local_18c,3);
                    cVar18 = fn_80204578(iVar4,piVar24 + 10);
                    if (cVar18 == '\0') {
                      fn_801A7470(uVar7,0xc);
                    }
                    else {
                      fn_8020123C(0x37,iVar5,iVar13,0);
                      fn_801A7470(uVar7,0xb);
                    }
                    fn_800359A0(iVar4,local_5c);
                    if (iVar8 == 2) {
                      fn_801A7538(uVar7,5);
                      fn_801A7518(uVar7,5);
                      fn_801A74D8(uVar7,0x400000);
                      uVar10 = fn_8020123C(0x27,iVar5,iVar13,uVar7);
                      if ((uVar10 & 1) != 0) {
                        fn_8020123C(0x67,iVar5,iVar13,uVar7);
                        fn_8020104C(0x68,iVar5,iVar13,uVar7,lbl_8064E05C)
                        ;
                        fn_80120AD0((double)lbl_8064E064,
                                     (double)lbl_8064E150,iVar11,0,100,10);
                      }
                    }
                    else if (iVar8 < 2) {
                      if (0 < iVar8) {
                        fn_801A7538(uVar7,1);
                        fn_801A7518(uVar7,10);
                        fn_801A74D8(uVar7,0x400000);
                        fn_8020123C(0x27,iVar5,iVar13,uVar7);
                        fn_801A7538(uVar7,8);
                        fn_801A7518(uVar7,30000);
                        fn_801A7470(uVar7,0xffffffff);
                        fn_801A764C(uVar7,piVar24 + 10);
                        uVar10 = fn_8020123C(0x27,iVar5,iVar13,uVar7);
                        if ((uVar10 & 1) != 0) {
                          fn_80120AD0((double)lbl_8064E064,
                                       (double)lbl_8064E14C,iVar11,0,100,0x22);
                        }
                      }
                    }
                    else if (iVar8 < 4) {
                      iVar12 = fn_80201AE4();
                      if ((iVar13 == iVar12) || (iVar14 = fn_80201B44(), iVar13 == iVar14)) {
                        fn_8020123C(0x86,iVar5,iVar12,1);
                        fn_8020104C(0x86,iVar5,iVar12,0,lbl_8064E04C);
                      }
                      fn_801A7538(uVar7,3);
                      fn_801A7518(uVar7,5);
                      fn_801A74D8(uVar7,0x400000);
                      uVar10 = fn_8020123C(0x27,iVar5,iVar13,uVar7);
                      if ((uVar10 & 1) != 0) {
                        fn_80120AD0((double)lbl_8064E064,
                                     (double)lbl_8064E154,iVar11,0,100,0x12);
                      }
                    }
                    if ((uVar10 & 1) != 0) {
                      fn_80031A00(1,piVar24 + 0x19,iVar8,piVar24 + 10,iVar13,0x18,uVar23,10,3,0,
                                   cVar17);
                      fn_80031A00(1,piVar24 + 0x4a,iVar8,piVar24 + 10,iVar13,0x1a,uVar21,10,3,0,
                                   cVar17);
                      fn_80031A00(1,piVar24 + 0x7b,iVar8,piVar24 + 10,iVar13,0x19,uVar22,10,3,0,
                                   cVar17);
                      fn_80031A00(1,piVar24 + 0xac,iVar8,piVar24 + 10,iVar13,0x17,uVar20,10,3,0,
                                   cVar17);
                      local_60 = 1;
                    }
                  }
                  else {
                    if (iVar12 != 0) {
                      fn_80031A00(0,piVar24 + 0x19,iVar8,piVar24 + 0xd,iVar13,0x18,uVar23,10,3,0,
                                   cVar17);
                      fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0xd),
                                   lbl_8064E13C);
                    }
                    if (iVar14 != 0) {
                      fn_80031A00(0,piVar24 + 0x4a,iVar8,piVar24 + 0x10,iVar13,0x1a,uVar21,10,3,0,
                                   cVar17);
                      fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0x10),
                                   lbl_8064E13C);
                    }
                    if (iVar15 != 0) {
                      fn_80031A00(0,piVar24 + 0x7b,iVar8,piVar24 + 0x13,iVar13,0x19,uVar22,10,3,0,
                                   cVar17);
                      fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0x13),
                                   lbl_8064E13C);
                    }
                    if (local_54 != 0) {
                      fn_80031A00(0,piVar24 + 0xac,iVar8,piVar24 + 0x16,iVar13,0x17,uVar20,10,3,0,
                                   cVar17);
                      fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0x16),
                                   lbl_8064E13C);
                    }
                    piVar24[6] = 1;
                  }
                }
              }
              if (piVar24[6] != 0) {
                fn_802006D4(uVar6,uVar6,0xffffffff,0x39,0);
                fn_8020104C(0x39,uVar6,uVar6,0,lbl_8064E120);
              }
            }
            if (local_58 == lbl_8064D18C) {
              if (local_60 == 0) {
                fn_80031948(piVar24 + 10,iVar8);
                fn_80031694(piVar24 + 10,1,iVar8);
              }
              else {
                fn_80031694(piVar24 + 10,0,iVar8);
              }
            }
          }
          else if (*piVar24 == 1) {
            iVar11 = piVar24[3];
            iVar4 = (int)fn_80201814(iVar11);
            if (iVar4 != 0) {
              (int)fn_80201BC8();
              iVar12 = fn_80201EB8((void *)iVar4);
              iVar13 = fn_80201B5C(iVar4);
              uVar3 = __cntlzw(0x3f - iVar13);
              uVar10 = 0;
              fn_800C43AC(auStack_198,iVar4);
              if ((local_58 == iVar12) &&
                 ((((uVar3 >> 5 != 0 ||
                    (uVar3 = fn_80178E94(piVar24 + 10,auStack_198), uVar3 < 0xbe)) &&
                   (local_5c != iVar4)) &&
                  ((extraout_r4_03 = fn_8020123C(0x3b,iVar5,iVar11,1), extraout_r4_03 == 1 && (piVar24[6] == 0))))))
              {
                local_1a8 = lbl_80238CD0[30];
                local_1a4 = lbl_80238CD0[31];
                local_1a0 = lbl_80238CD0[32];
                local_19c = lbl_80238CD0[33];
                iVar12 = fn_80201B5C(iVar4);
                if (iVar12 != 6) {
                  iVar12 = fn_80066D04(iVar4,2);
                  if (iVar12 == 0) {
                    unaff_r15 = 1;
                    unaff_r14 = 1;
                  }
                  else {
                    unaff_r15 = 2;
                    unaff_r14 = 2;
                  }
                  iVar12 = fn_80066D04(iVar4,3);
                  if (iVar12 == 0) {
                    unaff_r16 = 1;
                    unaff_r17 = 1;
                  }
                  else {
                    unaff_r16 = 3;
                    unaff_r17 = 3;
                  }
                  if ((lbl_8064D18C != 0x61) ||
                     (iVar12 = fn_80201AE4(), piVar24[2] != iVar12)) {
                    local_1a8 = fn_80031BE0(iVar4,0x18,unaff_r14,piVar24 + 10,uVar9,piVar24 + 0xd);
                    local_1a4 = fn_80031BE0(iVar4,0x1a,unaff_r15,piVar24 + 10,uVar9,piVar24 + 0x10)
                    ;
                    local_1a0 = fn_80031BE0(iVar4,0x19,unaff_r16,piVar24 + 10,uVar9,piVar24 + 0x13)
                    ;
                    local_19c = fn_80031BE0(iVar4,0x17,unaff_r17,piVar24 + 10,uVar9,piVar24 + 0x16)
                    ;
                  }
                  if ((((local_1a8 != 0) || (local_1a4 != 0)) || (local_1a0 != 0)) ||
                     (local_19c != 0)) {
                    if (local_1a8 != 0) {
                      fn_80031A00(0,piVar24 + 0x19,iVar8,piVar24 + 0xd,iVar11,0x18,unaff_r14,10,3,0
                                   ,cVar17);
                      fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0xd),
                                   lbl_8064E13C);
                    }
                    if (local_1a4 != 0) {
                      fn_80031A00(0,piVar24 + 0x4a,iVar8,piVar24 + 0x10,iVar11,0x1a,unaff_r15,10,3,
                                   0,cVar17);
                      fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0x10),
                                   lbl_8064E13C);
                    }
                    if (local_1a0 != 0) {
                      fn_80031A00(0,piVar24 + 0x7b,iVar8,piVar24 + 0x13,iVar11,0x19,unaff_r16,10,3,
                                   0,cVar17);
                      fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0x13),
                                   lbl_8064E13C);
                    }
                    if (local_19c != 0) {
                      fn_80031A00(0,piVar24 + 0xac,iVar8,piVar24 + 0x16,iVar11,0x17,unaff_r17,10,3,
                                   0,cVar17);
                      fn_8020104C(0x92,uVar6,uVar6,(unsigned int)(piVar24 + 0x16),
                                   lbl_8064E13C);
                    }
                    piVar24[6] = 1;
                    fn_802006D4(uVar6,uVar6,0xffffffff,0x39,0);
                    fn_8020104C(0x39,uVar6,uVar6,0,lbl_8064E120);
                  }
                }
                if (piVar24[6] == 0) {
                  fn_801A74A8(uVar7,iVar11);
                  fn_801AC9F4(0x4a,100,auStack_198,3);
                  fn_800359A0(iVar4,local_5c);
                  fn_801A7538(uVar7,1);
                  sVar16 = fn_801CEB2C(piVar24[5]);
                  iVar12 = (int)sVar16;
                  uVar10 = (iVar12 >> 1) + 1U & 0xff;
                  sVar16 = (short)(iVar12 >> 1);
                  if ((piVar24[5] & 0xfU) == 8) {
                    iVar13 = (int)(short)(sVar16 * 0xf);
                    iVar14 = fn_80201B5C(iVar4);
                    if (iVar14 != 0x58) {
                      fn_801DD0A8(piVar24[5],iVar4,0);
                    }
                  }
                  else {
                    uVar6 = fn_80035628((void*)iVar4);
                    iVar13 = fn_801D1B10((int)(short)(sVar16 * 10),uVar6,iVar8,uVar10);
                  }
                  iVar14 = fn_80201B44();
                  if ((iVar11 != iVar14) && (iVar14 = fn_80071DD8(), iVar14 != 0)) {
                    iVar13 = 1;
                  }
                  fn_801A7518(uVar7,iVar13);
                  fn_801A7588(uVar7,0x8000);
                  fn_801A764C(uVar7,piVar24 + 10);
                  fn_801A74D8(uVar7,0x800);
                  fn_801A74D8(uVar7,0x10000);
                  if (iVar12 == 5) {
                    fn_801A74D8(uVar7,0x80000);
                  }
                  else if (iVar12 < 5) {
                    if (iVar12 == 3) {
                      fn_801A74D8(uVar7,0x40000);
                    }
                  }
                  else if (iVar12 == 7) {
                    fn_801A74D8(uVar7,0x100000);
                  }
                  fn_801A7668(uVar7,iVar8);
                  fn_801A7670(uVar7,uVar10);
                  iVar12 = fn_80201B5C(iVar4);
                  if (iVar12 == 0x58) {
                    fn_8020104C(0xed,iVar5,iVar11,uVar7,lbl_8064E158);
                    uVar7 = 0;
                    uVar10 = 1;
                  }
                  else {
                    uVar10 = fn_8020123C(0xb,iVar5,iVar11,uVar7);
                  }
                  if ((((uVar10 & 1) != 0) && (iVar5 = fn_80201B5C(iVar4), iVar5 != 6)) &&
                     (iVar4 = fn_80201B5C(iVar4), iVar4 != 0x39)) {
                    fn_80031A00(1,piVar24 + 0x19,iVar8,piVar24 + 10,iVar11,0x18,unaff_r14,10,3,0,
                                 cVar17);
                    fn_80031A00(1,piVar24 + 0x4a,iVar8,piVar24 + 10,iVar11,0x1a,unaff_r15,10,3,0,
                                 cVar17);
                    fn_80031A00(1,piVar24 + 0x7b,iVar8,piVar24 + 10,iVar11,0x19,unaff_r16,10,3,0,
                                 cVar17);
                    fn_80031A00(1,piVar24 + 0xac,iVar8,piVar24 + 10,iVar11,0x17,unaff_r17,10,3,0,
                                 cVar17);
                  }
                }
              }
              if (((uVar10 & 1) == 0) && (lbl_8064D18C == local_58)) {
                fn_80031948(piVar24 + 10,iVar8);
                fn_80031694(piVar24 + 10,1,iVar8);
              }
            }
          }
        }
        fn_801A7228(uVar7);
      }
      else {
        fn_8020123C(0x39,uVar6,uVar6,0);
      }
      return 1;
    }
  }
  return 0;
}

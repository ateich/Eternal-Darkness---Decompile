
build/GEDE01/obj/game/game_fn_800614A8.o:     file format elf32-powerpc


Disassembly of section .text:

00000000 <fn_800614A8>:
       0:	94 21 fe d0 	stwu    r1,-304(r1)
       4:	7c 08 02 a6 	mflr    r0
       8:	3c e0 00 00 	lis     r7,0
			a: R_PPC_ADDR16_HA	lbl_80243C30
       c:	90 01 01 34 	stw     r0,308(r1)
      10:	bd e1 00 ec 	stmw    r15,236(r1)
      14:	7c b9 2b 78 	mr      r25,r5
      18:	7c 7d 1b 78 	mr      r29,r3
      1c:	7c 98 23 78 	mr      r24,r4
      20:	7c de 33 78 	mr      r30,r6
      24:	7f 23 cb 78 	mr      r3,r25
      28:	3a c7 00 00 	addi    r22,r7,0
			2a: R_PPC_ADDR16_LO	lbl_80243C30
      2c:	48 00 00 01 	bl      2c <fn_800614A8+0x2c>
			2c: R_PPC_REL24	fn_80200C10
      30:	7c 77 1b 78 	mr      r23,r3
      34:	7f a3 eb 78 	mr      r3,r29
      38:	48 00 00 01 	bl      38 <fn_800614A8+0x38>
			38: R_PPC_REL24	fn_80201BC8
      3c:	7c 60 1b 78 	mr      r0,r3
      40:	7f a3 eb 78 	mr      r3,r29
      44:	7c 1f 03 78 	mr      r31,r0
      48:	48 00 00 01 	bl      48 <fn_800614A8+0x48>
			48: R_PPC_REL24	fn_80201B8C
      4c:	7c 60 1b 78 	mr      r0,r3
      50:	7f a3 eb 78 	mr      r3,r29
      54:	7c 15 03 78 	mr      r21,r0
      58:	83 75 00 8c 	lwz     r27,140(r21)
      5c:	83 95 00 08 	lwz     r28,8(r21)
      60:	48 00 00 01 	bl      60 <fn_800614A8+0x60>
			60: R_PPC_REL24	fn_80201B94
      64:	7c 60 1b 78 	mr      r0,r3
      68:	7f a3 eb 78 	mr      r3,r29
      6c:	7c 11 03 78 	mr      r17,r0
      70:	48 00 00 01 	bl      70 <fn_800614A8+0x70>
			70: R_PPC_REL24	fn_80201B54
      74:	7c 7a 1b 78 	mr      r26,r3
      78:	7f e4 fb 78 	mr      r4,r31
      7c:	38 61 00 8c 	addi    r3,r1,140
      80:	48 00 00 01 	bl      80 <fn_800614A8+0x80>
			80: R_PPC_REL24	fn_8011F114
      84:	80 95 00 8c 	lwz     r4,140(r21)
      88:	7f a3 eb 78 	mr      r3,r29
      8c:	80 a0 00 00 	lwz     r5,0(0)
			8c: R_PPC_EMB_SDA21	lbl_8064D5A8
      90:	a8 15 00 9c 	lha     r0,156(r21)
      94:	8a 64 01 61 	lbz     r19,353(r4)
      98:	7e 85 02 14 	add     r20,r5,r0
      9c:	7e 73 07 74 	extsb   r19,r19
      a0:	48 00 00 01 	bl      a0 <fn_800614A8+0xa0>
			a0: R_PPC_REL24	fn_80201EB8
      a4:	2c 17 00 03 	cmpwi   r23,3
      a8:	7c 72 1b 78 	mr      r18,r3
      ac:	40 82 01 10 	bne     1bc <fn_800614A8+0x1bc>
      b0:	7f a3 eb 78 	mr      r3,r29
      b4:	3a 00 00 00 	li      r16,0
      b8:	38 80 00 03 	li      r4,3
      bc:	48 00 00 01 	bl      bc <fn_800614A8+0xbc>
			bc: R_PPC_REL24	fn_80066D04
      c0:	2c 03 00 00 	cmpwi   r3,0
      c4:	40 82 00 1c 	bne     e0 <fn_800614A8+0xe0>
      c8:	7f a3 eb 78 	mr      r3,r29
      cc:	38 80 00 02 	li      r4,2
      d0:	48 00 00 01 	bl      d0 <fn_800614A8+0xd0>
			d0: R_PPC_REL24	fn_80066D04
      d4:	2c 03 00 00 	cmpwi   r3,0
      d8:	40 82 00 08 	bne     e0 <fn_800614A8+0xe0>
      dc:	3a 00 00 01 	li      r16,1
      e0:	7f a3 eb 78 	mr      r3,r29
      e4:	7e 24 8b 78 	mr      r4,r17
      e8:	48 00 00 01 	bl      e8 <fn_800614A8+0xe8>
			e8: R_PPC_REL24	fn_8005E9E4
      ec:	7c 6f 1b 78 	mr      r15,r3
      f0:	7f a3 eb 78 	mr      r3,r29
      f4:	48 00 00 01 	bl      f4 <fn_800614A8+0xf4>
			f4: R_PPC_REL24	fn_800CC4DC
      f8:	a8 7b 01 50 	lha     r3,336(r27)
      fc:	2c 03 00 01 	cmpwi   r3,1
     100:	41 80 00 08 	blt     108 <fn_800614A8+0x108>
     104:	38 63 ff ff 	addi    r3,r3,-1
     108:	b0 7b 01 50 	sth     r3,336(r27)
     10c:	a8 7b 01 58 	lha     r3,344(r27)
     110:	2c 03 00 01 	cmpwi   r3,1
     114:	41 80 00 08 	blt     11c <fn_800614A8+0x11c>
     118:	38 63 ff ff 	addi    r3,r3,-1
     11c:	2c 0f 03 e8 	cmpwi   r15,1000
     120:	b0 7b 01 58 	sth     r3,344(r27)
     124:	41 81 00 1c 	bgt     140 <fn_800614A8+0x140>
     128:	80 75 00 8c 	lwz     r3,140(r21)
     12c:	80 03 00 00 	lwz     r0,0(r3)
     130:	54 00 02 11 	rlwinm. r0,r0,0,8,8
     134:	40 82 00 0c 	bne     140 <fn_800614A8+0x140>
     138:	2c 10 00 00 	cmpwi   r16,0
     13c:	41 82 00 18 	beq     154 <fn_800614A8+0x154>
     140:	a8 7b 01 4e 	lha     r3,334(r27)
     144:	2c 03 00 01 	cmpwi   r3,1
     148:	41 80 00 08 	blt     150 <fn_800614A8+0x150>
     14c:	38 63 ff ff 	addi    r3,r3,-1
     150:	b0 7b 01 4e 	sth     r3,334(r27)
     154:	a8 7c 00 86 	lha     r3,134(r28)
     158:	2c 03 00 01 	cmpwi   r3,1
     15c:	41 81 00 0c 	bgt     168 <fn_800614A8+0x168>
     160:	38 00 00 00 	li      r0,0
     164:	48 00 00 08 	b       16c <fn_800614A8+0x16c>
     168:	38 03 ff ff 	addi    r0,r3,-1
     16c:	b0 1c 00 86 	sth     r0,134(r28)
     170:	7f a3 eb 78 	mr      r3,r29
     174:	48 00 00 01 	bl      174 <fn_800614A8+0x174>
			174: R_PPC_REL24	fn_800C9C60
     178:	80 00 00 00 	lwz     r0,0(0)
			178: R_PPC_EMB_SDA21	lbl_8064D5A8
     17c:	54 00 06 3f 	clrlwi. r0,r0,24
     180:	40 82 00 0c 	bne     18c <fn_800614A8+0x18c>
     184:	7f a3 eb 78 	mr      r3,r29
     188:	48 00 00 01 	bl      188 <fn_800614A8+0x188>
			188: R_PPC_REL24	fn_800C9D68
     18c:	7f e3 fb 78 	mr      r3,r31
     190:	48 00 00 01 	bl      190 <fn_800614A8+0x190>
			190: R_PPC_REL24	fn_8013017C
     194:	54 60 06 73 	rlwinm. r0,r3,0,25,25
     198:	41 82 00 24 	beq     1bc <fn_800614A8+0x1bc>
     19c:	7f e3 fb 78 	mr      r3,r31
     1a0:	48 00 00 01 	bl      1a0 <fn_800614A8+0x1a0>
			1a0: R_PPC_REL24	fn_801305D4
     1a4:	2c 03 00 00 	cmpwi   r3,0
     1a8:	40 82 00 14 	bne     1bc <fn_800614A8+0x1bc>
     1ac:	7f e3 fb 78 	mr      r3,r31
     1b0:	38 80 00 40 	li      r4,64
     1b4:	38 a0 00 00 	li      r5,0
     1b8:	48 00 00 01 	bl      1b8 <fn_800614A8+0x1b8>
			1b8: R_PPC_REL24	fn_801301B0
     1bc:	2c 18 00 00 	cmpwi   r24,0
     1c0:	40 82 07 30 	bne     8f0 <fn_800614A8+0x8f0>
     1c4:	2c 17 00 01 	cmpwi   r23,1
     1c8:	40 82 00 48 	bne     210 <fn_800614A8+0x210>
     1cc:	48 00 00 01 	bl      1cc <fn_800614A8+0x1cc>
			1cc: R_PPC_REL24	fn_800FBFB0
     1d0:	54 60 e8 04 	slwi    r0,r3,29
     1d4:	54 65 0f fe 	srwi    r5,r3,31
     1d8:	7c 65 00 50 	subf    r3,r5,r0
     1dc:	38 00 00 1e 	li      r0,30
     1e0:	54 64 18 3e 	rotlwi  r4,r3,3
     1e4:	7f a3 eb 78 	mr      r3,r29
     1e8:	7c a4 2a 14 	add     r5,r4,r5
     1ec:	38 80 00 01 	li      r4,1
     1f0:	90 bc 00 78 	stw     r5,120(r28)
     1f4:	b0 1c 00 86 	sth     r0,134(r28)
     1f8:	48 00 00 01 	bl      1f8 <fn_800614A8+0x1f8>
			1f8: R_PPC_REL24	fn_80201D2C
     1fc:	7f a3 eb 78 	mr      r3,r29
     200:	38 80 00 01 	li      r4,1
     204:	48 00 00 01 	bl      204 <fn_800614A8+0x204>
			204: R_PPC_REL24	fn_80201D14
     208:	38 60 00 01 	li      r3,1
     20c:	48 00 18 08 	b       1a14 <fn_800614A8+0x1a14>
     210:	2c 17 00 f1 	cmpwi   r23,241
     214:	40 82 00 24 	bne     238 <fn_800614A8+0x238>
     218:	7e 43 93 78 	mr      r3,r18
     21c:	7f a4 eb 78 	mr      r4,r29
     220:	7f e5 fb 78 	mr      r5,r31
     224:	7e a6 ab 78 	mr      r6,r21
     228:	7f 27 cb 78 	mr      r7,r25
     22c:	48 00 00 01 	bl      22c <fn_800614A8+0x22c>
			22c: R_PPC_REL24	fn_8005EC6C
     230:	38 60 00 01 	li      r3,1
     234:	48 00 17 e0 	b       1a14 <fn_800614A8+0x1a14>
     238:	2c 17 00 f5 	cmpwi   r23,245
     23c:	40 82 00 24 	bne     260 <fn_800614A8+0x260>
     240:	7e 43 93 78 	mr      r3,r18
     244:	7f a4 eb 78 	mr      r4,r29
     248:	7f e5 fb 78 	mr      r5,r31
     24c:	7e a6 ab 78 	mr      r6,r21
     250:	7f 27 cb 78 	mr      r7,r25
     254:	48 00 00 01 	bl      254 <fn_800614A8+0x254>
			254: R_PPC_REL24	fn_8005EC6C
     258:	38 60 00 01 	li      r3,1
     25c:	48 00 17 b8 	b       1a14 <fn_800614A8+0x1a14>
     260:	2c 17 00 df 	cmpwi   r23,223
     264:	40 82 00 20 	bne     284 <fn_800614A8+0x284>
     268:	7e 43 93 78 	mr      r3,r18
     26c:	7f a4 eb 78 	mr      r4,r29
     270:	7f 25 cb 78 	mr      r5,r25
     274:	38 c1 00 8c 	addi    r6,r1,140
     278:	48 00 00 01 	bl      278 <fn_800614A8+0x278>
			278: R_PPC_REL24	fn_8005EA38
     27c:	38 60 00 01 	li      r3,1
     280:	48 00 17 94 	b       1a14 <fn_800614A8+0x1a14>
     284:	2c 17 00 08 	cmpwi   r23,8
     288:	40 82 00 38 	bne     2c0 <fn_800614A8+0x2c0>
     28c:	80 00 00 00 	lwz     r0,0(0)
			28c: R_PPC_EMB_SDA21	lbl_8064D18C
     290:	7c 12 00 00 	cmpw    r18,r0
     294:	41 82 00 14 	beq     2a8 <fn_800614A8+0x2a8>
     298:	7f a4 eb 78 	mr      r4,r29
     29c:	38 60 00 02 	li      r3,2
     2a0:	48 00 00 01 	bl      2a0 <fn_800614A8+0x2a0>
			2a0: R_PPC_REL24	fn_801E8328
     2a4:	48 00 00 14 	b       2b8 <fn_800614A8+0x2b8>
     2a8:	7f a3 eb 78 	mr      r3,r29
     2ac:	7f 24 cb 78 	mr      r4,r25
     2b0:	38 a0 03 c0 	li      r5,960
     2b4:	48 00 00 01 	bl      2b4 <fn_800614A8+0x2b4>
			2b4: R_PPC_REL24	fn_800CD094
     2b8:	38 60 00 01 	li      r3,1
     2bc:	48 00 17 58 	b       1a14 <fn_800614A8+0x1a14>
     2c0:	2c 17 00 3d 	cmpwi   r23,61
     2c4:	40 82 00 24 	bne     2e8 <fn_800614A8+0x2e8>
     2c8:	7f a3 eb 78 	mr      r3,r29
     2cc:	7f 64 db 78 	mr      r4,r27
     2d0:	48 00 00 01 	bl      2d0 <fn_800614A8+0x2d0>
			2d0: R_PPC_REL24	fn_800EA3A0
     2d4:	7f a3 eb 78 	mr      r3,r29
     2d8:	7f 64 db 78 	mr      r4,r27
     2dc:	48 00 00 01 	bl      2dc <fn_800614A8+0x2dc>
			2dc: R_PPC_REL24	fn_800BD2DC
     2e0:	38 60 00 01 	li      r3,1
     2e4:	48 00 17 30 	b       1a14 <fn_800614A8+0x1a14>
     2e8:	2c 17 00 3e 	cmpwi   r23,62
     2ec:	40 82 00 a8 	bne     394 <fn_800614A8+0x394>
     2f0:	7f a3 eb 78 	mr      r3,r29
     2f4:	48 00 00 01 	bl      2f4 <fn_800614A8+0x2f4>
			2f4: R_PPC_REL24	fn_80036D5C
     2f8:	54 60 01 09 	rlwinm. r0,r3,0,4,4
     2fc:	7c 64 1b 78 	mr      r4,r3
     300:	41 82 00 68 	beq     368 <fn_800614A8+0x368>
     304:	7f a3 eb 78 	mr      r3,r29
     308:	54 84 01 46 	rlwinm  r4,r4,0,5,3
     30c:	48 00 00 01 	bl      30c <fn_800614A8+0x30c>
			30c: R_PPC_REL24	fn_80036DA4
     310:	7f e3 fb 78 	mr      r3,r31
     314:	48 00 00 01 	bl      314 <fn_800614A8+0x314>
			314: R_PPC_REL24	fn_801261F4
     318:	80 80 00 00 	lwz     r4,0(0)
			318: R_PPC_EMB_SDA21	lbl_8064E610
     31c:	38 e1 00 18 	addi    r7,r1,24
     320:	81 20 00 00 	lwz     r9,0(0)
			320: R_PPC_EMB_SDA21	lbl_80651954
     324:	38 c1 00 20 	addi    r6,r1,32
     328:	80 00 00 00 	lwz     r0,0(0)
			328: R_PPC_EMB_SDA21	lbl_8064E60C
     32c:	38 a1 00 28 	addi    r5,r1,40
     330:	90 81 00 14 	stw     r4,20(r1)
     334:	7f e3 fb 78 	mr      r3,r31
     338:	39 00 00 04 	li      r8,4
     33c:	90 81 00 18 	stw     r4,24(r1)
     340:	38 80 00 0f 	li      r4,15
     344:	91 21 00 1c 	stw     r9,28(r1)
     348:	91 21 00 20 	stw     r9,32(r1)
     34c:	90 01 00 24 	stw     r0,36(r1)
     350:	90 01 00 28 	stw     r0,40(r1)
     354:	48 00 00 01 	bl      354 <fn_800614A8+0x354>
			354: R_PPC_REL24	fn_8012C62C
     358:	7f e3 fb 78 	mr      r3,r31
     35c:	38 80 00 00 	li      r4,0
     360:	38 a0 01 00 	li      r5,256
     364:	48 00 00 01 	bl      364 <fn_800614A8+0x364>
			364: R_PPC_REL24	fn_8011FA8C
     368:	7f a3 eb 78 	mr      r3,r29
     36c:	7f 64 db 78 	mr      r4,r27
     370:	48 00 00 01 	bl      370 <fn_800614A8+0x370>
			370: R_PPC_REL24	fn_800BD194
     374:	7f a3 eb 78 	mr      r3,r29
     378:	48 00 00 01 	bl      378 <fn_800614A8+0x378>
			378: R_PPC_REL24	fn_800C9E50
     37c:	38 00 00 00 	li      r0,0
     380:	7f 43 d3 78 	mr      r3,r26
     384:	98 1c 00 88 	stb     r0,136(r28)
     388:	48 00 00 01 	bl      388 <fn_800614A8+0x388>
			388: R_PPC_REL24	fn_801D14CC
     38c:	38 60 00 01 	li      r3,1
     390:	48 00 16 84 	b       1a14 <fn_800614A8+0x1a14>
     394:	2c 17 00 c9 	cmpwi   r23,201
     398:	40 82 00 5c 	bne     3f4 <fn_800614A8+0x3f4>
     39c:	48 00 00 01 	bl      39c <fn_800614A8+0x39c>
			39c: R_PPC_REL24	fn_8011FF38
     3a0:	2c 03 00 00 	cmpwi   r3,0
     3a4:	41 82 00 48 	beq     3ec <fn_800614A8+0x3ec>
     3a8:	7f e3 fb 78 	mr      r3,r31
     3ac:	38 80 00 00 	li      r4,0
     3b0:	3c a0 20 00 	lis     r5,8192
     3b4:	48 00 00 01 	bl      3b4 <fn_800614A8+0x3b4>
			3b4: R_PPC_REL24	fn_8011FA8C
     3b8:	38 00 00 00 	li      r0,0
     3bc:	c0 20 00 00 	lfs     f1,0(0)
			3bc: R_PPC_EMB_SDA21	lbl_8064E5BC
     3c0:	90 01 00 08 	stw     r0,8(r1)
     3c4:	38 c1 00 8c 	addi    r6,r1,140
     3c8:	38 60 01 f1 	li      r3,497
     3cc:	38 80 00 64 	li      r4,100
     3d0:	80 00 00 00 	lwz     r0,0(0)
			3d0: R_PPC_EMB_SDA21	lbl_8064D18C
     3d4:	38 a0 00 00 	li      r5,0
     3d8:	38 e0 00 02 	li      r7,2
     3dc:	39 00 00 02 	li      r8,2
     3e0:	54 0a 04 3e 	clrlwi  r10,r0,16
     3e4:	39 20 00 00 	li      r9,0
     3e8:	48 00 00 01 	bl      3e8 <fn_800614A8+0x3e8>
			3e8: R_PPC_REL24	fn_801AAE68
     3ec:	38 60 00 01 	li      r3,1
     3f0:	48 00 16 24 	b       1a14 <fn_800614A8+0x1a14>
     3f4:	2c 17 00 67 	cmpwi   r23,103
     3f8:	40 82 00 1c 	bne     414 <fn_800614A8+0x414>
     3fc:	7f a3 eb 78 	mr      r3,r29
     400:	7f e4 fb 78 	mr      r4,r31
     404:	7f 25 cb 78 	mr      r5,r25
     408:	48 00 00 01 	bl      408 <fn_800614A8+0x408>
			408: R_PPC_REL24	fn_800C9B08
     40c:	38 60 00 01 	li      r3,1
     410:	48 00 16 04 	b       1a14 <fn_800614A8+0x1a14>
     414:	2c 17 00 ed 	cmpwi   r23,237
     418:	40 82 00 4c 	bne     464 <fn_800614A8+0x464>
     41c:	7f 23 cb 78 	mr      r3,r25
     420:	48 00 00 01 	bl      420 <fn_800614A8+0x420>
			420: R_PPC_REL24	fn_80200C38
     424:	7c 70 1b 78 	mr      r16,r3
     428:	7f 23 cb 78 	mr      r3,r25
     42c:	48 00 00 01 	bl      42c <fn_800614A8+0x42c>
			42c: R_PPC_REL24	fn_80200C28
     430:	7c 6f 1b 78 	mr      r15,r3
     434:	7f 23 cb 78 	mr      r3,r25
     438:	48 00 00 01 	bl      438 <fn_800614A8+0x438>
			438: R_PPC_REL24	fn_80200C20
     43c:	7c 64 1b 78 	mr      r4,r3
     440:	7d e5 7b 78 	mr      r5,r15
     444:	7e 06 83 78 	mr      r6,r16
     448:	38 60 00 0b 	li      r3,11
     44c:	48 00 00 01 	bl      44c <fn_800614A8+0x44c>
			44c: R_PPC_REL24	fn_8020123C
     450:	7f 23 cb 78 	mr      r3,r25
     454:	48 00 00 01 	bl      454 <fn_800614A8+0x454>
			454: R_PPC_REL24	fn_80200C38
     458:	48 00 00 01 	bl      458 <fn_800614A8+0x458>
			458: R_PPC_REL24	fn_801A7228
     45c:	38 60 00 01 	li      r3,1
     460:	48 00 15 b4 	b       1a14 <fn_800614A8+0x1a14>
     464:	2c 17 00 3a 	cmpwi   r23,58
     468:	40 82 00 4c 	bne     4b4 <fn_800614A8+0x4b4>
     46c:	7f 23 cb 78 	mr      r3,r25
     470:	48 00 00 01 	bl      470 <fn_800614A8+0x470>
			470: R_PPC_REL24	fn_80200C38
     474:	7c 70 1b 78 	mr      r16,r3
     478:	7f 23 cb 78 	mr      r3,r25
     47c:	48 00 00 01 	bl      47c <fn_800614A8+0x47c>
			47c: R_PPC_REL24	fn_80200C28
     480:	7c 6f 1b 78 	mr      r15,r3
     484:	7f 23 cb 78 	mr      r3,r25
     488:	48 00 00 01 	bl      488 <fn_800614A8+0x488>
			488: R_PPC_REL24	fn_80200C20
     48c:	7c 64 1b 78 	mr      r4,r3
     490:	7d e5 7b 78 	mr      r5,r15
     494:	7e 06 83 78 	mr      r6,r16
     498:	38 60 00 27 	li      r3,39
     49c:	48 00 00 01 	bl      49c <fn_800614A8+0x49c>
			49c: R_PPC_REL24	fn_8020123C
     4a0:	7f 23 cb 78 	mr      r3,r25
     4a4:	48 00 00 01 	bl      4a4 <fn_800614A8+0x4a4>
			4a4: R_PPC_REL24	fn_80200C38
     4a8:	48 00 00 01 	bl      4a8 <fn_800614A8+0x4a8>
			4a8: R_PPC_REL24	fn_801A7228
     4ac:	38 60 00 01 	li      r3,1
     4b0:	48 00 15 64 	b       1a14 <fn_800614A8+0x1a14>
     4b4:	2c 17 00 0b 	cmpwi   r23,11
     4b8:	40 82 00 58 	bne     510 <fn_800614A8+0x510>
     4bc:	48 00 00 01 	bl      4bc <fn_800614A8+0x4bc>
			4bc: R_PPC_REL24	fn_80201B9C
     4c0:	38 80 00 20 	li      r4,32
     4c4:	48 00 00 01 	bl      4c4 <fn_800614A8+0x4c4>
			4c4: R_PPC_REL24	fn_80204844
     4c8:	48 00 00 01 	bl      4c8 <fn_800614A8+0x4c8>
			4c8: R_PPC_REL24	fn_8006D444
     4cc:	3c 80 00 08 	lis     r4,8
     4d0:	38 a0 00 00 	li      r5,0
     4d4:	48 00 00 01 	bl      4d4 <fn_800614A8+0x4d4>
			4d4: R_PPC_REL24	fn_8006D344
     4d8:	2c 03 00 00 	cmpwi   r3,0
     4dc:	41 82 00 14 	beq     4f0 <fn_800614A8+0x4f0>
     4e0:	7f a3 eb 78 	mr      r3,r29
     4e4:	48 00 00 01 	bl      4e4 <fn_800614A8+0x4e4>
			4e4: R_PPC_REL24	fn_80067180
     4e8:	38 60 00 01 	li      r3,1
     4ec:	48 00 00 10 	b       4fc <fn_800614A8+0x4fc>
     4f0:	7f 23 cb 78 	mr      r3,r25
     4f4:	48 00 00 01 	bl      4f4 <fn_800614A8+0x4f4>
			4f4: R_PPC_REL24	fn_80200C38
     4f8:	48 00 00 01 	bl      4f8 <fn_800614A8+0x4f8>
			4f8: R_PPC_REL24	fn_800654F8
     4fc:	28 1e 00 00 	cmplwi  r30,0
     500:	41 82 00 08 	beq     508 <fn_800614A8+0x508>
     504:	90 7e 00 00 	stw     r3,0(r30)
     508:	38 60 00 01 	li      r3,1
     50c:	48 00 15 08 	b       1a14 <fn_800614A8+0x1a14>
     510:	2c 17 00 65 	cmpwi   r23,101
     514:	40 82 00 38 	bne     54c <fn_800614A8+0x54c>
     518:	7f 23 cb 78 	mr      r3,r25
     51c:	48 00 00 01 	bl      51c <fn_800614A8+0x51c>
			51c: R_PPC_REL24	fn_80200C20
     520:	48 00 00 01 	bl      520 <fn_800614A8+0x520>
			520: R_PPC_REL24	fn_80201814
     524:	7c 60 1b 78 	mr      r0,r3
     528:	7f a3 eb 78 	mr      r3,r29
     52c:	7c 04 03 78 	mr      r4,r0
     530:	48 00 00 01 	bl      530 <fn_800614A8+0x530>
			530: R_PPC_REL24	fn_800359A0
     534:	28 1e 00 00 	cmplwi  r30,0
     538:	41 82 00 0c 	beq     544 <fn_800614A8+0x544>
     53c:	38 00 00 01 	li      r0,1
     540:	90 1e 00 00 	stw     r0,0(r30)
     544:	38 60 00 01 	li      r3,1
     548:	48 00 14 cc 	b       1a14 <fn_800614A8+0x1a14>
     54c:	2c 17 00 39 	cmpwi   r23,57
     550:	40 82 00 5c 	bne     5ac <fn_800614A8+0x5ac>
     554:	7f a3 eb 78 	mr      r3,r29
     558:	48 00 00 01 	bl      558 <fn_800614A8+0x558>
			558: R_PPC_REL24	fn_800CA2C8
     55c:	7f a3 eb 78 	mr      r3,r29
     560:	7f 64 db 78 	mr      r4,r27
     564:	48 00 00 01 	bl      564 <fn_800614A8+0x564>
			564: R_PPC_REL24	fn_800EA3A0
     568:	7f e3 fb 78 	mr      r3,r31
     56c:	48 00 00 01 	bl      56c <fn_800614A8+0x56c>
			56c: R_PPC_REL24	fn_8012B324
     570:	7f e3 fb 78 	mr      r3,r31
     574:	38 80 00 c0 	li      r4,192
     578:	38 a0 00 00 	li      r5,0
     57c:	48 00 00 01 	bl      57c <fn_800614A8+0x57c>
			57c: R_PPC_REL24	fn_8011FA8C
     580:	7f a3 eb 78 	mr      r3,r29
     584:	38 80 00 00 	li      r4,0
     588:	48 00 00 01 	bl      588 <fn_800614A8+0x588>
			588: R_PPC_REL24	fn_80201D34
     58c:	7f a3 eb 78 	mr      r3,r29
     590:	38 80 00 01 	li      r4,1
     594:	48 00 00 01 	bl      594 <fn_800614A8+0x594>
			594: R_PPC_REL24	fn_80201D1C
     598:	7f a4 eb 78 	mr      r4,r29
     59c:	38 60 00 02 	li      r3,2
     5a0:	48 00 00 01 	bl      5a0 <fn_800614A8+0x5a0>
			5a0: R_PPC_REL24	fn_801E8328
     5a4:	38 60 00 01 	li      r3,1
     5a8:	48 00 14 6c 	b       1a14 <fn_800614A8+0x1a14>
     5ac:	2c 17 00 0e 	cmpwi   r23,14
     5b0:	40 82 00 18 	bne     5c8 <fn_800614A8+0x5c8>
     5b4:	7f a3 eb 78 	mr      r3,r29
     5b8:	7f 24 cb 78 	mr      r4,r25
     5bc:	48 00 00 01 	bl      5bc <fn_800614A8+0x5bc>
			5bc: R_PPC_REL24	fn_80068994
     5c0:	38 60 00 01 	li      r3,1
     5c4:	48 00 14 50 	b       1a14 <fn_800614A8+0x1a14>
     5c8:	2c 17 00 27 	cmpwi   r23,39
     5cc:	40 82 00 1c 	bne     5e8 <fn_800614A8+0x5e8>
     5d0:	7f a3 eb 78 	mr      r3,r29
     5d4:	7f 24 cb 78 	mr      r4,r25
     5d8:	7f c5 f3 78 	mr      r5,r30
     5dc:	48 00 00 01 	bl      5dc <fn_800614A8+0x5dc>
			5dc: R_PPC_REL24	fn_80064B38
     5e0:	38 60 00 01 	li      r3,1
     5e4:	48 00 14 30 	b       1a14 <fn_800614A8+0x1a14>
     5e8:	2c 17 00 3b 	cmpwi   r23,59
     5ec:	40 82 00 40 	bne     62c <fn_800614A8+0x62c>
     5f0:	7f 23 cb 78 	mr      r3,r25
     5f4:	39 e0 00 01 	li      r15,1
     5f8:	48 00 00 01 	bl      5f8 <fn_800614A8+0x5f8>
			5f8: R_PPC_REL24	fn_80200C20
     5fc:	48 00 00 01 	bl      5fc <fn_800614A8+0x5fc>
			5fc: R_PPC_REL24	fn_80201814
     600:	28 03 00 00 	cmplwi  r3,0
     604:	41 82 00 14 	beq     618 <fn_800614A8+0x618>
     608:	48 00 00 01 	bl      608 <fn_800614A8+0x608>
			608: R_PPC_REL24	fn_80036E50
     60c:	2c 03 00 06 	cmpwi   r3,6
     610:	40 82 00 08 	bne     618 <fn_800614A8+0x618>
     614:	39 e0 00 00 	li      r15,0
     618:	28 1e 00 00 	cmplwi  r30,0
     61c:	41 82 00 08 	beq     624 <fn_800614A8+0x624>
     620:	91 fe 00 00 	stw     r15,0(r30)
     624:	38 60 00 01 	li      r3,1
     628:	48 00 13 ec 	b       1a14 <fn_800614A8+0x1a14>
     62c:	2c 17 00 4e 	cmpwi   r23,78
     630:	40 82 00 30 	bne     660 <fn_800614A8+0x660>
     634:	28 1e 00 00 	cmplwi  r30,0
     638:	41 82 00 20 	beq     658 <fn_800614A8+0x658>
     63c:	80 1b 00 6c 	lwz     r0,108(r27)
     640:	2c 00 00 00 	cmpwi   r0,0
     644:	41 82 00 0c 	beq     650 <fn_800614A8+0x650>
     648:	38 00 00 00 	li      r0,0
     64c:	48 00 00 08 	b       654 <fn_800614A8+0x654>
     650:	38 00 00 01 	li      r0,1
     654:	90 1e 00 00 	stw     r0,0(r30)
     658:	38 60 00 01 	li      r3,1
     65c:	48 00 13 b8 	b       1a14 <fn_800614A8+0x1a14>
     660:	2c 17 00 82 	cmpwi   r23,130
     664:	40 82 00 1c 	bne     680 <fn_800614A8+0x680>
     668:	28 1e 00 00 	cmplwi  r30,0
     66c:	41 82 00 0c 	beq     678 <fn_800614A8+0x678>
     670:	38 00 00 01 	li      r0,1
     674:	90 1e 00 00 	stw     r0,0(r30)
     678:	38 60 00 01 	li      r3,1
     67c:	48 00 13 98 	b       1a14 <fn_800614A8+0x1a14>
     680:	2c 17 00 32 	cmpwi   r23,50
     684:	40 82 00 18 	bne     69c <fn_800614A8+0x69c>
     688:	7f a3 eb 78 	mr      r3,r29
     68c:	7f 24 cb 78 	mr      r4,r25
     690:	48 00 00 01 	bl      690 <fn_800614A8+0x690>
			690: R_PPC_REL24	fn_80066A0C
     694:	38 60 00 01 	li      r3,1
     698:	48 00 13 7c 	b       1a14 <fn_800614A8+0x1a14>
     69c:	2c 17 00 e6 	cmpwi   r23,230
     6a0:	40 82 00 28 	bne     6c8 <fn_800614A8+0x6c8>
     6a4:	7f 23 cb 78 	mr      r3,r25
     6a8:	48 00 00 01 	bl      6a8 <fn_800614A8+0x6a8>
			6a8: R_PPC_REL24	fn_80200C38
     6ac:	c0 20 00 00 	lfs     f1,0(0)
			6ac: R_PPC_EMB_SDA21	lbl_8064E614
     6b0:	7c 64 1b 78 	mr      r4,r3
     6b4:	c0 40 00 00 	lfs     f2,0(0)
			6b4: R_PPC_EMB_SDA21	lbl_8064E618
     6b8:	7f e3 fb 78 	mr      r3,r31
     6bc:	48 00 00 01 	bl      6bc <fn_800614A8+0x6bc>
			6bc: R_PPC_REL24	fn_80066888
     6c0:	38 60 00 01 	li      r3,1
     6c4:	48 00 13 50 	b       1a14 <fn_800614A8+0x1a14>
     6c8:	2c 17 00 35 	cmpwi   r23,53
     6cc:	40 82 00 88 	bne     754 <fn_800614A8+0x754>
     6d0:	7f 23 cb 78 	mr      r3,r25
     6d4:	48 00 00 01 	bl      6d4 <fn_800614A8+0x6d4>
			6d4: R_PPC_REL24	fn_80200C38
     6d8:	7c 6f 1b 78 	mr      r15,r3
     6dc:	48 00 00 01 	bl      6dc <fn_800614A8+0x6dc>
			6dc: R_PPC_REL24	fn_801A7488
     6e0:	7c 70 1b 78 	mr      r16,r3
     6e4:	2c 10 00 0b 	cmpwi   r16,11
     6e8:	40 82 00 14 	bne     6fc <fn_800614A8+0x6fc>
     6ec:	7d e3 7b 78 	mr      r3,r15
     6f0:	38 80 00 0d 	li      r4,13
     6f4:	48 00 00 01 	bl      6f4 <fn_800614A8+0x6f4>
			6f4: R_PPC_REL24	fn_801A7470
     6f8:	48 00 00 18 	b       710 <fn_800614A8+0x710>
     6fc:	2c 10 00 0c 	cmpwi   r16,12
     700:	40 82 00 10 	bne     710 <fn_800614A8+0x710>
     704:	7d e3 7b 78 	mr      r3,r15
     708:	38 80 00 0e 	li      r4,14
     70c:	48 00 00 01 	bl      70c <fn_800614A8+0x70c>
			70c: R_PPC_REL24	fn_801A7470
     710:	7f a3 eb 78 	mr      r3,r29
     714:	7f 24 cb 78 	mr      r4,r25
     718:	7f c5 f3 78 	mr      r5,r30
     71c:	48 00 00 01 	bl      71c <fn_800614A8+0x71c>
			71c: R_PPC_REL24	fn_80066754
     720:	7d e3 7b 78 	mr      r3,r15
     724:	7e 04 83 78 	mr      r4,r16
     728:	48 00 00 01 	bl      728 <fn_800614A8+0x728>
			728: R_PPC_REL24	fn_801A7470
     72c:	2c 10 00 0b 	cmpwi   r16,11
     730:	41 82 00 0c 	beq     73c <fn_800614A8+0x73c>
     734:	2c 10 00 0c 	cmpwi   r16,12
     738:	40 82 00 14 	bne     74c <fn_800614A8+0x74c>
     73c:	3c 80 00 02 	lis     r4,2
     740:	7f e3 fb 78 	mr      r3,r31
     744:	38 84 fd 70 	addi    r4,r4,-656
     748:	48 00 00 01 	bl      748 <fn_800614A8+0x748>
			748: R_PPC_REL24	fn_801296F8
     74c:	38 60 00 01 	li      r3,1
     750:	48 00 12 c4 	b       1a14 <fn_800614A8+0x1a14>
     754:	2c 17 00 ea 	cmpwi   r23,234
     758:	40 82 01 48 	bne     8a0 <fn_800614A8+0x8a0>
     75c:	7f a3 eb 78 	mr      r3,r29
     760:	7f 24 cb 78 	mr      r4,r25
     764:	48 00 00 01 	bl      764 <fn_800614A8+0x764>
			764: R_PPC_REL24	fn_800674E4
     768:	80 00 00 00 	lwz     r0,0(0)
			768: R_PPC_EMB_SDA21	lbl_8064D18C
     76c:	2c 00 00 88 	cmpwi   r0,136
     770:	40 82 01 14 	bne     884 <fn_800614A8+0x884>
     774:	a8 7b 00 ea 	lha     r3,234(r27)
     778:	7c 60 0e 70 	srawi   r0,r3,1
     77c:	2c 00 00 01 	cmpwi   r0,1
     780:	40 80 00 0c 	bge     78c <fn_800614A8+0x78c>
     784:	38 00 00 01 	li      r0,1
     788:	48 00 00 08 	b       790 <fn_800614A8+0x790>
     78c:	7c 60 0e 70 	srawi   r0,r3,1
     790:	b0 1b 00 ea 	sth     r0,234(r27)
     794:	a8 7b 00 fa 	lha     r3,250(r27)
     798:	7c 60 0e 70 	srawi   r0,r3,1
     79c:	2c 00 00 01 	cmpwi   r0,1
     7a0:	40 80 00 0c 	bge     7ac <fn_800614A8+0x7ac>
     7a4:	38 00 00 01 	li      r0,1
     7a8:	48 00 00 08 	b       7b0 <fn_800614A8+0x7b0>
     7ac:	7c 60 0e 70 	srawi   r0,r3,1
     7b0:	b0 1b 00 fa 	sth     r0,250(r27)
     7b4:	a8 7b 00 fc 	lha     r3,252(r27)
     7b8:	7c 60 0e 70 	srawi   r0,r3,1
     7bc:	2c 00 00 01 	cmpwi   r0,1
     7c0:	40 80 00 0c 	bge     7cc <fn_800614A8+0x7cc>
     7c4:	38 00 00 01 	li      r0,1
     7c8:	48 00 00 08 	b       7d0 <fn_800614A8+0x7d0>
     7cc:	7c 60 0e 70 	srawi   r0,r3,1
     7d0:	b0 1b 00 fc 	sth     r0,252(r27)
     7d4:	a8 7b 00 ee 	lha     r3,238(r27)
     7d8:	7c 60 0e 70 	srawi   r0,r3,1
     7dc:	2c 00 00 01 	cmpwi   r0,1
     7e0:	40 80 00 0c 	bge     7ec <fn_800614A8+0x7ec>
     7e4:	38 00 00 01 	li      r0,1
     7e8:	48 00 00 08 	b       7f0 <fn_800614A8+0x7f0>
     7ec:	7c 60 0e 70 	srawi   r0,r3,1
     7f0:	b0 1b 00 ee 	sth     r0,238(r27)
     7f4:	a8 7b 00 f0 	lha     r3,240(r27)
     7f8:	7c 60 0e 70 	srawi   r0,r3,1
     7fc:	2c 00 00 01 	cmpwi   r0,1
     800:	40 80 00 0c 	bge     80c <fn_800614A8+0x80c>
     804:	38 00 00 01 	li      r0,1
     808:	48 00 00 08 	b       810 <fn_800614A8+0x810>
     80c:	7c 60 0e 70 	srawi   r0,r3,1
     810:	b0 1b 00 f0 	sth     r0,240(r27)
     814:	a8 7b 00 ec 	lha     r3,236(r27)
     818:	7c 60 0e 70 	srawi   r0,r3,1
     81c:	2c 00 00 01 	cmpwi   r0,1
     820:	40 80 00 0c 	bge     82c <fn_800614A8+0x82c>
     824:	38 00 00 01 	li      r0,1
     828:	48 00 00 08 	b       830 <fn_800614A8+0x830>
     82c:	7c 60 0e 70 	srawi   r0,r3,1
     830:	b0 1b 00 ec 	sth     r0,236(r27)
     834:	7f a3 eb 78 	mr      r3,r29
     838:	38 a1 00 10 	addi    r5,r1,16
     83c:	38 80 00 00 	li      r4,0
     840:	48 00 00 01 	bl      840 <fn_800614A8+0x840>
			840: R_PPC_REL24	fn_80038308
     844:	a8 61 00 10 	lha     r3,16(r1)
     848:	7c 60 0e 70 	srawi   r0,r3,1
     84c:	2c 00 00 01 	cmpwi   r0,1
     850:	40 80 00 0c 	bge     85c <fn_800614A8+0x85c>
     854:	38 00 00 01 	li      r0,1
     858:	48 00 00 08 	b       860 <fn_800614A8+0x860>
     85c:	7c 60 0e 70 	srawi   r0,r3,1
     860:	7f a3 eb 78 	mr      r3,r29
     864:	7c 05 07 34 	extsh   r5,r0
     868:	38 80 00 00 	li      r4,0
     86c:	38 c0 00 00 	li      r6,0
     870:	48 00 00 01 	bl      870 <fn_800614A8+0x870>
			870: R_PPC_REL24	fn_800389E0
     874:	a8 7c 00 86 	lha     r3,134(r28)
     878:	38 03 00 1e 	addi    r0,r3,30
     87c:	b0 1c 00 86 	sth     r0,134(r28)
     880:	48 00 00 18 	b       898 <fn_800614A8+0x898>
     884:	2c 00 00 29 	cmpwi   r0,41
     888:	40 82 00 10 	bne     898 <fn_800614A8+0x898>
     88c:	a8 7c 00 86 	lha     r3,134(r28)
     890:	38 03 00 1e 	addi    r0,r3,30
     894:	b0 1c 00 86 	sth     r0,134(r28)
     898:	38 60 00 01 	li      r3,1
     89c:	48 00 11 78 	b       1a14 <fn_800614A8+0x1a14>
     8a0:	2c 17 00 eb 	cmpwi   r23,235
     8a4:	40 82 00 18 	bne     8bc <fn_800614A8+0x8bc>
     8a8:	7f a3 eb 78 	mr      r3,r29
     8ac:	7f 24 cb 78 	mr      r4,r25
     8b0:	48 00 00 01 	bl      8b0 <fn_800614A8+0x8b0>
			8b0: R_PPC_REL24	fn_80067650
     8b4:	38 60 00 01 	li      r3,1
     8b8:	48 00 11 5c 	b       1a14 <fn_800614A8+0x1a14>
     8bc:	2c 17 00 f3 	cmpwi   r23,243
     8c0:	40 82 11 50 	bne     1a10 <fn_800614A8+0x1a10>
     8c4:	7f 23 cb 78 	mr      r3,r25
     8c8:	48 00 00 01 	bl      8c8 <fn_800614A8+0x8c8>
			8c8: R_PPC_REL24	fn_80200C38
     8cc:	7c 60 1b 78 	mr      r0,r3
     8d0:	7f a3 eb 78 	mr      r3,r29
     8d4:	7c 05 03 78 	mr      r5,r0
     8d8:	7f 64 db 78 	mr      r4,r27
     8dc:	7f 26 cb 78 	mr      r6,r25
     8e0:	7f c7 f3 78 	mr      r7,r30
     8e4:	48 00 00 01 	bl      8e4 <fn_800614A8+0x8e4>
			8e4: R_PPC_REL24	fn_800EA0FC
     8e8:	38 60 00 01 	li      r3,1
     8ec:	48 00 11 28 	b       1a14 <fn_800614A8+0x1a14>
     8f0:	2c 18 00 01 	cmpwi   r24,1
     8f4:	40 82 02 20 	bne     b14 <fn_800614A8+0xb14>
     8f8:	2c 17 00 01 	cmpwi   r23,1
     8fc:	40 82 00 30 	bne     92c <fn_800614A8+0x92c>
     900:	c0 20 00 00 	lfs     f1,0(0)
			900: R_PPC_EMB_SDA21	lbl_8064E61C
     904:	7f e3 fb 78 	mr      r3,r31
     908:	48 00 00 01 	bl      908 <fn_800614A8+0x908>
			908: R_PPC_REL24	fn_8011F778
     90c:	c0 20 00 00 	lfs     f1,0(0)
			90c: R_PPC_EMB_SDA21	lbl_8064E61C
     910:	7f e3 fb 78 	mr      r3,r31
     914:	48 00 00 01 	bl      914 <fn_800614A8+0x914>
			914: R_PPC_REL24	fn_8011F788
     918:	c0 20 00 00 	lfs     f1,0(0)
			918: R_PPC_EMB_SDA21	lbl_8064E61C
     91c:	7f e3 fb 78 	mr      r3,r31
     920:	48 00 00 01 	bl      920 <fn_800614A8+0x920>
			920: R_PPC_REL24	fn_8011F798
     924:	38 60 00 01 	li      r3,1
     928:	48 00 10 ec 	b       1a14 <fn_800614A8+0x1a14>
     92c:	2c 17 00 5a 	cmpwi   r23,90
     930:	40 82 01 94 	bne     ac4 <fn_800614A8+0xac4>
     934:	7f 23 cb 78 	mr      r3,r25
     938:	48 00 00 01 	bl      938 <fn_800614A8+0x938>
			938: R_PPC_REL24	fn_80200C20
     93c:	48 00 00 01 	bl      93c <fn_800614A8+0x93c>
			93c: R_PPC_REL24	fn_80201814
     940:	28 03 00 00 	cmplwi  r3,0
     944:	41 82 00 10 	beq     954 <fn_800614A8+0x954>
     948:	48 00 00 01 	bl      948 <fn_800614A8+0x948>
			948: R_PPC_REL24	fn_80201BC8
     94c:	7c 6f 1b 78 	mr      r15,r3
     950:	48 00 00 08 	b       958 <fn_800614A8+0x958>
     954:	39 e0 00 00 	li      r15,0
     958:	28 0f 00 00 	cmplwi  r15,0
     95c:	41 82 01 60 	beq     abc <fn_800614A8+0xabc>
     960:	48 00 00 01 	bl      960 <fn_800614A8+0x960>
			960: R_PPC_REL24	fn_800460EC
     964:	2c 03 00 00 	cmpwi   r3,0
     968:	40 82 01 54 	bne     abc <fn_800614A8+0xabc>
     96c:	7f a3 eb 78 	mr      r3,r29
     970:	48 00 00 01 	bl      970 <fn_800614A8+0x970>
			970: R_PPC_REL24	fn_800CAF7C
     974:	2c 03 00 00 	cmpwi   r3,0
     978:	41 82 01 44 	beq     abc <fn_800614A8+0xabc>
     97c:	80 75 00 8c 	lwz     r3,140(r21)
     980:	a8 03 01 50 	lha     r0,336(r3)
     984:	2c 00 00 00 	cmpwi   r0,0
     988:	40 82 01 34 	bne     abc <fn_800614A8+0xabc>
     98c:	7d e4 7b 78 	mr      r4,r15
     990:	38 61 00 50 	addi    r3,r1,80
     994:	48 00 00 01 	bl      994 <fn_800614A8+0x994>
			994: R_PPC_REL24	fn_8011F114
     998:	80 a1 00 50 	lwz     r5,80(r1)
     99c:	3c 00 43 30 	lis     r0,17200
     9a0:	80 e1 00 54 	lwz     r7,84(r1)
     9a4:	7f e3 fb 78 	mr      r3,r31
     9a8:	80 c1 00 58 	lwz     r6,88(r1)
     9ac:	38 81 00 74 	addi    r4,r1,116
     9b0:	90 a1 00 74 	stw     r5,116(r1)
     9b4:	38 a0 00 00 	li      r5,0
     9b8:	c8 20 00 00 	lfd     f1,0(0)
			9b8: R_PPC_EMB_SDA21	lbl_8064E5C0
     9bc:	90 e1 00 78 	stw     r7,120(r1)
     9c0:	c0 40 00 00 	lfs     f2,0(0)
			9c0: R_PPC_EMB_SDA21	lbl_8064E620
     9c4:	90 c1 00 7c 	stw     r6,124(r1)
     9c8:	a8 db 01 4a 	lha     r6,330(r27)
     9cc:	90 01 00 c0 	stw     r0,192(r1)
     9d0:	6c c0 80 00 	xoris   r0,r6,32768
     9d4:	90 01 00 c4 	stw     r0,196(r1)
     9d8:	c8 01 00 c0 	lfd     f0,192(r1)
     9dc:	ec 00 08 28 	fsubs   f0,f0,f1
     9e0:	ec 22 00 32 	fmuls   f1,f2,f0
     9e4:	48 00 00 01 	bl      9e4 <fn_800614A8+0x9e4>
			9e4: R_PPC_REL24	fn_80204434
     9e8:	54 60 06 3f 	clrlwi. r0,r3,24
     9ec:	40 82 00 d0 	bne     abc <fn_800614A8+0xabc>
     9f0:	80 00 00 00 	lwz     r0,0(0)
			9f0: R_PPC_EMB_SDA21	lbl_8064D18C
     9f4:	2c 00 00 34 	cmpwi   r0,52
     9f8:	41 82 00 c4 	beq     abc <fn_800614A8+0xabc>
     9fc:	7d e4 7b 78 	mr      r4,r15
     a00:	38 61 00 44 	addi    r3,r1,68
     a04:	48 00 00 01 	bl      a04 <fn_800614A8+0xa04>
			a04: R_PPC_REL24	fn_8011F114
     a08:	80 c1 00 44 	lwz     r6,68(r1)
     a0c:	7d e3 7b 78 	mr      r3,r15
     a10:	80 01 00 48 	lwz     r0,72(r1)
     a14:	38 e1 00 98 	addi    r7,r1,152
     a18:	38 80 00 00 	li      r4,0
     a1c:	38 a0 00 00 	li      r5,0
     a20:	90 db 00 94 	stw     r6,148(r27)
     a24:	38 c0 ff ff 	li      r6,-1
     a28:	39 00 00 01 	li      r8,1
     a2c:	90 1b 00 98 	stw     r0,152(r27)
     a30:	80 01 00 4c 	lwz     r0,76(r1)
     a34:	90 1b 00 9c 	stw     r0,156(r27)
     a38:	48 00 00 01 	bl      a38 <fn_800614A8+0xa38>
			a38: R_PPC_REL24	fn_8011F598
     a3c:	2c 03 ff ff 	cmpwi   r3,-1
     a40:	41 82 00 18 	beq     a58 <fn_800614A8+0xa58>
     a44:	7d e3 7b 78 	mr      r3,r15
     a48:	38 a1 00 80 	addi    r5,r1,128
     a4c:	38 80 00 00 	li      r4,0
     a50:	48 00 00 01 	bl      a50 <fn_800614A8+0xa50>
			a50: R_PPC_REL24	fn_8012FE10
     a54:	48 00 00 1c 	b       a70 <fn_800614A8+0xa70>
     a58:	80 81 00 74 	lwz     r4,116(r1)
     a5c:	80 61 00 78 	lwz     r3,120(r1)
     a60:	80 01 00 7c 	lwz     r0,124(r1)
     a64:	90 81 00 80 	stw     r4,128(r1)
     a68:	90 61 00 84 	stw     r3,132(r1)
     a6c:	90 01 00 88 	stw     r0,136(r1)
     a70:	80 15 00 94 	lwz     r0,148(r21)
     a74:	2c 00 00 01 	cmpwi   r0,1
     a78:	40 82 00 2c 	bne     aa4 <fn_800614A8+0xaa4>
     a7c:	7f e3 fb 78 	mr      r3,r31
     a80:	38 81 00 80 	addi    r4,r1,128
     a84:	38 a0 00 04 	li      r5,4
     a88:	38 c0 00 04 	li      r6,4
     a8c:	48 00 00 01 	bl      a8c <fn_800614A8+0xa8c>
			a8c: R_PPC_REL24	fn_8012FF34
     a90:	2c 03 00 00 	cmpwi   r3,0
     a94:	41 82 00 10 	beq     aa4 <fn_800614A8+0xaa4>
     a98:	7f e3 fb 78 	mr      r3,r31
     a9c:	38 80 00 3c 	li      r4,60
     aa0:	48 00 00 01 	bl      aa0 <fn_800614A8+0xaa0>
			aa0: R_PPC_REL24	fn_801302BC
     aa4:	7f a3 eb 78 	mr      r3,r29
     aa8:	38 80 00 15 	li      r4,21
     aac:	48 00 00 01 	bl      aac <fn_800614A8+0xaac>
			aac: R_PPC_REL24	fn_80201D2C
     ab0:	7f a3 eb 78 	mr      r3,r29
     ab4:	38 80 00 01 	li      r4,1
     ab8:	48 00 00 01 	bl      ab8 <fn_800614A8+0xab8>
			ab8: R_PPC_REL24	fn_80201D14
     abc:	38 60 00 01 	li      r3,1
     ac0:	48 00 0f 54 	b       1a14 <fn_800614A8+0x1a14>
     ac4:	2c 17 00 03 	cmpwi   r23,3
     ac8:	40 82 0f 48 	bne     1a10 <fn_800614A8+0x1a10>
     acc:	7f e3 fb 78 	mr      r3,r31
     ad0:	7e 84 a3 78 	mr      r4,r20
     ad4:	7e 65 9b 78 	mr      r5,r19
     ad8:	48 00 00 01 	bl      ad8 <fn_800614A8+0xad8>
			ad8: R_PPC_REL24	fn_80060C24
     adc:	7f a3 eb 78 	mr      r3,r29
     ae0:	7f e4 fb 78 	mr      r4,r31
     ae4:	7f 25 cb 78 	mr      r5,r25
     ae8:	7e 86 a3 78 	mr      r6,r20
     aec:	7e 67 9b 78 	mr      r7,r19
     af0:	48 00 00 01 	bl      af0 <fn_800614A8+0xaf0>
			af0: R_PPC_REL24	fn_80060D4C
     af4:	7f 43 d3 78 	mr      r3,r26
     af8:	7f a4 eb 78 	mr      r4,r29
     afc:	7f e5 fb 78 	mr      r5,r31
     b00:	7e a6 ab 78 	mr      r6,r21
     b04:	7f 87 e3 78 	mr      r7,r28
     b08:	48 00 00 01 	bl      b08 <fn_800614A8+0xb08>
			b08: R_PPC_REL24	fn_8005FD84
     b0c:	38 60 00 01 	li      r3,1
     b10:	48 00 0f 04 	b       1a14 <fn_800614A8+0x1a14>
     b14:	2c 18 00 15 	cmpwi   r24,21
     b18:	40 82 02 60 	bne     d78 <fn_800614A8+0xd78>
     b1c:	2c 17 00 01 	cmpwi   r23,1
     b20:	40 82 00 1c 	bne     b3c <fn_800614A8+0xb3c>
     b24:	c0 00 00 00 	lfs     f0,0(0)
			b24: R_PPC_EMB_SDA21	lbl_8064E5DC
     b28:	7f e3 fb 78 	mr      r3,r31
     b2c:	d0 1b 00 c4 	stfs    f0,196(r27)
     b30:	48 00 00 01 	bl      b30 <fn_800614A8+0xb30>
			b30: R_PPC_REL24	fn_8012B344
     b34:	38 60 00 01 	li      r3,1
     b38:	48 00 0e dc 	b       1a14 <fn_800614A8+0x1a14>
     b3c:	2c 17 00 03 	cmpwi   r23,3
     b40:	40 82 00 d8 	bne     c18 <fn_800614A8+0xc18>
     b44:	7f 43 d3 78 	mr      r3,r26
     b48:	7f a4 eb 78 	mr      r4,r29
     b4c:	7f e5 fb 78 	mr      r5,r31
     b50:	7e a6 ab 78 	mr      r6,r21
     b54:	7f 87 e3 78 	mr      r7,r28
     b58:	48 00 00 01 	bl      b58 <fn_800614A8+0xb58>
			b58: R_PPC_REL24	fn_8005FD84
     b5c:	7f a3 eb 78 	mr      r3,r29
     b60:	7f e4 fb 78 	mr      r4,r31
     b64:	7f 25 cb 78 	mr      r5,r25
     b68:	7e 86 a3 78 	mr      r6,r20
     b6c:	7e 67 9b 78 	mr      r7,r19
     b70:	48 00 00 01 	bl      b70 <fn_800614A8+0xb70>
			b70: R_PPC_REL24	fn_80060D4C
     b74:	2c 03 00 00 	cmpwi   r3,0
     b78:	40 82 00 98 	bne     c10 <fn_800614A8+0xc10>
     b7c:	c0 20 00 00 	lfs     f1,0(0)
			b7c: R_PPC_EMB_SDA21	lbl_8064E608
     b80:	7f e3 fb 78 	mr      r3,r31
     b84:	38 9b 00 94 	addi    r4,r27,148
     b88:	38 a0 00 02 	li      r5,2
     b8c:	38 c0 00 00 	li      r6,0
     b90:	48 00 00 01 	bl      b90 <fn_800614A8+0xb90>
			b90: R_PPC_REL24	fn_800BE86C
     b94:	2c 03 00 00 	cmpwi   r3,0
     b98:	40 82 00 34 	bne     bcc <fn_800614A8+0xbcc>
     b9c:	7f e3 fb 78 	mr      r3,r31
     ba0:	38 80 00 0f 	li      r4,15
     ba4:	38 a0 00 25 	li      r5,37
     ba8:	38 c0 00 01 	li      r6,1
     bac:	48 00 00 01 	bl      bac <fn_800614A8+0xbac>
			bac: R_PPC_REL24	fn_801294DC
     bb0:	7f a3 eb 78 	mr      r3,r29
     bb4:	38 80 00 01 	li      r4,1
     bb8:	48 00 00 01 	bl      bb8 <fn_800614A8+0xbb8>
			bb8: R_PPC_REL24	fn_80201D2C
     bbc:	7f a3 eb 78 	mr      r3,r29
     bc0:	38 80 00 01 	li      r4,1
     bc4:	48 00 00 01 	bl      bc4 <fn_800614A8+0xbc4>
			bc4: R_PPC_REL24	fn_80201D14
     bc8:	48 00 00 48 	b       c10 <fn_800614A8+0xc10>
     bcc:	c0 5b 00 c4 	lfs     f2,196(r27)
     bd0:	c0 00 00 00 	lfs     f0,0(0)
			bd0: R_PPC_EMB_SDA21	lbl_8064E624
     bd4:	fc 02 00 40 	fcmpo   cr0,f2,f0
     bd8:	40 80 00 38 	bge     c10 <fn_800614A8+0xc10>
     bdc:	c0 00 00 00 	lfs     f0,0(0)
			bdc: R_PPC_EMB_SDA21	lbl_8064E628
     be0:	c0 20 00 00 	lfs     f1,0(0)
			be0: R_PPC_EMB_SDA21	lbl_8064E614
     be4:	ec 02 00 2a 	fadds   f0,f2,f0
     be8:	fc 02 08 40 	fcmpo   cr0,f2,f1
     bec:	d0 1b 00 c4 	stfs    f0,196(r27)
     bf0:	4c 40 13 82 	cror    eq,lt,eq
     bf4:	40 82 00 1c 	bne     c10 <fn_800614A8+0xc10>
     bf8:	c0 1b 00 c4 	lfs     f0,196(r27)
     bfc:	fc 00 08 40 	fcmpo   cr0,f0,f1
     c00:	40 81 00 10 	ble     c10 <fn_800614A8+0xc10>
     c04:	7f e3 fb 78 	mr      r3,r31
     c08:	38 80 00 3f 	li      r4,63
     c0c:	48 00 00 01 	bl      c0c <fn_800614A8+0xc0c>
			c0c: R_PPC_REL24	fn_801A977C
     c10:	38 60 00 01 	li      r3,1
     c14:	48 00 0e 00 	b       1a14 <fn_800614A8+0x1a14>
     c18:	2c 17 00 5a 	cmpwi   r23,90
     c1c:	40 82 00 f4 	bne     d10 <fn_800614A8+0xd10>
     c20:	7f 23 cb 78 	mr      r3,r25
     c24:	48 00 00 01 	bl      c24 <fn_800614A8+0xc24>
			c24: R_PPC_REL24	fn_80200C20
     c28:	48 00 00 01 	bl      c28 <fn_800614A8+0xc28>
			c28: R_PPC_REL24	fn_80201814
     c2c:	28 03 00 00 	cmplwi  r3,0
     c30:	41 82 00 10 	beq     c40 <fn_800614A8+0xc40>
     c34:	48 00 00 01 	bl      c34 <fn_800614A8+0xc34>
			c34: R_PPC_REL24	fn_80201BC8
     c38:	7c 6f 1b 78 	mr      r15,r3
     c3c:	48 00 00 08 	b       c44 <fn_800614A8+0xc44>
     c40:	39 e0 00 00 	li      r15,0
     c44:	28 0f 00 00 	cmplwi  r15,0
     c48:	41 82 00 c0 	beq     d08 <fn_800614A8+0xd08>
     c4c:	48 00 00 01 	bl      c4c <fn_800614A8+0xc4c>
			c4c: R_PPC_REL24	fn_800460EC
     c50:	2c 03 00 00 	cmpwi   r3,0
     c54:	40 82 00 b4 	bne     d08 <fn_800614A8+0xd08>
     c58:	7f a3 eb 78 	mr      r3,r29
     c5c:	48 00 00 01 	bl      c5c <fn_800614A8+0xc5c>
			c5c: R_PPC_REL24	fn_800CAF7C
     c60:	2c 03 00 00 	cmpwi   r3,0
     c64:	41 82 00 a4 	beq     d08 <fn_800614A8+0xd08>
     c68:	a8 1b 01 50 	lha     r0,336(r27)
     c6c:	2c 00 00 00 	cmpwi   r0,0
     c70:	40 82 00 98 	bne     d08 <fn_800614A8+0xd08>
     c74:	7d e4 7b 78 	mr      r4,r15
     c78:	38 61 00 38 	addi    r3,r1,56
     c7c:	48 00 00 01 	bl      c7c <fn_800614A8+0xc7c>
			c7c: R_PPC_REL24	fn_8011F114
     c80:	80 a1 00 38 	lwz     r5,56(r1)
     c84:	3c 00 43 30 	lis     r0,17200
     c88:	80 e1 00 3c 	lwz     r7,60(r1)
     c8c:	7f e3 fb 78 	mr      r3,r31
     c90:	80 c1 00 40 	lwz     r6,64(r1)
     c94:	38 81 00 68 	addi    r4,r1,104
     c98:	90 a1 00 68 	stw     r5,104(r1)
     c9c:	38 a0 00 00 	li      r5,0
     ca0:	c8 20 00 00 	lfd     f1,0(0)
			ca0: R_PPC_EMB_SDA21	lbl_8064E5C0
     ca4:	90 e1 00 6c 	stw     r7,108(r1)
     ca8:	c0 40 00 00 	lfs     f2,0(0)
			ca8: R_PPC_EMB_SDA21	lbl_8064E620
     cac:	90 c1 00 70 	stw     r6,112(r1)
     cb0:	a8 db 01 4a 	lha     r6,330(r27)
     cb4:	90 01 00 c0 	stw     r0,192(r1)
     cb8:	6c c0 80 00 	xoris   r0,r6,32768
     cbc:	90 01 00 c4 	stw     r0,196(r1)
     cc0:	c8 01 00 c0 	lfd     f0,192(r1)
     cc4:	ec 00 08 28 	fsubs   f0,f0,f1
     cc8:	ec 22 00 32 	fmuls   f1,f2,f0
     ccc:	48 00 00 01 	bl      ccc <fn_800614A8+0xccc>
			ccc: R_PPC_REL24	fn_80204434
     cd0:	54 60 06 3f 	clrlwi. r0,r3,24
     cd4:	40 82 00 34 	bne     d08 <fn_800614A8+0xd08>
     cd8:	80 00 00 00 	lwz     r0,0(0)
			cd8: R_PPC_EMB_SDA21	lbl_8064D18C
     cdc:	2c 00 00 34 	cmpwi   r0,52
     ce0:	41 82 00 28 	beq     d08 <fn_800614A8+0xd08>
     ce4:	7d e4 7b 78 	mr      r4,r15
     ce8:	38 61 00 2c 	addi    r3,r1,44
     cec:	48 00 00 01 	bl      cec <fn_800614A8+0xcec>
			cec: R_PPC_REL24	fn_8011F114
     cf0:	80 61 00 2c 	lwz     r3,44(r1)
     cf4:	80 01 00 30 	lwz     r0,48(r1)
     cf8:	90 7b 00 94 	stw     r3,148(r27)
     cfc:	90 1b 00 98 	stw     r0,152(r27)
     d00:	80 01 00 34 	lwz     r0,52(r1)
     d04:	90 1b 00 9c 	stw     r0,156(r27)
     d08:	38 60 00 01 	li      r3,1
     d0c:	48 00 0d 08 	b       1a14 <fn_800614A8+0x1a14>
     d10:	2c 17 00 02 	cmpwi   r23,2
     d14:	40 82 0c fc 	bne     1a10 <fn_800614A8+0x1a10>
     d18:	7f e3 fb 78 	mr      r3,r31
     d1c:	48 00 00 01 	bl      d1c <fn_800614A8+0xd1c>
			d1c: R_PPC_REL24	fn_80128EAC
     d20:	7c 6f 1b 78 	mr      r15,r3
     d24:	7f e3 fb 78 	mr      r3,r31
     d28:	48 00 00 01 	bl      d28 <fn_800614A8+0xd28>
			d28: R_PPC_REL24	fn_801290D0
     d2c:	54 60 07 7b 	rlwinm. r0,r3,0,29,29
     d30:	41 82 00 38 	beq     d68 <fn_800614A8+0xd68>
     d34:	2c 0f 00 03 	cmpwi   r15,3
     d38:	41 82 00 0c 	beq     d44 <fn_800614A8+0xd44>
     d3c:	2c 0f 00 02 	cmpwi   r15,2
     d40:	40 82 00 28 	bne     d68 <fn_800614A8+0xd68>
     d44:	80 00 00 00 	lwz     r0,0(0)
			d44: R_PPC_EMB_SDA21	lbl_8064D18C
     d48:	2c 00 00 53 	cmpwi   r0,83
     d4c:	40 82 00 10 	bne     d5c <fn_800614A8+0xd5c>
     d50:	7f e3 fb 78 	mr      r3,r31
     d54:	48 00 00 01 	bl      d54 <fn_800614A8+0xd54>
			d54: R_PPC_REL24	fn_8012B344
     d58:	48 00 00 10 	b       d68 <fn_800614A8+0xd68>
     d5c:	54 64 07 b8 	rlwinm  r4,r3,0,30,28
     d60:	7f e3 fb 78 	mr      r3,r31
     d64:	48 00 00 01 	bl      d64 <fn_800614A8+0xd64>
			d64: R_PPC_REL24	fn_80128F74
     d68:	c0 00 00 00 	lfs     f0,0(0)
			d68: R_PPC_EMB_SDA21	lbl_8064E5DC
     d6c:	38 60 00 01 	li      r3,1
     d70:	d0 1b 00 c4 	stfs    f0,196(r27)
     d74:	48 00 0c a0 	b       1a14 <fn_800614A8+0x1a14>
     d78:	2c 18 00 03 	cmpwi   r24,3
     d7c:	40 82 00 a4 	bne     e20 <fn_800614A8+0xe20>
     d80:	2c 17 00 03 	cmpwi   r23,3
     d84:	40 82 00 6c 	bne     df0 <fn_800614A8+0xdf0>
     d88:	7f 43 d3 78 	mr      r3,r26
     d8c:	7f a4 eb 78 	mr      r4,r29
     d90:	7f e5 fb 78 	mr      r5,r31
     d94:	7e a6 ab 78 	mr      r6,r21
     d98:	7f 87 e3 78 	mr      r7,r28
     d9c:	48 00 00 01 	bl      d9c <fn_800614A8+0xd9c>
			d9c: R_PPC_REL24	fn_8005FD84
     da0:	7f a3 eb 78 	mr      r3,r29
     da4:	7f 64 db 78 	mr      r4,r27
     da8:	48 00 00 01 	bl      da8 <fn_800614A8+0xda8>
			da8: R_PPC_REL24	fn_800BE010
     dac:	7e 23 8b 78 	mr      r3,r17
     db0:	48 00 00 01 	bl      db0 <fn_800614A8+0xdb0>
			db0: R_PPC_REL24	fn_80201C48
     db4:	2c 03 00 00 	cmpwi   r3,0
     db8:	41 82 00 10 	beq     dc8 <fn_800614A8+0xdc8>
     dbc:	7f a3 eb 78 	mr      r3,r29
     dc0:	7f 64 db 78 	mr      r4,r27
     dc4:	48 00 00 01 	bl      dc4 <fn_800614A8+0xdc4>
			dc4: R_PPC_REL24	fn_800BDEE4
     dc8:	7f a3 eb 78 	mr      r3,r29
     dcc:	7f e4 fb 78 	mr      r4,r31
     dd0:	7f 45 d3 78 	mr      r5,r26
     dd4:	7f 66 db 78 	mr      r6,r27
     dd8:	7f 27 cb 78 	mr      r7,r25
     ddc:	7e 88 a3 78 	mr      r8,r20
     de0:	7e 69 9b 78 	mr      r9,r19
     de4:	48 00 00 01 	bl      de4 <fn_800614A8+0xde4>
			de4: R_PPC_REL24	fn_80060F9C
     de8:	38 60 00 01 	li      r3,1
     dec:	48 00 0c 28 	b       1a14 <fn_800614A8+0x1a14>
     df0:	2c 17 00 66 	cmpwi   r23,102
     df4:	40 82 0c 1c 	bne     1a10 <fn_800614A8+0x1a10>
     df8:	7f e3 fb 78 	mr      r3,r31
     dfc:	48 00 00 01 	bl      dfc <fn_800614A8+0xdfc>
			dfc: R_PPC_REL24	fn_8012B344
     e00:	7f a3 eb 78 	mr      r3,r29
     e04:	38 80 00 01 	li      r4,1
     e08:	48 00 00 01 	bl      e08 <fn_800614A8+0xe08>
			e08: R_PPC_REL24	fn_80201D2C
     e0c:	7f a3 eb 78 	mr      r3,r29
     e10:	38 80 00 01 	li      r4,1
     e14:	48 00 00 01 	bl      e14 <fn_800614A8+0xe14>
			e14: R_PPC_REL24	fn_80201D14
     e18:	38 60 00 01 	li      r3,1
     e1c:	48 00 0b f8 	b       1a14 <fn_800614A8+0x1a14>
     e20:	2c 18 00 06 	cmpwi   r24,6
     e24:	40 82 01 2c 	bne     f50 <fn_800614A8+0xf50>
     e28:	2c 17 00 01 	cmpwi   r23,1
     e2c:	40 82 00 18 	bne     e44 <fn_800614A8+0xe44>
     e30:	88 1c 00 89 	lbz     r0,137(r28)
     e34:	38 60 00 01 	li      r3,1
     e38:	54 00 06 3c 	rlwinm  r0,r0,0,24,30
     e3c:	98 1c 00 89 	stb     r0,137(r28)
     e40:	48 00 0b d4 	b       1a14 <fn_800614A8+0x1a14>
     e44:	2c 17 00 03 	cmpwi   r23,3
     e48:	40 82 00 24 	bne     e6c <fn_800614A8+0xe6c>
     e4c:	7f 43 d3 78 	mr      r3,r26
     e50:	7f a4 eb 78 	mr      r4,r29
     e54:	7f e5 fb 78 	mr      r5,r31
     e58:	7e a6 ab 78 	mr      r6,r21
     e5c:	7f 87 e3 78 	mr      r7,r28
     e60:	48 00 00 01 	bl      e60 <fn_800614A8+0xe60>
			e60: R_PPC_REL24	fn_8005FD84
     e64:	38 60 00 01 	li      r3,1
     e68:	48 00 0b ac 	b       1a14 <fn_800614A8+0x1a14>
     e6c:	2c 17 00 0c 	cmpwi   r23,12
     e70:	40 82 00 44 	bne     eb4 <fn_800614A8+0xeb4>
     e74:	7f a3 eb 78 	mr      r3,r29
     e78:	7f e4 fb 78 	mr      r4,r31
     e7c:	7f 25 cb 78 	mr      r5,r25
     e80:	48 00 00 01 	bl      e80 <fn_800614A8+0xe80>
			e80: R_PPC_REL24	fn_80060F10
     e84:	2c 03 00 00 	cmpwi   r3,0
     e88:	40 82 00 24 	bne     eac <fn_800614A8+0xeac>
     e8c:	38 00 00 5a 	li      r0,90
     e90:	7f a3 eb 78 	mr      r3,r29
     e94:	b0 1b 01 50 	sth     r0,336(r27)
     e98:	38 80 00 01 	li      r4,1
     e9c:	48 00 00 01 	bl      e9c <fn_800614A8+0xe9c>
			e9c: R_PPC_REL24	fn_80201D2C
     ea0:	7f a3 eb 78 	mr      r3,r29
     ea4:	38 80 00 01 	li      r4,1
     ea8:	48 00 00 01 	bl      ea8 <fn_800614A8+0xea8>
			ea8: R_PPC_REL24	fn_80201D14
     eac:	38 60 00 01 	li      r3,1
     eb0:	48 00 0b 64 	b       1a14 <fn_800614A8+0x1a14>
     eb4:	2c 17 00 07 	cmpwi   r23,7
     eb8:	40 82 00 68 	bne     f20 <fn_800614A8+0xf20>
     ebc:	7f a3 eb 78 	mr      r3,r29
     ec0:	38 96 01 b8 	addi    r4,r22,440
     ec4:	38 d6 01 cc 	addi    r6,r22,460
     ec8:	39 16 01 d8 	addi    r8,r22,472
     ecc:	38 a0 00 00 	li      r5,0
			ecc: R_PPC_EMB_SDA21	lbl_8064B508
     ed0:	38 e0 00 00 	li      r7,0
			ed0: R_PPC_EMB_SDA21	lbl_8064B510
     ed4:	48 00 00 01 	bl      ed4 <fn_800614A8+0xed4>
			ed4: R_PPC_REL24	fn_80035FB8
     ed8:	2c 03 00 00 	cmpwi   r3,0
     edc:	40 82 00 3c 	bne     f18 <fn_800614A8+0xf18>
     ee0:	7f a3 eb 78 	mr      r3,r29
     ee4:	7f e4 fb 78 	mr      r4,r31
     ee8:	7f 25 cb 78 	mr      r5,r25
     eec:	48 00 00 01 	bl      eec <fn_800614A8+0xeec>
			eec: R_PPC_REL24	fn_80060F10
     ef0:	2c 03 00 00 	cmpwi   r3,0
     ef4:	40 82 00 24 	bne     f18 <fn_800614A8+0xf18>
     ef8:	38 00 00 5a 	li      r0,90
     efc:	7f a3 eb 78 	mr      r3,r29
     f00:	b0 1b 01 50 	sth     r0,336(r27)
     f04:	38 80 00 01 	li      r4,1
     f08:	48 00 00 01 	bl      f08 <fn_800614A8+0xf08>
			f08: R_PPC_REL24	fn_80201D2C
     f0c:	7f a3 eb 78 	mr      r3,r29
     f10:	38 80 00 01 	li      r4,1
     f14:	48 00 00 01 	bl      f14 <fn_800614A8+0xf14>
			f14: R_PPC_REL24	fn_80201D14
     f18:	38 60 00 01 	li      r3,1
     f1c:	48 00 0a f8 	b       1a14 <fn_800614A8+0x1a14>
     f20:	2c 17 00 0d 	cmpwi   r23,13
     f24:	40 82 0a ec 	bne     1a10 <fn_800614A8+0x1a10>
     f28:	7f a3 eb 78 	mr      r3,r29
     f2c:	38 80 00 01 	li      r4,1
     f30:	48 00 00 01 	bl      f30 <fn_800614A8+0xf30>
			f30: R_PPC_REL24	fn_80201D2C
     f34:	7f a3 eb 78 	mr      r3,r29
     f38:	38 80 00 01 	li      r4,1
     f3c:	48 00 00 01 	bl      f3c <fn_800614A8+0xf3c>
			f3c: R_PPC_REL24	fn_80201D14
     f40:	7f e3 fb 78 	mr      r3,r31
     f44:	48 00 00 01 	bl      f44 <fn_800614A8+0xf44>
			f44: R_PPC_REL24	fn_8012B344
     f48:	38 60 00 01 	li      r3,1
     f4c:	48 00 0a c8 	b       1a14 <fn_800614A8+0x1a14>
     f50:	2c 18 00 5f 	cmpwi   r24,95
     f54:	40 82 00 84 	bne     fd8 <fn_800614A8+0xfd8>
     f58:	2c 17 00 03 	cmpwi   r23,3
     f5c:	40 82 00 18 	bne     f74 <fn_800614A8+0xf74>
     f60:	7f a3 eb 78 	mr      r3,r29
     f64:	7f e4 fb 78 	mr      r4,r31
     f68:	48 00 00 01 	bl      f68 <fn_800614A8+0xf68>
			f68: R_PPC_REL24	fn_800C9B74
     f6c:	38 60 00 01 	li      r3,1
     f70:	48 00 0a a4 	b       1a14 <fn_800614A8+0x1a14>
     f74:	2c 17 00 68 	cmpwi   r23,104
     f78:	40 82 00 24 	bne     f9c <fn_800614A8+0xf9c>
     f7c:	7f a3 eb 78 	mr      r3,r29
     f80:	38 80 00 01 	li      r4,1
     f84:	48 00 00 01 	bl      f84 <fn_800614A8+0xf84>
			f84: R_PPC_REL24	fn_80201D2C
     f88:	7f a3 eb 78 	mr      r3,r29
     f8c:	38 80 00 01 	li      r4,1
     f90:	48 00 00 01 	bl      f90 <fn_800614A8+0xf90>
			f90: R_PPC_REL24	fn_80201D14
     f94:	38 60 00 01 	li      r3,1
     f98:	48 00 0a 7c 	b       1a14 <fn_800614A8+0x1a14>
     f9c:	2c 17 00 02 	cmpwi   r23,2
     fa0:	40 82 00 18 	bne     fb8 <fn_800614A8+0xfb8>
     fa4:	7f a3 eb 78 	mr      r3,r29
     fa8:	7f e4 fb 78 	mr      r4,r31
     fac:	48 00 00 01 	bl      fac <fn_800614A8+0xfac>
			fac: R_PPC_REL24	fn_800C9AD4
     fb0:	38 60 00 01 	li      r3,1
     fb4:	48 00 0a 60 	b       1a14 <fn_800614A8+0x1a14>
     fb8:	2c 17 00 69 	cmpwi   r23,105
     fbc:	40 82 00 0c 	bne     fc8 <fn_800614A8+0xfc8>
     fc0:	38 60 00 01 	li      r3,1
     fc4:	48 00 0a 50 	b       1a14 <fn_800614A8+0x1a14>
     fc8:	2c 17 00 65 	cmpwi   r23,101
     fcc:	40 82 0a 44 	bne     1a10 <fn_800614A8+0x1a10>
     fd0:	38 60 00 01 	li      r3,1
     fd4:	48 00 0a 40 	b       1a14 <fn_800614A8+0x1a14>
     fd8:	2c 18 00 56 	cmpwi   r24,86
     fdc:	40 82 01 f8 	bne     11d4 <fn_800614A8+0x11d4>
     fe0:	2c 17 00 03 	cmpwi   r23,3
     fe4:	40 82 00 24 	bne     1008 <fn_800614A8+0x1008>
     fe8:	7f 43 d3 78 	mr      r3,r26
     fec:	7f a4 eb 78 	mr      r4,r29
     ff0:	7f e5 fb 78 	mr      r5,r31
     ff4:	7e a6 ab 78 	mr      r6,r21
     ff8:	7f 87 e3 78 	mr      r7,r28
     ffc:	48 00 00 01 	bl      ffc <fn_800614A8+0xffc>
			ffc: R_PPC_REL24	fn_8005FD84
    1000:	38 60 00 01 	li      r3,1
    1004:	48 00 0a 10 	b       1a14 <fn_800614A8+0x1a14>
    1008:	2c 17 00 05 	cmpwi   r23,5
    100c:	40 82 01 64 	bne     1170 <fn_800614A8+0x1170>
    1010:	7f a3 eb 78 	mr      r3,r29
    1014:	39 e0 00 00 	li      r15,0
    1018:	38 80 00 03 	li      r4,3
    101c:	48 00 00 01 	bl      101c <fn_800614A8+0x101c>
			101c: R_PPC_REL24	fn_80066D04
    1020:	2c 03 00 00 	cmpwi   r3,0
    1024:	40 82 00 1c 	bne     1040 <fn_800614A8+0x1040>
    1028:	7f a3 eb 78 	mr      r3,r29
    102c:	38 80 00 02 	li      r4,2
    1030:	48 00 00 01 	bl      1030 <fn_800614A8+0x1030>
			1030: R_PPC_REL24	fn_80066D04
    1034:	2c 03 00 00 	cmpwi   r3,0
    1038:	40 82 00 08 	bne     1040 <fn_800614A8+0x1040>
    103c:	39 e0 00 01 	li      r15,1
    1040:	7f e3 fb 78 	mr      r3,r31
    1044:	48 00 00 01 	bl      1044 <fn_800614A8+0x1044>
			1044: R_PPC_REL24	fn_8012B344
    1048:	7f a3 eb 78 	mr      r3,r29
    104c:	38 81 00 5c 	addi    r4,r1,92
    1050:	48 00 00 01 	bl      1050 <fn_800614A8+0x1050>
			1050: R_PPC_REL24	fn_802045AC
    1054:	c0 01 00 8c 	lfs     f0,140(r1)
    1058:	c0 41 00 90 	lfs     f2,144(r1)
    105c:	c0 21 00 5c 	lfs     f1,92(r1)
    1060:	fc 60 00 1e 	fctiwz  f3,f0
    1064:	c0 01 00 60 	lfs     f0,96(r1)
    1068:	fc 40 10 1e 	fctiwz  f2,f2
    106c:	fc 20 08 1e 	fctiwz  f1,f1
    1070:	fc 00 00 1e 	fctiwz  f0,f0
    1074:	d8 61 00 c0 	stfd    f3,192(r1)
    1078:	d8 41 00 c8 	stfd    f2,200(r1)
    107c:	80 61 00 c4 	lwz     r3,196(r1)
    1080:	d8 21 00 d0 	stfd    f1,208(r1)
    1084:	80 81 00 cc 	lwz     r4,204(r1)
    1088:	d8 01 00 d8 	stfd    f0,216(r1)
    108c:	80 a1 00 d4 	lwz     r5,212(r1)
    1090:	80 c1 00 dc 	lwz     r6,220(r1)
    1094:	48 00 00 01 	bl      1094 <fn_800614A8+0x1094>
			1094: R_PPC_REL24	fn_80179064
    1098:	2c 0f 00 00 	cmpwi   r15,0
    109c:	40 82 00 b4 	bne     1150 <fn_800614A8+0x1150>
    10a0:	48 00 00 01 	bl      10a0 <fn_800614A8+0x10a0>
			10a0: R_PPC_REL24	fn_800FBFB0
    10a4:	54 60 07 ff 	clrlwi. r0,r3,31
    10a8:	39 e0 00 01 	li      r15,1
    10ac:	41 82 00 80 	beq     112c <fn_800614A8+0x112c>
    10b0:	88 1c 00 89 	lbz     r0,137(r28)
    10b4:	54 00 07 ff 	clrlwi. r0,r0,31
    10b8:	41 82 00 74 	beq     112c <fn_800614A8+0x112c>
    10bc:	48 00 00 01 	bl      10bc <fn_800614A8+0x10bc>
			10bc: R_PPC_REL24	fn_801A717C
    10c0:	88 1c 00 89 	lbz     r0,137(r28)
    10c4:	7c 70 1b 78 	mr      r16,r3
    10c8:	38 80 00 10 	li      r4,16
    10cc:	54 00 06 3c 	rlwinm  r0,r0,0,24,30
    10d0:	98 1c 00 89 	stb     r0,137(r28)
    10d4:	48 00 00 01 	bl      10d4 <fn_800614A8+0x10d4>
			10d4: R_PPC_REL24	fn_801A7470
    10d8:	7e 03 83 78 	mr      r3,r16
    10dc:	7f 44 d3 78 	mr      r4,r26
    10e0:	48 00 00 01 	bl      10e0 <fn_800614A8+0x10e0>
			10e0: R_PPC_REL24	fn_801A74A0
    10e4:	7e 03 83 78 	mr      r3,r16
    10e8:	7f 44 d3 78 	mr      r4,r26
    10ec:	48 00 00 01 	bl      10ec <fn_800614A8+0x10ec>
			10ec: R_PPC_REL24	fn_801A74A8
    10f0:	7e 03 83 78 	mr      r3,r16
    10f4:	38 81 00 8c 	addi    r4,r1,140
    10f8:	48 00 00 01 	bl      10f8 <fn_800614A8+0x10f8>
			10f8: R_PPC_REL24	fn_801A764C
    10fc:	7f 44 d3 78 	mr      r4,r26
    1100:	7f 45 d3 78 	mr      r5,r26
    1104:	7e 06 83 78 	mr      r6,r16
    1108:	38 60 00 35 	li      r3,53
    110c:	48 00 00 01 	bl      110c <fn_800614A8+0x110c>
			110c: R_PPC_REL24	fn_8020123C
    1110:	38 00 ff ff 	li      r0,-1
    1114:	7e 03 83 78 	mr      r3,r16
    1118:	7c 90 00 38 	and     r16,r4,r0
    111c:	48 00 00 01 	bl      111c <fn_800614A8+0x111c>
			111c: R_PPC_REL24	fn_801A7228
    1120:	56 00 07 ff 	clrlwi. r0,r16,31
    1124:	41 82 00 08 	beq     112c <fn_800614A8+0x112c>
    1128:	39 e0 00 00 	li      r15,0
    112c:	2c 0f 00 00 	cmpwi   r15,0
    1130:	41 82 00 38 	beq     1168 <fn_800614A8+0x1168>
    1134:	7f a3 eb 78 	mr      r3,r29
    1138:	38 80 00 01 	li      r4,1
    113c:	48 00 00 01 	bl      113c <fn_800614A8+0x113c>
			113c: R_PPC_REL24	fn_80201D2C
    1140:	7f a3 eb 78 	mr      r3,r29
    1144:	38 80 00 01 	li      r4,1
    1148:	48 00 00 01 	bl      1148 <fn_800614A8+0x1148>
			1148: R_PPC_REL24	fn_80201D14
    114c:	48 00 00 1c 	b       1168 <fn_800614A8+0x1168>
    1150:	7f a3 eb 78 	mr      r3,r29
    1154:	38 80 00 01 	li      r4,1
    1158:	48 00 00 01 	bl      1158 <fn_800614A8+0x1158>
			1158: R_PPC_REL24	fn_80201D2C
    115c:	7f a3 eb 78 	mr      r3,r29
    1160:	38 80 00 01 	li      r4,1
    1164:	48 00 00 01 	bl      1164 <fn_800614A8+0x1164>
			1164: R_PPC_REL24	fn_80201D14
    1168:	38 60 00 01 	li      r3,1
    116c:	48 00 08 a8 	b       1a14 <fn_800614A8+0x1a14>
    1170:	2c 17 00 3d 	cmpwi   r23,61
    1174:	40 82 00 38 	bne     11ac <fn_800614A8+0x11ac>
    1178:	7f a3 eb 78 	mr      r3,r29
    117c:	7f 64 db 78 	mr      r4,r27
    1180:	48 00 00 01 	bl      1180 <fn_800614A8+0x1180>
			1180: R_PPC_REL24	fn_800EA3A0
    1184:	7f e3 fb 78 	mr      r3,r31
    1188:	48 00 00 01 	bl      1188 <fn_800614A8+0x1188>
			1188: R_PPC_REL24	fn_8012B344
    118c:	7f a3 eb 78 	mr      r3,r29
    1190:	38 80 00 01 	li      r4,1
    1194:	48 00 00 01 	bl      1194 <fn_800614A8+0x1194>
			1194: R_PPC_REL24	fn_80201D2C
    1198:	7f a3 eb 78 	mr      r3,r29
    119c:	38 80 00 01 	li      r4,1
    11a0:	48 00 00 01 	bl      11a0 <fn_800614A8+0x11a0>
			11a0: R_PPC_REL24	fn_80201D14
    11a4:	38 60 00 01 	li      r3,1
    11a8:	48 00 08 6c 	b       1a14 <fn_800614A8+0x1a14>
    11ac:	2c 17 00 02 	cmpwi   r23,2
    11b0:	40 82 08 60 	bne     1a10 <fn_800614A8+0x1a10>
    11b4:	7f 43 d3 78 	mr      r3,r26
    11b8:	7f 44 d3 78 	mr      r4,r26
    11bc:	38 a0 00 56 	li      r5,86
    11c0:	38 c0 00 05 	li      r6,5
    11c4:	38 e0 00 00 	li      r7,0
    11c8:	48 00 00 01 	bl      11c8 <fn_800614A8+0x11c8>
			11c8: R_PPC_REL24	fn_802006D4
    11cc:	38 60 00 01 	li      r3,1
    11d0:	48 00 08 44 	b       1a14 <fn_800614A8+0x1a14>
    11d4:	2c 18 00 59 	cmpwi   r24,89
    11d8:	40 82 00 c0 	bne     1298 <fn_800614A8+0x1298>
    11dc:	2c 17 00 03 	cmpwi   r23,3
    11e0:	40 82 00 24 	bne     1204 <fn_800614A8+0x1204>
    11e4:	7f 43 d3 78 	mr      r3,r26
    11e8:	7f a4 eb 78 	mr      r4,r29
    11ec:	7f e5 fb 78 	mr      r5,r31
    11f0:	7e a6 ab 78 	mr      r6,r21
    11f4:	7f 87 e3 78 	mr      r7,r28
    11f8:	48 00 00 01 	bl      11f8 <fn_800614A8+0x11f8>
			11f8: R_PPC_REL24	fn_8005FD84
    11fc:	38 60 00 01 	li      r3,1
    1200:	48 00 08 14 	b       1a14 <fn_800614A8+0x1a14>
    1204:	2c 17 00 05 	cmpwi   r23,5
    1208:	40 82 00 2c 	bne     1234 <fn_800614A8+0x1234>
    120c:	7f e3 fb 78 	mr      r3,r31
    1210:	48 00 00 01 	bl      1210 <fn_800614A8+0x1210>
			1210: R_PPC_REL24	fn_8012B344
    1214:	7f a3 eb 78 	mr      r3,r29
    1218:	38 80 00 01 	li      r4,1
    121c:	48 00 00 01 	bl      121c <fn_800614A8+0x121c>
			121c: R_PPC_REL24	fn_80201D2C
    1220:	7f a3 eb 78 	mr      r3,r29
    1224:	38 80 00 01 	li      r4,1
    1228:	48 00 00 01 	bl      1228 <fn_800614A8+0x1228>
			1228: R_PPC_REL24	fn_80201D14
    122c:	38 60 00 01 	li      r3,1
    1230:	48 00 07 e4 	b       1a14 <fn_800614A8+0x1a14>
    1234:	2c 17 00 3d 	cmpwi   r23,61
    1238:	40 82 00 38 	bne     1270 <fn_800614A8+0x1270>
    123c:	7f a3 eb 78 	mr      r3,r29
    1240:	7f 64 db 78 	mr      r4,r27
    1244:	48 00 00 01 	bl      1244 <fn_800614A8+0x1244>
			1244: R_PPC_REL24	fn_800EA3A0
    1248:	7f e3 fb 78 	mr      r3,r31
    124c:	48 00 00 01 	bl      124c <fn_800614A8+0x124c>
			124c: R_PPC_REL24	fn_8012B344
    1250:	7f a3 eb 78 	mr      r3,r29
    1254:	38 80 00 01 	li      r4,1
    1258:	48 00 00 01 	bl      1258 <fn_800614A8+0x1258>
			1258: R_PPC_REL24	fn_80201D2C
    125c:	7f a3 eb 78 	mr      r3,r29
    1260:	38 80 00 01 	li      r4,1
    1264:	48 00 00 01 	bl      1264 <fn_800614A8+0x1264>
			1264: R_PPC_REL24	fn_80201D14
    1268:	38 60 00 01 	li      r3,1
    126c:	48 00 07 a8 	b       1a14 <fn_800614A8+0x1a14>
    1270:	2c 17 00 02 	cmpwi   r23,2
    1274:	40 82 07 9c 	bne     1a10 <fn_800614A8+0x1a10>
    1278:	7f 43 d3 78 	mr      r3,r26
    127c:	7f 44 d3 78 	mr      r4,r26
    1280:	38 a0 00 59 	li      r5,89
    1284:	38 c0 00 05 	li      r6,5
    1288:	38 e0 00 00 	li      r7,0
    128c:	48 00 00 01 	bl      128c <fn_800614A8+0x128c>
			128c: R_PPC_REL24	fn_802006D4
    1290:	38 60 00 01 	li      r3,1
    1294:	48 00 07 80 	b       1a14 <fn_800614A8+0x1a14>
    1298:	2c 18 00 07 	cmpwi   r24,7
    129c:	40 82 00 b0 	bne     134c <fn_800614A8+0x134c>
    12a0:	2c 17 00 03 	cmpwi   r23,3
    12a4:	40 82 00 24 	bne     12c8 <fn_800614A8+0x12c8>
    12a8:	7f 43 d3 78 	mr      r3,r26
    12ac:	7f a4 eb 78 	mr      r4,r29
    12b0:	7f e5 fb 78 	mr      r5,r31
    12b4:	7e a6 ab 78 	mr      r6,r21
    12b8:	7f 87 e3 78 	mr      r7,r28
    12bc:	48 00 00 01 	bl      12bc <fn_800614A8+0x12bc>
			12bc: R_PPC_REL24	fn_8005FD84
    12c0:	38 60 00 01 	li      r3,1
    12c4:	48 00 07 50 	b       1a14 <fn_800614A8+0x1a14>
    12c8:	2c 17 00 36 	cmpwi   r23,54
    12cc:	40 82 00 24 	bne     12f0 <fn_800614A8+0x12f0>
    12d0:	7f a3 eb 78 	mr      r3,r29
    12d4:	38 80 00 01 	li      r4,1
    12d8:	48 00 00 01 	bl      12d8 <fn_800614A8+0x12d8>
			12d8: R_PPC_REL24	fn_80201D2C
    12dc:	7f a3 eb 78 	mr      r3,r29
    12e0:	38 80 00 01 	li      r4,1
    12e4:	48 00 00 01 	bl      12e4 <fn_800614A8+0x12e4>
			12e4: R_PPC_REL24	fn_80201D14
    12e8:	38 60 00 01 	li      r3,1
    12ec:	48 00 07 28 	b       1a14 <fn_800614A8+0x1a14>
    12f0:	2c 17 00 07 	cmpwi   r23,7
    12f4:	40 82 00 48 	bne     133c <fn_800614A8+0x133c>
    12f8:	7f a3 eb 78 	mr      r3,r29
    12fc:	38 96 01 f0 	addi    r4,r22,496
    1300:	38 d6 01 cc 	addi    r6,r22,460
    1304:	39 16 01 d8 	addi    r8,r22,472
    1308:	38 a0 00 00 	li      r5,0
			1308: R_PPC_EMB_SDA21	lbl_8064B518
    130c:	38 e0 00 00 	li      r7,0
			130c: R_PPC_EMB_SDA21	lbl_8064B510
    1310:	48 00 00 01 	bl      1310 <fn_800614A8+0x1310>
			1310: R_PPC_REL24	fn_80035FB8
    1314:	2c 03 00 00 	cmpwi   r3,0
    1318:	40 82 00 1c 	bne     1334 <fn_800614A8+0x1334>
    131c:	7f a3 eb 78 	mr      r3,r29
    1320:	38 80 00 01 	li      r4,1
    1324:	48 00 00 01 	bl      1324 <fn_800614A8+0x1324>
			1324: R_PPC_REL24	fn_80201D2C
    1328:	7f a3 eb 78 	mr      r3,r29
    132c:	38 80 00 01 	li      r4,1
    1330:	48 00 00 01 	bl      1330 <fn_800614A8+0x1330>
			1330: R_PPC_REL24	fn_80201D14
    1334:	38 60 00 01 	li      r3,1
    1338:	48 00 06 dc 	b       1a14 <fn_800614A8+0x1a14>
    133c:	2c 17 00 35 	cmpwi   r23,53
    1340:	40 82 06 d0 	bne     1a10 <fn_800614A8+0x1a10>
    1344:	38 60 00 01 	li      r3,1
    1348:	48 00 06 cc 	b       1a14 <fn_800614A8+0x1a14>
    134c:	2c 18 00 20 	cmpwi   r24,32
    1350:	40 82 01 80 	bne     14d0 <fn_800614A8+0x14d0>
    1354:	2c 17 00 03 	cmpwi   r23,3
    1358:	40 82 00 24 	bne     137c <fn_800614A8+0x137c>
    135c:	7f 43 d3 78 	mr      r3,r26
    1360:	7f a4 eb 78 	mr      r4,r29
    1364:	7f e5 fb 78 	mr      r5,r31
    1368:	7e a6 ab 78 	mr      r6,r21
    136c:	7f 87 e3 78 	mr      r7,r28
    1370:	48 00 00 01 	bl      1370 <fn_800614A8+0x1370>
			1370: R_PPC_REL24	fn_8005FD84
    1374:	38 60 00 01 	li      r3,1
    1378:	48 00 06 9c 	b       1a14 <fn_800614A8+0x1a14>
    137c:	2c 17 00 05 	cmpwi   r23,5
    1380:	40 82 00 80 	bne     1400 <fn_800614A8+0x1400>
    1384:	7f e3 fb 78 	mr      r3,r31
    1388:	48 00 00 01 	bl      1388 <fn_800614A8+0x1388>
			1388: R_PPC_REL24	fn_80128EAC
    138c:	7c 70 1b 78 	mr      r16,r3
    1390:	7f e3 fb 78 	mr      r3,r31
    1394:	48 00 00 01 	bl      1394 <fn_800614A8+0x1394>
			1394: R_PPC_REL24	fn_801290D0
    1398:	7c 6f 1b 78 	mr      r15,r3
    139c:	7f e3 fb 78 	mr      r3,r31
    13a0:	48 00 00 01 	bl      13a0 <fn_800614A8+0x13a0>
			13a0: R_PPC_REL24	fn_80128E30
    13a4:	28 03 00 00 	cmplwi  r3,0
    13a8:	41 82 00 38 	beq     13e0 <fn_800614A8+0x13e0>
    13ac:	2c 10 00 0f 	cmpwi   r16,15
    13b0:	40 82 00 30 	bne     13e0 <fn_800614A8+0x13e0>
    13b4:	55 e0 07 ff 	clrlwi. r0,r15,31
    13b8:	41 82 00 28 	beq     13e0 <fn_800614A8+0x13e0>
    13bc:	7f e3 fb 78 	mr      r3,r31
    13c0:	48 00 00 01 	bl      13c0 <fn_800614A8+0x13c0>
			13c0: R_PPC_REL24	fn_8012B344
    13c4:	7f a3 eb 78 	mr      r3,r29
    13c8:	38 80 00 01 	li      r4,1
    13cc:	48 00 00 01 	bl      13cc <fn_800614A8+0x13cc>
			13cc: R_PPC_REL24	fn_80201D2C
    13d0:	7f a3 eb 78 	mr      r3,r29
    13d4:	38 80 00 01 	li      r4,1
    13d8:	48 00 00 01 	bl      13d8 <fn_800614A8+0x13d8>
			13d8: R_PPC_REL24	fn_80201D14
    13dc:	48 00 00 1c 	b       13f8 <fn_800614A8+0x13f8>
    13e0:	7f a3 eb 78 	mr      r3,r29
    13e4:	38 80 00 01 	li      r4,1
    13e8:	48 00 00 01 	bl      13e8 <fn_800614A8+0x13e8>
			13e8: R_PPC_REL24	fn_80201D2C
    13ec:	7f a3 eb 78 	mr      r3,r29
    13f0:	38 80 00 01 	li      r4,1
    13f4:	48 00 00 01 	bl      13f4 <fn_800614A8+0x13f4>
			13f4: R_PPC_REL24	fn_80201D14
    13f8:	38 60 00 01 	li      r3,1
    13fc:	48 00 06 18 	b       1a14 <fn_800614A8+0x1a14>
    1400:	2c 17 00 07 	cmpwi   r23,7
    1404:	40 82 00 48 	bne     144c <fn_800614A8+0x144c>
    1408:	7f a3 eb 78 	mr      r3,r29
    140c:	38 96 01 f0 	addi    r4,r22,496
    1410:	38 d6 01 cc 	addi    r6,r22,460
    1414:	39 16 01 d8 	addi    r8,r22,472
    1418:	38 a0 00 00 	li      r5,0
			1418: R_PPC_EMB_SDA21	lbl_8064B51C
    141c:	38 e0 00 00 	li      r7,0
			141c: R_PPC_EMB_SDA21	lbl_8064B510
    1420:	48 00 00 01 	bl      1420 <fn_800614A8+0x1420>
			1420: R_PPC_REL24	fn_80035FB8
    1424:	2c 03 00 00 	cmpwi   r3,0
    1428:	40 82 00 1c 	bne     1444 <fn_800614A8+0x1444>
    142c:	7f a3 eb 78 	mr      r3,r29
    1430:	38 80 00 01 	li      r4,1
    1434:	48 00 00 01 	bl      1434 <fn_800614A8+0x1434>
			1434: R_PPC_REL24	fn_80201D2C
    1438:	7f a3 eb 78 	mr      r3,r29
    143c:	38 80 00 01 	li      r4,1
    1440:	48 00 00 01 	bl      1440 <fn_800614A8+0x1440>
			1440: R_PPC_REL24	fn_80201D14
    1444:	38 60 00 01 	li      r3,1
    1448:	48 00 05 cc 	b       1a14 <fn_800614A8+0x1a14>
    144c:	2c 17 00 3d 	cmpwi   r23,61
    1450:	40 82 00 38 	bne     1488 <fn_800614A8+0x1488>
    1454:	7f a3 eb 78 	mr      r3,r29
    1458:	7f 64 db 78 	mr      r4,r27
    145c:	48 00 00 01 	bl      145c <fn_800614A8+0x145c>
			145c: R_PPC_REL24	fn_800EA3A0
    1460:	7f a3 eb 78 	mr      r3,r29
    1464:	7f 64 db 78 	mr      r4,r27
    1468:	48 00 00 01 	bl      1468 <fn_800614A8+0x1468>
			1468: R_PPC_REL24	fn_800BD2DC
    146c:	7f 44 d3 78 	mr      r4,r26
    1470:	7f 45 d3 78 	mr      r5,r26
    1474:	38 60 00 05 	li      r3,5
    1478:	38 c0 00 00 	li      r6,0
    147c:	48 00 00 01 	bl      147c <fn_800614A8+0x147c>
			147c: R_PPC_REL24	fn_8020123C
    1480:	38 60 00 01 	li      r3,1
    1484:	48 00 05 90 	b       1a14 <fn_800614A8+0x1a14>
    1488:	2c 17 00 02 	cmpwi   r23,2
    148c:	40 82 00 24 	bne     14b0 <fn_800614A8+0x14b0>
    1490:	7f 43 d3 78 	mr      r3,r26
    1494:	7f 44 d3 78 	mr      r4,r26
    1498:	38 a0 00 20 	li      r5,32
    149c:	38 c0 00 05 	li      r6,5
    14a0:	38 e0 00 00 	li      r7,0
    14a4:	48 00 00 01 	bl      14a4 <fn_800614A8+0x14a4>
			14a4: R_PPC_REL24	fn_802006D4
    14a8:	38 60 00 01 	li      r3,1
    14ac:	48 00 05 68 	b       1a14 <fn_800614A8+0x1a14>
    14b0:	2c 17 00 35 	cmpwi   r23,53
    14b4:	40 82 00 0c 	bne     14c0 <fn_800614A8+0x14c0>
    14b8:	38 60 00 01 	li      r3,1
    14bc:	48 00 05 58 	b       1a14 <fn_800614A8+0x1a14>
    14c0:	2c 17 00 67 	cmpwi   r23,103
    14c4:	40 82 05 4c 	bne     1a10 <fn_800614A8+0x1a10>
    14c8:	38 60 00 01 	li      r3,1
    14cc:	48 00 05 48 	b       1a14 <fn_800614A8+0x1a14>
    14d0:	2c 18 00 08 	cmpwi   r24,8
    14d4:	40 82 03 50 	bne     1824 <fn_800614A8+0x1824>
    14d8:	2c 17 00 01 	cmpwi   r23,1
    14dc:	40 82 00 60 	bne     153c <fn_800614A8+0x153c>
    14e0:	7f e3 fb 78 	mr      r3,r31
    14e4:	48 00 00 01 	bl      14e4 <fn_800614A8+0x14e4>
			14e4: R_PPC_REL24	fn_80128EAC
    14e8:	7f e3 fb 78 	mr      r3,r31
    14ec:	48 00 00 01 	bl      14ec <fn_800614A8+0x14ec>
			14ec: R_PPC_REL24	fn_801290D0
    14f0:	7f a3 eb 78 	mr      r3,r29
    14f4:	38 80 00 00 	li      r4,0
    14f8:	48 00 00 01 	bl      14f8 <fn_800614A8+0x14f8>
			14f8: R_PPC_REL24	fn_80201350
    14fc:	88 75 00 9f 	lbz     r3,159(r21)
    1500:	48 00 00 01 	bl      1500 <fn_800614A8+0x1500>
			1500: R_PPC_REL24	fn_800CA13C
    1504:	54 64 08 3c 	slwi    r4,r3,1
    1508:	7f a3 eb 78 	mr      r3,r29
    150c:	38 a0 00 00 	li      r5,0
    1510:	48 00 00 01 	bl      1510 <fn_800614A8+0x1510>
			1510: R_PPC_REL24	fn_800E0708
    1514:	7f a3 eb 78 	mr      r3,r29
    1518:	38 80 00 01 	li      r4,1
    151c:	38 a0 00 00 	li      r5,0
    1520:	48 00 00 01 	bl      1520 <fn_800614A8+0x1520>
			1520: R_PPC_REL24	fn_800CC860
    1524:	7f 43 d3 78 	mr      r3,r26
    1528:	48 00 00 01 	bl      1528 <fn_800614A8+0x1528>
			1528: R_PPC_REL24	fn_800BE8D4
    152c:	7f a3 eb 78 	mr      r3,r29
    1530:	48 00 00 01 	bl      1530 <fn_800614A8+0x1530>
			1530: R_PPC_REL24	fn_800CA2C8
    1534:	38 60 00 01 	li      r3,1
    1538:	48 00 04 dc 	b       1a14 <fn_800614A8+0x1a14>
    153c:	2c 17 00 03 	cmpwi   r23,3
    1540:	40 82 00 40 	bne     1580 <fn_800614A8+0x1580>
    1544:	7f e3 fb 78 	mr      r3,r31
    1548:	48 00 00 01 	bl      1548 <fn_800614A8+0x1548>
			1548: R_PPC_REL24	fn_80128EAC
    154c:	7c 6f 1b 78 	mr      r15,r3
    1550:	7f e3 fb 78 	mr      r3,r31
    1554:	48 00 00 01 	bl      1554 <fn_800614A8+0x1554>
			1554: R_PPC_REL24	fn_801290D0
    1558:	2c 0f 00 18 	cmpwi   r15,24
    155c:	41 82 00 08 	beq     1564 <fn_800614A8+0x1564>
    1560:	60 00 00 00 	nop
    1564:	7f a3 eb 78 	mr      r3,r29
    1568:	7f e4 fb 78 	mr      r4,r31
    156c:	7f 45 d3 78 	mr      r5,r26
    1570:	7f 66 db 78 	mr      r6,r27
    1574:	48 00 00 01 	bl      1574 <fn_800614A8+0x1574>
			1574: R_PPC_REL24	fn_8003E5DC
    1578:	38 60 00 01 	li      r3,1
    157c:	48 00 04 98 	b       1a14 <fn_800614A8+0x1a14>
    1580:	2c 17 00 3d 	cmpwi   r23,61
    1584:	40 82 00 2c 	bne     15b0 <fn_800614A8+0x15b0>
    1588:	7f a3 eb 78 	mr      r3,r29
    158c:	7f 64 db 78 	mr      r4,r27
    1590:	48 00 00 01 	bl      1590 <fn_800614A8+0x1590>
			1590: R_PPC_REL24	fn_800EA3A0
    1594:	7f 44 d3 78 	mr      r4,r26
    1598:	7f 45 d3 78 	mr      r5,r26
    159c:	38 60 00 39 	li      r3,57
    15a0:	38 c0 00 00 	li      r6,0
    15a4:	48 00 00 01 	bl      15a4 <fn_800614A8+0x15a4>
			15a4: R_PPC_REL24	fn_8020123C
    15a8:	38 60 00 01 	li      r3,1
    15ac:	48 00 04 68 	b       1a14 <fn_800614A8+0x1a14>
    15b0:	2c 17 00 c1 	cmpwi   r23,193
    15b4:	40 82 00 24 	bne     15d8 <fn_800614A8+0x15d8>
    15b8:	28 1e 00 00 	cmplwi  r30,0
    15bc:	41 82 00 14 	beq     15d0 <fn_800614A8+0x15d0>
    15c0:	7f e3 fb 78 	mr      r3,r31
    15c4:	7e a4 ab 78 	mr      r4,r21
    15c8:	48 00 00 01 	bl      15c8 <fn_800614A8+0x15c8>
			15c8: R_PPC_REL24	fn_800C9BA8
    15cc:	90 7e 00 00 	stw     r3,0(r30)
    15d0:	38 60 00 01 	li      r3,1
    15d4:	48 00 04 40 	b       1a14 <fn_800614A8+0x1a14>
    15d8:	2c 17 00 2f 	cmpwi   r23,47
    15dc:	40 82 00 24 	bne     1600 <fn_800614A8+0x1600>
    15e0:	7f a3 eb 78 	mr      r3,r29
    15e4:	38 80 00 1f 	li      r4,31
    15e8:	48 00 00 01 	bl      15e8 <fn_800614A8+0x15e8>
			15e8: R_PPC_REL24	fn_80201D2C
    15ec:	7f a3 eb 78 	mr      r3,r29
    15f0:	38 80 00 01 	li      r4,1
    15f4:	48 00 00 01 	bl      15f4 <fn_800614A8+0x15f4>
			15f4: R_PPC_REL24	fn_80201D14
    15f8:	38 60 00 01 	li      r3,1
    15fc:	48 00 04 18 	b       1a14 <fn_800614A8+0x1a14>
    1600:	2c 17 00 c2 	cmpwi   r23,194
    1604:	40 82 00 20 	bne     1624 <fn_800614A8+0x1624>
    1608:	7f a3 eb 78 	mr      r3,r29
    160c:	7f e4 fb 78 	mr      r4,r31
    1610:	7f 25 cb 78 	mr      r5,r25
    1614:	7f c6 f3 78 	mr      r6,r30
    1618:	48 00 00 01 	bl      1618 <fn_800614A8+0x1618>
			1618: R_PPC_REL24	fn_800CA1BC
    161c:	38 60 00 01 	li      r3,1
    1620:	48 00 03 f4 	b       1a14 <fn_800614A8+0x1a14>
    1624:	2c 17 00 11 	cmpwi   r23,17
    1628:	40 82 00 78 	bne     16a0 <fn_800614A8+0x16a0>
    162c:	7f a3 eb 78 	mr      r3,r29
    1630:	48 00 00 01 	bl      1630 <fn_800614A8+0x1630>
			1630: R_PPC_REL24	fn_8003C04C
    1634:	2c 03 00 00 	cmpwi   r3,0
    1638:	41 82 00 60 	beq     1698 <fn_800614A8+0x1698>
    163c:	7f a3 eb 78 	mr      r3,r29
    1640:	7f 64 db 78 	mr      r4,r27
    1644:	48 00 00 01 	bl      1644 <fn_800614A8+0x1644>
			1644: R_PPC_REL24	fn_800EA3A0
    1648:	7f a3 eb 78 	mr      r3,r29
    164c:	48 00 00 01 	bl      164c <fn_800614A8+0x164c>
			164c: R_PPC_REL24	fn_800CF598
    1650:	c0 20 00 00 	lfs     f1,0(0)
			1650: R_PPC_EMB_SDA21	lbl_8064E62C
    1654:	7f e3 fb 78 	mr      r3,r31
    1658:	c0 40 00 00 	lfs     f2,0(0)
			1658: R_PPC_EMB_SDA21	lbl_8064E5DC
    165c:	38 80 00 00 	li      r4,0
    1660:	38 a0 00 00 	li      r5,0
    1664:	38 c0 01 01 	li      r6,257
    1668:	48 00 00 01 	bl      1668 <fn_800614A8+0x1668>
			1668: R_PPC_REL24	fn_80120AD0
    166c:	7f e3 fb 78 	mr      r3,r31
    1670:	38 80 00 28 	li      r4,40
    1674:	38 a0 00 21 	li      r5,33
    1678:	38 c0 00 0a 	li      r6,10
    167c:	48 00 00 01 	bl      167c <fn_800614A8+0x167c>
			167c: R_PPC_REL24	fn_801294DC
    1680:	7f a3 eb 78 	mr      r3,r29
    1684:	38 80 00 15 	li      r4,21
    1688:	48 00 00 01 	bl      1688 <fn_800614A8+0x1688>
			1688: R_PPC_REL24	fn_80201D34
    168c:	7f a3 eb 78 	mr      r3,r29
    1690:	38 80 00 01 	li      r4,1
    1694:	48 00 00 01 	bl      1694 <fn_800614A8+0x1694>
			1694: R_PPC_REL24	fn_80201D1C
    1698:	38 60 00 01 	li      r3,1
    169c:	48 00 03 78 	b       1a14 <fn_800614A8+0x1a14>
    16a0:	2c 17 00 0b 	cmpwi   r23,11
    16a4:	40 82 00 68 	bne     170c <fn_800614A8+0x170c>
    16a8:	7f 23 cb 78 	mr      r3,r25
    16ac:	48 00 00 01 	bl      16ac <fn_800614A8+0x16ac>
			16ac: R_PPC_REL24	fn_80200C38
    16b0:	7c 6f 1b 78 	mr      r15,r3
    16b4:	48 00 00 01 	bl      16b4 <fn_800614A8+0x16b4>
			16b4: R_PPC_REL24	fn_801A74C0
    16b8:	54 60 06 b5 	rlwinm. r0,r3,0,26,26
    16bc:	41 82 00 48 	beq     1704 <fn_800614A8+0x1704>
    16c0:	7d e3 7b 78 	mr      r3,r15
    16c4:	48 00 00 01 	bl      16c4 <fn_800614A8+0x16c4>
			16c4: R_PPC_REL24	fn_800654F8
    16c8:	7c 6f 1b 78 	mr      r15,r3
    16cc:	7f 44 d3 78 	mr      r4,r26
    16d0:	7f 45 d3 78 	mr      r5,r26
    16d4:	38 60 00 2f 	li      r3,47
    16d8:	38 c0 00 00 	li      r6,0
    16dc:	48 00 00 01 	bl      16dc <fn_800614A8+0x16dc>
			16dc: R_PPC_REL24	fn_8020123C
    16e0:	c0 20 00 00 	lfs     f1,0(0)
			16e0: R_PPC_EMB_SDA21	lbl_8064E630
    16e4:	7f 44 d3 78 	mr      r4,r26
    16e8:	7f 45 d3 78 	mr      r5,r26
    16ec:	38 60 00 31 	li      r3,49
    16f0:	38 c0 00 00 	li      r6,0
    16f4:	48 00 00 01 	bl      16f4 <fn_800614A8+0x16f4>
			16f4: R_PPC_REL24	fn_8020104C
    16f8:	28 1e 00 00 	cmplwi  r30,0
    16fc:	41 82 00 08 	beq     1704 <fn_800614A8+0x1704>
    1700:	91 fe 00 00 	stw     r15,0(r30)
    1704:	38 60 00 01 	li      r3,1
    1708:	48 00 03 0c 	b       1a14 <fn_800614A8+0x1a14>
    170c:	2c 17 00 35 	cmpwi   r23,53
    1710:	40 82 00 28 	bne     1738 <fn_800614A8+0x1738>
    1714:	7f 23 cb 78 	mr      r3,r25
    1718:	48 00 00 01 	bl      1718 <fn_800614A8+0x1718>
			1718: R_PPC_REL24	fn_80200C38
    171c:	c0 20 00 00 	lfs     f1,0(0)
			171c: R_PPC_EMB_SDA21	lbl_8064E614
    1720:	7c 64 1b 78 	mr      r4,r3
    1724:	c0 40 00 00 	lfs     f2,0(0)
			1724: R_PPC_EMB_SDA21	lbl_8064E618
    1728:	7f e3 fb 78 	mr      r3,r31
    172c:	48 00 00 01 	bl      172c <fn_800614A8+0x172c>
			172c: R_PPC_REL24	fn_80066888
    1730:	38 60 00 01 	li      r3,1
    1734:	48 00 02 e0 	b       1a14 <fn_800614A8+0x1a14>
    1738:	2c 17 00 4e 	cmpwi   r23,78
    173c:	40 82 00 1c 	bne     1758 <fn_800614A8+0x1758>
    1740:	28 1e 00 00 	cmplwi  r30,0
    1744:	41 82 00 0c 	beq     1750 <fn_800614A8+0x1750>
    1748:	38 00 00 00 	li      r0,0
    174c:	90 1e 00 00 	stw     r0,0(r30)
    1750:	38 60 00 01 	li      r3,1
    1754:	48 00 02 c0 	b       1a14 <fn_800614A8+0x1a14>
    1758:	2c 17 00 33 	cmpwi   r23,51
    175c:	40 82 00 20 	bne     177c <fn_800614A8+0x177c>
    1760:	7f 44 d3 78 	mr      r4,r26
    1764:	7f 45 d3 78 	mr      r5,r26
    1768:	38 60 00 39 	li      r3,57
    176c:	38 c0 00 00 	li      r6,0
    1770:	48 00 00 01 	bl      1770 <fn_800614A8+0x1770>
			1770: R_PPC_REL24	fn_8020123C
    1774:	38 60 00 01 	li      r3,1
    1778:	48 00 02 9c 	b       1a14 <fn_800614A8+0x1a14>
    177c:	2c 17 00 02 	cmpwi   r23,2
    1780:	40 82 00 24 	bne     17a4 <fn_800614A8+0x17a4>
    1784:	7f 43 d3 78 	mr      r3,r26
    1788:	7f 44 d3 78 	mr      r4,r26
    178c:	38 a0 00 08 	li      r5,8
    1790:	38 c0 00 11 	li      r6,17
    1794:	38 e0 00 00 	li      r7,0
    1798:	48 00 00 01 	bl      1798 <fn_800614A8+0x1798>
			1798: R_PPC_REL24	fn_802006D4
    179c:	38 60 00 01 	li      r3,1
    17a0:	48 00 02 74 	b       1a14 <fn_800614A8+0x1a14>
    17a4:	2c 17 00 3b 	cmpwi   r23,59
    17a8:	40 82 00 0c 	bne     17b4 <fn_800614A8+0x17b4>
    17ac:	38 60 00 01 	li      r3,1
    17b0:	48 00 02 64 	b       1a14 <fn_800614A8+0x1a14>
    17b4:	2c 17 00 08 	cmpwi   r23,8
    17b8:	40 82 00 0c 	bne     17c4 <fn_800614A8+0x17c4>
    17bc:	38 60 00 01 	li      r3,1
    17c0:	48 00 02 54 	b       1a14 <fn_800614A8+0x1a14>
    17c4:	2c 17 00 35 	cmpwi   r23,53
    17c8:	40 82 00 0c 	bne     17d4 <fn_800614A8+0x17d4>
    17cc:	38 60 00 01 	li      r3,1
    17d0:	48 00 02 44 	b       1a14 <fn_800614A8+0x1a14>
    17d4:	2c 17 00 32 	cmpwi   r23,50
    17d8:	40 82 00 0c 	bne     17e4 <fn_800614A8+0x17e4>
    17dc:	38 60 00 01 	li      r3,1
    17e0:	48 00 02 34 	b       1a14 <fn_800614A8+0x1a14>
    17e4:	2c 17 00 0b 	cmpwi   r23,11
    17e8:	40 82 00 0c 	bne     17f4 <fn_800614A8+0x17f4>
    17ec:	38 60 00 01 	li      r3,1
    17f0:	48 00 02 24 	b       1a14 <fn_800614A8+0x1a14>
    17f4:	2c 17 00 27 	cmpwi   r23,39
    17f8:	40 82 00 0c 	bne     1804 <fn_800614A8+0x1804>
    17fc:	38 60 00 01 	li      r3,1
    1800:	48 00 02 14 	b       1a14 <fn_800614A8+0x1a14>
    1804:	2c 17 00 67 	cmpwi   r23,103
    1808:	40 82 00 0c 	bne     1814 <fn_800614A8+0x1814>
    180c:	38 60 00 01 	li      r3,1
    1810:	48 00 02 04 	b       1a14 <fn_800614A8+0x1a14>
    1814:	2c 17 00 ea 	cmpwi   r23,234
    1818:	40 82 01 f8 	bne     1a10 <fn_800614A8+0x1a10>
    181c:	38 60 00 01 	li      r3,1
    1820:	48 00 01 f4 	b       1a14 <fn_800614A8+0x1a14>
    1824:	2c 18 00 1f 	cmpwi   r24,31
    1828:	40 82 01 e0 	bne     1a08 <fn_800614A8+0x1a08>
    182c:	2c 17 00 01 	cmpwi   r23,1
    1830:	40 82 00 68 	bne     1898 <fn_800614A8+0x1898>
    1834:	7f e3 fb 78 	mr      r3,r31
    1838:	48 00 00 01 	bl      1838 <fn_800614A8+0x1838>
			1838: R_PPC_REL24	fn_80128EAC
    183c:	7f e3 fb 78 	mr      r3,r31
    1840:	48 00 00 01 	bl      1840 <fn_800614A8+0x1840>
			1840: R_PPC_REL24	fn_801290D0
    1844:	7f 43 d3 78 	mr      r3,r26
    1848:	48 00 00 01 	bl      1848 <fn_800614A8+0x1848>
			1848: R_PPC_REL24	fn_800BE8D4
    184c:	7f a3 eb 78 	mr      r3,r29
    1850:	38 80 00 02 	li      r4,2
    1854:	38 a0 00 03 	li      r5,3
    1858:	48 00 00 01 	bl      1858 <fn_800614A8+0x1858>
			1858: R_PPC_REL24	fn_800CC860
    185c:	7f e3 fb 78 	mr      r3,r31
    1860:	38 80 00 33 	li      r4,51
    1864:	48 00 00 01 	bl      1864 <fn_800614A8+0x1864>
			1864: R_PPC_REL24	fn_801A977C
    1868:	7f a3 eb 78 	mr      r3,r29
    186c:	48 00 00 01 	bl      186c <fn_800614A8+0x186c>
			186c: R_PPC_REL24	fn_800CA2C8
    1870:	7f a3 eb 78 	mr      r3,r29
    1874:	48 00 00 01 	bl      1874 <fn_800614A8+0x1874>
			1874: R_PPC_REL24	fn_80204FDC
    1878:	c0 20 00 00 	lfs     f1,0(0)
			1878: R_PPC_EMB_SDA21	lbl_8064E634
    187c:	7f 44 d3 78 	mr      r4,r26
    1880:	7f 45 d3 78 	mr      r5,r26
    1884:	38 60 00 11 	li      r3,17
    1888:	38 c0 00 00 	li      r6,0
    188c:	48 00 00 01 	bl      188c <fn_800614A8+0x188c>
			188c: R_PPC_REL24	fn_8020104C
    1890:	38 60 00 01 	li      r3,1
    1894:	48 00 01 80 	b       1a14 <fn_800614A8+0x1a14>
    1898:	2c 17 00 30 	cmpwi   r23,48
    189c:	40 82 00 24 	bne     18c0 <fn_800614A8+0x18c0>
    18a0:	7f 23 cb 78 	mr      r3,r25
    18a4:	48 00 00 01 	bl      18a4 <fn_800614A8+0x18a4>
			18a4: R_PPC_REL24	fn_80200C38
    18a8:	48 00 00 01 	bl      18a8 <fn_800614A8+0x18a8>
			18a8: R_PPC_REL24	fn_800654F8
    18ac:	28 1e 00 00 	cmplwi  r30,0
    18b0:	41 82 00 08 	beq     18b8 <fn_800614A8+0x18b8>
    18b4:	90 7e 00 00 	stw     r3,0(r30)
    18b8:	38 60 00 01 	li      r3,1
    18bc:	48 00 01 58 	b       1a14 <fn_800614A8+0x1a14>
    18c0:	2c 17 00 31 	cmpwi   r23,49
    18c4:	40 82 00 1c 	bne     18e0 <fn_800614A8+0x18e0>
    18c8:	7f a3 eb 78 	mr      r3,r29
    18cc:	7f e4 fb 78 	mr      r4,r31
    18d0:	7f 45 d3 78 	mr      r5,r26
    18d4:	48 00 00 01 	bl      18d4 <fn_800614A8+0x18d4>
			18d4: R_PPC_REL24	fn_8003C114
    18d8:	38 60 00 01 	li      r3,1
    18dc:	48 00 01 38 	b       1a14 <fn_800614A8+0x1a14>
    18e0:	2c 17 00 3d 	cmpwi   r23,61
    18e4:	40 82 00 2c 	bne     1910 <fn_800614A8+0x1910>
    18e8:	7f a3 eb 78 	mr      r3,r29
    18ec:	7f 64 db 78 	mr      r4,r27
    18f0:	48 00 00 01 	bl      18f0 <fn_800614A8+0x18f0>
			18f0: R_PPC_REL24	fn_800EA3A0
    18f4:	7f 44 d3 78 	mr      r4,r26
    18f8:	7f 45 d3 78 	mr      r5,r26
    18fc:	38 60 00 39 	li      r3,57
    1900:	38 c0 00 00 	li      r6,0
    1904:	48 00 00 01 	bl      1904 <fn_800614A8+0x1904>
			1904: R_PPC_REL24	fn_8020123C
    1908:	38 60 00 01 	li      r3,1
    190c:	48 00 01 08 	b       1a14 <fn_800614A8+0x1a14>
    1910:	2c 17 00 11 	cmpwi   r23,17
    1914:	40 82 00 54 	bne     1968 <fn_800614A8+0x1968>
    1918:	7f a3 eb 78 	mr      r3,r29
    191c:	7f 64 db 78 	mr      r4,r27
    1920:	48 00 00 01 	bl      1920 <fn_800614A8+0x1920>
			1920: R_PPC_REL24	fn_800EA3A0
    1924:	7f a3 eb 78 	mr      r3,r29
    1928:	48 00 00 01 	bl      1928 <fn_800614A8+0x1928>
			1928: R_PPC_REL24	fn_800CF598
    192c:	c0 20 00 00 	lfs     f1,0(0)
			192c: R_PPC_EMB_SDA21	lbl_8064E62C
    1930:	7f e3 fb 78 	mr      r3,r31
    1934:	c0 40 00 00 	lfs     f2,0(0)
			1934: R_PPC_EMB_SDA21	lbl_8064E5DC
    1938:	38 80 00 00 	li      r4,0
    193c:	38 a0 00 00 	li      r5,0
    1940:	38 c0 01 01 	li      r6,257
    1944:	48 00 00 01 	bl      1944 <fn_800614A8+0x1944>
			1944: R_PPC_REL24	fn_80120AD0
    1948:	7f a3 eb 78 	mr      r3,r29
    194c:	38 80 00 15 	li      r4,21
    1950:	48 00 00 01 	bl      1950 <fn_800614A8+0x1950>
			1950: R_PPC_REL24	fn_80201D34
    1954:	7f a3 eb 78 	mr      r3,r29
    1958:	38 80 00 01 	li      r4,1
    195c:	48 00 00 01 	bl      195c <fn_800614A8+0x195c>
			195c: R_PPC_REL24	fn_80201D1C
    1960:	38 60 00 01 	li      r3,1
    1964:	48 00 00 b0 	b       1a14 <fn_800614A8+0x1a14>
    1968:	2c 17 00 4e 	cmpwi   r23,78
    196c:	40 82 00 1c 	bne     1988 <fn_800614A8+0x1988>
    1970:	28 1e 00 00 	cmplwi  r30,0
    1974:	41 82 00 0c 	beq     1980 <fn_800614A8+0x1980>
    1978:	38 00 00 00 	li      r0,0
    197c:	90 1e 00 00 	stw     r0,0(r30)
    1980:	38 60 00 01 	li      r3,1
    1984:	48 00 00 90 	b       1a14 <fn_800614A8+0x1a14>
    1988:	2c 17 00 3b 	cmpwi   r23,59
    198c:	40 82 00 0c 	bne     1998 <fn_800614A8+0x1998>
    1990:	38 60 00 01 	li      r3,1
    1994:	48 00 00 80 	b       1a14 <fn_800614A8+0x1a14>
    1998:	2c 17 00 08 	cmpwi   r23,8
    199c:	40 82 00 0c 	bne     19a8 <fn_800614A8+0x19a8>
    19a0:	38 60 00 01 	li      r3,1
    19a4:	48 00 00 70 	b       1a14 <fn_800614A8+0x1a14>
    19a8:	2c 17 00 35 	cmpwi   r23,53
    19ac:	40 82 00 0c 	bne     19b8 <fn_800614A8+0x19b8>
    19b0:	38 60 00 01 	li      r3,1
    19b4:	48 00 00 60 	b       1a14 <fn_800614A8+0x1a14>
    19b8:	2c 17 00 32 	cmpwi   r23,50
    19bc:	40 82 00 0c 	bne     19c8 <fn_800614A8+0x19c8>
    19c0:	38 60 00 01 	li      r3,1
    19c4:	48 00 00 50 	b       1a14 <fn_800614A8+0x1a14>
    19c8:	2c 17 00 0b 	cmpwi   r23,11
    19cc:	40 82 00 0c 	bne     19d8 <fn_800614A8+0x19d8>
    19d0:	38 60 00 01 	li      r3,1
    19d4:	48 00 00 40 	b       1a14 <fn_800614A8+0x1a14>
    19d8:	2c 17 00 27 	cmpwi   r23,39
    19dc:	40 82 00 0c 	bne     19e8 <fn_800614A8+0x19e8>
    19e0:	38 60 00 01 	li      r3,1
    19e4:	48 00 00 30 	b       1a14 <fn_800614A8+0x1a14>
    19e8:	2c 17 00 67 	cmpwi   r23,103
    19ec:	40 82 00 0c 	bne     19f8 <fn_800614A8+0x19f8>
    19f0:	38 60 00 01 	li      r3,1
    19f4:	48 00 00 20 	b       1a14 <fn_800614A8+0x1a14>
    19f8:	2c 17 00 ea 	cmpwi   r23,234
    19fc:	40 82 00 14 	bne     1a10 <fn_800614A8+0x1a10>
    1a00:	38 60 00 01 	li      r3,1
    1a04:	48 00 00 10 	b       1a14 <fn_800614A8+0x1a14>
    1a08:	38 60 00 00 	li      r3,0
    1a0c:	48 00 00 08 	b       1a14 <fn_800614A8+0x1a14>
    1a10:	38 60 00 00 	li      r3,0
    1a14:	b9 e1 00 ec 	lmw     r15,236(r1)
    1a18:	80 01 01 34 	lwz     r0,308(r1)
    1a1c:	7c 08 03 a6 	mtlr    r0
    1a20:	38 21 01 30 	addi    r1,r1,304
    1a24:	4e 80 00 20 	blr

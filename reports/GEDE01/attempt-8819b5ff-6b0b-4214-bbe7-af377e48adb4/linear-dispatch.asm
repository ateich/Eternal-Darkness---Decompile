
build/GEDE01/src/game/game_fn_800614A8.o:     file format elf32-powerpc


Disassembly of section .text:

00000000 <fn_800614A8>:
       0:	94 21 fe f0 	stwu    r1,-272(r1)
       4:	7c 08 02 a6 	mflr    r0
       8:	3c e0 00 00 	lis     r7,0
			a: R_PPC_ADDR16_HA	lbl_80243C30
       c:	90 01 01 14 	stw     r0,276(r1)
      10:	bd e1 00 cc 	stmw    r15,204(r1)
      14:	7c b8 2b 78 	mr      r24,r5
      18:	7c 7f 1b 78 	mr      r31,r3
      1c:	7c 97 23 78 	mr      r23,r4
      20:	7c d9 33 78 	mr      r25,r6
      24:	7f 03 c3 78 	mr      r3,r24
      28:	3a a7 00 00 	addi    r21,r7,0
			2a: R_PPC_ADDR16_LO	lbl_80243C30
      2c:	48 00 00 01 	bl      2c <fn_800614A8+0x2c>
			2c: R_PPC_REL24	fn_80200C10
      30:	7c 76 1b 78 	mr      r22,r3
      34:	7f e3 fb 78 	mr      r3,r31
      38:	48 00 00 01 	bl      38 <fn_800614A8+0x38>
			38: R_PPC_REL24	fn_80201BC8
      3c:	7c 60 1b 78 	mr      r0,r3
      40:	7f e3 fb 78 	mr      r3,r31
      44:	7c 1e 03 78 	mr      r30,r0
      48:	48 00 00 01 	bl      48 <fn_800614A8+0x48>
			48: R_PPC_REL24	fn_80201B8C
      4c:	7c 60 1b 78 	mr      r0,r3
      50:	7f e3 fb 78 	mr      r3,r31
      54:	7c 1b 03 78 	mr      r27,r0
      58:	83 bb 00 8c 	lwz     r29,140(r27)
      5c:	83 5b 00 08 	lwz     r26,8(r27)
      60:	48 00 00 01 	bl      60 <fn_800614A8+0x60>
			60: R_PPC_REL24	fn_80201B94
      64:	7c 60 1b 78 	mr      r0,r3
      68:	7f e3 fb 78 	mr      r3,r31
      6c:	7c 14 03 78 	mr      r20,r0
      70:	48 00 00 01 	bl      70 <fn_800614A8+0x70>
			70: R_PPC_REL24	fn_80201B54
      74:	7c 7c 1b 78 	mr      r28,r3
      78:	7f c4 f3 78 	mr      r4,r30
      7c:	38 61 00 78 	addi    r3,r1,120
      80:	48 00 00 01 	bl      80 <fn_800614A8+0x80>
			80: R_PPC_REL24	fn_8011F114
      84:	80 9b 00 8c 	lwz     r4,140(r27)
      88:	7f e3 fb 78 	mr      r3,r31
      8c:	80 c0 00 00 	lwz     r6,0(0)
			8c: R_PPC_EMB_SDA21	lbl_8064D5A8
      90:	a8 bb 00 9c 	lha     r5,156(r27)
      94:	88 04 01 61 	lbz     r0,353(r4)
      98:	7e 46 2a 14 	add     r18,r6,r5
      9c:	7c 10 07 74 	extsb   r16,r0
      a0:	48 00 00 01 	bl      a0 <fn_800614A8+0xa0>
			a0: R_PPC_REL24	fn_80201EB8
      a4:	2c 16 00 03 	cmpwi   r22,3
      a8:	7c 73 1b 78 	mr      r19,r3
      ac:	40 82 01 18 	bne     1c4 <fn_800614A8+0x1c4>
      b0:	7f e3 fb 78 	mr      r3,r31
      b4:	3a 20 00 00 	li      r17,0
      b8:	38 80 00 03 	li      r4,3
      bc:	48 00 00 01 	bl      bc <fn_800614A8+0xbc>
			bc: R_PPC_REL24	fn_80066D04
      c0:	2c 03 00 00 	cmpwi   r3,0
      c4:	40 82 00 1c 	bne     e0 <fn_800614A8+0xe0>
      c8:	7f e3 fb 78 	mr      r3,r31
      cc:	38 80 00 02 	li      r4,2
      d0:	48 00 00 01 	bl      d0 <fn_800614A8+0xd0>
			d0: R_PPC_REL24	fn_80066D04
      d4:	2c 03 00 00 	cmpwi   r3,0
      d8:	40 82 00 08 	bne     e0 <fn_800614A8+0xe0>
      dc:	3a 20 00 01 	li      r17,1
      e0:	7f e3 fb 78 	mr      r3,r31
      e4:	7e 84 a3 78 	mr      r4,r20
      e8:	48 00 00 01 	bl      e8 <fn_800614A8+0xe8>
			e8: R_PPC_REL24	fn_8005E9E4
      ec:	7c 6f 1b 78 	mr      r15,r3
      f0:	7f e3 fb 78 	mr      r3,r31
      f4:	48 00 00 01 	bl      f4 <fn_800614A8+0xf4>
			f4: R_PPC_REL24	fn_800CC4DC
      f8:	a8 7d 01 50 	lha     r3,336(r29)
      fc:	2c 03 00 01 	cmpwi   r3,1
     100:	41 80 00 08 	blt     108 <fn_800614A8+0x108>
     104:	38 63 ff ff 	addi    r3,r3,-1
     108:	b0 7d 01 50 	sth     r3,336(r29)
     10c:	a8 7d 01 58 	lha     r3,344(r29)
     110:	2c 03 00 01 	cmpwi   r3,1
     114:	41 80 00 08 	blt     11c <fn_800614A8+0x11c>
     118:	38 63 ff ff 	addi    r3,r3,-1
     11c:	2c 0f 03 e8 	cmpwi   r15,1000
     120:	b0 7d 01 58 	sth     r3,344(r29)
     124:	41 81 00 1c 	bgt     140 <fn_800614A8+0x140>
     128:	80 7b 00 8c 	lwz     r3,140(r27)
     12c:	80 03 00 00 	lwz     r0,0(r3)
     130:	54 00 02 11 	rlwinm. r0,r0,0,8,8
     134:	40 82 00 0c 	bne     140 <fn_800614A8+0x140>
     138:	2c 11 00 00 	cmpwi   r17,0
     13c:	41 82 00 18 	beq     154 <fn_800614A8+0x154>
     140:	a8 7d 01 4e 	lha     r3,334(r29)
     144:	2c 03 00 01 	cmpwi   r3,1
     148:	41 80 00 08 	blt     150 <fn_800614A8+0x150>
     14c:	38 63 ff ff 	addi    r3,r3,-1
     150:	b0 7d 01 4e 	sth     r3,334(r29)
     154:	a8 ba 00 86 	lha     r5,134(r26)
     158:	7f e3 fb 78 	mr      r3,r31
     15c:	6c a4 80 00 	xoris   r4,r5,32768
     160:	20 05 00 01 	subfic  r0,r5,1
     164:	7c 80 20 14 	addc    r4,r0,r4
     168:	38 05 ff ff 	addi    r0,r5,-1
     16c:	7c 84 21 10 	subfe   r4,r4,r4
     170:	7c 00 07 34 	extsh   r0,r0
     174:	7c 00 20 78 	andc    r0,r0,r4
     178:	b0 1a 00 86 	sth     r0,134(r26)
     17c:	48 00 00 01 	bl      17c <fn_800614A8+0x17c>
			17c: R_PPC_REL24	fn_800C9C60
     180:	80 00 00 00 	lwz     r0,0(0)
			180: R_PPC_EMB_SDA21	lbl_8064D5A8
     184:	54 00 06 3f 	clrlwi. r0,r0,24
     188:	40 82 00 0c 	bne     194 <fn_800614A8+0x194>
     18c:	7f e3 fb 78 	mr      r3,r31
     190:	48 00 00 01 	bl      190 <fn_800614A8+0x190>
			190: R_PPC_REL24	fn_800C9D68
     194:	7f c3 f3 78 	mr      r3,r30
     198:	48 00 00 01 	bl      198 <fn_800614A8+0x198>
			198: R_PPC_REL24	fn_8013017C
     19c:	54 60 06 73 	rlwinm. r0,r3,0,25,25
     1a0:	41 82 00 24 	beq     1c4 <fn_800614A8+0x1c4>
     1a4:	7f c3 f3 78 	mr      r3,r30
     1a8:	48 00 00 01 	bl      1a8 <fn_800614A8+0x1a8>
			1a8: R_PPC_REL24	fn_801305D4
     1ac:	2c 03 00 00 	cmpwi   r3,0
     1b0:	40 82 00 14 	bne     1c4 <fn_800614A8+0x1c4>
     1b4:	7f c3 f3 78 	mr      r3,r30
     1b8:	38 80 00 40 	li      r4,64
     1bc:	38 a0 00 00 	li      r5,0
     1c0:	48 00 00 01 	bl      1c0 <fn_800614A8+0x1c0>
			1c0: R_PPC_REL24	fn_801301B0
     1c4:	2c 17 00 00 	cmpwi   r23,0
     1c8:	40 82 07 14 	bne     8dc <fn_800614A8+0x8dc>
     1cc:	2c 16 00 01 	cmpwi   r22,1
     1d0:	40 82 00 4c 	bne     21c <fn_800614A8+0x21c>
     1d4:	48 00 00 01 	bl      1d4 <fn_800614A8+0x1d4>
			1d4: R_PPC_REL24	fn_800FBFB0
     1d8:	54 66 0f fe 	srwi    r6,r3,31
     1dc:	54 60 e8 04 	slwi    r0,r3,29
     1e0:	7c 86 00 50 	subf    r4,r6,r0
     1e4:	7f e3 fb 78 	mr      r3,r31
     1e8:	54 85 1f 7e 	srwi    r5,r4,29
     1ec:	38 00 00 1e 	li      r0,30
     1f0:	50 85 18 38 	rlwimi  r5,r4,3,0,28
     1f4:	38 80 00 01 	li      r4,1
     1f8:	7c a6 2a 14 	add     r5,r6,r5
     1fc:	90 ba 00 78 	stw     r5,120(r26)
     200:	b0 1a 00 86 	sth     r0,134(r26)
     204:	48 00 00 01 	bl      204 <fn_800614A8+0x204>
			204: R_PPC_REL24	fn_80201D2C
     208:	7f e3 fb 78 	mr      r3,r31
     20c:	38 80 00 01 	li      r4,1
     210:	48 00 00 01 	bl      210 <fn_800614A8+0x210>
			210: R_PPC_REL24	fn_80201D14
     214:	38 60 00 01 	li      r3,1
     218:	48 00 17 d4 	b       19ec <fn_800614A8+0x19ec>
     21c:	2c 16 00 f1 	cmpwi   r22,241
     220:	40 82 00 24 	bne     244 <fn_800614A8+0x244>
     224:	7e 63 9b 78 	mr      r3,r19
     228:	7f e4 fb 78 	mr      r4,r31
     22c:	7f c5 f3 78 	mr      r5,r30
     230:	7f 66 db 78 	mr      r6,r27
     234:	7f 07 c3 78 	mr      r7,r24
     238:	48 00 00 01 	bl      238 <fn_800614A8+0x238>
			238: R_PPC_REL24	fn_8005EC6C
     23c:	38 60 00 01 	li      r3,1
     240:	48 00 17 ac 	b       19ec <fn_800614A8+0x19ec>
     244:	2c 16 00 f5 	cmpwi   r22,245
     248:	40 82 00 24 	bne     26c <fn_800614A8+0x26c>
     24c:	7e 63 9b 78 	mr      r3,r19
     250:	7f e4 fb 78 	mr      r4,r31
     254:	7f c5 f3 78 	mr      r5,r30
     258:	7f 66 db 78 	mr      r6,r27
     25c:	7f 07 c3 78 	mr      r7,r24
     260:	48 00 00 01 	bl      260 <fn_800614A8+0x260>
			260: R_PPC_REL24	fn_8005EC6C
     264:	38 60 00 01 	li      r3,1
     268:	48 00 17 84 	b       19ec <fn_800614A8+0x19ec>
     26c:	2c 16 00 df 	cmpwi   r22,223
     270:	40 82 00 20 	bne     290 <fn_800614A8+0x290>
     274:	7e 63 9b 78 	mr      r3,r19
     278:	7f e4 fb 78 	mr      r4,r31
     27c:	7f 05 c3 78 	mr      r5,r24
     280:	38 c1 00 78 	addi    r6,r1,120
     284:	48 00 00 01 	bl      284 <fn_800614A8+0x284>
			284: R_PPC_REL24	fn_8005EA38
     288:	38 60 00 01 	li      r3,1
     28c:	48 00 17 60 	b       19ec <fn_800614A8+0x19ec>
     290:	2c 16 00 08 	cmpwi   r22,8
     294:	40 82 00 38 	bne     2cc <fn_800614A8+0x2cc>
     298:	80 00 00 00 	lwz     r0,0(0)
			298: R_PPC_EMB_SDA21	lbl_8064D18C
     29c:	7c 13 00 00 	cmpw    r19,r0
     2a0:	41 82 00 14 	beq     2b4 <fn_800614A8+0x2b4>
     2a4:	7f e4 fb 78 	mr      r4,r31
     2a8:	38 60 00 02 	li      r3,2
     2ac:	48 00 00 01 	bl      2ac <fn_800614A8+0x2ac>
			2ac: R_PPC_REL24	fn_801E8328
     2b0:	48 00 00 14 	b       2c4 <fn_800614A8+0x2c4>
     2b4:	7f e3 fb 78 	mr      r3,r31
     2b8:	7f 04 c3 78 	mr      r4,r24
     2bc:	38 a0 03 c0 	li      r5,960
     2c0:	48 00 00 01 	bl      2c0 <fn_800614A8+0x2c0>
			2c0: R_PPC_REL24	fn_800CD094
     2c4:	38 60 00 01 	li      r3,1
     2c8:	48 00 17 24 	b       19ec <fn_800614A8+0x19ec>
     2cc:	2c 16 00 3d 	cmpwi   r22,61
     2d0:	40 82 00 24 	bne     2f4 <fn_800614A8+0x2f4>
     2d4:	7f e3 fb 78 	mr      r3,r31
     2d8:	7f a4 eb 78 	mr      r4,r29
     2dc:	48 00 00 01 	bl      2dc <fn_800614A8+0x2dc>
			2dc: R_PPC_REL24	fn_800EA3A0
     2e0:	7f e3 fb 78 	mr      r3,r31
     2e4:	7f a4 eb 78 	mr      r4,r29
     2e8:	48 00 00 01 	bl      2e8 <fn_800614A8+0x2e8>
			2e8: R_PPC_REL24	fn_800BD2DC
     2ec:	38 60 00 01 	li      r3,1
     2f0:	48 00 16 fc 	b       19ec <fn_800614A8+0x19ec>
     2f4:	2c 16 00 3e 	cmpwi   r22,62
     2f8:	40 82 00 a8 	bne     3a0 <fn_800614A8+0x3a0>
     2fc:	7f e3 fb 78 	mr      r3,r31
     300:	48 00 00 01 	bl      300 <fn_800614A8+0x300>
			300: R_PPC_REL24	fn_80036D5C
     304:	54 60 01 09 	rlwinm. r0,r3,0,4,4
     308:	7c 64 1b 78 	mr      r4,r3
     30c:	41 82 00 68 	beq     374 <fn_800614A8+0x374>
     310:	7f e3 fb 78 	mr      r3,r31
     314:	54 84 01 46 	rlwinm  r4,r4,0,5,3
     318:	48 00 00 01 	bl      318 <fn_800614A8+0x318>
			318: R_PPC_REL24	fn_80036DA4
     31c:	7f c3 f3 78 	mr      r3,r30
     320:	48 00 00 01 	bl      320 <fn_800614A8+0x320>
			320: R_PPC_REL24	fn_801261F4
     324:	81 20 00 00 	lwz     r9,0(0)
			324: R_PPC_EMB_SDA21	lbl_80651954
     328:	38 e1 00 88 	addi    r7,r1,136
     32c:	80 00 00 00 	lwz     r0,0(0)
			32c: R_PPC_EMB_SDA21	lbl_8064E610
     330:	38 c1 00 90 	addi    r6,r1,144
     334:	81 40 00 00 	lwz     r10,0(0)
			334: R_PPC_EMB_SDA21	lbl_8064E60C
     338:	38 a1 00 98 	addi    r5,r1,152
     33c:	90 01 00 84 	stw     r0,132(r1)
     340:	7f c3 f3 78 	mr      r3,r30
     344:	38 80 00 0f 	li      r4,15
     348:	39 00 00 04 	li      r8,4
     34c:	90 01 00 88 	stw     r0,136(r1)
     350:	91 21 00 8c 	stw     r9,140(r1)
     354:	91 21 00 90 	stw     r9,144(r1)
     358:	91 41 00 94 	stw     r10,148(r1)
     35c:	91 41 00 98 	stw     r10,152(r1)
     360:	48 00 00 01 	bl      360 <fn_800614A8+0x360>
			360: R_PPC_REL24	fn_8012C62C
     364:	7f c3 f3 78 	mr      r3,r30
     368:	38 80 00 00 	li      r4,0
     36c:	38 a0 01 00 	li      r5,256
     370:	48 00 00 01 	bl      370 <fn_800614A8+0x370>
			370: R_PPC_REL24	fn_8011FA8C
     374:	7f e3 fb 78 	mr      r3,r31
     378:	7f a4 eb 78 	mr      r4,r29
     37c:	48 00 00 01 	bl      37c <fn_800614A8+0x37c>
			37c: R_PPC_REL24	fn_800BD194
     380:	7f e3 fb 78 	mr      r3,r31
     384:	48 00 00 01 	bl      384 <fn_800614A8+0x384>
			384: R_PPC_REL24	fn_800C9E50
     388:	38 00 00 00 	li      r0,0
     38c:	7f 83 e3 78 	mr      r3,r28
     390:	98 1a 00 88 	stb     r0,136(r26)
     394:	48 00 00 01 	bl      394 <fn_800614A8+0x394>
			394: R_PPC_REL24	fn_801D14CC
     398:	38 60 00 01 	li      r3,1
     39c:	48 00 16 50 	b       19ec <fn_800614A8+0x19ec>
     3a0:	2c 16 00 c9 	cmpwi   r22,201
     3a4:	40 82 00 5c 	bne     400 <fn_800614A8+0x400>
     3a8:	48 00 00 01 	bl      3a8 <fn_800614A8+0x3a8>
			3a8: R_PPC_REL24	fn_8011FF38
     3ac:	2c 03 00 00 	cmpwi   r3,0
     3b0:	41 82 00 48 	beq     3f8 <fn_800614A8+0x3f8>
     3b4:	7f c3 f3 78 	mr      r3,r30
     3b8:	38 80 00 00 	li      r4,0
     3bc:	3c a0 20 00 	lis     r5,8192
     3c0:	48 00 00 01 	bl      3c0 <fn_800614A8+0x3c0>
			3c0: R_PPC_REL24	fn_8011FA8C
     3c4:	38 00 00 00 	li      r0,0
     3c8:	38 c1 00 78 	addi    r6,r1,120
     3cc:	90 01 00 08 	stw     r0,8(r1)
     3d0:	38 60 01 f1 	li      r3,497
     3d4:	38 80 00 64 	li      r4,100
     3d8:	38 a0 00 00 	li      r5,0
     3dc:	80 00 00 00 	lwz     r0,0(0)
			3dc: R_PPC_EMB_SDA21	lbl_8064D18C
     3e0:	38 e0 00 02 	li      r7,2
     3e4:	c0 20 00 00 	lfs     f1,0(0)
			3e4: R_PPC_EMB_SDA21	lbl_8064E5BC
     3e8:	39 00 00 02 	li      r8,2
     3ec:	54 0a 04 3e 	clrlwi  r10,r0,16
     3f0:	39 20 00 00 	li      r9,0
     3f4:	48 00 00 01 	bl      3f4 <fn_800614A8+0x3f4>
			3f4: R_PPC_REL24	fn_801AAE68
     3f8:	38 60 00 01 	li      r3,1
     3fc:	48 00 15 f0 	b       19ec <fn_800614A8+0x19ec>
     400:	2c 16 00 67 	cmpwi   r22,103
     404:	40 82 00 1c 	bne     420 <fn_800614A8+0x420>
     408:	7f e3 fb 78 	mr      r3,r31
     40c:	7f c4 f3 78 	mr      r4,r30
     410:	7f 05 c3 78 	mr      r5,r24
     414:	48 00 00 01 	bl      414 <fn_800614A8+0x414>
			414: R_PPC_REL24	fn_800C9B08
     418:	38 60 00 01 	li      r3,1
     41c:	48 00 15 d0 	b       19ec <fn_800614A8+0x19ec>
     420:	2c 16 00 ed 	cmpwi   r22,237
     424:	40 82 00 54 	bne     478 <fn_800614A8+0x478>
     428:	7f 03 c3 78 	mr      r3,r24
     42c:	48 00 00 01 	bl      42c <fn_800614A8+0x42c>
			42c: R_PPC_REL24	fn_80200C38
     430:	7c 60 1b 78 	mr      r0,r3
     434:	7f 03 c3 78 	mr      r3,r24
     438:	7c 10 03 78 	mr      r16,r0
     43c:	48 00 00 01 	bl      43c <fn_800614A8+0x43c>
			43c: R_PPC_REL24	fn_80200C28
     440:	7c 60 1b 78 	mr      r0,r3
     444:	7f 03 c3 78 	mr      r3,r24
     448:	7c 0f 03 78 	mr      r15,r0
     44c:	48 00 00 01 	bl      44c <fn_800614A8+0x44c>
			44c: R_PPC_REL24	fn_80200C20
     450:	7c 64 1b 78 	mr      r4,r3
     454:	7d e5 7b 78 	mr      r5,r15
     458:	7e 06 83 78 	mr      r6,r16
     45c:	38 60 00 0b 	li      r3,11
     460:	48 00 00 01 	bl      460 <fn_800614A8+0x460>
			460: R_PPC_REL24	fn_8020123C
     464:	7f 03 c3 78 	mr      r3,r24
     468:	48 00 00 01 	bl      468 <fn_800614A8+0x468>
			468: R_PPC_REL24	fn_80200C38
     46c:	48 00 00 01 	bl      46c <fn_800614A8+0x46c>
			46c: R_PPC_REL24	fn_801A7228
     470:	38 60 00 01 	li      r3,1
     474:	48 00 15 78 	b       19ec <fn_800614A8+0x19ec>
     478:	2c 16 00 3a 	cmpwi   r22,58
     47c:	40 82 00 54 	bne     4d0 <fn_800614A8+0x4d0>
     480:	7f 03 c3 78 	mr      r3,r24
     484:	48 00 00 01 	bl      484 <fn_800614A8+0x484>
			484: R_PPC_REL24	fn_80200C38
     488:	7c 60 1b 78 	mr      r0,r3
     48c:	7f 03 c3 78 	mr      r3,r24
     490:	7c 10 03 78 	mr      r16,r0
     494:	48 00 00 01 	bl      494 <fn_800614A8+0x494>
			494: R_PPC_REL24	fn_80200C28
     498:	7c 60 1b 78 	mr      r0,r3
     49c:	7f 03 c3 78 	mr      r3,r24
     4a0:	7c 0f 03 78 	mr      r15,r0
     4a4:	48 00 00 01 	bl      4a4 <fn_800614A8+0x4a4>
			4a4: R_PPC_REL24	fn_80200C20
     4a8:	7c 64 1b 78 	mr      r4,r3
     4ac:	7d e5 7b 78 	mr      r5,r15
     4b0:	7e 06 83 78 	mr      r6,r16
     4b4:	38 60 00 27 	li      r3,39
     4b8:	48 00 00 01 	bl      4b8 <fn_800614A8+0x4b8>
			4b8: R_PPC_REL24	fn_8020123C
     4bc:	7f 03 c3 78 	mr      r3,r24
     4c0:	48 00 00 01 	bl      4c0 <fn_800614A8+0x4c0>
			4c0: R_PPC_REL24	fn_80200C38
     4c4:	48 00 00 01 	bl      4c4 <fn_800614A8+0x4c4>
			4c4: R_PPC_REL24	fn_801A7228
     4c8:	38 60 00 01 	li      r3,1
     4cc:	48 00 15 20 	b       19ec <fn_800614A8+0x19ec>
     4d0:	2c 16 00 0b 	cmpwi   r22,11
     4d4:	40 82 00 58 	bne     52c <fn_800614A8+0x52c>
     4d8:	48 00 00 01 	bl      4d8 <fn_800614A8+0x4d8>
			4d8: R_PPC_REL24	fn_80201B9C
     4dc:	38 60 00 20 	li      r3,32
     4e0:	48 00 00 01 	bl      4e0 <fn_800614A8+0x4e0>
			4e0: R_PPC_REL24	fn_80204844
     4e4:	48 00 00 01 	bl      4e4 <fn_800614A8+0x4e4>
			4e4: R_PPC_REL24	fn_8006D444
     4e8:	3c 60 00 08 	lis     r3,8
     4ec:	38 80 00 00 	li      r4,0
     4f0:	48 00 00 01 	bl      4f0 <fn_800614A8+0x4f0>
			4f0: R_PPC_REL24	fn_8006D344
     4f4:	2c 03 00 00 	cmpwi   r3,0
     4f8:	41 82 00 14 	beq     50c <fn_800614A8+0x50c>
     4fc:	7f e3 fb 78 	mr      r3,r31
     500:	48 00 00 01 	bl      500 <fn_800614A8+0x500>
			500: R_PPC_REL24	fn_80067180
     504:	38 60 00 01 	li      r3,1
     508:	48 00 00 10 	b       518 <fn_800614A8+0x518>
     50c:	7f 03 c3 78 	mr      r3,r24
     510:	48 00 00 01 	bl      510 <fn_800614A8+0x510>
			510: R_PPC_REL24	fn_80200C38
     514:	48 00 00 01 	bl      514 <fn_800614A8+0x514>
			514: R_PPC_REL24	fn_800654F8
     518:	28 19 00 00 	cmplwi  r25,0
     51c:	41 82 00 08 	beq     524 <fn_800614A8+0x524>
     520:	90 79 00 00 	stw     r3,0(r25)
     524:	38 60 00 01 	li      r3,1
     528:	48 00 14 c4 	b       19ec <fn_800614A8+0x19ec>
     52c:	2c 16 00 65 	cmpwi   r22,101
     530:	40 82 00 34 	bne     564 <fn_800614A8+0x564>
     534:	7f 03 c3 78 	mr      r3,r24
     538:	48 00 00 01 	bl      538 <fn_800614A8+0x538>
			538: R_PPC_REL24	fn_80200C20
     53c:	48 00 00 01 	bl      53c <fn_800614A8+0x53c>
			53c: R_PPC_REL24	fn_80201814
     540:	7c 64 1b 78 	mr      r4,r3
     544:	7f e3 fb 78 	mr      r3,r31
     548:	48 00 00 01 	bl      548 <fn_800614A8+0x548>
			548: R_PPC_REL24	fn_800359A0
     54c:	28 19 00 00 	cmplwi  r25,0
     550:	41 82 00 0c 	beq     55c <fn_800614A8+0x55c>
     554:	38 00 00 01 	li      r0,1
     558:	90 19 00 00 	stw     r0,0(r25)
     55c:	38 60 00 01 	li      r3,1
     560:	48 00 14 8c 	b       19ec <fn_800614A8+0x19ec>
     564:	2c 16 00 39 	cmpwi   r22,57
     568:	40 82 00 5c 	bne     5c4 <fn_800614A8+0x5c4>
     56c:	7f e3 fb 78 	mr      r3,r31
     570:	48 00 00 01 	bl      570 <fn_800614A8+0x570>
			570: R_PPC_REL24	fn_800CA2C8
     574:	7f e3 fb 78 	mr      r3,r31
     578:	7f a4 eb 78 	mr      r4,r29
     57c:	48 00 00 01 	bl      57c <fn_800614A8+0x57c>
			57c: R_PPC_REL24	fn_800EA3A0
     580:	7f c3 f3 78 	mr      r3,r30
     584:	48 00 00 01 	bl      584 <fn_800614A8+0x584>
			584: R_PPC_REL24	fn_8012B324
     588:	7f c3 f3 78 	mr      r3,r30
     58c:	38 80 00 c0 	li      r4,192
     590:	38 a0 00 00 	li      r5,0
     594:	48 00 00 01 	bl      594 <fn_800614A8+0x594>
			594: R_PPC_REL24	fn_8011FA8C
     598:	7f e3 fb 78 	mr      r3,r31
     59c:	38 80 00 00 	li      r4,0
     5a0:	48 00 00 01 	bl      5a0 <fn_800614A8+0x5a0>
			5a0: R_PPC_REL24	fn_80201D34
     5a4:	7f e3 fb 78 	mr      r3,r31
     5a8:	38 80 00 01 	li      r4,1
     5ac:	48 00 00 01 	bl      5ac <fn_800614A8+0x5ac>
			5ac: R_PPC_REL24	fn_80201D1C
     5b0:	7f e4 fb 78 	mr      r4,r31
     5b4:	38 60 00 02 	li      r3,2
     5b8:	48 00 00 01 	bl      5b8 <fn_800614A8+0x5b8>
			5b8: R_PPC_REL24	fn_801E8328
     5bc:	38 60 00 01 	li      r3,1
     5c0:	48 00 14 2c 	b       19ec <fn_800614A8+0x19ec>
     5c4:	2c 16 00 0e 	cmpwi   r22,14
     5c8:	40 82 00 18 	bne     5e0 <fn_800614A8+0x5e0>
     5cc:	7f e3 fb 78 	mr      r3,r31
     5d0:	7f 04 c3 78 	mr      r4,r24
     5d4:	48 00 00 01 	bl      5d4 <fn_800614A8+0x5d4>
			5d4: R_PPC_REL24	fn_80068994
     5d8:	38 60 00 01 	li      r3,1
     5dc:	48 00 14 10 	b       19ec <fn_800614A8+0x19ec>
     5e0:	2c 16 00 27 	cmpwi   r22,39
     5e4:	40 82 00 1c 	bne     600 <fn_800614A8+0x600>
     5e8:	7f e3 fb 78 	mr      r3,r31
     5ec:	7f 04 c3 78 	mr      r4,r24
     5f0:	7f 25 cb 78 	mr      r5,r25
     5f4:	48 00 00 01 	bl      5f4 <fn_800614A8+0x5f4>
			5f4: R_PPC_REL24	fn_80064B38
     5f8:	38 60 00 01 	li      r3,1
     5fc:	48 00 13 f0 	b       19ec <fn_800614A8+0x19ec>
     600:	2c 16 00 3b 	cmpwi   r22,59
     604:	40 82 00 40 	bne     644 <fn_800614A8+0x644>
     608:	7f 03 c3 78 	mr      r3,r24
     60c:	39 e0 00 01 	li      r15,1
     610:	48 00 00 01 	bl      610 <fn_800614A8+0x610>
			610: R_PPC_REL24	fn_80200C20
     614:	48 00 00 01 	bl      614 <fn_800614A8+0x614>
			614: R_PPC_REL24	fn_80201814
     618:	28 03 00 00 	cmplwi  r3,0
     61c:	41 82 00 14 	beq     630 <fn_800614A8+0x630>
     620:	48 00 00 01 	bl      620 <fn_800614A8+0x620>
			620: R_PPC_REL24	fn_80036E50
     624:	2c 03 00 06 	cmpwi   r3,6
     628:	40 82 00 08 	bne     630 <fn_800614A8+0x630>
     62c:	39 e0 00 00 	li      r15,0
     630:	28 19 00 00 	cmplwi  r25,0
     634:	41 82 00 08 	beq     63c <fn_800614A8+0x63c>
     638:	91 f9 00 00 	stw     r15,0(r25)
     63c:	38 60 00 01 	li      r3,1
     640:	48 00 13 ac 	b       19ec <fn_800614A8+0x19ec>
     644:	2c 16 00 4e 	cmpwi   r22,78
     648:	40 82 00 24 	bne     66c <fn_800614A8+0x66c>
     64c:	28 19 00 00 	cmplwi  r25,0
     650:	41 82 00 14 	beq     664 <fn_800614A8+0x664>
     654:	80 1d 00 6c 	lwz     r0,108(r29)
     658:	7c 00 00 34 	cntlzw  r0,r0
     65c:	54 00 d9 7e 	srwi    r0,r0,5
     660:	90 19 00 00 	stw     r0,0(r25)
     664:	38 60 00 01 	li      r3,1
     668:	48 00 13 84 	b       19ec <fn_800614A8+0x19ec>
     66c:	2c 16 00 82 	cmpwi   r22,130
     670:	40 82 00 1c 	bne     68c <fn_800614A8+0x68c>
     674:	28 19 00 00 	cmplwi  r25,0
     678:	41 82 00 0c 	beq     684 <fn_800614A8+0x684>
     67c:	38 00 00 01 	li      r0,1
     680:	90 19 00 00 	stw     r0,0(r25)
     684:	38 60 00 01 	li      r3,1
     688:	48 00 13 64 	b       19ec <fn_800614A8+0x19ec>
     68c:	2c 16 00 32 	cmpwi   r22,50
     690:	40 82 00 18 	bne     6a8 <fn_800614A8+0x6a8>
     694:	7f e3 fb 78 	mr      r3,r31
     698:	7f 04 c3 78 	mr      r4,r24
     69c:	48 00 00 01 	bl      69c <fn_800614A8+0x69c>
			69c: R_PPC_REL24	fn_80066A0C
     6a0:	38 60 00 01 	li      r3,1
     6a4:	48 00 13 48 	b       19ec <fn_800614A8+0x19ec>
     6a8:	2c 16 00 e6 	cmpwi   r22,230
     6ac:	40 82 00 28 	bne     6d4 <fn_800614A8+0x6d4>
     6b0:	7f 03 c3 78 	mr      r3,r24
     6b4:	48 00 00 01 	bl      6b4 <fn_800614A8+0x6b4>
			6b4: R_PPC_REL24	fn_80200C38
     6b8:	c0 20 00 00 	lfs     f1,0(0)
			6b8: R_PPC_EMB_SDA21	lbl_8064E614
     6bc:	7c 64 1b 78 	mr      r4,r3
     6c0:	c0 40 00 00 	lfs     f2,0(0)
			6c0: R_PPC_EMB_SDA21	lbl_8064E618
     6c4:	7f c3 f3 78 	mr      r3,r30
     6c8:	48 00 00 01 	bl      6c8 <fn_800614A8+0x6c8>
			6c8: R_PPC_REL24	fn_80066888
     6cc:	38 60 00 01 	li      r3,1
     6d0:	48 00 13 1c 	b       19ec <fn_800614A8+0x19ec>
     6d4:	2c 16 00 35 	cmpwi   r22,53
     6d8:	40 82 00 88 	bne     760 <fn_800614A8+0x760>
     6dc:	7f 03 c3 78 	mr      r3,r24
     6e0:	48 00 00 01 	bl      6e0 <fn_800614A8+0x6e0>
			6e0: R_PPC_REL24	fn_80200C38
     6e4:	7c 6f 1b 78 	mr      r15,r3
     6e8:	48 00 00 01 	bl      6e8 <fn_800614A8+0x6e8>
			6e8: R_PPC_REL24	fn_801A7488
     6ec:	7c 70 1b 78 	mr      r16,r3
     6f0:	2c 10 00 0b 	cmpwi   r16,11
     6f4:	40 82 00 14 	bne     708 <fn_800614A8+0x708>
     6f8:	7d e3 7b 78 	mr      r3,r15
     6fc:	38 80 00 0d 	li      r4,13
     700:	48 00 00 01 	bl      700 <fn_800614A8+0x700>
			700: R_PPC_REL24	fn_801A7470
     704:	48 00 00 18 	b       71c <fn_800614A8+0x71c>
     708:	2c 10 00 0c 	cmpwi   r16,12
     70c:	40 82 00 10 	bne     71c <fn_800614A8+0x71c>
     710:	7d e3 7b 78 	mr      r3,r15
     714:	38 80 00 0e 	li      r4,14
     718:	48 00 00 01 	bl      718 <fn_800614A8+0x718>
			718: R_PPC_REL24	fn_801A7470
     71c:	7f e3 fb 78 	mr      r3,r31
     720:	7f 04 c3 78 	mr      r4,r24
     724:	7f 25 cb 78 	mr      r5,r25
     728:	48 00 00 01 	bl      728 <fn_800614A8+0x728>
			728: R_PPC_REL24	fn_80066754
     72c:	7d e3 7b 78 	mr      r3,r15
     730:	7e 04 83 78 	mr      r4,r16
     734:	48 00 00 01 	bl      734 <fn_800614A8+0x734>
			734: R_PPC_REL24	fn_801A7470
     738:	2c 10 00 0b 	cmpwi   r16,11
     73c:	41 82 00 0c 	beq     748 <fn_800614A8+0x748>
     740:	2c 10 00 0c 	cmpwi   r16,12
     744:	40 82 00 14 	bne     758 <fn_800614A8+0x758>
     748:	3c 80 00 02 	lis     r4,2
     74c:	7f c3 f3 78 	mr      r3,r30
     750:	38 84 fd 70 	addi    r4,r4,-656
     754:	48 00 00 01 	bl      754 <fn_800614A8+0x754>
			754: R_PPC_REL24	fn_801296F8
     758:	38 60 00 01 	li      r3,1
     75c:	48 00 12 90 	b       19ec <fn_800614A8+0x19ec>
     760:	2c 16 00 ea 	cmpwi   r22,234
     764:	40 82 01 2c 	bne     890 <fn_800614A8+0x890>
     768:	7f e3 fb 78 	mr      r3,r31
     76c:	7f 04 c3 78 	mr      r4,r24
     770:	48 00 00 01 	bl      770 <fn_800614A8+0x770>
			770: R_PPC_REL24	fn_800674E4
     774:	80 00 00 00 	lwz     r0,0(0)
			774: R_PPC_EMB_SDA21	lbl_8064D18C
     778:	2c 00 00 88 	cmpwi   r0,136
     77c:	40 82 00 f8 	bne     874 <fn_800614A8+0x874>
     780:	a8 7d 00 ea 	lha     r3,234(r29)
     784:	38 00 00 01 	li      r0,1
     788:	7c 63 0e 70 	srawi   r3,r3,1
     78c:	2c 03 00 01 	cmpwi   r3,1
     790:	41 80 00 08 	blt     798 <fn_800614A8+0x798>
     794:	7c 60 1b 78 	mr      r0,r3
     798:	b0 1d 00 ea 	sth     r0,234(r29)
     79c:	38 00 00 01 	li      r0,1
     7a0:	a8 7d 00 fa 	lha     r3,250(r29)
     7a4:	7c 63 0e 70 	srawi   r3,r3,1
     7a8:	2c 03 00 01 	cmpwi   r3,1
     7ac:	41 80 00 08 	blt     7b4 <fn_800614A8+0x7b4>
     7b0:	7c 60 1b 78 	mr      r0,r3
     7b4:	b0 1d 00 fa 	sth     r0,250(r29)
     7b8:	38 00 00 01 	li      r0,1
     7bc:	a8 7d 00 fc 	lha     r3,252(r29)
     7c0:	7c 63 0e 70 	srawi   r3,r3,1
     7c4:	2c 03 00 01 	cmpwi   r3,1
     7c8:	41 80 00 08 	blt     7d0 <fn_800614A8+0x7d0>
     7cc:	7c 60 1b 78 	mr      r0,r3
     7d0:	b0 1d 00 fc 	sth     r0,252(r29)
     7d4:	38 00 00 01 	li      r0,1
     7d8:	a8 7d 00 ee 	lha     r3,238(r29)
     7dc:	7c 63 0e 70 	srawi   r3,r3,1
     7e0:	2c 03 00 01 	cmpwi   r3,1
     7e4:	41 80 00 08 	blt     7ec <fn_800614A8+0x7ec>
     7e8:	7c 60 1b 78 	mr      r0,r3
     7ec:	b0 1d 00 ee 	sth     r0,238(r29)
     7f0:	38 00 00 01 	li      r0,1
     7f4:	a8 7d 00 f0 	lha     r3,240(r29)
     7f8:	7c 63 0e 70 	srawi   r3,r3,1
     7fc:	2c 03 00 01 	cmpwi   r3,1
     800:	41 80 00 08 	blt     808 <fn_800614A8+0x808>
     804:	7c 60 1b 78 	mr      r0,r3
     808:	b0 1d 00 f0 	sth     r0,240(r29)
     80c:	38 00 00 01 	li      r0,1
     810:	a8 7d 00 ec 	lha     r3,236(r29)
     814:	7c 63 0e 70 	srawi   r3,r3,1
     818:	2c 03 00 01 	cmpwi   r3,1
     81c:	41 80 00 08 	blt     824 <fn_800614A8+0x824>
     820:	7c 60 1b 78 	mr      r0,r3
     824:	b0 1d 00 ec 	sth     r0,236(r29)
     828:	7f e3 fb 78 	mr      r3,r31
     82c:	38 a1 00 10 	addi    r5,r1,16
     830:	38 80 00 00 	li      r4,0
     834:	48 00 00 01 	bl      834 <fn_800614A8+0x834>
			834: R_PPC_REL24	fn_80038308
     838:	a8 01 00 10 	lha     r0,16(r1)
     83c:	38 80 00 01 	li      r4,1
     840:	7c 00 0e 70 	srawi   r0,r0,1
     844:	2c 00 00 01 	cmpwi   r0,1
     848:	41 80 00 08 	blt     850 <fn_800614A8+0x850>
     84c:	7c 04 03 78 	mr      r4,r0
     850:	7f e3 fb 78 	mr      r3,r31
     854:	7c 85 07 34 	extsh   r5,r4
     858:	38 80 00 00 	li      r4,0
     85c:	38 c0 00 00 	li      r6,0
     860:	48 00 00 01 	bl      860 <fn_800614A8+0x860>
			860: R_PPC_REL24	fn_800389E0
     864:	a8 7a 00 86 	lha     r3,134(r26)
     868:	38 03 00 1e 	addi    r0,r3,30
     86c:	b0 1a 00 86 	sth     r0,134(r26)
     870:	48 00 00 18 	b       888 <fn_800614A8+0x888>
     874:	2c 00 00 29 	cmpwi   r0,41
     878:	40 82 00 10 	bne     888 <fn_800614A8+0x888>
     87c:	a8 7a 00 86 	lha     r3,134(r26)
     880:	38 03 00 1e 	addi    r0,r3,30
     884:	b0 1a 00 86 	sth     r0,134(r26)
     888:	38 60 00 01 	li      r3,1
     88c:	48 00 11 60 	b       19ec <fn_800614A8+0x19ec>
     890:	2c 16 00 eb 	cmpwi   r22,235
     894:	40 82 00 18 	bne     8ac <fn_800614A8+0x8ac>
     898:	7f e3 fb 78 	mr      r3,r31
     89c:	7f 04 c3 78 	mr      r4,r24
     8a0:	48 00 00 01 	bl      8a0 <fn_800614A8+0x8a0>
			8a0: R_PPC_REL24	fn_80067650
     8a4:	38 60 00 01 	li      r3,1
     8a8:	48 00 11 44 	b       19ec <fn_800614A8+0x19ec>
     8ac:	2c 16 00 f3 	cmpwi   r22,243
     8b0:	40 82 11 3c 	bne     19ec <fn_800614A8+0x19ec>
     8b4:	7f 03 c3 78 	mr      r3,r24
     8b8:	48 00 00 01 	bl      8b8 <fn_800614A8+0x8b8>
			8b8: R_PPC_REL24	fn_80200C38
     8bc:	7c 65 1b 78 	mr      r5,r3
     8c0:	7f e3 fb 78 	mr      r3,r31
     8c4:	7f a4 eb 78 	mr      r4,r29
     8c8:	7f 06 c3 78 	mr      r6,r24
     8cc:	7f 27 cb 78 	mr      r7,r25
     8d0:	48 00 00 01 	bl      8d0 <fn_800614A8+0x8d0>
			8d0: R_PPC_REL24	fn_800EA0FC
     8d4:	38 60 00 01 	li      r3,1
     8d8:	48 00 11 14 	b       19ec <fn_800614A8+0x19ec>
     8dc:	2c 17 00 01 	cmpwi   r23,1
     8e0:	40 82 02 20 	bne     b00 <fn_800614A8+0xb00>
     8e4:	2c 16 00 01 	cmpwi   r22,1
     8e8:	40 82 00 30 	bne     918 <fn_800614A8+0x918>
     8ec:	c0 20 00 00 	lfs     f1,0(0)
			8ec: R_PPC_EMB_SDA21	lbl_8064E61C
     8f0:	7f c3 f3 78 	mr      r3,r30
     8f4:	48 00 00 01 	bl      8f4 <fn_800614A8+0x8f4>
			8f4: R_PPC_REL24	fn_8011F778
     8f8:	c0 20 00 00 	lfs     f1,0(0)
			8f8: R_PPC_EMB_SDA21	lbl_8064E61C
     8fc:	7f c3 f3 78 	mr      r3,r30
     900:	48 00 00 01 	bl      900 <fn_800614A8+0x900>
			900: R_PPC_REL24	fn_8011F788
     904:	c0 20 00 00 	lfs     f1,0(0)
			904: R_PPC_EMB_SDA21	lbl_8064E61C
     908:	7f c3 f3 78 	mr      r3,r30
     90c:	48 00 00 01 	bl      90c <fn_800614A8+0x90c>
			90c: R_PPC_REL24	fn_8011F798
     910:	38 60 00 01 	li      r3,1
     914:	48 00 10 d8 	b       19ec <fn_800614A8+0x19ec>
     918:	2c 16 00 5a 	cmpwi   r22,90
     91c:	40 82 01 94 	bne     ab0 <fn_800614A8+0xab0>
     920:	7f 03 c3 78 	mr      r3,r24
     924:	48 00 00 01 	bl      924 <fn_800614A8+0x924>
			924: R_PPC_REL24	fn_80200C20
     928:	48 00 00 01 	bl      928 <fn_800614A8+0x928>
			928: R_PPC_REL24	fn_80201814
     92c:	28 03 00 00 	cmplwi  r3,0
     930:	41 82 00 10 	beq     940 <fn_800614A8+0x940>
     934:	48 00 00 01 	bl      934 <fn_800614A8+0x934>
			934: R_PPC_REL24	fn_80201BC8
     938:	7c 70 1b 78 	mr      r16,r3
     93c:	48 00 00 08 	b       944 <fn_800614A8+0x944>
     940:	3a 00 00 00 	li      r16,0
     944:	28 10 00 00 	cmplwi  r16,0
     948:	41 82 01 60 	beq     aa8 <fn_800614A8+0xaa8>
     94c:	48 00 00 01 	bl      94c <fn_800614A8+0x94c>
			94c: R_PPC_REL24	fn_800460EC
     950:	2c 03 00 00 	cmpwi   r3,0
     954:	40 82 01 54 	bne     aa8 <fn_800614A8+0xaa8>
     958:	7f e3 fb 78 	mr      r3,r31
     95c:	48 00 00 01 	bl      95c <fn_800614A8+0x95c>
			95c: R_PPC_REL24	fn_800CAF7C
     960:	2c 03 00 00 	cmpwi   r3,0
     964:	41 82 01 44 	beq     aa8 <fn_800614A8+0xaa8>
     968:	80 7b 00 8c 	lwz     r3,140(r27)
     96c:	a8 03 01 50 	lha     r0,336(r3)
     970:	7c 00 07 35 	extsh.  r0,r0
     974:	40 82 01 34 	bne     aa8 <fn_800614A8+0xaa8>
     978:	7e 04 83 78 	mr      r4,r16
     97c:	38 61 00 3c 	addi    r3,r1,60
     980:	48 00 00 01 	bl      980 <fn_800614A8+0x980>
			980: R_PPC_REL24	fn_8011F114
     984:	80 e1 00 40 	lwz     r7,64(r1)
     988:	3c 00 43 30 	lis     r0,17200
     98c:	c0 01 00 3c 	lfs     f0,60(r1)
     990:	7f c3 f3 78 	mr      r3,r30
     994:	80 c1 00 44 	lwz     r6,68(r1)
     998:	38 81 00 60 	addi    r4,r1,96
     99c:	d0 01 00 60 	stfs    f0,96(r1)
     9a0:	38 a0 00 00 	li      r5,0
     9a4:	c8 20 00 00 	lfd     f1,0(0)
			9a4: R_PPC_EMB_SDA21	@569
     9a8:	90 e1 00 64 	stw     r7,100(r1)
     9ac:	c0 40 00 00 	lfs     f2,0(0)
			9ac: R_PPC_EMB_SDA21	lbl_8064E620
     9b0:	90 c1 00 68 	stw     r6,104(r1)
     9b4:	a8 dd 01 4a 	lha     r6,330(r29)
     9b8:	90 01 00 a0 	stw     r0,160(r1)
     9bc:	6c c0 80 00 	xoris   r0,r6,32768
     9c0:	90 01 00 a4 	stw     r0,164(r1)
     9c4:	c8 01 00 a0 	lfd     f0,160(r1)
     9c8:	ec 00 08 28 	fsubs   f0,f0,f1
     9cc:	ec 22 00 32 	fmuls   f1,f2,f0
     9d0:	48 00 00 01 	bl      9d0 <fn_800614A8+0x9d0>
			9d0: R_PPC_REL24	fn_80204434
     9d4:	54 60 06 3f 	clrlwi. r0,r3,24
     9d8:	40 82 00 d0 	bne     aa8 <fn_800614A8+0xaa8>
     9dc:	80 00 00 00 	lwz     r0,0(0)
			9dc: R_PPC_EMB_SDA21	lbl_8064D18C
     9e0:	2c 00 00 34 	cmpwi   r0,52
     9e4:	41 82 00 c4 	beq     aa8 <fn_800614A8+0xaa8>
     9e8:	7e 04 83 78 	mr      r4,r16
     9ec:	38 61 00 30 	addi    r3,r1,48
     9f0:	48 00 00 01 	bl      9f0 <fn_800614A8+0x9f0>
			9f0: R_PPC_REL24	fn_8011F114
     9f4:	c0 01 00 30 	lfs     f0,48(r1)
     9f8:	7e 03 83 78 	mr      r3,r16
     9fc:	38 e1 00 14 	addi    r7,r1,20
     a00:	38 80 00 00 	li      r4,0
     a04:	d0 1d 00 94 	stfs    f0,148(r29)
     a08:	38 a0 00 00 	li      r5,0
     a0c:	38 c0 ff ff 	li      r6,-1
     a10:	39 00 00 01 	li      r8,1
     a14:	80 01 00 34 	lwz     r0,52(r1)
     a18:	90 1d 00 98 	stw     r0,152(r29)
     a1c:	80 01 00 38 	lwz     r0,56(r1)
     a20:	90 1d 00 9c 	stw     r0,156(r29)
     a24:	48 00 00 01 	bl      a24 <fn_800614A8+0xa24>
			a24: R_PPC_REL24	fn_8011F598
     a28:	2c 03 ff ff 	cmpwi   r3,-1
     a2c:	41 82 00 18 	beq     a44 <fn_800614A8+0xa44>
     a30:	7e 03 83 78 	mr      r3,r16
     a34:	38 a1 00 6c 	addi    r5,r1,108
     a38:	38 80 00 00 	li      r4,0
     a3c:	48 00 00 01 	bl      a3c <fn_800614A8+0xa3c>
			a3c: R_PPC_REL24	fn_8012FE10
     a40:	48 00 00 1c 	b       a5c <fn_800614A8+0xa5c>
     a44:	c0 01 00 60 	lfs     f0,96(r1)
     a48:	80 61 00 64 	lwz     r3,100(r1)
     a4c:	80 01 00 68 	lwz     r0,104(r1)
     a50:	d0 01 00 6c 	stfs    f0,108(r1)
     a54:	90 61 00 70 	stw     r3,112(r1)
     a58:	90 01 00 74 	stw     r0,116(r1)
     a5c:	80 1b 00 94 	lwz     r0,148(r27)
     a60:	2c 00 00 01 	cmpwi   r0,1
     a64:	40 82 00 2c 	bne     a90 <fn_800614A8+0xa90>
     a68:	7f c3 f3 78 	mr      r3,r30
     a6c:	38 81 00 6c 	addi    r4,r1,108
     a70:	38 a0 00 04 	li      r5,4
     a74:	38 c0 00 04 	li      r6,4
     a78:	48 00 00 01 	bl      a78 <fn_800614A8+0xa78>
			a78: R_PPC_REL24	fn_8012FF34
     a7c:	2c 03 00 00 	cmpwi   r3,0
     a80:	41 82 00 10 	beq     a90 <fn_800614A8+0xa90>
     a84:	7f c3 f3 78 	mr      r3,r30
     a88:	38 80 00 3c 	li      r4,60
     a8c:	48 00 00 01 	bl      a8c <fn_800614A8+0xa8c>
			a8c: R_PPC_REL24	fn_801302BC
     a90:	7f e3 fb 78 	mr      r3,r31
     a94:	38 80 00 15 	li      r4,21
     a98:	48 00 00 01 	bl      a98 <fn_800614A8+0xa98>
			a98: R_PPC_REL24	fn_80201D2C
     a9c:	7f e3 fb 78 	mr      r3,r31
     aa0:	38 80 00 01 	li      r4,1
     aa4:	48 00 00 01 	bl      aa4 <fn_800614A8+0xaa4>
			aa4: R_PPC_REL24	fn_80201D14
     aa8:	38 60 00 01 	li      r3,1
     aac:	48 00 0f 40 	b       19ec <fn_800614A8+0x19ec>
     ab0:	2c 16 00 03 	cmpwi   r22,3
     ab4:	40 82 0f 38 	bne     19ec <fn_800614A8+0x19ec>
     ab8:	7f c3 f3 78 	mr      r3,r30
     abc:	7e 44 93 78 	mr      r4,r18
     ac0:	7e 05 83 78 	mr      r5,r16
     ac4:	48 00 00 01 	bl      ac4 <fn_800614A8+0xac4>
			ac4: R_PPC_REL24	fn_80060C24
     ac8:	7f e3 fb 78 	mr      r3,r31
     acc:	7f c4 f3 78 	mr      r4,r30
     ad0:	7f 05 c3 78 	mr      r5,r24
     ad4:	7e 46 93 78 	mr      r6,r18
     ad8:	7e 07 83 78 	mr      r7,r16
     adc:	48 00 00 01 	bl      adc <fn_800614A8+0xadc>
			adc: R_PPC_REL24	fn_80060D4C
     ae0:	7f 83 e3 78 	mr      r3,r28
     ae4:	7f e4 fb 78 	mr      r4,r31
     ae8:	7f c5 f3 78 	mr      r5,r30
     aec:	7f 66 db 78 	mr      r6,r27
     af0:	7f 47 d3 78 	mr      r7,r26
     af4:	48 00 00 01 	bl      af4 <fn_800614A8+0xaf4>
			af4: R_PPC_REL24	fn_8005FD84
     af8:	38 60 00 01 	li      r3,1
     afc:	48 00 0e f0 	b       19ec <fn_800614A8+0x19ec>
     b00:	2c 17 00 15 	cmpwi   r23,21
     b04:	40 82 02 60 	bne     d64 <fn_800614A8+0xd64>
     b08:	2c 16 00 01 	cmpwi   r22,1
     b0c:	40 82 00 1c 	bne     b28 <fn_800614A8+0xb28>
     b10:	c0 00 00 00 	lfs     f0,0(0)
			b10: R_PPC_EMB_SDA21	lbl_8064E5DC
     b14:	7f c3 f3 78 	mr      r3,r30
     b18:	d0 1d 00 c4 	stfs    f0,196(r29)
     b1c:	48 00 00 01 	bl      b1c <fn_800614A8+0xb1c>
			b1c: R_PPC_REL24	fn_8012B344
     b20:	38 60 00 01 	li      r3,1
     b24:	48 00 0e c8 	b       19ec <fn_800614A8+0x19ec>
     b28:	2c 16 00 03 	cmpwi   r22,3
     b2c:	40 82 00 d4 	bne     c00 <fn_800614A8+0xc00>
     b30:	7f 83 e3 78 	mr      r3,r28
     b34:	7f e4 fb 78 	mr      r4,r31
     b38:	7f c5 f3 78 	mr      r5,r30
     b3c:	7f 66 db 78 	mr      r6,r27
     b40:	7f 47 d3 78 	mr      r7,r26
     b44:	48 00 00 01 	bl      b44 <fn_800614A8+0xb44>
			b44: R_PPC_REL24	fn_8005FD84
     b48:	7f e3 fb 78 	mr      r3,r31
     b4c:	7f c4 f3 78 	mr      r4,r30
     b50:	7f 05 c3 78 	mr      r5,r24
     b54:	7e 46 93 78 	mr      r6,r18
     b58:	7e 07 83 78 	mr      r7,r16
     b5c:	48 00 00 01 	bl      b5c <fn_800614A8+0xb5c>
			b5c: R_PPC_REL24	fn_80060D4C
     b60:	2c 03 00 00 	cmpwi   r3,0
     b64:	40 82 00 94 	bne     bf8 <fn_800614A8+0xbf8>
     b68:	c0 20 00 00 	lfs     f1,0(0)
			b68: R_PPC_EMB_SDA21	lbl_8064E608
     b6c:	7f c3 f3 78 	mr      r3,r30
     b70:	38 9d 00 94 	addi    r4,r29,148
     b74:	38 a0 00 02 	li      r5,2
     b78:	38 c0 00 00 	li      r6,0
     b7c:	48 00 00 01 	bl      b7c <fn_800614A8+0xb7c>
			b7c: R_PPC_REL24	fn_800BE86C
     b80:	2c 03 00 00 	cmpwi   r3,0
     b84:	40 82 00 34 	bne     bb8 <fn_800614A8+0xbb8>
     b88:	7f c3 f3 78 	mr      r3,r30
     b8c:	38 80 00 0f 	li      r4,15
     b90:	38 a0 00 25 	li      r5,37
     b94:	38 c0 00 01 	li      r6,1
     b98:	48 00 00 01 	bl      b98 <fn_800614A8+0xb98>
			b98: R_PPC_REL24	fn_801294DC
     b9c:	7f e3 fb 78 	mr      r3,r31
     ba0:	38 80 00 01 	li      r4,1
     ba4:	48 00 00 01 	bl      ba4 <fn_800614A8+0xba4>
			ba4: R_PPC_REL24	fn_80201D2C
     ba8:	7f e3 fb 78 	mr      r3,r31
     bac:	38 80 00 01 	li      r4,1
     bb0:	48 00 00 01 	bl      bb0 <fn_800614A8+0xbb0>
			bb0: R_PPC_REL24	fn_80201D14
     bb4:	48 00 00 44 	b       bf8 <fn_800614A8+0xbf8>
     bb8:	c0 5d 00 c4 	lfs     f2,196(r29)
     bbc:	c0 00 00 00 	lfs     f0,0(0)
			bbc: R_PPC_EMB_SDA21	lbl_8064E624
     bc0:	fc 02 00 40 	fcmpo   cr0,f2,f0
     bc4:	40 80 00 34 	bge     bf8 <fn_800614A8+0xbf8>
     bc8:	c0 00 00 00 	lfs     f0,0(0)
			bc8: R_PPC_EMB_SDA21	lbl_8064E628
     bcc:	ec 02 00 2a 	fadds   f0,f2,f0
     bd0:	d0 1d 00 c4 	stfs    f0,196(r29)
     bd4:	c0 20 00 00 	lfs     f1,0(0)
			bd4: R_PPC_EMB_SDA21	lbl_8064E614
     bd8:	fc 02 08 00 	fcmpu   cr0,f2,f1
     bdc:	40 82 00 1c 	bne     bf8 <fn_800614A8+0xbf8>
     be0:	c0 1d 00 c4 	lfs     f0,196(r29)
     be4:	fc 00 08 40 	fcmpo   cr0,f0,f1
     be8:	40 81 00 10 	ble     bf8 <fn_800614A8+0xbf8>
     bec:	7f c3 f3 78 	mr      r3,r30
     bf0:	38 80 00 3f 	li      r4,63
     bf4:	48 00 00 01 	bl      bf4 <fn_800614A8+0xbf4>
			bf4: R_PPC_REL24	fn_801A977C
     bf8:	38 60 00 01 	li      r3,1
     bfc:	48 00 0d f0 	b       19ec <fn_800614A8+0x19ec>
     c00:	2c 16 00 5a 	cmpwi   r22,90
     c04:	40 82 00 f4 	bne     cf8 <fn_800614A8+0xcf8>
     c08:	7f 03 c3 78 	mr      r3,r24
     c0c:	48 00 00 01 	bl      c0c <fn_800614A8+0xc0c>
			c0c: R_PPC_REL24	fn_80200C20
     c10:	48 00 00 01 	bl      c10 <fn_800614A8+0xc10>
			c10: R_PPC_REL24	fn_80201814
     c14:	28 03 00 00 	cmplwi  r3,0
     c18:	41 82 00 10 	beq     c28 <fn_800614A8+0xc28>
     c1c:	48 00 00 01 	bl      c1c <fn_800614A8+0xc1c>
			c1c: R_PPC_REL24	fn_80201BC8
     c20:	7c 70 1b 78 	mr      r16,r3
     c24:	48 00 00 08 	b       c2c <fn_800614A8+0xc2c>
     c28:	3a 00 00 00 	li      r16,0
     c2c:	28 10 00 00 	cmplwi  r16,0
     c30:	41 82 00 c0 	beq     cf0 <fn_800614A8+0xcf0>
     c34:	48 00 00 01 	bl      c34 <fn_800614A8+0xc34>
			c34: R_PPC_REL24	fn_800460EC
     c38:	2c 03 00 00 	cmpwi   r3,0
     c3c:	40 82 00 b4 	bne     cf0 <fn_800614A8+0xcf0>
     c40:	7f e3 fb 78 	mr      r3,r31
     c44:	48 00 00 01 	bl      c44 <fn_800614A8+0xc44>
			c44: R_PPC_REL24	fn_800CAF7C
     c48:	2c 03 00 00 	cmpwi   r3,0
     c4c:	41 82 00 a4 	beq     cf0 <fn_800614A8+0xcf0>
     c50:	a8 1d 01 50 	lha     r0,336(r29)
     c54:	7c 00 07 35 	extsh.  r0,r0
     c58:	40 82 00 98 	bne     cf0 <fn_800614A8+0xcf0>
     c5c:	7e 04 83 78 	mr      r4,r16
     c60:	38 61 00 24 	addi    r3,r1,36
     c64:	48 00 00 01 	bl      c64 <fn_800614A8+0xc64>
			c64: R_PPC_REL24	fn_8011F114
     c68:	80 e1 00 28 	lwz     r7,40(r1)
     c6c:	3c 00 43 30 	lis     r0,17200
     c70:	c0 01 00 24 	lfs     f0,36(r1)
     c74:	7f c3 f3 78 	mr      r3,r30
     c78:	80 c1 00 2c 	lwz     r6,44(r1)
     c7c:	38 81 00 54 	addi    r4,r1,84
     c80:	d0 01 00 54 	stfs    f0,84(r1)
     c84:	38 a0 00 00 	li      r5,0
     c88:	c8 20 00 00 	lfd     f1,0(0)
			c88: R_PPC_EMB_SDA21	@569
     c8c:	90 e1 00 58 	stw     r7,88(r1)
     c90:	c0 40 00 00 	lfs     f2,0(0)
			c90: R_PPC_EMB_SDA21	lbl_8064E620
     c94:	90 c1 00 5c 	stw     r6,92(r1)
     c98:	a8 dd 01 4a 	lha     r6,330(r29)
     c9c:	90 01 00 a0 	stw     r0,160(r1)
     ca0:	6c c0 80 00 	xoris   r0,r6,32768
     ca4:	90 01 00 a4 	stw     r0,164(r1)
     ca8:	c8 01 00 a0 	lfd     f0,160(r1)
     cac:	ec 00 08 28 	fsubs   f0,f0,f1
     cb0:	ec 22 00 32 	fmuls   f1,f2,f0
     cb4:	48 00 00 01 	bl      cb4 <fn_800614A8+0xcb4>
			cb4: R_PPC_REL24	fn_80204434
     cb8:	54 60 06 3f 	clrlwi. r0,r3,24
     cbc:	40 82 00 34 	bne     cf0 <fn_800614A8+0xcf0>
     cc0:	80 00 00 00 	lwz     r0,0(0)
			cc0: R_PPC_EMB_SDA21	lbl_8064D18C
     cc4:	2c 00 00 34 	cmpwi   r0,52
     cc8:	41 82 00 28 	beq     cf0 <fn_800614A8+0xcf0>
     ccc:	7e 04 83 78 	mr      r4,r16
     cd0:	38 61 00 18 	addi    r3,r1,24
     cd4:	48 00 00 01 	bl      cd4 <fn_800614A8+0xcd4>
			cd4: R_PPC_REL24	fn_8011F114
     cd8:	c0 01 00 18 	lfs     f0,24(r1)
     cdc:	d0 1d 00 94 	stfs    f0,148(r29)
     ce0:	80 01 00 1c 	lwz     r0,28(r1)
     ce4:	90 1d 00 98 	stw     r0,152(r29)
     ce8:	80 01 00 20 	lwz     r0,32(r1)
     cec:	90 1d 00 9c 	stw     r0,156(r29)
     cf0:	38 60 00 01 	li      r3,1
     cf4:	48 00 0c f8 	b       19ec <fn_800614A8+0x19ec>
     cf8:	2c 16 00 02 	cmpwi   r22,2
     cfc:	40 82 0c f0 	bne     19ec <fn_800614A8+0x19ec>
     d00:	7f c3 f3 78 	mr      r3,r30
     d04:	48 00 00 01 	bl      d04 <fn_800614A8+0xd04>
			d04: R_PPC_REL24	fn_80128EAC
     d08:	7c 70 1b 78 	mr      r16,r3
     d0c:	7f c3 f3 78 	mr      r3,r30
     d10:	48 00 00 01 	bl      d10 <fn_800614A8+0xd10>
			d10: R_PPC_REL24	fn_801290D0
     d14:	54 60 07 7b 	rlwinm. r0,r3,0,29,29
     d18:	7c 64 1b 78 	mr      r4,r3
     d1c:	41 82 00 38 	beq     d54 <fn_800614A8+0xd54>
     d20:	2c 10 00 03 	cmpwi   r16,3
     d24:	41 82 00 0c 	beq     d30 <fn_800614A8+0xd30>
     d28:	2c 10 00 02 	cmpwi   r16,2
     d2c:	40 82 00 28 	bne     d54 <fn_800614A8+0xd54>
     d30:	80 00 00 00 	lwz     r0,0(0)
			d30: R_PPC_EMB_SDA21	lbl_8064D18C
     d34:	2c 00 00 53 	cmpwi   r0,83
     d38:	40 82 00 10 	bne     d48 <fn_800614A8+0xd48>
     d3c:	7f c3 f3 78 	mr      r3,r30
     d40:	48 00 00 01 	bl      d40 <fn_800614A8+0xd40>
			d40: R_PPC_REL24	fn_8012B344
     d44:	48 00 00 10 	b       d54 <fn_800614A8+0xd54>
     d48:	7f c3 f3 78 	mr      r3,r30
     d4c:	54 84 07 b8 	rlwinm  r4,r4,0,30,28
     d50:	48 00 00 01 	bl      d50 <fn_800614A8+0xd50>
			d50: R_PPC_REL24	fn_80128F74
     d54:	c0 00 00 00 	lfs     f0,0(0)
			d54: R_PPC_EMB_SDA21	lbl_8064E5DC
     d58:	38 60 00 01 	li      r3,1
     d5c:	d0 1d 00 c4 	stfs    f0,196(r29)
     d60:	48 00 0c 8c 	b       19ec <fn_800614A8+0x19ec>
     d64:	2c 17 00 03 	cmpwi   r23,3
     d68:	40 82 00 ac 	bne     e14 <fn_800614A8+0xe14>
     d6c:	2c 16 00 03 	cmpwi   r22,3
     d70:	40 82 00 6c 	bne     ddc <fn_800614A8+0xddc>
     d74:	7f 83 e3 78 	mr      r3,r28
     d78:	7f e4 fb 78 	mr      r4,r31
     d7c:	7f c5 f3 78 	mr      r5,r30
     d80:	7f 66 db 78 	mr      r6,r27
     d84:	7f 47 d3 78 	mr      r7,r26
     d88:	48 00 00 01 	bl      d88 <fn_800614A8+0xd88>
			d88: R_PPC_REL24	fn_8005FD84
     d8c:	7f e3 fb 78 	mr      r3,r31
     d90:	7f a4 eb 78 	mr      r4,r29
     d94:	48 00 00 01 	bl      d94 <fn_800614A8+0xd94>
			d94: R_PPC_REL24	fn_800BE010
     d98:	7e 83 a3 78 	mr      r3,r20
     d9c:	48 00 00 01 	bl      d9c <fn_800614A8+0xd9c>
			d9c: R_PPC_REL24	fn_80201C48
     da0:	2c 03 00 00 	cmpwi   r3,0
     da4:	41 82 00 10 	beq     db4 <fn_800614A8+0xdb4>
     da8:	7f e3 fb 78 	mr      r3,r31
     dac:	7f a4 eb 78 	mr      r4,r29
     db0:	48 00 00 01 	bl      db0 <fn_800614A8+0xdb0>
			db0: R_PPC_REL24	fn_800BDEE4
     db4:	7f e3 fb 78 	mr      r3,r31
     db8:	7f c4 f3 78 	mr      r4,r30
     dbc:	7f 85 e3 78 	mr      r5,r28
     dc0:	7f a6 eb 78 	mr      r6,r29
     dc4:	7f 07 c3 78 	mr      r7,r24
     dc8:	7e 48 93 78 	mr      r8,r18
     dcc:	7e 09 83 78 	mr      r9,r16
     dd0:	48 00 00 01 	bl      dd0 <fn_800614A8+0xdd0>
			dd0: R_PPC_REL24	fn_80060F9C
     dd4:	38 60 00 01 	li      r3,1
     dd8:	48 00 0c 14 	b       19ec <fn_800614A8+0x19ec>
     ddc:	2c 16 00 66 	cmpwi   r22,102
     de0:	40 82 00 2c 	bne     e0c <fn_800614A8+0xe0c>
     de4:	7f c3 f3 78 	mr      r3,r30
     de8:	48 00 00 01 	bl      de8 <fn_800614A8+0xde8>
			de8: R_PPC_REL24	fn_8012B344
     dec:	7f e3 fb 78 	mr      r3,r31
     df0:	38 80 00 01 	li      r4,1
     df4:	48 00 00 01 	bl      df4 <fn_800614A8+0xdf4>
			df4: R_PPC_REL24	fn_80201D2C
     df8:	7f e3 fb 78 	mr      r3,r31
     dfc:	38 80 00 01 	li      r4,1
     e00:	48 00 00 01 	bl      e00 <fn_800614A8+0xe00>
			e00: R_PPC_REL24	fn_80201D14
     e04:	38 60 00 01 	li      r3,1
     e08:	48 00 0b e4 	b       19ec <fn_800614A8+0x19ec>
     e0c:	38 60 00 00 	li      r3,0
     e10:	48 00 0b dc 	b       19ec <fn_800614A8+0x19ec>
     e14:	2c 17 00 06 	cmpwi   r23,6
     e18:	40 82 01 2c 	bne     f44 <fn_800614A8+0xf44>
     e1c:	2c 16 00 01 	cmpwi   r22,1
     e20:	40 82 00 18 	bne     e38 <fn_800614A8+0xe38>
     e24:	88 1a 00 89 	lbz     r0,137(r26)
     e28:	38 60 00 01 	li      r3,1
     e2c:	54 00 06 3c 	rlwinm  r0,r0,0,24,30
     e30:	98 1a 00 89 	stb     r0,137(r26)
     e34:	48 00 0b b8 	b       19ec <fn_800614A8+0x19ec>
     e38:	2c 16 00 03 	cmpwi   r22,3
     e3c:	40 82 00 24 	bne     e60 <fn_800614A8+0xe60>
     e40:	7f 83 e3 78 	mr      r3,r28
     e44:	7f e4 fb 78 	mr      r4,r31
     e48:	7f c5 f3 78 	mr      r5,r30
     e4c:	7f 66 db 78 	mr      r6,r27
     e50:	7f 47 d3 78 	mr      r7,r26
     e54:	48 00 00 01 	bl      e54 <fn_800614A8+0xe54>
			e54: R_PPC_REL24	fn_8005FD84
     e58:	38 60 00 01 	li      r3,1
     e5c:	48 00 0b 90 	b       19ec <fn_800614A8+0x19ec>
     e60:	2c 16 00 0c 	cmpwi   r22,12
     e64:	40 82 00 44 	bne     ea8 <fn_800614A8+0xea8>
     e68:	7f e3 fb 78 	mr      r3,r31
     e6c:	7f c4 f3 78 	mr      r4,r30
     e70:	7f 05 c3 78 	mr      r5,r24
     e74:	48 00 00 01 	bl      e74 <fn_800614A8+0xe74>
			e74: R_PPC_REL24	fn_80060F10
     e78:	2c 03 00 00 	cmpwi   r3,0
     e7c:	40 82 00 24 	bne     ea0 <fn_800614A8+0xea0>
     e80:	38 00 00 5a 	li      r0,90
     e84:	7f e3 fb 78 	mr      r3,r31
     e88:	b0 1d 01 50 	sth     r0,336(r29)
     e8c:	38 80 00 01 	li      r4,1
     e90:	48 00 00 01 	bl      e90 <fn_800614A8+0xe90>
			e90: R_PPC_REL24	fn_80201D2C
     e94:	7f e3 fb 78 	mr      r3,r31
     e98:	38 80 00 01 	li      r4,1
     e9c:	48 00 00 01 	bl      e9c <fn_800614A8+0xe9c>
			e9c: R_PPC_REL24	fn_80201D14
     ea0:	38 60 00 01 	li      r3,1
     ea4:	48 00 0b 48 	b       19ec <fn_800614A8+0x19ec>
     ea8:	2c 16 00 07 	cmpwi   r22,7
     eac:	40 82 00 68 	bne     f14 <fn_800614A8+0xf14>
     eb0:	7f e3 fb 78 	mr      r3,r31
     eb4:	38 95 01 b8 	addi    r4,r21,440
     eb8:	38 d5 01 cc 	addi    r6,r21,460
     ebc:	39 15 01 d8 	addi    r8,r21,472
     ec0:	38 a0 00 00 	li      r5,0
			ec0: R_PPC_EMB_SDA21	lbl_8064B508
     ec4:	38 e0 00 00 	li      r7,0
			ec4: R_PPC_EMB_SDA21	lbl_8064B510
     ec8:	48 00 00 01 	bl      ec8 <fn_800614A8+0xec8>
			ec8: R_PPC_REL24	fn_80035FB8
     ecc:	2c 03 00 00 	cmpwi   r3,0
     ed0:	40 82 00 3c 	bne     f0c <fn_800614A8+0xf0c>
     ed4:	7f e3 fb 78 	mr      r3,r31
     ed8:	7f c4 f3 78 	mr      r4,r30
     edc:	7f 05 c3 78 	mr      r5,r24
     ee0:	48 00 00 01 	bl      ee0 <fn_800614A8+0xee0>
			ee0: R_PPC_REL24	fn_80060F10
     ee4:	2c 03 00 00 	cmpwi   r3,0
     ee8:	40 82 00 24 	bne     f0c <fn_800614A8+0xf0c>
     eec:	38 00 00 5a 	li      r0,90
     ef0:	7f e3 fb 78 	mr      r3,r31
     ef4:	b0 1d 01 50 	sth     r0,336(r29)
     ef8:	38 80 00 01 	li      r4,1
     efc:	48 00 00 01 	bl      efc <fn_800614A8+0xefc>
			efc: R_PPC_REL24	fn_80201D2C
     f00:	7f e3 fb 78 	mr      r3,r31
     f04:	38 80 00 01 	li      r4,1
     f08:	48 00 00 01 	bl      f08 <fn_800614A8+0xf08>
			f08: R_PPC_REL24	fn_80201D14
     f0c:	38 60 00 01 	li      r3,1
     f10:	48 00 0a dc 	b       19ec <fn_800614A8+0x19ec>
     f14:	2c 16 00 0d 	cmpwi   r22,13
     f18:	40 82 0a d4 	bne     19ec <fn_800614A8+0x19ec>
     f1c:	7f e3 fb 78 	mr      r3,r31
     f20:	38 80 00 01 	li      r4,1
     f24:	48 00 00 01 	bl      f24 <fn_800614A8+0xf24>
			f24: R_PPC_REL24	fn_80201D2C
     f28:	7f e3 fb 78 	mr      r3,r31
     f2c:	38 80 00 01 	li      r4,1
     f30:	48 00 00 01 	bl      f30 <fn_800614A8+0xf30>
			f30: R_PPC_REL24	fn_80201D14
     f34:	7f c3 f3 78 	mr      r3,r30
     f38:	48 00 00 01 	bl      f38 <fn_800614A8+0xf38>
			f38: R_PPC_REL24	fn_8012B344
     f3c:	38 60 00 01 	li      r3,1
     f40:	48 00 0a ac 	b       19ec <fn_800614A8+0x19ec>
     f44:	2c 17 00 5f 	cmpwi   r23,95
     f48:	40 82 00 84 	bne     fcc <fn_800614A8+0xfcc>
     f4c:	2c 16 00 03 	cmpwi   r22,3
     f50:	40 82 00 18 	bne     f68 <fn_800614A8+0xf68>
     f54:	7f e3 fb 78 	mr      r3,r31
     f58:	7f c4 f3 78 	mr      r4,r30
     f5c:	48 00 00 01 	bl      f5c <fn_800614A8+0xf5c>
			f5c: R_PPC_REL24	fn_800C9B74
     f60:	38 60 00 01 	li      r3,1
     f64:	48 00 0a 88 	b       19ec <fn_800614A8+0x19ec>
     f68:	2c 16 00 68 	cmpwi   r22,104
     f6c:	40 82 00 24 	bne     f90 <fn_800614A8+0xf90>
     f70:	7f e3 fb 78 	mr      r3,r31
     f74:	38 80 00 01 	li      r4,1
     f78:	48 00 00 01 	bl      f78 <fn_800614A8+0xf78>
			f78: R_PPC_REL24	fn_80201D2C
     f7c:	7f e3 fb 78 	mr      r3,r31
     f80:	38 80 00 01 	li      r4,1
     f84:	48 00 00 01 	bl      f84 <fn_800614A8+0xf84>
			f84: R_PPC_REL24	fn_80201D14
     f88:	38 60 00 01 	li      r3,1
     f8c:	48 00 0a 60 	b       19ec <fn_800614A8+0x19ec>
     f90:	2c 16 00 02 	cmpwi   r22,2
     f94:	40 82 00 18 	bne     fac <fn_800614A8+0xfac>
     f98:	7f e3 fb 78 	mr      r3,r31
     f9c:	7f c4 f3 78 	mr      r4,r30
     fa0:	48 00 00 01 	bl      fa0 <fn_800614A8+0xfa0>
			fa0: R_PPC_REL24	fn_800C9AD4
     fa4:	38 60 00 01 	li      r3,1
     fa8:	48 00 0a 44 	b       19ec <fn_800614A8+0x19ec>
     fac:	2c 16 00 69 	cmpwi   r22,105
     fb0:	40 82 00 0c 	bne     fbc <fn_800614A8+0xfbc>
     fb4:	38 60 00 01 	li      r3,1
     fb8:	48 00 0a 34 	b       19ec <fn_800614A8+0x19ec>
     fbc:	2c 16 00 65 	cmpwi   r22,101
     fc0:	40 82 0a 2c 	bne     19ec <fn_800614A8+0x19ec>
     fc4:	38 60 00 01 	li      r3,1
     fc8:	48 00 0a 24 	b       19ec <fn_800614A8+0x19ec>
     fcc:	2c 17 00 56 	cmpwi   r23,86
     fd0:	40 82 01 f4 	bne     11c4 <fn_800614A8+0x11c4>
     fd4:	2c 16 00 03 	cmpwi   r22,3
     fd8:	40 82 00 24 	bne     ffc <fn_800614A8+0xffc>
     fdc:	7f 83 e3 78 	mr      r3,r28
     fe0:	7f e4 fb 78 	mr      r4,r31
     fe4:	7f c5 f3 78 	mr      r5,r30
     fe8:	7f 66 db 78 	mr      r6,r27
     fec:	7f 47 d3 78 	mr      r7,r26
     ff0:	48 00 00 01 	bl      ff0 <fn_800614A8+0xff0>
			ff0: R_PPC_REL24	fn_8005FD84
     ff4:	38 60 00 01 	li      r3,1
     ff8:	48 00 09 f4 	b       19ec <fn_800614A8+0x19ec>
     ffc:	2c 16 00 05 	cmpwi   r22,5
    1000:	40 82 01 60 	bne     1160 <fn_800614A8+0x1160>
    1004:	7f e3 fb 78 	mr      r3,r31
    1008:	3a 00 00 00 	li      r16,0
    100c:	38 80 00 03 	li      r4,3
    1010:	48 00 00 01 	bl      1010 <fn_800614A8+0x1010>
			1010: R_PPC_REL24	fn_80066D04
    1014:	2c 03 00 00 	cmpwi   r3,0
    1018:	40 82 00 1c 	bne     1034 <fn_800614A8+0x1034>
    101c:	7f e3 fb 78 	mr      r3,r31
    1020:	38 80 00 02 	li      r4,2
    1024:	48 00 00 01 	bl      1024 <fn_800614A8+0x1024>
			1024: R_PPC_REL24	fn_80066D04
    1028:	2c 03 00 00 	cmpwi   r3,0
    102c:	40 82 00 08 	bne     1034 <fn_800614A8+0x1034>
    1030:	3a 00 00 01 	li      r16,1
    1034:	7f c3 f3 78 	mr      r3,r30
    1038:	48 00 00 01 	bl      1038 <fn_800614A8+0x1038>
			1038: R_PPC_REL24	fn_8012B344
    103c:	7f e3 fb 78 	mr      r3,r31
    1040:	38 81 00 48 	addi    r4,r1,72
    1044:	48 00 00 01 	bl      1044 <fn_800614A8+0x1044>
			1044: R_PPC_REL24	fn_802045AC
    1048:	c0 01 00 78 	lfs     f0,120(r1)
    104c:	c0 41 00 7c 	lfs     f2,124(r1)
    1050:	c0 21 00 48 	lfs     f1,72(r1)
    1054:	fc 60 00 1e 	fctiwz  f3,f0
    1058:	c0 01 00 4c 	lfs     f0,76(r1)
    105c:	fc 40 10 1e 	fctiwz  f2,f2
    1060:	fc 20 08 1e 	fctiwz  f1,f1
    1064:	fc 00 00 1e 	fctiwz  f0,f0
    1068:	d8 61 00 a0 	stfd    f3,160(r1)
    106c:	d8 41 00 a8 	stfd    f2,168(r1)
    1070:	80 61 00 a4 	lwz     r3,164(r1)
    1074:	d8 21 00 b0 	stfd    f1,176(r1)
    1078:	80 81 00 ac 	lwz     r4,172(r1)
    107c:	d8 01 00 b8 	stfd    f0,184(r1)
    1080:	80 a1 00 b4 	lwz     r5,180(r1)
    1084:	80 c1 00 bc 	lwz     r6,188(r1)
    1088:	48 00 00 01 	bl      1088 <fn_800614A8+0x1088>
			1088: R_PPC_REL24	fn_80179064
    108c:	2c 10 00 00 	cmpwi   r16,0
    1090:	40 82 00 b0 	bne     1140 <fn_800614A8+0x1140>
    1094:	3a 20 00 01 	li      r17,1
    1098:	48 00 00 01 	bl      1098 <fn_800614A8+0x1098>
			1098: R_PPC_REL24	fn_800FBFB0
    109c:	54 60 07 ff 	clrlwi. r0,r3,31
    10a0:	41 82 00 7c 	beq     111c <fn_800614A8+0x111c>
    10a4:	88 1a 00 89 	lbz     r0,137(r26)
    10a8:	54 00 07 ff 	clrlwi. r0,r0,31
    10ac:	41 82 00 70 	beq     111c <fn_800614A8+0x111c>
    10b0:	48 00 00 01 	bl      10b0 <fn_800614A8+0x10b0>
			10b0: R_PPC_REL24	fn_801A717C
    10b4:	88 1a 00 89 	lbz     r0,137(r26)
    10b8:	7c 6f 1b 78 	mr      r15,r3
    10bc:	38 60 00 10 	li      r3,16
    10c0:	54 00 06 3c 	rlwinm  r0,r0,0,24,30
    10c4:	98 1a 00 89 	stb     r0,137(r26)
    10c8:	48 00 00 01 	bl      10c8 <fn_800614A8+0x10c8>
			10c8: R_PPC_REL24	fn_801A7470
    10cc:	7d e3 7b 78 	mr      r3,r15
    10d0:	7f 84 e3 78 	mr      r4,r28
    10d4:	48 00 00 01 	bl      10d4 <fn_800614A8+0x10d4>
			10d4: R_PPC_REL24	fn_801A74A0
    10d8:	7d e3 7b 78 	mr      r3,r15
    10dc:	7f 84 e3 78 	mr      r4,r28
    10e0:	48 00 00 01 	bl      10e0 <fn_800614A8+0x10e0>
			10e0: R_PPC_REL24	fn_801A74A8
    10e4:	7d e3 7b 78 	mr      r3,r15
    10e8:	38 81 00 78 	addi    r4,r1,120
    10ec:	48 00 00 01 	bl      10ec <fn_800614A8+0x10ec>
			10ec: R_PPC_REL24	fn_801A764C
    10f0:	7f 84 e3 78 	mr      r4,r28
    10f4:	7f 85 e3 78 	mr      r5,r28
    10f8:	7d e6 7b 78 	mr      r6,r15
    10fc:	38 60 00 35 	li      r3,53
    1100:	48 00 00 01 	bl      1100 <fn_800614A8+0x1100>
			1100: R_PPC_REL24	fn_8020123C
    1104:	7c 90 23 78 	mr      r16,r4
    1108:	7d e3 7b 78 	mr      r3,r15
    110c:	48 00 00 01 	bl      110c <fn_800614A8+0x110c>
			110c: R_PPC_REL24	fn_801A7228
    1110:	56 00 07 ff 	clrlwi. r0,r16,31
    1114:	41 82 00 08 	beq     111c <fn_800614A8+0x111c>
    1118:	3a 20 00 00 	li      r17,0
    111c:	2c 11 00 00 	cmpwi   r17,0
    1120:	41 82 00 38 	beq     1158 <fn_800614A8+0x1158>
    1124:	7f e3 fb 78 	mr      r3,r31
    1128:	38 80 00 01 	li      r4,1
    112c:	48 00 00 01 	bl      112c <fn_800614A8+0x112c>
			112c: R_PPC_REL24	fn_80201D2C
    1130:	7f e3 fb 78 	mr      r3,r31
    1134:	38 80 00 01 	li      r4,1
    1138:	48 00 00 01 	bl      1138 <fn_800614A8+0x1138>
			1138: R_PPC_REL24	fn_80201D14
    113c:	48 00 00 1c 	b       1158 <fn_800614A8+0x1158>
    1140:	7f e3 fb 78 	mr      r3,r31
    1144:	38 80 00 01 	li      r4,1
    1148:	48 00 00 01 	bl      1148 <fn_800614A8+0x1148>
			1148: R_PPC_REL24	fn_80201D2C
    114c:	7f e3 fb 78 	mr      r3,r31
    1150:	38 80 00 01 	li      r4,1
    1154:	48 00 00 01 	bl      1154 <fn_800614A8+0x1154>
			1154: R_PPC_REL24	fn_80201D14
    1158:	38 60 00 01 	li      r3,1
    115c:	48 00 08 90 	b       19ec <fn_800614A8+0x19ec>
    1160:	2c 16 00 3d 	cmpwi   r22,61
    1164:	40 82 00 38 	bne     119c <fn_800614A8+0x119c>
    1168:	7f e3 fb 78 	mr      r3,r31
    116c:	7f a4 eb 78 	mr      r4,r29
    1170:	48 00 00 01 	bl      1170 <fn_800614A8+0x1170>
			1170: R_PPC_REL24	fn_800EA3A0
    1174:	7f c3 f3 78 	mr      r3,r30
    1178:	48 00 00 01 	bl      1178 <fn_800614A8+0x1178>
			1178: R_PPC_REL24	fn_8012B344
    117c:	7f e3 fb 78 	mr      r3,r31
    1180:	38 80 00 01 	li      r4,1
    1184:	48 00 00 01 	bl      1184 <fn_800614A8+0x1184>
			1184: R_PPC_REL24	fn_80201D2C
    1188:	7f e3 fb 78 	mr      r3,r31
    118c:	38 80 00 01 	li      r4,1
    1190:	48 00 00 01 	bl      1190 <fn_800614A8+0x1190>
			1190: R_PPC_REL24	fn_80201D14
    1194:	38 60 00 01 	li      r3,1
    1198:	48 00 08 54 	b       19ec <fn_800614A8+0x19ec>
    119c:	2c 16 00 02 	cmpwi   r22,2
    11a0:	40 82 08 4c 	bne     19ec <fn_800614A8+0x19ec>
    11a4:	7f 83 e3 78 	mr      r3,r28
    11a8:	7f 84 e3 78 	mr      r4,r28
    11ac:	38 a0 00 56 	li      r5,86
    11b0:	38 c0 00 05 	li      r6,5
    11b4:	38 e0 00 00 	li      r7,0
    11b8:	48 00 00 01 	bl      11b8 <fn_800614A8+0x11b8>
			11b8: R_PPC_REL24	fn_802006D4
    11bc:	38 60 00 01 	li      r3,1
    11c0:	48 00 08 2c 	b       19ec <fn_800614A8+0x19ec>
    11c4:	2c 17 00 59 	cmpwi   r23,89
    11c8:	40 82 00 c0 	bne     1288 <fn_800614A8+0x1288>
    11cc:	2c 16 00 03 	cmpwi   r22,3
    11d0:	40 82 00 24 	bne     11f4 <fn_800614A8+0x11f4>
    11d4:	7f 83 e3 78 	mr      r3,r28
    11d8:	7f e4 fb 78 	mr      r4,r31
    11dc:	7f c5 f3 78 	mr      r5,r30
    11e0:	7f 66 db 78 	mr      r6,r27
    11e4:	7f 47 d3 78 	mr      r7,r26
    11e8:	48 00 00 01 	bl      11e8 <fn_800614A8+0x11e8>
			11e8: R_PPC_REL24	fn_8005FD84
    11ec:	38 60 00 01 	li      r3,1
    11f0:	48 00 07 fc 	b       19ec <fn_800614A8+0x19ec>
    11f4:	2c 16 00 05 	cmpwi   r22,5
    11f8:	40 82 00 2c 	bne     1224 <fn_800614A8+0x1224>
    11fc:	7f c3 f3 78 	mr      r3,r30
    1200:	48 00 00 01 	bl      1200 <fn_800614A8+0x1200>
			1200: R_PPC_REL24	fn_8012B344
    1204:	7f e3 fb 78 	mr      r3,r31
    1208:	38 80 00 01 	li      r4,1
    120c:	48 00 00 01 	bl      120c <fn_800614A8+0x120c>
			120c: R_PPC_REL24	fn_80201D2C
    1210:	7f e3 fb 78 	mr      r3,r31
    1214:	38 80 00 01 	li      r4,1
    1218:	48 00 00 01 	bl      1218 <fn_800614A8+0x1218>
			1218: R_PPC_REL24	fn_80201D14
    121c:	38 60 00 01 	li      r3,1
    1220:	48 00 07 cc 	b       19ec <fn_800614A8+0x19ec>
    1224:	2c 16 00 3d 	cmpwi   r22,61
    1228:	40 82 00 38 	bne     1260 <fn_800614A8+0x1260>
    122c:	7f e3 fb 78 	mr      r3,r31
    1230:	7f a4 eb 78 	mr      r4,r29
    1234:	48 00 00 01 	bl      1234 <fn_800614A8+0x1234>
			1234: R_PPC_REL24	fn_800EA3A0
    1238:	7f c3 f3 78 	mr      r3,r30
    123c:	48 00 00 01 	bl      123c <fn_800614A8+0x123c>
			123c: R_PPC_REL24	fn_8012B344
    1240:	7f e3 fb 78 	mr      r3,r31
    1244:	38 80 00 01 	li      r4,1
    1248:	48 00 00 01 	bl      1248 <fn_800614A8+0x1248>
			1248: R_PPC_REL24	fn_80201D2C
    124c:	7f e3 fb 78 	mr      r3,r31
    1250:	38 80 00 01 	li      r4,1
    1254:	48 00 00 01 	bl      1254 <fn_800614A8+0x1254>
			1254: R_PPC_REL24	fn_80201D14
    1258:	38 60 00 01 	li      r3,1
    125c:	48 00 07 90 	b       19ec <fn_800614A8+0x19ec>
    1260:	2c 16 00 02 	cmpwi   r22,2
    1264:	40 82 07 88 	bne     19ec <fn_800614A8+0x19ec>
    1268:	7f 83 e3 78 	mr      r3,r28
    126c:	7f 84 e3 78 	mr      r4,r28
    1270:	38 a0 00 59 	li      r5,89
    1274:	38 c0 00 05 	li      r6,5
    1278:	38 e0 00 00 	li      r7,0
    127c:	48 00 00 01 	bl      127c <fn_800614A8+0x127c>
			127c: R_PPC_REL24	fn_802006D4
    1280:	38 60 00 01 	li      r3,1
    1284:	48 00 07 68 	b       19ec <fn_800614A8+0x19ec>
    1288:	2c 17 00 07 	cmpwi   r23,7
    128c:	40 82 00 b0 	bne     133c <fn_800614A8+0x133c>
    1290:	2c 16 00 03 	cmpwi   r22,3
    1294:	40 82 00 24 	bne     12b8 <fn_800614A8+0x12b8>
    1298:	7f 83 e3 78 	mr      r3,r28
    129c:	7f e4 fb 78 	mr      r4,r31
    12a0:	7f c5 f3 78 	mr      r5,r30
    12a4:	7f 66 db 78 	mr      r6,r27
    12a8:	7f 47 d3 78 	mr      r7,r26
    12ac:	48 00 00 01 	bl      12ac <fn_800614A8+0x12ac>
			12ac: R_PPC_REL24	fn_8005FD84
    12b0:	38 60 00 01 	li      r3,1
    12b4:	48 00 07 38 	b       19ec <fn_800614A8+0x19ec>
    12b8:	2c 16 00 36 	cmpwi   r22,54
    12bc:	40 82 00 24 	bne     12e0 <fn_800614A8+0x12e0>
    12c0:	7f e3 fb 78 	mr      r3,r31
    12c4:	38 80 00 01 	li      r4,1
    12c8:	48 00 00 01 	bl      12c8 <fn_800614A8+0x12c8>
			12c8: R_PPC_REL24	fn_80201D2C
    12cc:	7f e3 fb 78 	mr      r3,r31
    12d0:	38 80 00 01 	li      r4,1
    12d4:	48 00 00 01 	bl      12d4 <fn_800614A8+0x12d4>
			12d4: R_PPC_REL24	fn_80201D14
    12d8:	38 60 00 01 	li      r3,1
    12dc:	48 00 07 10 	b       19ec <fn_800614A8+0x19ec>
    12e0:	2c 16 00 07 	cmpwi   r22,7
    12e4:	40 82 00 48 	bne     132c <fn_800614A8+0x132c>
    12e8:	7f e3 fb 78 	mr      r3,r31
    12ec:	38 95 01 f0 	addi    r4,r21,496
    12f0:	38 d5 01 cc 	addi    r6,r21,460
    12f4:	39 15 01 d8 	addi    r8,r21,472
    12f8:	38 a0 00 00 	li      r5,0
			12f8: R_PPC_EMB_SDA21	lbl_8064B518
    12fc:	38 e0 00 00 	li      r7,0
			12fc: R_PPC_EMB_SDA21	lbl_8064B510
    1300:	48 00 00 01 	bl      1300 <fn_800614A8+0x1300>
			1300: R_PPC_REL24	fn_80035FB8
    1304:	2c 03 00 00 	cmpwi   r3,0
    1308:	40 82 00 1c 	bne     1324 <fn_800614A8+0x1324>
    130c:	7f e3 fb 78 	mr      r3,r31
    1310:	38 80 00 01 	li      r4,1
    1314:	48 00 00 01 	bl      1314 <fn_800614A8+0x1314>
			1314: R_PPC_REL24	fn_80201D2C
    1318:	7f e3 fb 78 	mr      r3,r31
    131c:	38 80 00 01 	li      r4,1
    1320:	48 00 00 01 	bl      1320 <fn_800614A8+0x1320>
			1320: R_PPC_REL24	fn_80201D14
    1324:	38 60 00 01 	li      r3,1
    1328:	48 00 06 c4 	b       19ec <fn_800614A8+0x19ec>
    132c:	2c 16 00 35 	cmpwi   r22,53
    1330:	40 82 06 bc 	bne     19ec <fn_800614A8+0x19ec>
    1334:	38 60 00 01 	li      r3,1
    1338:	48 00 06 b4 	b       19ec <fn_800614A8+0x19ec>
    133c:	2c 17 00 20 	cmpwi   r23,32
    1340:	40 82 01 80 	bne     14c0 <fn_800614A8+0x14c0>
    1344:	2c 16 00 03 	cmpwi   r22,3
    1348:	40 82 00 24 	bne     136c <fn_800614A8+0x136c>
    134c:	7f 83 e3 78 	mr      r3,r28
    1350:	7f e4 fb 78 	mr      r4,r31
    1354:	7f c5 f3 78 	mr      r5,r30
    1358:	7f 66 db 78 	mr      r6,r27
    135c:	7f 47 d3 78 	mr      r7,r26
    1360:	48 00 00 01 	bl      1360 <fn_800614A8+0x1360>
			1360: R_PPC_REL24	fn_8005FD84
    1364:	38 60 00 01 	li      r3,1
    1368:	48 00 06 84 	b       19ec <fn_800614A8+0x19ec>
    136c:	2c 16 00 05 	cmpwi   r22,5
    1370:	40 82 00 80 	bne     13f0 <fn_800614A8+0x13f0>
    1374:	7f c3 f3 78 	mr      r3,r30
    1378:	48 00 00 01 	bl      1378 <fn_800614A8+0x1378>
			1378: R_PPC_REL24	fn_80128EAC
    137c:	7c 71 1b 78 	mr      r17,r3
    1380:	7f c3 f3 78 	mr      r3,r30
    1384:	48 00 00 01 	bl      1384 <fn_800614A8+0x1384>
			1384: R_PPC_REL24	fn_801290D0
    1388:	7c 70 1b 78 	mr      r16,r3
    138c:	7f c3 f3 78 	mr      r3,r30
    1390:	48 00 00 01 	bl      1390 <fn_800614A8+0x1390>
			1390: R_PPC_REL24	fn_80128E30
    1394:	28 03 00 00 	cmplwi  r3,0
    1398:	41 82 00 38 	beq     13d0 <fn_800614A8+0x13d0>
    139c:	2c 11 00 0f 	cmpwi   r17,15
    13a0:	40 82 00 30 	bne     13d0 <fn_800614A8+0x13d0>
    13a4:	56 00 07 ff 	clrlwi. r0,r16,31
    13a8:	41 82 00 28 	beq     13d0 <fn_800614A8+0x13d0>
    13ac:	7f c3 f3 78 	mr      r3,r30
    13b0:	48 00 00 01 	bl      13b0 <fn_800614A8+0x13b0>
			13b0: R_PPC_REL24	fn_8012B344
    13b4:	7f e3 fb 78 	mr      r3,r31
    13b8:	38 80 00 01 	li      r4,1
    13bc:	48 00 00 01 	bl      13bc <fn_800614A8+0x13bc>
			13bc: R_PPC_REL24	fn_80201D2C
    13c0:	7f e3 fb 78 	mr      r3,r31
    13c4:	38 80 00 01 	li      r4,1
    13c8:	48 00 00 01 	bl      13c8 <fn_800614A8+0x13c8>
			13c8: R_PPC_REL24	fn_80201D14
    13cc:	48 00 00 1c 	b       13e8 <fn_800614A8+0x13e8>
    13d0:	7f e3 fb 78 	mr      r3,r31
    13d4:	38 80 00 01 	li      r4,1
    13d8:	48 00 00 01 	bl      13d8 <fn_800614A8+0x13d8>
			13d8: R_PPC_REL24	fn_80201D2C
    13dc:	7f e3 fb 78 	mr      r3,r31
    13e0:	38 80 00 01 	li      r4,1
    13e4:	48 00 00 01 	bl      13e4 <fn_800614A8+0x13e4>
			13e4: R_PPC_REL24	fn_80201D14
    13e8:	38 60 00 01 	li      r3,1
    13ec:	48 00 06 00 	b       19ec <fn_800614A8+0x19ec>
    13f0:	2c 16 00 07 	cmpwi   r22,7
    13f4:	40 82 00 48 	bne     143c <fn_800614A8+0x143c>
    13f8:	7f e3 fb 78 	mr      r3,r31
    13fc:	38 95 01 f0 	addi    r4,r21,496
    1400:	38 d5 01 cc 	addi    r6,r21,460
    1404:	39 15 01 d8 	addi    r8,r21,472
    1408:	38 a0 00 00 	li      r5,0
			1408: R_PPC_EMB_SDA21	lbl_8064B51C
    140c:	38 e0 00 00 	li      r7,0
			140c: R_PPC_EMB_SDA21	lbl_8064B510
    1410:	48 00 00 01 	bl      1410 <fn_800614A8+0x1410>
			1410: R_PPC_REL24	fn_80035FB8
    1414:	2c 03 00 00 	cmpwi   r3,0
    1418:	40 82 00 1c 	bne     1434 <fn_800614A8+0x1434>
    141c:	7f e3 fb 78 	mr      r3,r31
    1420:	38 80 00 01 	li      r4,1
    1424:	48 00 00 01 	bl      1424 <fn_800614A8+0x1424>
			1424: R_PPC_REL24	fn_80201D2C
    1428:	7f e3 fb 78 	mr      r3,r31
    142c:	38 80 00 01 	li      r4,1
    1430:	48 00 00 01 	bl      1430 <fn_800614A8+0x1430>
			1430: R_PPC_REL24	fn_80201D14
    1434:	38 60 00 01 	li      r3,1
    1438:	48 00 05 b4 	b       19ec <fn_800614A8+0x19ec>
    143c:	2c 16 00 3d 	cmpwi   r22,61
    1440:	40 82 00 38 	bne     1478 <fn_800614A8+0x1478>
    1444:	7f e3 fb 78 	mr      r3,r31
    1448:	7f a4 eb 78 	mr      r4,r29
    144c:	48 00 00 01 	bl      144c <fn_800614A8+0x144c>
			144c: R_PPC_REL24	fn_800EA3A0
    1450:	7f e3 fb 78 	mr      r3,r31
    1454:	7f a4 eb 78 	mr      r4,r29
    1458:	48 00 00 01 	bl      1458 <fn_800614A8+0x1458>
			1458: R_PPC_REL24	fn_800BD2DC
    145c:	7f 84 e3 78 	mr      r4,r28
    1460:	7f 85 e3 78 	mr      r5,r28
    1464:	38 60 00 05 	li      r3,5
    1468:	38 c0 00 00 	li      r6,0
    146c:	48 00 00 01 	bl      146c <fn_800614A8+0x146c>
			146c: R_PPC_REL24	fn_8020123C
    1470:	38 60 00 01 	li      r3,1
    1474:	48 00 05 78 	b       19ec <fn_800614A8+0x19ec>
    1478:	2c 16 00 02 	cmpwi   r22,2
    147c:	40 82 00 24 	bne     14a0 <fn_800614A8+0x14a0>
    1480:	7f 83 e3 78 	mr      r3,r28
    1484:	7f 84 e3 78 	mr      r4,r28
    1488:	38 a0 00 20 	li      r5,32
    148c:	38 c0 00 05 	li      r6,5
    1490:	38 e0 00 00 	li      r7,0
    1494:	48 00 00 01 	bl      1494 <fn_800614A8+0x1494>
			1494: R_PPC_REL24	fn_802006D4
    1498:	38 60 00 01 	li      r3,1
    149c:	48 00 05 50 	b       19ec <fn_800614A8+0x19ec>
    14a0:	2c 16 00 35 	cmpwi   r22,53
    14a4:	40 82 00 0c 	bne     14b0 <fn_800614A8+0x14b0>
    14a8:	38 60 00 01 	li      r3,1
    14ac:	48 00 05 40 	b       19ec <fn_800614A8+0x19ec>
    14b0:	2c 16 00 67 	cmpwi   r22,103
    14b4:	40 82 05 38 	bne     19ec <fn_800614A8+0x19ec>
    14b8:	38 60 00 01 	li      r3,1
    14bc:	48 00 05 30 	b       19ec <fn_800614A8+0x19ec>
    14c0:	2c 17 00 08 	cmpwi   r23,8
    14c4:	40 82 03 40 	bne     1804 <fn_800614A8+0x1804>
    14c8:	2c 16 00 01 	cmpwi   r22,1
    14cc:	40 82 00 60 	bne     152c <fn_800614A8+0x152c>
    14d0:	7f c3 f3 78 	mr      r3,r30
    14d4:	48 00 00 01 	bl      14d4 <fn_800614A8+0x14d4>
			14d4: R_PPC_REL24	fn_80128EAC
    14d8:	7f c3 f3 78 	mr      r3,r30
    14dc:	48 00 00 01 	bl      14dc <fn_800614A8+0x14dc>
			14dc: R_PPC_REL24	fn_801290D0
    14e0:	7f e3 fb 78 	mr      r3,r31
    14e4:	38 80 00 00 	li      r4,0
    14e8:	48 00 00 01 	bl      14e8 <fn_800614A8+0x14e8>
			14e8: R_PPC_REL24	fn_80201350
    14ec:	88 7b 00 9f 	lbz     r3,159(r27)
    14f0:	48 00 00 01 	bl      14f0 <fn_800614A8+0x14f0>
			14f0: R_PPC_REL24	fn_800CA13C
    14f4:	54 64 08 3c 	slwi    r4,r3,1
    14f8:	7f e3 fb 78 	mr      r3,r31
    14fc:	38 a0 00 00 	li      r5,0
    1500:	48 00 00 01 	bl      1500 <fn_800614A8+0x1500>
			1500: R_PPC_REL24	fn_800E0708
    1504:	7f e3 fb 78 	mr      r3,r31
    1508:	38 80 00 01 	li      r4,1
    150c:	38 a0 00 00 	li      r5,0
    1510:	48 00 00 01 	bl      1510 <fn_800614A8+0x1510>
			1510: R_PPC_REL24	fn_800CC860
    1514:	7f 83 e3 78 	mr      r3,r28
    1518:	48 00 00 01 	bl      1518 <fn_800614A8+0x1518>
			1518: R_PPC_REL24	fn_800BE8D4
    151c:	7f e3 fb 78 	mr      r3,r31
    1520:	48 00 00 01 	bl      1520 <fn_800614A8+0x1520>
			1520: R_PPC_REL24	fn_800CA2C8
    1524:	38 60 00 01 	li      r3,1
    1528:	48 00 04 c4 	b       19ec <fn_800614A8+0x19ec>
    152c:	2c 16 00 03 	cmpwi   r22,3
    1530:	40 82 00 30 	bne     1560 <fn_800614A8+0x1560>
    1534:	7f c3 f3 78 	mr      r3,r30
    1538:	48 00 00 01 	bl      1538 <fn_800614A8+0x1538>
			1538: R_PPC_REL24	fn_80128EAC
    153c:	7f c3 f3 78 	mr      r3,r30
    1540:	48 00 00 01 	bl      1540 <fn_800614A8+0x1540>
			1540: R_PPC_REL24	fn_801290D0
    1544:	7f e3 fb 78 	mr      r3,r31
    1548:	7f c4 f3 78 	mr      r4,r30
    154c:	7f 85 e3 78 	mr      r5,r28
    1550:	7f a6 eb 78 	mr      r6,r29
    1554:	48 00 00 01 	bl      1554 <fn_800614A8+0x1554>
			1554: R_PPC_REL24	fn_8003E5DC
    1558:	38 60 00 01 	li      r3,1
    155c:	48 00 04 90 	b       19ec <fn_800614A8+0x19ec>
    1560:	2c 16 00 3d 	cmpwi   r22,61
    1564:	40 82 00 2c 	bne     1590 <fn_800614A8+0x1590>
    1568:	7f e3 fb 78 	mr      r3,r31
    156c:	7f a4 eb 78 	mr      r4,r29
    1570:	48 00 00 01 	bl      1570 <fn_800614A8+0x1570>
			1570: R_PPC_REL24	fn_800EA3A0
    1574:	7f 84 e3 78 	mr      r4,r28
    1578:	7f 85 e3 78 	mr      r5,r28
    157c:	38 60 00 39 	li      r3,57
    1580:	38 c0 00 00 	li      r6,0
    1584:	48 00 00 01 	bl      1584 <fn_800614A8+0x1584>
			1584: R_PPC_REL24	fn_8020123C
    1588:	38 60 00 01 	li      r3,1
    158c:	48 00 04 60 	b       19ec <fn_800614A8+0x19ec>
    1590:	2c 16 00 c1 	cmpwi   r22,193
    1594:	40 82 00 24 	bne     15b8 <fn_800614A8+0x15b8>
    1598:	28 19 00 00 	cmplwi  r25,0
    159c:	41 82 00 14 	beq     15b0 <fn_800614A8+0x15b0>
    15a0:	7f c3 f3 78 	mr      r3,r30
    15a4:	7f 64 db 78 	mr      r4,r27
    15a8:	48 00 00 01 	bl      15a8 <fn_800614A8+0x15a8>
			15a8: R_PPC_REL24	fn_800C9BA8
    15ac:	90 79 00 00 	stw     r3,0(r25)
    15b0:	38 60 00 01 	li      r3,1
    15b4:	48 00 04 38 	b       19ec <fn_800614A8+0x19ec>
    15b8:	2c 16 00 2f 	cmpwi   r22,47
    15bc:	40 82 00 24 	bne     15e0 <fn_800614A8+0x15e0>
    15c0:	7f e3 fb 78 	mr      r3,r31
    15c4:	38 80 00 1f 	li      r4,31
    15c8:	48 00 00 01 	bl      15c8 <fn_800614A8+0x15c8>
			15c8: R_PPC_REL24	fn_80201D2C
    15cc:	7f e3 fb 78 	mr      r3,r31
    15d0:	38 80 00 01 	li      r4,1
    15d4:	48 00 00 01 	bl      15d4 <fn_800614A8+0x15d4>
			15d4: R_PPC_REL24	fn_80201D14
    15d8:	38 60 00 01 	li      r3,1
    15dc:	48 00 04 10 	b       19ec <fn_800614A8+0x19ec>
    15e0:	2c 16 00 c2 	cmpwi   r22,194
    15e4:	40 82 00 20 	bne     1604 <fn_800614A8+0x1604>
    15e8:	7f e3 fb 78 	mr      r3,r31
    15ec:	7f c4 f3 78 	mr      r4,r30
    15f0:	7f 05 c3 78 	mr      r5,r24
    15f4:	7f 26 cb 78 	mr      r6,r25
    15f8:	48 00 00 01 	bl      15f8 <fn_800614A8+0x15f8>
			15f8: R_PPC_REL24	fn_800CA1BC
    15fc:	38 60 00 01 	li      r3,1
    1600:	48 00 03 ec 	b       19ec <fn_800614A8+0x19ec>
    1604:	2c 16 00 11 	cmpwi   r22,17
    1608:	40 82 00 78 	bne     1680 <fn_800614A8+0x1680>
    160c:	7f e3 fb 78 	mr      r3,r31
    1610:	48 00 00 01 	bl      1610 <fn_800614A8+0x1610>
			1610: R_PPC_REL24	fn_8003C04C
    1614:	2c 03 00 00 	cmpwi   r3,0
    1618:	41 82 00 60 	beq     1678 <fn_800614A8+0x1678>
    161c:	7f e3 fb 78 	mr      r3,r31
    1620:	7f a4 eb 78 	mr      r4,r29
    1624:	48 00 00 01 	bl      1624 <fn_800614A8+0x1624>
			1624: R_PPC_REL24	fn_800EA3A0
    1628:	7f e3 fb 78 	mr      r3,r31
    162c:	48 00 00 01 	bl      162c <fn_800614A8+0x162c>
			162c: R_PPC_REL24	fn_800CF598
    1630:	c0 20 00 00 	lfs     f1,0(0)
			1630: R_PPC_EMB_SDA21	lbl_8064E62C
    1634:	7f c3 f3 78 	mr      r3,r30
    1638:	c0 40 00 00 	lfs     f2,0(0)
			1638: R_PPC_EMB_SDA21	lbl_8064E5DC
    163c:	38 80 00 00 	li      r4,0
    1640:	38 a0 00 00 	li      r5,0
    1644:	38 c0 01 01 	li      r6,257
    1648:	48 00 00 01 	bl      1648 <fn_800614A8+0x1648>
			1648: R_PPC_REL24	fn_80120AD0
    164c:	7f c3 f3 78 	mr      r3,r30
    1650:	38 80 00 28 	li      r4,40
    1654:	38 a0 00 21 	li      r5,33
    1658:	38 c0 00 0a 	li      r6,10
    165c:	48 00 00 01 	bl      165c <fn_800614A8+0x165c>
			165c: R_PPC_REL24	fn_801294DC
    1660:	7f e3 fb 78 	mr      r3,r31
    1664:	38 80 00 15 	li      r4,21
    1668:	48 00 00 01 	bl      1668 <fn_800614A8+0x1668>
			1668: R_PPC_REL24	fn_80201D34
    166c:	7f e3 fb 78 	mr      r3,r31
    1670:	38 80 00 01 	li      r4,1
    1674:	48 00 00 01 	bl      1674 <fn_800614A8+0x1674>
			1674: R_PPC_REL24	fn_80201D1C
    1678:	38 60 00 01 	li      r3,1
    167c:	48 00 03 70 	b       19ec <fn_800614A8+0x19ec>
    1680:	2c 16 00 0b 	cmpwi   r22,11
    1684:	40 82 00 68 	bne     16ec <fn_800614A8+0x16ec>
    1688:	7f 03 c3 78 	mr      r3,r24
    168c:	48 00 00 01 	bl      168c <fn_800614A8+0x168c>
			168c: R_PPC_REL24	fn_80200C38
    1690:	7c 6f 1b 78 	mr      r15,r3
    1694:	48 00 00 01 	bl      1694 <fn_800614A8+0x1694>
			1694: R_PPC_REL24	fn_801A74C0
    1698:	54 60 06 b5 	rlwinm. r0,r3,0,26,26
    169c:	41 82 00 48 	beq     16e4 <fn_800614A8+0x16e4>
    16a0:	7d e3 7b 78 	mr      r3,r15
    16a4:	48 00 00 01 	bl      16a4 <fn_800614A8+0x16a4>
			16a4: R_PPC_REL24	fn_800654F8
    16a8:	7c 70 1b 78 	mr      r16,r3
    16ac:	7f 84 e3 78 	mr      r4,r28
    16b0:	7f 85 e3 78 	mr      r5,r28
    16b4:	38 60 00 2f 	li      r3,47
    16b8:	38 c0 00 00 	li      r6,0
    16bc:	48 00 00 01 	bl      16bc <fn_800614A8+0x16bc>
			16bc: R_PPC_REL24	fn_8020123C
    16c0:	c0 20 00 00 	lfs     f1,0(0)
			16c0: R_PPC_EMB_SDA21	lbl_8064E630
    16c4:	7f 84 e3 78 	mr      r4,r28
    16c8:	7f 85 e3 78 	mr      r5,r28
    16cc:	38 60 00 31 	li      r3,49
    16d0:	38 c0 00 00 	li      r6,0
    16d4:	48 00 00 01 	bl      16d4 <fn_800614A8+0x16d4>
			16d4: R_PPC_REL24	fn_8020104C
    16d8:	28 19 00 00 	cmplwi  r25,0
    16dc:	41 82 00 08 	beq     16e4 <fn_800614A8+0x16e4>
    16e0:	92 19 00 00 	stw     r16,0(r25)
    16e4:	38 60 00 01 	li      r3,1
    16e8:	48 00 03 04 	b       19ec <fn_800614A8+0x19ec>
    16ec:	2c 16 00 35 	cmpwi   r22,53
    16f0:	40 82 00 28 	bne     1718 <fn_800614A8+0x1718>
    16f4:	7f 03 c3 78 	mr      r3,r24
    16f8:	48 00 00 01 	bl      16f8 <fn_800614A8+0x16f8>
			16f8: R_PPC_REL24	fn_80200C38
    16fc:	c0 20 00 00 	lfs     f1,0(0)
			16fc: R_PPC_EMB_SDA21	lbl_8064E614
    1700:	7c 64 1b 78 	mr      r4,r3
    1704:	c0 40 00 00 	lfs     f2,0(0)
			1704: R_PPC_EMB_SDA21	lbl_8064E618
    1708:	7f c3 f3 78 	mr      r3,r30
    170c:	48 00 00 01 	bl      170c <fn_800614A8+0x170c>
			170c: R_PPC_REL24	fn_80066888
    1710:	38 60 00 01 	li      r3,1
    1714:	48 00 02 d8 	b       19ec <fn_800614A8+0x19ec>
    1718:	2c 16 00 4e 	cmpwi   r22,78
    171c:	40 82 00 1c 	bne     1738 <fn_800614A8+0x1738>
    1720:	28 19 00 00 	cmplwi  r25,0
    1724:	41 82 00 0c 	beq     1730 <fn_800614A8+0x1730>
    1728:	38 00 00 00 	li      r0,0
    172c:	90 19 00 00 	stw     r0,0(r25)
    1730:	38 60 00 01 	li      r3,1
    1734:	48 00 02 b8 	b       19ec <fn_800614A8+0x19ec>
    1738:	2c 16 00 33 	cmpwi   r22,51
    173c:	40 82 00 20 	bne     175c <fn_800614A8+0x175c>
    1740:	7f 84 e3 78 	mr      r4,r28
    1744:	7f 85 e3 78 	mr      r5,r28
    1748:	38 60 00 39 	li      r3,57
    174c:	38 c0 00 00 	li      r6,0
    1750:	48 00 00 01 	bl      1750 <fn_800614A8+0x1750>
			1750: R_PPC_REL24	fn_8020123C
    1754:	38 60 00 01 	li      r3,1
    1758:	48 00 02 94 	b       19ec <fn_800614A8+0x19ec>
    175c:	2c 16 00 02 	cmpwi   r22,2
    1760:	40 82 00 24 	bne     1784 <fn_800614A8+0x1784>
    1764:	7f 83 e3 78 	mr      r3,r28
    1768:	7f 84 e3 78 	mr      r4,r28
    176c:	38 a0 00 08 	li      r5,8
    1770:	38 c0 00 11 	li      r6,17
    1774:	38 e0 00 00 	li      r7,0
    1778:	48 00 00 01 	bl      1778 <fn_800614A8+0x1778>
			1778: R_PPC_REL24	fn_802006D4
    177c:	38 60 00 01 	li      r3,1
    1780:	48 00 02 6c 	b       19ec <fn_800614A8+0x19ec>
    1784:	2c 16 00 3b 	cmpwi   r22,59
    1788:	40 82 00 0c 	bne     1794 <fn_800614A8+0x1794>
    178c:	38 60 00 01 	li      r3,1
    1790:	48 00 02 5c 	b       19ec <fn_800614A8+0x19ec>
    1794:	2c 16 00 08 	cmpwi   r22,8
    1798:	40 82 00 0c 	bne     17a4 <fn_800614A8+0x17a4>
    179c:	38 60 00 01 	li      r3,1
    17a0:	48 00 02 4c 	b       19ec <fn_800614A8+0x19ec>
    17a4:	2c 16 00 35 	cmpwi   r22,53
    17a8:	40 82 00 0c 	bne     17b4 <fn_800614A8+0x17b4>
    17ac:	38 60 00 01 	li      r3,1
    17b0:	48 00 02 3c 	b       19ec <fn_800614A8+0x19ec>
    17b4:	2c 16 00 32 	cmpwi   r22,50
    17b8:	40 82 00 0c 	bne     17c4 <fn_800614A8+0x17c4>
    17bc:	38 60 00 01 	li      r3,1
    17c0:	48 00 02 2c 	b       19ec <fn_800614A8+0x19ec>
    17c4:	2c 16 00 0b 	cmpwi   r22,11
    17c8:	40 82 00 0c 	bne     17d4 <fn_800614A8+0x17d4>
    17cc:	38 60 00 01 	li      r3,1
    17d0:	48 00 02 1c 	b       19ec <fn_800614A8+0x19ec>
    17d4:	2c 16 00 27 	cmpwi   r22,39
    17d8:	40 82 00 0c 	bne     17e4 <fn_800614A8+0x17e4>
    17dc:	38 60 00 01 	li      r3,1
    17e0:	48 00 02 0c 	b       19ec <fn_800614A8+0x19ec>
    17e4:	2c 16 00 67 	cmpwi   r22,103
    17e8:	40 82 00 0c 	bne     17f4 <fn_800614A8+0x17f4>
    17ec:	38 60 00 01 	li      r3,1
    17f0:	48 00 01 fc 	b       19ec <fn_800614A8+0x19ec>
    17f4:	2c 16 00 ea 	cmpwi   r22,234
    17f8:	40 82 01 f4 	bne     19ec <fn_800614A8+0x19ec>
    17fc:	38 60 00 01 	li      r3,1
    1800:	48 00 01 ec 	b       19ec <fn_800614A8+0x19ec>
    1804:	2c 17 00 1f 	cmpwi   r23,31
    1808:	40 82 01 e0 	bne     19e8 <fn_800614A8+0x19e8>
    180c:	2c 16 00 01 	cmpwi   r22,1
    1810:	40 82 00 68 	bne     1878 <fn_800614A8+0x1878>
    1814:	7f c3 f3 78 	mr      r3,r30
    1818:	48 00 00 01 	bl      1818 <fn_800614A8+0x1818>
			1818: R_PPC_REL24	fn_80128EAC
    181c:	7f c3 f3 78 	mr      r3,r30
    1820:	48 00 00 01 	bl      1820 <fn_800614A8+0x1820>
			1820: R_PPC_REL24	fn_801290D0
    1824:	7f 83 e3 78 	mr      r3,r28
    1828:	48 00 00 01 	bl      1828 <fn_800614A8+0x1828>
			1828: R_PPC_REL24	fn_800BE8D4
    182c:	7f e3 fb 78 	mr      r3,r31
    1830:	38 80 00 02 	li      r4,2
    1834:	38 a0 00 03 	li      r5,3
    1838:	48 00 00 01 	bl      1838 <fn_800614A8+0x1838>
			1838: R_PPC_REL24	fn_800CC860
    183c:	7f c3 f3 78 	mr      r3,r30
    1840:	38 80 00 33 	li      r4,51
    1844:	48 00 00 01 	bl      1844 <fn_800614A8+0x1844>
			1844: R_PPC_REL24	fn_801A977C
    1848:	7f e3 fb 78 	mr      r3,r31
    184c:	48 00 00 01 	bl      184c <fn_800614A8+0x184c>
			184c: R_PPC_REL24	fn_800CA2C8
    1850:	7f e3 fb 78 	mr      r3,r31
    1854:	48 00 00 01 	bl      1854 <fn_800614A8+0x1854>
			1854: R_PPC_REL24	fn_80204FDC
    1858:	c0 20 00 00 	lfs     f1,0(0)
			1858: R_PPC_EMB_SDA21	lbl_8064E634
    185c:	7f 84 e3 78 	mr      r4,r28
    1860:	7f 85 e3 78 	mr      r5,r28
    1864:	38 60 00 11 	li      r3,17
    1868:	38 c0 00 00 	li      r6,0
    186c:	48 00 00 01 	bl      186c <fn_800614A8+0x186c>
			186c: R_PPC_REL24	fn_8020104C
    1870:	38 60 00 01 	li      r3,1
    1874:	48 00 01 78 	b       19ec <fn_800614A8+0x19ec>
    1878:	2c 16 00 30 	cmpwi   r22,48
    187c:	40 82 00 24 	bne     18a0 <fn_800614A8+0x18a0>
    1880:	7f 03 c3 78 	mr      r3,r24
    1884:	48 00 00 01 	bl      1884 <fn_800614A8+0x1884>
			1884: R_PPC_REL24	fn_80200C38
    1888:	48 00 00 01 	bl      1888 <fn_800614A8+0x1888>
			1888: R_PPC_REL24	fn_800654F8
    188c:	28 19 00 00 	cmplwi  r25,0
    1890:	41 82 00 08 	beq     1898 <fn_800614A8+0x1898>
    1894:	90 79 00 00 	stw     r3,0(r25)
    1898:	38 60 00 01 	li      r3,1
    189c:	48 00 01 50 	b       19ec <fn_800614A8+0x19ec>
    18a0:	2c 16 00 31 	cmpwi   r22,49
    18a4:	40 82 00 1c 	bne     18c0 <fn_800614A8+0x18c0>
    18a8:	7f e3 fb 78 	mr      r3,r31
    18ac:	7f c4 f3 78 	mr      r4,r30
    18b0:	7f 85 e3 78 	mr      r5,r28
    18b4:	48 00 00 01 	bl      18b4 <fn_800614A8+0x18b4>
			18b4: R_PPC_REL24	fn_8003C114
    18b8:	38 60 00 01 	li      r3,1
    18bc:	48 00 01 30 	b       19ec <fn_800614A8+0x19ec>
    18c0:	2c 16 00 3d 	cmpwi   r22,61
    18c4:	40 82 00 2c 	bne     18f0 <fn_800614A8+0x18f0>
    18c8:	7f e3 fb 78 	mr      r3,r31
    18cc:	7f a4 eb 78 	mr      r4,r29
    18d0:	48 00 00 01 	bl      18d0 <fn_800614A8+0x18d0>
			18d0: R_PPC_REL24	fn_800EA3A0
    18d4:	7f 84 e3 78 	mr      r4,r28
    18d8:	7f 85 e3 78 	mr      r5,r28
    18dc:	38 60 00 39 	li      r3,57
    18e0:	38 c0 00 00 	li      r6,0
    18e4:	48 00 00 01 	bl      18e4 <fn_800614A8+0x18e4>
			18e4: R_PPC_REL24	fn_8020123C
    18e8:	38 60 00 01 	li      r3,1
    18ec:	48 00 01 00 	b       19ec <fn_800614A8+0x19ec>
    18f0:	2c 16 00 11 	cmpwi   r22,17
    18f4:	40 82 00 54 	bne     1948 <fn_800614A8+0x1948>
    18f8:	7f e3 fb 78 	mr      r3,r31
    18fc:	7f a4 eb 78 	mr      r4,r29
    1900:	48 00 00 01 	bl      1900 <fn_800614A8+0x1900>
			1900: R_PPC_REL24	fn_800EA3A0
    1904:	7f e3 fb 78 	mr      r3,r31
    1908:	48 00 00 01 	bl      1908 <fn_800614A8+0x1908>
			1908: R_PPC_REL24	fn_800CF598
    190c:	c0 20 00 00 	lfs     f1,0(0)
			190c: R_PPC_EMB_SDA21	lbl_8064E62C
    1910:	7f c3 f3 78 	mr      r3,r30
    1914:	c0 40 00 00 	lfs     f2,0(0)
			1914: R_PPC_EMB_SDA21	lbl_8064E5DC
    1918:	38 80 00 00 	li      r4,0
    191c:	38 a0 00 00 	li      r5,0
    1920:	38 c0 01 01 	li      r6,257
    1924:	48 00 00 01 	bl      1924 <fn_800614A8+0x1924>
			1924: R_PPC_REL24	fn_80120AD0
    1928:	7f e3 fb 78 	mr      r3,r31
    192c:	38 80 00 15 	li      r4,21
    1930:	48 00 00 01 	bl      1930 <fn_800614A8+0x1930>
			1930: R_PPC_REL24	fn_80201D34
    1934:	7f e3 fb 78 	mr      r3,r31
    1938:	38 80 00 01 	li      r4,1
    193c:	48 00 00 01 	bl      193c <fn_800614A8+0x193c>
			193c: R_PPC_REL24	fn_80201D1C
    1940:	38 60 00 01 	li      r3,1
    1944:	48 00 00 a8 	b       19ec <fn_800614A8+0x19ec>
    1948:	2c 16 00 4e 	cmpwi   r22,78
    194c:	40 82 00 1c 	bne     1968 <fn_800614A8+0x1968>
    1950:	28 19 00 00 	cmplwi  r25,0
    1954:	41 82 00 0c 	beq     1960 <fn_800614A8+0x1960>
    1958:	38 00 00 00 	li      r0,0
    195c:	90 19 00 00 	stw     r0,0(r25)
    1960:	38 60 00 01 	li      r3,1
    1964:	48 00 00 88 	b       19ec <fn_800614A8+0x19ec>
    1968:	2c 16 00 3b 	cmpwi   r22,59
    196c:	40 82 00 0c 	bne     1978 <fn_800614A8+0x1978>
    1970:	38 60 00 01 	li      r3,1
    1974:	48 00 00 78 	b       19ec <fn_800614A8+0x19ec>
    1978:	2c 16 00 08 	cmpwi   r22,8
    197c:	40 82 00 0c 	bne     1988 <fn_800614A8+0x1988>
    1980:	38 60 00 01 	li      r3,1
    1984:	48 00 00 68 	b       19ec <fn_800614A8+0x19ec>
    1988:	2c 16 00 35 	cmpwi   r22,53
    198c:	40 82 00 0c 	bne     1998 <fn_800614A8+0x1998>
    1990:	38 60 00 01 	li      r3,1
    1994:	48 00 00 58 	b       19ec <fn_800614A8+0x19ec>
    1998:	2c 16 00 32 	cmpwi   r22,50
    199c:	40 82 00 0c 	bne     19a8 <fn_800614A8+0x19a8>
    19a0:	38 60 00 01 	li      r3,1
    19a4:	48 00 00 48 	b       19ec <fn_800614A8+0x19ec>
    19a8:	2c 16 00 0b 	cmpwi   r22,11
    19ac:	40 82 00 0c 	bne     19b8 <fn_800614A8+0x19b8>
    19b0:	38 60 00 01 	li      r3,1
    19b4:	48 00 00 38 	b       19ec <fn_800614A8+0x19ec>
    19b8:	2c 16 00 27 	cmpwi   r22,39
    19bc:	40 82 00 0c 	bne     19c8 <fn_800614A8+0x19c8>
    19c0:	38 60 00 01 	li      r3,1
    19c4:	48 00 00 28 	b       19ec <fn_800614A8+0x19ec>
    19c8:	2c 16 00 67 	cmpwi   r22,103
    19cc:	40 82 00 0c 	bne     19d8 <fn_800614A8+0x19d8>
    19d0:	38 60 00 01 	li      r3,1
    19d4:	48 00 00 18 	b       19ec <fn_800614A8+0x19ec>
    19d8:	2c 16 00 ea 	cmpwi   r22,234
    19dc:	40 82 00 10 	bne     19ec <fn_800614A8+0x19ec>
    19e0:	38 60 00 01 	li      r3,1
    19e4:	48 00 00 08 	b       19ec <fn_800614A8+0x19ec>
    19e8:	38 60 00 00 	li      r3,0
    19ec:	b9 e1 00 cc 	lmw     r15,204(r1)
    19f0:	80 01 01 14 	lwz     r0,276(r1)
    19f4:	7c 08 03 a6 	mtlr    r0
    19f8:	38 21 01 10 	addi    r1,r1,272
    19fc:	4e 80 00 20 	blr

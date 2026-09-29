
build/GEDE01/src/game/game_fn_800614A8.o:     file format elf32-powerpc


Disassembly of section .text:

00000000 <fn_800614A8>:
       0:	94 21 fe d0 	stwu    r1,-304(r1)
       4:	7c 08 02 a6 	mflr    r0
       8:	3c e0 00 00 	lis     r7,0
			a: R_PPC_ADDR16_HA	lbl_80243C30
       c:	90 01 01 34 	stw     r0,308(r1)
      10:	bd e1 00 ec 	stmw    r15,236(r1)
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
      44:	7c 1d 03 78 	mr      r29,r0
      48:	48 00 00 01 	bl      48 <fn_800614A8+0x48>
			48: R_PPC_REL24	fn_80201B8C
      4c:	7c 60 1b 78 	mr      r0,r3
      50:	7f e3 fb 78 	mr      r3,r31
      54:	7c 1c 03 78 	mr      r28,r0
      58:	83 7c 00 8c 	lwz     r27,140(r28)
      5c:	83 5c 00 08 	lwz     r26,8(r28)
      60:	48 00 00 01 	bl      60 <fn_800614A8+0x60>
			60: R_PPC_REL24	fn_80201B94
      64:	7c 60 1b 78 	mr      r0,r3
      68:	7f e3 fb 78 	mr      r3,r31
      6c:	7c 14 03 78 	mr      r20,r0
      70:	48 00 00 01 	bl      70 <fn_800614A8+0x70>
			70: R_PPC_REL24	fn_80201B54
      74:	7c 7e 1b 78 	mr      r30,r3
      78:	7f a4 eb 78 	mr      r4,r29
      7c:	38 61 00 8c 	addi    r3,r1,140
      80:	48 00 00 01 	bl      80 <fn_800614A8+0x80>
			80: R_PPC_REL24	fn_8011F114
      84:	80 9c 00 8c 	lwz     r4,140(r28)
      88:	7f e3 fb 78 	mr      r3,r31
      8c:	80 c0 00 00 	lwz     r6,0(0)
			8c: R_PPC_EMB_SDA21	lbl_8064D5A8
      90:	a8 bc 00 9c 	lha     r5,156(r28)
      94:	88 04 01 61 	lbz     r0,353(r4)
      98:	7e 46 2a 14 	add     r18,r6,r5
      9c:	7c 10 07 74 	extsb   r16,r0
      a0:	48 00 00 01 	bl      a0 <fn_800614A8+0xa0>
			a0: R_PPC_REL24	fn_80201EB8
      a4:	2c 16 00 03 	cmpwi   r22,3
      a8:	7c 73 1b 78 	mr      r19,r3
      ac:	40 82 01 14 	bne     1c0 <fn_800614A8+0x1c0>
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
     128:	80 7c 00 8c 	lwz     r3,140(r28)
     12c:	80 03 00 00 	lwz     r0,0(r3)
     130:	54 00 02 11 	rlwinm. r0,r0,0,8,8
     134:	40 82 00 0c 	bne     140 <fn_800614A8+0x140>
     138:	2c 11 00 00 	cmpwi   r17,0
     13c:	41 82 00 18 	beq     154 <fn_800614A8+0x154>
     140:	a8 7b 01 4e 	lha     r3,334(r27)
     144:	2c 03 00 01 	cmpwi   r3,1
     148:	41 80 00 08 	blt     150 <fn_800614A8+0x150>
     14c:	38 63 ff ff 	addi    r3,r3,-1
     150:	b0 7b 01 4e 	sth     r3,334(r27)
     154:	a8 ba 00 86 	lha     r5,134(r26)
     158:	7f e3 fb 78 	mr      r3,r31
     15c:	6c a4 80 00 	xoris   r4,r5,32768
     160:	20 05 00 01 	subfic  r0,r5,1
     164:	7c 80 20 14 	addc    r4,r0,r4
     168:	38 05 ff ff 	addi    r0,r5,-1
     16c:	7c 84 21 10 	subfe   r4,r4,r4
     170:	7c 00 20 78 	andc    r0,r0,r4
     174:	b0 1a 00 86 	sth     r0,134(r26)
     178:	48 00 00 01 	bl      178 <fn_800614A8+0x178>
			178: R_PPC_REL24	fn_800C9C60
     17c:	80 00 00 00 	lwz     r0,0(0)
			17c: R_PPC_EMB_SDA21	lbl_8064D5A8
     180:	54 00 06 3f 	clrlwi. r0,r0,24
     184:	40 82 00 0c 	bne     190 <fn_800614A8+0x190>
     188:	7f e3 fb 78 	mr      r3,r31
     18c:	48 00 00 01 	bl      18c <fn_800614A8+0x18c>
			18c: R_PPC_REL24	fn_800C9D68
     190:	7f a3 eb 78 	mr      r3,r29
     194:	48 00 00 01 	bl      194 <fn_800614A8+0x194>
			194: R_PPC_REL24	fn_8013017C
     198:	54 60 06 73 	rlwinm. r0,r3,0,25,25
     19c:	41 82 00 24 	beq     1c0 <fn_800614A8+0x1c0>
     1a0:	7f a3 eb 78 	mr      r3,r29
     1a4:	48 00 00 01 	bl      1a4 <fn_800614A8+0x1a4>
			1a4: R_PPC_REL24	fn_801305D4
     1a8:	2c 03 00 00 	cmpwi   r3,0
     1ac:	40 82 00 14 	bne     1c0 <fn_800614A8+0x1c0>
     1b0:	7f a3 eb 78 	mr      r3,r29
     1b4:	38 80 00 40 	li      r4,64
     1b8:	38 a0 00 00 	li      r5,0
     1bc:	48 00 00 01 	bl      1bc <fn_800614A8+0x1bc>
			1bc: R_PPC_REL24	fn_801301B0
     1c0:	2c 17 00 00 	cmpwi   r23,0
     1c4:	40 82 07 10 	bne     8d4 <fn_800614A8+0x8d4>
     1c8:	2c 16 00 01 	cmpwi   r22,1
     1cc:	40 82 00 48 	bne     214 <fn_800614A8+0x214>
     1d0:	48 00 00 01 	bl      1d0 <fn_800614A8+0x1d0>
			1d0: R_PPC_REL24	fn_800FBFB0
     1d4:	54 60 e8 04 	slwi    r0,r3,29
     1d8:	54 65 0f fe 	srwi    r5,r3,31
     1dc:	7c 65 00 50 	subf    r3,r5,r0
     1e0:	38 00 00 1e 	li      r0,30
     1e4:	54 64 18 3e 	rotlwi  r4,r3,3
     1e8:	7f e3 fb 78 	mr      r3,r31
     1ec:	7c a4 2a 14 	add     r5,r4,r5
     1f0:	38 80 00 01 	li      r4,1
     1f4:	90 ba 00 78 	stw     r5,120(r26)
     1f8:	b0 1a 00 86 	sth     r0,134(r26)
     1fc:	48 00 00 01 	bl      1fc <fn_800614A8+0x1fc>
			1fc: R_PPC_REL24	fn_80201D2C
     200:	7f e3 fb 78 	mr      r3,r31
     204:	38 80 00 01 	li      r4,1
     208:	48 00 00 01 	bl      208 <fn_800614A8+0x208>
			208: R_PPC_REL24	fn_80201D14
     20c:	38 60 00 01 	li      r3,1
     210:	48 00 17 dc 	b       19ec <fn_800614A8+0x19ec>
     214:	2c 16 00 f1 	cmpwi   r22,241
     218:	40 82 00 24 	bne     23c <fn_800614A8+0x23c>
     21c:	7e 63 9b 78 	mr      r3,r19
     220:	7f e4 fb 78 	mr      r4,r31
     224:	7f a5 eb 78 	mr      r5,r29
     228:	7f 86 e3 78 	mr      r6,r28
     22c:	7f 07 c3 78 	mr      r7,r24
     230:	48 00 00 01 	bl      230 <fn_800614A8+0x230>
			230: R_PPC_REL24	fn_8005EC6C
     234:	38 60 00 01 	li      r3,1
     238:	48 00 17 b4 	b       19ec <fn_800614A8+0x19ec>
     23c:	2c 16 00 f5 	cmpwi   r22,245
     240:	40 82 00 24 	bne     264 <fn_800614A8+0x264>
     244:	7e 63 9b 78 	mr      r3,r19
     248:	7f e4 fb 78 	mr      r4,r31
     24c:	7f a5 eb 78 	mr      r5,r29
     250:	7f 86 e3 78 	mr      r6,r28
     254:	7f 07 c3 78 	mr      r7,r24
     258:	48 00 00 01 	bl      258 <fn_800614A8+0x258>
			258: R_PPC_REL24	fn_8005EC6C
     25c:	38 60 00 01 	li      r3,1
     260:	48 00 17 8c 	b       19ec <fn_800614A8+0x19ec>
     264:	2c 16 00 df 	cmpwi   r22,223
     268:	40 82 00 20 	bne     288 <fn_800614A8+0x288>
     26c:	7e 63 9b 78 	mr      r3,r19
     270:	7f e4 fb 78 	mr      r4,r31
     274:	7f 05 c3 78 	mr      r5,r24
     278:	38 c1 00 8c 	addi    r6,r1,140
     27c:	48 00 00 01 	bl      27c <fn_800614A8+0x27c>
			27c: R_PPC_REL24	fn_8005EA38
     280:	38 60 00 01 	li      r3,1
     284:	48 00 17 68 	b       19ec <fn_800614A8+0x19ec>
     288:	2c 16 00 08 	cmpwi   r22,8
     28c:	40 82 00 38 	bne     2c4 <fn_800614A8+0x2c4>
     290:	80 00 00 00 	lwz     r0,0(0)
			290: R_PPC_EMB_SDA21	lbl_8064D18C
     294:	7c 13 00 00 	cmpw    r19,r0
     298:	41 82 00 14 	beq     2ac <fn_800614A8+0x2ac>
     29c:	7f e4 fb 78 	mr      r4,r31
     2a0:	38 60 00 02 	li      r3,2
     2a4:	48 00 00 01 	bl      2a4 <fn_800614A8+0x2a4>
			2a4: R_PPC_REL24	fn_801E8328
     2a8:	48 00 00 14 	b       2bc <fn_800614A8+0x2bc>
     2ac:	7f e3 fb 78 	mr      r3,r31
     2b0:	7f 04 c3 78 	mr      r4,r24
     2b4:	38 a0 03 c0 	li      r5,960
     2b8:	48 00 00 01 	bl      2b8 <fn_800614A8+0x2b8>
			2b8: R_PPC_REL24	fn_800CD094
     2bc:	38 60 00 01 	li      r3,1
     2c0:	48 00 17 2c 	b       19ec <fn_800614A8+0x19ec>
     2c4:	2c 16 00 3d 	cmpwi   r22,61
     2c8:	40 82 00 24 	bne     2ec <fn_800614A8+0x2ec>
     2cc:	7f e3 fb 78 	mr      r3,r31
     2d0:	7f 64 db 78 	mr      r4,r27
     2d4:	48 00 00 01 	bl      2d4 <fn_800614A8+0x2d4>
			2d4: R_PPC_REL24	fn_800EA3A0
     2d8:	7f e3 fb 78 	mr      r3,r31
     2dc:	7f 64 db 78 	mr      r4,r27
     2e0:	48 00 00 01 	bl      2e0 <fn_800614A8+0x2e0>
			2e0: R_PPC_REL24	fn_800BD2DC
     2e4:	38 60 00 01 	li      r3,1
     2e8:	48 00 17 04 	b       19ec <fn_800614A8+0x19ec>
     2ec:	2c 16 00 3e 	cmpwi   r22,62
     2f0:	40 82 00 a8 	bne     398 <fn_800614A8+0x398>
     2f4:	7f e3 fb 78 	mr      r3,r31
     2f8:	48 00 00 01 	bl      2f8 <fn_800614A8+0x2f8>
			2f8: R_PPC_REL24	fn_80036D5C
     2fc:	54 60 01 09 	rlwinm. r0,r3,0,4,4
     300:	7c 64 1b 78 	mr      r4,r3
     304:	41 82 00 68 	beq     36c <fn_800614A8+0x36c>
     308:	7f e3 fb 78 	mr      r3,r31
     30c:	54 84 01 46 	rlwinm  r4,r4,0,5,3
     310:	48 00 00 01 	bl      310 <fn_800614A8+0x310>
			310: R_PPC_REL24	fn_80036DA4
     314:	7f a3 eb 78 	mr      r3,r29
     318:	48 00 00 01 	bl      318 <fn_800614A8+0x318>
			318: R_PPC_REL24	fn_801261F4
     31c:	80 00 00 00 	lwz     r0,0(0)
			31c: R_PPC_EMB_SDA21	lbl_8064E610
     320:	38 e1 00 18 	addi    r7,r1,24
     324:	81 20 00 00 	lwz     r9,0(0)
			324: R_PPC_EMB_SDA21	lbl_80651954
     328:	38 c1 00 20 	addi    r6,r1,32
     32c:	81 40 00 00 	lwz     r10,0(0)
			32c: R_PPC_EMB_SDA21	lbl_8064E60C
     330:	38 a1 00 28 	addi    r5,r1,40
     334:	90 01 00 14 	stw     r0,20(r1)
     338:	7f a3 eb 78 	mr      r3,r29
     33c:	38 80 00 0f 	li      r4,15
     340:	39 00 00 04 	li      r8,4
     344:	90 01 00 18 	stw     r0,24(r1)
     348:	91 21 00 1c 	stw     r9,28(r1)
     34c:	91 21 00 20 	stw     r9,32(r1)
     350:	91 41 00 24 	stw     r10,36(r1)
     354:	91 41 00 28 	stw     r10,40(r1)
     358:	48 00 00 01 	bl      358 <fn_800614A8+0x358>
			358: R_PPC_REL24	fn_8012C62C
     35c:	7f a3 eb 78 	mr      r3,r29
     360:	38 80 00 00 	li      r4,0
     364:	38 a0 01 00 	li      r5,256
     368:	48 00 00 01 	bl      368 <fn_800614A8+0x368>
			368: R_PPC_REL24	fn_8011FA8C
     36c:	7f e3 fb 78 	mr      r3,r31
     370:	7f 64 db 78 	mr      r4,r27
     374:	48 00 00 01 	bl      374 <fn_800614A8+0x374>
			374: R_PPC_REL24	fn_800BD194
     378:	7f e3 fb 78 	mr      r3,r31
     37c:	48 00 00 01 	bl      37c <fn_800614A8+0x37c>
			37c: R_PPC_REL24	fn_800C9E50
     380:	38 00 00 00 	li      r0,0
     384:	7f c3 f3 78 	mr      r3,r30
     388:	98 1a 00 88 	stb     r0,136(r26)
     38c:	48 00 00 01 	bl      38c <fn_800614A8+0x38c>
			38c: R_PPC_REL24	fn_801D14CC
     390:	38 60 00 01 	li      r3,1
     394:	48 00 16 58 	b       19ec <fn_800614A8+0x19ec>
     398:	2c 16 00 c9 	cmpwi   r22,201
     39c:	40 82 00 5c 	bne     3f8 <fn_800614A8+0x3f8>
     3a0:	48 00 00 01 	bl      3a0 <fn_800614A8+0x3a0>
			3a0: R_PPC_REL24	fn_8011FF38
     3a4:	2c 03 00 00 	cmpwi   r3,0
     3a8:	41 82 00 48 	beq     3f0 <fn_800614A8+0x3f0>
     3ac:	7f a3 eb 78 	mr      r3,r29
     3b0:	38 80 00 00 	li      r4,0
     3b4:	3c a0 20 00 	lis     r5,8192
     3b8:	48 00 00 01 	bl      3b8 <fn_800614A8+0x3b8>
			3b8: R_PPC_REL24	fn_8011FA8C
     3bc:	38 00 00 00 	li      r0,0
     3c0:	38 c1 00 8c 	addi    r6,r1,140
     3c4:	90 01 00 08 	stw     r0,8(r1)
     3c8:	38 60 01 f1 	li      r3,497
     3cc:	38 80 00 64 	li      r4,100
     3d0:	38 a0 00 00 	li      r5,0
     3d4:	80 00 00 00 	lwz     r0,0(0)
			3d4: R_PPC_EMB_SDA21	lbl_8064D18C
     3d8:	38 e0 00 02 	li      r7,2
     3dc:	c0 20 00 00 	lfs     f1,0(0)
			3dc: R_PPC_EMB_SDA21	lbl_8064E5BC
     3e0:	39 00 00 02 	li      r8,2
     3e4:	54 0a 04 3e 	clrlwi  r10,r0,16
     3e8:	39 20 00 00 	li      r9,0
     3ec:	48 00 00 01 	bl      3ec <fn_800614A8+0x3ec>
			3ec: R_PPC_REL24	fn_801AAE68
     3f0:	38 60 00 01 	li      r3,1
     3f4:	48 00 15 f8 	b       19ec <fn_800614A8+0x19ec>
     3f8:	2c 16 00 67 	cmpwi   r22,103
     3fc:	40 82 00 1c 	bne     418 <fn_800614A8+0x418>
     400:	7f e3 fb 78 	mr      r3,r31
     404:	7f a4 eb 78 	mr      r4,r29
     408:	7f 05 c3 78 	mr      r5,r24
     40c:	48 00 00 01 	bl      40c <fn_800614A8+0x40c>
			40c: R_PPC_REL24	fn_800C9B08
     410:	38 60 00 01 	li      r3,1
     414:	48 00 15 d8 	b       19ec <fn_800614A8+0x19ec>
     418:	2c 16 00 ed 	cmpwi   r22,237
     41c:	40 82 00 54 	bne     470 <fn_800614A8+0x470>
     420:	7f 03 c3 78 	mr      r3,r24
     424:	48 00 00 01 	bl      424 <fn_800614A8+0x424>
			424: R_PPC_REL24	fn_80200C38
     428:	7c 60 1b 78 	mr      r0,r3
     42c:	7f 03 c3 78 	mr      r3,r24
     430:	7c 10 03 78 	mr      r16,r0
     434:	48 00 00 01 	bl      434 <fn_800614A8+0x434>
			434: R_PPC_REL24	fn_80200C28
     438:	7c 60 1b 78 	mr      r0,r3
     43c:	7f 03 c3 78 	mr      r3,r24
     440:	7c 0f 03 78 	mr      r15,r0
     444:	48 00 00 01 	bl      444 <fn_800614A8+0x444>
			444: R_PPC_REL24	fn_80200C20
     448:	7c 64 1b 78 	mr      r4,r3
     44c:	7d e5 7b 78 	mr      r5,r15
     450:	7e 06 83 78 	mr      r6,r16
     454:	38 60 00 0b 	li      r3,11
     458:	48 00 00 01 	bl      458 <fn_800614A8+0x458>
			458: R_PPC_REL24	fn_8020123C
     45c:	7f 03 c3 78 	mr      r3,r24
     460:	48 00 00 01 	bl      460 <fn_800614A8+0x460>
			460: R_PPC_REL24	fn_80200C38
     464:	48 00 00 01 	bl      464 <fn_800614A8+0x464>
			464: R_PPC_REL24	fn_801A7228
     468:	38 60 00 01 	li      r3,1
     46c:	48 00 15 80 	b       19ec <fn_800614A8+0x19ec>
     470:	2c 16 00 3a 	cmpwi   r22,58
     474:	40 82 00 54 	bne     4c8 <fn_800614A8+0x4c8>
     478:	7f 03 c3 78 	mr      r3,r24
     47c:	48 00 00 01 	bl      47c <fn_800614A8+0x47c>
			47c: R_PPC_REL24	fn_80200C38
     480:	7c 60 1b 78 	mr      r0,r3
     484:	7f 03 c3 78 	mr      r3,r24
     488:	7c 10 03 78 	mr      r16,r0
     48c:	48 00 00 01 	bl      48c <fn_800614A8+0x48c>
			48c: R_PPC_REL24	fn_80200C28
     490:	7c 60 1b 78 	mr      r0,r3
     494:	7f 03 c3 78 	mr      r3,r24
     498:	7c 0f 03 78 	mr      r15,r0
     49c:	48 00 00 01 	bl      49c <fn_800614A8+0x49c>
			49c: R_PPC_REL24	fn_80200C20
     4a0:	7c 64 1b 78 	mr      r4,r3
     4a4:	7d e5 7b 78 	mr      r5,r15
     4a8:	7e 06 83 78 	mr      r6,r16
     4ac:	38 60 00 27 	li      r3,39
     4b0:	48 00 00 01 	bl      4b0 <fn_800614A8+0x4b0>
			4b0: R_PPC_REL24	fn_8020123C
     4b4:	7f 03 c3 78 	mr      r3,r24
     4b8:	48 00 00 01 	bl      4b8 <fn_800614A8+0x4b8>
			4b8: R_PPC_REL24	fn_80200C38
     4bc:	48 00 00 01 	bl      4bc <fn_800614A8+0x4bc>
			4bc: R_PPC_REL24	fn_801A7228
     4c0:	38 60 00 01 	li      r3,1
     4c4:	48 00 15 28 	b       19ec <fn_800614A8+0x19ec>
     4c8:	2c 16 00 0b 	cmpwi   r22,11
     4cc:	40 82 00 58 	bne     524 <fn_800614A8+0x524>
     4d0:	48 00 00 01 	bl      4d0 <fn_800614A8+0x4d0>
			4d0: R_PPC_REL24	fn_80201B9C
     4d4:	38 80 00 20 	li      r4,32
     4d8:	48 00 00 01 	bl      4d8 <fn_800614A8+0x4d8>
			4d8: R_PPC_REL24	fn_80204844
     4dc:	48 00 00 01 	bl      4dc <fn_800614A8+0x4dc>
			4dc: R_PPC_REL24	fn_8006D444
     4e0:	3c 80 00 08 	lis     r4,8
     4e4:	38 a0 00 00 	li      r5,0
     4e8:	48 00 00 01 	bl      4e8 <fn_800614A8+0x4e8>
			4e8: R_PPC_REL24	fn_8006D344
     4ec:	2c 03 00 00 	cmpwi   r3,0
     4f0:	41 82 00 14 	beq     504 <fn_800614A8+0x504>
     4f4:	7f e3 fb 78 	mr      r3,r31
     4f8:	48 00 00 01 	bl      4f8 <fn_800614A8+0x4f8>
			4f8: R_PPC_REL24	fn_80067180
     4fc:	38 60 00 01 	li      r3,1
     500:	48 00 00 10 	b       510 <fn_800614A8+0x510>
     504:	7f 03 c3 78 	mr      r3,r24
     508:	48 00 00 01 	bl      508 <fn_800614A8+0x508>
			508: R_PPC_REL24	fn_80200C38
     50c:	48 00 00 01 	bl      50c <fn_800614A8+0x50c>
			50c: R_PPC_REL24	fn_800654F8
     510:	28 19 00 00 	cmplwi  r25,0
     514:	41 82 00 08 	beq     51c <fn_800614A8+0x51c>
     518:	90 79 00 00 	stw     r3,0(r25)
     51c:	38 60 00 01 	li      r3,1
     520:	48 00 14 cc 	b       19ec <fn_800614A8+0x19ec>
     524:	2c 16 00 65 	cmpwi   r22,101
     528:	40 82 00 34 	bne     55c <fn_800614A8+0x55c>
     52c:	7f 03 c3 78 	mr      r3,r24
     530:	48 00 00 01 	bl      530 <fn_800614A8+0x530>
			530: R_PPC_REL24	fn_80200C20
     534:	48 00 00 01 	bl      534 <fn_800614A8+0x534>
			534: R_PPC_REL24	fn_80201814
     538:	7c 64 1b 78 	mr      r4,r3
     53c:	7f e3 fb 78 	mr      r3,r31
     540:	48 00 00 01 	bl      540 <fn_800614A8+0x540>
			540: R_PPC_REL24	fn_800359A0
     544:	28 19 00 00 	cmplwi  r25,0
     548:	41 82 00 0c 	beq     554 <fn_800614A8+0x554>
     54c:	38 00 00 01 	li      r0,1
     550:	90 19 00 00 	stw     r0,0(r25)
     554:	38 60 00 01 	li      r3,1
     558:	48 00 14 94 	b       19ec <fn_800614A8+0x19ec>
     55c:	2c 16 00 39 	cmpwi   r22,57
     560:	40 82 00 5c 	bne     5bc <fn_800614A8+0x5bc>
     564:	7f e3 fb 78 	mr      r3,r31
     568:	48 00 00 01 	bl      568 <fn_800614A8+0x568>
			568: R_PPC_REL24	fn_800CA2C8
     56c:	7f e3 fb 78 	mr      r3,r31
     570:	7f 64 db 78 	mr      r4,r27
     574:	48 00 00 01 	bl      574 <fn_800614A8+0x574>
			574: R_PPC_REL24	fn_800EA3A0
     578:	7f a3 eb 78 	mr      r3,r29
     57c:	48 00 00 01 	bl      57c <fn_800614A8+0x57c>
			57c: R_PPC_REL24	fn_8012B324
     580:	7f a3 eb 78 	mr      r3,r29
     584:	38 80 00 c0 	li      r4,192
     588:	38 a0 00 00 	li      r5,0
     58c:	48 00 00 01 	bl      58c <fn_800614A8+0x58c>
			58c: R_PPC_REL24	fn_8011FA8C
     590:	7f e3 fb 78 	mr      r3,r31
     594:	38 80 00 00 	li      r4,0
     598:	48 00 00 01 	bl      598 <fn_800614A8+0x598>
			598: R_PPC_REL24	fn_80201D34
     59c:	7f e3 fb 78 	mr      r3,r31
     5a0:	38 80 00 01 	li      r4,1
     5a4:	48 00 00 01 	bl      5a4 <fn_800614A8+0x5a4>
			5a4: R_PPC_REL24	fn_80201D1C
     5a8:	7f e4 fb 78 	mr      r4,r31
     5ac:	38 60 00 02 	li      r3,2
     5b0:	48 00 00 01 	bl      5b0 <fn_800614A8+0x5b0>
			5b0: R_PPC_REL24	fn_801E8328
     5b4:	38 60 00 01 	li      r3,1
     5b8:	48 00 14 34 	b       19ec <fn_800614A8+0x19ec>
     5bc:	2c 16 00 0e 	cmpwi   r22,14
     5c0:	40 82 00 18 	bne     5d8 <fn_800614A8+0x5d8>
     5c4:	7f e3 fb 78 	mr      r3,r31
     5c8:	7f 04 c3 78 	mr      r4,r24
     5cc:	48 00 00 01 	bl      5cc <fn_800614A8+0x5cc>
			5cc: R_PPC_REL24	fn_80068994
     5d0:	38 60 00 01 	li      r3,1
     5d4:	48 00 14 18 	b       19ec <fn_800614A8+0x19ec>
     5d8:	2c 16 00 27 	cmpwi   r22,39
     5dc:	40 82 00 1c 	bne     5f8 <fn_800614A8+0x5f8>
     5e0:	7f e3 fb 78 	mr      r3,r31
     5e4:	7f 04 c3 78 	mr      r4,r24
     5e8:	7f 25 cb 78 	mr      r5,r25
     5ec:	48 00 00 01 	bl      5ec <fn_800614A8+0x5ec>
			5ec: R_PPC_REL24	fn_80064B38
     5f0:	38 60 00 01 	li      r3,1
     5f4:	48 00 13 f8 	b       19ec <fn_800614A8+0x19ec>
     5f8:	2c 16 00 3b 	cmpwi   r22,59
     5fc:	40 82 00 40 	bne     63c <fn_800614A8+0x63c>
     600:	7f 03 c3 78 	mr      r3,r24
     604:	39 e0 00 01 	li      r15,1
     608:	48 00 00 01 	bl      608 <fn_800614A8+0x608>
			608: R_PPC_REL24	fn_80200C20
     60c:	48 00 00 01 	bl      60c <fn_800614A8+0x60c>
			60c: R_PPC_REL24	fn_80201814
     610:	28 03 00 00 	cmplwi  r3,0
     614:	41 82 00 14 	beq     628 <fn_800614A8+0x628>
     618:	48 00 00 01 	bl      618 <fn_800614A8+0x618>
			618: R_PPC_REL24	fn_80036E50
     61c:	2c 03 00 06 	cmpwi   r3,6
     620:	40 82 00 08 	bne     628 <fn_800614A8+0x628>
     624:	39 e0 00 00 	li      r15,0
     628:	28 19 00 00 	cmplwi  r25,0
     62c:	41 82 00 08 	beq     634 <fn_800614A8+0x634>
     630:	91 f9 00 00 	stw     r15,0(r25)
     634:	38 60 00 01 	li      r3,1
     638:	48 00 13 b4 	b       19ec <fn_800614A8+0x19ec>
     63c:	2c 16 00 4e 	cmpwi   r22,78
     640:	40 82 00 24 	bne     664 <fn_800614A8+0x664>
     644:	28 19 00 00 	cmplwi  r25,0
     648:	41 82 00 14 	beq     65c <fn_800614A8+0x65c>
     64c:	80 1b 00 6c 	lwz     r0,108(r27)
     650:	7c 00 00 34 	cntlzw  r0,r0
     654:	54 00 d9 7e 	srwi    r0,r0,5
     658:	90 19 00 00 	stw     r0,0(r25)
     65c:	38 60 00 01 	li      r3,1
     660:	48 00 13 8c 	b       19ec <fn_800614A8+0x19ec>
     664:	2c 16 00 82 	cmpwi   r22,130
     668:	40 82 00 1c 	bne     684 <fn_800614A8+0x684>
     66c:	28 19 00 00 	cmplwi  r25,0
     670:	41 82 00 0c 	beq     67c <fn_800614A8+0x67c>
     674:	38 00 00 01 	li      r0,1
     678:	90 19 00 00 	stw     r0,0(r25)
     67c:	38 60 00 01 	li      r3,1
     680:	48 00 13 6c 	b       19ec <fn_800614A8+0x19ec>
     684:	2c 16 00 32 	cmpwi   r22,50
     688:	40 82 00 18 	bne     6a0 <fn_800614A8+0x6a0>
     68c:	7f e3 fb 78 	mr      r3,r31
     690:	7f 04 c3 78 	mr      r4,r24
     694:	48 00 00 01 	bl      694 <fn_800614A8+0x694>
			694: R_PPC_REL24	fn_80066A0C
     698:	38 60 00 01 	li      r3,1
     69c:	48 00 13 50 	b       19ec <fn_800614A8+0x19ec>
     6a0:	2c 16 00 e6 	cmpwi   r22,230
     6a4:	40 82 00 28 	bne     6cc <fn_800614A8+0x6cc>
     6a8:	7f 03 c3 78 	mr      r3,r24
     6ac:	48 00 00 01 	bl      6ac <fn_800614A8+0x6ac>
			6ac: R_PPC_REL24	fn_80200C38
     6b0:	c0 20 00 00 	lfs     f1,0(0)
			6b0: R_PPC_EMB_SDA21	lbl_8064E614
     6b4:	7c 64 1b 78 	mr      r4,r3
     6b8:	c0 40 00 00 	lfs     f2,0(0)
			6b8: R_PPC_EMB_SDA21	lbl_8064E618
     6bc:	7f a3 eb 78 	mr      r3,r29
     6c0:	48 00 00 01 	bl      6c0 <fn_800614A8+0x6c0>
			6c0: R_PPC_REL24	fn_80066888
     6c4:	38 60 00 01 	li      r3,1
     6c8:	48 00 13 24 	b       19ec <fn_800614A8+0x19ec>
     6cc:	2c 16 00 35 	cmpwi   r22,53
     6d0:	40 82 00 88 	bne     758 <fn_800614A8+0x758>
     6d4:	7f 03 c3 78 	mr      r3,r24
     6d8:	48 00 00 01 	bl      6d8 <fn_800614A8+0x6d8>
			6d8: R_PPC_REL24	fn_80200C38
     6dc:	7c 6f 1b 78 	mr      r15,r3
     6e0:	48 00 00 01 	bl      6e0 <fn_800614A8+0x6e0>
			6e0: R_PPC_REL24	fn_801A7488
     6e4:	7c 70 1b 78 	mr      r16,r3
     6e8:	2c 10 00 0b 	cmpwi   r16,11
     6ec:	40 82 00 14 	bne     700 <fn_800614A8+0x700>
     6f0:	7d e3 7b 78 	mr      r3,r15
     6f4:	38 80 00 0d 	li      r4,13
     6f8:	48 00 00 01 	bl      6f8 <fn_800614A8+0x6f8>
			6f8: R_PPC_REL24	fn_801A7470
     6fc:	48 00 00 18 	b       714 <fn_800614A8+0x714>
     700:	2c 10 00 0c 	cmpwi   r16,12
     704:	40 82 00 10 	bne     714 <fn_800614A8+0x714>
     708:	7d e3 7b 78 	mr      r3,r15
     70c:	38 80 00 0e 	li      r4,14
     710:	48 00 00 01 	bl      710 <fn_800614A8+0x710>
			710: R_PPC_REL24	fn_801A7470
     714:	7f e3 fb 78 	mr      r3,r31
     718:	7f 04 c3 78 	mr      r4,r24
     71c:	7f 25 cb 78 	mr      r5,r25
     720:	48 00 00 01 	bl      720 <fn_800614A8+0x720>
			720: R_PPC_REL24	fn_80066754
     724:	7d e3 7b 78 	mr      r3,r15
     728:	7e 04 83 78 	mr      r4,r16
     72c:	48 00 00 01 	bl      72c <fn_800614A8+0x72c>
			72c: R_PPC_REL24	fn_801A7470
     730:	2c 10 00 0b 	cmpwi   r16,11
     734:	41 82 00 0c 	beq     740 <fn_800614A8+0x740>
     738:	2c 10 00 0c 	cmpwi   r16,12
     73c:	40 82 00 14 	bne     750 <fn_800614A8+0x750>
     740:	3c 80 00 02 	lis     r4,2
     744:	7f a3 eb 78 	mr      r3,r29
     748:	38 84 fd 70 	addi    r4,r4,-656
     74c:	48 00 00 01 	bl      74c <fn_800614A8+0x74c>
			74c: R_PPC_REL24	fn_801296F8
     750:	38 60 00 01 	li      r3,1
     754:	48 00 12 98 	b       19ec <fn_800614A8+0x19ec>
     758:	2c 16 00 ea 	cmpwi   r22,234
     75c:	40 82 01 2c 	bne     888 <fn_800614A8+0x888>
     760:	7f e3 fb 78 	mr      r3,r31
     764:	7f 04 c3 78 	mr      r4,r24
     768:	48 00 00 01 	bl      768 <fn_800614A8+0x768>
			768: R_PPC_REL24	fn_800674E4
     76c:	80 00 00 00 	lwz     r0,0(0)
			76c: R_PPC_EMB_SDA21	lbl_8064D18C
     770:	2c 00 00 88 	cmpwi   r0,136
     774:	40 82 00 f8 	bne     86c <fn_800614A8+0x86c>
     778:	a8 9b 00 ea 	lha     r4,234(r27)
     77c:	38 60 00 01 	li      r3,1
     780:	7c 80 0e 70 	srawi   r0,r4,1
     784:	2c 00 00 01 	cmpwi   r0,1
     788:	41 80 00 08 	blt     790 <fn_800614A8+0x790>
     78c:	7c 83 0e 70 	srawi   r3,r4,1
     790:	b0 7b 00 ea 	sth     r3,234(r27)
     794:	38 60 00 01 	li      r3,1
     798:	a8 9b 00 fa 	lha     r4,250(r27)
     79c:	7c 80 0e 70 	srawi   r0,r4,1
     7a0:	2c 00 00 01 	cmpwi   r0,1
     7a4:	41 80 00 08 	blt     7ac <fn_800614A8+0x7ac>
     7a8:	7c 83 0e 70 	srawi   r3,r4,1
     7ac:	b0 7b 00 fa 	sth     r3,250(r27)
     7b0:	38 60 00 01 	li      r3,1
     7b4:	a8 9b 00 fc 	lha     r4,252(r27)
     7b8:	7c 80 0e 70 	srawi   r0,r4,1
     7bc:	2c 00 00 01 	cmpwi   r0,1
     7c0:	41 80 00 08 	blt     7c8 <fn_800614A8+0x7c8>
     7c4:	7c 83 0e 70 	srawi   r3,r4,1
     7c8:	b0 7b 00 fc 	sth     r3,252(r27)
     7cc:	38 60 00 01 	li      r3,1
     7d0:	a8 9b 00 ee 	lha     r4,238(r27)
     7d4:	7c 80 0e 70 	srawi   r0,r4,1
     7d8:	2c 00 00 01 	cmpwi   r0,1
     7dc:	41 80 00 08 	blt     7e4 <fn_800614A8+0x7e4>
     7e0:	7c 83 0e 70 	srawi   r3,r4,1
     7e4:	b0 7b 00 ee 	sth     r3,238(r27)
     7e8:	38 60 00 01 	li      r3,1
     7ec:	a8 9b 00 f0 	lha     r4,240(r27)
     7f0:	7c 80 0e 70 	srawi   r0,r4,1
     7f4:	2c 00 00 01 	cmpwi   r0,1
     7f8:	41 80 00 08 	blt     800 <fn_800614A8+0x800>
     7fc:	7c 83 0e 70 	srawi   r3,r4,1
     800:	b0 7b 00 f0 	sth     r3,240(r27)
     804:	38 60 00 01 	li      r3,1
     808:	a8 9b 00 ec 	lha     r4,236(r27)
     80c:	7c 80 0e 70 	srawi   r0,r4,1
     810:	2c 00 00 01 	cmpwi   r0,1
     814:	41 80 00 08 	blt     81c <fn_800614A8+0x81c>
     818:	7c 83 0e 70 	srawi   r3,r4,1
     81c:	b0 7b 00 ec 	sth     r3,236(r27)
     820:	7f e3 fb 78 	mr      r3,r31
     824:	38 a1 00 10 	addi    r5,r1,16
     828:	38 80 00 00 	li      r4,0
     82c:	48 00 00 01 	bl      82c <fn_800614A8+0x82c>
			82c: R_PPC_REL24	fn_80038308
     830:	a8 61 00 10 	lha     r3,16(r1)
     834:	38 80 00 01 	li      r4,1
     838:	7c 60 0e 70 	srawi   r0,r3,1
     83c:	2c 00 00 01 	cmpwi   r0,1
     840:	41 80 00 08 	blt     848 <fn_800614A8+0x848>
     844:	7c 64 0e 70 	srawi   r4,r3,1
     848:	7f e3 fb 78 	mr      r3,r31
     84c:	7c 85 07 34 	extsh   r5,r4
     850:	38 80 00 00 	li      r4,0
     854:	38 c0 00 00 	li      r6,0
     858:	48 00 00 01 	bl      858 <fn_800614A8+0x858>
			858: R_PPC_REL24	fn_800389E0
     85c:	a8 7a 00 86 	lha     r3,134(r26)
     860:	38 03 00 1e 	addi    r0,r3,30
     864:	b0 1a 00 86 	sth     r0,134(r26)
     868:	48 00 00 18 	b       880 <fn_800614A8+0x880>
     86c:	2c 00 00 29 	cmpwi   r0,41
     870:	40 82 00 10 	bne     880 <fn_800614A8+0x880>
     874:	a8 7a 00 86 	lha     r3,134(r26)
     878:	38 03 00 1e 	addi    r0,r3,30
     87c:	b0 1a 00 86 	sth     r0,134(r26)
     880:	38 60 00 01 	li      r3,1
     884:	48 00 11 68 	b       19ec <fn_800614A8+0x19ec>
     888:	2c 16 00 eb 	cmpwi   r22,235
     88c:	40 82 00 18 	bne     8a4 <fn_800614A8+0x8a4>
     890:	7f e3 fb 78 	mr      r3,r31
     894:	7f 04 c3 78 	mr      r4,r24
     898:	48 00 00 01 	bl      898 <fn_800614A8+0x898>
			898: R_PPC_REL24	fn_80067650
     89c:	38 60 00 01 	li      r3,1
     8a0:	48 00 11 4c 	b       19ec <fn_800614A8+0x19ec>
     8a4:	2c 16 00 f3 	cmpwi   r22,243
     8a8:	40 82 11 44 	bne     19ec <fn_800614A8+0x19ec>
     8ac:	7f 03 c3 78 	mr      r3,r24
     8b0:	48 00 00 01 	bl      8b0 <fn_800614A8+0x8b0>
			8b0: R_PPC_REL24	fn_80200C38
     8b4:	7c 65 1b 78 	mr      r5,r3
     8b8:	7f e3 fb 78 	mr      r3,r31
     8bc:	7f 64 db 78 	mr      r4,r27
     8c0:	7f 06 c3 78 	mr      r6,r24
     8c4:	7f 27 cb 78 	mr      r7,r25
     8c8:	48 00 00 01 	bl      8c8 <fn_800614A8+0x8c8>
			8c8: R_PPC_REL24	fn_800EA0FC
     8cc:	38 60 00 01 	li      r3,1
     8d0:	48 00 11 1c 	b       19ec <fn_800614A8+0x19ec>
     8d4:	2c 17 00 01 	cmpwi   r23,1
     8d8:	40 82 02 20 	bne     af8 <fn_800614A8+0xaf8>
     8dc:	2c 16 00 01 	cmpwi   r22,1
     8e0:	40 82 00 30 	bne     910 <fn_800614A8+0x910>
     8e4:	c0 20 00 00 	lfs     f1,0(0)
			8e4: R_PPC_EMB_SDA21	lbl_8064E61C
     8e8:	7f a3 eb 78 	mr      r3,r29
     8ec:	48 00 00 01 	bl      8ec <fn_800614A8+0x8ec>
			8ec: R_PPC_REL24	fn_8011F778
     8f0:	c0 20 00 00 	lfs     f1,0(0)
			8f0: R_PPC_EMB_SDA21	lbl_8064E61C
     8f4:	7f a3 eb 78 	mr      r3,r29
     8f8:	48 00 00 01 	bl      8f8 <fn_800614A8+0x8f8>
			8f8: R_PPC_REL24	fn_8011F788
     8fc:	c0 20 00 00 	lfs     f1,0(0)
			8fc: R_PPC_EMB_SDA21	lbl_8064E61C
     900:	7f a3 eb 78 	mr      r3,r29
     904:	48 00 00 01 	bl      904 <fn_800614A8+0x904>
			904: R_PPC_REL24	fn_8011F798
     908:	38 60 00 01 	li      r3,1
     90c:	48 00 10 e0 	b       19ec <fn_800614A8+0x19ec>
     910:	2c 16 00 5a 	cmpwi   r22,90
     914:	40 82 01 94 	bne     aa8 <fn_800614A8+0xaa8>
     918:	7f 03 c3 78 	mr      r3,r24
     91c:	48 00 00 01 	bl      91c <fn_800614A8+0x91c>
			91c: R_PPC_REL24	fn_80200C20
     920:	48 00 00 01 	bl      920 <fn_800614A8+0x920>
			920: R_PPC_REL24	fn_80201814
     924:	28 03 00 00 	cmplwi  r3,0
     928:	41 82 00 10 	beq     938 <fn_800614A8+0x938>
     92c:	48 00 00 01 	bl      92c <fn_800614A8+0x92c>
			92c: R_PPC_REL24	fn_80201BC8
     930:	7c 77 1b 78 	mr      r23,r3
     934:	48 00 00 08 	b       93c <fn_800614A8+0x93c>
     938:	3a e0 00 00 	li      r23,0
     93c:	28 17 00 00 	cmplwi  r23,0
     940:	41 82 01 60 	beq     aa0 <fn_800614A8+0xaa0>
     944:	48 00 00 01 	bl      944 <fn_800614A8+0x944>
			944: R_PPC_REL24	fn_800460EC
     948:	2c 03 00 00 	cmpwi   r3,0
     94c:	40 82 01 54 	bne     aa0 <fn_800614A8+0xaa0>
     950:	7f e3 fb 78 	mr      r3,r31
     954:	48 00 00 01 	bl      954 <fn_800614A8+0x954>
			954: R_PPC_REL24	fn_800CAF7C
     958:	2c 03 00 00 	cmpwi   r3,0
     95c:	41 82 01 44 	beq     aa0 <fn_800614A8+0xaa0>
     960:	80 7c 00 8c 	lwz     r3,140(r28)
     964:	a8 03 01 50 	lha     r0,336(r3)
     968:	2c 00 00 00 	cmpwi   r0,0
     96c:	40 82 01 34 	bne     aa0 <fn_800614A8+0xaa0>
     970:	7e e4 bb 78 	mr      r4,r23
     974:	38 61 00 50 	addi    r3,r1,80
     978:	48 00 00 01 	bl      978 <fn_800614A8+0x978>
			978: R_PPC_REL24	fn_8011F114
     97c:	80 a1 00 50 	lwz     r5,80(r1)
     980:	3c 00 43 30 	lis     r0,17200
     984:	80 e1 00 54 	lwz     r7,84(r1)
     988:	7f a3 eb 78 	mr      r3,r29
     98c:	80 c1 00 58 	lwz     r6,88(r1)
     990:	38 81 00 74 	addi    r4,r1,116
     994:	90 a1 00 74 	stw     r5,116(r1)
     998:	38 a0 00 00 	li      r5,0
     99c:	c8 20 00 00 	lfd     f1,0(0)
			99c: R_PPC_EMB_SDA21	@559
     9a0:	90 e1 00 78 	stw     r7,120(r1)
     9a4:	c0 40 00 00 	lfs     f2,0(0)
			9a4: R_PPC_EMB_SDA21	lbl_8064E620
     9a8:	90 c1 00 7c 	stw     r6,124(r1)
     9ac:	a8 db 01 4a 	lha     r6,330(r27)
     9b0:	90 01 00 c0 	stw     r0,192(r1)
     9b4:	6c c0 80 00 	xoris   r0,r6,32768
     9b8:	90 01 00 c4 	stw     r0,196(r1)
     9bc:	c8 01 00 c0 	lfd     f0,192(r1)
     9c0:	ec 00 08 28 	fsubs   f0,f0,f1
     9c4:	ec 22 00 32 	fmuls   f1,f2,f0
     9c8:	48 00 00 01 	bl      9c8 <fn_800614A8+0x9c8>
			9c8: R_PPC_REL24	fn_80204434
     9cc:	54 60 06 3f 	clrlwi. r0,r3,24
     9d0:	40 82 00 d0 	bne     aa0 <fn_800614A8+0xaa0>
     9d4:	80 00 00 00 	lwz     r0,0(0)
			9d4: R_PPC_EMB_SDA21	lbl_8064D18C
     9d8:	2c 00 00 34 	cmpwi   r0,52
     9dc:	41 82 00 c4 	beq     aa0 <fn_800614A8+0xaa0>
     9e0:	7e e4 bb 78 	mr      r4,r23
     9e4:	38 61 00 44 	addi    r3,r1,68
     9e8:	48 00 00 01 	bl      9e8 <fn_800614A8+0x9e8>
			9e8: R_PPC_REL24	fn_8011F114
     9ec:	80 c1 00 44 	lwz     r6,68(r1)
     9f0:	7e e3 bb 78 	mr      r3,r23
     9f4:	80 01 00 48 	lwz     r0,72(r1)
     9f8:	38 e1 00 98 	addi    r7,r1,152
     9fc:	38 80 00 00 	li      r4,0
     a00:	38 a0 00 00 	li      r5,0
     a04:	90 db 00 94 	stw     r6,148(r27)
     a08:	38 c0 ff ff 	li      r6,-1
     a0c:	39 00 00 01 	li      r8,1
     a10:	90 1b 00 98 	stw     r0,152(r27)
     a14:	80 01 00 4c 	lwz     r0,76(r1)
     a18:	90 1b 00 9c 	stw     r0,156(r27)
     a1c:	48 00 00 01 	bl      a1c <fn_800614A8+0xa1c>
			a1c: R_PPC_REL24	fn_8011F598
     a20:	2c 03 ff ff 	cmpwi   r3,-1
     a24:	41 82 00 18 	beq     a3c <fn_800614A8+0xa3c>
     a28:	7e e3 bb 78 	mr      r3,r23
     a2c:	38 a1 00 80 	addi    r5,r1,128
     a30:	38 80 00 00 	li      r4,0
     a34:	48 00 00 01 	bl      a34 <fn_800614A8+0xa34>
			a34: R_PPC_REL24	fn_8012FE10
     a38:	48 00 00 1c 	b       a54 <fn_800614A8+0xa54>
     a3c:	80 81 00 74 	lwz     r4,116(r1)
     a40:	80 61 00 78 	lwz     r3,120(r1)
     a44:	80 01 00 7c 	lwz     r0,124(r1)
     a48:	90 81 00 80 	stw     r4,128(r1)
     a4c:	90 61 00 84 	stw     r3,132(r1)
     a50:	90 01 00 88 	stw     r0,136(r1)
     a54:	80 1c 00 94 	lwz     r0,148(r28)
     a58:	2c 00 00 01 	cmpwi   r0,1
     a5c:	40 82 00 2c 	bne     a88 <fn_800614A8+0xa88>
     a60:	7f a3 eb 78 	mr      r3,r29
     a64:	38 81 00 80 	addi    r4,r1,128
     a68:	38 a0 00 04 	li      r5,4
     a6c:	38 c0 00 04 	li      r6,4
     a70:	48 00 00 01 	bl      a70 <fn_800614A8+0xa70>
			a70: R_PPC_REL24	fn_8012FF34
     a74:	2c 03 00 00 	cmpwi   r3,0
     a78:	41 82 00 10 	beq     a88 <fn_800614A8+0xa88>
     a7c:	7f a3 eb 78 	mr      r3,r29
     a80:	38 80 00 3c 	li      r4,60
     a84:	48 00 00 01 	bl      a84 <fn_800614A8+0xa84>
			a84: R_PPC_REL24	fn_801302BC
     a88:	7f e3 fb 78 	mr      r3,r31
     a8c:	38 80 00 15 	li      r4,21
     a90:	48 00 00 01 	bl      a90 <fn_800614A8+0xa90>
			a90: R_PPC_REL24	fn_80201D2C
     a94:	7f e3 fb 78 	mr      r3,r31
     a98:	38 80 00 01 	li      r4,1
     a9c:	48 00 00 01 	bl      a9c <fn_800614A8+0xa9c>
			a9c: R_PPC_REL24	fn_80201D14
     aa0:	38 60 00 01 	li      r3,1
     aa4:	48 00 0f 48 	b       19ec <fn_800614A8+0x19ec>
     aa8:	2c 16 00 03 	cmpwi   r22,3
     aac:	40 82 0f 40 	bne     19ec <fn_800614A8+0x19ec>
     ab0:	7f a3 eb 78 	mr      r3,r29
     ab4:	7e 44 93 78 	mr      r4,r18
     ab8:	7e 05 83 78 	mr      r5,r16
     abc:	48 00 00 01 	bl      abc <fn_800614A8+0xabc>
			abc: R_PPC_REL24	fn_80060C24
     ac0:	7f e3 fb 78 	mr      r3,r31
     ac4:	7f a4 eb 78 	mr      r4,r29
     ac8:	7f 05 c3 78 	mr      r5,r24
     acc:	7e 46 93 78 	mr      r6,r18
     ad0:	7e 07 83 78 	mr      r7,r16
     ad4:	48 00 00 01 	bl      ad4 <fn_800614A8+0xad4>
			ad4: R_PPC_REL24	fn_80060D4C
     ad8:	7f c3 f3 78 	mr      r3,r30
     adc:	7f e4 fb 78 	mr      r4,r31
     ae0:	7f a5 eb 78 	mr      r5,r29
     ae4:	7f 86 e3 78 	mr      r6,r28
     ae8:	7f 47 d3 78 	mr      r7,r26
     aec:	48 00 00 01 	bl      aec <fn_800614A8+0xaec>
			aec: R_PPC_REL24	fn_8005FD84
     af0:	38 60 00 01 	li      r3,1
     af4:	48 00 0e f8 	b       19ec <fn_800614A8+0x19ec>
     af8:	2c 17 00 15 	cmpwi   r23,21
     afc:	40 82 02 64 	bne     d60 <fn_800614A8+0xd60>
     b00:	2c 16 00 01 	cmpwi   r22,1
     b04:	40 82 00 1c 	bne     b20 <fn_800614A8+0xb20>
     b08:	c0 00 00 00 	lfs     f0,0(0)
			b08: R_PPC_EMB_SDA21	lbl_8064E5DC
     b0c:	7f a3 eb 78 	mr      r3,r29
     b10:	d0 1b 00 c4 	stfs    f0,196(r27)
     b14:	48 00 00 01 	bl      b14 <fn_800614A8+0xb14>
			b14: R_PPC_REL24	fn_8012B344
     b18:	38 60 00 01 	li      r3,1
     b1c:	48 00 0e d0 	b       19ec <fn_800614A8+0x19ec>
     b20:	2c 16 00 03 	cmpwi   r22,3
     b24:	40 82 00 d8 	bne     bfc <fn_800614A8+0xbfc>
     b28:	7f c3 f3 78 	mr      r3,r30
     b2c:	7f e4 fb 78 	mr      r4,r31
     b30:	7f a5 eb 78 	mr      r5,r29
     b34:	7f 86 e3 78 	mr      r6,r28
     b38:	7f 47 d3 78 	mr      r7,r26
     b3c:	48 00 00 01 	bl      b3c <fn_800614A8+0xb3c>
			b3c: R_PPC_REL24	fn_8005FD84
     b40:	7f e3 fb 78 	mr      r3,r31
     b44:	7f a4 eb 78 	mr      r4,r29
     b48:	7f 05 c3 78 	mr      r5,r24
     b4c:	7e 46 93 78 	mr      r6,r18
     b50:	7e 07 83 78 	mr      r7,r16
     b54:	48 00 00 01 	bl      b54 <fn_800614A8+0xb54>
			b54: R_PPC_REL24	fn_80060D4C
     b58:	2c 03 00 00 	cmpwi   r3,0
     b5c:	40 82 00 98 	bne     bf4 <fn_800614A8+0xbf4>
     b60:	c0 20 00 00 	lfs     f1,0(0)
			b60: R_PPC_EMB_SDA21	lbl_8064E608
     b64:	7f a3 eb 78 	mr      r3,r29
     b68:	38 9b 00 94 	addi    r4,r27,148
     b6c:	38 a0 00 02 	li      r5,2
     b70:	38 c0 00 00 	li      r6,0
     b74:	48 00 00 01 	bl      b74 <fn_800614A8+0xb74>
			b74: R_PPC_REL24	fn_800BE86C
     b78:	2c 03 00 00 	cmpwi   r3,0
     b7c:	40 82 00 34 	bne     bb0 <fn_800614A8+0xbb0>
     b80:	7f a3 eb 78 	mr      r3,r29
     b84:	38 80 00 0f 	li      r4,15
     b88:	38 a0 00 25 	li      r5,37
     b8c:	38 c0 00 01 	li      r6,1
     b90:	48 00 00 01 	bl      b90 <fn_800614A8+0xb90>
			b90: R_PPC_REL24	fn_801294DC
     b94:	7f e3 fb 78 	mr      r3,r31
     b98:	38 80 00 01 	li      r4,1
     b9c:	48 00 00 01 	bl      b9c <fn_800614A8+0xb9c>
			b9c: R_PPC_REL24	fn_80201D2C
     ba0:	7f e3 fb 78 	mr      r3,r31
     ba4:	38 80 00 01 	li      r4,1
     ba8:	48 00 00 01 	bl      ba8 <fn_800614A8+0xba8>
			ba8: R_PPC_REL24	fn_80201D14
     bac:	48 00 00 48 	b       bf4 <fn_800614A8+0xbf4>
     bb0:	c0 5b 00 c4 	lfs     f2,196(r27)
     bb4:	c0 00 00 00 	lfs     f0,0(0)
			bb4: R_PPC_EMB_SDA21	lbl_8064E624
     bb8:	fc 02 00 40 	fcmpo   cr0,f2,f0
     bbc:	40 80 00 38 	bge     bf4 <fn_800614A8+0xbf4>
     bc0:	c0 00 00 00 	lfs     f0,0(0)
			bc0: R_PPC_EMB_SDA21	lbl_8064E628
     bc4:	ec 02 00 2a 	fadds   f0,f2,f0
     bc8:	d0 1b 00 c4 	stfs    f0,196(r27)
     bcc:	c0 20 00 00 	lfs     f1,0(0)
			bcc: R_PPC_EMB_SDA21	lbl_8064E614
     bd0:	fc 02 08 40 	fcmpo   cr0,f2,f1
     bd4:	4c 40 13 82 	cror    eq,lt,eq
     bd8:	40 82 00 1c 	bne     bf4 <fn_800614A8+0xbf4>
     bdc:	c0 1b 00 c4 	lfs     f0,196(r27)
     be0:	fc 00 08 40 	fcmpo   cr0,f0,f1
     be4:	40 81 00 10 	ble     bf4 <fn_800614A8+0xbf4>
     be8:	7f a3 eb 78 	mr      r3,r29
     bec:	38 80 00 3f 	li      r4,63
     bf0:	48 00 00 01 	bl      bf0 <fn_800614A8+0xbf0>
			bf0: R_PPC_REL24	fn_801A977C
     bf4:	38 60 00 01 	li      r3,1
     bf8:	48 00 0d f4 	b       19ec <fn_800614A8+0x19ec>
     bfc:	2c 16 00 5a 	cmpwi   r22,90
     c00:	40 82 00 f4 	bne     cf4 <fn_800614A8+0xcf4>
     c04:	7f 03 c3 78 	mr      r3,r24
     c08:	48 00 00 01 	bl      c08 <fn_800614A8+0xc08>
			c08: R_PPC_REL24	fn_80200C20
     c0c:	48 00 00 01 	bl      c0c <fn_800614A8+0xc0c>
			c0c: R_PPC_REL24	fn_80201814
     c10:	28 03 00 00 	cmplwi  r3,0
     c14:	41 82 00 10 	beq     c24 <fn_800614A8+0xc24>
     c18:	48 00 00 01 	bl      c18 <fn_800614A8+0xc18>
			c18: R_PPC_REL24	fn_80201BC8
     c1c:	7c 70 1b 78 	mr      r16,r3
     c20:	48 00 00 08 	b       c28 <fn_800614A8+0xc28>
     c24:	3a 00 00 00 	li      r16,0
     c28:	28 10 00 00 	cmplwi  r16,0
     c2c:	41 82 00 c0 	beq     cec <fn_800614A8+0xcec>
     c30:	48 00 00 01 	bl      c30 <fn_800614A8+0xc30>
			c30: R_PPC_REL24	fn_800460EC
     c34:	2c 03 00 00 	cmpwi   r3,0
     c38:	40 82 00 b4 	bne     cec <fn_800614A8+0xcec>
     c3c:	7f e3 fb 78 	mr      r3,r31
     c40:	48 00 00 01 	bl      c40 <fn_800614A8+0xc40>
			c40: R_PPC_REL24	fn_800CAF7C
     c44:	2c 03 00 00 	cmpwi   r3,0
     c48:	41 82 00 a4 	beq     cec <fn_800614A8+0xcec>
     c4c:	a8 1b 01 50 	lha     r0,336(r27)
     c50:	2c 00 00 00 	cmpwi   r0,0
     c54:	40 82 00 98 	bne     cec <fn_800614A8+0xcec>
     c58:	7e 04 83 78 	mr      r4,r16
     c5c:	38 61 00 38 	addi    r3,r1,56
     c60:	48 00 00 01 	bl      c60 <fn_800614A8+0xc60>
			c60: R_PPC_REL24	fn_8011F114
     c64:	80 a1 00 38 	lwz     r5,56(r1)
     c68:	3c 00 43 30 	lis     r0,17200
     c6c:	80 e1 00 3c 	lwz     r7,60(r1)
     c70:	7f a3 eb 78 	mr      r3,r29
     c74:	80 c1 00 40 	lwz     r6,64(r1)
     c78:	38 81 00 68 	addi    r4,r1,104
     c7c:	90 a1 00 68 	stw     r5,104(r1)
     c80:	38 a0 00 00 	li      r5,0
     c84:	c8 20 00 00 	lfd     f1,0(0)
			c84: R_PPC_EMB_SDA21	@559
     c88:	90 e1 00 6c 	stw     r7,108(r1)
     c8c:	c0 40 00 00 	lfs     f2,0(0)
			c8c: R_PPC_EMB_SDA21	lbl_8064E620
     c90:	90 c1 00 70 	stw     r6,112(r1)
     c94:	a8 db 01 4a 	lha     r6,330(r27)
     c98:	90 01 00 c0 	stw     r0,192(r1)
     c9c:	6c c0 80 00 	xoris   r0,r6,32768
     ca0:	90 01 00 c4 	stw     r0,196(r1)
     ca4:	c8 01 00 c0 	lfd     f0,192(r1)
     ca8:	ec 00 08 28 	fsubs   f0,f0,f1
     cac:	ec 22 00 32 	fmuls   f1,f2,f0
     cb0:	48 00 00 01 	bl      cb0 <fn_800614A8+0xcb0>
			cb0: R_PPC_REL24	fn_80204434
     cb4:	54 60 06 3f 	clrlwi. r0,r3,24
     cb8:	40 82 00 34 	bne     cec <fn_800614A8+0xcec>
     cbc:	80 00 00 00 	lwz     r0,0(0)
			cbc: R_PPC_EMB_SDA21	lbl_8064D18C
     cc0:	2c 00 00 34 	cmpwi   r0,52
     cc4:	41 82 00 28 	beq     cec <fn_800614A8+0xcec>
     cc8:	7e 04 83 78 	mr      r4,r16
     ccc:	38 61 00 2c 	addi    r3,r1,44
     cd0:	48 00 00 01 	bl      cd0 <fn_800614A8+0xcd0>
			cd0: R_PPC_REL24	fn_8011F114
     cd4:	80 61 00 2c 	lwz     r3,44(r1)
     cd8:	80 01 00 30 	lwz     r0,48(r1)
     cdc:	90 7b 00 94 	stw     r3,148(r27)
     ce0:	90 1b 00 98 	stw     r0,152(r27)
     ce4:	80 01 00 34 	lwz     r0,52(r1)
     ce8:	90 1b 00 9c 	stw     r0,156(r27)
     cec:	38 60 00 01 	li      r3,1
     cf0:	48 00 0c fc 	b       19ec <fn_800614A8+0x19ec>
     cf4:	2c 16 00 02 	cmpwi   r22,2
     cf8:	40 82 0c f4 	bne     19ec <fn_800614A8+0x19ec>
     cfc:	7f a3 eb 78 	mr      r3,r29
     d00:	48 00 00 01 	bl      d00 <fn_800614A8+0xd00>
			d00: R_PPC_REL24	fn_80128EAC
     d04:	7c 70 1b 78 	mr      r16,r3
     d08:	7f a3 eb 78 	mr      r3,r29
     d0c:	48 00 00 01 	bl      d0c <fn_800614A8+0xd0c>
			d0c: R_PPC_REL24	fn_801290D0
     d10:	54 60 07 7b 	rlwinm. r0,r3,0,29,29
     d14:	7c 64 1b 78 	mr      r4,r3
     d18:	41 82 00 38 	beq     d50 <fn_800614A8+0xd50>
     d1c:	2c 10 00 03 	cmpwi   r16,3
     d20:	41 82 00 0c 	beq     d2c <fn_800614A8+0xd2c>
     d24:	2c 10 00 02 	cmpwi   r16,2
     d28:	40 82 00 28 	bne     d50 <fn_800614A8+0xd50>
     d2c:	80 00 00 00 	lwz     r0,0(0)
			d2c: R_PPC_EMB_SDA21	lbl_8064D18C
     d30:	2c 00 00 53 	cmpwi   r0,83
     d34:	40 82 00 10 	bne     d44 <fn_800614A8+0xd44>
     d38:	7f a3 eb 78 	mr      r3,r29
     d3c:	48 00 00 01 	bl      d3c <fn_800614A8+0xd3c>
			d3c: R_PPC_REL24	fn_8012B344
     d40:	48 00 00 10 	b       d50 <fn_800614A8+0xd50>
     d44:	7f a3 eb 78 	mr      r3,r29
     d48:	54 84 07 b8 	rlwinm  r4,r4,0,30,28
     d4c:	48 00 00 01 	bl      d4c <fn_800614A8+0xd4c>
			d4c: R_PPC_REL24	fn_80128F74
     d50:	c0 00 00 00 	lfs     f0,0(0)
			d50: R_PPC_EMB_SDA21	lbl_8064E5DC
     d54:	38 60 00 01 	li      r3,1
     d58:	d0 1b 00 c4 	stfs    f0,196(r27)
     d5c:	48 00 0c 90 	b       19ec <fn_800614A8+0x19ec>
     d60:	2c 17 00 03 	cmpwi   r23,3
     d64:	40 82 00 ac 	bne     e10 <fn_800614A8+0xe10>
     d68:	2c 16 00 03 	cmpwi   r22,3
     d6c:	40 82 00 6c 	bne     dd8 <fn_800614A8+0xdd8>
     d70:	7f c3 f3 78 	mr      r3,r30
     d74:	7f e4 fb 78 	mr      r4,r31
     d78:	7f a5 eb 78 	mr      r5,r29
     d7c:	7f 86 e3 78 	mr      r6,r28
     d80:	7f 47 d3 78 	mr      r7,r26
     d84:	48 00 00 01 	bl      d84 <fn_800614A8+0xd84>
			d84: R_PPC_REL24	fn_8005FD84
     d88:	7f e3 fb 78 	mr      r3,r31
     d8c:	7f 64 db 78 	mr      r4,r27
     d90:	48 00 00 01 	bl      d90 <fn_800614A8+0xd90>
			d90: R_PPC_REL24	fn_800BE010
     d94:	7e 83 a3 78 	mr      r3,r20
     d98:	48 00 00 01 	bl      d98 <fn_800614A8+0xd98>
			d98: R_PPC_REL24	fn_80201C48
     d9c:	2c 03 00 00 	cmpwi   r3,0
     da0:	41 82 00 10 	beq     db0 <fn_800614A8+0xdb0>
     da4:	7f e3 fb 78 	mr      r3,r31
     da8:	7f 64 db 78 	mr      r4,r27
     dac:	48 00 00 01 	bl      dac <fn_800614A8+0xdac>
			dac: R_PPC_REL24	fn_800BDEE4
     db0:	7f e3 fb 78 	mr      r3,r31
     db4:	7f a4 eb 78 	mr      r4,r29
     db8:	7f c5 f3 78 	mr      r5,r30
     dbc:	7f 66 db 78 	mr      r6,r27
     dc0:	7f 07 c3 78 	mr      r7,r24
     dc4:	7e 48 93 78 	mr      r8,r18
     dc8:	7e 09 83 78 	mr      r9,r16
     dcc:	48 00 00 01 	bl      dcc <fn_800614A8+0xdcc>
			dcc: R_PPC_REL24	fn_80060F9C
     dd0:	38 60 00 01 	li      r3,1
     dd4:	48 00 0c 18 	b       19ec <fn_800614A8+0x19ec>
     dd8:	2c 16 00 66 	cmpwi   r22,102
     ddc:	40 82 00 2c 	bne     e08 <fn_800614A8+0xe08>
     de0:	7f a3 eb 78 	mr      r3,r29
     de4:	48 00 00 01 	bl      de4 <fn_800614A8+0xde4>
			de4: R_PPC_REL24	fn_8012B344
     de8:	7f e3 fb 78 	mr      r3,r31
     dec:	38 80 00 01 	li      r4,1
     df0:	48 00 00 01 	bl      df0 <fn_800614A8+0xdf0>
			df0: R_PPC_REL24	fn_80201D2C
     df4:	7f e3 fb 78 	mr      r3,r31
     df8:	38 80 00 01 	li      r4,1
     dfc:	48 00 00 01 	bl      dfc <fn_800614A8+0xdfc>
			dfc: R_PPC_REL24	fn_80201D14
     e00:	38 60 00 01 	li      r3,1
     e04:	48 00 0b e8 	b       19ec <fn_800614A8+0x19ec>
     e08:	38 60 00 00 	li      r3,0
     e0c:	48 00 0b e0 	b       19ec <fn_800614A8+0x19ec>
     e10:	2c 17 00 06 	cmpwi   r23,6
     e14:	40 82 01 2c 	bne     f40 <fn_800614A8+0xf40>
     e18:	2c 16 00 01 	cmpwi   r22,1
     e1c:	40 82 00 18 	bne     e34 <fn_800614A8+0xe34>
     e20:	88 1a 00 89 	lbz     r0,137(r26)
     e24:	38 60 00 01 	li      r3,1
     e28:	54 00 06 3c 	rlwinm  r0,r0,0,24,30
     e2c:	98 1a 00 89 	stb     r0,137(r26)
     e30:	48 00 0b bc 	b       19ec <fn_800614A8+0x19ec>
     e34:	2c 16 00 03 	cmpwi   r22,3
     e38:	40 82 00 24 	bne     e5c <fn_800614A8+0xe5c>
     e3c:	7f c3 f3 78 	mr      r3,r30
     e40:	7f e4 fb 78 	mr      r4,r31
     e44:	7f a5 eb 78 	mr      r5,r29
     e48:	7f 86 e3 78 	mr      r6,r28
     e4c:	7f 47 d3 78 	mr      r7,r26
     e50:	48 00 00 01 	bl      e50 <fn_800614A8+0xe50>
			e50: R_PPC_REL24	fn_8005FD84
     e54:	38 60 00 01 	li      r3,1
     e58:	48 00 0b 94 	b       19ec <fn_800614A8+0x19ec>
     e5c:	2c 16 00 0c 	cmpwi   r22,12
     e60:	40 82 00 44 	bne     ea4 <fn_800614A8+0xea4>
     e64:	7f e3 fb 78 	mr      r3,r31
     e68:	7f a4 eb 78 	mr      r4,r29
     e6c:	7f 05 c3 78 	mr      r5,r24
     e70:	48 00 00 01 	bl      e70 <fn_800614A8+0xe70>
			e70: R_PPC_REL24	fn_80060F10
     e74:	2c 03 00 00 	cmpwi   r3,0
     e78:	40 82 00 24 	bne     e9c <fn_800614A8+0xe9c>
     e7c:	38 00 00 5a 	li      r0,90
     e80:	7f e3 fb 78 	mr      r3,r31
     e84:	b0 1b 01 50 	sth     r0,336(r27)
     e88:	38 80 00 01 	li      r4,1
     e8c:	48 00 00 01 	bl      e8c <fn_800614A8+0xe8c>
			e8c: R_PPC_REL24	fn_80201D2C
     e90:	7f e3 fb 78 	mr      r3,r31
     e94:	38 80 00 01 	li      r4,1
     e98:	48 00 00 01 	bl      e98 <fn_800614A8+0xe98>
			e98: R_PPC_REL24	fn_80201D14
     e9c:	38 60 00 01 	li      r3,1
     ea0:	48 00 0b 4c 	b       19ec <fn_800614A8+0x19ec>
     ea4:	2c 16 00 07 	cmpwi   r22,7
     ea8:	40 82 00 68 	bne     f10 <fn_800614A8+0xf10>
     eac:	7f e3 fb 78 	mr      r3,r31
     eb0:	38 95 01 b8 	addi    r4,r21,440
     eb4:	38 d5 01 cc 	addi    r6,r21,460
     eb8:	39 15 01 d8 	addi    r8,r21,472
     ebc:	38 a0 00 00 	li      r5,0
			ebc: R_PPC_EMB_SDA21	lbl_8064B508
     ec0:	38 e0 00 00 	li      r7,0
			ec0: R_PPC_EMB_SDA21	lbl_8064B510
     ec4:	48 00 00 01 	bl      ec4 <fn_800614A8+0xec4>
			ec4: R_PPC_REL24	fn_80035FB8
     ec8:	2c 03 00 00 	cmpwi   r3,0
     ecc:	40 82 00 3c 	bne     f08 <fn_800614A8+0xf08>
     ed0:	7f e3 fb 78 	mr      r3,r31
     ed4:	7f a4 eb 78 	mr      r4,r29
     ed8:	7f 05 c3 78 	mr      r5,r24
     edc:	48 00 00 01 	bl      edc <fn_800614A8+0xedc>
			edc: R_PPC_REL24	fn_80060F10
     ee0:	2c 03 00 00 	cmpwi   r3,0
     ee4:	40 82 00 24 	bne     f08 <fn_800614A8+0xf08>
     ee8:	38 00 00 5a 	li      r0,90
     eec:	7f e3 fb 78 	mr      r3,r31
     ef0:	b0 1b 01 50 	sth     r0,336(r27)
     ef4:	38 80 00 01 	li      r4,1
     ef8:	48 00 00 01 	bl      ef8 <fn_800614A8+0xef8>
			ef8: R_PPC_REL24	fn_80201D2C
     efc:	7f e3 fb 78 	mr      r3,r31
     f00:	38 80 00 01 	li      r4,1
     f04:	48 00 00 01 	bl      f04 <fn_800614A8+0xf04>
			f04: R_PPC_REL24	fn_80201D14
     f08:	38 60 00 01 	li      r3,1
     f0c:	48 00 0a e0 	b       19ec <fn_800614A8+0x19ec>
     f10:	2c 16 00 0d 	cmpwi   r22,13
     f14:	40 82 0a d8 	bne     19ec <fn_800614A8+0x19ec>
     f18:	7f e3 fb 78 	mr      r3,r31
     f1c:	38 80 00 01 	li      r4,1
     f20:	48 00 00 01 	bl      f20 <fn_800614A8+0xf20>
			f20: R_PPC_REL24	fn_80201D2C
     f24:	7f e3 fb 78 	mr      r3,r31
     f28:	38 80 00 01 	li      r4,1
     f2c:	48 00 00 01 	bl      f2c <fn_800614A8+0xf2c>
			f2c: R_PPC_REL24	fn_80201D14
     f30:	7f a3 eb 78 	mr      r3,r29
     f34:	48 00 00 01 	bl      f34 <fn_800614A8+0xf34>
			f34: R_PPC_REL24	fn_8012B344
     f38:	38 60 00 01 	li      r3,1
     f3c:	48 00 0a b0 	b       19ec <fn_800614A8+0x19ec>
     f40:	2c 17 00 5f 	cmpwi   r23,95
     f44:	40 82 00 84 	bne     fc8 <fn_800614A8+0xfc8>
     f48:	2c 16 00 03 	cmpwi   r22,3
     f4c:	40 82 00 18 	bne     f64 <fn_800614A8+0xf64>
     f50:	7f e3 fb 78 	mr      r3,r31
     f54:	7f a4 eb 78 	mr      r4,r29
     f58:	48 00 00 01 	bl      f58 <fn_800614A8+0xf58>
			f58: R_PPC_REL24	fn_800C9B74
     f5c:	38 60 00 01 	li      r3,1
     f60:	48 00 0a 8c 	b       19ec <fn_800614A8+0x19ec>
     f64:	2c 16 00 68 	cmpwi   r22,104
     f68:	40 82 00 24 	bne     f8c <fn_800614A8+0xf8c>
     f6c:	7f e3 fb 78 	mr      r3,r31
     f70:	38 80 00 01 	li      r4,1
     f74:	48 00 00 01 	bl      f74 <fn_800614A8+0xf74>
			f74: R_PPC_REL24	fn_80201D2C
     f78:	7f e3 fb 78 	mr      r3,r31
     f7c:	38 80 00 01 	li      r4,1
     f80:	48 00 00 01 	bl      f80 <fn_800614A8+0xf80>
			f80: R_PPC_REL24	fn_80201D14
     f84:	38 60 00 01 	li      r3,1
     f88:	48 00 0a 64 	b       19ec <fn_800614A8+0x19ec>
     f8c:	2c 16 00 02 	cmpwi   r22,2
     f90:	40 82 00 18 	bne     fa8 <fn_800614A8+0xfa8>
     f94:	7f e3 fb 78 	mr      r3,r31
     f98:	7f a4 eb 78 	mr      r4,r29
     f9c:	48 00 00 01 	bl      f9c <fn_800614A8+0xf9c>
			f9c: R_PPC_REL24	fn_800C9AD4
     fa0:	38 60 00 01 	li      r3,1
     fa4:	48 00 0a 48 	b       19ec <fn_800614A8+0x19ec>
     fa8:	2c 16 00 69 	cmpwi   r22,105
     fac:	40 82 00 0c 	bne     fb8 <fn_800614A8+0xfb8>
     fb0:	38 60 00 01 	li      r3,1
     fb4:	48 00 0a 38 	b       19ec <fn_800614A8+0x19ec>
     fb8:	2c 16 00 65 	cmpwi   r22,101
     fbc:	40 82 0a 30 	bne     19ec <fn_800614A8+0x19ec>
     fc0:	38 60 00 01 	li      r3,1
     fc4:	48 00 0a 28 	b       19ec <fn_800614A8+0x19ec>
     fc8:	2c 17 00 56 	cmpwi   r23,86
     fcc:	40 82 01 f8 	bne     11c4 <fn_800614A8+0x11c4>
     fd0:	2c 16 00 03 	cmpwi   r22,3
     fd4:	40 82 00 24 	bne     ff8 <fn_800614A8+0xff8>
     fd8:	7f c3 f3 78 	mr      r3,r30
     fdc:	7f e4 fb 78 	mr      r4,r31
     fe0:	7f a5 eb 78 	mr      r5,r29
     fe4:	7f 86 e3 78 	mr      r6,r28
     fe8:	7f 47 d3 78 	mr      r7,r26
     fec:	48 00 00 01 	bl      fec <fn_800614A8+0xfec>
			fec: R_PPC_REL24	fn_8005FD84
     ff0:	38 60 00 01 	li      r3,1
     ff4:	48 00 09 f8 	b       19ec <fn_800614A8+0x19ec>
     ff8:	2c 16 00 05 	cmpwi   r22,5
     ffc:	40 82 01 64 	bne     1160 <fn_800614A8+0x1160>
    1000:	7f e3 fb 78 	mr      r3,r31
    1004:	3a 00 00 00 	li      r16,0
    1008:	38 80 00 03 	li      r4,3
    100c:	48 00 00 01 	bl      100c <fn_800614A8+0x100c>
			100c: R_PPC_REL24	fn_80066D04
    1010:	2c 03 00 00 	cmpwi   r3,0
    1014:	40 82 00 1c 	bne     1030 <fn_800614A8+0x1030>
    1018:	7f e3 fb 78 	mr      r3,r31
    101c:	38 80 00 02 	li      r4,2
    1020:	48 00 00 01 	bl      1020 <fn_800614A8+0x1020>
			1020: R_PPC_REL24	fn_80066D04
    1024:	2c 03 00 00 	cmpwi   r3,0
    1028:	40 82 00 08 	bne     1030 <fn_800614A8+0x1030>
    102c:	3a 00 00 01 	li      r16,1
    1030:	7f a3 eb 78 	mr      r3,r29
    1034:	48 00 00 01 	bl      1034 <fn_800614A8+0x1034>
			1034: R_PPC_REL24	fn_8012B344
    1038:	7f e3 fb 78 	mr      r3,r31
    103c:	38 81 00 5c 	addi    r4,r1,92
    1040:	48 00 00 01 	bl      1040 <fn_800614A8+0x1040>
			1040: R_PPC_REL24	fn_802045AC
    1044:	c0 01 00 8c 	lfs     f0,140(r1)
    1048:	c0 41 00 90 	lfs     f2,144(r1)
    104c:	c0 21 00 5c 	lfs     f1,92(r1)
    1050:	fc 60 00 1e 	fctiwz  f3,f0
    1054:	c0 01 00 60 	lfs     f0,96(r1)
    1058:	fc 40 10 1e 	fctiwz  f2,f2
    105c:	fc 20 08 1e 	fctiwz  f1,f1
    1060:	fc 00 00 1e 	fctiwz  f0,f0
    1064:	d8 61 00 c0 	stfd    f3,192(r1)
    1068:	d8 41 00 c8 	stfd    f2,200(r1)
    106c:	80 61 00 c4 	lwz     r3,196(r1)
    1070:	d8 21 00 d0 	stfd    f1,208(r1)
    1074:	80 81 00 cc 	lwz     r4,204(r1)
    1078:	d8 01 00 d8 	stfd    f0,216(r1)
    107c:	80 a1 00 d4 	lwz     r5,212(r1)
    1080:	80 c1 00 dc 	lwz     r6,220(r1)
    1084:	48 00 00 01 	bl      1084 <fn_800614A8+0x1084>
			1084: R_PPC_REL24	fn_80179064
    1088:	2c 10 00 00 	cmpwi   r16,0
    108c:	40 82 00 b4 	bne     1140 <fn_800614A8+0x1140>
    1090:	3a 00 00 01 	li      r16,1
    1094:	48 00 00 01 	bl      1094 <fn_800614A8+0x1094>
			1094: R_PPC_REL24	fn_800FBFB0
    1098:	54 60 07 ff 	clrlwi. r0,r3,31
    109c:	41 82 00 80 	beq     111c <fn_800614A8+0x111c>
    10a0:	88 1a 00 89 	lbz     r0,137(r26)
    10a4:	54 00 07 ff 	clrlwi. r0,r0,31
    10a8:	41 82 00 74 	beq     111c <fn_800614A8+0x111c>
    10ac:	48 00 00 01 	bl      10ac <fn_800614A8+0x10ac>
			10ac: R_PPC_REL24	fn_801A717C
    10b0:	88 1a 00 89 	lbz     r0,137(r26)
    10b4:	7c 6f 1b 78 	mr      r15,r3
    10b8:	38 80 00 10 	li      r4,16
    10bc:	54 00 06 3c 	rlwinm  r0,r0,0,24,30
    10c0:	98 1a 00 89 	stb     r0,137(r26)
    10c4:	48 00 00 01 	bl      10c4 <fn_800614A8+0x10c4>
			10c4: R_PPC_REL24	fn_801A7470
    10c8:	7d e3 7b 78 	mr      r3,r15
    10cc:	7f c4 f3 78 	mr      r4,r30
    10d0:	48 00 00 01 	bl      10d0 <fn_800614A8+0x10d0>
			10d0: R_PPC_REL24	fn_801A74A0
    10d4:	7d e3 7b 78 	mr      r3,r15
    10d8:	7f c4 f3 78 	mr      r4,r30
    10dc:	48 00 00 01 	bl      10dc <fn_800614A8+0x10dc>
			10dc: R_PPC_REL24	fn_801A74A8
    10e0:	7d e3 7b 78 	mr      r3,r15
    10e4:	38 81 00 8c 	addi    r4,r1,140
    10e8:	48 00 00 01 	bl      10e8 <fn_800614A8+0x10e8>
			10e8: R_PPC_REL24	fn_801A764C
    10ec:	7f c4 f3 78 	mr      r4,r30
    10f0:	7f c5 f3 78 	mr      r5,r30
    10f4:	7d e6 7b 78 	mr      r6,r15
    10f8:	38 60 00 35 	li      r3,53
    10fc:	48 00 00 01 	bl      10fc <fn_800614A8+0x10fc>
			10fc: R_PPC_REL24	fn_8020123C
    1100:	38 00 ff ff 	li      r0,-1
    1104:	7d e3 7b 78 	mr      r3,r15
    1108:	7c 8f 00 38 	and     r15,r4,r0
    110c:	48 00 00 01 	bl      110c <fn_800614A8+0x110c>
			110c: R_PPC_REL24	fn_801A7228
    1110:	55 e0 07 ff 	clrlwi. r0,r15,31
    1114:	41 82 00 08 	beq     111c <fn_800614A8+0x111c>
    1118:	3a 00 00 00 	li      r16,0
    111c:	2c 10 00 00 	cmpwi   r16,0
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
    116c:	7f 64 db 78 	mr      r4,r27
    1170:	48 00 00 01 	bl      1170 <fn_800614A8+0x1170>
			1170: R_PPC_REL24	fn_800EA3A0
    1174:	7f a3 eb 78 	mr      r3,r29
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
    11a4:	7f c3 f3 78 	mr      r3,r30
    11a8:	7f c4 f3 78 	mr      r4,r30
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
    11d4:	7f c3 f3 78 	mr      r3,r30
    11d8:	7f e4 fb 78 	mr      r4,r31
    11dc:	7f a5 eb 78 	mr      r5,r29
    11e0:	7f 86 e3 78 	mr      r6,r28
    11e4:	7f 47 d3 78 	mr      r7,r26
    11e8:	48 00 00 01 	bl      11e8 <fn_800614A8+0x11e8>
			11e8: R_PPC_REL24	fn_8005FD84
    11ec:	38 60 00 01 	li      r3,1
    11f0:	48 00 07 fc 	b       19ec <fn_800614A8+0x19ec>
    11f4:	2c 16 00 05 	cmpwi   r22,5
    11f8:	40 82 00 2c 	bne     1224 <fn_800614A8+0x1224>
    11fc:	7f a3 eb 78 	mr      r3,r29
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
    1230:	7f 64 db 78 	mr      r4,r27
    1234:	48 00 00 01 	bl      1234 <fn_800614A8+0x1234>
			1234: R_PPC_REL24	fn_800EA3A0
    1238:	7f a3 eb 78 	mr      r3,r29
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
    1268:	7f c3 f3 78 	mr      r3,r30
    126c:	7f c4 f3 78 	mr      r4,r30
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
    1298:	7f c3 f3 78 	mr      r3,r30
    129c:	7f e4 fb 78 	mr      r4,r31
    12a0:	7f a5 eb 78 	mr      r5,r29
    12a4:	7f 86 e3 78 	mr      r6,r28
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
    134c:	7f c3 f3 78 	mr      r3,r30
    1350:	7f e4 fb 78 	mr      r4,r31
    1354:	7f a5 eb 78 	mr      r5,r29
    1358:	7f 86 e3 78 	mr      r6,r28
    135c:	7f 47 d3 78 	mr      r7,r26
    1360:	48 00 00 01 	bl      1360 <fn_800614A8+0x1360>
			1360: R_PPC_REL24	fn_8005FD84
    1364:	38 60 00 01 	li      r3,1
    1368:	48 00 06 84 	b       19ec <fn_800614A8+0x19ec>
    136c:	2c 16 00 05 	cmpwi   r22,5
    1370:	40 82 00 80 	bne     13f0 <fn_800614A8+0x13f0>
    1374:	7f a3 eb 78 	mr      r3,r29
    1378:	48 00 00 01 	bl      1378 <fn_800614A8+0x1378>
			1378: R_PPC_REL24	fn_80128EAC
    137c:	7c 71 1b 78 	mr      r17,r3
    1380:	7f a3 eb 78 	mr      r3,r29
    1384:	48 00 00 01 	bl      1384 <fn_800614A8+0x1384>
			1384: R_PPC_REL24	fn_801290D0
    1388:	7c 70 1b 78 	mr      r16,r3
    138c:	7f a3 eb 78 	mr      r3,r29
    1390:	48 00 00 01 	bl      1390 <fn_800614A8+0x1390>
			1390: R_PPC_REL24	fn_80128E30
    1394:	28 03 00 00 	cmplwi  r3,0
    1398:	41 82 00 38 	beq     13d0 <fn_800614A8+0x13d0>
    139c:	2c 11 00 0f 	cmpwi   r17,15
    13a0:	40 82 00 30 	bne     13d0 <fn_800614A8+0x13d0>
    13a4:	56 00 07 ff 	clrlwi. r0,r16,31
    13a8:	41 82 00 28 	beq     13d0 <fn_800614A8+0x13d0>
    13ac:	7f a3 eb 78 	mr      r3,r29
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
    1448:	7f 64 db 78 	mr      r4,r27
    144c:	48 00 00 01 	bl      144c <fn_800614A8+0x144c>
			144c: R_PPC_REL24	fn_800EA3A0
    1450:	7f e3 fb 78 	mr      r3,r31
    1454:	7f 64 db 78 	mr      r4,r27
    1458:	48 00 00 01 	bl      1458 <fn_800614A8+0x1458>
			1458: R_PPC_REL24	fn_800BD2DC
    145c:	7f c4 f3 78 	mr      r4,r30
    1460:	7f c5 f3 78 	mr      r5,r30
    1464:	38 60 00 05 	li      r3,5
    1468:	38 c0 00 00 	li      r6,0
    146c:	48 00 00 01 	bl      146c <fn_800614A8+0x146c>
			146c: R_PPC_REL24	fn_8020123C
    1470:	38 60 00 01 	li      r3,1
    1474:	48 00 05 78 	b       19ec <fn_800614A8+0x19ec>
    1478:	2c 16 00 02 	cmpwi   r22,2
    147c:	40 82 00 24 	bne     14a0 <fn_800614A8+0x14a0>
    1480:	7f c3 f3 78 	mr      r3,r30
    1484:	7f c4 f3 78 	mr      r4,r30
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
    14d0:	7f a3 eb 78 	mr      r3,r29
    14d4:	48 00 00 01 	bl      14d4 <fn_800614A8+0x14d4>
			14d4: R_PPC_REL24	fn_80128EAC
    14d8:	7f a3 eb 78 	mr      r3,r29
    14dc:	48 00 00 01 	bl      14dc <fn_800614A8+0x14dc>
			14dc: R_PPC_REL24	fn_801290D0
    14e0:	7f e3 fb 78 	mr      r3,r31
    14e4:	38 80 00 00 	li      r4,0
    14e8:	48 00 00 01 	bl      14e8 <fn_800614A8+0x14e8>
			14e8: R_PPC_REL24	fn_80201350
    14ec:	88 7c 00 9f 	lbz     r3,159(r28)
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
    1514:	7f c3 f3 78 	mr      r3,r30
    1518:	48 00 00 01 	bl      1518 <fn_800614A8+0x1518>
			1518: R_PPC_REL24	fn_800BE8D4
    151c:	7f e3 fb 78 	mr      r3,r31
    1520:	48 00 00 01 	bl      1520 <fn_800614A8+0x1520>
			1520: R_PPC_REL24	fn_800CA2C8
    1524:	38 60 00 01 	li      r3,1
    1528:	48 00 04 c4 	b       19ec <fn_800614A8+0x19ec>
    152c:	2c 16 00 03 	cmpwi   r22,3
    1530:	40 82 00 30 	bne     1560 <fn_800614A8+0x1560>
    1534:	7f a3 eb 78 	mr      r3,r29
    1538:	48 00 00 01 	bl      1538 <fn_800614A8+0x1538>
			1538: R_PPC_REL24	fn_80128EAC
    153c:	7f a3 eb 78 	mr      r3,r29
    1540:	48 00 00 01 	bl      1540 <fn_800614A8+0x1540>
			1540: R_PPC_REL24	fn_801290D0
    1544:	7f e3 fb 78 	mr      r3,r31
    1548:	7f a4 eb 78 	mr      r4,r29
    154c:	7f c5 f3 78 	mr      r5,r30
    1550:	7f 66 db 78 	mr      r6,r27
    1554:	48 00 00 01 	bl      1554 <fn_800614A8+0x1554>
			1554: R_PPC_REL24	fn_8003E5DC
    1558:	38 60 00 01 	li      r3,1
    155c:	48 00 04 90 	b       19ec <fn_800614A8+0x19ec>
    1560:	2c 16 00 3d 	cmpwi   r22,61
    1564:	40 82 00 2c 	bne     1590 <fn_800614A8+0x1590>
    1568:	7f e3 fb 78 	mr      r3,r31
    156c:	7f 64 db 78 	mr      r4,r27
    1570:	48 00 00 01 	bl      1570 <fn_800614A8+0x1570>
			1570: R_PPC_REL24	fn_800EA3A0
    1574:	7f c4 f3 78 	mr      r4,r30
    1578:	7f c5 f3 78 	mr      r5,r30
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
    15a0:	7f a3 eb 78 	mr      r3,r29
    15a4:	7f 84 e3 78 	mr      r4,r28
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
    15ec:	7f a4 eb 78 	mr      r4,r29
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
    1620:	7f 64 db 78 	mr      r4,r27
    1624:	48 00 00 01 	bl      1624 <fn_800614A8+0x1624>
			1624: R_PPC_REL24	fn_800EA3A0
    1628:	7f e3 fb 78 	mr      r3,r31
    162c:	48 00 00 01 	bl      162c <fn_800614A8+0x162c>
			162c: R_PPC_REL24	fn_800CF598
    1630:	c0 20 00 00 	lfs     f1,0(0)
			1630: R_PPC_EMB_SDA21	lbl_8064E62C
    1634:	7f a3 eb 78 	mr      r3,r29
    1638:	c0 40 00 00 	lfs     f2,0(0)
			1638: R_PPC_EMB_SDA21	lbl_8064E5DC
    163c:	38 80 00 00 	li      r4,0
    1640:	38 a0 00 00 	li      r5,0
    1644:	38 c0 01 01 	li      r6,257
    1648:	48 00 00 01 	bl      1648 <fn_800614A8+0x1648>
			1648: R_PPC_REL24	fn_80120AD0
    164c:	7f a3 eb 78 	mr      r3,r29
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
    16ac:	7f c4 f3 78 	mr      r4,r30
    16b0:	7f c5 f3 78 	mr      r5,r30
    16b4:	38 60 00 2f 	li      r3,47
    16b8:	38 c0 00 00 	li      r6,0
    16bc:	48 00 00 01 	bl      16bc <fn_800614A8+0x16bc>
			16bc: R_PPC_REL24	fn_8020123C
    16c0:	c0 20 00 00 	lfs     f1,0(0)
			16c0: R_PPC_EMB_SDA21	lbl_8064E630
    16c4:	7f c4 f3 78 	mr      r4,r30
    16c8:	7f c5 f3 78 	mr      r5,r30
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
    1708:	7f a3 eb 78 	mr      r3,r29
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
    1740:	7f c4 f3 78 	mr      r4,r30
    1744:	7f c5 f3 78 	mr      r5,r30
    1748:	38 60 00 39 	li      r3,57
    174c:	38 c0 00 00 	li      r6,0
    1750:	48 00 00 01 	bl      1750 <fn_800614A8+0x1750>
			1750: R_PPC_REL24	fn_8020123C
    1754:	38 60 00 01 	li      r3,1
    1758:	48 00 02 94 	b       19ec <fn_800614A8+0x19ec>
    175c:	2c 16 00 02 	cmpwi   r22,2
    1760:	40 82 00 24 	bne     1784 <fn_800614A8+0x1784>
    1764:	7f c3 f3 78 	mr      r3,r30
    1768:	7f c4 f3 78 	mr      r4,r30
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
    1814:	7f a3 eb 78 	mr      r3,r29
    1818:	48 00 00 01 	bl      1818 <fn_800614A8+0x1818>
			1818: R_PPC_REL24	fn_80128EAC
    181c:	7f a3 eb 78 	mr      r3,r29
    1820:	48 00 00 01 	bl      1820 <fn_800614A8+0x1820>
			1820: R_PPC_REL24	fn_801290D0
    1824:	7f c3 f3 78 	mr      r3,r30
    1828:	48 00 00 01 	bl      1828 <fn_800614A8+0x1828>
			1828: R_PPC_REL24	fn_800BE8D4
    182c:	7f e3 fb 78 	mr      r3,r31
    1830:	38 80 00 02 	li      r4,2
    1834:	38 a0 00 03 	li      r5,3
    1838:	48 00 00 01 	bl      1838 <fn_800614A8+0x1838>
			1838: R_PPC_REL24	fn_800CC860
    183c:	7f a3 eb 78 	mr      r3,r29
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
    185c:	7f c4 f3 78 	mr      r4,r30
    1860:	7f c5 f3 78 	mr      r5,r30
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
    18ac:	7f a4 eb 78 	mr      r4,r29
    18b0:	7f c5 f3 78 	mr      r5,r30
    18b4:	48 00 00 01 	bl      18b4 <fn_800614A8+0x18b4>
			18b4: R_PPC_REL24	fn_8003C114
    18b8:	38 60 00 01 	li      r3,1
    18bc:	48 00 01 30 	b       19ec <fn_800614A8+0x19ec>
    18c0:	2c 16 00 3d 	cmpwi   r22,61
    18c4:	40 82 00 2c 	bne     18f0 <fn_800614A8+0x18f0>
    18c8:	7f e3 fb 78 	mr      r3,r31
    18cc:	7f 64 db 78 	mr      r4,r27
    18d0:	48 00 00 01 	bl      18d0 <fn_800614A8+0x18d0>
			18d0: R_PPC_REL24	fn_800EA3A0
    18d4:	7f c4 f3 78 	mr      r4,r30
    18d8:	7f c5 f3 78 	mr      r5,r30
    18dc:	38 60 00 39 	li      r3,57
    18e0:	38 c0 00 00 	li      r6,0
    18e4:	48 00 00 01 	bl      18e4 <fn_800614A8+0x18e4>
			18e4: R_PPC_REL24	fn_8020123C
    18e8:	38 60 00 01 	li      r3,1
    18ec:	48 00 01 00 	b       19ec <fn_800614A8+0x19ec>
    18f0:	2c 16 00 11 	cmpwi   r22,17
    18f4:	40 82 00 54 	bne     1948 <fn_800614A8+0x1948>
    18f8:	7f e3 fb 78 	mr      r3,r31
    18fc:	7f 64 db 78 	mr      r4,r27
    1900:	48 00 00 01 	bl      1900 <fn_800614A8+0x1900>
			1900: R_PPC_REL24	fn_800EA3A0
    1904:	7f e3 fb 78 	mr      r3,r31
    1908:	48 00 00 01 	bl      1908 <fn_800614A8+0x1908>
			1908: R_PPC_REL24	fn_800CF598
    190c:	c0 20 00 00 	lfs     f1,0(0)
			190c: R_PPC_EMB_SDA21	lbl_8064E62C
    1910:	7f a3 eb 78 	mr      r3,r29
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
    19ec:	b9 e1 00 ec 	lmw     r15,236(r1)
    19f0:	80 01 01 34 	lwz     r0,308(r1)
    19f4:	7c 08 03 a6 	mtlr    r0
    19f8:	38 21 01 30 	addi    r1,r1,304
    19fc:	4e 80 00 20 	blr

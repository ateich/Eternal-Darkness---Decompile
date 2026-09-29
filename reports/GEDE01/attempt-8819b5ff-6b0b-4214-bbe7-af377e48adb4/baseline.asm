
build/GEDE01/src/game/game_fn_800614A8.o:     file format elf32-powerpc


Disassembly of section .text:

00000000 <fn_800614A8>:
       0:	94 21 ff 10 	stwu    r1,-240(r1)
       4:	7c 08 02 a6 	mflr    r0
       8:	3c e0 00 00 	lis     r7,0
			a: R_PPC_ADDR16_HA	lbl_80243C30
       c:	90 01 00 f4 	stw     r0,244(r1)
      10:	bd e1 00 ac 	stmw    r15,172(r1)
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
      7c:	38 61 00 18 	addi    r3,r1,24
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
     1c4:	2c 17 00 15 	cmpwi   r23,21
     1c8:	41 82 0a 24 	beq     bec <fn_800614A8+0xbec>
     1cc:	40 80 00 4c 	bge     218 <fn_800614A8+0x218>
     1d0:	2c 17 00 03 	cmpwi   r23,3
     1d4:	41 82 0c 7c 	beq     e50 <fn_800614A8+0xe50>
     1d8:	40 80 00 1c 	bge     1f4 <fn_800614A8+0x1f4>
     1dc:	2c 17 00 01 	cmpwi   r23,1
     1e0:	41 82 07 e4 	beq     9c4 <fn_800614A8+0x9c4>
     1e4:	40 80 19 44 	bge     1b28 <fn_800614A8+0x1b28>
     1e8:	2c 17 00 00 	cmpwi   r23,0
     1ec:	40 80 00 68 	bge     254 <fn_800614A8+0x254>
     1f0:	48 00 19 38 	b       1b28 <fn_800614A8+0x1b28>
     1f4:	2c 17 00 07 	cmpwi   r23,7
     1f8:	41 82 11 68 	beq     1360 <fn_800614A8+0x1360>
     1fc:	40 80 00 10 	bge     20c <fn_800614A8+0x20c>
     200:	2c 17 00 06 	cmpwi   r23,6
     204:	40 80 0c f4 	bge     ef8 <fn_800614A8+0xef8>
     208:	48 00 19 20 	b       1b28 <fn_800614A8+0x1b28>
     20c:	2c 17 00 09 	cmpwi   r23,9
     210:	40 80 19 18 	bge     1b28 <fn_800614A8+0x1b28>
     214:	48 00 13 a4 	b       15b8 <fn_800614A8+0x15b8>
     218:	2c 17 00 56 	cmpwi   r23,86
     21c:	41 82 0e 90 	beq     10ac <fn_800614A8+0x10ac>
     220:	40 80 00 1c 	bge     23c <fn_800614A8+0x23c>
     224:	2c 17 00 20 	cmpwi   r23,32
     228:	41 82 11 f4 	beq     141c <fn_800614A8+0x141c>
     22c:	40 80 18 fc 	bge     1b28 <fn_800614A8+0x1b28>
     230:	2c 17 00 1f 	cmpwi   r23,31
     234:	40 80 16 ec 	bge     1920 <fn_800614A8+0x1920>
     238:	48 00 18 f0 	b       1b28 <fn_800614A8+0x1b28>
     23c:	2c 17 00 5f 	cmpwi   r23,95
     240:	41 82 0d d8 	beq     1018 <fn_800614A8+0x1018>
     244:	40 80 18 e4 	bge     1b28 <fn_800614A8+0x1b28>
     248:	2c 17 00 59 	cmpwi   r23,89
     24c:	41 82 10 48 	beq     1294 <fn_800614A8+0x1294>
     250:	48 00 18 d8 	b       1b28 <fn_800614A8+0x1b28>
     254:	2c 16 00 65 	cmpwi   r22,101
     258:	41 82 04 24 	beq     67c <fn_800614A8+0x67c>
     25c:	40 80 00 98 	bge     2f4 <fn_800614A8+0x2f4>
     260:	2c 16 00 32 	cmpwi   r22,50
     264:	41 82 05 40 	beq     7a4 <fn_800614A8+0x7a4>
     268:	40 80 00 40 	bge     2a8 <fn_800614A8+0x2a8>
     26c:	2c 16 00 0b 	cmpwi   r22,11
     270:	41 82 03 b8 	beq     628 <fn_800614A8+0x628>
     274:	40 80 00 1c 	bge     290 <fn_800614A8+0x290>
     278:	2c 16 00 08 	cmpwi   r22,8
     27c:	41 82 01 ac 	beq     428 <fn_800614A8+0x428>
     280:	40 80 18 ac 	bge     1b2c <fn_800614A8+0x1b2c>
     284:	2c 16 00 01 	cmpwi   r22,1
     288:	41 82 00 fc 	beq     384 <fn_800614A8+0x384>
     28c:	48 00 18 a0 	b       1b2c <fn_800614A8+0x1b2c>
     290:	2c 16 00 27 	cmpwi   r22,39
     294:	41 82 04 84 	beq     718 <fn_800614A8+0x718>
     298:	40 80 18 94 	bge     1b2c <fn_800614A8+0x1b2c>
     29c:	2c 16 00 0e 	cmpwi   r22,14
     2a0:	41 82 04 64 	beq     704 <fn_800614A8+0x704>
     2a4:	48 00 18 88 	b       1b2c <fn_800614A8+0x1b2c>
     2a8:	2c 16 00 3c 	cmpwi   r22,60
     2ac:	41 82 18 80 	beq     1b2c <fn_800614A8+0x1b2c>
     2b0:	40 80 00 28 	bge     2d8 <fn_800614A8+0x2d8>
     2b4:	2c 16 00 39 	cmpwi   r22,57
     2b8:	41 82 03 f4 	beq     6ac <fn_800614A8+0x6ac>
     2bc:	40 80 00 10 	bge     2cc <fn_800614A8+0x2cc>
     2c0:	2c 16 00 35 	cmpwi   r22,53
     2c4:	41 82 05 18 	beq     7dc <fn_800614A8+0x7dc>
     2c8:	48 00 18 64 	b       1b2c <fn_800614A8+0x1b2c>
     2cc:	2c 16 00 3b 	cmpwi   r22,59
     2d0:	40 80 04 60 	bge     730 <fn_800614A8+0x730>
     2d4:	48 00 03 04 	b       5d8 <fn_800614A8+0x5d8>
     2d8:	2c 16 00 4e 	cmpwi   r22,78
     2dc:	41 82 04 90 	beq     76c <fn_800614A8+0x76c>
     2e0:	40 80 18 4c 	bge     1b2c <fn_800614A8+0x1b2c>
     2e4:	2c 16 00 3e 	cmpwi   r22,62
     2e8:	41 82 01 94 	beq     47c <fn_800614A8+0x47c>
     2ec:	40 80 18 40 	bge     1b2c <fn_800614A8+0x1b2c>
     2f0:	48 00 01 6c 	b       45c <fn_800614A8+0x45c>
     2f4:	2c 16 00 ea 	cmpwi   r22,234
     2f8:	41 82 05 68 	beq     860 <fn_800614A8+0x860>
     2fc:	40 80 00 40 	bge     33c <fn_800614A8+0x33c>
     300:	2c 16 00 c9 	cmpwi   r22,201
     304:	41 82 02 1c 	beq     520 <fn_800614A8+0x520>
     308:	40 80 00 1c 	bge     324 <fn_800614A8+0x324>
     30c:	2c 16 00 82 	cmpwi   r22,130
     310:	41 82 04 7c 	beq     78c <fn_800614A8+0x78c>
     314:	40 80 18 18 	bge     1b2c <fn_800614A8+0x1b2c>
     318:	2c 16 00 67 	cmpwi   r22,103
     31c:	41 82 02 54 	beq     570 <fn_800614A8+0x570>
     320:	48 00 18 0c 	b       1b2c <fn_800614A8+0x1b2c>
     324:	2c 16 00 e6 	cmpwi   r22,230
     328:	41 82 04 90 	beq     7b8 <fn_800614A8+0x7b8>
     32c:	40 80 18 00 	bge     1b2c <fn_800614A8+0x1b2c>
     330:	2c 16 00 df 	cmpwi   r22,223
     334:	41 82 00 d8 	beq     40c <fn_800614A8+0x40c>
     338:	48 00 17 f4 	b       1b2c <fn_800614A8+0x1b2c>
     33c:	2c 16 00 f2 	cmpwi   r22,242
     340:	41 82 17 ec 	beq     1b2c <fn_800614A8+0x1b2c>
     344:	40 80 00 28 	bge     36c <fn_800614A8+0x36c>
     348:	2c 16 00 ed 	cmpwi   r22,237
     34c:	41 82 02 3c 	beq     588 <fn_800614A8+0x588>
     350:	40 80 00 10 	bge     360 <fn_800614A8+0x360>
     354:	2c 16 00 ec 	cmpwi   r22,236
     358:	40 80 17 d4 	bge     1b2c <fn_800614A8+0x1b2c>
     35c:	48 00 06 2c 	b       988 <fn_800614A8+0x988>
     360:	2c 16 00 f1 	cmpwi   r22,241
     364:	40 80 00 68 	bge     3cc <fn_800614A8+0x3cc>
     368:	48 00 17 c4 	b       1b2c <fn_800614A8+0x1b2c>
     36c:	2c 16 00 f5 	cmpwi   r22,245
     370:	41 82 00 7c 	beq     3ec <fn_800614A8+0x3ec>
     374:	40 80 17 b8 	bge     1b2c <fn_800614A8+0x1b2c>
     378:	2c 16 00 f4 	cmpwi   r22,244
     37c:	40 80 17 b0 	bge     1b2c <fn_800614A8+0x1b2c>
     380:	48 00 06 1c 	b       99c <fn_800614A8+0x99c>
     384:	48 00 00 01 	bl      384 <fn_800614A8+0x384>
			384: R_PPC_REL24	fn_800FBFB0
     388:	54 66 0f fe 	srwi    r6,r3,31
     38c:	54 60 e8 04 	slwi    r0,r3,29
     390:	7c 86 00 50 	subf    r4,r6,r0
     394:	7f e3 fb 78 	mr      r3,r31
     398:	54 85 1f 7e 	srwi    r5,r4,29
     39c:	38 00 00 1e 	li      r0,30
     3a0:	50 85 18 38 	rlwimi  r5,r4,3,0,28
     3a4:	38 80 00 01 	li      r4,1
     3a8:	7c a6 2a 14 	add     r5,r6,r5
     3ac:	90 ba 00 78 	stw     r5,120(r26)
     3b0:	b0 1a 00 86 	sth     r0,134(r26)
     3b4:	48 00 00 01 	bl      3b4 <fn_800614A8+0x3b4>
			3b4: R_PPC_REL24	fn_80201D2C
     3b8:	7f e3 fb 78 	mr      r3,r31
     3bc:	38 80 00 01 	li      r4,1
     3c0:	48 00 00 01 	bl      3c0 <fn_800614A8+0x3c0>
			3c0: R_PPC_REL24	fn_80201D14
     3c4:	38 60 00 01 	li      r3,1
     3c8:	48 00 17 64 	b       1b2c <fn_800614A8+0x1b2c>
     3cc:	7e 63 9b 78 	mr      r3,r19
     3d0:	7f e4 fb 78 	mr      r4,r31
     3d4:	7f c5 f3 78 	mr      r5,r30
     3d8:	7f 66 db 78 	mr      r6,r27
     3dc:	7f 07 c3 78 	mr      r7,r24
     3e0:	48 00 00 01 	bl      3e0 <fn_800614A8+0x3e0>
			3e0: R_PPC_REL24	fn_8005EC6C
     3e4:	38 60 00 01 	li      r3,1
     3e8:	48 00 17 44 	b       1b2c <fn_800614A8+0x1b2c>
     3ec:	7e 63 9b 78 	mr      r3,r19
     3f0:	7f e4 fb 78 	mr      r4,r31
     3f4:	7f c5 f3 78 	mr      r5,r30
     3f8:	7f 66 db 78 	mr      r6,r27
     3fc:	7f 07 c3 78 	mr      r7,r24
     400:	48 00 00 01 	bl      400 <fn_800614A8+0x400>
			400: R_PPC_REL24	fn_8005EC6C
     404:	38 60 00 01 	li      r3,1
     408:	48 00 17 24 	b       1b2c <fn_800614A8+0x1b2c>
     40c:	7e 63 9b 78 	mr      r3,r19
     410:	7f e4 fb 78 	mr      r4,r31
     414:	7f 05 c3 78 	mr      r5,r24
     418:	38 c1 00 18 	addi    r6,r1,24
     41c:	48 00 00 01 	bl      41c <fn_800614A8+0x41c>
			41c: R_PPC_REL24	fn_8005EA38
     420:	38 60 00 01 	li      r3,1
     424:	48 00 17 08 	b       1b2c <fn_800614A8+0x1b2c>
     428:	80 00 00 00 	lwz     r0,0(0)
			428: R_PPC_EMB_SDA21	lbl_8064D18C
     42c:	7c 13 00 00 	cmpw    r19,r0
     430:	41 82 00 14 	beq     444 <fn_800614A8+0x444>
     434:	7f e4 fb 78 	mr      r4,r31
     438:	38 60 00 02 	li      r3,2
     43c:	48 00 00 01 	bl      43c <fn_800614A8+0x43c>
			43c: R_PPC_REL24	fn_801E8328
     440:	48 00 00 14 	b       454 <fn_800614A8+0x454>
     444:	7f e3 fb 78 	mr      r3,r31
     448:	7f 04 c3 78 	mr      r4,r24
     44c:	38 a0 03 c0 	li      r5,960
     450:	48 00 00 01 	bl      450 <fn_800614A8+0x450>
			450: R_PPC_REL24	fn_800CD094
     454:	38 60 00 01 	li      r3,1
     458:	48 00 16 d4 	b       1b2c <fn_800614A8+0x1b2c>
     45c:	7f e3 fb 78 	mr      r3,r31
     460:	7f a4 eb 78 	mr      r4,r29
     464:	48 00 00 01 	bl      464 <fn_800614A8+0x464>
			464: R_PPC_REL24	fn_800EA3A0
     468:	7f e3 fb 78 	mr      r3,r31
     46c:	7f a4 eb 78 	mr      r4,r29
     470:	48 00 00 01 	bl      470 <fn_800614A8+0x470>
			470: R_PPC_REL24	fn_800BD2DC
     474:	38 60 00 01 	li      r3,1
     478:	48 00 16 b4 	b       1b2c <fn_800614A8+0x1b2c>
     47c:	7f e3 fb 78 	mr      r3,r31
     480:	48 00 00 01 	bl      480 <fn_800614A8+0x480>
			480: R_PPC_REL24	fn_80036D5C
     484:	54 60 01 09 	rlwinm. r0,r3,0,4,4
     488:	7c 64 1b 78 	mr      r4,r3
     48c:	41 82 00 68 	beq     4f4 <fn_800614A8+0x4f4>
     490:	7f e3 fb 78 	mr      r3,r31
     494:	54 84 01 46 	rlwinm  r4,r4,0,5,3
     498:	48 00 00 01 	bl      498 <fn_800614A8+0x498>
			498: R_PPC_REL24	fn_80036DA4
     49c:	7f c3 f3 78 	mr      r3,r30
     4a0:	48 00 00 01 	bl      4a0 <fn_800614A8+0x4a0>
			4a0: R_PPC_REL24	fn_801261F4
     4a4:	81 20 00 00 	lwz     r9,0(0)
			4a4: R_PPC_EMB_SDA21	lbl_80651954
     4a8:	38 e1 00 78 	addi    r7,r1,120
     4ac:	80 00 00 00 	lwz     r0,0(0)
			4ac: R_PPC_EMB_SDA21	lbl_8064E610
     4b0:	38 c1 00 80 	addi    r6,r1,128
     4b4:	81 40 00 00 	lwz     r10,0(0)
			4b4: R_PPC_EMB_SDA21	lbl_8064E60C
     4b8:	38 a1 00 88 	addi    r5,r1,136
     4bc:	90 01 00 74 	stw     r0,116(r1)
     4c0:	7f c3 f3 78 	mr      r3,r30
     4c4:	38 80 00 0f 	li      r4,15
     4c8:	39 00 00 04 	li      r8,4
     4cc:	90 01 00 78 	stw     r0,120(r1)
     4d0:	91 21 00 7c 	stw     r9,124(r1)
     4d4:	91 21 00 80 	stw     r9,128(r1)
     4d8:	91 41 00 84 	stw     r10,132(r1)
     4dc:	91 41 00 88 	stw     r10,136(r1)
     4e0:	48 00 00 01 	bl      4e0 <fn_800614A8+0x4e0>
			4e0: R_PPC_REL24	fn_8012C62C
     4e4:	7f c3 f3 78 	mr      r3,r30
     4e8:	38 80 00 00 	li      r4,0
     4ec:	38 a0 01 00 	li      r5,256
     4f0:	48 00 00 01 	bl      4f0 <fn_800614A8+0x4f0>
			4f0: R_PPC_REL24	fn_8011FA8C
     4f4:	7f e3 fb 78 	mr      r3,r31
     4f8:	7f a4 eb 78 	mr      r4,r29
     4fc:	48 00 00 01 	bl      4fc <fn_800614A8+0x4fc>
			4fc: R_PPC_REL24	fn_800BD194
     500:	7f e3 fb 78 	mr      r3,r31
     504:	48 00 00 01 	bl      504 <fn_800614A8+0x504>
			504: R_PPC_REL24	fn_800C9E50
     508:	38 00 00 00 	li      r0,0
     50c:	7f 83 e3 78 	mr      r3,r28
     510:	98 1a 00 88 	stb     r0,136(r26)
     514:	48 00 00 01 	bl      514 <fn_800614A8+0x514>
			514: R_PPC_REL24	fn_801D14CC
     518:	38 60 00 01 	li      r3,1
     51c:	48 00 16 10 	b       1b2c <fn_800614A8+0x1b2c>
     520:	48 00 00 01 	bl      520 <fn_800614A8+0x520>
			520: R_PPC_REL24	fn_8011FF38
     524:	2c 03 00 00 	cmpwi   r3,0
     528:	41 82 00 40 	beq     568 <fn_800614A8+0x568>
     52c:	7f c3 f3 78 	mr      r3,r30
     530:	38 80 00 00 	li      r4,0
     534:	3c a0 20 00 	lis     r5,8192
     538:	48 00 00 01 	bl      538 <fn_800614A8+0x538>
			538: R_PPC_REL24	fn_8011FA8C
     53c:	80 00 00 00 	lwz     r0,0(0)
			53c: R_PPC_EMB_SDA21	lbl_8064D18C
     540:	38 c1 00 18 	addi    r6,r1,24
     544:	c0 20 00 00 	lfs     f1,0(0)
			544: R_PPC_EMB_SDA21	lbl_8064E5BC
     548:	38 60 01 f1 	li      r3,497
     54c:	54 0a 04 3e 	clrlwi  r10,r0,16
     550:	38 80 00 64 	li      r4,100
     554:	38 a0 00 00 	li      r5,0
     558:	38 e0 00 02 	li      r7,2
     55c:	39 00 00 02 	li      r8,2
     560:	39 20 00 00 	li      r9,0
     564:	48 00 00 01 	bl      564 <fn_800614A8+0x564>
			564: R_PPC_REL24	fn_801AAE68
     568:	38 60 00 01 	li      r3,1
     56c:	48 00 15 c0 	b       1b2c <fn_800614A8+0x1b2c>
     570:	7f e3 fb 78 	mr      r3,r31
     574:	7f c4 f3 78 	mr      r4,r30
     578:	7f 05 c3 78 	mr      r5,r24
     57c:	48 00 00 01 	bl      57c <fn_800614A8+0x57c>
			57c: R_PPC_REL24	fn_800C9B08
     580:	38 60 00 01 	li      r3,1
     584:	48 00 15 a8 	b       1b2c <fn_800614A8+0x1b2c>
     588:	7f 03 c3 78 	mr      r3,r24
     58c:	48 00 00 01 	bl      58c <fn_800614A8+0x58c>
			58c: R_PPC_REL24	fn_80200C38
     590:	7c 60 1b 78 	mr      r0,r3
     594:	7f 03 c3 78 	mr      r3,r24
     598:	7c 10 03 78 	mr      r16,r0
     59c:	48 00 00 01 	bl      59c <fn_800614A8+0x59c>
			59c: R_PPC_REL24	fn_80200C28
     5a0:	7c 60 1b 78 	mr      r0,r3
     5a4:	7f 03 c3 78 	mr      r3,r24
     5a8:	7c 0f 03 78 	mr      r15,r0
     5ac:	48 00 00 01 	bl      5ac <fn_800614A8+0x5ac>
			5ac: R_PPC_REL24	fn_80200C20
     5b0:	7c 64 1b 78 	mr      r4,r3
     5b4:	7d e5 7b 78 	mr      r5,r15
     5b8:	7e 06 83 78 	mr      r6,r16
     5bc:	38 60 00 0b 	li      r3,11
     5c0:	48 00 00 01 	bl      5c0 <fn_800614A8+0x5c0>
			5c0: R_PPC_REL24	fn_8020123C
     5c4:	7f 03 c3 78 	mr      r3,r24
     5c8:	48 00 00 01 	bl      5c8 <fn_800614A8+0x5c8>
			5c8: R_PPC_REL24	fn_80200C38
     5cc:	48 00 00 01 	bl      5cc <fn_800614A8+0x5cc>
			5cc: R_PPC_REL24	fn_801A7228
     5d0:	38 60 00 01 	li      r3,1
     5d4:	48 00 15 58 	b       1b2c <fn_800614A8+0x1b2c>
     5d8:	7f 03 c3 78 	mr      r3,r24
     5dc:	48 00 00 01 	bl      5dc <fn_800614A8+0x5dc>
			5dc: R_PPC_REL24	fn_80200C38
     5e0:	7c 60 1b 78 	mr      r0,r3
     5e4:	7f 03 c3 78 	mr      r3,r24
     5e8:	7c 10 03 78 	mr      r16,r0
     5ec:	48 00 00 01 	bl      5ec <fn_800614A8+0x5ec>
			5ec: R_PPC_REL24	fn_80200C28
     5f0:	7c 60 1b 78 	mr      r0,r3
     5f4:	7f 03 c3 78 	mr      r3,r24
     5f8:	7c 0f 03 78 	mr      r15,r0
     5fc:	48 00 00 01 	bl      5fc <fn_800614A8+0x5fc>
			5fc: R_PPC_REL24	fn_80200C20
     600:	7c 64 1b 78 	mr      r4,r3
     604:	7d e5 7b 78 	mr      r5,r15
     608:	7e 06 83 78 	mr      r6,r16
     60c:	38 60 00 27 	li      r3,39
     610:	48 00 00 01 	bl      610 <fn_800614A8+0x610>
			610: R_PPC_REL24	fn_8020123C
     614:	7f 03 c3 78 	mr      r3,r24
     618:	48 00 00 01 	bl      618 <fn_800614A8+0x618>
			618: R_PPC_REL24	fn_80200C38
     61c:	48 00 00 01 	bl      61c <fn_800614A8+0x61c>
			61c: R_PPC_REL24	fn_801A7228
     620:	38 60 00 01 	li      r3,1
     624:	48 00 15 08 	b       1b2c <fn_800614A8+0x1b2c>
     628:	48 00 00 01 	bl      628 <fn_800614A8+0x628>
			628: R_PPC_REL24	fn_80201B9C
     62c:	38 60 00 20 	li      r3,32
     630:	48 00 00 01 	bl      630 <fn_800614A8+0x630>
			630: R_PPC_REL24	fn_80204844
     634:	48 00 00 01 	bl      634 <fn_800614A8+0x634>
			634: R_PPC_REL24	fn_8006D444
     638:	3c 60 00 08 	lis     r3,8
     63c:	38 80 00 00 	li      r4,0
     640:	48 00 00 01 	bl      640 <fn_800614A8+0x640>
			640: R_PPC_REL24	fn_8006D344
     644:	2c 03 00 00 	cmpwi   r3,0
     648:	41 82 00 14 	beq     65c <fn_800614A8+0x65c>
     64c:	7f e3 fb 78 	mr      r3,r31
     650:	48 00 00 01 	bl      650 <fn_800614A8+0x650>
			650: R_PPC_REL24	fn_80067180
     654:	38 60 00 01 	li      r3,1
     658:	48 00 00 10 	b       668 <fn_800614A8+0x668>
     65c:	7f 03 c3 78 	mr      r3,r24
     660:	48 00 00 01 	bl      660 <fn_800614A8+0x660>
			660: R_PPC_REL24	fn_80200C38
     664:	48 00 00 01 	bl      664 <fn_800614A8+0x664>
			664: R_PPC_REL24	fn_800654F8
     668:	28 19 00 00 	cmplwi  r25,0
     66c:	41 82 00 08 	beq     674 <fn_800614A8+0x674>
     670:	90 79 00 00 	stw     r3,0(r25)
     674:	38 60 00 01 	li      r3,1
     678:	48 00 14 b4 	b       1b2c <fn_800614A8+0x1b2c>
     67c:	7f 03 c3 78 	mr      r3,r24
     680:	48 00 00 01 	bl      680 <fn_800614A8+0x680>
			680: R_PPC_REL24	fn_80200C20
     684:	48 00 00 01 	bl      684 <fn_800614A8+0x684>
			684: R_PPC_REL24	fn_80201814
     688:	7c 64 1b 78 	mr      r4,r3
     68c:	7f e3 fb 78 	mr      r3,r31
     690:	48 00 00 01 	bl      690 <fn_800614A8+0x690>
			690: R_PPC_REL24	fn_800359A0
     694:	28 19 00 00 	cmplwi  r25,0
     698:	41 82 00 0c 	beq     6a4 <fn_800614A8+0x6a4>
     69c:	38 00 00 01 	li      r0,1
     6a0:	90 19 00 00 	stw     r0,0(r25)
     6a4:	38 60 00 01 	li      r3,1
     6a8:	48 00 14 84 	b       1b2c <fn_800614A8+0x1b2c>
     6ac:	7f e3 fb 78 	mr      r3,r31
     6b0:	48 00 00 01 	bl      6b0 <fn_800614A8+0x6b0>
			6b0: R_PPC_REL24	fn_800CA2C8
     6b4:	7f e3 fb 78 	mr      r3,r31
     6b8:	7f a4 eb 78 	mr      r4,r29
     6bc:	48 00 00 01 	bl      6bc <fn_800614A8+0x6bc>
			6bc: R_PPC_REL24	fn_800EA3A0
     6c0:	7f c3 f3 78 	mr      r3,r30
     6c4:	48 00 00 01 	bl      6c4 <fn_800614A8+0x6c4>
			6c4: R_PPC_REL24	fn_8012B324
     6c8:	7f c3 f3 78 	mr      r3,r30
     6cc:	38 80 00 c0 	li      r4,192
     6d0:	38 a0 00 00 	li      r5,0
     6d4:	48 00 00 01 	bl      6d4 <fn_800614A8+0x6d4>
			6d4: R_PPC_REL24	fn_8011FA8C
     6d8:	7f e3 fb 78 	mr      r3,r31
     6dc:	38 80 00 00 	li      r4,0
     6e0:	48 00 00 01 	bl      6e0 <fn_800614A8+0x6e0>
			6e0: R_PPC_REL24	fn_80201D34
     6e4:	7f e3 fb 78 	mr      r3,r31
     6e8:	38 80 00 01 	li      r4,1
     6ec:	48 00 00 01 	bl      6ec <fn_800614A8+0x6ec>
			6ec: R_PPC_REL24	fn_80201D1C
     6f0:	7f e4 fb 78 	mr      r4,r31
     6f4:	38 60 00 02 	li      r3,2
     6f8:	48 00 00 01 	bl      6f8 <fn_800614A8+0x6f8>
			6f8: R_PPC_REL24	fn_801E8328
     6fc:	38 60 00 01 	li      r3,1
     700:	48 00 14 2c 	b       1b2c <fn_800614A8+0x1b2c>
     704:	7f e3 fb 78 	mr      r3,r31
     708:	7f 04 c3 78 	mr      r4,r24
     70c:	48 00 00 01 	bl      70c <fn_800614A8+0x70c>
			70c: R_PPC_REL24	fn_80068994
     710:	38 60 00 01 	li      r3,1
     714:	48 00 14 18 	b       1b2c <fn_800614A8+0x1b2c>
     718:	7f e3 fb 78 	mr      r3,r31
     71c:	7f 04 c3 78 	mr      r4,r24
     720:	7f 25 cb 78 	mr      r5,r25
     724:	48 00 00 01 	bl      724 <fn_800614A8+0x724>
			724: R_PPC_REL24	fn_80064B38
     728:	38 60 00 01 	li      r3,1
     72c:	48 00 14 00 	b       1b2c <fn_800614A8+0x1b2c>
     730:	7f 03 c3 78 	mr      r3,r24
     734:	39 e0 00 01 	li      r15,1
     738:	48 00 00 01 	bl      738 <fn_800614A8+0x738>
			738: R_PPC_REL24	fn_80200C20
     73c:	48 00 00 01 	bl      73c <fn_800614A8+0x73c>
			73c: R_PPC_REL24	fn_80201814
     740:	28 03 00 00 	cmplwi  r3,0
     744:	41 82 00 14 	beq     758 <fn_800614A8+0x758>
     748:	48 00 00 01 	bl      748 <fn_800614A8+0x748>
			748: R_PPC_REL24	fn_80036E50
     74c:	2c 03 00 06 	cmpwi   r3,6
     750:	40 82 00 08 	bne     758 <fn_800614A8+0x758>
     754:	39 e0 00 00 	li      r15,0
     758:	28 19 00 00 	cmplwi  r25,0
     75c:	41 82 00 08 	beq     764 <fn_800614A8+0x764>
     760:	91 f9 00 00 	stw     r15,0(r25)
     764:	38 60 00 01 	li      r3,1
     768:	48 00 13 c4 	b       1b2c <fn_800614A8+0x1b2c>
     76c:	28 19 00 00 	cmplwi  r25,0
     770:	41 82 00 14 	beq     784 <fn_800614A8+0x784>
     774:	80 1d 00 6c 	lwz     r0,108(r29)
     778:	7c 00 00 34 	cntlzw  r0,r0
     77c:	54 00 d9 7e 	srwi    r0,r0,5
     780:	90 19 00 00 	stw     r0,0(r25)
     784:	38 60 00 01 	li      r3,1
     788:	48 00 13 a4 	b       1b2c <fn_800614A8+0x1b2c>
     78c:	28 19 00 00 	cmplwi  r25,0
     790:	41 82 00 0c 	beq     79c <fn_800614A8+0x79c>
     794:	38 00 00 01 	li      r0,1
     798:	90 19 00 00 	stw     r0,0(r25)
     79c:	38 60 00 01 	li      r3,1
     7a0:	48 00 13 8c 	b       1b2c <fn_800614A8+0x1b2c>
     7a4:	7f e3 fb 78 	mr      r3,r31
     7a8:	7f 04 c3 78 	mr      r4,r24
     7ac:	48 00 00 01 	bl      7ac <fn_800614A8+0x7ac>
			7ac: R_PPC_REL24	fn_80066A0C
     7b0:	38 60 00 01 	li      r3,1
     7b4:	48 00 13 78 	b       1b2c <fn_800614A8+0x1b2c>
     7b8:	7f 03 c3 78 	mr      r3,r24
     7bc:	48 00 00 01 	bl      7bc <fn_800614A8+0x7bc>
			7bc: R_PPC_REL24	fn_80200C38
     7c0:	c0 20 00 00 	lfs     f1,0(0)
			7c0: R_PPC_EMB_SDA21	lbl_8064E614
     7c4:	7c 64 1b 78 	mr      r4,r3
     7c8:	c0 40 00 00 	lfs     f2,0(0)
			7c8: R_PPC_EMB_SDA21	lbl_8064E618
     7cc:	7f c3 f3 78 	mr      r3,r30
     7d0:	48 00 00 01 	bl      7d0 <fn_800614A8+0x7d0>
			7d0: R_PPC_REL24	fn_80066888
     7d4:	38 60 00 01 	li      r3,1
     7d8:	48 00 13 54 	b       1b2c <fn_800614A8+0x1b2c>
     7dc:	7f 03 c3 78 	mr      r3,r24
     7e0:	48 00 00 01 	bl      7e0 <fn_800614A8+0x7e0>
			7e0: R_PPC_REL24	fn_80200C38
     7e4:	7c 6f 1b 78 	mr      r15,r3
     7e8:	48 00 00 01 	bl      7e8 <fn_800614A8+0x7e8>
			7e8: R_PPC_REL24	fn_801A7488
     7ec:	7c 70 1b 78 	mr      r16,r3
     7f0:	2c 10 00 0b 	cmpwi   r16,11
     7f4:	40 82 00 14 	bne     808 <fn_800614A8+0x808>
     7f8:	7d e3 7b 78 	mr      r3,r15
     7fc:	38 80 00 0d 	li      r4,13
     800:	48 00 00 01 	bl      800 <fn_800614A8+0x800>
			800: R_PPC_REL24	fn_801A7470
     804:	48 00 00 18 	b       81c <fn_800614A8+0x81c>
     808:	2c 10 00 0c 	cmpwi   r16,12
     80c:	40 82 00 10 	bne     81c <fn_800614A8+0x81c>
     810:	7d e3 7b 78 	mr      r3,r15
     814:	38 80 00 0e 	li      r4,14
     818:	48 00 00 01 	bl      818 <fn_800614A8+0x818>
			818: R_PPC_REL24	fn_801A7470
     81c:	7f e3 fb 78 	mr      r3,r31
     820:	7f 04 c3 78 	mr      r4,r24
     824:	7f 25 cb 78 	mr      r5,r25
     828:	48 00 00 01 	bl      828 <fn_800614A8+0x828>
			828: R_PPC_REL24	fn_80066754
     82c:	7d e3 7b 78 	mr      r3,r15
     830:	7e 04 83 78 	mr      r4,r16
     834:	48 00 00 01 	bl      834 <fn_800614A8+0x834>
			834: R_PPC_REL24	fn_801A7470
     838:	2c 10 00 0b 	cmpwi   r16,11
     83c:	41 82 00 0c 	beq     848 <fn_800614A8+0x848>
     840:	2c 10 00 0c 	cmpwi   r16,12
     844:	40 82 00 14 	bne     858 <fn_800614A8+0x858>
     848:	3c 80 00 02 	lis     r4,2
     84c:	7f c3 f3 78 	mr      r3,r30
     850:	38 84 fd 70 	addi    r4,r4,-656
     854:	48 00 00 01 	bl      854 <fn_800614A8+0x854>
			854: R_PPC_REL24	fn_801296F8
     858:	38 60 00 01 	li      r3,1
     85c:	48 00 12 d0 	b       1b2c <fn_800614A8+0x1b2c>
     860:	7f e3 fb 78 	mr      r3,r31
     864:	7f 04 c3 78 	mr      r4,r24
     868:	48 00 00 01 	bl      868 <fn_800614A8+0x868>
			868: R_PPC_REL24	fn_800674E4
     86c:	80 00 00 00 	lwz     r0,0(0)
			86c: R_PPC_EMB_SDA21	lbl_8064D18C
     870:	2c 00 00 88 	cmpwi   r0,136
     874:	40 82 00 f8 	bne     96c <fn_800614A8+0x96c>
     878:	a8 7d 00 ea 	lha     r3,234(r29)
     87c:	38 00 00 01 	li      r0,1
     880:	7c 63 0e 70 	srawi   r3,r3,1
     884:	2c 03 00 01 	cmpwi   r3,1
     888:	41 80 00 08 	blt     890 <fn_800614A8+0x890>
     88c:	7c 60 1b 78 	mr      r0,r3
     890:	b0 1d 00 ea 	sth     r0,234(r29)
     894:	38 00 00 01 	li      r0,1
     898:	a8 7d 00 fa 	lha     r3,250(r29)
     89c:	7c 63 0e 70 	srawi   r3,r3,1
     8a0:	2c 03 00 01 	cmpwi   r3,1
     8a4:	41 80 00 08 	blt     8ac <fn_800614A8+0x8ac>
     8a8:	7c 60 1b 78 	mr      r0,r3
     8ac:	b0 1d 00 fa 	sth     r0,250(r29)
     8b0:	38 00 00 01 	li      r0,1
     8b4:	a8 7d 00 fc 	lha     r3,252(r29)
     8b8:	7c 63 0e 70 	srawi   r3,r3,1
     8bc:	2c 03 00 01 	cmpwi   r3,1
     8c0:	41 80 00 08 	blt     8c8 <fn_800614A8+0x8c8>
     8c4:	7c 60 1b 78 	mr      r0,r3
     8c8:	b0 1d 00 fc 	sth     r0,252(r29)
     8cc:	38 00 00 01 	li      r0,1
     8d0:	a8 7d 00 ee 	lha     r3,238(r29)
     8d4:	7c 63 0e 70 	srawi   r3,r3,1
     8d8:	2c 03 00 01 	cmpwi   r3,1
     8dc:	41 80 00 08 	blt     8e4 <fn_800614A8+0x8e4>
     8e0:	7c 60 1b 78 	mr      r0,r3
     8e4:	b0 1d 00 ee 	sth     r0,238(r29)
     8e8:	38 00 00 01 	li      r0,1
     8ec:	a8 7d 00 f0 	lha     r3,240(r29)
     8f0:	7c 63 0e 70 	srawi   r3,r3,1
     8f4:	2c 03 00 01 	cmpwi   r3,1
     8f8:	41 80 00 08 	blt     900 <fn_800614A8+0x900>
     8fc:	7c 60 1b 78 	mr      r0,r3
     900:	b0 1d 00 f0 	sth     r0,240(r29)
     904:	38 00 00 01 	li      r0,1
     908:	a8 7d 00 ec 	lha     r3,236(r29)
     90c:	7c 63 0e 70 	srawi   r3,r3,1
     910:	2c 03 00 01 	cmpwi   r3,1
     914:	41 80 00 08 	blt     91c <fn_800614A8+0x91c>
     918:	7c 60 1b 78 	mr      r0,r3
     91c:	b0 1d 00 ec 	sth     r0,236(r29)
     920:	7f e3 fb 78 	mr      r3,r31
     924:	38 a1 00 08 	addi    r5,r1,8
     928:	38 80 00 00 	li      r4,0
     92c:	48 00 00 01 	bl      92c <fn_800614A8+0x92c>
			92c: R_PPC_REL24	fn_80038308
     930:	a8 01 00 08 	lha     r0,8(r1)
     934:	38 80 00 01 	li      r4,1
     938:	7c 00 0e 70 	srawi   r0,r0,1
     93c:	2c 00 00 01 	cmpwi   r0,1
     940:	41 80 00 08 	blt     948 <fn_800614A8+0x948>
     944:	7c 04 03 78 	mr      r4,r0
     948:	7f e3 fb 78 	mr      r3,r31
     94c:	7c 85 07 34 	extsh   r5,r4
     950:	38 80 00 00 	li      r4,0
     954:	38 c0 00 00 	li      r6,0
     958:	48 00 00 01 	bl      958 <fn_800614A8+0x958>
			958: R_PPC_REL24	fn_800389E0
     95c:	a8 7a 00 86 	lha     r3,134(r26)
     960:	38 03 00 1e 	addi    r0,r3,30
     964:	b0 1a 00 86 	sth     r0,134(r26)
     968:	48 00 00 18 	b       980 <fn_800614A8+0x980>
     96c:	2c 00 00 29 	cmpwi   r0,41
     970:	40 82 00 10 	bne     980 <fn_800614A8+0x980>
     974:	a8 7a 00 86 	lha     r3,134(r26)
     978:	38 03 00 1e 	addi    r0,r3,30
     97c:	b0 1a 00 86 	sth     r0,134(r26)
     980:	38 60 00 01 	li      r3,1
     984:	48 00 11 a8 	b       1b2c <fn_800614A8+0x1b2c>
     988:	7f e3 fb 78 	mr      r3,r31
     98c:	7f 04 c3 78 	mr      r4,r24
     990:	48 00 00 01 	bl      990 <fn_800614A8+0x990>
			990: R_PPC_REL24	fn_80067650
     994:	38 60 00 01 	li      r3,1
     998:	48 00 11 94 	b       1b2c <fn_800614A8+0x1b2c>
     99c:	7f 03 c3 78 	mr      r3,r24
     9a0:	48 00 00 01 	bl      9a0 <fn_800614A8+0x9a0>
			9a0: R_PPC_REL24	fn_80200C38
     9a4:	7c 65 1b 78 	mr      r5,r3
     9a8:	7f e3 fb 78 	mr      r3,r31
     9ac:	7f a4 eb 78 	mr      r4,r29
     9b0:	7f 06 c3 78 	mr      r6,r24
     9b4:	7f 27 cb 78 	mr      r7,r25
     9b8:	48 00 00 01 	bl      9b8 <fn_800614A8+0x9b8>
			9b8: R_PPC_REL24	fn_800EA0FC
     9bc:	38 60 00 01 	li      r3,1
     9c0:	48 00 11 6c 	b       1b2c <fn_800614A8+0x1b2c>
     9c4:	2c 16 00 03 	cmpwi   r22,3
     9c8:	41 82 01 dc 	beq     ba4 <fn_800614A8+0xba4>
     9cc:	40 80 00 10 	bge     9dc <fn_800614A8+0x9dc>
     9d0:	2c 16 00 01 	cmpwi   r22,1
     9d4:	41 82 00 14 	beq     9e8 <fn_800614A8+0x9e8>
     9d8:	48 00 11 54 	b       1b2c <fn_800614A8+0x1b2c>
     9dc:	2c 16 00 5a 	cmpwi   r22,90
     9e0:	41 82 00 34 	beq     a14 <fn_800614A8+0xa14>
     9e4:	48 00 11 48 	b       1b2c <fn_800614A8+0x1b2c>
     9e8:	c0 20 00 00 	lfs     f1,0(0)
			9e8: R_PPC_EMB_SDA21	lbl_8064E61C
     9ec:	7f c3 f3 78 	mr      r3,r30
     9f0:	48 00 00 01 	bl      9f0 <fn_800614A8+0x9f0>
			9f0: R_PPC_REL24	fn_8011F778
     9f4:	c0 20 00 00 	lfs     f1,0(0)
			9f4: R_PPC_EMB_SDA21	lbl_8064E61C
     9f8:	7f c3 f3 78 	mr      r3,r30
     9fc:	48 00 00 01 	bl      9fc <fn_800614A8+0x9fc>
			9fc: R_PPC_REL24	fn_8011F788
     a00:	c0 20 00 00 	lfs     f1,0(0)
			a00: R_PPC_EMB_SDA21	lbl_8064E61C
     a04:	7f c3 f3 78 	mr      r3,r30
     a08:	48 00 00 01 	bl      a08 <fn_800614A8+0xa08>
			a08: R_PPC_REL24	fn_8011F798
     a0c:	38 60 00 01 	li      r3,1
     a10:	48 00 11 1c 	b       1b2c <fn_800614A8+0x1b2c>
     a14:	7f 03 c3 78 	mr      r3,r24
     a18:	48 00 00 01 	bl      a18 <fn_800614A8+0xa18>
			a18: R_PPC_REL24	fn_80200C20
     a1c:	48 00 00 01 	bl      a1c <fn_800614A8+0xa1c>
			a1c: R_PPC_REL24	fn_80201814
     a20:	28 03 00 00 	cmplwi  r3,0
     a24:	41 82 00 10 	beq     a34 <fn_800614A8+0xa34>
     a28:	48 00 00 01 	bl      a28 <fn_800614A8+0xa28>
			a28: R_PPC_REL24	fn_80201BC8
     a2c:	7c 70 1b 78 	mr      r16,r3
     a30:	48 00 00 08 	b       a38 <fn_800614A8+0xa38>
     a34:	3a 00 00 00 	li      r16,0
     a38:	28 10 00 00 	cmplwi  r16,0
     a3c:	41 82 01 60 	beq     b9c <fn_800614A8+0xb9c>
     a40:	48 00 00 01 	bl      a40 <fn_800614A8+0xa40>
			a40: R_PPC_REL24	fn_800460EC
     a44:	2c 03 00 00 	cmpwi   r3,0
     a48:	40 82 01 54 	bne     b9c <fn_800614A8+0xb9c>
     a4c:	7f e3 fb 78 	mr      r3,r31
     a50:	48 00 00 01 	bl      a50 <fn_800614A8+0xa50>
			a50: R_PPC_REL24	fn_800CAF7C
     a54:	2c 03 00 00 	cmpwi   r3,0
     a58:	41 82 01 44 	beq     b9c <fn_800614A8+0xb9c>
     a5c:	80 7b 00 8c 	lwz     r3,140(r27)
     a60:	a8 03 01 50 	lha     r0,336(r3)
     a64:	7c 00 07 35 	extsh.  r0,r0
     a68:	40 82 01 34 	bne     b9c <fn_800614A8+0xb9c>
     a6c:	7e 04 83 78 	mr      r4,r16
     a70:	38 61 00 44 	addi    r3,r1,68
     a74:	48 00 00 01 	bl      a74 <fn_800614A8+0xa74>
			a74: R_PPC_REL24	fn_8011F114
     a78:	80 e1 00 48 	lwz     r7,72(r1)
     a7c:	3c 00 43 30 	lis     r0,17200
     a80:	c0 01 00 44 	lfs     f0,68(r1)
     a84:	7f c3 f3 78 	mr      r3,r30
     a88:	80 c1 00 4c 	lwz     r6,76(r1)
     a8c:	38 81 00 5c 	addi    r4,r1,92
     a90:	d0 01 00 5c 	stfs    f0,92(r1)
     a94:	38 a0 00 00 	li      r5,0
     a98:	c8 20 00 00 	lfd     f1,0(0)
			a98: R_PPC_EMB_SDA21	@349
     a9c:	90 e1 00 60 	stw     r7,96(r1)
     aa0:	c0 40 00 00 	lfs     f2,0(0)
			aa0: R_PPC_EMB_SDA21	lbl_8064E620
     aa4:	90 c1 00 64 	stw     r6,100(r1)
     aa8:	a8 dd 01 4a 	lha     r6,330(r29)
     aac:	90 01 00 90 	stw     r0,144(r1)
     ab0:	6c c0 80 00 	xoris   r0,r6,32768
     ab4:	90 01 00 94 	stw     r0,148(r1)
     ab8:	c8 01 00 90 	lfd     f0,144(r1)
     abc:	ec 00 08 28 	fsubs   f0,f0,f1
     ac0:	ec 22 00 32 	fmuls   f1,f2,f0
     ac4:	48 00 00 01 	bl      ac4 <fn_800614A8+0xac4>
			ac4: R_PPC_REL24	fn_80204434
     ac8:	54 60 06 3f 	clrlwi. r0,r3,24
     acc:	40 82 00 d0 	bne     b9c <fn_800614A8+0xb9c>
     ad0:	80 00 00 00 	lwz     r0,0(0)
			ad0: R_PPC_EMB_SDA21	lbl_8064D18C
     ad4:	2c 00 00 34 	cmpwi   r0,52
     ad8:	41 82 00 c4 	beq     b9c <fn_800614A8+0xb9c>
     adc:	7e 04 83 78 	mr      r4,r16
     ae0:	38 61 00 38 	addi    r3,r1,56
     ae4:	48 00 00 01 	bl      ae4 <fn_800614A8+0xae4>
			ae4: R_PPC_REL24	fn_8011F114
     ae8:	c0 01 00 38 	lfs     f0,56(r1)
     aec:	7e 03 83 78 	mr      r3,r16
     af0:	38 e1 00 0c 	addi    r7,r1,12
     af4:	38 80 00 00 	li      r4,0
     af8:	d0 1d 00 94 	stfs    f0,148(r29)
     afc:	38 a0 00 00 	li      r5,0
     b00:	38 c0 ff ff 	li      r6,-1
     b04:	39 00 00 01 	li      r8,1
     b08:	80 01 00 3c 	lwz     r0,60(r1)
     b0c:	90 1d 00 98 	stw     r0,152(r29)
     b10:	80 01 00 40 	lwz     r0,64(r1)
     b14:	90 1d 00 9c 	stw     r0,156(r29)
     b18:	48 00 00 01 	bl      b18 <fn_800614A8+0xb18>
			b18: R_PPC_REL24	fn_8011F598
     b1c:	2c 03 ff ff 	cmpwi   r3,-1
     b20:	41 82 00 18 	beq     b38 <fn_800614A8+0xb38>
     b24:	7e 03 83 78 	mr      r3,r16
     b28:	38 a1 00 68 	addi    r5,r1,104
     b2c:	38 80 00 00 	li      r4,0
     b30:	48 00 00 01 	bl      b30 <fn_800614A8+0xb30>
			b30: R_PPC_REL24	fn_8012FE10
     b34:	48 00 00 1c 	b       b50 <fn_800614A8+0xb50>
     b38:	c0 01 00 5c 	lfs     f0,92(r1)
     b3c:	80 61 00 60 	lwz     r3,96(r1)
     b40:	80 01 00 64 	lwz     r0,100(r1)
     b44:	d0 01 00 68 	stfs    f0,104(r1)
     b48:	90 61 00 6c 	stw     r3,108(r1)
     b4c:	90 01 00 70 	stw     r0,112(r1)
     b50:	80 1b 00 94 	lwz     r0,148(r27)
     b54:	2c 00 00 01 	cmpwi   r0,1
     b58:	40 82 00 2c 	bne     b84 <fn_800614A8+0xb84>
     b5c:	7f c3 f3 78 	mr      r3,r30
     b60:	38 81 00 68 	addi    r4,r1,104
     b64:	38 a0 00 04 	li      r5,4
     b68:	38 c0 00 04 	li      r6,4
     b6c:	48 00 00 01 	bl      b6c <fn_800614A8+0xb6c>
			b6c: R_PPC_REL24	fn_8012FF34
     b70:	2c 03 00 00 	cmpwi   r3,0
     b74:	41 82 00 10 	beq     b84 <fn_800614A8+0xb84>
     b78:	7f c3 f3 78 	mr      r3,r30
     b7c:	38 80 00 3c 	li      r4,60
     b80:	48 00 00 01 	bl      b80 <fn_800614A8+0xb80>
			b80: R_PPC_REL24	fn_801302BC
     b84:	7f e3 fb 78 	mr      r3,r31
     b88:	38 80 00 15 	li      r4,21
     b8c:	48 00 00 01 	bl      b8c <fn_800614A8+0xb8c>
			b8c: R_PPC_REL24	fn_80201D2C
     b90:	7f e3 fb 78 	mr      r3,r31
     b94:	38 80 00 01 	li      r4,1
     b98:	48 00 00 01 	bl      b98 <fn_800614A8+0xb98>
			b98: R_PPC_REL24	fn_80201D14
     b9c:	38 60 00 01 	li      r3,1
     ba0:	48 00 0f 8c 	b       1b2c <fn_800614A8+0x1b2c>
     ba4:	7f c3 f3 78 	mr      r3,r30
     ba8:	7e 44 93 78 	mr      r4,r18
     bac:	7e 05 83 78 	mr      r5,r16
     bb0:	48 00 00 01 	bl      bb0 <fn_800614A8+0xbb0>
			bb0: R_PPC_REL24	fn_80060C24
     bb4:	7f e3 fb 78 	mr      r3,r31
     bb8:	7f c4 f3 78 	mr      r4,r30
     bbc:	7f 05 c3 78 	mr      r5,r24
     bc0:	7e 46 93 78 	mr      r6,r18
     bc4:	7e 07 83 78 	mr      r7,r16
     bc8:	48 00 00 01 	bl      bc8 <fn_800614A8+0xbc8>
			bc8: R_PPC_REL24	fn_80060D4C
     bcc:	7f 83 e3 78 	mr      r3,r28
     bd0:	7f e4 fb 78 	mr      r4,r31
     bd4:	7f c5 f3 78 	mr      r5,r30
     bd8:	7f 66 db 78 	mr      r6,r27
     bdc:	7f 47 d3 78 	mr      r7,r26
     be0:	48 00 00 01 	bl      be0 <fn_800614A8+0xbe0>
			be0: R_PPC_REL24	fn_8005FD84
     be4:	38 60 00 01 	li      r3,1
     be8:	48 00 0f 44 	b       1b2c <fn_800614A8+0x1b2c>
     bec:	2c 16 00 03 	cmpwi   r22,3
     bf0:	41 82 00 3c 	beq     c2c <fn_800614A8+0xc2c>
     bf4:	40 80 00 14 	bge     c08 <fn_800614A8+0xc08>
     bf8:	2c 16 00 01 	cmpwi   r22,1
     bfc:	41 82 00 18 	beq     c14 <fn_800614A8+0xc14>
     c00:	40 80 01 ec 	bge     dec <fn_800614A8+0xdec>
     c04:	48 00 0f 28 	b       1b2c <fn_800614A8+0x1b2c>
     c08:	2c 16 00 5a 	cmpwi   r22,90
     c0c:	41 82 00 f0 	beq     cfc <fn_800614A8+0xcfc>
     c10:	48 00 0f 1c 	b       1b2c <fn_800614A8+0x1b2c>
     c14:	c0 00 00 00 	lfs     f0,0(0)
			c14: R_PPC_EMB_SDA21	lbl_8064E5DC
     c18:	7f c3 f3 78 	mr      r3,r30
     c1c:	d0 1d 00 c4 	stfs    f0,196(r29)
     c20:	48 00 00 01 	bl      c20 <fn_800614A8+0xc20>
			c20: R_PPC_REL24	fn_8012B344
     c24:	38 60 00 01 	li      r3,1
     c28:	48 00 0f 04 	b       1b2c <fn_800614A8+0x1b2c>
     c2c:	7f 83 e3 78 	mr      r3,r28
     c30:	7f e4 fb 78 	mr      r4,r31
     c34:	7f c5 f3 78 	mr      r5,r30
     c38:	7f 66 db 78 	mr      r6,r27
     c3c:	7f 47 d3 78 	mr      r7,r26
     c40:	48 00 00 01 	bl      c40 <fn_800614A8+0xc40>
			c40: R_PPC_REL24	fn_8005FD84
     c44:	7f e3 fb 78 	mr      r3,r31
     c48:	7f c4 f3 78 	mr      r4,r30
     c4c:	7f 05 c3 78 	mr      r5,r24
     c50:	7e 46 93 78 	mr      r6,r18
     c54:	7e 07 83 78 	mr      r7,r16
     c58:	48 00 00 01 	bl      c58 <fn_800614A8+0xc58>
			c58: R_PPC_REL24	fn_80060D4C
     c5c:	2c 03 00 00 	cmpwi   r3,0
     c60:	40 82 00 94 	bne     cf4 <fn_800614A8+0xcf4>
     c64:	c0 20 00 00 	lfs     f1,0(0)
			c64: R_PPC_EMB_SDA21	lbl_8064E608
     c68:	7f c3 f3 78 	mr      r3,r30
     c6c:	38 9d 00 94 	addi    r4,r29,148
     c70:	38 a0 00 02 	li      r5,2
     c74:	38 c0 00 00 	li      r6,0
     c78:	48 00 00 01 	bl      c78 <fn_800614A8+0xc78>
			c78: R_PPC_REL24	fn_800BE86C
     c7c:	2c 03 00 00 	cmpwi   r3,0
     c80:	40 82 00 34 	bne     cb4 <fn_800614A8+0xcb4>
     c84:	7f c3 f3 78 	mr      r3,r30
     c88:	38 80 00 0f 	li      r4,15
     c8c:	38 a0 00 25 	li      r5,37
     c90:	38 c0 00 01 	li      r6,1
     c94:	48 00 00 01 	bl      c94 <fn_800614A8+0xc94>
			c94: R_PPC_REL24	fn_801294DC
     c98:	7f e3 fb 78 	mr      r3,r31
     c9c:	38 80 00 01 	li      r4,1
     ca0:	48 00 00 01 	bl      ca0 <fn_800614A8+0xca0>
			ca0: R_PPC_REL24	fn_80201D2C
     ca4:	7f e3 fb 78 	mr      r3,r31
     ca8:	38 80 00 01 	li      r4,1
     cac:	48 00 00 01 	bl      cac <fn_800614A8+0xcac>
			cac: R_PPC_REL24	fn_80201D14
     cb0:	48 00 00 44 	b       cf4 <fn_800614A8+0xcf4>
     cb4:	c0 5d 00 c4 	lfs     f2,196(r29)
     cb8:	c0 00 00 00 	lfs     f0,0(0)
			cb8: R_PPC_EMB_SDA21	lbl_8064E624
     cbc:	fc 02 00 40 	fcmpo   cr0,f2,f0
     cc0:	40 80 00 34 	bge     cf4 <fn_800614A8+0xcf4>
     cc4:	c0 00 00 00 	lfs     f0,0(0)
			cc4: R_PPC_EMB_SDA21	lbl_8064E628
     cc8:	ec 02 00 2a 	fadds   f0,f2,f0
     ccc:	d0 1d 00 c4 	stfs    f0,196(r29)
     cd0:	c0 20 00 00 	lfs     f1,0(0)
			cd0: R_PPC_EMB_SDA21	lbl_8064E614
     cd4:	fc 02 08 00 	fcmpu   cr0,f2,f1
     cd8:	40 82 00 1c 	bne     cf4 <fn_800614A8+0xcf4>
     cdc:	c0 1d 00 c4 	lfs     f0,196(r29)
     ce0:	fc 00 08 40 	fcmpo   cr0,f0,f1
     ce4:	40 81 00 10 	ble     cf4 <fn_800614A8+0xcf4>
     ce8:	7f c3 f3 78 	mr      r3,r30
     cec:	38 80 00 3f 	li      r4,63
     cf0:	48 00 00 01 	bl      cf0 <fn_800614A8+0xcf0>
			cf0: R_PPC_REL24	fn_801A977C
     cf4:	38 60 00 01 	li      r3,1
     cf8:	48 00 0e 34 	b       1b2c <fn_800614A8+0x1b2c>
     cfc:	7f 03 c3 78 	mr      r3,r24
     d00:	48 00 00 01 	bl      d00 <fn_800614A8+0xd00>
			d00: R_PPC_REL24	fn_80200C20
     d04:	48 00 00 01 	bl      d04 <fn_800614A8+0xd04>
			d04: R_PPC_REL24	fn_80201814
     d08:	28 03 00 00 	cmplwi  r3,0
     d0c:	41 82 00 10 	beq     d1c <fn_800614A8+0xd1c>
     d10:	48 00 00 01 	bl      d10 <fn_800614A8+0xd10>
			d10: R_PPC_REL24	fn_80201BC8
     d14:	7c 70 1b 78 	mr      r16,r3
     d18:	48 00 00 08 	b       d20 <fn_800614A8+0xd20>
     d1c:	3a 00 00 00 	li      r16,0
     d20:	28 10 00 00 	cmplwi  r16,0
     d24:	41 82 00 c0 	beq     de4 <fn_800614A8+0xde4>
     d28:	48 00 00 01 	bl      d28 <fn_800614A8+0xd28>
			d28: R_PPC_REL24	fn_800460EC
     d2c:	2c 03 00 00 	cmpwi   r3,0
     d30:	40 82 00 b4 	bne     de4 <fn_800614A8+0xde4>
     d34:	7f e3 fb 78 	mr      r3,r31
     d38:	48 00 00 01 	bl      d38 <fn_800614A8+0xd38>
			d38: R_PPC_REL24	fn_800CAF7C
     d3c:	2c 03 00 00 	cmpwi   r3,0
     d40:	41 82 00 a4 	beq     de4 <fn_800614A8+0xde4>
     d44:	a8 1d 01 50 	lha     r0,336(r29)
     d48:	7c 00 07 35 	extsh.  r0,r0
     d4c:	40 82 00 98 	bne     de4 <fn_800614A8+0xde4>
     d50:	7e 04 83 78 	mr      r4,r16
     d54:	38 61 00 2c 	addi    r3,r1,44
     d58:	48 00 00 01 	bl      d58 <fn_800614A8+0xd58>
			d58: R_PPC_REL24	fn_8011F114
     d5c:	80 e1 00 30 	lwz     r7,48(r1)
     d60:	3c 00 43 30 	lis     r0,17200
     d64:	c0 01 00 2c 	lfs     f0,44(r1)
     d68:	7f c3 f3 78 	mr      r3,r30
     d6c:	80 c1 00 34 	lwz     r6,52(r1)
     d70:	38 81 00 50 	addi    r4,r1,80
     d74:	d0 01 00 50 	stfs    f0,80(r1)
     d78:	38 a0 00 00 	li      r5,0
     d7c:	c8 20 00 00 	lfd     f1,0(0)
			d7c: R_PPC_EMB_SDA21	@349
     d80:	90 e1 00 54 	stw     r7,84(r1)
     d84:	c0 40 00 00 	lfs     f2,0(0)
			d84: R_PPC_EMB_SDA21	lbl_8064E620
     d88:	90 c1 00 58 	stw     r6,88(r1)
     d8c:	a8 dd 01 4a 	lha     r6,330(r29)
     d90:	90 01 00 90 	stw     r0,144(r1)
     d94:	6c c0 80 00 	xoris   r0,r6,32768
     d98:	90 01 00 94 	stw     r0,148(r1)
     d9c:	c8 01 00 90 	lfd     f0,144(r1)
     da0:	ec 00 08 28 	fsubs   f0,f0,f1
     da4:	ec 22 00 32 	fmuls   f1,f2,f0
     da8:	48 00 00 01 	bl      da8 <fn_800614A8+0xda8>
			da8: R_PPC_REL24	fn_80204434
     dac:	54 60 06 3f 	clrlwi. r0,r3,24
     db0:	40 82 00 34 	bne     de4 <fn_800614A8+0xde4>
     db4:	80 00 00 00 	lwz     r0,0(0)
			db4: R_PPC_EMB_SDA21	lbl_8064D18C
     db8:	2c 00 00 34 	cmpwi   r0,52
     dbc:	41 82 00 28 	beq     de4 <fn_800614A8+0xde4>
     dc0:	7e 04 83 78 	mr      r4,r16
     dc4:	38 61 00 20 	addi    r3,r1,32
     dc8:	48 00 00 01 	bl      dc8 <fn_800614A8+0xdc8>
			dc8: R_PPC_REL24	fn_8011F114
     dcc:	c0 01 00 20 	lfs     f0,32(r1)
     dd0:	d0 1d 00 94 	stfs    f0,148(r29)
     dd4:	80 01 00 24 	lwz     r0,36(r1)
     dd8:	90 1d 00 98 	stw     r0,152(r29)
     ddc:	80 01 00 28 	lwz     r0,40(r1)
     de0:	90 1d 00 9c 	stw     r0,156(r29)
     de4:	38 60 00 01 	li      r3,1
     de8:	48 00 0d 44 	b       1b2c <fn_800614A8+0x1b2c>
     dec:	7f c3 f3 78 	mr      r3,r30
     df0:	48 00 00 01 	bl      df0 <fn_800614A8+0xdf0>
			df0: R_PPC_REL24	fn_80128EAC
     df4:	7c 70 1b 78 	mr      r16,r3
     df8:	7f c3 f3 78 	mr      r3,r30
     dfc:	48 00 00 01 	bl      dfc <fn_800614A8+0xdfc>
			dfc: R_PPC_REL24	fn_801290D0
     e00:	54 60 07 7b 	rlwinm. r0,r3,0,29,29
     e04:	7c 64 1b 78 	mr      r4,r3
     e08:	41 82 00 38 	beq     e40 <fn_800614A8+0xe40>
     e0c:	2c 10 00 03 	cmpwi   r16,3
     e10:	41 82 00 0c 	beq     e1c <fn_800614A8+0xe1c>
     e14:	2c 10 00 02 	cmpwi   r16,2
     e18:	40 82 00 28 	bne     e40 <fn_800614A8+0xe40>
     e1c:	80 00 00 00 	lwz     r0,0(0)
			e1c: R_PPC_EMB_SDA21	lbl_8064D18C
     e20:	2c 00 00 53 	cmpwi   r0,83
     e24:	40 82 00 10 	bne     e34 <fn_800614A8+0xe34>
     e28:	7f c3 f3 78 	mr      r3,r30
     e2c:	48 00 00 01 	bl      e2c <fn_800614A8+0xe2c>
			e2c: R_PPC_REL24	fn_8012B344
     e30:	48 00 00 10 	b       e40 <fn_800614A8+0xe40>
     e34:	7f c3 f3 78 	mr      r3,r30
     e38:	54 84 07 b8 	rlwinm  r4,r4,0,30,28
     e3c:	48 00 00 01 	bl      e3c <fn_800614A8+0xe3c>
			e3c: R_PPC_REL24	fn_80128F74
     e40:	c0 00 00 00 	lfs     f0,0(0)
			e40: R_PPC_EMB_SDA21	lbl_8064E5DC
     e44:	38 60 00 01 	li      r3,1
     e48:	d0 1d 00 c4 	stfs    f0,196(r29)
     e4c:	48 00 0c e0 	b       1b2c <fn_800614A8+0x1b2c>
     e50:	2c 16 00 03 	cmpwi   r22,3
     e54:	40 82 00 6c 	bne     ec0 <fn_800614A8+0xec0>
     e58:	7f 83 e3 78 	mr      r3,r28
     e5c:	7f e4 fb 78 	mr      r4,r31
     e60:	7f c5 f3 78 	mr      r5,r30
     e64:	7f 66 db 78 	mr      r6,r27
     e68:	7f 47 d3 78 	mr      r7,r26
     e6c:	48 00 00 01 	bl      e6c <fn_800614A8+0xe6c>
			e6c: R_PPC_REL24	fn_8005FD84
     e70:	7f e3 fb 78 	mr      r3,r31
     e74:	7f a4 eb 78 	mr      r4,r29
     e78:	48 00 00 01 	bl      e78 <fn_800614A8+0xe78>
			e78: R_PPC_REL24	fn_800BE010
     e7c:	7e 83 a3 78 	mr      r3,r20
     e80:	48 00 00 01 	bl      e80 <fn_800614A8+0xe80>
			e80: R_PPC_REL24	fn_80201C48
     e84:	2c 03 00 00 	cmpwi   r3,0
     e88:	41 82 00 10 	beq     e98 <fn_800614A8+0xe98>
     e8c:	7f e3 fb 78 	mr      r3,r31
     e90:	7f a4 eb 78 	mr      r4,r29
     e94:	48 00 00 01 	bl      e94 <fn_800614A8+0xe94>
			e94: R_PPC_REL24	fn_800BDEE4
     e98:	7f e3 fb 78 	mr      r3,r31
     e9c:	7f c4 f3 78 	mr      r4,r30
     ea0:	7f 85 e3 78 	mr      r5,r28
     ea4:	7f a6 eb 78 	mr      r6,r29
     ea8:	7f 07 c3 78 	mr      r7,r24
     eac:	7e 48 93 78 	mr      r8,r18
     eb0:	7e 09 83 78 	mr      r9,r16
     eb4:	48 00 00 01 	bl      eb4 <fn_800614A8+0xeb4>
			eb4: R_PPC_REL24	fn_80060F9C
     eb8:	38 60 00 01 	li      r3,1
     ebc:	48 00 0c 70 	b       1b2c <fn_800614A8+0x1b2c>
     ec0:	2c 16 00 66 	cmpwi   r22,102
     ec4:	40 82 00 2c 	bne     ef0 <fn_800614A8+0xef0>
     ec8:	7f c3 f3 78 	mr      r3,r30
     ecc:	48 00 00 01 	bl      ecc <fn_800614A8+0xecc>
			ecc: R_PPC_REL24	fn_8012B344
     ed0:	7f e3 fb 78 	mr      r3,r31
     ed4:	38 80 00 01 	li      r4,1
     ed8:	48 00 00 01 	bl      ed8 <fn_800614A8+0xed8>
			ed8: R_PPC_REL24	fn_80201D2C
     edc:	7f e3 fb 78 	mr      r3,r31
     ee0:	38 80 00 01 	li      r4,1
     ee4:	48 00 00 01 	bl      ee4 <fn_800614A8+0xee4>
			ee4: R_PPC_REL24	fn_80201D14
     ee8:	38 60 00 01 	li      r3,1
     eec:	48 00 0c 40 	b       1b2c <fn_800614A8+0x1b2c>
     ef0:	38 60 00 00 	li      r3,0
     ef4:	48 00 0c 38 	b       1b2c <fn_800614A8+0x1b2c>
     ef8:	28 16 00 0d 	cmplwi  r22,13
     efc:	41 81 0c 30 	bgt     1b2c <fn_800614A8+0x1b2c>
     f00:	3c 80 00 00 	lis     r4,0
			f02: R_PPC_ADDR16_HA	@350
     f04:	56 c0 10 3a 	slwi    r0,r22,2
     f08:	38 84 00 00 	addi    r4,r4,0
			f0a: R_PPC_ADDR16_LO	@350
     f0c:	7c 04 00 2e 	lwzx    r0,r4,r0
     f10:	7c 09 03 a6 	mtctr   r0
     f14:	4e 80 04 20 	bctr
     f18:	88 1a 00 89 	lbz     r0,137(r26)
     f1c:	38 60 00 01 	li      r3,1
     f20:	54 00 06 3c 	rlwinm  r0,r0,0,24,30
     f24:	98 1a 00 89 	stb     r0,137(r26)
     f28:	48 00 0c 04 	b       1b2c <fn_800614A8+0x1b2c>
     f2c:	7f 83 e3 78 	mr      r3,r28
     f30:	7f e4 fb 78 	mr      r4,r31
     f34:	7f c5 f3 78 	mr      r5,r30
     f38:	7f 66 db 78 	mr      r6,r27
     f3c:	7f 47 d3 78 	mr      r7,r26
     f40:	48 00 00 01 	bl      f40 <fn_800614A8+0xf40>
			f40: R_PPC_REL24	fn_8005FD84
     f44:	38 60 00 01 	li      r3,1
     f48:	48 00 0b e4 	b       1b2c <fn_800614A8+0x1b2c>
     f4c:	7f e3 fb 78 	mr      r3,r31
     f50:	7f c4 f3 78 	mr      r4,r30
     f54:	7f 05 c3 78 	mr      r5,r24
     f58:	48 00 00 01 	bl      f58 <fn_800614A8+0xf58>
			f58: R_PPC_REL24	fn_80060F10
     f5c:	2c 03 00 00 	cmpwi   r3,0
     f60:	40 82 00 24 	bne     f84 <fn_800614A8+0xf84>
     f64:	38 00 00 5a 	li      r0,90
     f68:	7f e3 fb 78 	mr      r3,r31
     f6c:	b0 1d 01 50 	sth     r0,336(r29)
     f70:	38 80 00 01 	li      r4,1
     f74:	48 00 00 01 	bl      f74 <fn_800614A8+0xf74>
			f74: R_PPC_REL24	fn_80201D2C
     f78:	7f e3 fb 78 	mr      r3,r31
     f7c:	38 80 00 01 	li      r4,1
     f80:	48 00 00 01 	bl      f80 <fn_800614A8+0xf80>
			f80: R_PPC_REL24	fn_80201D14
     f84:	38 60 00 01 	li      r3,1
     f88:	48 00 0b a4 	b       1b2c <fn_800614A8+0x1b2c>
     f8c:	7f e3 fb 78 	mr      r3,r31
     f90:	38 95 01 b8 	addi    r4,r21,440
     f94:	38 d5 01 cc 	addi    r6,r21,460
     f98:	39 15 01 d8 	addi    r8,r21,472
     f9c:	38 a0 00 00 	li      r5,0
			f9c: R_PPC_EMB_SDA21	lbl_8064B508
     fa0:	38 e0 00 00 	li      r7,0
			fa0: R_PPC_EMB_SDA21	lbl_8064B510
     fa4:	48 00 00 01 	bl      fa4 <fn_800614A8+0xfa4>
			fa4: R_PPC_REL24	fn_80035FB8
     fa8:	2c 03 00 00 	cmpwi   r3,0
     fac:	40 82 00 3c 	bne     fe8 <fn_800614A8+0xfe8>
     fb0:	7f e3 fb 78 	mr      r3,r31
     fb4:	7f c4 f3 78 	mr      r4,r30
     fb8:	7f 05 c3 78 	mr      r5,r24
     fbc:	48 00 00 01 	bl      fbc <fn_800614A8+0xfbc>
			fbc: R_PPC_REL24	fn_80060F10
     fc0:	2c 03 00 00 	cmpwi   r3,0
     fc4:	40 82 00 24 	bne     fe8 <fn_800614A8+0xfe8>
     fc8:	38 00 00 5a 	li      r0,90
     fcc:	7f e3 fb 78 	mr      r3,r31
     fd0:	b0 1d 01 50 	sth     r0,336(r29)
     fd4:	38 80 00 01 	li      r4,1
     fd8:	48 00 00 01 	bl      fd8 <fn_800614A8+0xfd8>
			fd8: R_PPC_REL24	fn_80201D2C
     fdc:	7f e3 fb 78 	mr      r3,r31
     fe0:	38 80 00 01 	li      r4,1
     fe4:	48 00 00 01 	bl      fe4 <fn_800614A8+0xfe4>
			fe4: R_PPC_REL24	fn_80201D14
     fe8:	38 60 00 01 	li      r3,1
     fec:	48 00 0b 40 	b       1b2c <fn_800614A8+0x1b2c>
     ff0:	7f e3 fb 78 	mr      r3,r31
     ff4:	38 80 00 01 	li      r4,1
     ff8:	48 00 00 01 	bl      ff8 <fn_800614A8+0xff8>
			ff8: R_PPC_REL24	fn_80201D2C
     ffc:	7f e3 fb 78 	mr      r3,r31
    1000:	38 80 00 01 	li      r4,1
    1004:	48 00 00 01 	bl      1004 <fn_800614A8+0x1004>
			1004: R_PPC_REL24	fn_80201D14
    1008:	7f c3 f3 78 	mr      r3,r30
    100c:	48 00 00 01 	bl      100c <fn_800614A8+0x100c>
			100c: R_PPC_REL24	fn_8012B344
    1010:	38 60 00 01 	li      r3,1
    1014:	48 00 0b 18 	b       1b2c <fn_800614A8+0x1b2c>
    1018:	2c 16 00 65 	cmpwi   r22,101
    101c:	41 82 00 88 	beq     10a4 <fn_800614A8+0x10a4>
    1020:	40 80 00 1c 	bge     103c <fn_800614A8+0x103c>
    1024:	2c 16 00 03 	cmpwi   r22,3
    1028:	41 82 00 2c 	beq     1054 <fn_800614A8+0x1054>
    102c:	40 80 0b 00 	bge     1b2c <fn_800614A8+0x1b2c>
    1030:	2c 16 00 02 	cmpwi   r22,2
    1034:	40 80 00 54 	bge     1088 <fn_800614A8+0x1088>
    1038:	48 00 0a f4 	b       1b2c <fn_800614A8+0x1b2c>
    103c:	2c 16 00 69 	cmpwi   r22,105
    1040:	41 82 00 5c 	beq     109c <fn_800614A8+0x109c>
    1044:	40 80 0a e8 	bge     1b2c <fn_800614A8+0x1b2c>
    1048:	2c 16 00 68 	cmpwi   r22,104
    104c:	40 80 00 1c 	bge     1068 <fn_800614A8+0x1068>
    1050:	48 00 0a dc 	b       1b2c <fn_800614A8+0x1b2c>
    1054:	7f e3 fb 78 	mr      r3,r31
    1058:	7f c4 f3 78 	mr      r4,r30
    105c:	48 00 00 01 	bl      105c <fn_800614A8+0x105c>
			105c: R_PPC_REL24	fn_800C9B74
    1060:	38 60 00 01 	li      r3,1
    1064:	48 00 0a c8 	b       1b2c <fn_800614A8+0x1b2c>
    1068:	7f e3 fb 78 	mr      r3,r31
    106c:	38 80 00 01 	li      r4,1
    1070:	48 00 00 01 	bl      1070 <fn_800614A8+0x1070>
			1070: R_PPC_REL24	fn_80201D2C
    1074:	7f e3 fb 78 	mr      r3,r31
    1078:	38 80 00 01 	li      r4,1
    107c:	48 00 00 01 	bl      107c <fn_800614A8+0x107c>
			107c: R_PPC_REL24	fn_80201D14
    1080:	38 60 00 01 	li      r3,1
    1084:	48 00 0a a8 	b       1b2c <fn_800614A8+0x1b2c>
    1088:	7f e3 fb 78 	mr      r3,r31
    108c:	7f c4 f3 78 	mr      r4,r30
    1090:	48 00 00 01 	bl      1090 <fn_800614A8+0x1090>
			1090: R_PPC_REL24	fn_800C9AD4
    1094:	38 60 00 01 	li      r3,1
    1098:	48 00 0a 94 	b       1b2c <fn_800614A8+0x1b2c>
    109c:	38 60 00 01 	li      r3,1
    10a0:	48 00 0a 8c 	b       1b2c <fn_800614A8+0x1b2c>
    10a4:	38 60 00 01 	li      r3,1
    10a8:	48 00 0a 84 	b       1b2c <fn_800614A8+0x1b2c>
    10ac:	2c 16 00 05 	cmpwi   r22,5
    10b0:	41 82 00 4c 	beq     10fc <fn_800614A8+0x10fc>
    10b4:	40 80 00 1c 	bge     10d0 <fn_800614A8+0x10d0>
    10b8:	2c 16 00 03 	cmpwi   r22,3
    10bc:	41 82 00 20 	beq     10dc <fn_800614A8+0x10dc>
    10c0:	40 80 0a 6c 	bge     1b2c <fn_800614A8+0x1b2c>
    10c4:	2c 16 00 02 	cmpwi   r22,2
    10c8:	40 80 01 ac 	bge     1274 <fn_800614A8+0x1274>
    10cc:	48 00 0a 60 	b       1b2c <fn_800614A8+0x1b2c>
    10d0:	2c 16 00 3d 	cmpwi   r22,61
    10d4:	41 82 01 6c 	beq     1240 <fn_800614A8+0x1240>
    10d8:	48 00 0a 54 	b       1b2c <fn_800614A8+0x1b2c>
    10dc:	7f 83 e3 78 	mr      r3,r28
    10e0:	7f e4 fb 78 	mr      r4,r31
    10e4:	7f c5 f3 78 	mr      r5,r30
    10e8:	7f 66 db 78 	mr      r6,r27
    10ec:	7f 47 d3 78 	mr      r7,r26
    10f0:	48 00 00 01 	bl      10f0 <fn_800614A8+0x10f0>
			10f0: R_PPC_REL24	fn_8005FD84
    10f4:	38 60 00 01 	li      r3,1
    10f8:	48 00 0a 34 	b       1b2c <fn_800614A8+0x1b2c>
    10fc:	7f e3 fb 78 	mr      r3,r31
    1100:	3a 00 00 00 	li      r16,0
    1104:	38 80 00 03 	li      r4,3
    1108:	48 00 00 01 	bl      1108 <fn_800614A8+0x1108>
			1108: R_PPC_REL24	fn_80066D04
    110c:	2c 03 00 00 	cmpwi   r3,0
    1110:	40 82 00 1c 	bne     112c <fn_800614A8+0x112c>
    1114:	7f e3 fb 78 	mr      r3,r31
    1118:	38 80 00 02 	li      r4,2
    111c:	48 00 00 01 	bl      111c <fn_800614A8+0x111c>
			111c: R_PPC_REL24	fn_80066D04
    1120:	2c 03 00 00 	cmpwi   r3,0
    1124:	40 82 00 08 	bne     112c <fn_800614A8+0x112c>
    1128:	3a 00 00 01 	li      r16,1
    112c:	7f c3 f3 78 	mr      r3,r30
    1130:	48 00 00 01 	bl      1130 <fn_800614A8+0x1130>
			1130: R_PPC_REL24	fn_8012B344
    1134:	7f e3 fb 78 	mr      r3,r31
    1138:	38 81 00 10 	addi    r4,r1,16
    113c:	48 00 00 01 	bl      113c <fn_800614A8+0x113c>
			113c: R_PPC_REL24	fn_802045AC
    1140:	c0 21 00 18 	lfs     f1,24(r1)
    1144:	c0 01 00 10 	lfs     f0,16(r1)
    1148:	fc 20 08 1e 	fctiwz  f1,f1
    114c:	80 81 00 1c 	lwz     r4,28(r1)
    1150:	fc 00 00 1e 	fctiwz  f0,f0
    1154:	80 c1 00 14 	lwz     r6,20(r1)
    1158:	d8 21 00 90 	stfd    f1,144(r1)
    115c:	d8 01 00 98 	stfd    f0,152(r1)
    1160:	80 61 00 94 	lwz     r3,148(r1)
    1164:	80 a1 00 9c 	lwz     r5,156(r1)
    1168:	48 00 00 01 	bl      1168 <fn_800614A8+0x1168>
			1168: R_PPC_REL24	fn_80179064
    116c:	2c 10 00 00 	cmpwi   r16,0
    1170:	40 82 00 b0 	bne     1220 <fn_800614A8+0x1220>
    1174:	3a 20 00 01 	li      r17,1
    1178:	48 00 00 01 	bl      1178 <fn_800614A8+0x1178>
			1178: R_PPC_REL24	fn_800FBFB0
    117c:	54 60 07 ff 	clrlwi. r0,r3,31
    1180:	41 82 00 7c 	beq     11fc <fn_800614A8+0x11fc>
    1184:	88 1a 00 89 	lbz     r0,137(r26)
    1188:	54 00 07 ff 	clrlwi. r0,r0,31
    118c:	41 82 00 70 	beq     11fc <fn_800614A8+0x11fc>
    1190:	48 00 00 01 	bl      1190 <fn_800614A8+0x1190>
			1190: R_PPC_REL24	fn_801A717C
    1194:	88 1a 00 89 	lbz     r0,137(r26)
    1198:	7c 6f 1b 78 	mr      r15,r3
    119c:	38 60 00 10 	li      r3,16
    11a0:	54 00 06 3c 	rlwinm  r0,r0,0,24,30
    11a4:	98 1a 00 89 	stb     r0,137(r26)
    11a8:	48 00 00 01 	bl      11a8 <fn_800614A8+0x11a8>
			11a8: R_PPC_REL24	fn_801A7470
    11ac:	7d e3 7b 78 	mr      r3,r15
    11b0:	7f 84 e3 78 	mr      r4,r28
    11b4:	48 00 00 01 	bl      11b4 <fn_800614A8+0x11b4>
			11b4: R_PPC_REL24	fn_801A74A0
    11b8:	7d e3 7b 78 	mr      r3,r15
    11bc:	7f 84 e3 78 	mr      r4,r28
    11c0:	48 00 00 01 	bl      11c0 <fn_800614A8+0x11c0>
			11c0: R_PPC_REL24	fn_801A74A8
    11c4:	7d e3 7b 78 	mr      r3,r15
    11c8:	38 81 00 18 	addi    r4,r1,24
    11cc:	48 00 00 01 	bl      11cc <fn_800614A8+0x11cc>
			11cc: R_PPC_REL24	fn_801A764C
    11d0:	7f 84 e3 78 	mr      r4,r28
    11d4:	7f 85 e3 78 	mr      r5,r28
    11d8:	7d e6 7b 78 	mr      r6,r15
    11dc:	38 60 00 35 	li      r3,53
    11e0:	48 00 00 01 	bl      11e0 <fn_800614A8+0x11e0>
			11e0: R_PPC_REL24	fn_8020123C
    11e4:	7c 90 23 78 	mr      r16,r4
    11e8:	7d e3 7b 78 	mr      r3,r15
    11ec:	48 00 00 01 	bl      11ec <fn_800614A8+0x11ec>
			11ec: R_PPC_REL24	fn_801A7228
    11f0:	56 00 07 ff 	clrlwi. r0,r16,31
    11f4:	41 82 00 08 	beq     11fc <fn_800614A8+0x11fc>
    11f8:	3a 20 00 00 	li      r17,0
    11fc:	2c 11 00 00 	cmpwi   r17,0
    1200:	41 82 00 38 	beq     1238 <fn_800614A8+0x1238>
    1204:	7f e3 fb 78 	mr      r3,r31
    1208:	38 80 00 01 	li      r4,1
    120c:	48 00 00 01 	bl      120c <fn_800614A8+0x120c>
			120c: R_PPC_REL24	fn_80201D2C
    1210:	7f e3 fb 78 	mr      r3,r31
    1214:	38 80 00 01 	li      r4,1
    1218:	48 00 00 01 	bl      1218 <fn_800614A8+0x1218>
			1218: R_PPC_REL24	fn_80201D14
    121c:	48 00 00 1c 	b       1238 <fn_800614A8+0x1238>
    1220:	7f e3 fb 78 	mr      r3,r31
    1224:	38 80 00 01 	li      r4,1
    1228:	48 00 00 01 	bl      1228 <fn_800614A8+0x1228>
			1228: R_PPC_REL24	fn_80201D2C
    122c:	7f e3 fb 78 	mr      r3,r31
    1230:	38 80 00 01 	li      r4,1
    1234:	48 00 00 01 	bl      1234 <fn_800614A8+0x1234>
			1234: R_PPC_REL24	fn_80201D14
    1238:	38 60 00 01 	li      r3,1
    123c:	48 00 08 f0 	b       1b2c <fn_800614A8+0x1b2c>
    1240:	7f e3 fb 78 	mr      r3,r31
    1244:	7f a4 eb 78 	mr      r4,r29
    1248:	48 00 00 01 	bl      1248 <fn_800614A8+0x1248>
			1248: R_PPC_REL24	fn_800EA3A0
    124c:	7f c3 f3 78 	mr      r3,r30
    1250:	48 00 00 01 	bl      1250 <fn_800614A8+0x1250>
			1250: R_PPC_REL24	fn_8012B344
    1254:	7f e3 fb 78 	mr      r3,r31
    1258:	38 80 00 01 	li      r4,1
    125c:	48 00 00 01 	bl      125c <fn_800614A8+0x125c>
			125c: R_PPC_REL24	fn_80201D2C
    1260:	7f e3 fb 78 	mr      r3,r31
    1264:	38 80 00 01 	li      r4,1
    1268:	48 00 00 01 	bl      1268 <fn_800614A8+0x1268>
			1268: R_PPC_REL24	fn_80201D14
    126c:	38 60 00 01 	li      r3,1
    1270:	48 00 08 bc 	b       1b2c <fn_800614A8+0x1b2c>
    1274:	7f 83 e3 78 	mr      r3,r28
    1278:	7f 84 e3 78 	mr      r4,r28
    127c:	38 a0 00 56 	li      r5,86
    1280:	38 c0 00 05 	li      r6,5
    1284:	38 e0 00 00 	li      r7,0
    1288:	48 00 00 01 	bl      1288 <fn_800614A8+0x1288>
			1288: R_PPC_REL24	fn_802006D4
    128c:	38 60 00 01 	li      r3,1
    1290:	48 00 08 9c 	b       1b2c <fn_800614A8+0x1b2c>
    1294:	2c 16 00 05 	cmpwi   r22,5
    1298:	41 82 00 4c 	beq     12e4 <fn_800614A8+0x12e4>
    129c:	40 80 00 1c 	bge     12b8 <fn_800614A8+0x12b8>
    12a0:	2c 16 00 03 	cmpwi   r22,3
    12a4:	41 82 00 20 	beq     12c4 <fn_800614A8+0x12c4>
    12a8:	40 80 08 84 	bge     1b2c <fn_800614A8+0x1b2c>
    12ac:	2c 16 00 02 	cmpwi   r22,2
    12b0:	40 80 00 90 	bge     1340 <fn_800614A8+0x1340>
    12b4:	48 00 08 78 	b       1b2c <fn_800614A8+0x1b2c>
    12b8:	2c 16 00 3d 	cmpwi   r22,61
    12bc:	41 82 00 50 	beq     130c <fn_800614A8+0x130c>
    12c0:	48 00 08 6c 	b       1b2c <fn_800614A8+0x1b2c>
    12c4:	7f 83 e3 78 	mr      r3,r28
    12c8:	7f e4 fb 78 	mr      r4,r31
    12cc:	7f c5 f3 78 	mr      r5,r30
    12d0:	7f 66 db 78 	mr      r6,r27
    12d4:	7f 47 d3 78 	mr      r7,r26
    12d8:	48 00 00 01 	bl      12d8 <fn_800614A8+0x12d8>
			12d8: R_PPC_REL24	fn_8005FD84
    12dc:	38 60 00 01 	li      r3,1
    12e0:	48 00 08 4c 	b       1b2c <fn_800614A8+0x1b2c>
    12e4:	7f c3 f3 78 	mr      r3,r30
    12e8:	48 00 00 01 	bl      12e8 <fn_800614A8+0x12e8>
			12e8: R_PPC_REL24	fn_8012B344
    12ec:	7f e3 fb 78 	mr      r3,r31
    12f0:	38 80 00 01 	li      r4,1
    12f4:	48 00 00 01 	bl      12f4 <fn_800614A8+0x12f4>
			12f4: R_PPC_REL24	fn_80201D2C
    12f8:	7f e3 fb 78 	mr      r3,r31
    12fc:	38 80 00 01 	li      r4,1
    1300:	48 00 00 01 	bl      1300 <fn_800614A8+0x1300>
			1300: R_PPC_REL24	fn_80201D14
    1304:	38 60 00 01 	li      r3,1
    1308:	48 00 08 24 	b       1b2c <fn_800614A8+0x1b2c>
    130c:	7f e3 fb 78 	mr      r3,r31
    1310:	7f a4 eb 78 	mr      r4,r29
    1314:	48 00 00 01 	bl      1314 <fn_800614A8+0x1314>
			1314: R_PPC_REL24	fn_800EA3A0
    1318:	7f c3 f3 78 	mr      r3,r30
    131c:	48 00 00 01 	bl      131c <fn_800614A8+0x131c>
			131c: R_PPC_REL24	fn_8012B344
    1320:	7f e3 fb 78 	mr      r3,r31
    1324:	38 80 00 01 	li      r4,1
    1328:	48 00 00 01 	bl      1328 <fn_800614A8+0x1328>
			1328: R_PPC_REL24	fn_80201D2C
    132c:	7f e3 fb 78 	mr      r3,r31
    1330:	38 80 00 01 	li      r4,1
    1334:	48 00 00 01 	bl      1334 <fn_800614A8+0x1334>
			1334: R_PPC_REL24	fn_80201D14
    1338:	38 60 00 01 	li      r3,1
    133c:	48 00 07 f0 	b       1b2c <fn_800614A8+0x1b2c>
    1340:	7f 83 e3 78 	mr      r3,r28
    1344:	7f 84 e3 78 	mr      r4,r28
    1348:	38 a0 00 59 	li      r5,89
    134c:	38 c0 00 05 	li      r6,5
    1350:	38 e0 00 00 	li      r7,0
    1354:	48 00 00 01 	bl      1354 <fn_800614A8+0x1354>
			1354: R_PPC_REL24	fn_802006D4
    1358:	38 60 00 01 	li      r3,1
    135c:	48 00 07 d0 	b       1b2c <fn_800614A8+0x1b2c>
    1360:	2c 16 00 07 	cmpwi   r22,7
    1364:	41 82 00 6c 	beq     13d0 <fn_800614A8+0x13d0>
    1368:	40 80 00 10 	bge     1378 <fn_800614A8+0x1378>
    136c:	2c 16 00 03 	cmpwi   r22,3
    1370:	41 82 00 20 	beq     1390 <fn_800614A8+0x1390>
    1374:	48 00 07 b8 	b       1b2c <fn_800614A8+0x1b2c>
    1378:	2c 16 00 36 	cmpwi   r22,54
    137c:	41 82 00 34 	beq     13b0 <fn_800614A8+0x13b0>
    1380:	40 80 07 ac 	bge     1b2c <fn_800614A8+0x1b2c>
    1384:	2c 16 00 35 	cmpwi   r22,53
    1388:	40 80 00 8c 	bge     1414 <fn_800614A8+0x1414>
    138c:	48 00 07 a0 	b       1b2c <fn_800614A8+0x1b2c>
    1390:	7f 83 e3 78 	mr      r3,r28
    1394:	7f e4 fb 78 	mr      r4,r31
    1398:	7f c5 f3 78 	mr      r5,r30
    139c:	7f 66 db 78 	mr      r6,r27
    13a0:	7f 47 d3 78 	mr      r7,r26
    13a4:	48 00 00 01 	bl      13a4 <fn_800614A8+0x13a4>
			13a4: R_PPC_REL24	fn_8005FD84
    13a8:	38 60 00 01 	li      r3,1
    13ac:	48 00 07 80 	b       1b2c <fn_800614A8+0x1b2c>
    13b0:	7f e3 fb 78 	mr      r3,r31
    13b4:	38 80 00 01 	li      r4,1
    13b8:	48 00 00 01 	bl      13b8 <fn_800614A8+0x13b8>
			13b8: R_PPC_REL24	fn_80201D2C
    13bc:	7f e3 fb 78 	mr      r3,r31
    13c0:	38 80 00 01 	li      r4,1
    13c4:	48 00 00 01 	bl      13c4 <fn_800614A8+0x13c4>
			13c4: R_PPC_REL24	fn_80201D14
    13c8:	38 60 00 01 	li      r3,1
    13cc:	48 00 07 60 	b       1b2c <fn_800614A8+0x1b2c>
    13d0:	7f e3 fb 78 	mr      r3,r31
    13d4:	38 95 01 f0 	addi    r4,r21,496
    13d8:	38 d5 01 cc 	addi    r6,r21,460
    13dc:	39 15 01 d8 	addi    r8,r21,472
    13e0:	38 a0 00 00 	li      r5,0
			13e0: R_PPC_EMB_SDA21	lbl_8064B518
    13e4:	38 e0 00 00 	li      r7,0
			13e4: R_PPC_EMB_SDA21	lbl_8064B510
    13e8:	48 00 00 01 	bl      13e8 <fn_800614A8+0x13e8>
			13e8: R_PPC_REL24	fn_80035FB8
    13ec:	2c 03 00 00 	cmpwi   r3,0
    13f0:	40 82 00 1c 	bne     140c <fn_800614A8+0x140c>
    13f4:	7f e3 fb 78 	mr      r3,r31
    13f8:	38 80 00 01 	li      r4,1
    13fc:	48 00 00 01 	bl      13fc <fn_800614A8+0x13fc>
			13fc: R_PPC_REL24	fn_80201D2C
    1400:	7f e3 fb 78 	mr      r3,r31
    1404:	38 80 00 01 	li      r4,1
    1408:	48 00 00 01 	bl      1408 <fn_800614A8+0x1408>
			1408: R_PPC_REL24	fn_80201D14
    140c:	38 60 00 01 	li      r3,1
    1410:	48 00 07 1c 	b       1b2c <fn_800614A8+0x1b2c>
    1414:	38 60 00 01 	li      r3,1
    1418:	48 00 07 14 	b       1b2c <fn_800614A8+0x1b2c>
    141c:	2c 16 00 07 	cmpwi   r22,7
    1420:	41 82 00 f0 	beq     1510 <fn_800614A8+0x1510>
    1424:	40 80 00 2c 	bge     1450 <fn_800614A8+0x1450>
    1428:	2c 16 00 04 	cmpwi   r22,4
    142c:	41 82 07 00 	beq     1b2c <fn_800614A8+0x1b2c>
    1430:	40 80 00 14 	bge     1444 <fn_800614A8+0x1444>
    1434:	2c 16 00 02 	cmpwi   r22,2
    1438:	41 82 01 50 	beq     1588 <fn_800614A8+0x1588>
    143c:	40 80 00 38 	bge     1474 <fn_800614A8+0x1474>
    1440:	48 00 06 ec 	b       1b2c <fn_800614A8+0x1b2c>
    1444:	2c 16 00 06 	cmpwi   r22,6
    1448:	40 80 06 e4 	bge     1b2c <fn_800614A8+0x1b2c>
    144c:	48 00 00 48 	b       1494 <fn_800614A8+0x1494>
    1450:	2c 16 00 3d 	cmpwi   r22,61
    1454:	41 82 01 00 	beq     1554 <fn_800614A8+0x1554>
    1458:	40 80 00 10 	bge     1468 <fn_800614A8+0x1468>
    145c:	2c 16 00 35 	cmpwi   r22,53
    1460:	41 82 01 48 	beq     15a8 <fn_800614A8+0x15a8>
    1464:	48 00 06 c8 	b       1b2c <fn_800614A8+0x1b2c>
    1468:	2c 16 00 67 	cmpwi   r22,103
    146c:	41 82 01 44 	beq     15b0 <fn_800614A8+0x15b0>
    1470:	48 00 06 bc 	b       1b2c <fn_800614A8+0x1b2c>
    1474:	7f 83 e3 78 	mr      r3,r28
    1478:	7f e4 fb 78 	mr      r4,r31
    147c:	7f c5 f3 78 	mr      r5,r30
    1480:	7f 66 db 78 	mr      r6,r27
    1484:	7f 47 d3 78 	mr      r7,r26
    1488:	48 00 00 01 	bl      1488 <fn_800614A8+0x1488>
			1488: R_PPC_REL24	fn_8005FD84
    148c:	38 60 00 01 	li      r3,1
    1490:	48 00 06 9c 	b       1b2c <fn_800614A8+0x1b2c>
    1494:	7f c3 f3 78 	mr      r3,r30
    1498:	48 00 00 01 	bl      1498 <fn_800614A8+0x1498>
			1498: R_PPC_REL24	fn_80128EAC
    149c:	7c 71 1b 78 	mr      r17,r3
    14a0:	7f c3 f3 78 	mr      r3,r30
    14a4:	48 00 00 01 	bl      14a4 <fn_800614A8+0x14a4>
			14a4: R_PPC_REL24	fn_801290D0
    14a8:	7c 70 1b 78 	mr      r16,r3
    14ac:	7f c3 f3 78 	mr      r3,r30
    14b0:	48 00 00 01 	bl      14b0 <fn_800614A8+0x14b0>
			14b0: R_PPC_REL24	fn_80128E30
    14b4:	28 03 00 00 	cmplwi  r3,0
    14b8:	41 82 00 38 	beq     14f0 <fn_800614A8+0x14f0>
    14bc:	2c 11 00 0f 	cmpwi   r17,15
    14c0:	40 82 00 30 	bne     14f0 <fn_800614A8+0x14f0>
    14c4:	56 00 07 ff 	clrlwi. r0,r16,31
    14c8:	41 82 00 28 	beq     14f0 <fn_800614A8+0x14f0>
    14cc:	7f c3 f3 78 	mr      r3,r30
    14d0:	48 00 00 01 	bl      14d0 <fn_800614A8+0x14d0>
			14d0: R_PPC_REL24	fn_8012B344
    14d4:	7f e3 fb 78 	mr      r3,r31
    14d8:	38 80 00 01 	li      r4,1
    14dc:	48 00 00 01 	bl      14dc <fn_800614A8+0x14dc>
			14dc: R_PPC_REL24	fn_80201D2C
    14e0:	7f e3 fb 78 	mr      r3,r31
    14e4:	38 80 00 01 	li      r4,1
    14e8:	48 00 00 01 	bl      14e8 <fn_800614A8+0x14e8>
			14e8: R_PPC_REL24	fn_80201D14
    14ec:	48 00 00 1c 	b       1508 <fn_800614A8+0x1508>
    14f0:	7f e3 fb 78 	mr      r3,r31
    14f4:	38 80 00 01 	li      r4,1
    14f8:	48 00 00 01 	bl      14f8 <fn_800614A8+0x14f8>
			14f8: R_PPC_REL24	fn_80201D2C
    14fc:	7f e3 fb 78 	mr      r3,r31
    1500:	38 80 00 01 	li      r4,1
    1504:	48 00 00 01 	bl      1504 <fn_800614A8+0x1504>
			1504: R_PPC_REL24	fn_80201D14
    1508:	38 60 00 01 	li      r3,1
    150c:	48 00 06 20 	b       1b2c <fn_800614A8+0x1b2c>
    1510:	7f e3 fb 78 	mr      r3,r31
    1514:	38 95 01 f0 	addi    r4,r21,496
    1518:	38 d5 01 cc 	addi    r6,r21,460
    151c:	39 15 01 d8 	addi    r8,r21,472
    1520:	38 a0 00 00 	li      r5,0
			1520: R_PPC_EMB_SDA21	lbl_8064B51C
    1524:	38 e0 00 00 	li      r7,0
			1524: R_PPC_EMB_SDA21	lbl_8064B510
    1528:	48 00 00 01 	bl      1528 <fn_800614A8+0x1528>
			1528: R_PPC_REL24	fn_80035FB8
    152c:	2c 03 00 00 	cmpwi   r3,0
    1530:	40 82 00 1c 	bne     154c <fn_800614A8+0x154c>
    1534:	7f e3 fb 78 	mr      r3,r31
    1538:	38 80 00 01 	li      r4,1
    153c:	48 00 00 01 	bl      153c <fn_800614A8+0x153c>
			153c: R_PPC_REL24	fn_80201D2C
    1540:	7f e3 fb 78 	mr      r3,r31
    1544:	38 80 00 01 	li      r4,1
    1548:	48 00 00 01 	bl      1548 <fn_800614A8+0x1548>
			1548: R_PPC_REL24	fn_80201D14
    154c:	38 60 00 01 	li      r3,1
    1550:	48 00 05 dc 	b       1b2c <fn_800614A8+0x1b2c>
    1554:	7f e3 fb 78 	mr      r3,r31
    1558:	7f a4 eb 78 	mr      r4,r29
    155c:	48 00 00 01 	bl      155c <fn_800614A8+0x155c>
			155c: R_PPC_REL24	fn_800EA3A0
    1560:	7f e3 fb 78 	mr      r3,r31
    1564:	7f a4 eb 78 	mr      r4,r29
    1568:	48 00 00 01 	bl      1568 <fn_800614A8+0x1568>
			1568: R_PPC_REL24	fn_800BD2DC
    156c:	7f 84 e3 78 	mr      r4,r28
    1570:	7f 85 e3 78 	mr      r5,r28
    1574:	38 60 00 05 	li      r3,5
    1578:	38 c0 00 00 	li      r6,0
    157c:	48 00 00 01 	bl      157c <fn_800614A8+0x157c>
			157c: R_PPC_REL24	fn_8020123C
    1580:	38 60 00 01 	li      r3,1
    1584:	48 00 05 a8 	b       1b2c <fn_800614A8+0x1b2c>
    1588:	7f 83 e3 78 	mr      r3,r28
    158c:	7f 84 e3 78 	mr      r4,r28
    1590:	38 a0 00 20 	li      r5,32
    1594:	38 c0 00 05 	li      r6,5
    1598:	38 e0 00 00 	li      r7,0
    159c:	48 00 00 01 	bl      159c <fn_800614A8+0x159c>
			159c: R_PPC_REL24	fn_802006D4
    15a0:	38 60 00 01 	li      r3,1
    15a4:	48 00 05 88 	b       1b2c <fn_800614A8+0x1b2c>
    15a8:	38 60 00 01 	li      r3,1
    15ac:	48 00 05 80 	b       1b2c <fn_800614A8+0x1b2c>
    15b0:	38 60 00 01 	li      r3,1
    15b4:	48 00 05 78 	b       1b2c <fn_800614A8+0x1b2c>
    15b8:	2c 16 00 01 	cmpwi   r22,1
    15bc:	40 82 00 60 	bne     161c <fn_800614A8+0x161c>
    15c0:	7f c3 f3 78 	mr      r3,r30
    15c4:	48 00 00 01 	bl      15c4 <fn_800614A8+0x15c4>
			15c4: R_PPC_REL24	fn_80128EAC
    15c8:	7f c3 f3 78 	mr      r3,r30
    15cc:	48 00 00 01 	bl      15cc <fn_800614A8+0x15cc>
			15cc: R_PPC_REL24	fn_801290D0
    15d0:	7f e3 fb 78 	mr      r3,r31
    15d4:	38 80 00 00 	li      r4,0
    15d8:	48 00 00 01 	bl      15d8 <fn_800614A8+0x15d8>
			15d8: R_PPC_REL24	fn_80201350
    15dc:	88 7b 00 9f 	lbz     r3,159(r27)
    15e0:	48 00 00 01 	bl      15e0 <fn_800614A8+0x15e0>
			15e0: R_PPC_REL24	fn_800CA13C
    15e4:	54 64 08 3c 	slwi    r4,r3,1
    15e8:	7f e3 fb 78 	mr      r3,r31
    15ec:	38 a0 00 00 	li      r5,0
    15f0:	48 00 00 01 	bl      15f0 <fn_800614A8+0x15f0>
			15f0: R_PPC_REL24	fn_800E0708
    15f4:	7f e3 fb 78 	mr      r3,r31
    15f8:	38 80 00 01 	li      r4,1
    15fc:	38 a0 00 00 	li      r5,0
    1600:	48 00 00 01 	bl      1600 <fn_800614A8+0x1600>
			1600: R_PPC_REL24	fn_800CC860
    1604:	7f 83 e3 78 	mr      r3,r28
    1608:	48 00 00 01 	bl      1608 <fn_800614A8+0x1608>
			1608: R_PPC_REL24	fn_800BE8D4
    160c:	7f e3 fb 78 	mr      r3,r31
    1610:	48 00 00 01 	bl      1610 <fn_800614A8+0x1610>
			1610: R_PPC_REL24	fn_800CA2C8
    1614:	38 60 00 01 	li      r3,1
    1618:	48 00 05 14 	b       1b2c <fn_800614A8+0x1b2c>
    161c:	2c 16 00 03 	cmpwi   r22,3
    1620:	40 82 00 30 	bne     1650 <fn_800614A8+0x1650>
    1624:	7f c3 f3 78 	mr      r3,r30
    1628:	48 00 00 01 	bl      1628 <fn_800614A8+0x1628>
			1628: R_PPC_REL24	fn_80128EAC
    162c:	7f c3 f3 78 	mr      r3,r30
    1630:	48 00 00 01 	bl      1630 <fn_800614A8+0x1630>
			1630: R_PPC_REL24	fn_801290D0
    1634:	7f e3 fb 78 	mr      r3,r31
    1638:	7f c4 f3 78 	mr      r4,r30
    163c:	7f 85 e3 78 	mr      r5,r28
    1640:	7f a6 eb 78 	mr      r6,r29
    1644:	48 00 00 01 	bl      1644 <fn_800614A8+0x1644>
			1644: R_PPC_REL24	fn_8003E5DC
    1648:	38 60 00 01 	li      r3,1
    164c:	48 00 04 e0 	b       1b2c <fn_800614A8+0x1b2c>
    1650:	2c 16 00 3d 	cmpwi   r22,61
    1654:	40 82 00 2c 	bne     1680 <fn_800614A8+0x1680>
    1658:	7f e3 fb 78 	mr      r3,r31
    165c:	7f a4 eb 78 	mr      r4,r29
    1660:	48 00 00 01 	bl      1660 <fn_800614A8+0x1660>
			1660: R_PPC_REL24	fn_800EA3A0
    1664:	7f 84 e3 78 	mr      r4,r28
    1668:	7f 85 e3 78 	mr      r5,r28
    166c:	38 60 00 39 	li      r3,57
    1670:	38 c0 00 00 	li      r6,0
    1674:	48 00 00 01 	bl      1674 <fn_800614A8+0x1674>
			1674: R_PPC_REL24	fn_8020123C
    1678:	38 60 00 01 	li      r3,1
    167c:	48 00 04 b0 	b       1b2c <fn_800614A8+0x1b2c>
    1680:	2c 16 00 c1 	cmpwi   r22,193
    1684:	40 82 00 24 	bne     16a8 <fn_800614A8+0x16a8>
    1688:	28 19 00 00 	cmplwi  r25,0
    168c:	41 82 00 14 	beq     16a0 <fn_800614A8+0x16a0>
    1690:	7f c3 f3 78 	mr      r3,r30
    1694:	7f 64 db 78 	mr      r4,r27
    1698:	48 00 00 01 	bl      1698 <fn_800614A8+0x1698>
			1698: R_PPC_REL24	fn_800C9BA8
    169c:	90 79 00 00 	stw     r3,0(r25)
    16a0:	38 60 00 01 	li      r3,1
    16a4:	48 00 04 88 	b       1b2c <fn_800614A8+0x1b2c>
    16a8:	2c 16 00 2f 	cmpwi   r22,47
    16ac:	40 82 00 24 	bne     16d0 <fn_800614A8+0x16d0>
    16b0:	7f e3 fb 78 	mr      r3,r31
    16b4:	38 80 00 1f 	li      r4,31
    16b8:	48 00 00 01 	bl      16b8 <fn_800614A8+0x16b8>
			16b8: R_PPC_REL24	fn_80201D2C
    16bc:	7f e3 fb 78 	mr      r3,r31
    16c0:	38 80 00 01 	li      r4,1
    16c4:	48 00 00 01 	bl      16c4 <fn_800614A8+0x16c4>
			16c4: R_PPC_REL24	fn_80201D14
    16c8:	38 60 00 01 	li      r3,1
    16cc:	48 00 04 60 	b       1b2c <fn_800614A8+0x1b2c>
    16d0:	2c 16 00 c2 	cmpwi   r22,194
    16d4:	40 82 00 20 	bne     16f4 <fn_800614A8+0x16f4>
    16d8:	7f e3 fb 78 	mr      r3,r31
    16dc:	7f c4 f3 78 	mr      r4,r30
    16e0:	7f 05 c3 78 	mr      r5,r24
    16e4:	7f 26 cb 78 	mr      r6,r25
    16e8:	48 00 00 01 	bl      16e8 <fn_800614A8+0x16e8>
			16e8: R_PPC_REL24	fn_800CA1BC
    16ec:	38 60 00 01 	li      r3,1
    16f0:	48 00 04 3c 	b       1b2c <fn_800614A8+0x1b2c>
    16f4:	2c 16 00 11 	cmpwi   r22,17
    16f8:	40 82 00 78 	bne     1770 <fn_800614A8+0x1770>
    16fc:	7f e3 fb 78 	mr      r3,r31
    1700:	48 00 00 01 	bl      1700 <fn_800614A8+0x1700>
			1700: R_PPC_REL24	fn_8003C04C
    1704:	2c 03 00 00 	cmpwi   r3,0
    1708:	41 82 00 60 	beq     1768 <fn_800614A8+0x1768>
    170c:	7f e3 fb 78 	mr      r3,r31
    1710:	7f a4 eb 78 	mr      r4,r29
    1714:	48 00 00 01 	bl      1714 <fn_800614A8+0x1714>
			1714: R_PPC_REL24	fn_800EA3A0
    1718:	7f e3 fb 78 	mr      r3,r31
    171c:	48 00 00 01 	bl      171c <fn_800614A8+0x171c>
			171c: R_PPC_REL24	fn_800CF598
    1720:	c0 20 00 00 	lfs     f1,0(0)
			1720: R_PPC_EMB_SDA21	lbl_8064E62C
    1724:	7f c3 f3 78 	mr      r3,r30
    1728:	c0 40 00 00 	lfs     f2,0(0)
			1728: R_PPC_EMB_SDA21	lbl_8064E5DC
    172c:	38 80 00 00 	li      r4,0
    1730:	38 a0 00 00 	li      r5,0
    1734:	38 c0 01 01 	li      r6,257
    1738:	48 00 00 01 	bl      1738 <fn_800614A8+0x1738>
			1738: R_PPC_REL24	fn_80120AD0
    173c:	7f c3 f3 78 	mr      r3,r30
    1740:	38 80 00 28 	li      r4,40
    1744:	38 a0 00 21 	li      r5,33
    1748:	38 c0 00 0a 	li      r6,10
    174c:	48 00 00 01 	bl      174c <fn_800614A8+0x174c>
			174c: R_PPC_REL24	fn_801294DC
    1750:	7f e3 fb 78 	mr      r3,r31
    1754:	38 80 00 15 	li      r4,21
    1758:	48 00 00 01 	bl      1758 <fn_800614A8+0x1758>
			1758: R_PPC_REL24	fn_80201D34
    175c:	7f e3 fb 78 	mr      r3,r31
    1760:	38 80 00 01 	li      r4,1
    1764:	48 00 00 01 	bl      1764 <fn_800614A8+0x1764>
			1764: R_PPC_REL24	fn_80201D1C
    1768:	38 60 00 01 	li      r3,1
    176c:	48 00 03 c0 	b       1b2c <fn_800614A8+0x1b2c>
    1770:	2c 16 00 0b 	cmpwi   r22,11
    1774:	40 82 00 68 	bne     17dc <fn_800614A8+0x17dc>
    1778:	7f 03 c3 78 	mr      r3,r24
    177c:	48 00 00 01 	bl      177c <fn_800614A8+0x177c>
			177c: R_PPC_REL24	fn_80200C38
    1780:	7c 6f 1b 78 	mr      r15,r3
    1784:	48 00 00 01 	bl      1784 <fn_800614A8+0x1784>
			1784: R_PPC_REL24	fn_801A74C0
    1788:	54 60 06 b5 	rlwinm. r0,r3,0,26,26
    178c:	41 82 00 48 	beq     17d4 <fn_800614A8+0x17d4>
    1790:	7d e3 7b 78 	mr      r3,r15
    1794:	48 00 00 01 	bl      1794 <fn_800614A8+0x1794>
			1794: R_PPC_REL24	fn_800654F8
    1798:	7c 70 1b 78 	mr      r16,r3
    179c:	7f 84 e3 78 	mr      r4,r28
    17a0:	7f 85 e3 78 	mr      r5,r28
    17a4:	38 60 00 2f 	li      r3,47
    17a8:	38 c0 00 00 	li      r6,0
    17ac:	48 00 00 01 	bl      17ac <fn_800614A8+0x17ac>
			17ac: R_PPC_REL24	fn_8020123C
    17b0:	c0 20 00 00 	lfs     f1,0(0)
			17b0: R_PPC_EMB_SDA21	lbl_8064E630
    17b4:	7f 84 e3 78 	mr      r4,r28
    17b8:	7f 85 e3 78 	mr      r5,r28
    17bc:	38 60 00 31 	li      r3,49
    17c0:	38 c0 00 00 	li      r6,0
    17c4:	48 00 00 01 	bl      17c4 <fn_800614A8+0x17c4>
			17c4: R_PPC_REL24	fn_8020104C
    17c8:	28 19 00 00 	cmplwi  r25,0
    17cc:	41 82 00 08 	beq     17d4 <fn_800614A8+0x17d4>
    17d0:	92 19 00 00 	stw     r16,0(r25)
    17d4:	38 60 00 01 	li      r3,1
    17d8:	48 00 03 54 	b       1b2c <fn_800614A8+0x1b2c>
    17dc:	2c 16 00 35 	cmpwi   r22,53
    17e0:	40 82 00 28 	bne     1808 <fn_800614A8+0x1808>
    17e4:	7f 03 c3 78 	mr      r3,r24
    17e8:	48 00 00 01 	bl      17e8 <fn_800614A8+0x17e8>
			17e8: R_PPC_REL24	fn_80200C38
    17ec:	c0 20 00 00 	lfs     f1,0(0)
			17ec: R_PPC_EMB_SDA21	lbl_8064E614
    17f0:	7c 64 1b 78 	mr      r4,r3
    17f4:	c0 40 00 00 	lfs     f2,0(0)
			17f4: R_PPC_EMB_SDA21	lbl_8064E618
    17f8:	7f c3 f3 78 	mr      r3,r30
    17fc:	48 00 00 01 	bl      17fc <fn_800614A8+0x17fc>
			17fc: R_PPC_REL24	fn_80066888
    1800:	38 60 00 01 	li      r3,1
    1804:	48 00 03 28 	b       1b2c <fn_800614A8+0x1b2c>
    1808:	2c 16 00 34 	cmpwi   r22,52
    180c:	41 82 03 20 	beq     1b2c <fn_800614A8+0x1b2c>
    1810:	40 80 00 40 	bge     1850 <fn_800614A8+0x1850>
    1814:	2c 16 00 0b 	cmpwi   r22,11
    1818:	41 82 00 e8 	beq     1900 <fn_800614A8+0x1900>
    181c:	40 80 00 1c 	bge     1838 <fn_800614A8+0x1838>
    1820:	2c 16 00 08 	cmpwi   r22,8
    1824:	41 82 00 c4 	beq     18e8 <fn_800614A8+0x18e8>
    1828:	40 80 03 04 	bge     1b2c <fn_800614A8+0x1b2c>
    182c:	2c 16 00 02 	cmpwi   r22,2
    1830:	41 82 00 90 	beq     18c0 <fn_800614A8+0x18c0>
    1834:	48 00 02 f8 	b       1b2c <fn_800614A8+0x1b2c>
    1838:	2c 16 00 32 	cmpwi   r22,50
    183c:	41 82 00 bc 	beq     18f8 <fn_800614A8+0x18f8>
    1840:	40 80 00 64 	bge     18a4 <fn_800614A8+0x18a4>
    1844:	2c 16 00 27 	cmpwi   r22,39
    1848:	41 82 00 c0 	beq     1908 <fn_800614A8+0x1908>
    184c:	48 00 02 e0 	b       1b2c <fn_800614A8+0x1b2c>
    1850:	2c 16 00 4e 	cmpwi   r22,78
    1854:	41 82 00 38 	beq     188c <fn_800614A8+0x188c>
    1858:	40 80 00 1c 	bge     1874 <fn_800614A8+0x1874>
    185c:	2c 16 00 3b 	cmpwi   r22,59
    1860:	41 82 00 80 	beq     18e0 <fn_800614A8+0x18e0>
    1864:	40 80 02 c8 	bge     1b2c <fn_800614A8+0x1b2c>
    1868:	2c 16 00 36 	cmpwi   r22,54
    186c:	40 80 02 c0 	bge     1b2c <fn_800614A8+0x1b2c>
    1870:	48 00 00 80 	b       18f0 <fn_800614A8+0x18f0>
    1874:	2c 16 00 ea 	cmpwi   r22,234
    1878:	41 82 00 a0 	beq     1918 <fn_800614A8+0x1918>
    187c:	40 80 02 b0 	bge     1b2c <fn_800614A8+0x1b2c>
    1880:	2c 16 00 67 	cmpwi   r22,103
    1884:	41 82 00 8c 	beq     1910 <fn_800614A8+0x1910>
    1888:	48 00 02 a4 	b       1b2c <fn_800614A8+0x1b2c>
    188c:	28 19 00 00 	cmplwi  r25,0
    1890:	41 82 00 0c 	beq     189c <fn_800614A8+0x189c>
    1894:	38 00 00 00 	li      r0,0
    1898:	90 19 00 00 	stw     r0,0(r25)
    189c:	38 60 00 01 	li      r3,1
    18a0:	48 00 02 8c 	b       1b2c <fn_800614A8+0x1b2c>
    18a4:	7f 84 e3 78 	mr      r4,r28
    18a8:	7f 85 e3 78 	mr      r5,r28
    18ac:	38 60 00 39 	li      r3,57
    18b0:	38 c0 00 00 	li      r6,0
    18b4:	48 00 00 01 	bl      18b4 <fn_800614A8+0x18b4>
			18b4: R_PPC_REL24	fn_8020123C
    18b8:	38 60 00 01 	li      r3,1
    18bc:	48 00 02 70 	b       1b2c <fn_800614A8+0x1b2c>
    18c0:	7f 83 e3 78 	mr      r3,r28
    18c4:	7f 84 e3 78 	mr      r4,r28
    18c8:	38 a0 00 08 	li      r5,8
    18cc:	38 c0 00 11 	li      r6,17
    18d0:	38 e0 00 00 	li      r7,0
    18d4:	48 00 00 01 	bl      18d4 <fn_800614A8+0x18d4>
			18d4: R_PPC_REL24	fn_802006D4
    18d8:	38 60 00 01 	li      r3,1
    18dc:	48 00 02 50 	b       1b2c <fn_800614A8+0x1b2c>
    18e0:	38 60 00 01 	li      r3,1
    18e4:	48 00 02 48 	b       1b2c <fn_800614A8+0x1b2c>
    18e8:	38 60 00 01 	li      r3,1
    18ec:	48 00 02 40 	b       1b2c <fn_800614A8+0x1b2c>
    18f0:	38 60 00 01 	li      r3,1
    18f4:	48 00 02 38 	b       1b2c <fn_800614A8+0x1b2c>
    18f8:	38 60 00 01 	li      r3,1
    18fc:	48 00 02 30 	b       1b2c <fn_800614A8+0x1b2c>
    1900:	38 60 00 01 	li      r3,1
    1904:	48 00 02 28 	b       1b2c <fn_800614A8+0x1b2c>
    1908:	38 60 00 01 	li      r3,1
    190c:	48 00 02 20 	b       1b2c <fn_800614A8+0x1b2c>
    1910:	38 60 00 01 	li      r3,1
    1914:	48 00 02 18 	b       1b2c <fn_800614A8+0x1b2c>
    1918:	38 60 00 01 	li      r3,1
    191c:	48 00 02 10 	b       1b2c <fn_800614A8+0x1b2c>
    1920:	2c 16 00 32 	cmpwi   r22,50
    1924:	41 82 01 dc 	beq     1b00 <fn_800614A8+0x1b00>
    1928:	40 80 00 4c 	bge     1974 <fn_800614A8+0x1974>
    192c:	2c 16 00 11 	cmpwi   r22,17
    1930:	41 82 01 50 	beq     1a80 <fn_800614A8+0x1a80>
    1934:	40 80 00 28 	bge     195c <fn_800614A8+0x195c>
    1938:	2c 16 00 08 	cmpwi   r22,8
    193c:	41 82 01 b4 	beq     1af0 <fn_800614A8+0x1af0>
    1940:	40 80 00 10 	bge     1950 <fn_800614A8+0x1950>
    1944:	2c 16 00 01 	cmpwi   r22,1
    1948:	41 82 00 74 	beq     19bc <fn_800614A8+0x19bc>
    194c:	48 00 01 e0 	b       1b2c <fn_800614A8+0x1b2c>
    1950:	2c 16 00 0b 	cmpwi   r22,11
    1954:	41 82 01 b4 	beq     1b08 <fn_800614A8+0x1b08>
    1958:	48 00 01 d4 	b       1b2c <fn_800614A8+0x1b2c>
    195c:	2c 16 00 30 	cmpwi   r22,48
    1960:	41 82 00 c0 	beq     1a20 <fn_800614A8+0x1a20>
    1964:	40 80 00 dc 	bge     1a40 <fn_800614A8+0x1a40>
    1968:	2c 16 00 27 	cmpwi   r22,39
    196c:	41 82 01 a4 	beq     1b10 <fn_800614A8+0x1b10>
    1970:	48 00 01 bc 	b       1b2c <fn_800614A8+0x1b2c>
    1974:	2c 16 00 4e 	cmpwi   r22,78
    1978:	41 82 01 58 	beq     1ad0 <fn_800614A8+0x1ad0>
    197c:	40 80 00 28 	bge     19a4 <fn_800614A8+0x19a4>
    1980:	2c 16 00 3b 	cmpwi   r22,59
    1984:	41 82 01 64 	beq     1ae8 <fn_800614A8+0x1ae8>
    1988:	40 80 00 10 	bge     1998 <fn_800614A8+0x1998>
    198c:	2c 16 00 35 	cmpwi   r22,53
    1990:	41 82 01 68 	beq     1af8 <fn_800614A8+0x1af8>
    1994:	48 00 01 98 	b       1b2c <fn_800614A8+0x1b2c>
    1998:	2c 16 00 3d 	cmpwi   r22,61
    199c:	41 82 00 bc 	beq     1a58 <fn_800614A8+0x1a58>
    19a0:	48 00 01 8c 	b       1b2c <fn_800614A8+0x1b2c>
    19a4:	2c 16 00 ea 	cmpwi   r22,234
    19a8:	41 82 01 78 	beq     1b20 <fn_800614A8+0x1b20>
    19ac:	40 80 01 80 	bge     1b2c <fn_800614A8+0x1b2c>
    19b0:	2c 16 00 67 	cmpwi   r22,103
    19b4:	41 82 01 64 	beq     1b18 <fn_800614A8+0x1b18>
    19b8:	48 00 01 74 	b       1b2c <fn_800614A8+0x1b2c>
    19bc:	7f c3 f3 78 	mr      r3,r30
    19c0:	48 00 00 01 	bl      19c0 <fn_800614A8+0x19c0>
			19c0: R_PPC_REL24	fn_80128EAC
    19c4:	7f c3 f3 78 	mr      r3,r30
    19c8:	48 00 00 01 	bl      19c8 <fn_800614A8+0x19c8>
			19c8: R_PPC_REL24	fn_801290D0
    19cc:	7f 83 e3 78 	mr      r3,r28
    19d0:	48 00 00 01 	bl      19d0 <fn_800614A8+0x19d0>
			19d0: R_PPC_REL24	fn_800BE8D4
    19d4:	7f e3 fb 78 	mr      r3,r31
    19d8:	38 80 00 02 	li      r4,2
    19dc:	38 a0 00 03 	li      r5,3
    19e0:	48 00 00 01 	bl      19e0 <fn_800614A8+0x19e0>
			19e0: R_PPC_REL24	fn_800CC860
    19e4:	7f c3 f3 78 	mr      r3,r30
    19e8:	38 80 00 33 	li      r4,51
    19ec:	48 00 00 01 	bl      19ec <fn_800614A8+0x19ec>
			19ec: R_PPC_REL24	fn_801A977C
    19f0:	7f e3 fb 78 	mr      r3,r31
    19f4:	48 00 00 01 	bl      19f4 <fn_800614A8+0x19f4>
			19f4: R_PPC_REL24	fn_800CA2C8
    19f8:	7f e3 fb 78 	mr      r3,r31
    19fc:	48 00 00 01 	bl      19fc <fn_800614A8+0x19fc>
			19fc: R_PPC_REL24	fn_80204FDC
    1a00:	c0 20 00 00 	lfs     f1,0(0)
			1a00: R_PPC_EMB_SDA21	lbl_8064E634
    1a04:	7f 84 e3 78 	mr      r4,r28
    1a08:	7f 85 e3 78 	mr      r5,r28
    1a0c:	38 60 00 11 	li      r3,17
    1a10:	38 c0 00 00 	li      r6,0
    1a14:	48 00 00 01 	bl      1a14 <fn_800614A8+0x1a14>
			1a14: R_PPC_REL24	fn_8020104C
    1a18:	38 60 00 01 	li      r3,1
    1a1c:	48 00 01 10 	b       1b2c <fn_800614A8+0x1b2c>
    1a20:	7f 03 c3 78 	mr      r3,r24
    1a24:	48 00 00 01 	bl      1a24 <fn_800614A8+0x1a24>
			1a24: R_PPC_REL24	fn_80200C38
    1a28:	48 00 00 01 	bl      1a28 <fn_800614A8+0x1a28>
			1a28: R_PPC_REL24	fn_800654F8
    1a2c:	28 19 00 00 	cmplwi  r25,0
    1a30:	41 82 00 08 	beq     1a38 <fn_800614A8+0x1a38>
    1a34:	90 79 00 00 	stw     r3,0(r25)
    1a38:	38 60 00 01 	li      r3,1
    1a3c:	48 00 00 f0 	b       1b2c <fn_800614A8+0x1b2c>
    1a40:	7f e3 fb 78 	mr      r3,r31
    1a44:	7f c4 f3 78 	mr      r4,r30
    1a48:	7f 85 e3 78 	mr      r5,r28
    1a4c:	48 00 00 01 	bl      1a4c <fn_800614A8+0x1a4c>
			1a4c: R_PPC_REL24	fn_8003C114
    1a50:	38 60 00 01 	li      r3,1
    1a54:	48 00 00 d8 	b       1b2c <fn_800614A8+0x1b2c>
    1a58:	7f e3 fb 78 	mr      r3,r31
    1a5c:	7f a4 eb 78 	mr      r4,r29
    1a60:	48 00 00 01 	bl      1a60 <fn_800614A8+0x1a60>
			1a60: R_PPC_REL24	fn_800EA3A0
    1a64:	7f 84 e3 78 	mr      r4,r28
    1a68:	7f 85 e3 78 	mr      r5,r28
    1a6c:	38 60 00 39 	li      r3,57
    1a70:	38 c0 00 00 	li      r6,0
    1a74:	48 00 00 01 	bl      1a74 <fn_800614A8+0x1a74>
			1a74: R_PPC_REL24	fn_8020123C
    1a78:	38 60 00 01 	li      r3,1
    1a7c:	48 00 00 b0 	b       1b2c <fn_800614A8+0x1b2c>
    1a80:	7f e3 fb 78 	mr      r3,r31
    1a84:	7f a4 eb 78 	mr      r4,r29
    1a88:	48 00 00 01 	bl      1a88 <fn_800614A8+0x1a88>
			1a88: R_PPC_REL24	fn_800EA3A0
    1a8c:	7f e3 fb 78 	mr      r3,r31
    1a90:	48 00 00 01 	bl      1a90 <fn_800614A8+0x1a90>
			1a90: R_PPC_REL24	fn_800CF598
    1a94:	c0 20 00 00 	lfs     f1,0(0)
			1a94: R_PPC_EMB_SDA21	lbl_8064E62C
    1a98:	7f c3 f3 78 	mr      r3,r30
    1a9c:	c0 40 00 00 	lfs     f2,0(0)
			1a9c: R_PPC_EMB_SDA21	lbl_8064E5DC
    1aa0:	38 80 00 00 	li      r4,0
    1aa4:	38 a0 00 00 	li      r5,0
    1aa8:	38 c0 01 01 	li      r6,257
    1aac:	48 00 00 01 	bl      1aac <fn_800614A8+0x1aac>
			1aac: R_PPC_REL24	fn_80120AD0
    1ab0:	7f e3 fb 78 	mr      r3,r31
    1ab4:	38 80 00 15 	li      r4,21
    1ab8:	48 00 00 01 	bl      1ab8 <fn_800614A8+0x1ab8>
			1ab8: R_PPC_REL24	fn_80201D34
    1abc:	7f e3 fb 78 	mr      r3,r31
    1ac0:	38 80 00 01 	li      r4,1
    1ac4:	48 00 00 01 	bl      1ac4 <fn_800614A8+0x1ac4>
			1ac4: R_PPC_REL24	fn_80201D1C
    1ac8:	38 60 00 01 	li      r3,1
    1acc:	48 00 00 60 	b       1b2c <fn_800614A8+0x1b2c>
    1ad0:	28 19 00 00 	cmplwi  r25,0
    1ad4:	41 82 00 0c 	beq     1ae0 <fn_800614A8+0x1ae0>
    1ad8:	38 00 00 00 	li      r0,0
    1adc:	90 19 00 00 	stw     r0,0(r25)
    1ae0:	38 60 00 01 	li      r3,1
    1ae4:	48 00 00 48 	b       1b2c <fn_800614A8+0x1b2c>
    1ae8:	38 60 00 01 	li      r3,1
    1aec:	48 00 00 40 	b       1b2c <fn_800614A8+0x1b2c>
    1af0:	38 60 00 01 	li      r3,1
    1af4:	48 00 00 38 	b       1b2c <fn_800614A8+0x1b2c>
    1af8:	38 60 00 01 	li      r3,1
    1afc:	48 00 00 30 	b       1b2c <fn_800614A8+0x1b2c>
    1b00:	38 60 00 01 	li      r3,1
    1b04:	48 00 00 28 	b       1b2c <fn_800614A8+0x1b2c>
    1b08:	38 60 00 01 	li      r3,1
    1b0c:	48 00 00 20 	b       1b2c <fn_800614A8+0x1b2c>
    1b10:	38 60 00 01 	li      r3,1
    1b14:	48 00 00 18 	b       1b2c <fn_800614A8+0x1b2c>
    1b18:	38 60 00 01 	li      r3,1
    1b1c:	48 00 00 10 	b       1b2c <fn_800614A8+0x1b2c>
    1b20:	38 60 00 01 	li      r3,1
    1b24:	48 00 00 08 	b       1b2c <fn_800614A8+0x1b2c>
    1b28:	38 60 00 00 	li      r3,0
    1b2c:	b9 e1 00 ac 	lmw     r15,172(r1)
    1b30:	80 01 00 f4 	lwz     r0,244(r1)
    1b34:	7c 08 03 a6 	mtlr    r0
    1b38:	38 21 00 f0 	addi    r1,r1,240
    1b3c:	4e 80 00 20 	blr

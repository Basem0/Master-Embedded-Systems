
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0008 	ldr	r0, [pc, #8]	; 18 <main+0x18>
   c:	ebfffffe 	bl	0 <Uart_Send_string>
  10:	e1a00000 	nop			; (mov r0, r0)
  14:	e8bd8800 	pop	{fp, pc}
  18:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string_buffer>:
   0:	656d6841 	strbvs	r6, [sp, #-2113]!	; 0xfffff7bf
   4:	61422064 	cmpvs	r2, r4, rrx
   8:	006d6573 	rsbeq	r6, sp, r3, ror r5
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000062 	andeq	r0, r0, r2, rrx
   4:	00000004 	andeq	r0, r0, r4
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000029 	andeq	r0, r0, r9, lsr #32
  10:	0000b70c 	andeq	fp, r0, ip, lsl #14
  14:	00008600 	andeq	r8, r0, r0, lsl #12
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001c00 	andeq	r1, r0, r0, lsl #24
  20:	00000000 	andeq	r0, r0, r0
  24:	003c0200 	eorseq	r0, ip, r0, lsl #4
  28:	00350000 	eorseq	r0, r5, r0
  2c:	35030000 	strcc	r0, [r3, #-0]
  30:	63000000 	movwvs	r0, #0
  34:	07040400 	streq	r0, [r4, -r0, lsl #8]
  38:	0000001c 	andeq	r0, r0, ip, lsl r0
  3c:	00080104 	andeq	r0, r8, r4, lsl #2
  40:	05000000 	streq	r0, [r0, #-0]
  44:	0000000e 	andeq	r0, r0, lr
  48:	00250201 	eoreq	r0, r5, r1, lsl #4
  4c:	03050000 	movweq	r0, #20480	; 0x5000
  50:	00000000 	andeq	r0, r0, r0
  54:	0000bd06 	andeq	fp, r0, r6, lsl #26
  58:	00030100 	andeq	r0, r3, r0, lsl #2
  5c:	1c000000 	stcne	0, cr0, [r0], {-0}
  60:	01000000 	mrseq	r0, (UNDEF: 0)
  64:	Address 0x00000064 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10061201 	andne	r1, r6, r1, lsl #4
  10:	02000017 	andeq	r0, r0, #23
  14:	13490101 	movtne	r0, #37121	; 0x9101
  18:	00001301 	andeq	r1, r0, r1, lsl #6
  1c:	49002103 	stmdbmi	r0, {r0, r1, r8, sp}
  20:	000b2f13 	andeq	r2, fp, r3, lsl pc
  24:	00240400 	eoreq	r0, r4, r0, lsl #8
  28:	0b3e0b0b 	bleq	f82c5c <main+0xf82c5c>
  2c:	00000e03 	andeq	r0, r0, r3, lsl #28
  30:	03003405 	movweq	r3, #1029	; 0x405
  34:	3b0b3a0e 	blcc	2ce874 <main+0x2ce874>
  38:	3f13490b 	svccc	0x0013490b
  3c:	00180219 	andseq	r0, r8, r9, lsl r2
  40:	002e0600 	eoreq	r0, lr, r0, lsl #12
  44:	0e03193f 			; <UNDEFINED> instruction: 0x0e03193f
  48:	0b3b0b3a 	bleq	ec2d38 <main+0xec2d38>
  4c:	06120111 			; <UNDEFINED> instruction: 0x06120111
  50:	42961840 	addsmi	r1, r6, #64, 16	; 0x400000
  54:	00000019 	andeq	r0, r0, r9, lsl r0

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	0000001c 	andeq	r0, r0, ip, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000031 	andeq	r0, r0, r1, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	4b4b1500 	blmi	12c5434 <main+0x12c5434>
  30:	01000602 	tsteq	r0, r2, lsl #12
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
   8:	61686320 	cmnvs	r8, r0, lsr #6
   c:	74730072 	ldrbtvc	r0, [r3], #-114	; 0xffffff8e
  10:	676e6972 			; <UNDEFINED> instruction: 0x676e6972
  14:	6675625f 			; <UNDEFINED> instruction: 0x6675625f
  18:	00726566 	rsbseq	r6, r2, r6, ror #10
  1c:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  20:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
  24:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
  28:	554e4700 	strbpl	r4, [lr, #-1792]	; 0xfffff900
  2c:	31314320 	teqcc	r1, r0, lsr #6
  30:	322e3720 	eorcc	r3, lr, #32, 14	; 0x800000
  34:	3220312e 	eorcc	r3, r0, #-2147483637	; 0x8000000b
  38:	30373130 	eorscc	r3, r7, r0, lsr r1
  3c:	20343039 	eorscs	r3, r4, r9, lsr r0
  40:	6c657228 	sfmvs	f7, 2, [r5], #-160	; 0xffffff60
  44:	65736165 	ldrbvs	r6, [r3, #-357]!	; 0xfffffe9b
  48:	415b2029 	cmpmi	fp, r9, lsr #32
  4c:	652f4d52 	strvs	r4, [pc, #-3410]!	; fffff302 <main+0xfffff302>
  50:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  54:	2d646564 	cfstr64cs	mvdx6, [r4, #-400]!	; 0xfffffe70
  58:	72622d37 	rsbvc	r2, r2, #3520	; 0xdc0
  5c:	68636e61 	stmdavs	r3!, {r0, r5, r6, r9, sl, fp, sp, lr}^
  60:	76657220 	strbtvc	r7, [r5], -r0, lsr #4
  64:	6f697369 	svcvs	0x00697369
  68:	3532206e 	ldrcc	r2, [r2, #-110]!	; 0xffffff92
  6c:	34303235 	ldrtcc	r3, [r0], #-565	; 0xfffffdcb
  70:	6d2d205d 	stcvs	0, cr2, [sp, #-372]!	; 0xfffffe8c
  74:	3d757063 	ldclcc	0, cr7, [r5, #-396]!	; 0xfffffe74
  78:	396d7261 	stmdbcc	sp!, {r0, r5, r6, r9, ip, sp, lr}^
  7c:	6a653632 	bvs	194d94c <main+0x194d94c>
  80:	2d20732d 	stccs	3, cr7, [r0, #-180]!	; 0xffffff4c
  84:	3a460067 	bcc	1180228 <main+0x1180228>
  88:	7469475c 	strbtvc	r4, [r9], #-1884	; 0xfffff8a4
  8c:	52627548 	rsbpl	r7, r2, #72, 10	; 0x12000000
  90:	5c6f7065 	stclpl	0, cr7, [pc], #-404	; ffffff04 <main+0xffffff04>
  94:	7473614d 	ldrbtvc	r6, [r3], #-333	; 0xfffffeb3
  98:	452d7265 	strmi	r7, [sp, #-613]!	; 0xfffffd9b
  9c:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  a0:	2d646564 	cfstr64cs	mvdx6, [r4, #-400]!	; 0xfffffe70
  a4:	74737953 	ldrbtvc	r7, [r3], #-2387	; 0xfffff6ad
  a8:	5c736d65 	ldclpl	13, cr6, [r3], #-404	; 0xfffffe6c
  ac:	74696e55 	strbtvc	r6, [r9], #-3669	; 0xfffff1ab
  b0:	614c5c33 	cmpvs	ip, r3, lsr ip
  b4:	61003162 	tstvs	r0, r2, ror #2
  b8:	632e7070 			; <UNDEFINED> instruction: 0x632e7070
  bc:	69616d00 	stmdbvs	r1!, {r8, sl, fp, sp, lr}^
  c0:	Address 0x000000c0 is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	5420554e 	strtpl	r5, [r0], #-1358	; 0xfffffab2
   c:	736c6f6f 	cmnvc	ip, #444	; 0x1bc
  10:	726f6620 	rsbvc	r6, pc, #32, 12	; 0x2000000
  14:	6d724120 	ldfvse	f4, [r2, #-128]!	; 0xffffff80
  18:	626d4520 	rsbvs	r4, sp, #32, 10	; 0x8000000
  1c:	65646465 	strbvs	r6, [r4, #-1125]!	; 0xfffffb9b
  20:	72502064 	subsvc	r2, r0, #100	; 0x64
  24:	7365636f 	cmnvc	r5, #-1140850687	; 0xbc000001
  28:	73726f73 	cmnvc	r2, #460	; 0x1cc
  2c:	322d3720 	eorcc	r3, sp, #32, 14	; 0x800000
  30:	2d373130 	ldfcss	f3, [r7, #-192]!	; 0xffffff40
  34:	6d2d3471 	cfstrsvs	mvf3, [sp, #-452]!	; 0xfffffe3c
  38:	726f6a61 	rsbvc	r6, pc, #397312	; 0x61000
  3c:	2e372029 	cdpcs	0, 3, cr2, cr7, cr9, {1}
  40:	20312e32 	eorscs	r2, r1, r2, lsr lr
  44:	37313032 			; <UNDEFINED> instruction: 0x37313032
  48:	34303930 	ldrtcc	r3, [r0], #-2352	; 0xfffff6d0
  4c:	65722820 	ldrbvs	r2, [r2, #-2080]!	; 0xfffff7e0
  50:	7361656c 	cmnvc	r1, #108, 10	; 0x1b000000
  54:	5b202965 	blpl	80a5f0 <main+0x80a5f0>
  58:	2f4d5241 	svccs	0x004d5241
  5c:	65626d65 	strbvs	r6, [r2, #-3429]!	; 0xfffff29b
  60:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  64:	622d372d 	eorvs	r3, sp, #11796480	; 0xb40000
  68:	636e6172 	cmnvs	lr, #-2147483620	; 0x8000001c
  6c:	65722068 	ldrbvs	r2, [r2, #-104]!	; 0xffffff98
  70:	69736976 	ldmdbvs	r3!, {r1, r2, r4, r5, r6, r8, fp, sp, lr}^
  74:	32206e6f 	eorcc	r6, r0, #1776	; 0x6f0
  78:	30323535 	eorscc	r3, r2, r5, lsr r5
  7c:	Address 0x0000007c is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	0000001c 	andeq	r0, r0, ip, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0xfffffdc7
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0xfffffef7
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.



uart.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <Uart_Send_string>:
   0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
   4:	e28db000 	add	fp, sp, #0
   8:	e24dd00c 	sub	sp, sp, #12
   c:	e50b0008 	str	r0, [fp, #-8]
  10:	ea000006 	b	30 <Uart_Send_string+0x30>
  14:	e51b3008 	ldr	r3, [fp, #-8]
  18:	e5d32000 	ldrb	r2, [r3]
  1c:	e59f302c 	ldr	r3, [pc, #44]	; 50 <Uart_Send_string+0x50>
  20:	e5832000 	str	r2, [r3]
  24:	e51b3008 	ldr	r3, [fp, #-8]
  28:	e2833001 	add	r3, r3, #1
  2c:	e50b3008 	str	r3, [fp, #-8]
  30:	e51b3008 	ldr	r3, [fp, #-8]
  34:	e5d33000 	ldrb	r3, [r3]
  38:	e3530000 	cmp	r3, #0
  3c:	1afffff4 	bne	14 <Uart_Send_string+0x14>
  40:	e1a00000 	nop			; (mov r0, r0)
  44:	e28bd000 	add	sp, fp, #0
  48:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
  4c:	e12fff1e 	bx	lr
  50:	101f1000 	andsne	r1, pc, r0

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000053 	andeq	r0, r0, r3, asr r0
   4:	00000004 	andeq	r0, r0, r4
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000002b 	andeq	r0, r0, fp, lsr #32
  10:	0000b90c 	andeq	fp, r0, ip, lsl #18
  14:	00008800 	andeq	r8, r0, r0, lsl #16
  18:	00000000 	andeq	r0, r0, r0
  1c:	00005400 	andeq	r5, r0, r0, lsl #8
  20:	00000000 	andeq	r0, r0, r0
  24:	001a0200 	andseq	r0, sl, r0, lsl #4
  28:	04010000 	streq	r0, [r1], #-0
  2c:	00000000 	andeq	r0, r0, r0
  30:	00000054 	andeq	r0, r0, r4, asr r0
  34:	00499c01 	subeq	r9, r9, r1, lsl #24
  38:	00030000 	andeq	r0, r3, r0
  3c:	01000000 	mrseq	r0, (UNDEF: 0)
  40:	00004904 	andeq	r4, r0, r4, lsl #18
  44:	74910200 	ldrvc	r0, [r1], #512	; 0x200
  48:	4f040400 	svcmi	0x00040400
  4c:	05000000 	streq	r0, [r0, #-0]
  50:	000c0801 	andeq	r0, ip, r1, lsl #16
  54:	Address 0x00000054 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10061201 	andne	r1, r6, r1, lsl #4
  10:	02000017 	andeq	r0, r0, #23
  14:	193f012e 	ldmdbne	pc!, {r1, r2, r3, r5, r8}	; <UNPREDICTABLE>
  18:	0b3a0e03 	bleq	e8382c <Uart_Send_string+0xe8382c>
  1c:	19270b3b 	stmdbne	r7!, {r0, r1, r3, r4, r5, r8, r9, fp}
  20:	06120111 			; <UNDEFINED> instruction: 0x06120111
  24:	42971840 	addsmi	r1, r7, #64, 16	; 0x400000
  28:	00130119 	andseq	r0, r3, r9, lsl r1
  2c:	00050300 	andeq	r0, r5, r0, lsl #6
  30:	0b3a0e03 	bleq	e83844 <Uart_Send_string+0xe83844>
  34:	13490b3b 	movtne	r0, #39739	; 0x9b3b
  38:	00001802 	andeq	r1, r0, r2, lsl #16
  3c:	0b000f04 	bleq	3c54 <Uart_Send_string+0x3c54>
  40:	0013490b 	andseq	r4, r3, fp, lsl #18
  44:	00240500 	eoreq	r0, r4, r0, lsl #10
  48:	0b3e0b0b 	bleq	f82c7c <Uart_Send_string+0xf82c7c>
  4c:	00000e03 	andeq	r0, r0, r3, lsl #28
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000054 	andeq	r0, r0, r4, asr r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000035 	andeq	r0, r0, r5, lsr r0
   4:	001d0002 	andseq	r0, sp, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	74726175 	ldrbtvc	r6, [r2], #-373	; 0xfffffe8b
  20:	0000632e 	andeq	r6, r0, lr, lsr #6
  24:	00000000 	andeq	r0, r0, r0
  28:	00000205 	andeq	r0, r0, r5, lsl #4
  2c:	83160000 	tsthi	r6, #0
  30:	87638330 			; <UNDEFINED> instruction: 0x87638330
  34:	01000a02 	tsteq	r0, r2, lsl #20
  38:	Address 0x00000038 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	78745f50 	ldmdavc	r4!, {r4, r6, r8, r9, sl, fp, ip, lr}^
   4:	7274735f 	rsbsvc	r7, r4, #2080374785	; 0x7c000001
   8:	00676e69 	rsbeq	r6, r7, r9, ror #28
   c:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  10:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
  14:	61686320 	cmnvs	r8, r0, lsr #6
  18:	61550072 	cmpvs	r5, r2, ror r0
  1c:	535f7472 	cmppl	pc, #1912602624	; 0x72000000
  20:	5f646e65 	svcpl	0x00646e65
  24:	69727473 	ldmdbvs	r2!, {r0, r1, r4, r5, r6, sl, ip, sp, lr}^
  28:	4700676e 	strmi	r6, [r0, -lr, ror #14]
  2c:	4320554e 			; <UNDEFINED> instruction: 0x4320554e
  30:	37203131 			; <UNDEFINED> instruction: 0x37203131
  34:	312e322e 			; <UNDEFINED> instruction: 0x312e322e
  38:	31303220 	teqcc	r0, r0, lsr #4
  3c:	30393037 	eorscc	r3, r9, r7, lsr r0
  40:	72282034 	eorvc	r2, r8, #52	; 0x34
  44:	61656c65 	cmnvs	r5, r5, ror #24
  48:	20296573 	eorcs	r6, r9, r3, ror r5
  4c:	4d52415b 	ldfmie	f4, [r2, #-364]	; 0xfffffe94
  50:	626d652f 	rsbvs	r6, sp, #197132288	; 0xbc00000
  54:	65646465 	strbvs	r6, [r4, #-1125]!	; 0xfffffb9b
  58:	2d372d64 	ldccs	13, cr2, [r7, #-400]!	; 0xfffffe70
  5c:	6e617262 	cdpvs	2, 6, cr7, cr1, cr2, {3}
  60:	72206863 	eorvc	r6, r0, #6488064	; 0x630000
  64:	73697665 	cmnvc	r9, #105906176	; 0x6500000
  68:	206e6f69 	rsbcs	r6, lr, r9, ror #30
  6c:	32353532 	eorscc	r3, r5, #209715200	; 0xc800000
  70:	205d3430 	subscs	r3, sp, r0, lsr r4
  74:	70636d2d 	rsbvc	r6, r3, sp, lsr #26
  78:	72613d75 	rsbvc	r3, r1, #7488	; 0x1d40
  7c:	3632396d 	ldrtcc	r3, [r2], -sp, ror #18
  80:	732d6a65 			; <UNDEFINED> instruction: 0x732d6a65
  84:	00672d20 	rsbeq	r2, r7, r0, lsr #26
  88:	475c3a46 	ldrbmi	r3, [ip, -r6, asr #20]
  8c:	75487469 	strbvc	r7, [r8, #-1129]	; 0xfffffb97
  90:	70655262 	rsbvc	r5, r5, r2, ror #4
  94:	614d5c6f 	cmpvs	sp, pc, ror #24
  98:	72657473 	rsbvc	r7, r5, #1929379840	; 0x73000000
  9c:	626d452d 	rsbvs	r4, sp, #188743680	; 0xb400000
  a0:	65646465 	strbvs	r6, [r4, #-1125]!	; 0xfffffb9b
  a4:	79532d64 	ldmdbvc	r3, {r2, r5, r6, r8, sl, fp, sp}^
  a8:	6d657473 	cfstrdvs	mvd7, [r5, #-460]!	; 0xfffffe34
  ac:	6e555c73 	mrcvs	12, 2, r5, cr5, cr3, {3}
  b0:	5c337469 	cfldrspl	mvf7, [r3], #-420	; 0xfffffe5c
  b4:	3162614c 	cmncc	r2, ip, asr #2
  b8:	72617500 	rsbvc	r7, r1, #0, 10
  bc:	00632e74 	rsbeq	r2, r3, r4, ror lr

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
  54:	5b202965 	blpl	80a5f0 <Uart_Send_string+0x80a5f0>
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
  10:	0000001c 	andeq	r0, r0, ip, lsl r0
	...
  1c:	00000054 	andeq	r0, r0, r4, asr r0
  20:	8b040e42 	blhi	103930 <Uart_Send_string+0x103930>
  24:	0b0d4201 	bleq	350830 <Uart_Send_string+0x350830>
  28:	420d0d60 	andmi	r0, sp, #96, 26	; 0x1800
  2c:	00000ecb 	andeq	r0, r0, fp, asr #29

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


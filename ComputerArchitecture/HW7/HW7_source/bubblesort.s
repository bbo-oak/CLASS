.text
.global bubblesort
.global swap
.type bubblesort, STT_FUNC

bubblesort:
		sub	sp, sp, #24
		str	lr, [sp, #20]
		str	r8, [sp, #16] // 레지스터 추가로 사용
		str	r7, [sp, #12]
		str	r6, [sp, #8]
		str r3, [sp, #4]
		str	r2, [sp, #0]
		
		mov	r6, r0
		mov	r7, r1
		mov	r2, #0
		sub	r1, r1, #1 // n-1 연산

for1tst:
		cmp	r2, r1 // if(i < n-1)
		bge	exit1
		mov	r3, #0 // j=0으로 설정
		sub	r8, r1, r2 // n-1-i 연산
		
for2tst:
		cmp	r3, r8 // if(j < n-1-i)
		bge	exit2
		add	r12, r0, r3, LSL #2
		ldr	r4, [r12, #0]
		ldr	r5, [r12, #4]
		cmp	r4, r5
		ble	exit2
		
		stmdb	sp!,{r0,r1,r2,r3,r12}
		mov	r0, r6
		mov	r1, r3
		bl	swap
		ldmia sp!,{r0,r1,r2,r3,r12}
		
		add	r3, r3, #1
		b	for2tst
		
exit2:
		add	r2, r2, #1
		b	for1tst
		
exit1:
		ldr	r2, [sp, #0]
		ldr	r3, [sp, #4]
		ldr	r6, [sp, #8]
		ldr     r7, [sp, #12]
		str	r8, [sp, #16]
		ldr	lr, [sp, #20]		
		add	sp, sp, #24
		
		mov	pc, lr
		
.end

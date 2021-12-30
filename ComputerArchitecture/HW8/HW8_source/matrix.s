.text
.global matrix         
         
matrix:
	stmfd sp!, {r0-r12,lr}

	mov	r10,#0 // use more registers for address calculation
	mov	r6,#0									
	mov	r7,#0									
	mov	r8,#0									
	mov	r9,#0									
	
Loop:	
	add	r11,r0,r6,LSL #2 // access array A's row addr
	ldr	r11,[r11]	
	add	r11,r11,r7,LSL #2 // access array A's col addr
	ldr	r12,[r11] // get number from array A
	
	add	r11,r1,r7,LSL #2 // access array B's row addr
	ldr	r11,[r11]
	add	r11,r11,r8,LSL #2 // access array B's col addr
	ldr	r11,[r11] // get number from array B
	
	mul	r12,r11,r12						
	add	r9, r9, r12
	
	add	r7,r7,#1
	
	mov	r10,#0
	add	r10,r3,#4
	ldr	r10,[r10] //get "u" from Array_size
	cmp	r7,r10									 
	bne	Loop
	mov	r7,#0								

												
	add	r11,r2,r6,LSL #2
	ldr	r11,[r11]		
	add	r11,r11,r8,LSL #2							

	str	r9, [r11]							
													; 
	mov	r9,#0
	
	add	r8,r8,#1
	
	mov	r10,#0
	add	r10,r3,#8
	ldr	r10,[r10] //get "v" from Array_size
	cmp	r8, r10								
	bne	Loop

	mov	r8,#0								
	
	add	r6,r6,#1
	
	mov	r10,#0
	add	r10,r3,#0
	ldr	r10,[r10] //get "s" from Array_size
	cmp	r6,r10									
	bne	Loop	

	ldmfd sp!, {r0-r12,pc}
	
.end
		
		

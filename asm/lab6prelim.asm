.data
	prompt: .asciiz "Square Matrix Size (N): "
	prompt2: .asciiz "Enter Element Values Row By Row: "
	prompt3: .asciiz "Enter index (i) of the element to be displayed: "
	prompt4: .asciiz "Enter index (j) of the element to be displayed: "
	prompt5: .asciiz "The element is: "
	prompt6: .asciiz "\nSummation of matrix elements column-major (column by column) summation: "
	prompt7: .asciiz "\nSummation of matrix elements row-major (row by row) summation: "
.text
	#get matrix size
	li $v0,4
	la $a0,prompt
	syscall	
	li $v0, 5
	syscall
	move $s0, $v0   #s0: matrix size
	addi $s1, $0, 4
	mult $s0, $s0
	mflo $s2	#s2=s0*s0
	mult $s2, $s1
	mflo $s2        #s2: matrix size*4
	
	
	add	$a0, $s2, $0 	
	li	$v0, 9
	syscall	#all bytes are allocated
	la	$s3, ($v0) #s3: beginning address of the array
	
	addi 	$s4, $0, 0 #s4: counter for loop
	
	#initialize array contents row by row
		loop:
			beq $s4, $s2, exit
			
			add $s5, $s3, $s4 #s5: current address
			#li $v0, 4
			#la $a0, prompt2
			#syscall
			#li $v0, 5
			#syscall
			#move $s6, $v0 #s6: element value
			addi $s6, $0, 1
			sw $s6, 0($s5) #store element value
			addi $s4, $s4, 4
			j loop
		exit:
			li $v0, 4
			la $a0, prompt3
			syscall
			li $v0, 5
			syscall
			move $s7, $v0 
			
			li $v0, 4
			la $a0, prompt4
			syscall
			li $v0, 5
			syscall
			
			add $a0,$s7,$0 #i
			add $a1,$v0,$0 #j
			add $a2,$s3,$0 #address of the array
			add $a3,$s0,$0 #N
			jal getElement
			move $s1,$v0 #the value of the element
			
			li $v0, 4
			la $a0, prompt5
			syscall
			li $v0, 1
			move $a0, $s1
			syscall
			
			li $v0, 4
			la $a0, prompt6
			syscall
			add $a0,$s3,$0 #address of the array
			add $a1,$s2,$0 #matrix size
			add $a3,$s0,$0 #N
			jal sumColumnByColumn
			move $s1,$v0 #the sum
			
			li $v0, 1
			move $a0, $s1
			syscall
			
			li $v0, 4
			la $a0, prompt7
			syscall
			add $a0,$s3,$0 #address of the array
			add $a1,$s2,$0 #matrix size
			jal sumRowByRow
			move $s1,$v0 #the sum
			
			li $v0, 1
			move $a0, $s1
			syscall
												
			li	$v0, 10
			syscall	
getElement:
	#stack operations**************
		addi $sp,$sp,-40
		sw $ra,36($sp)
		sw $a0,32($sp)
		sw $a1,28($sp)
		sw $a2,24($sp)
		sw $a3,20($sp)
		sw $s0,16($sp)
		sw $s1,12($sp)
		sw $s2,8($sp)
		sw $s3,4($sp)
		sw $s4,0($sp)
		#******************************
	addi $s0, $a0, -1 #i-1
	addi $s1, $a1, -1 #j-1
	mult $s1, $a3
	mflo $s1 #s1:(j-1)*N
	add $s2, $s1, $s0
	addi $s3, $0, 4
	mult $s3, $s2
	mflo $s4 #s4: displacement
	add $s1, $s4, $a2 #s1:address of the interest element
	lw $v0, 0($s1)
	#stack operations**************
		lw $s4,0($sp)
		lw $s3,4($sp)
		lw $s2,8($sp)
		lw $s1,12($sp)
		lw $s0,16($sp)
		lw $a3,20($sp)
		lw $a2,24($sp)
		lw $a1,28($sp)
		lw $a0,32($sp)
		lw $ra,36($sp)
		addi $sp,$sp,40
		#******************************
	jr $ra
sumRowByRow:
	#stack operations**************
		addi $sp,$sp,-40
		sw $ra,36($sp)
		sw $a0,32($sp)
		sw $a1,28($sp)
		sw $a2,24($sp)
		sw $a3,20($sp)
		sw $s0,16($sp)
		sw $s1,12($sp)
		sw $s2,8($sp)
		sw $s3,4($sp)
		sw $s4,0($sp)
		#******************************
	add $s0, $a0, $0 #address of the array
	add $s1, $a1, $0 #matrix size
	add $s2, $0, $0 #counter
	add $s5, $0, $0 #sum
	loop2:
			beq $s2, $s1, exit2
			add $s3, $s0, $s2 #s5: current address
			
			lw $s4, 0($s3) #load element value
			add $s5, $s5, $s4
			addi $s2, $s2, 4
			j loop2
	exit2:
		move $v0, $s5
	#stack operations**************
		lw $s4,0($sp)
		lw $s3,4($sp)
		lw $s2,8($sp)
		lw $s1,12($sp)
		lw $s0,16($sp)
		lw $a3,20($sp)
		lw $a2,24($sp)
		lw $a1,28($sp)
		lw $a0,32($sp)
		lw $ra,36($sp)
		addi $sp,$sp,40
		#******************************
	jr $ra
sumColumnByColumn:
	#stack operations**************
		addi $sp,$sp,-40
		sw $ra,36($sp)
		sw $a0,32($sp)
		sw $a1,28($sp)
		sw $a2,24($sp)
		sw $a3,20($sp)
		sw $s0,16($sp)
		sw $s1,12($sp)
		sw $s2,8($sp)
		sw $s3,4($sp)
		sw $s4,0($sp)
		#******************************
	add $s0, $a0, $0 #address of the array
	add $s1, $a1, $0 #matrix size
	add $s4, $a3, $0 #N

	addi $s3, $0, 1 #j-counter
	add $s5, $0, $0 #sum
	
	loop3: 	bgt $s3,$s4,exit3
		addi $s2, $0, 1 #i-counter
		loop4:  bgt $s2,$s4,exit4
		
			add $a0,$s3,$0 #i
			add $a1,$s2,$0 #j
			add $a2,$s0,$0 #address of the array
			add $a3,$s4,$0 #N
			jal getElement
			add $s5,$s5,$v0 #sum
			
			addi $s2,$s2,1
			j loop4
		exit4:
		addi $s3,$s3,1
		j loop3
	exit3:
		move $v0, $s5
	
	#stack operations**************
		lw $s4,0($sp)
		lw $s3,4($sp)
		lw $s2,8($sp)
		lw $s1,12($sp)
		lw $s0,16($sp)
		lw $a3,20($sp)
		lw $a2,24($sp)
		lw $a1,28($sp)
		lw $a0,32($sp)
		lw $ra,36($sp)
		addi $sp,$sp,40
		#******************************
	jr $ra

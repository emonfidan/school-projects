.data 
	string1: .space 2
	string: .space 4
	prompt: .asciiz "\nDo you want to continue? Enter Y or N:"
	prompt2: .asciiz "Enter HEX number: "
	prompt3: .asciiz "\nChoose Operation:\n1) convertHexToDec\n2) invertBytes "
	prompt4: .asciiz "Enter input to be inverted: "
	prompt5: .asciiz "Input: "
	prompt6: .asciiz "\nOutput: "
.text
main:	
	loop:
		#choose operation
		li $v0,4
		la $a0,prompt3
		syscall
		li $v0, 5
		syscall
		move $s0, $v0
		beq $s0,1,firstOp
		beq $s0,2,secondOp
		j loop
		firstOp:
			#get string input
			li $v0,4
			la $a0,prompt2
			syscall
			li $v0,8
			la $a0, string
			li $a1, 10
			syscall
			#call convertHexToDec function
			la $a0,string
			jal convertHexToDec
			#print result
			move $s1,$v0
			li $v0, 1
			addi $a0, $s1, 0
			syscall
			j loop2
		secondOp:
			#get decimal input
			li $v0,4
			la $a0,prompt4
			syscall
			li $v0, 5
			syscall
			move $s2, $v0
			#call invertBytes function and print input
			li $v0,4
			la $a0,prompt5
			syscall
			li $v0, 34
			move $a0, $s2
			syscall
			add $a0,$s2,$0
			jal invertBytes
			move $s1,$v0
			#print result
			li $v0,4
			la $a0,prompt6
			syscall
			li $v0, 34
			move $a0, $s1
			syscall
			j loop2
	
		#do you want to continue
		loop2:
		li $v0,4
		la $a0,prompt
		syscall
		li $v0,8
		la $a0, string1
		li $a1, 2
		syscall
		la $s4,string1
		lbu $s5,0($s4)
		beq $s5,0x59,loop
		beq $s5,0x4e,exit
		j loop2
	
convertHexToDec:
	#stack operations**************
	addi $sp,$sp,-12
	sw $s0,8($sp)
	sw $s1,4($sp)
	sw $s2,0($sp)
	#******************************
	addi $s1,$0,0 #s1:result num
	add $s2,$0,$a0 #current address ptr
	loop1:
		lbu $s0,0($s2) #s0:ascii value of current character of string
		beq $s0,10,firstExit
		#control if current character is in range 0-9 or a-f
		sub $s0,$s0,48
		sgt $s3,$s0,15
		bne $s3,$0,inrangeaf
		j notinrangeaf
		inrangeaf:
			sub $s0,$s0,39
		notinrangeaf:
			#add new num to the result register s1
			sll $s1,$s1,4
			add $s1,$s1,$s0
		addi $s2,$s2,1 #next byte address of string 
		j loop1
		
	firstExit:
		add $v0,$s1,$0	#load result num
		#stack operations**************
		lw $s2,0($sp)
		lw $s1,4($sp)
		lw $s0,8($sp)
		addi $sp,$sp,12
		#******************************
		jr $ra


invertBytes:
	#stack operations**************
	addi $sp,$sp,-16
	sw $s0,12($sp)
	sw $s1,8($sp)
	sw $s2,4($sp)
	sw $s3,0($sp)
	#******************************
	addi $s2, $a0, 0 #s3:input hex
	addi $s0,$0,0 #s1:result hex
	addi $s1,$0,0 #s2:current byte counter
	
	loop3: 
	beq $s1,4,secondExit
	andi $s3, $s2, 0x000000ff #take least significant byte of input
	srl $s2,$s2,8
	sll $s0,$s0,8
	add $s0,$s0,$s3
	addi $s1,$s1,1
	j loop3
	secondExit:
	add $v0,$s0,$0	#load result num
	#stack operations**************
	lw $s3,0($sp)
	lw $s2,4($sp)
	lw $s1,8($sp)
	lw $s0,12($sp)
	addi $sp,$sp,16
	#******************************
	jr $ra

exit:

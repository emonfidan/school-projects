.data 
	array: .space 40
	prompt: .asciiz "\nArray Size:"
	prompt2: .asciiz "Enter array element: "
	prompt3: .asciiz "\nMax array element: "
	prompt4: .asciiz "\nMin array element: "
.text
	main:
		#s0:array size 
		#s1:4 (4 bytes for each integer)
		#$s2:array size in bytes
		#s3:array address pointer
		
		#take array size
		li $v0,4
		la $a0,prompt
		syscall
		li $v0, 5
		syscall
		move $s0, $v0
		#mult array size by 4
		addi $s1,$0,4
		mult $s0,$s1
		mflo $s2
		#allocate memory dynamically
		li $v0,9
		add $a0,$0,$s2
		syscall
		add $s3,$0,$v0
		#call monitor
		add $a0,$0,$s3 #a0: adress
		add $a1,$0,$s2 #a1: size
		jal monitor
		j mainExit
		 
	monitor:
		#stack operations**************
		addi $sp,$sp,-36
		sw $ra,32($sp)
		sw $a0,28($sp)
		sw $a1,24($sp)
		sw $s0,20($sp)
		sw $s1,16($sp)
		sw $s2,12($sp)
		sw $s3,8($sp)
		sw $s4,4($sp)
		sw $s5,0($sp)
		#******************************
		#s0:address s1:size s2:counter=0 s3:current address
		add $s0,$0,$a0
		add $s1,$0,$a1
		addi $s2,$0,0
		#initialize array contents
		loop:
			beq $s1, $s2, exit
			add $s3,$s0,$s2
			li $v0, 4
			la $a0, prompt2
			syscall
			li $v0, 5
			syscall
			sw $v0, 0($s3)
			addi $s2, $s2, 4
			j loop
		exit:
			#call bubbleSort
			add $a0,$0,$s0 #a0: adress
			add $a1,$0,$s1 #a1: size
			jal bubbleSort
			jal minMax
			# print results
			add $s4,$v0,$0#max
			add $s5,$v1,$0#min
			li $v0, 4
			la $a0, prompt3
			syscall
			li $v0, 1
			addi $a0,$s4 ,0
			syscall
			li $v0, 4
			la $a0, prompt4
			syscall
			li $v0, 1
			addi $a0,$s5,0
			syscall
			
		#stack operations**************
		lw $s5,0($sp)
		lw $s4,4($sp)
		lw $s3,8($sp)
		lw $s2,12($sp)
		lw $s1,16($sp)
		lw $s0,20($sp)
		lw $a1,24($sp)
		lw $a0,28($sp)
		lw $ra,32($sp)
		addi $sp,$sp,36
		#******************************
		jr $ra
	bubbleSort:
		#stack operations**************
		addi $sp,$sp,-36
		sw $ra,32($sp)
		sw $s0,28($sp)
		sw $s1,24($sp)
		sw $s2,20($sp)
		sw $s3,16($sp)
		sw $s4,12($sp)
		sw $s5,8($sp)
		sw $s6,4($sp)
		sw $s7,0($sp)
		#******************************
		#s0:address s1:size-1 s2:counter=0 s3:current address s4:temp reg s5:counter2 for inner loop s6:next element s7: current element
		add $s0,$0,$a0
		addi $s1,$a1,-4 #s1: size -1
		addi $s2,$0,0 #counter
		add $s3,$0,$s0
		loop2:
			beq $s2,$s1,exit2
			addi $s5,$0,0 #counter2
			loop3:
				beq $s5,$s1,exit3
				add $s3,$s0,$s5
				lw $s7, 0($s3) #s7:element at current address
				lw $s6, 4($s3) #s6:next element at current address
				bge $s6,$s7,else
				#swap s6 and s7
				add $s4, $s6,$0
				add $s6, $s7,$0
				add $s7, $s4,$0
				sw $s7, 0($s3)
				sw $s6, 4($s3)
				else:
				addi $s5,$s5,4
				j loop3
			exit3:
			addi $s2,$s2,4
			j loop2
		exit2:
		#stack operations**************
		lw $s7,0($sp)
		lw $s6,4($sp)
		lw $s5,8($sp)
		lw $s4,12($sp)
		lw $s3,16($sp)
		lw $s2,20($sp)
		lw $s1,24($sp)
		lw $s0,28($sp)
		lw $ra,32($sp)
		addi $sp,$sp,36
		#******************************
		jr $ra
	minMax:
		#stack operations**************
		addi $sp,$sp,-16
		sw $ra,12($sp)
		sw $s0,8($sp)
		sw $s1,4($sp)
		sw $s2,0($sp)
		#******************************
		#s0:address s1:size 
		add $s0,$0,$a0
		addi $s1,$a1,-4 #s1: size-1
		lw $v1, 0($s0)
		add $s0,$s1,$s0
		lw $v0, 0($s0)
		#stack operations**************
		lw $s2,0($sp)
		lw $s1,4($sp)
		lw $s0,8($sp)
		lw $ra,12($sp)
		addi $sp,$sp,16
		#******************************
		jr $ra
mainExit:
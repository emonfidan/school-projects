.data
	array: .space 80
	prompt: .asciiz "The number of integers to be stored in the array: "
	prompt2: .asciiz "Enter array element: "
	prompt3: .asciiz "Enter N: "
	prompt4: .asciiz "\nChoose the operation: \n1.Find the number of array members equal to N.\n2.Find the number of array members less than N.\n3.Find the number of array members greater than N.\n4.Find the number of elements evenly divisible by N.\n5.Exit"

.text
	#make t0 zero
	addi $t0, $zero, 0
	#take array size from user and save it as *4
	li $v0, 4
	la $a0, prompt
	syscall
	li $v0, 5
	syscall
	move $s0, $v0
	sll $s0, $s0, 2
	#take array elements one by one
	loop:
		li $v0, 4
		la $a0, prompt2
		syscall
		li $v0, 5
		syscall
		move $t1, $v0
		sw $t1, array($t0)
		addi $t0, $t0, 4
		beq $t0, $s0, exit
		j loop
	exit: 
		#take number N
		li $v0, 4
		la $a0, prompt3
		syscall
		li $v0, 5
		syscall
		move $s1, $v0
		
		loop2:
			#take operation info
			li $v0, 4
			la $a0, prompt4
			syscall
			li $v0, 5
			syscall
			move $s2, $v0
			#make necessary variables 0
			addi $t0, $zero, 0
			addi $s3, $zero, 0
			#branch according to chosen operation
			beq $s2, 5, exit2
			beq $s2, 1, op1
			beq $s2, 2, op2
			beq $s2, 3, op3
			beq $s2, 4, op4
			op1:
				#Find the number of array members equal to N.
				loop3:
					lw $t1, array($t0)
					bne $t1, $s1, dontadd
					addi $s3, $s3, 1
					dontadd:
					addi $t0, $t0, 4
					beq $t0, $s0, exit3
					j loop3
				#print the result
				exit3:
					li $v0, 1
					addi $a0, $s3, 0
					syscall
					j loop2
			op2:
				#Find the number of array members less than N.
				loop4:
					lw $t1, array($t0)
					slt $t3, $t1, $s1
					beq $t3, $zero, dontadd2
					addi $s3, $s3, 1
					dontadd2:
					addi $t0, $t0, 4
					beq $t0, $s0, exit4
					j loop4
				#print the result
				exit4:
					li $v0, 1
					addi $a0, $s3, 0
					syscall
					j loop2	
				j loop2
			op3:
				#Find the number of array members less than N.
				loop5:
					lw $t1, array($t0)
					beq $t1, $s1, dontadd3
					slt $t3, $t1, $s1
					bne $t3, $zero, dontadd3
					addi $s3, $s3, 1
					dontadd3:
					addi $t0, $t0, 4
					beq $t0, $s0, exit5
					j loop5
				#print the result
				exit5:
					li $v0, 1
					addi $a0, $s3, 0
					syscall
					j loop2	
				j loop2
			op4:
				#Find the number of elements evenly divisible by N.
				loop6:
					lw $t1, array($t0)
					div $t1, $s1
					mfhi $t3
					bne $t3, $zero, dontadd4
					addi $s3, $s3, 1
					dontadd4:
					addi $t0, $t0, 4
					beq $t0, $s0, exit6
					j loop6
				#print the result
				exit6:
					li $v0, 1
					addi $a0, $s3, 0
					syscall
					j loop2	
				j loop2
		exit2:
		
	li $v0, 10
	syscall
	
	

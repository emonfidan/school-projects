# Emine Fidan
# 22102860
# instructionCount and recursiveDivision functions
# are implemented
# cs224-4
#
.data 
	word: 1
	line: .asciiz "\n"
	string: .asciiz "\nTotal number of add, ori, lw in main: "
	string1: .space 2
	string2: .asciiz "\nTotal number of add, ori, lw in instructionCount: "
	prompt: .asciiz "\nDo you want to continue? Enter Y or N:"
	prompt4: .asciiz "\nEnter the number dividend: "
	prompt5: .asciiz "Enter the number divisor: "
	prompt6: .asciiz "\nQuotient : "
.text
main:
	
	la $a0,main
	la $a1,done
	jal instructionCount
	#print v0
	add $s0,$v0,$0
	li $v0,4
	la $a0,string
	syscall
	li $v0,1
	addi $a0,$s0,0
	syscall
	
	la $a0,instructionCount
	la $a1,endOfInstructionCount
	jal instructionCount
	#print v0
	add $s0,$v0,$0
	li $v0,4
	la $a0,string2
	syscall
	addi $a0,$s0,0
	li $v0,1
	addi $a0,$s0,0
	syscall 
	
	#recursivedivision part of the main
	loop3:
			#get decimal inputs
			li $v0,4
			la $a0,prompt4
			syscall
			li $v0, 5
			syscall
			move $s2, $v0
			li $v0,4
			la $a0,prompt5
			syscall
			li $v0, 5
			syscall
			move $s3, $v0
			#call recursiveDivision function and print input
			
			add $a0,$s2,$0
			add $a1,$s3,$0
			add $a2,$s2,$0 #remainder
			add $s7,$0,$0 #s7:quotient
			jal recursiveDivision
			move $s1,$v0
			#print result
			li $v0,4
			la $a0,prompt6
			syscall
			li $v0,1
			add $a0,$s1,$0
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
		beq $s5,0x59,loop3
		beq $s5,0x4e,done
		j loop2
	
done:
	li	$v0, 10
	syscall	


instructionCount:
	#stack operations**************
		addi $sp,$sp,-32
		sw $ra,28($sp)
		sw $a0,24($sp)
		sw $a1,20($sp)
		sw $s0,16($sp)
		sw $s1,12($sp)
		sw $s2,8($sp)
		sw $s3,4($sp)
		sw $s4,0($sp)
		#******************************
	addi $s0,$a0,0 #s0=start address
	addi $s1,$0,0 #s1=counter

	loop:
		beq $s0,$a1,exit
		lw $s2, 0($s0)
		
		srl $s3,$s2,26 #take only first 6 bits to check opcode
		
		#check opcode
		beq $s3,0x23,iflw
		beq $s3,0xd,ifori
		bne $s3,0,else
		#add control
			andi $s4,$s2,0x0000003f
			bne $s4,0x20,else
			addi $s1,$s1,1
			j else
		ifori:	
		#ori control
			addi $s1,$s1,1
			j else
		iflw:
		#lw control
			addi $s1,$s1,1
			j else
		
		else:
		addi $s0,$s0,4 #current instruction adress+=4 bytes
		j loop
	exit:
	add $v0,$s1,$0
	#stack operations**************
		lw $s4,0($sp)
		lw $s3,4($sp)
		lw $s2,8($sp)
		lw $s1,12($sp)
		lw $s0,16($sp)
		lw $a1,20($sp)
		lw $a0,24($sp)
		lw $ra,28($sp)
		addi $sp,$sp,32
		#******************************
	jr $ra
endOfInstructionCount:
recursiveDivision:
	#stack operations**************
		addi $sp,$sp,-36
		sw $ra,32($sp)
		sw $a0,28($sp)
		sw $a1,24($sp)
		sw $a2,20($sp)
		sw $s0,16($sp)
		sw $s1,12($sp)
		sw $s2,8($sp)
		sw $s3,4($sp)
		sw $s4,0($sp)
		#******************************
	addi $s0,$a0,0 #dividend
	addi $s1,$a1,0 #divisor	
	addi $s2,$a2,0 #remainder
	bgt $s1,$s2, endOfDivision
	sub $a2,$s2,$s1
	addi $s7,$s7,1
	jal recursiveDivision
	endOfDivision:
	add $v0,$s7,$0
	#stack operations**************
		lw $s4,0($sp)
		lw $s3,4($sp)
		lw $s2,8($sp)
		lw $s1,12($sp)
		lw $s0,16($sp)
		lw $a2,20($sp)
		lw $a1,24($sp)
		lw $a0,28($sp)
		lw $ra,32($sp)
		addi $sp,$sp,36
		#******************************
	jr $ra

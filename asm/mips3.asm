.data
	prompt: .asciiz "Enter integer: "
	prompt2: .asciiz "Result is: "
	prompt3: .asciiz "Division by zero detected. "
.text
	#(((a*a)-b)/b)%a
	
	#take the integer a
	li $v0, 4
	la $a0, prompt
	syscall
	li $v0, 5
	syscall
	move $s0, $v0
	#take the integer b
	li $v0, 4
	la $a0, prompt
	syscall
	li $v0, 5
	syscall
	move $s1, $v0
	beq $s1,$0,error
	
	#start operations (((a*a)-b)/b)%a
	mult $s0,$s0 #t0=a*a
	mflo $t0
	
	sub $t0,$t0,$s1 #t0=(a*a)-b
	div $t0,$t0,$s1 #t0=t0/b
	mflo $t0
	div $t0,$s0 #t0/q
	mfhi $s3
	
	#print the result
	li $v0, 4
	la $a0, prompt2
	syscall
	li $v0, 1
	addi $a0, $s3, 0
	syscall
	j noerror
	error:
	li $v0, 4
	la $a0, prompt3
	syscall
	noerror:
.data
	my_int: .word 23
.text
	li $v0, 1
	lw $a0, my_int
	syscall


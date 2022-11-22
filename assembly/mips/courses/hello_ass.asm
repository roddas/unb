.data
	my_message:	.asciiz "Ola Mundo\n"
	
.text
	li $v0, 4
	la $a0, my_message
	syscall


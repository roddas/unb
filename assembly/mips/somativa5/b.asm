.data
	text_add: .string "ADD: "
	new_line: .string "\n"
	close_parenthesis: .string "): "
	text_sub: .string "SUB: "
	text_and: .string "AND: "
	text_or: .string "OR: "
	text_xor: .string "XOR: "
	text_mask: .string "MASK: "
	text_sll: .string "SLL("
	text_srl: .string "SRL("
.text
	.globl main
	main:
	# Recebe as entradas
	li a7, 5
	ecall
	mv s2, a0 
	
	li a7, 5
	ecall
	mv s3, a0
	
	li a7, 5
	ecall
	mv s4, a0  

	# A + B
	add t0, s2, s3
	
	# Apresentar na tela o texto ADD : [resultado]
	li a7, 4
	la a0, text_add
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 4
	la a0, new_line
	ecall
	# -------------------------------------
	 
	# A - B
	sub t0, s2, s3
	
	# Apresentar na tela o texto SUB : [resultado]
	li a7, 4
	la a0, text_sub
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 4
	la a0, new_line
	ecall
	# -------------------------------------
	
	# A and B
	and t0, s2, s3
	
	# Apresentar na tela o texto ADD : [resultado]
	li a7, 4
	la a0, text_and
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 4
	la a0, new_line
	ecall
	# -------------------------------------
	
	# A or B
	or t0, s2, s3
	
	# Apresentar na tela o texto OR : [resultado]
	li a7, 4
	la a0, text_or
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 4
	la a0, new_line
	ecall
	# -------------------------------------
	
	# A xor B
	xor t0, s2, s3
	
	# Apresentar na tela o texto XOR : [resultado]
	li a7, 4
	la a0, text_xor
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 4
	la a0, new_line
	ecall
	# -------------------------------------
	
	# C mask 31
	andi t1, s4, 31 # c & 31
	
	# Apresentar na tela o texto MASK : [resultado]
	li a7, 4
	la a0, text_mask
	ecall
	
	li a7, 1
	mv a0, t1
	ecall
	
	li a7, 4
	la a0, new_line
	ecall
	# -------------------------------------
	
	# SLL
	sll t0, s2, t1 # c & 31
	
	# Apresentar na tela o texto SLL : [resultado]
	li a7, 4
	la a0, text_sll
	ecall
	
	li a7, 1
	mv a0, t1
	ecall
	
	li a7, 4
	la a0, close_parenthesis
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 4
	la a0, new_line
	ecall
	# -------------------------------------
	
	# SRL
	srl t0, s3, t1 # c & 31
	
	# Apresentar na tela o texto SRL : [resultado]
	li a7, 4
	la a0, text_srl
	ecall
	
	li a7, 1
	mv a0, t1
	ecall
	
	li a7, 4
	la a0, close_parenthesis
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 4
	la a0, new_line
	ecall
	# -------------------------------------
	
	# Sair do programa
	li a7,10
	ecall
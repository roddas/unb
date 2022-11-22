.text

.data

swap:
	multi $v0, $a1, 4
	add $v0, $a0, $v0
	lw $t7, 0($v0)
	lw $s0, 4($v0)
	sw $s0, 0($v0)
	sw $t7, 4($v0)
	jr $ra

.data
	big_pi: .double 3.1415123456789
	zero_double: .double 0.0
	
.text
	ldc1 $f2, big_pi
	ldc1 $f0, zero_double
	
	li $v0, 3
	add.d $f12,$f2,$f0
	
	syscall


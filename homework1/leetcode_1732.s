.data
gain: .word -1,5,4
gainsize: .word 3
gain2: .word -5,1,5,0,-7
gainsize2: .word 5
gain3: .word -5,1,3
gainsize3: .word 3

.text
main:
		la s0, gain 	#load gain address
		lw s1, gainsize
		jal lat
		la s0, gain2 	#load gain2 address
		lw s1, gainsize2
		jal lat
		la s0, gain3 	#load gain3 address
		lw s1, gainsize3
        jal lat
		li a7 10
		ecall
lat:
		mv t1, x0		#int i = 0
		mv a2, x0		#arti = 0
		mv a3, a2		#max=arti
loop:
        lw a1, 0(s0) #load gain[i]
		addi s0, s0, 4
		add a2, a2 a1 	#arti=arti+gain[i]
		blt a2, a3 conti  #if arti[i]<max, don't change the max value
		mv  a3, a2
conti:
		addi t1, t1 1	# i++
		blt t1, s1, loop	# i<gainsize jump to loop conti
		mv a0 a3
		li a7 1 
		ecall
		jr ra
		
		
		

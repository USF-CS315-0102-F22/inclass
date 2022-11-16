main:
    li a0, 1    
    li a1, 2    
    jal first_s    
    unimp
first_s:
    add a0, a0, a1    
    jalr ra

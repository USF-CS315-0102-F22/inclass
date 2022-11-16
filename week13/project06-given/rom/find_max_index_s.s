.global find_max_index_s

/* find_max_index_s finds the index of the largest value
    a0 = array
    a1 = array length
*/

find_max_index_s:
    mv t3, zero                 # t3 is the loop index
    mv t0, zero                 # t0 is max index
    lw t1, (a0)                 # max val = first elem
loop:
    beq t3, a1, done            # reached the end of array
    lw t2, (a0)                 # t2 = *arr
    blt t2, t1, next            # if cur val < max val, go again
    mv t0, t3                   # max index = loop index
    mv t1, t2                   # max val = cur val

next:
    add t3, t3, 1               # increment loop index
    add a0, a0, 4               # walk arr to next 4 byte int
    j loop

done:
    mv a0, t0                   # set up return value
    ret

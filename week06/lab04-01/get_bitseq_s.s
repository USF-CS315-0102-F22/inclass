.global get_bitseq_s

/* get_bitseq_s returns a specified range of bits within a number as unigned
    a0 is the number
    a1 is the start index
    a2 is the end index
*/

get_bitseq_s:
    sub t0, a2, a1              # end - start
    addi t0, t0, 1              # len = end - start + 1

    li t2, 64                   # special case but is the mask necessary? 
    bne t0, t2, build_mask      # can't we just return the number?
    mv t1, a0
    li t2, 0xFFFFFFFFFFFFFFFF
    j apply_mask

build_mask:    
    srl t1, a0, a1              # shift desired sequence right to bit 0
    li t2, 1                    # calculate the mask in t2
    sll t2, t2, t0
    addi t2, t2, -1

apply_mask:
    and a0, t1, t2              # set up shifted num & mask in a0
    ret

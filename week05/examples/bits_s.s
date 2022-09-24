.global get_bit_s
# Given a 32-bit value, get the bit value at position i

# a0 - uint32_t value
# a1 - int i

get_bit_s:
    srl a0, a0, a1               # Shift a0 to the right by a1 (i) bits
    andi a0, a0, 0b1             # Mask a0 with 0b1 to clear any upper bits
    ret

.global set_bit_s
# Given a 32-bit value, set the bit at position i to bvalue
# Return new 32-bit value

# a0 - uint32_t value
# a1 - int i
# a2 - uint32_t bvalue

# t0 - uint32_t mask

set_bit_s:
    beq a2, zero, set_bit_else   # Branch to unset code
    li t0, 0b1                   # t0 = 0b1
    sll t0, t0, a1               # t0 = t0 << a1 (i)
    or a0, a0, t0                # a0 = a0 | t0 (mask)
    j set_bit_exit               # Exit function
set_bit_else:
    li t0, 0b1                   # t0 = 0b1
    sll t0, t0, a1               # t0 = t0 << a1 (i)
    xori t0, t0, -1              # t0 = ~t0
    and a0, a0, t0               # a0 = a0 & t0 (mask)
set_bit_exit:
    ret

.global get_bitseq1_s
# Get the bit sequence in a 32 bit value starting at
# index start through index end. Return seq.

# a0 - uint32_t value
# a1 - int start
# a2 - int end

# t0 - uint32_t mask
# t1 - int len

get_bitseq1_s:
    sub t1, a2, a1              # t1 = a2 (end) = a1 (start)
    addi t1, t1, 1              # t1 = t1 + 1
    li t2, 32                   # t2 = 32
    bge t1, t2, get_bitseq_exit
    li t2, 1                    # t2 = 1
    sll t0, t2, t1              # t0 = t2 << t1 (len)
    addi t0, t0, -1             # t0 = t0 - 1 (create mask of len 1s)
    srl a0, a0, a1              # a0 = a0 >> a1 (start)
    and a0, a0, t0              # a0 = a0 & t0 (mask)

get_bitseq_exit:
    ret

.global get_bitseq_s
# Get the bit sequence in a 32 bit value starting at
# index start through index end. Return seq.

# a0 - uint32_t value
# a1 - int start
# a2 - int end

get_bitseq_s:
    li t0, 31                   # t0 = 31
    sub t0, t0, a2              # t0 = t0 (31) - a2 (end)
    sllw a0, a0, t0             # a0 = a0 << (31 - end)
    add t0, t0, a1              # t0 = t0 + a1 (start) 
    srlw a0, a0, t0             # a0 = a0 >> t0 ((31 - end) + start)   
    ret

.global merge_sort_s
.global merge_s

/* merge_sort_s recursively sorts arr
    a0 is arr
    a1 is aux
    a2 is start index
    a3 is end index
*/

.align 4
merge_sort_s:
    addi sp, sp, -32            # prologue
    sd ra, (sp)

    ble a3, a2, done            # end <= start?
    add t0, a2, a3              # start + end
    srli t0, t0, 1              # mid = (start + end) / 2
    sd t0, 8(sp)                # preserve mid
    sd a2, 16(sp)               # preserve start
    sd a3, 24(sp)               # preserve end

    mv a3, t0                   # set up mid param
    jal merge_sort_s
    ld a2, 8(sp)                # restore mid
    addi a2, a2, 1              # set up mid + 1 param
    ld a3, 24(sp)               # restore end
    jal merge_sort_s

    ld a2, 16(sp)               # restore start
    ld a3, 24(sp)               # restore end
    jal merge_s

done:                           # epilogue
    ld ra, (sp)
    addi sp, sp, 32
    ret

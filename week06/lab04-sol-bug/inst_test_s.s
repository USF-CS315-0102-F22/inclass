.global inst_test_s

inst_test_s:
    blt a0, a1, foo
    li a0, 1
    ret
foo:
    li a0, 2
    ret

mv_test_s:
    mv a0, a1
    ret

srli_test_s:
    srli a0, a0, 1
    ret
    
mul_test_s:
    mul a0, a0, a1
    ret

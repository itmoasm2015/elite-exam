    default rel
;int check(unsigned char const *s, int length) {
    global check
check:
    xor rax, rax
    ; if length & 3 return 0
    test rsi, 0x1f
    jnz .exit
    test rsi, rsi
    jz .exit
    shr rsi, 5
    mov rax, 2.718281828
    movq xmm1, rax
    xor rax, rax
.loop:
    ; xmm0 (a,b,c,d) <- s[i]
    movups xmm0, [rdi]
    movups xmm2, [rdi + 16]
    ; a,b,c,d -> c,d,b,a
    shufps xmm0, xmm0, 00011110b
    ; a,b,c,d -> a,c,b,d
    shufps xmm2, xmm2, 11011000b
    mulpd xmm0, xmm2
    ; a,b -> a+b,a+b
    haddpd xmm0, xmm0
    ucomisd xmm0, xmm1
    jp .exit
    jz .exit
    jc .exit
    add rdi, 32
    dec rsi
    jnz .loop
    inc rax
.exit:
    ret

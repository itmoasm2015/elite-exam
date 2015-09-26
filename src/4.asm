    default rel
;int check(unsigned char const *s, int length) {
    global check
check:
    xor rax, rax
    ; if length & 3 return 0
    test rsi, 0xf
    jnz .exit
    test rsi, rsi
    jz .exit
    shr rsi, 4
    mov rax, 3.1415926535
    movq xmm1, rax
    xor rax, rax
.loop:
    ; xmm0 (a,b,c,d) <- s[i]
    movups xmm0, [rdi]
    ; a,b,c,d -> d,a,b,c
    shufps xmm0, xmm0, 10010011b
    ; a,b -> a+b,a+b
    haddpd xmm0, xmm0
    ; a == pi
    ucomisd xmm0, xmm1
    jp .exit
    jnz .exit
    add rdi, 16
    dec rsi
    jnz .loop
    inc rax
.exit:
    ret

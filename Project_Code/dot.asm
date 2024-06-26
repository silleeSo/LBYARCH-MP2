section .text
bits 64
default rel
global calculateDotProductAsm

calculateDotProductAsm:
    push rbx
    mov rbx, 0
    xorpd xmm0, xmm0             ; Clear xmm0 (dotProduct)
loop_start:
    cmp rbx, r8                   ; Compare current address with end address
    je loop_end                   ; If equal, exit loop
    movsd xmm1, QWORD [rcx]      ; Load double from vector1 to xmm1
    movsd xmm2, QWORD [rdx]      ; Load double from vector2 to xmm2
    mulsd xmm1, xmm2              ; Multiply vector1 element with vector2 element
    addsd xmm0, xmm1              ; Add the result to dotProduct
    add rcx, 8                   ; Move to next element in vector1
    add rdx, 8    
    INC rbx               ; Move to next element in vector2
    jmp loop_start                ; Repeat the loop
loop_end:
    pop rbx
    xor rax, rax
    ret
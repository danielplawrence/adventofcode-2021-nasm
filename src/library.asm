;This can be assembled with NASM, maybe YASM
section .text
bits 64
;See library.hpp and main.cpp for "how to call these functions" from C++ code

;Exported symbols for the resuting object file. These are then just labels below
global compute_answer, sum_4_ints, increment_pointer_int64, sum_two_ints, mul_two_ints, count_increments

;This is just a function that return the number 42
;Return values are "whatever is in RAX" in x64
;
;		int compute_answer()
compute_answer:
	mov rax, 101010b
	ret

;The 4 first arguments are passed on by registers
; RDI - 1st arg
; RSI - 2nd arg
; RCX - 3rd arg
; RDX - 4th arg
;
;		int sum_4_ints(int, int, int, int)
sum_4_ints:
	mov rax, rdi
	add rax, rsi
	add rax, rdx
	add rax, rcx
	ret

increment_pointer_int64:
	add QWORD [rdi], 1
	ret

sum_two_ints:
	mov rax, rdi
    add rax, rsi
    ret

mul_two_ints:
    mov rax, rdi
    mul rsi
    ret

; Count the increments in an array
; RDI will hold a pointer to the first value of the array
; RSI will hold the array length
; Result will be accumulated in RAX and returned
increment:
    inc rax
    jmp next
count_increments:
    push rbp        ; Push this to the stack to preserve the caller's value
    xor rax, rax    ; Initialize RAX to zero
    mov rbp, 50000  ; Set prev val to a large number initially, to ensure the first comparison is false
compare:
    cmp rsi, 0      ; If RSI is 0, we've finished iterating...
    je done         ; ...so we jump to 'done'
    cmp [rdi], rbp  ; otherwise, compare the value at the current index with the previous value...
    jg increment    ; if it's larger, we increment RAX
next:
    mov rbp, [rdi]  ; update RBP with the current val, which becomes the previous val on next iteration
    add rdi, 8      ; increment 8 bits to get the next value of the array
    dec rsi         ; decrement RSI, as we just completed an array iteration
    jnz compare     ; if RSI is not 0, iterate again by jumping to compare
done:
    pop rbp         ; Retrieve the caller's RBP value and put it back in RBP
    ret             ; Return
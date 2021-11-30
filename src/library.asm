;This can be assembled with NASM, maybe YASM
section .text
bits 64
;See library.hpp and main.cpp for "how to call these functions" from C++ code

;Exported symbols for the resuting object file. These are then just labels below
global compute_answer, sum_4_ints, increment_pointer_int64

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

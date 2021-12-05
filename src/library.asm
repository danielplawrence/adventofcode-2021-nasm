section .text
bits 64
;See library.hpp and main.cpp for "how to call these functions" from C++ code

;Exported symbols for the resuting object file. These are then just labels below
global compute_answer, sum_4_ints, increment_pointer_int64, sum_two_ints, mul_two_ints, count_increments, three_element_window
extern malloc
extern realloc
extern free
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

; input is in [rdi]
; srcSize is in rsi
; destSize is in [rdx]
; [rax] will be first element of output
; [rdx] should contain new array size
three_element_window:
three_element_window_setup:
    xor rcx, rcx ; input index
    xor rax, rax ; output index
    mov r9, 0 ; count of output elements
    push r8  ; push r9 to keep stack aligned
    push r9  ; store r9 temporarily, because we need it
    push rdx ; store rdx temporarily, because we need it
    push rdi ; store rdi temporarily, because we need it
    push rsi ; store rsi temporarily, because we need it
    mov rdi, 32 ; allocate a 32 byte array
    call malloc ; rax now points to first element of array
    pop rsi ; restore rsi
    pop rdi ; restore rdi
    pop rdx ; restore rdx
    pop r9 ; restore r9
    pop r8 ; restore r8
    xor r8, r8 ; pointer to end of window
three_element_window_next:
    mov r8, 0   ; init r8
    add r8, rcx ; r8 will be rcx (input index) + 3
    add r8, 3   ; here's where we add 3
    cmp r8, rsi ;if r8 + 3 > srcSize, end
    jg three_element_window_done
three_element_window_sumthreeitems:
    mov r11, 0 ; sum is initially 0
    add r11, [rdi] ; add the first element
    add r11, [rdi + 8] ; add the second element
    add r11, [rdi + 16] ; add the third element
    mov [rax + r9 * 8], r11; add to output array
    add rdi, 8 ; increment the window
    inc rcx ; increment counter
    inc r9 ; increment the output size
    jmp three_element_window_next ; next iteration
three_element_window_done:
    mov [rdx], r9 ; mutate third arg to return array size
    ret
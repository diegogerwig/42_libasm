; ==============================================================================
; ft_strlen.s - Implementation of STRLEN function in x86-64 assembly
; ==============================================================================
; Signature (man 3 strlen):
;   size_t strlen(const char* s);
;
; Description:
;   The strlen() function computes the length of the string 's'.
;
; Input:
;   - 1st argument (rdi): const char* s
;
; Output:
;   - return value (rax): size_t len
;
; Return value:
;   The strlen() function returns the number of bytes in the string pointed 
;   to by s.
; ==============================================================================

section .text
	global _ft_strlen

_ft_strlen:
	cmp 	rdi, 0 					; Compare the input pointer with NULL
	je 		.exit  					; Jump to the exit label if rdi is NULL
	
	mov		rax, 0					; Initialize rax to 0 (representing the length)

.counter_loop:
	cmp		byte [rdi + rax], 0		; Compare the byte at the current position in the string with 0
	je		.exit					; Jump to the exit label if the byte is equal to 0 (end of the string)
	inc		rax						; i++ -> Increment +1 rax value
	jmp		.counter_loop			; Unconditional jump back to the loop label

.exit:
	ret								; Return the value store in rax (length of string)

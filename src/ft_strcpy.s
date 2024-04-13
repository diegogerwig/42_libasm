; ==============================================================================
; ft_strcpy.s - Implementation of STRCPY function in x86-64 assembly
; ==============================================================================
; Signature (man 3 strcpy):
;   char* strcpy(char* dst, const char* src);
;
; Description:
;   The strcpy() function copies the string 'src' to 'dst' (including the 
;   terminating '\0' character).
;
; Inputs:
;   - 1st argument (rdi): char* dst
;   - 2nd argument (rsi): const char* src
;
; Output:
;   - return value (rax): char* dst
;
; Return value:
;   The strcpy() function returns dst.   
;   The stpcpy() function returns a pointer to the terminating `\0' character 
;   of dst.
; ==============================================================================

section .text
	global _ft_strcpy

_ft_strcpy:	
    cmp		rdi, 0 						; Compare the input pointer with NULL
    je		.exit 						; Jump to the exit label if rdi is NULL
    cmp 	rsi, 0 						; Compare the input pointer with NULL
    je		.exit 						; Jump to the exit label if rsi is NULL

    mov		rax, rdi					; Copy rdi to rax
    mov		rcx, -1 					; i = -1

.copy_loop:								; Copy characters from src to dst
    inc		rcx 						; i++
    mov		r8b, byte [rsi + rcx] 		; char r8b = src[i] -> r8b is tmp register
    mov		byte [rdi + rcx], r8b 		; dst[i] = r8b
    cmp		byte [rsi + rcx], 0     	; Check for null terminator '\0'
    jne		.copy_loop          		; if (src[i] == '\0')
    ret									; Return the destination pointer

.exit:
    mov		rax, 0						; rax value = 0
    ret									; Return 0

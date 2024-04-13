; ==============================================================================
; ft_strcmp.s - Implementation of STRCMP function in x86-64 assembly
; ==============================================================================
; Signature (man 3 strcmp):
;	int	strcmp(const char* s1, const char* s2);
;
; Description:
;   The strcmp() function lexicographically compare the null-terminated 
;	strings s1 and s2. 
;	The strcmp() function return an integer greater than, equal to, 
;	or less than 0, according as the string s1 is greater than, equal to, 
;	or less than the string s2.
;
; Inputs:
;   - 1st argument (rdi): const char* s1
;   - 2nd argument (rsi): const char* s2
;
; Output:
;   - return value (rax): int diff
;
; Return value:
;   The strcmp() function return an integer less than, equal to, or greater 
;   than zero if s1 (or the first n bytes thereof) is found, respectively,
;   to be less than, to match, or be greater than s2.
; ==============================================================================

section .text
	global _ft_strcmp

_ft_strcmp:
	cmp 	rdi, 0 					; Compare the input pointer with NULL
	je 		.exit 					; Jump to the exit label if rdi is NULL
	cmp 	rsi, 0  				; Compare the input pointer with NULL
	je 		.exit 					; Jump to the exit label if rsi is NULL
	
	mov		rcx, -1					; i = -1

.compare_loop:
	inc     rcx  					; i++
	mov     r8b, byte[rdi + rcx]  	; char r8b = s1[i] -> r8b is tmp register
	mov     r9b, byte[rsi + rcx]  	; char r9b = s2[i] -> r9b is tmp register

	cmp     r8b, r9b
	jne     .exit  					; if (s1[i] != s2[i])
	cmp     r8b, 0
	je      .exit  					; if (s1[i] == '\0')
	cmp     r9b, 0
	je      .exit					; if (s2[i] == '\0')
	
	jmp     .compare_loop			; Unconditional jump back to the loop label

.exit:
	sub     r8b, r9b				; tmp = s1[i] - s2[i]  -> tmp value store in r8b
	movsx   rax, r8b				; ret = tmp  -> movsx (when source is smaller than destination)
	ret								; Return the value store in rax (diff between strings)

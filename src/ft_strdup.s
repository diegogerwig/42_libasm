; ==============================================================================
; ft_strdup.s - Implementation of STRDUP function in x86-64 assembly
; ==============================================================================
; Signature (man 3 strdup):
;   char* strdup(const char* s);
;
; Description:
;   The strdup() function returns a pointer to a new string which is a 
;	duplicate of the string s.
;	Memory for the new string is obtained with malloc(), and can be freed with 
;	free().
;
; Inputs:
;   - 1st argument (rdi): const char* s
;
; Output:
;   - return value (rax): char* dup
;
; Return value:
;   On success, the strdup() function returns a pointer to the duplicated 
;	string.  
;	It returns NULL if insufficient memory was available, with errno
;	set to indicate the error.
; ==============================================================================

section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_strcpy
	extern ___error

_ft_strdup:
	cmp		rdi, 0			; Compare the input pointer with NULL
	je		.exit			; Jump to the exit label if rdi is NULL

	push	rdi				; Preserve rdi to prevent the value from being modified

	call	_ft_strlen		; Calculate the length of the input string -> strlen(rdi)
	inc		rax				; Increment the length to include the null terminator '\0'
	mov		r12, rdi		; Save the original string address
	mov		rdi, rax		; Set the length as the argument for malloc

	call	_malloc			; Allocate memory for the duplicated string -> malloc(rdi)
	pop 	rdi				; Restore rdi
	cmp		rax, 0			; Check if malloc failed
	je		.ret_error		; if (!malloc) then ret_error()

	mov		rsi, r12		; Set rsi to the original string pointer
	mov		rdi, rax		; Set rdi to the destination (allocated memory) pointer
	call	_ft_strcpy		; Call the _ft_strcpy function to copy the original
							; string to the newly allocated memory -> strcpy(rdi, rsi)

.exit:
	ret						; Return the duplicated string

.ret_error:
	mov		r8, rax			; Save rax in r8 (r8 is a temp register)
	call	___error		; Call the ___error function to handle the error
	mov		[rax], r8		; Store the error code in the location pointed by rax
	mov		rax, -1			; Set rax to -1 to indicate an error
	ret						; Return the value store in rax

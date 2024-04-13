; ==============================================================================
; ft_read.s - Implementation of READ function in x86-64 assembly
; ==============================================================================
; Signature (man 2 read):
;	ssize_t write(int fd, void* buf, size_t nbyte);
;
; Description:
;   read() attempts to read nbyte bytes of data from the object referenced 
;	by the descriptor fildes into the buffer pointed to by buf.
;
; Inputs:
;   - 1st argument (rdi): int fd
;   - 2nd argument (rsi): void* buf
;   - 3rd argument (rdx): size_t length
;
; Output:
;   - return value (rax): ssize_t count
;
; Return value:
;	On success, the number of bytes actually read is returned.
;   On error, a -1 is returned and the global variable errno is set to indicate 
;	the error
; ==============================================================================

section .text
	global _ft_read
	extern ___error

_ft_read:
	mov 	rax, 0x2000003		; Loads the system call number for read into the rax register
	syscall						; Executes the system call (read(fd, buf, length)), 
								; and the result is stored in the rax register
	jnc 	.end				; Jump if no carry flag (it means SUCCESS in syscall)

.ret_error:
	mov 	r8, rax				; Copy the error code to r8
	call 	___error			; Call the ___error function to handle the error
	mov 	[rax], r8			; Store the error code in the location pointed by rax
	mov 	rax, -1 			; Set rax to -1 to indicate an error

.end:
	ret							; Return the value store in rax

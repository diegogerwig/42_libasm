; ==============================================================================
; ft_write.s - Implementation of WRITE function in x86-64 assembly
; ==============================================================================
; Signature (man 2 write):
;	ssize_t write(int fd, const void* buf, size_t nbyte);
;
; Description:
;   write() attempts to write nbyte of data to the object referenced by the 
;	descriptor fildes from the buffer pointed to by buf.
;
; Inputs:
;   - 1st argument (rdi): int fd
;   - 2nd argument (rsi): const void* buf
;   - 3rd argument (rdx): size_t length
;
; Output:
;   - return value (rax): ssize_t count
;
; Return value:
;   On success, the number of bytes which were written is returned.
;	On error, a -1 is returned and the global variable errno is set to indicate 
;	the error.
; ==============================================================================

section .text
	global _ft_write
	extern ___error

_ft_write:
	mov 	rax, 0x2000004		; Loads the system call number for write into the rax register
	syscall						; Executes the system call -> write(fd, buf, length), 
								; and the result is stored in the rax register
	jnc 	.end				; Jump if no carry flag (it means SUCCESS in syscall)

.ret_error:
	mov 	r8, rax				; Copy the error code to r8
	call 	___error			; Call the ___error function to handle the error
	mov 	[rax], r8			; Store the error code in the location pointed by rax
	mov 	rax, -1 			; Set rax to -1 to indicate an error

.end:
	ret							; Return the value store in rax

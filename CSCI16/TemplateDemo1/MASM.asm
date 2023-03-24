; .386
; .model flat, stdcall
; .stack 4096
; ExitProcess PROTO, dwExitCode: DWORD

;INCLUDE Irvine32.inc  ;alternate header

;INCLUDE include\masm32rt.inc  ; 32-bit

.data
hello db "Hello World!", 0   ; 32-bit
;wcount dq 0                 ; 64-bit


.code

start:
	;INVOKE StdOut, ADDR hello   ; 32-bit

	arg -11
	INVOKE GetStdHandle
	arg 0, ADDR wcount, 27
	arg ADDR hello, rax
	INVOKE WriteFile
	xor rax, rax
	ret

	INVOKE ExitProcess, 0
END start
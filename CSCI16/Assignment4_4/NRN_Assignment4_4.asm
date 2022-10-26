; Nicole-Rene Newcomb's code for Assignment4, problem 4

; Program Description: implements pseudocode example
; Author: Nicole-Rene Newcomb
; Creation Date: 10/23/2022

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
val1 dword ?

.code
main PROC
	mov ebx, 5          
	mov val1, 20
NRNLoop:
	cmp ebx, val1
	ja False                ; jumps to False (ending loop) if ebx > val1
	add ebx, 5
	dec val1
	jmp NRNLoop
False:
   INVOKE ExitProcess, 0
main ENDP
END main
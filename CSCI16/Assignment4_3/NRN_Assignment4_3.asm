; Nicole-Rene Newcomb's code for Assignment4, problem 3

; Program Description: implements pseudocode example
; Author: Nicole-Rene Newcomb
; Creation Date: 10/23/2022

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data

.code
main PROC
	mov ebx, 10          ; short-circuits/jumps if ebx > ecx and/or ecx <= edx
	mov ecx, 20
	mov edx, 15
	cmp ebx, ecx
	jg False
	cmp ecx, edx
	jle False
	mov eax, 5
	mov edx, 6
False:
   INVOKE ExitProcess, 0
main ENDP
END main
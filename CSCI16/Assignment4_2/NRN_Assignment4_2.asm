; Nicole-Rene Newcomb's code for Assignment4, problem 2

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
	mov ebx, 10          ; when reversed so ebx is 20 and ecx is 10, jumps to GreaterEBX
	mov ecx, 20
	cmp ebx, ecx
	ja GreaterEBX
	mov eax, 5
	mov edx, 6
GreaterEBX:
   INVOKE ExitProcess, 0
main ENDP
END main
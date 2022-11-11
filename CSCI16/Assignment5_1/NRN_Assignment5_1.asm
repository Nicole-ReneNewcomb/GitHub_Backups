; Nicole-Rene Newcomb's code for Assignment 5, problem 1

; Program Description: multiply AX*26 using shifting/addition
; Author: Nicole-Rene Newcomb
; Creation Date: 11/07/2022

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD


.code
main PROC
	mov eax, 0          ; clear register eax
	mov ebx, 0          ; clear register ebx
	mov edx, 0          ; clear register edx
	mov ax, 13          ; enter value into AX
	mov bx, ax          ; copy value to bx
	mov dx, ax          ; copy value to dx
	shl ax, 4           ; multiples ax value by 2^4 (16)
	shl bx, 3           ; multiplies bx value by 2^3 (8)
	shl dx, 1           ; multiples dx value by 2^1 (2)
	add ax, bx          ; add bx to ax
	add ax, dx          ; add dx to ax - final total is original AX * 26
main ENDP
END main
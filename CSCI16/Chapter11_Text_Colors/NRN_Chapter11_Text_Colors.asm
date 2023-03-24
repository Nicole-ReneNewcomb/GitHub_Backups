; Nicole-Rene Newcomb's code for Assignment 7, problem 1

; Program Description: DrawBox
; Author: Nicole-Rene Newcomb
; Creation Date: 12/05/2022

INCLUDE Irvine32.inc

.data
outHandle DWORD 0
cellsWritten DWORD 0
xyPos COORD <0,10>
; Array of character codes:
buffer BYTE 219, 219, 219, 219, 219, 219, 219, 219, 219, 219
BufSize DWORD ($ - buffer)
; Array of attributes:
attributes WORD 9, 9, 9, 9, 8, 8, 8, 8, 8, 8

.code
main PROC
; Get the Console standard output handle:
	INVOKE GetStdHandle,STD_OUTPUT_HANDLE
	mov outHandle,eax

; Set the colors of adjacent cells:
	INVOKE WriteConsoleOutputAttribute,
		outHandle, 
		ADDR attributes,
		BufSize, 
		xyPos, 
		ADDR cellsWritten

; Write character codes 1 through 20:
	INVOKE WriteConsoleOutputCharacter,
		outHandle, 
		ADDR buffer, 
		BufSize,
		xyPos, 
		ADDR cellsWritten

	INVOKE ExitProcess,0
main ENDP
END main
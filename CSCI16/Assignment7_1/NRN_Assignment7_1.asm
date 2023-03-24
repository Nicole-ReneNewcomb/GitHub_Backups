; Nicole-Rene Newcomb's code for Assignment 7, problem 1

; Program Description: DrawBox
; Author: Nicole-Rene Newcomb
; Creation Date: 12/05/2022

INCLUDE Irvine32.inc


.data
endl EQU <0dh, 0ah>                                    ; end of line sequence
topOfSquare BYTE 201, 205, 205, 205, 205, 205, 187     ; top of square
topSize DWORD ($ - topOfSquare)
middleOfSquare BYTE 186, 32, 32, 32, 32, 32, 186       ; middle sections of square
middleSize DWORD ($ - middleOfSquare)
numberMiddleSections DWORD 2                           ; number of middle sections
bottomOfSquare BYTE 200, 205, 205, 205, 205, 205, 188  ; bottom of square
bottomSize DWORD ($ - bottomOfSquare)
consoleHandle DWORD 0                                 ; handle to standard output device
cellsWritten DWORD 0
windowStart COORD <20,10> 

.code
main PROC
	INVOKE GetStdHandle, STD_OUTPUT_HANDLE
	mov consoleHandle, eax

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR topOfSquare,       ; draw top of square
		topSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y

	mov ecx, numberMiddleSections

Middle:
	push ecx
	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR middleOfSquare,   ; draw middle of square
		middleSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y
	pop ecx
	loop Middle
		

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR bottomOfSquare,   ; draw bottom of square
		bottomSize,
		windowStart,
		ADDR cellsWritten
	INVOKE ExitProcess, 0
main ENDP
END main
; Nicole-Rene Newcomb's code for Assignment 7, problem 4

; Program Description: Draw Colored Moving Square
;	Draws red, purple, blue square and re-draws
;	after moving 200 times with 10-100ms delay
; Author: Nicole-Rene Newcomb
; Creation Date: 12/05/2022

INCLUDE Irvine32.inc

DrawSquare PROTO

.data
topOfSquare BYTE 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh      ; top of square
topSize DWORD ($ - topOfSquare)
middleOfSquare BYTE 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh   ; middle sections of square
middleSize DWORD ($ - middleOfSquare)
numberMiddleSections DWORD 2                                         ; number of middle sections
bottomOfSquare BYTE 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh   ; bottom of square
bottomSize DWORD ($ - bottomOfSquare)
colors WORD 4, 4, 5, 5, 5, 5, 1, 1                    ; red, purple, blue attributes for square
consoleHandle DWORD 0                                 ; handle to standard output device
cellsWritten DWORD 0
windowStart COORD <0,6>                               ; 0,6 min to avoid built-in output messages

.code
main PROC

mov ecx, 200                       ; loop 200 times to move/draw square 200 times

MoveAndDraw:
	push ecx
	call Randomize
	mov ax, 111                   ; range stays in bound my usual pop-up console window
	call RandomRange
	mov windowStart.X, ax
	mov ax, 26                    ; range stays in bound my usual pop-up console window
	call RandomRange
	mov windowStart.Y, ax

	INVOKE DrawSquare             ; draws a red, purple, and blue square
	mov ax, 500                    ; range of 0-90 to be used as ms of delay
	;call RandomRange
	add ax, 10                    ; add 10 to create range from 10 to 100ms for Delay
	call Delay
	pop ecx
	loop MoveAndDraw

	INVOKE ExitProcess, 0

main ENDP

DrawSquare PROC
call Clrscr

INVOKE GetStdHandle, STD_OUTPUT_HANDLE
	mov consoleHandle, eax

	INVOKE WriteConsoleOutputAttribute,
		consoleHandle, 
		ADDR colors,
		topSize, 
		windowStart, 
		ADDR cellsWritten

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

	INVOKE WriteConsoleOutputAttribute,
		consoleHandle, 
		ADDR colors,
		middleSize, 
		windowStart, 
		ADDR cellsWritten

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR middleOfSquare,   ; draw middle of square
		middleSize,
		windowStart,
		ADDR cellsWritten

	inc windowStart.Y
	pop ecx
	loop Middle
		
	INVOKE WriteConsoleOutputAttribute,
		consoleHandle, 
		ADDR colors,
		bottomSize, 
		windowStart, 
		ADDR cellsWritten

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR bottomOfSquare,   ; draw bottom of square
		bottomSize,
		windowStart,
		ADDR cellsWritten

	inc windowStart.Y
	ret

DrawSquare ENDP
END main
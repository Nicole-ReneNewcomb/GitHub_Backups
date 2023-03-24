; Nicole-Rene Newcomb's code for Extra Credit Assignment

; Program Description: Draw Chess Board
; Author: Nicole-Rene Newcomb
; Creation Date: 12/16/2022

INCLUDE Irvine32.inc

DrawBoard PROTO
	

.data
main PROC

boardSquares BYTE 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh
		     BYTE 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh      ; squares of board
boardSquaresSize DWORD ($ - boardSquares)
colorsRow1 WORD 15, 15, 8, 8, 15, 15, 8, 8, 15, 15, 8, 8, 15, 15, 8, 8   ; 1st row colors
colorsRow2 WORD 8, 8, 15, 15, 8, 8, 15, 15, 8, 8, 15, 15, 8, 8, 15, 15   ; 2nd row colors
cellsWritten DWORD 0
windowStart COORD <0,6>       ; 0,6 min to avoid built-in output messages
consoleHandle DWORD 0         ; handle to standard output device


.code

mov ecx, 16

MoveAndDraw:
	push ecx
	INVOKE DrawBoard
	add ax, 500                    ; add 500ms delay
	call Delay
	pop ecx
	loop MoveAndDraw

	INVOKE ExitProcess, 0
main ENDP

DrawBoard PROC

call Clrscr


INVOKE GetStdHandle, STD_OUTPUT_HANDLE
	mov consoleHandle, eax

	mov ecx, 4

AlternatingRows:
	push ecx

	INVOKE WriteConsoleOutputAttribute,
		consoleHandle, 
		ADDR colorsRow1Proc,
		boardSquaresSizeProc, 
		windowStart, 
		ADDR cellsWrittenProc

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR boardSquaresProc,       ; draw 1st row
		boardSquaresSizeProc,
		windowStart,
		ADDR cellsWrittenProc

	inc windowStart.Y

	INVOKE WriteConsoleOutputAttribute,
		consoleHandle, 
		ADDR colorsRow2Proc,
		boardSquaresSizeProc, 
		windowStart, 
		ADDR cellsWrittenProc

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR boardSquaresProc,   ; draw 2nd row
		boardSquaresSizeProc,
		windowStart,
		ADDR cellsWrittenProc

	inc windowStart.Y
	pop ecx
	dec ecx
	cmp ecx, 0
	jnz AlternatingRows
		
	ret

DrawBoard ENDP
END main
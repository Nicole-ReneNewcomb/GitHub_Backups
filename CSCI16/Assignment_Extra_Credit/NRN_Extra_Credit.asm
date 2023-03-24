; Nicole-Rene Newcomb's code for Extra Credit Assignment

; Program Description: Draw Chess Board
; Author: Nicole-Rene Newcomb
; Creation Date: 12/16/2022

INCLUDE Irvine32.inc

DrawBoard PROTO, 
	boardSquaresProc:PTR BYTE,
	colorsRow1Proc:PTR WORD,
	colorsRow2Proc:PTR WORD,
	boardSquaresSizeProc:DWORD, 
	cellsWrittenProc:DWORD

.data


.code
main PROC

boardSquares BYTE 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh
		     BYTE 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh, 0DBh      ; squares of board
boardSquaresSize DWORD ($ - boardSquares)
colorsRow1 WORD 15, 15, 8, 8, 15, 15, 8, 8, 15, 15, 8, 8, 15, 15, 8, 8   ; 1st row colors
colorsRow2 WORD 8, 8, 15, 15, 8, 8, 15, 15, 8, 8, 15, 15, 8, 8, 15, 15   ; 2nd row colors
colors2a WORD 15, 15, 1, 1, 15, 15, 1, 1, 15, 15, 1, 1, 15, 15, 1, 1   ; 1st row colors
colors2b WORD 1, 1, 15, 15, 1, 1, 15, 15, 1, 1, 15, 15, 1, 1, 15, 15   ; 2nd row colors
colors3a WORD 15, 15, 2, 2, 15, 15, 2, 2, 15, 15, 2, 2, 15, 15, 2, 2   ; 1st row colors
colors3b WORD 2, 2, 15, 15, 2, 2, 15, 15, 2, 2, 15, 15, 2, 2, 15, 15   ; 2nd row colors
colors4a WORD 15, 15, 3, 3, 15, 15, 3, 3, 15, 15, 3, 3, 15, 15, 3, 3   ; 1st row colors
colors4b WORD 3, 3, 15, 15, 3, 3, 15, 15, 3, 3, 15, 15, 3, 3, 15, 15   ; 2nd row colors
colors5a WORD 15, 15, 4, 4, 15, 15, 4, 4, 15, 15, 4, 4, 15, 15, 4, 4   ; 1st row colors
colors5b WORD 4, 4, 15, 15, 4, 4, 15, 15, 4, 4, 15, 15, 4, 4, 15, 15   ; 2nd row colors
colors6a WORD 15, 15, 5, 5, 15, 15, 5, 5, 15, 15, 5, 5, 15, 15, 5, 5   ; 1st row colors
colors6b WORD 5, 5, 15, 15, 5, 5, 15, 15, 5, 5, 15, 15, 5, 5, 15, 15   ; 2nd row colors
cellsWritten DWORD 0

.data
main PROC

	INVOKE DrawBoard,
		ADDR boardSquares,
		ADDR colorsRow1,
		ADDR colorsRow2,
		boardSquaresSize, 
		cellsWritten

	INVOKE DrawBoard,
		ADDR boardSquares,
		ADDR colors2a,
		ADDR colors2b,
		boardSquaresSize, 
		cellsWritten

	INVOKE DrawBoard,
		ADDR boardSquares,
		ADDR colors3a,
		ADDR colors3b,
		boardSquaresSize, 
		cellsWritten

	INVOKE DrawBoard,
		ADDR boardSquares,
		ADDR colors4a,
		ADDR colors4b,
		boardSquaresSize, 
		cellsWritten

	INVOKE DrawBoard,
		ADDR boardSquares,
		ADDR colors5a,
		ADDR colors5b,
		boardSquaresSize, 
		cellsWritten

	INVOKE DrawBoard,
		ADDR boardSquares,
		ADDR colors6a,
		ADDR colors6b,
		boardSquaresSize, 
		cellsWritten
	
	add ax, 500                    ; add 500ms delay
	call Delay
	pop ecx

	INVOKE ExitProcess, 0
main ENDP

DrawBoard PROC,
	boardSquaresProc:PTR BYTE,
	colorsRow1Proc:PTR WORD,
	colorsRow2Proc:PTR WORD,
	boardSquaresSizeProc:DWORD, 
	cellsWrittenProc:DWORD

LOCAL windowStart:COORD,
consoleHandle:DWORD

mov windowStart.X, 6       ; 0,6 min to avoid built-in output messages
mov consoleHandle, 0         ; handle to standard output device

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
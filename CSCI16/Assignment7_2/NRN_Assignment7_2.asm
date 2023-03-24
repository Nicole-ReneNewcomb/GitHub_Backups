; Nicole-Rene Newcomb's code for Assignment 7, problem 2

; Program Description: Draw Triangle
; Author: Nicole-Rene Newcomb
; Creation Date: 12/05/2022

INCLUDE Irvine32.inc


.data
topOfTriangle BYTE 32, 32, 32, 32, 47, 92, 32, 32, 32, 32
topSize DWORD ($ - topOfTriangle)
rowTwo BYTE 32, 32, 32, 47, 32, 32, 92, 32, 32, 32      
rowTwoSize DWORD ($ - rowTwo)
rowThree BYTE 32, 32, 47, 32, 32, 32, 32, 92, 32, 32 
rowThreeSize DWORD ($ - rowThree)
rowFour BYTE 32, 47, 32, 32, 32, 32, 32, 32, 92, 32  
rowFourSize DWORD ($ - rowFour)
bottomOfTriangle BYTE 47, 95, 95, 95, 95, 95, 95, 95, 95, 92
bottomSize DWORD ($ - bottomofTriangle)
consoleHandle DWORD 0                                 ; handle to standard output device
cellsWritten DWORD 0
windowStart COORD <20,10> 

.code
main PROC
	INVOKE GetStdHandle, STD_OUTPUT_HANDLE
	mov consoleHandle, eax

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR topOfTriangle,       ; draw top of triangle
		topSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR rowTwo,   ; draw 2nd row of triangle
		rowTwoSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR rowThree,   ; draw 3rd row of triangle
		rowThreeSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR rowFour,   ; draw 4th row of triangle
		rowFourSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y
		

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR bottomOfTriangle,   ; draw bottom of triangle
		bottomSize,
		windowStart,
		ADDR cellsWritten
	INVOKE ExitProcess, 0
main ENDP
END main
; Nicole-Rene Newcomb's code for Assignment 7, problem 3

; Program Description: Draw House
; Author: Nicole-Rene Newcomb
; Creation Date: 12/05/2022

INCLUDE Irvine32.inc


.data
topOfHouse BYTE 218, 196, 196, 196, 196, 196, 196, 196, 196, 191     
topHouseSize DWORD ($ - topOfHouse)
middleOfHouse BYTE 179, 32, 32, 32, 32, 32, 32, 32, 32, 179      
middleHouseSize DWORD ($ - middleOfHouse)      
doorTop BYTE 179, 201, 205, 187, 32, 32, 201, 205, 187, 179      
doorTopSize DWORD ($ - doorTop)     
doorMiddle BYTE 179, 186, 32, 186, 32, 32, 186, 32, 186, 179      
doorMiddleSize DWORD ($ - doorMiddle)   
windowBottom BYTE 179, 186, 32, 186, 32, 32, 200, 205, 188, 179      
windowBottomSize DWORD ($ - windowBottom)   
doorBottom BYTE 179, 200, 205, 188, 32, 32, 32, 32, 32, 179      
doorBottomSize DWORD ($ - doorBottom) 
bottomOfHouse BYTE 192, 196, 196, 196, 196, 196, 196, 196, 196, 217 
bottomHouseSize DWORD ($ - bottomOfHouse)
topOfTriangle BYTE 32, 32, 32, 32, 47, 92, 32, 32, 32, 32
topSize DWORD ($ - topOfTriangle)
rowTwo BYTE 32, 32, 32, 47, 218, 191, 92, 32, 32, 32      
rowTwoSize DWORD ($ - rowTwo)
rowThree BYTE 32, 32, 47, 32, 179, 179, 32, 92, 32, 32 
rowThreeSize DWORD ($ - rowThree)
rowFour BYTE 32, 47, 32, 32, 192, 217, 32, 32, 92, 32  
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

; triangle roof
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
	inc windowStart.Y

; square house
	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR topOfHouse,       ; draw top of house
		topHouseSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y
	
	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR middleOfHouse,   ; draw non window/door portion of house
		middleHouseSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR doorTop,   ; draw top of window/door portion of house
		doorTopSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR doorMiddle,   ; draw middle of window/door portion of house
		doorMiddleSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR windowBottom,   ; draw bottom of window portion of house
		windowBottomSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y

	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR doorBottom,   ; draw bottom of door portion of house
		doorBottomSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y
		
	INVOKE WriteConsoleOutputCharacter,
		consoleHandle,
		ADDR bottomOfHouse,   ; draw bottom of house
		bottomHouseSize,
		windowStart,
		ADDR cellsWritten
	inc windowStart.Y

	INVOKE ExitProcess, 0
main ENDP
END main
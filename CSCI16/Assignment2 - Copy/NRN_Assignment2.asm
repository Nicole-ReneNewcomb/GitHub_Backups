INCLUDE Irvine32.inc
INCLUDE Macros.inc

mWritestringAttr Macro theString, color
call Clrscr
mov eax, color + (lightGray * 16)
mov esi, OFFSET mystring
call SetTextColor
INVOKE WriteConsole,
consoleHandle, 
ADDR theString, 
LENGTHOF theString - 1, 
ADDR bytesWritten,
0
endm

.data
myString BYTE "Here is my string", 0
myString2 BYTE "Here's a second string", 0
myString3 BYTE "Why not a third string for fun?", 0
consoleHandle DWORD 0
bytesWritten DWORD 0


.code
main PROC
mWriteStringAttr myString, white
mWriteStringAttr myString, blue
mWriteStringAttr myString, red




main ENDP
END main
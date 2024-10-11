.386
.model flat, stdcall
.stack 4096
.data
list db 10, 20, 30, 40, 50
listlen = $ - list

var byte 5h

var1 sbyte -7
var2 sbyte 4, 6, -7, -8, 9
var3 sword ?
var4 sdword -6, -2
var5 sword 3 dup(10)
var6 sdword 5 dup(-30)
var7 byte "This is my lab number 4", "&"

.code

main PROC

;mov al, list[1]
;add al, 2
;mov list[1], al

;mov al, list[3]
;add al, 5
;mov list[3], al

mov al, var

mov list[0], al

main ENDP
END main
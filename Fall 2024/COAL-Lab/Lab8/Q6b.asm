comment @
.386
.model flat,stdcall
.stack 4096
GetStdHandle PROTO, nStdHandle:DWORD
WriteConsoleA PROTO, a1:DWORD, a2: PTR BYTE, a3: DWORD, a4: ptr dword, a5: DWORD
ReadConsoleA PROTO, a1:DWORD, a2: PTR BYTE, a3: DWORD, a4: ptr dword, a5: DWORD

.data
stars db "*", 0
endl db " ", 0dh, 0ah, 0
i db 6
j db 6
k db 2
x dd ?

.code
main PROC

L1:
	mov ecx, 0
	mov al, k  ; mov i here to print in reverse order
	mov j, al
	movzx ecx, j

	L2:
		invoke GetStdHandle, -11
		invoke WriteConsoleA, eax, offset stars, lengthof stars, offset x, 0
		dec j
		mov cl, j

	loop L2

	; Print new line
    invoke GetStdHandle, -11
    invoke WriteConsoleA, eax, offset endl, lengthof endl, offset x, 0
	inc k
    dec i
	mov cl, i

loop L1

main ENDP
END main
@
end
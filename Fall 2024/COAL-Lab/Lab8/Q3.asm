comment @
.386
.model flat,stdcall
.stack 4096
GetStdHandle PROTO, nStdHandle:DWORD
WriteConsoleA PROTO, a1:DWORD, a2: PTR BYTE, a3: DWORD, a4: ptr dword, a5: DWORD
ReadConsoleA PROTO, a1:DWORD, a2: PTR BYTE, a3: DWORD, a4: ptr dword, a5: DWORD

.data
input db ?      ; Buffer to hold input
output db ?     ; Buffer to hold output message
prompt db "Enter a number: ", 0
msg1 db "The number is even ", 0
msg2 db "The number is odd ", 0
x dd ?

.code
main proc
    ; Get stdout handle
    invoke GetStdHandle, -11
    
    ; Display prompt
    invoke WriteConsoleA, eax, offset prompt, lengthof prompt, offset x, 0
    
    ; Get stdin handle
    invoke GetStdHandle, -10
    
    invoke ReadConsoleA, eax, offset input, lengthof input, offset x, 0
    
    mov al, input
    sub al, 48  ; Convert from ASCII to actual number (0-9 range)
    
    ; Check if the number is even or odd using bitwise AND
    test al, 1
    jz even_number
    
    ; If odd
    invoke GetStdHandle, -11
    invoke WriteConsoleA, eax, offset msg2, lengthof msg2, offset x, 0
    jmp done

even_number:
    ; If even
    invoke GetStdHandle, -11
    invoke WriteConsoleA, eax, offset msg1, lengthof msg1, offset x, 0

done:
    ret

main ENDP
END main
@
end
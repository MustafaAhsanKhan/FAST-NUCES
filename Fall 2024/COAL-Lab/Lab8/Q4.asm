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
prompt db "Enter a letter: ", 0
msg db "Previous letter: ", 0
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
    dec al
    
    ; Store result in output buffer
    mov output, al

    invoke GetStdHandle, -11
    invoke WriteConsoleA, eax, offset msg, lengthof msg, offset x, 0

    invoke GetStdHandle, -11
    invoke WriteConsoleA, eax, offset output, lengthof output, offset x, 0

    ret

main ENDP
END main
@
end
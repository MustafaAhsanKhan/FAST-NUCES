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
prompt db "Enter your marks: ", 0
msg1 db "You got D grade", 0
msg2 db "You got C grade", 0
msg3 db "You got B grade", 0
msg4 db "You got A grade", 0
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

    cmp al, 5
    jb D_Grade

    cmp al, 7
    jb C_Grade

    cmp al, 9
    jb B_Grade

    cmp al, 9
    je A_Grade


D_Grade:
    invoke GetStdHandle, -11
    invoke WriteConsoleA, eax, offset msg1, lengthof msg1, offset x, 0
    jmp done

C_Grade:
    invoke GetStdHandle, -11
    invoke WriteConsoleA, eax, offset msg2, lengthof msg2, offset x, 0
    jmp done

B_Grade:
    invoke GetStdHandle, -11
    invoke WriteConsoleA, eax, offset msg3, lengthof msg3, offset x, 0
    jmp done

A_Grade:
    invoke GetStdHandle, -11
    invoke WriteConsoleA, eax, offset msg4, lengthof msg4, offset x, 0
    jmp done

    
done:
    ret

main ENDP
END main
@
end
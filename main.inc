print macro cadena ; print-> id del macro; macro > reservada, cadena
MOV ah,09h
MOV dx,@data
MOV ds,dx
MOV dx, offset cadena
int 21h
endm        

getText macro buffer
PUSH SI 
PUSH AX 

xor si,si
CONTINUE:
getChar
cmp al,0dh
je FIN
mov buffer[si],al
inc si
jmp CONTINUE

FIN:
mov al, '$'
mov buffer[si],al

POP AX
POP SI
endm

getChar MACRO 
mov ah,01h
int 21h
endm

printChar macro char 
mov ah,02h
mov dl,char
int 21h
endm
;=======================SECCION DE EJECUTABLE
.model small
.stack  
.data
;====================== SEGMENTO DE DATOS =================
; VARIABLES
arreglo db 20 dup('$'), '$'
encab db 'UNIVERSIDAD DE SAN CARLOS DE GUATEMALA', 10,13,  'FACULTAD DE INGENIERIA',10,13, 'CIENCIAS Y SISTEMAS',10,13,'ARQUITECTURA DE COMPUTADORES Y ENSAMBLADORES', 10,13, 'JUAN JOSE RAMOS CAMPOS', 10,13, '201801262', 10,13,'SECCION:A',10,13, ' ',10,13, '1) Iniciar Juego',10,13,'2) Cargar juego',10,13, '3) Salir', 10,13,10,13, 'Escoja Una opcion:','$'  
tplayerb db 10,13,'Turno Jugador Blanco', '$'
tplayern db 10,13,'Turno Jugador Negro', '$'

;======================= SEGMENTO CODIGO ==================
.code
main proc
    MENUPRINCIPAL:
    print encab
    getChar
    cmp al,'1'
    MOV dx,1 
    je NEWGAME
    cmp al,'2'
    je OPENGAME
    cmp al,'3'
    je EXIT
    jmp MENUPRINCIPAL

NEWGAME:
    cmp dx,1
    je TURNOPLAYERBLANCO
    cmp dx,0
    je TURNOPLAYERNEGRO


TURNOPLAYERBLANCO:
    MOV dx, 0
    print tplayerb
    getChar
    jmp MENUPRINCIPAL


TURNOPLAYERNEGRO:
    MOV dx, 1
    print tplayern
    getChar
    jmp MENUPRINCIPAL

OPENGAME:
print tplayerb
getChar
jmp MENUPRINCIPAL
EXIT:
        mov ah,4ch
        int 21h
main endp


end
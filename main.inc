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

;========== MACRO TABLERO

include tablero.inc

;========== END MACRO TABLERO



;=======================SECCION DE EJECUTABLE
.model small
.stack  
.data
;====================== SEGMENTO DE DATOS =================
;========== VARIABLES
arreglo     db 20 dup('$'), '$'
encab       db 'UNIVERSIDAD DE SAN CARLOS DE GUATEMALA', 10,13,  'FACULTAD DE INGENIERIA',10,13, 'CIENCIAS Y SISTEMAS',10,13,'ARQUITECTURA DE COMPUTADORES Y ENSAMBLADORES', 10,13, 'JUAN JOSE RAMOS CAMPOS', 10,13, '201801262', 10,13,'SECCION:A',10,13, ' ',10,13, '1) Iniciar Juego',10,13,'2) Cargar juego',10,13, '3) Salir', 10,13,10,13, 'Escoja Una opcion:','$'  
tplayerb    db 10,13,'Turno Jugador Blanco', '$'
tplayern    db 10,13,'Turno Jugador Negro', '$'

;========== VARIABLES ARCHIVO
filepath    db 100 dup('$') ; ruta archivo
buffread    db 200 dup('$') ; buffer lectura
buffwrite   db 200 dup('$') ; buffer escritura
handlefile  dw ?

;========== VARIABLES TABLERO
turn    db 0b
row     db 0b
col     db 0b
rowF    db 0b
colF    db 0b
dist    db 0b
tipe    db 0b
actual  db 0b
comer   db 0b

row8    db 101b,000b,101b,000b,101b,000b,101b,000b
row7    db 000b,101b,000b,101b,000b,101b,000b,101b
row6    db 101b,000b,101b,000b,101b,000b,101b,000b
row5    db 000b,000b,000b,000b,000b,000b,000b,000b
row4    db 000b,000b,000b,000b,000b,000b,000b,000b
row3    db 000b,100b,000b,100b,000b,100b,000b,100b
row2    db 100b,000b,100b,000b,100b,000b,100b,000b
row1    db 000b,100b,000b,100b,000b,100b,000b,100b



entere  db 0ah,0dh,'$'
eig     db '8   |','$'
sev     db '7   |','$'
six     db '6   |','$'
fiv     db '5   |','$'
fou     db '4   |','$'
thr     db '3   |','$'
two     db '2   |','$'
one     db '1   |','$'

fneg    db 'FNEG|','$'

fblc    db 'FBLA|','$'
rneg    db 'RNEG|','$'
rblc    db 'RBLA|','$'

void    db '    |','$'
marc    db 0ah,0dh,32,32,32,32,'-----------------------------------------',0ah,0dh,'$'
lett    db 0ah,0dh,32,32,32,32,'  A    B    C    D    E    F    G    H','$'

;======================= SEGMENTO CODIGO ==================
.code
main proc
    MENUPRINCIPAL:
    print encab
    getChar
    cmp al,'1'
    
    xor cx,cx
    MOV cx, 1 
    je NEWGAME
    cmp al,'2'
    je OPENGAME
    cmp al,'3'
    je EXIT
    jmp MENUPRINCIPAL


;========== JUEGO


NEWGAME:

;========== TABLERO
    printTablero8 row8, eig
    printTablero7 row7, sev
    printTablero6 row6, six
    printTablero5 row5, fiv
    
    printTablero4 row4, fou
    printTablero3 row3, thr
    printTablero2 row2, two
    printTablero  row1, one

;========== END TABLERO









;========== LOOP DE TURNO ============    
    cmp cx,1
    je  IFBLANCO
    ELSENEGRO:
        xor cx,cx
        MOV cx,1 
        print tplayern
        getChar
        jmp NEWGAME
    
IFBLANCO:
    xor cx,cx
    MOV cx,2
    print tplayerb
    getChar
    jmp NEWGAME
;========== END LOOP DE TURNO ============    


OPENGAME:

jmp MENUPRINCIPAL
EXIT:
        mov ah,4ch
        int 21h
main endp


end
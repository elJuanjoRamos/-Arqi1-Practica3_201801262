print macro cadena ; print-> id del macro; macro > reservada, cadena
MOV ah,09h
MOV dx,@data
MOV ds,dx
MOV dx, offset cadena
int 21h
endm        

getText macro buffer
LOCAL CONTINUE, FIN
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


COMPARARSAVE macro buffer   ;   MACRO QUE SE ENCARGA DE COMPARAR EL COMANDO EJECUTADO
LOCAL IGUAL, DIFERENTE
   
    xor CX, CX
    mov cx,4   ;Determinamos la cantidad de datos a leer/comparar
    mov AX,DS  ;mueve el segmento datos a AX
    mov ES,AX  ;Mueve los datos al segmento extra
    lea si, buffer                ; Reset pointer to arr1
    lea di, savecommand

    repe cmpsb  ;compara las dos cadenas
    je IGUAL ;Si fueron iguales
    jne DIFERENTE

    IGUAL:
        jmp CREATE

    DIFERENTE:
        MOV cx, 7
endm

COMPARAREXIT macro buffer   ;   MACRO QUE SE ENCARGA DE COMPARAR EL COMANDO EJECUTADO
LOCAL IGUAL, DIFERENTE
   
    xor CX, CX
    mov cx,4   ;Determinamos la cantidad de datos a leer/comparar
    mov AX,DS  ;mueve el segmento datos a AX
    mov ES,AX  ;Mueve los datos al segmento extra
    lea si, buffer                ; Reset pointer to arr1
    lea di, exitcommand

    repe cmpsb  ;compara las dos cadenas
    je IGUAL ;Si fueron iguales
    jne DIFERENTE

    IGUAL:
        jmp EXIT
    DIFERENTE:
        MOV cx, 7
endm


COMPARARSHOW macro buffer   ;   MACRO QUE SE ENCARGA DE COMPARAR EL COMANDO EJECUTADO
LOCAL IGUAL, DIFERENTE
   
    xor CX, CX
    mov cx,4   ;Determinamos la cantidad de datos a leer/comparar
    mov AX,DS  ;mueve el segmento datos a AX
    mov ES,AX  ;Mueve los datos al segmento extra
    lea si, buffer                ; Reset pointer to arr1
    lea di, showcommand

    repe cmpsb  ;compara las dos cadenas
    je IGUAL ;Si fueron iguales
    jne DIFERENTE

    IGUAL:
        jmp SHOW
    DIFERENTE:
        MOV cx, 7
endm

;========== MACRO FECHA Y HORA

getDate macro
mov ah, 2ah
int 21h
endm

getHour macro
mov ah, 2ch
int 21h
endm

obtenerFecha macro dia, mes, ano, hora, minuto
xor ax,ax
xor bx,bx
getDate
mov bx,cx
convertirString bx, ano
xor bx,bx
getDate
moV bl,dh
convertirString bx, mes
xor bx,bx
getDate
mov bl,dl
convertirString bx, dia
xor bx,bx
getHour
mov bl,ch
convertirString bx, hora
xor bx,bx
getHour
mov bl,cl 
convertirString bx, minuto
endm


convertirString macro res, buffer
    LOCAL DIVIDIR, DIVIDIR2, FINC3, FIN
    XOR SI,SI
    XOR CX,CX
    XOR aX,aX
    
    mov AX,res
    mov dl,0ah
    JMP DIVIDIR2
    
    DIVIDIR:
        XOR AH,AH

    DIVIDIR2:
        DIV DL
        INC CX
        PUSH AX
        CMP AL,00H
        JE FINC3
        JMP DIVIDIR

    FINC3:
        POP AX
        ADD AH,30H
        MOV buffer[SI], AH
        INC SI
        LOOP FINC3
        MOV AH,24H
        MOV buffer[SI],AH
        inc si
    FIN:

endm

;convertirString macro buffer
;    LOCAL DIVIDIR, DIVIDIR2, FINC3, NEGARIGO, FIN2, FIN
;    XOR SI,SI
;    XOR CX,CX
;    XOR BX,BX
;    XOR DX,DX
;    MOV DL,0ah
;    TEST AX,1000000000000000
;    JNZ NEGARIGO
;    JMP DIVIDIR2

;    NEGARIGO:
;        NEG AX
;        MOV buffer[SI],45
;        INC SI
;        JMP DIVIDIR2
    
;    DIVIDIR:
;        XOR AH,AH

;    DIVIDIR2:
;        DIV DL
;        INC CX
;        PUSH AX
;        CMP AL,00H
;        JE FINC3
;        JMP DIVIDIR

;    FINC3:
;        POP AX
;        ADD AH,30H
;        MOV buffer[SI], AH
;        INC SI
;        LOOP FINC3
;        MOV AH,24H
;        MOV buffer[SI],AH
;        inc si
;    FIN:

;endm


;========== END MACRO FECHA HORA

;========== MACRO TABLERO

include tablero.inc
include archivo.inc
include ahmlt.inc
include mover.inc
;========== END MACRO TABLERO



;=======================SECCION DE EJECUTABLE
.model small
.stack  
.data
;====================== SEGMENTO DE DATOS =================
;========== VARIABLES

comando     db 7 dup('$'), '$'
savecommand db 'SAVE', '$'
exitcommand db 'EXIT', '$'
showcommand db 'SHOW', '$'

encab       db 'UNIVERSIDAD DE SAN CARLOS DE GUATEMALA', 10,13,  'FACULTAD DE INGENIERIA',10,13, 'CIENCIAS Y SISTEMAS',10,13,'ARQUITECTURA DE COMPUTADORES Y ENSAMBLADORES', 10,13, 'JUAN JOSE RAMOS CAMPOS', 10,13, '201801262', 10,13,'SECCION:A',10,13, ' ',10,13, '1) Iniciar Juego',10,13,'2) Cargar juego',10,13, '3) Salir', 10,13,10,13, 'Escoja Una opcion:','$'  
tplayerb    db 10,13,'Turno Jugador Blanco: ', '$'
tplayern    db 10,13,'Turno Jugador Negro: ', '$'
error       db 10,13,'Comando no soportado ',10,13, '$'
final       db 10,13,'Gracias pr jugar, vuelva pronto :) ',10,13, '$'




;========== VARIABLES ARCHIVO
filepath    db 100 dup('$') ; ruta archivo
buffread    db 200 dup('$') ; buffer lectura
buffwrite   db 200 dup('$') ; buffer escritura
handlefile  dw ?


msgcreatefile   db 0ah,0dh, 'Ingrese el nombre para guardar: ', 32, '$'
msgfilesave     db 0ah,0dh, 'Juego guardado con exito! ', 32, '$'


msgOpenFile db 0ah,0dh, 'Ingrese el nombre para abrir: ', 32, '$'
msgFileOpen db 0ah,0dh, 'Juego cargado con exito! ', 32, '$'

msmError1 db 0ah,0dh,'Error al abrir archivo','$'
msmError2 db 0ah,0dh,'Error al leer archivo','$'
msmError3 db 0ah,0dh,'Error al crear archivo','$'
msmError4 db 0ah,0dh,'Error al Escribir archivo','$'






abrirhtml   db 0ah, 0dh, '<!DOCTYPE html><html><head><style>table, th, td {border: 1px solid black;border-collapse: collapse;}</style></head></body><h2>Juan Jose Ramos</h2><br> '
abrirfecha   db 0ah, 0dh, '<h2>'
cerrarfecha   db 0ah, 0dh, '</h2><table>'

fichaNegra   db 0ah, 0dh, '<td bgcolor="black"><img src="afn.jpg"></td>'
reinaNegra   db 0ah, 0dh, '<td bgcolor="black"><img src="afn.jpg"></td>'
vacioNegra   db 0ah, 0dh, '<td bgcolor="black"><img src="avn.jpg"></td>'
fichaBlanca  db 0ah, 0dh, '<td bgcolor="white"><img src="afb.jpg"></td>'
reinaBlanca  db 0ah, 0dh, '<td bgcolor="white"><img src="afb.jpg"></td>'
vacioBlanca  db 0ah, 0dh, '<td bgcolor="white"><img src="avb.jpg"></td>'

tropen       db 0ah, 0dh, '<tr>'
trclose       db 0ah, 0dh, '</tr>'


pos1    db 1 dup('0')
pos2    db 1 dup('0')
dia     db 2 dup('0'), ' '
mes     db 1 dup('0'), ' '
ano     db 4 dup('0'), ' '
hora    db 2 dup('0'), ' '
minuto  db 2 dup('0'), ' '
slash   db '/'
slash1   db '--'
slash2   db ':'
cerrarhtml  db 0ah, 0dh, '</table></body></html>'

msj4 db 0ah,0dh, 'LLEGO A NADA ', '$'
msj5 db 0ah,0dh, 'LLEGO A EXIT', '$'
msj6 db 0ah,0dh, 'IGUALES', '$'
msj7 db 0ah,0dh, 'LLEGO A SHOW', '$'

;========== VARIABLES TABLERO


row8    db 101b,000b,101b,000b,101b,000b,101b,000b
row7    db 000b,101b,000b,101b,000b,101b,000b,101b
row6    db 101b,000b,101b,000b,101b,000b,101b,000b
row5    db 000b,000b,000b,000b,000b,000b,000b,000b
row4    db 000b,000b,000b,000b,000b,000b,000b,000b
row3    db 000b,100b,000b,100b,000b,100b,000b,100b
row2    db 100b,000b,100b,000b,100b,000b,100b,000b
row1    db 000b,100b,000b,100b,000b,100b,000b,100b



entere  db 0ah,0dh,'$'
endline db 0ah,0dh
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

txtfneg    db '1'
txtfblc    db '2'
txtrneg    db '3'
txtrblc    db '4'
txtvoid    db '0'


marc    db 0ah,0dh,32,32,32,32,'-----------------------------------------',0ah,0dh,'$'
lett    db 0ah,0dh,32,32,32,32,'  A    B    C    D    E    F    G    H','$'

mensajito    db 0ah,0dh,' LLEGO A 1 ',0ah,0dh,'$'

mensajito2    db 0ah,0dh,' LLEGO A 0 ',0ah,0dh,'$'

;======================= SEGMENTO CODIGO ==================
.code
main proc
    MENUPRINCIPAL:
    print encab
    getChar
    cmp al,'1' 
    je NEWGAME
    cmp al,'2'
    je OPENGAME
    cmp al,'3'
    je ENDGAME
    jmp MENUPRINCIPAL


;========== JUEGO


NEWGAME:
    xor cx,cx
    MOV cx, 1
    jmp LOOPJUEGO

LOOPJUEGO:
;========== TABLERO
    printTablero row8, eig
    printTablero row7, sev
    printTablero row6, six
    printTablero row5, fiv
    
    printTablero row4, fou
    printTablero row3, thr
    printTablero row2, two
    printTablero row1, one
    print marc
    print lett
    
;========== END TABLERO




;========== LOOP DE TURNO ============    
    cmp cx,1
    je  IFBLANCO
    ELSENEGRO:
        print tplayern
        getText comando

        COMPARARSAVE comando
        COMPARARSHOW comando
        COMPARAREXIT comando
        moverFichaNegro

        xor cx,cx
        MOV cx,1 
    
        jmp LOOPJUEGO
    
IFBLANCO:
    print tplayerb
    getText comando
    COMPARARSAVE comando
    COMPARARSHOW comando
    COMPARAREXIT comando
    moverFichaBlanco
    
    xor cx,cx
    MOV cx,2
    
    jmp LOOPJUEGO
;========== END LOOP DE TURNO ============    


OPENGAME:
    print msgOpenFile
    getRuta filepath
    openFile filepath, handlefile
    
    readFile SIZEOF buffread,buffread,handlefile
	closeFile handlefile
	print buffread
	
    obtenerArregloTablero buffread, row8, row7, row6, row5, row4, row3, row2, row1
    getChar

    xor cx,cx
    MOV cx, 1
    jmp LOOPJUEGO

jmp MENUPRINCIPAL

SHOW:
    
    obtenerFecha dia, mes, ano, hora, minuto 
    
    print msgcreatefile
    getRuta filepath
    createFile filepath,handlefile
    openhtml filepath, handlefile
    
    ;abrir html
    whritehtml SIZEOF abrirhtml, abrirhtml, handlefile
    whritehtml SIZEOF abrirfecha,abrirfecha,handlefile
    
    whritehtml SIZEOF dia, dia, handlefile
    whritehtml SIZEOF slash, slash, handlefile
    
    whritehtml SIZEOF mes, mes, handlefile
    whritehtml SIZEOF slash, slash, handlefile
    
    whritehtml SIZEOF ano, ano, handlefile
    whritehtml SIZEOF slash, slash, handlefile
    
    
    whritehtml SIZEOF slash1, slash1, handlefile
    whritehtml SIZEOF hora, hora, handlefile
    whritehtml SIZEOF slash2, slash2, handlefile
    whritehtml SIZEOF minuto, minuto, handlefile
    
    whritehtml SIZEOF cerrarfecha, cerrarfecha, handlefile
    
    htmltablero row8, handlefile 
    htmltablero row7, handlefile 
    htmltablero row6, handlefile 
    htmltablero row5, handlefile 
    htmltablero row4, handlefile 
    htmltablero row3, handlefile 
    htmltablero row2, handlefile 
    htmltablero row1, handlefile 

    ;cerrar html
    whritehtml SIZEOF cerrarhtml, cerrarhtml, handlefile
    closehtml handlefile
    print msgfilesave
    getChar
    jmp LOOPJUEGO


;;;; ========== CREA EL ARCHIVO DEL TABLERO
CREATE:
    print msgcreatefile
    getRuta filepath
    createFile filepath,handlefile
    openFile filepath, handlefile
    
    txttablero row8, handlefile 
    txttablero row7, handlefile 
    txttablero row6, handlefile 
    txttablero row5, handlefile 
    txttablero row4, handlefile 
    txttablero row3, handlefile 
    txttablero row2, handlefile 
    txttablero row1, handlefile 
    
    closeFile handlefile
    print msgfilesave
	getChar
    jmp NEWGAME


ErrorAbrir:
	print msmError1
	getChar
	jmp MENUPRINCIPAL
ErrorLeer:
	print msmError2
	getChar
	jmp MENUPRINCIPAL
ErrorCrear:
	print msmError3
	getChar
	jmp MENUPRINCIPAL
ErrorEscribir:
	print msmError4
	getChar
	jmp MENUPRINCIPAL


EXIT:        
    jmp MENUPRINCIPAL

ENDGAME:
    print final
    mov ah,4ch
    int 21h

main endp



end


printTablero macro buffer, row  ; Rcorre el arreglo que viene (buffer) y hace print de las cosas

PUSH SI
PUSH AX

xor si,si
print marc
print row ;imprime la columna, 8,7,6,...,1

CONT:
    cmp si,8
    je FIN

    cmp buffer[si], 101b
    je FN
    cmp buffer[si], 100b
    je FB
    jmp S

    FN:
        PrintFichaNegra CONT
    FB: 
        PrintFichaBlanca CONT
    S:
        PrintSpace CONT
FIN:
print marc
print lett

POP AX
POP SI
xor si,si
endm




printTablero2 macro buffer, row  ; Rcorre el arreglo que viene (buffer) y hace print de las cosas

PUSH SI
PUSH AX

xor si,si
print marc
print row ;imprime la columna, 8,7,6,...,1

CONT2:
    cmp si,8
    je FIN2

    cmp buffer[si], 101b
    je FN2
    cmp buffer[si], 100b
    je FB2
    jmp S2

    FN2:
        PrintFichaNegra CONT2
    FB2: 
        PrintFichaBlanca CONT2
    S2:
        PrintSpace CONT2
FIN2:

POP AX
POP SI
xor si,si
endm




printTablero3 macro buffer, row  ; Rcorre el arreglo que viene (buffer) y hace print de las cosas

PUSH SI
PUSH AX

xor si,si
print marc
print row ;imprime la columna, 8,7,6,...,1

CONT3:
    cmp si,8
    je FIN3

    cmp buffer[si], 101b
    je FN3
    cmp buffer[si], 100b
    je FB3
    jmp S3

    FN3:
        PrintFichaNegra CONT3
    FB3: 
        PrintFichaBlanca CONT3
    S3:
        PrintSpace CONT3
FIN3:

POP AX
POP SI
xor si,si
endm


printTablero4 macro buffer, row  ; Rcorre el arreglo que viene (buffer) y hace print de las cosas

PUSH SI
PUSH AX

xor si,si
print marc
print row ;imprime la columna, 8,7,6,...,1

CONT4:
    cmp si,8
    je FIN4

    cmp buffer[si], 101b
    je FN4
    cmp buffer[si], 100b
    je SB4
    jmp S4

    FN4:
        PrintFichaNegra CONT4
    SB4: 
        PrintFichaBlanca CONT4
    S4:
        PrintSpace CONT4
FIN4:

POP AX
POP SI
xor si,si
endm



PrintFichaNegra macro jumper
    print fneg
    inc si
    jmp jumper
endm


PrintFichaBlanca macro jumper
    print fblc
    inc si
    jmp jumper
endm


PrintSpace macro jumper
    print void
    inc si
    jmp jumper
endm





printTablero5 macro buffer, row  ; Rcorre el arreglo que viene (buffer) y hace print de las cosas

PUSH SI
PUSH AX

xor si,si
print marc
print row ;imprime la columna, 8,7,6,...,1

CONT5:
    cmp si,8
    je FIN5

    cmp buffer[si], 101b
    je FN5
    cmp buffer[si], 100b
    je SB5
    jmp S5

    FN5:
        PrintFichaNegra CONT5
    SB5: 
        PrintFichaBlanca CONT5
    S5:
        PrintSpace CONT5
FIN5:

POP AX
POP SI
xor si,si
endm


printTablero6 macro buffer, row  ; Rcorre el arreglo que viene (buffer) y hace print de las cosas

PUSH SI
PUSH AX

xor si,si
print marc
print row ;imprime la columna, 8,7,6,...,1

CONT6:
    cmp si,8
    je FIN6

    cmp buffer[si], 101b
    je FN6
    cmp buffer[si], 100b
    je SB6
    jmp S6

    FN6:
        PrintFichaNegra CONT6
    SB6: 
        PrintFichaBlanca CONT6
    S6:
        PrintSpace CONT6
FIN6:

POP AX
POP SI
xor si,si
endm

printTablero7 macro buffer, row  ; Rcorre el arreglo que viene (buffer) y hace print de las cosas

PUSH SI
PUSH AX

xor si,si
print marc
print row ;imprime la columna, 8,7,6,...,1

CONT7:
    cmp si,8
    je FIN7

    cmp buffer[si], 101b
    je FN7
    cmp buffer[si], 100b
    je SB7
    jmp S7

    FN7:
        PrintFichaNegra CONT7
    SB7: 
        PrintFichaBlanca CONT7
    S7:
        PrintSpace CONT7
FIN7:

POP AX
POP SI
xor si,si
endm

printTablero8 macro buffer, row  ; Rcorre el arreglo que viene (buffer) y hace print de las cosas

PUSH SI
PUSH AX

xor si,si
print marc
print row ;imprime la columna, 8,7,6,...,1

CONT8:
    cmp si,8
    je FIN8

    cmp buffer[si], 101b
    je FN8
    cmp buffer[si], 100b
    je SB8
    jmp S8

    FN8:
        PrintFichaNegra CONT8
    SB8: 
        PrintFichaBlanca CONT8
    S8:
        PrintSpace CONT8
FIN8:
POP AX
POP SI
xor si,si
endm
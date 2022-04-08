----- PORTUGUES --------


O ficheiro 'lab.h' deve ser descomprimido e copiado para a diretoria de trabalho.

Qualquer ficheiro que use esta biblioteca usar:

#include "lab.h"

este ficheiro possui vários métodos

gotoxy(int x, int y) //permite colocar o cursor em qualquer posição x,y  na consola, útil para organizar os menus e o desenho das cartas.

void showRect(int x, int y, int width, int height) //permite desenhar um retângulo na posição desejada

void show90RectAt(int x, int y, int width, int height)   //desenha um retangulo com linhas duplas na posicao X,Y com as dimensoes Width e Height, rodado 90º

void showCharAt(int x, int y, char c)      //mostra um carater na posição designada

void printfAt(int x, int y, char c[])    //escreve uma 'string' na horizontal na posição designada

void showVerticalWordAt(int x, int y, char c[], int charNumber)   //Escreve uma 'string' na vertical na posição designada

void setColor(int foreGround, int backGround)   //altera a cor do texto e do fundo

void setForeColor(int foreGround)             //altera a cor do texto, mantém a cor do fundo

void setBackColor(int backGround)          //altera a cor do fundo, mantém a cor do texto

void resetColor()       //Redefine as cores: branco para o texto e preto para o fundo


------ENGLISH-------

The file lab.h should be decompressed and copied to the working directory.
Any file needing it shoud have:

#include "lab.h"

este ficheiro possui vários métodos

gotoxy(int x, int y) //allows to place the cursor at any given position

void showRect(int x, int y, int width, int height) //allows to draw a rectangle (double lines) at any given position

void show90RectAt(int x, int y, int width, int height)   //allows to draw a rectangle (double lines) at any given position, rotated by 90º

void showCharAt(int x, int y, char c)   //show a char at a designated position

void printfAt(int x, int y, char c[])    //write an horizontal 'string' at a designated position

void showVerticalWordAt(int x, int y, char c[], int charNumber)   //write a 'string' verticaly at a designated position

void setColor(int foreGround, int backGround)   //changes both foreground and background colors

void setForeColor(int foreGround)             //changes foreground color while keeping background color

void setBackColor(int backGround)          //changes background color while keeping foreground color

void resetColor()               //Colors reset: foreground white, background black
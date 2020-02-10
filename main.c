#include<stdio.h>
#include<conio.h>
#include<DOS.H>
#include<STDLIB.h>
#include<windows.h>

#define esc 27  //
#define ret 40//
#define aba_der 0 // Direcciones pelota
#define arr_der 1
#define arr_izq 2
#define aba_izq 3
#define arr 4
#define abaj 5

#define izq 75
#define der 77
#define aba 80

void gotoxy(int,int);

COORD coord={0,0};

int main()
{
    char tecla;
    int xp,yp,dir_p,xj1,yj1,dir_j1,xj2,yj2,dir_j2,pj2=0,pj1=0,i;

    xp=39;
    yp=12;
    dir_p=0;

    xj1=38;
    yj1=22;
    dir_j1=0;

    xj2=38;
    yj2=2;
    dir_j2=0;


    do
    {
        do
        {
            // Mostrar objetos.

            gotoxy(xp,yp); // Pelota
            printf("*");

            gotoxy(xj1,yj1); // Jugador 1
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);

            gotoxy(xj2,yj2); // Jugador 2
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);

            // Direcciones.

            switch(dir_p) // Pelota.
            {
                case aba_der: xp++;yp++; break;
                case arr_der: xp++;yp--; break;
                case arr_izq: xp--;yp--; break;
                case aba_izq: xp--;yp++; break;
                case arr: yp++; break;
                case abaj: yp--; break;
            }

            switch(dir_j1) // Jugador 1.
            {
                case 1: if(xj1<64)xj1++; break;
                case 2: if(xj1>0) xj1--; break;
            }

            switch(dir_j2) // Jugador 2.
            {
                case 1: if(xj2<64)xj2++; break;
                case 2: if(xj2>0) xj2--; break;
            }

            // Limites.

            if(yp==24   &&  dir_p==aba_der)     dir_p=arr_der;// Pelota
            if(yp==24   &&  dir_p==aba_izq)     dir_p=arr_izq;
            if(yp==0    &&  dir_p==arr_der)     dir_p=aba_der;
            if(yp==0    &&  dir_p==arr_izq)     dir_p=aba_izq;
            if(xp==79   &&  dir_p==arr_der)     dir_p=arr_izq;
            if(xp==79   &&  dir_p==aba_der)     dir_p=aba_izq;
            if(xp==0    &&  dir_p==arr_izq)     dir_p=arr_der;
            if(xp==0    &&  dir_p==aba_izq)     dir_p=aba_der;

            // Puntos / vidas

            for(i=0;i<=15;i++)//pelota y j1.
            {
                if(xp==xj1+i && yp==yj1)
                {
                    if(i<=8)dir_p=arr_izq;
                    if(i>=7)dir_p=arr_der;
                }
            }

             for(i=0;i<=15;i++)// pelota y j2.
            {
                if(xp==xj2+i && yp==yj2)
                {
                    if(i<=7)dir_p=aba_izq;
                    if(i>=8)dir_p=aba_der;
                }
            }

            if(yp==24)//gana j2
            {
                gotoxy(30,12);
                pj2++;
                gotoxy(35,12);
                printf("Punto J2");
                Sleep(2000);
                xp=39;
                yp=12;
                dir_p=0;

                xj1=38;
                yj1=22;
                dir_j1=0;

                xj2=38;
                yj2=2;
                dir_j2=0;
            }

            if(yp==0)//gana j1
            {
                gotoxy(30,12);
                pj1++;
                gotoxy(35,12);
                printf("Punto J1");
                Sleep(2000);
                xp=39;
                yp=12;
                dir_p=1;

                xj1=38;
                yj1=22;
                dir_j1=0;

                xj2=38;
                yj2=2;
                dir_j2=0;
            }

            gotoxy(0,24);
            printf("Jugador 1: %d",pj1);
            gotoxy(0,0);
            printf("Jugador 2: %d",pj2);

            Sleep(ret); // Retardo.
            system("CLS"); // Borra pantalla.
        } while (kbhit ()==0);

        tecla=getch();

        if(tecla==-32)//teclas j1.
        {
            tecla=getch();

            switch(tecla)
            {
                case izq: dir_j1=2; break;
                case der: dir_j1=1; break;
                case aba: dir_j1=0; break;
            }
        }
        else
            {
            switch(tecla)
                {
                    case 'a': dir_j2=2;break;
                    case 'd':dir_j2=1;break;
                    case 's':dir_j2=0;break;
                }
            }



    }while (tecla!=esc);

    salir:

    return 0;
}

void gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }



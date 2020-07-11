#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Pantalla.h"
#include "Personaje.h"
#include "Galaxia.h"
#include "Ejercito.h"
/**
*   @mainpage Se trata de un juego 2D en el que hay que esquivar enemigos y recoger Estrellas para ganar.
*   Se tiene un límite de vidas definido
*/

int main(int argc, char ** argv)
{
    //Creación de la pantalla
    Pantalla_Crea("Alien Invasion", 800, 600);
    Imagen fondo1 = Pantalla_ImagenLee("Inicio.bmp",255); // Fondo pantalla Principal / Menú
    Imagen fondo2 = Pantalla_ImagenLee("N1.bmp",50);      // Fondo Nivel 1
    Imagen fondo3 = Pantalla_ImagenLee("N2.bmp",50);      // Fondo Nivel 2
    Imagen fondo4 = Pantalla_ImagenLee("Gameover.bmp",0); // Fondo pantalla Game Over

    int terminar1 = 0; // Pantalla inicio
    int terminar2 = 0; // Nivel 1
    int terminar3 = 0; // Nivel 2
    int terminar4 = 0; // pantalla Game Over

    int vidas = 4;      // variable de las vidas

    Imagen personajeImagen = Pantalla_ImagenLee("nave.bmp",255);
    Imagen enemigoImagen = Pantalla_ImagenLee("Enemigo.bmp",255);
    Imagen estrellaImagen = Pantalla_ImagenLee("estrella.bmp",255);


    Personaje personaje = PersonajeCrea(personajeImagen,rand()%(Pantalla_Anchura()-50),Pantalla_Altura()-50,50,50);   //Creación de la nave roja (personaje)
    Galaxia galaxia = GalaxiaCrea(10);                              // Creación de la galaxia con la que se consigue puntos
    Ejercito ejercito1 = EjercitoCrea(50);                          // Creación del ejercito de enemigos

    while (Pantalla_Activa()&&!terminar1)                           // Bucle de la pantalla de inicio
    {
         if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN))            // Paso al primer nivel cuando se pulsa ENTER
        {
            terminar1 = 1;
        }

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE))             // Salida total del juego al presionar ESC
        {
            terminar1 = 1; terminar2 = 1; terminar3 = 1; terminar4 = 1;
        }

        Pantalla_DibujaImagen(fondo1,0,0,Pantalla_Anchura(),Pantalla_Altura());

        Pantalla_ColorTrazo (255,255,255,255);                      // Primero hay que poner el Trazo y después el texto
        Pantalla_DibujaTexto ("BIENVENIDO A SPACE INVADERS",280, 10);

        Pantalla_ColorTrazo (255,255,0,255);
        Pantalla_DibujaTexto ("COGE LAS ESTRELLAS PARA PASAR AL SIGUIENTE NIVEL, PERO CUIDADO",130, 60);

        Pantalla_ColorTrazo (255,255,0,255);
        Pantalla_DibujaTexto ("PORQUE HAY NAVES ENEMIGAS QUE TE LO PONDRAN MAS DIFICIL.",170, 90);

        Pantalla_ColorTrazo (255,255,0,255);
        Pantalla_DibujaTexto ("TIENES 4 VIDAS PARA INTENTARLO",280,120);

        Pantalla_ColorTrazo (255,255,0,255);
        Pantalla_DibujaTexto("PRESIONA [ENTER] PARA EMPEZAR Y [ESC] PARA SALIR",180, 300);


        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    int record = 0;                                                 // Variable que guarda el record de tiempo
    int puntos = 0;                                                 // Variable que acumula los puntos cogidos
    int record_p = 0;                                               // Variable que guarda el record de puntos

    int tiempo = time (NULL);
    int tiempo_f = time (NULL);
    int tiempo_t = tiempo_f - tiempo;

    char texto [100];
    char texto1 [100];
    char texto2 [100];
    char texto3 [100];
    char texto4 [100];
    char texto5 [100];
    char texto6 [100];
    char texto7 [100];


    while (Pantalla_Activa() && !terminar2 && (vidas > 0))          // Bucle del primer nivel
    {

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE))             // Salida total del juego sin pasar por la pantalla Game Over
        {
            terminar2 = 1; terminar3 = 1;
        }

        PersonajeMueve(personaje,30,30);                            // Movimientos de la nave roja
        EjercitoMueve(ejercito1);                                   // Movimiento del ejército

        if (rand()%10==0)                                           // Inserta la galaxia de forma aleatoria en la pantalla
        {
            GalaxiaInserta(galaxia,estrellaImagen,rand()%(Pantalla_Anchura()-40),rand()%(Pantalla_Altura()-40),50,50);
        }

        if (rand()%25==0)                                           // Inserta el ejercito de forma aleatoria en la pantalla
        {
            EjercitoInserta(ejercito1,enemigoImagen,rand()%(Pantalla_Anchura()-40),rand()%(Pantalla_Altura()-40),80,80,25,25);
        }

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE))              // Paso a la pantalla Game Over
        {
            terminar2 = 1; terminar3 = 1;
        }

        vidas -= EjercitoColision(ejercito1,personaje);             // Se restan vidas cada vez que se choca contra una nave enemiga
        puntos += GalaxiaColision(galaxia,personaje);               // Se suma un punto cada vez que se coge una estrella


        if (puntos == 7)                                            // Si se recogen 7 puntos, se pasa al siguiente nivel
        {

            terminar2 = 1;

        }
        if (vidas == 0)                                             // Si se baja las vidas a 0, se pasa a la pantalla Game Over
        {
            terminar2 = 1; terminar3 = 1;
        }

        tiempo_t = time (NULL);
        tiempo_f = tiempo_t - tiempo;
        sprintf(texto,"Tiempo = %d",tiempo_f);
        sprintf(texto1,"Puntos = %d",puntos);
        sprintf(texto2,"Vidas = %d",vidas);

        //Escritura de las palabras para salir
        Pantalla_DibujaImagen(fondo2,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo (255,255,255,255);
        Pantalla_DibujaTexto ("Pulsa [ESC] para salir",5, 5);
        Pantalla_DibujaTexto ("Pulsa [SPACE] para terminar", 5, 585);
        Pantalla_DibujaTexto ("NIVEL 1",600,5);
        Pantalla_DibujaTexto(texto,5,35);
        Pantalla_DibujaTexto(texto1,5,50);
        Pantalla_DibujaTexto (texto2, 5,65);

        GalaxiaDibuja(galaxia);                                    // Dibuja las estrellas de la galaxia
        EjercitoDibuja(ejercito1);                                 // Dibuja a los enemigos del ejercito
        PersonajeDibuja(personaje);                                //Dibuja la nave roja en la pantalla

        Pantalla_Actualiza();
        Pantalla_Espera(40);

    }

    while (Pantalla_Activa()&&!terminar3 && (vidas > 0))        // Bucle del segundo nivel
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE))         //Salida total del juego
        {
            terminar3 = 1;
        }

        PersonajeMueve(personaje,45,45);                        // Movimiento del personaje con una velocidad diferente a la de primer nivel
        EjercitoMueve(ejercito1);                               // Movimiento del personaje con la misma velocidad que en el primer nivel

        if (rand()%15==0)                                       // Inserta la galaxia de forma aleatoria en la pantalla
        {

            GalaxiaInserta(galaxia,estrellaImagen,rand()%(Pantalla_Anchura()-40),rand()%(Pantalla_Altura()-40),50,50);
        }

        if (rand()%25==0)                                       // Inserta el ejército de forma aleatoria en la pantalla
        {

            EjercitoInserta(ejercito1, enemigoImagen, rand()%(Pantalla_Anchura()-40),rand()%(Pantalla_Altura()-40),80,80,25,25);
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE))
        {
            terminar3 = 1;
        }

        if (puntos == 20 || vidas == 0)
        {
            terminar3 = 1;
        }

        vidas -= EjercitoColision(ejercito1, personaje);        // Se restan vidas cada vez que el personaje choca contra alguna nave enemiga del ejército
        puntos += GalaxiaColision(galaxia, personaje);          // Se suma un punto cada vez que el personaje recoge una estrella de la galaxia


        tiempo_t = time (NULL);
        tiempo_f = tiempo_t - tiempo;
        sprintf(texto4,"Tiempo = %d",tiempo_f);
        sprintf(texto5,"Puntos = %d",puntos);
        sprintf(texto6,"Vidas = %d",vidas);

        //Escritura de las palabras para salir
        Pantalla_DibujaImagen(fondo3,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo (255,255,255,255);
        Pantalla_DibujaTexto ("Pulsa [ESC] para salir",5, 5);
        Pantalla_DibujaTexto ("Pulsa [SPACE] para terminar", 5, 585);
        Pantalla_DibujaTexto ("NIVEL 2",600,5);
        Pantalla_DibujaTexto(texto4,5,35);
        Pantalla_DibujaTexto(texto5,5,50);
        Pantalla_DibujaTexto(texto6,5,65);

        GalaxiaDibuja(galaxia);                                 // Dibuja la galaxia en pantalla
        EjercitoDibuja(ejercito1);                              // Dibuja el ejército en pantalla
        PersonajeDibuja(personaje);                             // Dibuja al personaje en pantalla

        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    sprintf(texto,"Tu tiempo fue: %d",tiempo_f);
    FILE * f = fopen("resultado_tiempo.txt","r");               //Abre el fichero con los resultados de los tiempos y los lee ("r") y guarda los datos en &record
    fscanf(f,"%d",&record);
    fclose(f);
    if (record < tiempo_f)                                      // Si el tiempo obtenido en esta partida es mayor que el último tiempo guardado en el fichero, se soobreescribe ya que es el nuevo record de tiempo
    {
        FILE * f = fopen("resultado_tiempo.txt","w");           // Se escribe en los ficheros con ("w")
        record = tiempo_f;
        fprintf(f,"%d",record);
        fclose(f);
    }

    sprintf(texto7, "Tus puntos fueron: %d", puntos);
    FILE * p = fopen("resultados_puntos.txt","r");              // Abre el fichero con los resultados de puntuación y los lee ("r") y guarda los datos en &puntos
    fscanf(p, "%d", &record_p);
    fclose(p);
    if (record_p < puntos)                                      // Si la puntuación obtenida en esta partida es mayor que la última guardada en el fichero, se soobreescribe ya que es el nuevo record de puntuación
    {
        FILE * p = fopen("resultados_puntos.txt","w");          // Se escribe en los ficheros con ("w")
        record_p = puntos;
        fprintf(p,"%d",record_p);
        fclose(p);
    }

    PersonajeLibera(personaje);
    EjercitoLibera(ejercito1);
    GalaxiaLibera(galaxia);


   while (Pantalla_Activa()&&!terminar4)                        // Bucle de pantalla Game Over
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN))         // Sale de la pantalla, y a su vez, del juego presionando la tecla Enter
        {
            terminar4 = 1;
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_PERIOD))         // Abre los ficheros que contienen los records de puntos y de tiempo y los pone a 0 cuando se presiona la tecla [.]
        {
            FILE * a = fopen("resultado_tiempo.txt","w");
            record = 0;
            fprintf(a,"%d",record);
            fclose(a);

            FILE * p = fopen("resultados_puntos.txt","w");
            record_p = 0;
            fprintf(p,"%d",record_p);
            fclose(p);

        }

        Pantalla_DibujaImagen(fondo4,0,0, Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(255,255,255,250);
        Pantalla_DibujaTexto("Pulse [ENTER] para salir",5,580);
        Pantalla_DibujaTexto("Pulse [.] para borrar historial de puntuacion",390,580);
        Pantalla_DibujaTexto(texto,5,5);

        sprintf(texto2,"El record de tiempo es: %d",record);
        sprintf(texto3,"El record de puntos es: %d",record_p);
        sprintf(texto4,"Tus puntos fueron: %d",puntos);
        Pantalla_DibujaTexto(texto2,560,5);
        Pantalla_DibujaTexto(texto3,560, 20);
        Pantalla_DibujaTexto(texto4,5,20);

        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    Pantalla_ImagenLibera(personajeImagen);
    Pantalla_ImagenLibera(enemigoImagen);
    Pantalla_ImagenLibera(estrellaImagen);

    Pantalla_ImagenLibera(fondo1);
    Pantalla_ImagenLibera(fondo2);
    Pantalla_ImagenLibera(fondo3);
    Pantalla_ImagenLibera(fondo4);
    Pantalla_Libera();
    return 0;
}

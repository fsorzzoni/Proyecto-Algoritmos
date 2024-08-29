#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

// aplica a las dos primeras funciones
// Se debe anteponer esta linea al inicio de la funcion.
// De otro modo, apareceran errores al momento de actualizar
// archivos. Esto se debe a un error en la implementacion de Windows.
//
// fseek(f,0,SEEK_CUR);

// 1.4.1.1
template<typename T> void write(FILE* f, T t)
{
   fseek(f,0,SEEK_CUR);
   fwrite(&t,sizeof(T),1,f);
}

// 1.4.1.2
template<typename T> T read(FILE* f)
{
   fseek(f,0,SEEK_CUR);
   T t;
   fread(&t,sizeof(T),1,f);
   return t;
}

// 1.4.1.3
template<typename T> void seek(FILE* f, int n)
{
   int posByte = n * sizeof(T);
   fseek(f,posByte,SEEK_SET);
}

// 1.4.1.4
template<typename T> int fileSize(FILE* f)
{
   int posActByte = ftell(f);

   fseek(f,0,SEEK_END);

   int fin = ftell(f) / sizeof(T);
   fseek(f,posActByte,SEEK_SET);

   return fin;
}

// 1.4.1.5
template<typename T> int filePos(FILE* f)
{
   // el tamano de T siempre va a ser divisor de la posicion del byte
   return ftell(f) / sizeof(T);
}

#endif

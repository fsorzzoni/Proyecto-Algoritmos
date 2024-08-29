#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../../funciones/strings.hpp"

using namespace std;

// 1.3.2.1. Estructura del TAD
// Aclaracion general: el template T en la estructura Coll esta para que cuando se usen para programar estas funciones, se
// aclare el tipo de dato que se almacena en Coll, sin embargo, T no se usa en la estructura, por lo que nada mas tiene propositos esteticos.
template<typename T>
struct Coll
{
   char sep;
   string tokenColl;
   int iteraciones;
};

// 1.3.2.2
template<typename T>
Coll<T> coll(char sep)
{
   return {sep,""};
}

// 1.3.2.3
// el separador por defecto es |
template<typename T>
Coll<T> coll()
{
   return {'|',""};
}

// 1.3.2.4
template<typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.tokenColl,c.sep);
}

// 1.3.2.5
template<typename T>
void collRemoveAll(Coll<T>& c)
{
   int size = collSize<T>(c);
   for(int i = 0 ; i < size ; i++)
   {
      removeTokenAt(c.tokenColl,c.sep,0);
   }
}

// 1.3.2.6
template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.tokenColl,c.sep,p);
}

// 1.3.2.7
template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   string add = tToString(t);
   addToken(c.tokenColl,c.sep,add);
   return collSize<T>(c) - 1;
}

// 1.3.2.8
template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   setTokenAt(c.tokenColl,c.sep,tToString(t),p);
}

// 1.3.2.9
template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   string s = getTokenAt(c.tokenColl,c.sep,p);
   return tFromString(s);
}

// 1.3.2.10
// la funcion cmpTK determina como se comparan T y K, que pueden ser o no el mismo tipo de dato
template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   int ret = -1;
   if(collSize<T>(c) == 0)
   {
   }
   else
   {
      // ini es el elemento de la Coll que agarro para comparar con K
      T ini = collGetAt<T>(c,0,tFromString);
      int i = 0;
      while((cmpTK(ini,k) != 0) && (i < collSize<T>(c)))
      {
       i++;
         if(i < collSize<T>(c))
         {
         ini = collGetAt<T>(c,i,tFromString);
         }
      }

   
      if((cmpTK(ini,k) == 0))
      {
         ret = i;
      }
   }
   return ret;
}

// 1.3.2.11
// si es de menor a mayor, t1<t2 = -
template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   // va borrando cada elemento de la cadena mientras se va encontrando
   Coll<T> aux = c;
   // se borran asi se puede volver a formar la cadena
   collRemoveAll<T>(c);

   // ini es el numero elegido para compararlo con los otros elementos
   int ini = 0;
   while(collSize<T>(aux) != 0)
   {
      int totalVecesMenorOIgual = 0;
      for(int i = 0 ; i < collSize<T>(aux) ; i++)
      {
         if(cmpTT(collGetAt<T>(aux,ini,tFromString),collGetAt<T>(aux,i,tFromString)) <= 0)
         {
            totalVecesMenorOIgual++;
         }
      }
      // si es el menor se agrega a C y se elimina de aux
      if(totalVecesMenorOIgual == collSize<T>(aux))
      {
      
         collAdd<T>(c,collGetAt<T>(aux,ini,tFromString),tToString);
         collRemoveAt<T>(aux,ini);
         ini = 0;
      }
      // si no va sumando hasta encontrar el menor
      else
      {
         ini++;
      }
   }
}

// 1.3.2.12
// el usuario establece cuantas iteraciones hay
template<typename T>
bool collHasNext(Coll<T> c)
{
   // como retorna un bool, puedo ponerlo directamente en el return sin crear un bool
   return c.iteraciones < collSize<T>(c);
}

// 1.3.2.13
// puede fallar si no hay mas elementos en la colleccion
template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t = collGetAt<T>(c,c.iteraciones,tFromString);
   // suma una iteracion
   c.iteraciones++;
   return t;
}

// 1.3.2.14
template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t;
   if(collHasNext<T>(c))
   {
      t = collNext<T>(c,tFromString);
      endOfColl = false;
   }
   else
   {
      endOfColl = true;
      t = tFromString("");
   }
   return t;
}

// 1.3.2.15
template<typename T>
void collReset(Coll<T>& c)
{
   c.iteraciones = 0;
}

// Algoritmos Tools
template<typename T>
string collToString(Coll<T> c)
{
	return c.sep+c.tokenColl;
}

template<typename T>
Coll<T> collFromString(string s)
{
	Coll<T> c;
	c.sep=s[0];
	c.tokenColl=substring(s,1);
	return c;
}



#endif

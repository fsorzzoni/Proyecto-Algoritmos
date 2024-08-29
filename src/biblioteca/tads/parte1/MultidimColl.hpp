#ifndef _TMTX_T_
#define _TMTX_T_

#include <iostream>
#include "Coll.hpp"

using namespace std;

template<typename T>
struct Mtx
{
   int f;
   int c;
   Coll<T> tC;
};

template <typename T>
Mtx<T> mtx(int f,int c,T valorDefault,string tToString(T))
{
   Mtx<T> m;
   int cant = f*c;
   for(int i = 0 ; i < cant ; i++)
   {
      collAdd<T>(m.tC,valorDefault,tToString);
   }
   m.f = f;
   m.c = c;
   return m;
}

template <typename T>
T mtxGetAt(Mtx<T> m,int f,int c,T tFromString(string))
{
   f--;
   c--;
   int pos = (f * m.c) + c;

   T t = collGetAt<T>(m.tC,pos,tFromString);

   return t;
}

template <typename T>
void mtxSetAt(Mtx<T>& m,T t,int f,int c,string tToString(T))
{
   f--;
   c--;
   int pos = (f * m.c) + c;

   collSetAt<T>(m.tC,t,pos,tToString);
}

// ------------------------

template<typename T>
struct Cube
{
   int f;
   int c;
   int p;
   Coll<T> tC;
};

template <typename T>
Cube<T> cube(int f,int c,int p,T valorDefault,string tToString(T))
{
   Cube<T> cu;
   int cant = f * c * p;
   for(int i = 0 ; i < cant ; i++)
   {
      collAdd<T>(cu.tC,valorDefault,tToString);
   }
   cu.f = f;
   cu.c = c;
   cu.p = p;
   return cu;
}

template <typename T>
T cubeGetAt(Cube<T> cu,int f,int c,int p,T tFromString(string))
{
   p--;
   f--;
   c--;
   int cantMtx = cu.f * cu.c;
   int pos = (p * cantMtx) + (f * cu.c) + c;

   T t = collGetAt<T>(cu.tC,pos,tFromString);

   return t;
}

template <typename T>
void cubeSetAt(Cube<T>& cu,T t,int f,int c,int p,string tToString(T))
{
   p--;
   f--;
   c--;
   int cantMtx = cu.f * cu.c;
   int pos = (p * cantMtx) + (f * cu.c) + c;

   collSetAt<T>(cu.tC,t,pos,tToString);
}

#endif

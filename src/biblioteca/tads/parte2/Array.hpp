#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
   T* arr;
   int len;
   int cap;
};

template<typename T>
Array<T> arrayIni()
{
   Array<T> ret;
   T* arr = new T[100];
   ret.arr = arr;
   ret.len = 0;
   ret.cap = 100;
   return ret;
}

template<typename T>
int arrayAdd(Array<T>& a,T t)
{
   if(a.cap == a.len)
   {
      T* b = new T[a.cap * 2];
      for(int i = 0; i < a.len ; i++)
      {
         b[i] = a.arr[i];
      }

      delete a.arr;
      a.arr = b;
      a.cap = a.cap * 2;
   }
   int pos = add<T>(a.arr,a.len,t);

   return pos;
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   T* t = &a.arr[p];
   return t;
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   a.arr[p] = t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   if(a.cap == a.len)
   {
      T* b = new T[a.cap * 2];
      for(int i = 0; i < a.len; i++)
      {
         b[i] = a.arr[i];
      }

      delete a.arr;
      a.arr = b;
      a.cap = a.cap * 2;
   }
   insert<T>(a.arr,a.len,t,p);
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   T t = remove<T>(a.arr,a.len,p);
   return t;
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   while(arraySize<T>(a) > 0)
   {
      remove<T>(a.arr,a.len,0);
   }
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   int pos = find<T,K>(a.arr,a.len,k,cmpTK);
   return pos;
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   if(a.cap == a.len)
   {
      T* b = new T[a.cap * 2];
      for(int i = 0; i < a.len; i++)
      {
         b[i] = a.arr[i];
      }

      delete a.arr;
      a.arr = b;
      a.cap = a.cap * 2;
   }
   int pos = orderedInsert<T>(a.arr,a.len,t,cmpTT);
   return pos;
}

template<typename T>
T* arrayDiscover(Array<T>& a,T t,int cmpTT(T,T))
{

   int pos = arrayFind<T,T>(a,t,cmpTT);
   T* ret;
   if(pos < 0)
   {
      if(a.cap == a.len)
      {
         T* b = new T[a.cap * 2];
         for(int i = 0; i < a.len; i++)
         {
            b[i] = a.arr[i];
         }

         delete a.arr;
         a.arr = b;
         a.cap = a.cap * 2;
      }
      pos = arrayAdd<T>(a,t);
      ret = arrayGet<T>(a,pos);
   }
   else
   {
      ret = arrayGet<T>(a,pos);
   }
   return ret;
}


template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.arr,a.len,cmpTT);
}

#endif

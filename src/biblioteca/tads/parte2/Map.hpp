
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K,typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int iteraciones;
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.keys = arrayIni<K>();
   m.values = arrayIni<V>();
   m.iteraciones = 0;
   return m;
}

template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
   int i = 0;
   bool encontrado = false;
   while(i < arraySize<K>(m.keys) && !encontrado)
   {
      K* t = arrayGet<K>(m.keys,i);
      if(k == *t)
      {
         encontrado = true;
      }
      else
      {
         i++;
      }
   }

   V* v;
   if(encontrado)
   {
      v = arrayGet<V>(m.values,i);
   }
   else
   {
      v = NULL;
   }
   
   return v;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   int i = 0;
   bool encontrado = false;
   while(i < arraySize<K>(m.keys) && !encontrado)
   {
      K* t = arrayGet<K>(m.keys,i);
      if(k == *t)
      {
         encontrado = true;
      }
      else
      {
         i++;
      }
   }

   V* ret;
   if(encontrado)
   {
      ret = arrayGet<V>(m.values,i);
      *ret = v;
   }
   else
   {
      arrayAdd<K>(m.keys,k);
      int pos = arrayAdd<V>(m.values,v);
      ret = arrayGet<V>(m.values,pos);
   }
   return ret;
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{
   bool encontrado = false;
   for(int i = 0; i < arraySize<K>(m.keys) && !encontrado ; i++)
   {
      K* t = arrayGet<K>(m.keys,i);
      if(k == *t)
      {
         encontrado = true;
      }
   }
   return encontrado;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   int i = 0;
   bool encontrado = false;
   while(i < arraySize<K>(m.keys) && !encontrado)
   {
      if(k == m.keys[i])
      {
         encontrado = true;
      }
      else
      {
         i++;
      }
   }
   V v = arrayRemove<V>(m.values,i);
   return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.values);
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return arraySize<K>(m.keys);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{
   bool hasNext = m.iteraciones < arraySize<K>(m.keys);
   return hasNext;
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
   K* k = arrayGet<K>(m.keys,m.iteraciones);
   m.iteraciones++;
   return *k;
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   V* v = arrayGet<V>(m.values,m.iteraciones);
   m.iteraciones++;
   return v;
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
   m.iteraciones = 0;
}

template<typename K,typename V>
V* mapDiscover(Map<K,V>& m,K k,V v)
{
   V* ret;
   if(mapContains<K,V>(m,k))
   {
      ret = mapGet<K,V>(m,k);
   }
   else
   {
      ret = mapPut<K,V>(m,k,v);
   }
   return ret;
}


template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
   arraySort<K>(m.keys,cmpKK);
}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{
   arraySort<V>(m.values,cmpVV);
}

#endif

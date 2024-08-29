#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len] = e;
   len++;
   return len - 1;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   for(int i = len ; i > p ; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[p] = e;
   len++;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret = arr[p];
   len--;
   for(int i = p ;  i < len ; i++)
   {
      arr[i] = arr[i + 1];
   }
   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   int i = 0;
   while(cmpTK(arr[i],k) != 0 && i < len)
   {
      i++;
   }
   if(i == len)
   {
      i = -1;
   }
   
   return i;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int i = 0;
   while(cmpTT(arr[i],e) < 0 && i < len)
   {
      i++;
   }
   if(i == len)
   {
      i = add<T>(arr,len,e);
   }
   else
   {
      insert<T>(arr,len,e,i);
   }
   return i;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   T arrAux[len];
   int lenAux = 0;
   for(int i = 0 ; i < len ; i++)
   {
      orderedInsert<T>(arrAux,lenAux,arr[i],cmpTT);
   }
   for(int i = 0 ; i < len ; i++)
   {
      arr[i] = arrAux[i];
   }
}

#endif

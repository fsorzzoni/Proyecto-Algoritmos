#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// 1.2.1.1
int tokenCount(string s,char sep)
{
	int cantidadToken;
	if(s[0] == '\0')
	{
		cantidadToken = 0;
	}
	else
	{
		cantidadToken = charCount(s,sep) + 1;
	}
	return cantidadToken;
}

// 1.2.1.2
void addToken(string& s,char sep,string t)
{
	bool vacio = isEmpty(s);
	if(vacio)
	{
		s = s + t;
	}
	else
	{
		s = s + sep + t;
	}
}

// 1.2.1.3
// errores: si i es negativo
string getTokenAt(string s,char sep, int i)
{
	int cantidadToken = tokenCount(s,sep);
	string token;

	// caso si se quiere el token 0
	if(i == 0)
	{
		int posPrimerSep = indexOf(s,sep);
		// si hay un solo token no va a detectar sep nunca
		if(posPrimerSep < 0)
		{
			token = s;
		}
		else
		{
			token = substring(s,0,posPrimerSep);
		}
	}
	else
	{
		// caso si se quiere al ultimo token
		if(i == cantidadToken - 1)
		{
			// le sumo uno a posUltimoSep porque la funcion substring incluye este caracter, y no queremos que incluya sep
			int posUltimoSep = lastIndexOf(s,sep) + 1;
			int posFin = indexOf(s,'\0');
			token = substring(s,posUltimoSep,posFin);
		}

		// caso si se quiere cualquier token del medio
		else
		{
			// le tengo que sumar 1 a posIniSep porque la funcion substring incluye este caracter, y no queremos que incluya el caracter sep
			int posIniSep = indexOfN(s,sep,i) + 1;
			// le sumo uno a i porque quiero entre la pos i e i + 1
			int posFinSep = indexOfN(s,sep,i + 1);

			token = substring(s,posIniSep,posFinSep);
		}
	}
	return token;
}

// 1.2.1.4
// errores: si i es negativo
void removeTokenAt(string& s,char sep, int i)
{
	int cantidadToken = tokenCount(s,sep);
	string token = "";

	// j lleva el recuento de por que numero de token va el for
	for(int j = 0 ; j != cantidadToken ; j++)
	{
		// necesito un auxiliar porque no puedo ni modificar s ni token
		string auxToken = "";

		// lo agrega si es distinta a la pos i
		if(j != i)
		{
			auxToken = getTokenAt(s,sep,j);

			addToken(token,sep,auxToken);
		}
	}
	s = token;
}

// 1.2.1.5
// errores: si i es negativo
void setTokenAt(string& s,char sep, string t,int i)
{
	int cantidadToken = tokenCount(s,sep);
		string token = "";

		// j lleva el recuento de por que numero de token va el for
		for(int j = 0 ; j != cantidadToken ; j++)
		{
			// necesito un auxiliar porque no puedo ni modificar s ni token
			string auxToken = "";

			// si es distinto agrega los mismos tokens
			if(j != i)
			{
				auxToken = getTokenAt(s,sep,j);

				addToken(token,sep,auxToken);
			}
			// si es igual agrega el string t
			else
			{
				addToken(token,sep,t);
			}
		}
		s = token;
}

// 1.2.1.6
int findToken(string s,char sep, string t)
{
	int cantidadToken = tokenCount(s,sep);
	// le asigno - 1 asi si no encuentra la palabra ya devuelve - 1
	int pos = -1;

	for(int j = 0 ; j < cantidadToken ; j++)
	{
		string aux = getTokenAt(s,sep,j);

		// si es igual le asigna j a pos y hace que j sea mayor a cantidadToken para que deje de iterar el for
		if(aux == t)
		{
			pos = j;
			j = cantidadToken + 1;
		}
	}
	return pos;
}

#endif

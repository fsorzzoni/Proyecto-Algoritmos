#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// 1.1.1.1
// i cuenta las letras que hay hasta llegar a '\0'.
int length(string s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return i;
}

// 1.1.1.2
// i va letra por letra y reconoce cuando se llega a '\0'. n cuenta cuantas veces aparece c.
int charCount(string s,char c)
{
	int i = 0;
	int n = 0;
	while(s[i] != '\0')
	{
		if(s[i] == c)
		{
			n++;
		}
		i++;
	}
	return n;
}

// 1.1.1.3
// x es el string que se va modificando segun corre la funcion.
// errores: si el usuario da posiciones (d o h) negativas
string substring(string s,int d,int h)
{
	string x = "";
	while((d < h) && (s[d] != '\0'))
	{
		x = x + s[d];
		d++;
	}
	return x;
}

// 1.1.1.4
// substring sobrecarga
// errores: si el usuario da posicion (d) negativa
string substring(string s,int d)
{
	string x = "";
	while(s[d] != '\0')
	{
		x = x + s[d];
		d++;
	}
	return x;
}

// 1.1.1.5
// i cuenta hasta llegar a c o a '\0'
int indexOf(string s,char c)
{
	int i = 0;
	while((s[i] != c) && (s[i] != '\0'))
	{
		i++;
	}
	if((s[i] == '\0') && (c != '\0'))
	{
		i = -1;
	}
	return i;
}

// 1.1.1.6
// indexOf sobrecarga 1
// errores: si se asigna un negativo a offSet. si no esta c devuelve -1
int indexOf(string s,char c,int offSet)
{
	while((s[offSet] != c) && (s[offSet] != '\0'))
	{
		offSet++;
	}
	if((s[offSet] == '\0') && (c != '\0'))
	{
		offSet = -1;
	}

	return offSet;
}

// 1.1.1.7
// indexOf sobrecarga 2
// i cuenta s, t cuenta toSearch, r es el valor a retornar
int indexOf(string s,string toSearch)
{
	int i=0;
	int t=0;
	// Se asigna -2 a r porque el programa nunca va a devolver ese valor, entonces mientras no se el asigne un valor a r, el programa seguira corriendo
	int r=-2;
	while(r == -2)
	{
	while((s[i] != toSearch[t]) && (s[i] != '\0'))
	{
		i++;
	}
	if((s[i] == '\0'))
	{
		r = -1;
	}
	else
	{
		while((s[i] == toSearch[t]) && (s[i] != '\0'))
		{
			i++;
			t++;
		}
		// hay que averiguar cuantas letras tiene toSearch
		if(length(toSearch) == t)
		{
			r = i - t;
		}
	}
	}
	return r;
}

// 1.1.1.8
// indexOf sobrecarga 3
// offset es el nuevo valor inicial, t cuenta toSearch, r es el valor a retornar
// errores: si se le da un negativo a offset
int indexOf(string s,string toSearch,int offset)
{
	int t=0;
	// Se asigna -2 a r porque el programa nunca va a devolver ese valor, entonces mientras no se el asigne un valor a r, el programa seguira corriendo
	int r=-2;
	while(r == -2)
	{
	while((s[offset] != toSearch[t]) && (s[offset] != '\0'))
	{
		offset++;
	}
	if(s[offset] == '\0')
	{
		r = -1;
	}
	else
	{
		while((s[offset] == toSearch[t]) && (s[offset] != '\0'))
		{
			offset++;
			t++;
		}
		// hay que averiguar cuantas letras tiene toSearch
		if(length(toSearch) == t)
		{
			r = offset - t;
		}
	}
	}
	return r;
}

// 1.1.1.9
// i cuenta s
int lastIndexOf(string s,char c)
{
	// hay que averiguar la longitud de s
	int i = length(s);
	while((s[i] != c) && (i > -1))
	{
		i--;
	}
	return i;
}

// 1.1.1.10
// r cuenta las veces que aparece c hasta que sea igual a n. i es el valor a retornar, que lleva cuenta de la posicion de la cadena.
// errores: si n es negativo devuelve -1
int indexOfN(string s,char c,int n)
{
	int i = -1;
	int r = 0;
	if(n > charCount(s,c))
	{
		i = length(s);
	}
	else
	{
		// devuelve -1 si es 0 o menor a 0
		while(r < n)
		{
			i++;
			while(s[i] != c)
			{
				i++;
			}
			if(s[i] == c)
			{
				r++;
			}
		}
	}

	return i;
}

// 1.1.1.11
// r es el valor a retornar
// errores: si c no es ni un numero ni una letra
int charToInt(char c)
{
	int r;
	// 0 al 9, 0 = 0, 9 = 9
	if((c >= 48) && (c <= 57))
	{
		r = int(c) - 48;
	}
	else
	{
		// A a la Z, A = 10, Z = 35
		if((c >= 65) && (c <= 90))
		{
			r = int(c) - 55;
		}
		else
		{
			// a a la z, a = 10, z = 35
			if((c >= 97) && (c <= 122))
			{
				r = int(c) - 87;
			}
		}
	}

	return r;
}

// 1.1.1.12
// r es el valor a retornar
// errores: si i no es un numero entre 0 y 35
char intToChar(int i)
{
	char r;
	// 0 al 9, 0 = 0, 9 = 9
	if((i >= 0) && (i <= 9))
	{
		r = i + 48;
	}
	else
	{
		// A a la Z, A = 10, Z = 35
		if((i >= 10) && (i <= 35))
		{
			r = i + 55;
		}
	}

	return r;
}

// 1.1.1.13
// s cuenta hasta llegar a i, d es el numero que divide a n para sacarle digitos
// errores: si i es negativo
int getDigit(int n,int i)
{
	int s = 0;
	int d = 1;
	// calcula cuantos digitos hay que sacarle
	while(s != i)
	{
		s++;
		d = d * 10;

	}
	if(i != 0)
	{
	// le saca la cantidad i de digitos
	n = n / d;
	}
	// calcula el valor del ultimo diigto de la cifra restante
	n = n % 10;
	return abs(n);
}

// 1.1.1.14
// d lleva el recuento de los digitos
int digitCount(int n)
{
	int d = 0;
	while(n != 0)
	{
		d++;
		n = n / 10;
	}
	return d;
}

// 1.1.1.15
string intToString(int i)
{
	string s;
	if(i == 0)
	{
		s = "0";
	}
	else
	{
	s = "";
	bool esNegativo;
	{
		if(i < 0)
		{
			esNegativo = true;
		}
		else
		{
			esNegativo = false;
		}
	}
	i = abs(i);
	while(i != 0)
	{
		s = intToChar(i%10) + s;
		i = i / 10;
	}

	if(esNegativo)
	{
		s = "-" + s;
	}
	}
	return s;
}

// 1.1.1.16
int stringToInt(string s,int b)
{
	// suma de todos los numeros
	int total = 0;
	// numero multiplicado por la base exponencial
	int multi;
	// recuento de la cadena
	int i;
	// recuento de potencia
	int j;
	// caracter convertido a int
	int numero;
	// base multiplicada exponencialmente
	int potencia = 1;


		bool esNegativo;
		{
			if(s[0] == '-')
			{
				esNegativo = true;
			}
			else
			{
				esNegativo = false;
			}
		}

		int l = length(s);
		if(esNegativo)
		{
			i = 1;
			l--;
			while(s[i] != '\0')
			{
				potencia = 1;
				j = 0;
				numero = charToInt(s[i]);
				l--;
				while(j != l)
				{
					potencia = potencia * b;
					j++;
				}
				multi = numero * potencia;
				total = total + multi;
				i++;
			}
			total = total * -1;
		}
		else
		{
			i = 0;
			while(s[i] != '\0')
			{
				potencia = 1;
				j = 0;
				numero = charToInt(s[i]);
				l--;
				while(j != l)
				{
					potencia = potencia * b;
					j++;
				}
				multi = numero * potencia;
				total = total + multi;
				i++;
			}
		}

	return total;
}

// 1.1.1.17
// stringToInt sobrecarga
int stringToInt(string s)
{
	int i;

	int j;

	int numero;

	int potencia;

	int total = 0;
	int l = length(s);
	if(s[0] == '-')
	{
		i = 1;
		l--;
		while(s[i] != '\0')
		{
			l--;
			potencia = 1;
			j = 0;
			while(j != l)
			{
				potencia = potencia * 10;
				j++;
			}
			numero = charToInt(s[i]) * potencia;
			total = total + numero;
			i++;
		}
		total = total * (-1);
	}
	else
	{
		i = 0;
		while(s[i] != '\0')
		{
			l--;
			potencia = 1;
			j = 0;
			while( j != l)
			{
				potencia = potencia * 10;
				j++;
			}
			numero = charToInt(s[i]) * potencia;
			total = total + numero;
			i++;
		}
	}
	return total;
}

// 1.1.1.18
string charToString(char c)
{
	string s;
	s = c;
	return s;
}

// 1.1.1.19
char stringToChar(string s)
{
	char c = s[0];
	return c;
}

// 1.1.1.20
string stringToString(string s)
{
	string x;
	x = s;
	return x;
}

// 1.1.1.21
// tiene problemas con el redondeo de los double
string doubleToString(double d)
{
	string negativo;
	if(d < 0)
	{
		negativo = "-";
	}
	else
	{
		negativo = "";
	}

	// se hace positivo a d para evitar errores de calculoy porqeu el -, si esta presente, ya fue contemplado con el string negativo
	d = abs(d);
	int cantidadComa = 0;
	double auxComa = d;
	int auxInt = (int)d;

	// e es la parte decimal del numero
	double e = d - (int)d;
	// Hay que ponerle un limite porque un double puede ser infinito. Cantidad es la cantidad de numeros con coma
	while((e != 0) && (cantidadComa != 100))
	{
	cantidadComa++;
	auxComa = auxComa * 10;
	e = auxComa - (int)auxComa;
	}

	string entero;
	if(auxInt == 0)
	{
		entero = "0";
	}
	else
	{
		while(auxInt != 0)
		{
			entero = intToChar(auxInt % 10) + entero;
			auxInt = auxInt / 10;
		}
	}

	string coma;
	if(cantidadComa == 0)
	{
		coma = "";
	}
	else
	{
		coma = ".";
		int i = 0;
		e = d - (int)d;
		while(i != cantidadComa)
		{
			i++;
			e = e * 10;
			coma = coma + intToChar((int)e);
			e = e - (int)e;
		}
	}
	string total;
	total = negativo + entero + coma;

	return total;
}

// 1.1.1.22
// hay que incluir la libreria <iomanip> para que un cout de un double muestre mas de 6 digitos y usar setprecision(x)
double stringToDouble(string s)
{
	// busca en que posicion esta el punto
	int posComa = indexOf(s, '.');
	// si es negativo tiene que empezar el substring una pos mas adelante
	int neg = 0;
	bool esPositivo;
	if(s[0] == '-')
	{
		neg++;
		esPositivo = false;
	}
	else
	{
		esPositivo = true;
	}
	// subcadena entero
	string substEnt = substring(s,neg,posComa);
	// numero entero
	int numEnt = stringToInt(substEnt);

	// busca en que pos esta \0
	int posFin = indexOf(s, '\0');
	// subcadena decimal
	posComa++;
	string substDec = substring(s, posComa, posFin);

	// numero por el que se multiplica a num
	double potencia = 1;
	// recuento potencia
	int j = 0;
	// recuento total
	int i = 0;
	// cada numero
	double num;
	double numDec = 0;
	// no hace falta reiniciar las variables cada vez que se entra porque va de izq a der
	while(substDec[i] != '\0')
	{
		num = charToInt(substDec[i]);
		// se suma i aca para que tenga sentido el while de abajo
		i++;
		while(j != i)
		{
			potencia = potencia * (0.1);
			j++;
		}
		num = num * potencia;
		numDec = numDec + num;
	}

	double total = numEnt + numDec;

	if(!esPositivo)
	{
		total = total * (-1);
	}
	return total;
}

// 1.1.1.23
bool isEmpty(string s)
{
	bool isEmpty = false;
	if(s[0] == '\0')
	{
		isEmpty = true;
	}
	return isEmpty;
}

// 1.1.1.24
bool startsWith(string s,string x)
{
	bool startsWith = false;
	int lengthX = length(x);
	int i = 0;
	int iguales = 0;

	while(i != lengthX)
	{
		if(s[i] == x[i])
		{
			iguales++;
		}
		i++;
	}

	if(iguales == lengthX)
	{
		startsWith = true;
	}

	return startsWith;
}

// 1.1.1.25
bool endsWith(string s,string x)
{
	bool endsWith = false;
	int lengthX = length(x);
	int lengthS = length(s);

	int inicio = lengthS - lengthX;
	int j = 0;
	int iguales = 0;
	while(inicio != lengthS)
	{
		if(s[inicio] == x[j])
		{
			iguales++;
		}
		j++;
		inicio++;
	}
	if(iguales == lengthX)
	{
		endsWith = true;
	}

	return endsWith;
}

// 1.1.1.26
bool contains(string s,char c)
{
	bool contains = false;
	if((charCount(s,c)) >= 1)
	{
		contains = true;
	}
	return contains;
}

// 1.1.1.27
string replace(string s,char oldChar,char newChar)
{
	int i = 0;
	string r = "";
	while(s[i] != '\0')
	{
		if(s[i] != oldChar)
		{
			r = r + s[i];
		}
		else
		{
			r = r + newChar;
		}
		i++;
	}
	return r;
}

// 1.1.1.28
// si la posicion esta por fuera de la cadena se devuelve la cadena original
string insertAt(string s,int pos,char c)
{
	int i = 0;
	string r = "";
	if(pos > length(s))
	{
		r = s;
	}
	else
	{
		if(s[pos] == '\0')
		{
			r = s + c;
		}
		else
		{
			while(s[i] != '\0')
			{
				if(i != pos)
				{
					r = r + s[i];
				}
				else
				{
					r = r + c + s[i];
				}
				i++;
			}
		}
	}
	return r;
}

// 1.1.1.29
// si pos esta por fuera devuelve la cadena original
string removeAt(string s,int pos)
{
	string r = "";
	int i = 0;

	while(s[i] != '\0')
	{
		if(i != pos)
		{
			r = r + s[i];
		}
		else
		{
			i++;
			r = r + s[i];
		}
		// hay que agregar este if por si se quiere borrar el caracter que esta antes del '\0'
		if(s[i] != '\0')
		{
		i++;
		}
	}

	return r;
}

// 1.1.1.30
string ltrim(string s)
{
	string r = "";
	int i = 0;
	while(s[i] == ' ')
	{
		i++;
	}
	while(s[i] != '\0')
	{
		r = r + s[i];
		i++;
	}
	return r;
}

// 1.1.1.31
string rtrim(string s)
{
	string r = "";
	int fin = length(s) - 1;

	while(s[fin] == ' ')
	{
		fin--;
	}

	int i = 0;
	while(i <= fin)
	{
		r = r + s[i];
		i++;
	}
	return r;
}

// 1.1.1.32
string trim(string s)
{
	string r = "";
	r = ltrim(s);
	r = rtrim(r);
	return r;
}

// 1.1.1.33
// si n es negativo o 0 no devuelve nada
string replicate(char c,int n)
{
	string r = "";
	int i = 0;
	while(i < n)
	{
		r = r + c;
		i++;
	}
	return r;
}

// 1.1.1.34
// si n es negativo o 0 no devuelve nada
string spaces(int n)
{
	string r = replicate(' ',n);
	return r;
}

// 1.1.1.35
// si n es menor al largo de s devuelve s original
string lpad(string s,int n,char c)
{
	while((length(s)) < n)
	{
		s = c + s;
	}
	return s;
}

// 1.1.1.36
// si n es menor al largo de s devuelve s original
string rpad(string s,int n,char c)
{
	while((length(s)) < n)
	{
		s = s + c;
	}
	return s;
}

// 1.1.1.37
// si es inpar el lado izquierdo tendra una letra mas. si n es menor al largo de s devuelve s original
string cpad(string s,int n,char c)
{
	while((length(s)) < n)
	{
		s = c + s;
		// este if esta por los casos impares
		if((length(s)) < n)
		{
			s = s + c;
		}
	}
	return s;
}

// 1.1.1.38
bool isDigit(char c)
{
	bool isDigit = false;
	// ascii 0 = 48, ascii 9 = 57
	if((c >= 48) && (c <= 57))
	{
		isDigit = true;
	}
	return isDigit;
}

// 1.1.1.39
bool isLetter(char c)
{
	bool isLetter = false;
	// ascii A-Z 65-90, ascii a-z 97-122
	if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
	{
		isLetter = true;
	}
	return isLetter;
}

// 1.1.1.40
bool isUpperCase(char c)
{
	bool isUpperCase = false;
	// ascii mayus 65-90
	if((c >= 65) && (c <= 90))
	{
		isUpperCase = true;
	}
	return isUpperCase;
}

// 1.1.1.41
bool isLowerCase(char c)
{
	bool isLowerCase = false;
	// ascii minus 97-122
	if((c >= 97) && (c <= 122))
	{
		isLowerCase = true;
	}
	return isLowerCase;
}

// 1.1.1.42
char toUpperCase(char c)
{
	char r = c;
	// ascii minus 97-122
	if((c >= 97) && (c <= 122))
	{
		r = c - 32;
	}
	return r;
}

// 1.1.1.43
char toLowerCase(char c)
{
	char r = c;
	// ascii mayus 65-90
	if((c >= 65) && (c <= 90))
	{
		r = c + 32;
	}
	return r;
}

// 1.1.1.44
string toUpperCase(string s)
{
	string r = "";
	int i = 0;
	while(s[i] != '\0')
	{
		r = r + toUpperCase(s[i]);
		i++;
	}
	return r;
}

// 1.1.1.45
string toLowerCase(string s)
{
	string r = "";
	int i = 0;
	while(s[i] != '\0')
	{
		r = r + toLowerCase(s[i]);
		i++;
	}
	return r;
}

// 1.1.1.46
int cmpString(string a,string b)
{
	// hay que pasar ambas cadenas al mismo caso, sea mayus o minus
	a = toUpperCase(a);
	b = toUpperCase(b);

	int ret;
	if(a == b)
	{
		ret = 0;
	}
	else
	{
		if(a < b)
		{
			ret = -1;
		}
		else
		{
			ret = 1;
		}
	}

	return ret;
}

// 1.1.1.47
int cmpDouble(double a,double b)
{
	int r = 0;
	if(a == b)
	{
	}
	else
	{
		if(a < b)
		{
			r = -1;
		}
		else
		{
			r = 1;
		}
	}
	return r;
}
// EXTRA
// checkea si es palabra o no
bool esPalabra(string s)
{
	bool esPalabra = true;
	if(s[0] == '\0')
	{
		esPalabra = false;
	}
	else
	{
		for(int i = 0 ; ((s[i] != '\0') && (esPalabra)) ; i++)
		{
			char aux = s[i];
			if(((aux >= 65) && (aux <= 90)) || ((aux >= 97) && (aux <= 122)))
			{
			}
			else
			{
				esPalabra = false;
			}
		}
	}
	return esPalabra;
}

#endif

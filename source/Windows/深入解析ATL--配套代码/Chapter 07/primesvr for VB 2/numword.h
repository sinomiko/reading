// NumWord.h

#pragma once
#ifndef _NUMWORD_H_
#define _NUMWORD_H_

inline
char* NumWord(long n, char* psz)
{
  *psz = 0;

  if( n < 0 )
  {
    n *= -1;
    strcpy(psz, "minus ");
  }

  long  billions = n/1000000000;
  if( billions )
  {
    n %= 1000000000;
    NumWord(billions, psz + strlen(psz));
    strcat(psz, " billion");
  }

  long  millions = n/1000000;
  if( millions )
  {
    n %= 1000000;
    if( *psz ) strcat(psz, ", ");
    NumWord(millions, psz + strlen(psz));
    strcat(psz, " million");
  }

  long  thousands = n/1000;
  if( thousands )
  {
    n %= 1000;
    if( *psz ) strcat(psz, ", ");
    NumWord(thousands, psz + strlen(psz));
    strcat(psz, " thousand");
  }

  long  hundreds = n/100;
  if( hundreds )
  {
    n %= 100;
    if( *psz ) strcat(psz, ", ");
    NumWord(hundreds, psz + strlen(psz));
    strcat(psz, " hundred");
  }

  long  tens = n/10;
  if( tens > 1 )
  {
    n %= 10;
    static const char* rgpszTens[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    if( *psz ) strcat(psz, " and ");
    strcat(psz, rgpszTens[tens - 2]);
  }

  if( n )
  {
    static const char* rgpszTeens[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    if( *psz && n && tens <= 1 ) strcat(psz, " and ");
    else if( *psz && n ) strcat(psz, " ");
    strcat(psz, rgpszTeens[n]);
  }
  else if( !*psz )
  {
    strcpy(psz, "zero");
  }

  return psz;
}

#endif  // _NUMWORD_H_


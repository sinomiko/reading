
#pragma once
#ifndef _ISPRIME_H_
#define _ISPRIME_H_

#include <math.h>

inline
bool IsPrime(long n)
{
  // Special case: < 2
  if( n < 2 ) return false;

  // Special case: first couple of primes
  if( n == 2 || n == 3 )
  {
    return true;
  }

  // Special case: even
  if( n % 2 == 0 ) return false;

  // Special case: has a square root
  double  root = sqrt(double(n));
  if( double(long(root)) == root ) return false;

  const long begin = 3;
  const long end = long(root) + 1;

  // Special case: root < begin
  if( end < begin ) return true;

  for( long i = begin; i != end; ++i )
  {
    if( n % i == 0 ) return false;
  }

  return true;
}

inline
size_t CountPrimes(long min, long max)
{
  size_t nCount = 0;
  for( long n = min; n <= max; n++ )
  {
    if( IsPrime(n) ) ++nCount;
  }

  return nCount;
}

inline
long NthPrime(long i, long min, long max)
{
  while( min <= max )
  {
    if( IsPrime(min) ) --i;
    if( !i ) return min;
    ++min;
  }

  return -1;
}

#endif  // _ISPRIME_H_

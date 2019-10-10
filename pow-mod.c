#include <stdio.h>
#include <stdint.h>

/*
a mod n = r
a = p * q

p = an+x
q = bn+y

-> x = p mod n
-> y = q mod n

pq = (an+x) * (bn+y)
   = ab*n² + any + bnx + xy
   = n*(abn + ay + bx) + xy
->
pq mod n = xy mod n
*/

/* Calculate b^e mod n using a modified square and multiply algorithm */
uint64_t pow_mod(uint64_t b, uint64_t e, uint64_t n) {
  if (e == 0) {
    return 1;
  } else {
    uint64_t pow = pow_mod(b, e/2, n);
    
    if ((e % 2) == 0)
      return (pow * pow) % n;
    else
      return (pow * pow * b) % n;
  }
}

uint64_t pow_mod_it(uint64_t b, uint64_t e, uint64_t n) {
  uint64_t tmp = 1;

  while (e > 0) {
    if (e & (1LL<<63))
      tmp = (tmp * tmp * b) % n;
    else
      tmp = (tmp * tmp) % n;
    e <<= 1;
  }

  return tmp;
}

int main(void) {
  uint64_t b = 75434;
  uint64_t e = 357107;
  uint64_t n = 753397;

  // Expected result is 72.
  printf("%llu^%llu mod %llu = %llu\n", b, e, n, pow_mod_it(b, e, n));
  return 0;
}

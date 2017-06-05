#include <stdint.h>
#define EXTERN
#ifndef TEST
# define DDRJ   _SFR_MEM8(0x104)
# define DDJ7   7
# define DDJ6   6
# define DDJ5   5
# define DDJ4   4
# define DDJ3   3
# define DDJ2   2
# define DDJ1   1
# define DDJ0   0
#else
EXTERN volatile uint8_t DDRJ;
# define DDJ7   7
# define DDJ6   6
# define DDJ5   5
# define DDJ4   4
# define DDJ3   3
# define DDJ2   2
# define DDJ1   1
# define DDJ0   0
#endif

#ifndef TEST
# define PORTJ  _SFR_MEM8(0x105)
# define PJ7 7
# define PJ6 6
# define PJ5 5
# define PJ4 4
# define PJ3 3
# define PJ2 2
# define PJ1 1
# define PJ0 0
# else
EXTERN volatile uint8_t PORTJ;
# define PJ7 7
# define PJ6 6
# define PJ5 5
# define PJ4 4
# define PJ3 3
# define PJ2 2
# define PJ1 1
# define PJ0 0
# endif

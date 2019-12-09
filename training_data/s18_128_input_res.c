#include "header.h"
unsigned short usa[128];
unsigned int   ua[128];

__attribute__((noinline))
void example23 (unsigned short *input, unsigned int *res)
{
  int i;

  for (i = 0; i < 128; i++)
    *res++ = *input++ << 7;
}

int main(int argc,char* argv[]){
  init_memory(&ua[0], &ua[128]);
      BENCH("Example23",  example23(usa,ua), Mi*8/128*512, digest_memory(&usa[0], &usa[128]));
  return 0;
}

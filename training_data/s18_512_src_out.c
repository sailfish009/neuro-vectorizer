#include "header.h"
unsigned short usa[512];
unsigned int   ua[512];

__attribute__((noinline))
void example23 (unsigned short *src, unsigned int *out)
{
  int i;

  for (i = 0; i < 512; i++)
    *out++ = *src++ << 7;
}

int main(int argc,char* argv[]){
  init_memory(&ua[0], &ua[512]);
      BENCH("Example23",  example23(usa,ua), Mi*8/512*512, digest_memory(&usa[0], &usa[512]));
  return 0;
}

#include "BCM2835.h"
#include "PiZeroW.h"

typedef unsigned int uint;

void write32(void *dst, uint val) {
  uint *dst_u = (uint *)dst;
  *dst_u = val;
  return;
}

uint read32(void *src) {
  uint *src_u = (uint *)src;
  return *src_u;
}

void wait(int count) {
  while (count--) {
    asm volatile("nop" ::);
  }
}

int main(void) {

  uint gpfsel4 = read32((void *)BCM2835_GPFSEL4);
  // Turn pin 47 into an output
  // (FSEL47 as specified in Broadcom BCM2835 ARM Peripherals data sheet).
  gpfsel4 |= (1 << 21);
  write32((void *)BCM2835_GPFSEL4, gpfsel4);

  while (1) {
    // Turn on pin 47 - Raspberry PI ZERO W clears the pin to activate it.
    write32((void *)BCM2835_GPCLR1, GPIO_ACT_LED);
    wait(1000000);
    // Turn off pin 47
    write32((void *)BCM2835_GPSET1, GPIO_ACT_LED);
    wait(1000000);
  }
  return 0;
}

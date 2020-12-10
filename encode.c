#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54

void encode(FILE *base, FILE *in, FILE *out) {
  rewind(base);
  unsigned char copy;
  unsigned char byte_in;
  unsigned char byte_base;
  unsigned char bit_in;
  unsigned char bit_base;

  for (int i = 0; i < HEADER_SIZE; i++) {
    copy = fgetc(base);
    fputc(copy, out);
  }

  rewind(in);
  while (!feof(in)) {
    byte_in = fgetc(in);

    for (int i = 0; i < 8; i++) {
      bit_in = (byte_in >> i) & 0x1;
      byte_base = fgetc(base);
      bit_base = (byte_base >> 7) & 0x1;

      if (bit_in != bit_base)
        byte_base = byte_base ^ 1;
      fputc(byte_base, out);
    }
  }

  while (!feof(base)) {
    copy = fgetc(base);
    fputc(copy, out);
  }
}

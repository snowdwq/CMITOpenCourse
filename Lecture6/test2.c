#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct point
{
    int x;
    int y;
};

typedef struct
{
    int x;
    int y;
} point2;

typedef struct
{
    int x;
    int y;
    int z;
} point3;

typedef struct
{
    int x;
} point4;

typedef struct
{
    char c;
    char c2;
} point5;

typedef struct
{
    char c;
    char c2;
    int k;
} point6;

typedef struct
{
    int k;
    char c;
    char c2;
} point7;

typedef struct
{
    int k;
    int l;
    int m;
    int n;
    char c;
} point8;
// better to have the biggest fields first (for allignment issues)

typedef struct
{
    char k;
} point9;

typedef struct {
  uint8_t val0;
  uint16_t val1;
  // padding 1 byte
  uint8_t val2;
  uint16_t val3;
  // padding 1 byte
  uint8_t val4;
  // padding 3 bytes
  uint32_t val5;
  uint8_t val6;
  // padding 3 bytes
} MemoryUnused;

typedef struct {
  uint8_t val0;
  uint8_t val2;

  uint16_t val1;

  uint16_t val3;
  uint8_t val4;
  // padding 1 byte
  uint32_t val5;
  uint8_t val6;
  // padding 3 bytes
} MemoryUnused2;

typedef struct {
  uint8_t val0;
  uint8_t val2;
  uint8_t val4;
  uint8_t val6;

  uint16_t val1;
  uint16_t val3;

  uint32_t val5;
} MemoryUnused3;

typedef struct {
  uint32_t val5;
  uint16_t val1;
  uint16_t val3;
  uint8_t val0;
  uint8_t val2;
  uint8_t val4;
  uint8_t val6;
} MemoryNotLost;

int main(void)
{
    point2 p;

    printf("%lu\n", sizeof(struct point));
    printf("%lu\n", sizeof(point2));
    printf("%lu\n", sizeof(point3));
    printf("%lu\n", sizeof(point4));
    printf("%lu\n", sizeof(point5));
    printf("%lu\n", sizeof(point6));
    printf("%lu\n", sizeof(point7));
    printf("%lu\n", sizeof(point8));
    printf("%lu\n", sizeof(point9));
    printf("%lu\n", sizeof(point9));
    printf("%lu\n", sizeof(MemoryUnused));
    printf("%lu\n", sizeof(MemoryUnused2));
    printf("%lu\n", sizeof(MemoryUnused3));
    printf("%lu\n", sizeof(MemoryNotLost));

    return 0;
}

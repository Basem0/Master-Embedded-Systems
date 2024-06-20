#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_
#include <stdint.h>
#include <stdbool.h>

#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE          CPU_TYPE_32
#define CPU_BIT_ORDER     MSB_FIRST
#define CPU_BYTE_ORDER    HIGH_BYTE_FIRST


#ifndef FALSE
#define FALSE             (boolean)false
#endif

#ifndef TRUE
#define TRUE              (boolean)true
#endif

typedef _Bool            boolean;
typedef signed char          sint8_t;
typedef unsigned char        uint8_t;
typedef signed short         sint16_t;
typedef unsigned short       uint16_t;
typedef signed long          sint32_t;
typedef unsigned long        uint32_t;
typedef signed long long     sint64_t;
typedef unsigned long long   uint64_t;

typedef volatile sint8_t  vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile sint16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile sint32_t vint32_t;
typedef volatile uint32_t vuint32_t;

typedef volatile sint64_t vint64_t;
typedef volatile uint64_t vuint64_t;

#endif //PLATFORM_TYPES_H_
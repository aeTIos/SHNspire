#ifndef INC_COMMON
#define INC_COMMON
#include <libndls.h>
#include "n2DLib.h"
// Use this instead of R5G6B5 to facilitate fade in/out-s
typedef struct
{
	uint8_t r, g, b;
} RGB;

typedef struct
{
	// polar coordinates
	Fixed r, a;
}SH_Vector;

typedef struct
{
	Fixed referenceAngle;
	SH_Vector vectors[6];
} SH_VectorSpace;

// 6-coordinates vertex
typedef struct
{
    Fixed u, v, w, x, y, z;
} SH_Vertex;

typedef struct
{
	SH_VectorSpace vectorSpace;
	RGB bg;
} GameSpace;

// SH_Vector.c
SH_VectorSpace buildUnitVectors();
void drawVectorSpace(SH_VectorSpace *s, uint16_t c);
void rotateVectorSpace(SH_VectorSpace *s, Fixed angle);
SH_Vector extendToScreenEdge(SH_Vector *u);

// utils.c
uint16_t rgbTo565(RGB c);

#endif
#include "common.h"

SH_VectorSpace buildUnitVectors()
{
	SH_VectorSpace result;
	int i;
	for(i = 0; i < 6; i++)
	{
		result.vectors[i].r = itofix(1);
		result.vectors[i].a = i * 43; // 43 * 6 = 258, close enough to 256
	}
	result.referenceAngle = 0;
	return result;
}

void updateVectorSpace(SH_VectorSpace *s)
{
	int i;
	s->referenceAngle &= 0xff;
	for(i = 0; i < 6; i++)
	{
		s->vectors[i].a = s->referenceAngle + i * 43; // 43 * 6 = 258, close enough to 256
	}
}

void drawVectorSpace(SH_VectorSpace *s, uint16_t c)
{
	int i;
	SH_Vector cv;
	// TODO : background
	for(i = 0; i < 6; i++)
	{
		cv = extendToScreenEdge(&s->vectors[i]);
		drawLine(160, 120, fixtoi(fixmul(cv.r, fixcos(cv.a))) + 160, fixtoi(fixmul(cv.r, fixsin(cv.a))) + 120, c);
	}
}

inline void rotateVectorSpace(SH_VectorSpace *s, Fixed angle)
{
	s->referenceAngle += angle;
	updateVectorSpace(s);
}

// Meant to be used only with SH_VectorSpace's vectors
// ie screen-centered unit vectors
SH_Vector extendToScreenEdge(SH_Vector *u)
{
    int a = u->a & 0xff;
    SH_Vector result;
    result.a = a;
	// The screen is a 320*240 rectangle, not a square
    if(a < 27 || a >= 229)
		result.r = fixdiv(itofix(160), fixcos(a));
	else if(a < 101)
		result.r = fixdiv(itofix(120), fixsin(a));
	else if(a < 155)
		result.r = fixdiv(itofix(-160), fixcos(a));
	else
		result.r = fixdiv(itofix(-120), fixsin(a));
	
	return result;
}

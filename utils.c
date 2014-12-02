#include "common.h"

inline uint16_t rgbTo565(RGB c)
{
	return ((c.r >> 3) << 11) | ((c.g >> 2) << 5) | (c.b >> 3);
}
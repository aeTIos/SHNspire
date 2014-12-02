#include "common.h"

int main(void) {
	assert_ndless_rev(801);
	GameSpace gameSpace;
	
	gameSpace.vectorSpace = buildUnitVectors();
	gameSpace.bg.r = gameSpace.bg.g = gameSpace.bg.b = 255;
	
	initBuffering();
	clearBufferB();
	
	while(!isKeyPressed(KEY_NSPIRE_ESC))
	{
		drawVectorSpace(&gameSpace.vectorSpace, rgbTo565(gameSpace.bg));
		if(isKeyPressed(KEY_NSPIRE_PLUS)) rotateVectorSpace(&gameSpace.vectorSpace, 1);
		updateScreen();
		clearBufferB();
	}
	
	deinitBuffering();
	return 0;
}

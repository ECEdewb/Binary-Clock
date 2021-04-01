#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include "display.h"

#define BLACK 0x0000

int main(void) {
	pi_framebuffer_t *fb=getFrameBuffer();
	clearFrameBuffer(fb,BLACK);
	int x = 1;
	while (x) {
		int seconds = 01;
		int minutes = 01;
		int hours = 01;
		int time = scanf("%d:%d:%d", &hours, &minutes, &seconds);
		if (time == 3) {
			clearFrameBuffer(fb,BLACK);
			freeFrameBuffer(fb);
			display_time(hours,minutes,seconds,fb);
		}
		else {
			break;
		}
	}
	clearFrameBuffer(fb,BLACK);
	freeFrameBuffer(fb);
	return 0;

}

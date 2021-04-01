#include <stdio.h>
#include <unistd.h>
#include "sense.h"

#define WHITE 0xFFFF
#define BLUE 0x1F
#define GREEN 0x7E0
#define RED 0xF800

void display_colons(pi_framebuffer_t *dev) {
	pi_framebuffer_t *fb=getFrameBuffer();
	sense_fb_bitmap_t *bm=fb->bitmap;

	bm->pixel[1][1]=WHITE;
	bm->pixel[1][2]=WHITE;
	bm->pixel[2][1]=WHITE;
	bm->pixel[2][2]=WHITE;

	bm->pixel[4][1]=WHITE;
	bm->pixel[4][2]=WHITE;
	bm->pixel[5][1]=WHITE;
	bm->pixel[5][2]=WHITE;

	bm->pixel[1][4]=WHITE;
	bm->pixel[2][4]=WHITE;
	bm->pixel[1][5]=WHITE;
	bm->pixel[2][5]=WHITE;

	bm->pixel[4][4]=WHITE;
	bm->pixel[4][5]=WHITE;
	bm->pixel[5][4]=WHITE;
	bm->pixel[5][5]=WHITE;
}
void display_hours(int hours, pi_framebuffer_t *dev) {
	pi_framebuffer_t *fb=getFrameBuffer();
	sense_fb_bitmap_t *bm=fb->bitmap;

	if ((hours % 2) == 1) {
		bm->pixel[0][6]=BLUE;
	}
	if (((hours / 2) % 2) == 1) {
		bm->pixel[1][6]=BLUE;
	}
	if (((hours / 4) % 2) == 1) {
		bm->pixel[2][6]=BLUE;
	}
	if (((hours / 8) % 2) == 1) {
		bm->pixel[3][6]=BLUE;
	}
	if (((hours / 16) % 2) == 1) {
		bm->pixel[4][6]=BLUE;
	}
}
void display_minutes(int minutes, pi_framebuffer_t *dev) {
	pi_framebuffer_t *fb=getFrameBuffer();
	sense_fb_bitmap_t *bm=fb->bitmap;

	if ((minutes % 2) == 1) {
		bm->pixel[0][3]=GREEN;
	}
	if (((minutes / 2) % 2) == 1) {
		bm->pixel[1][3]=GREEN;
	}
	if (((minutes / 4) % 2) == 1) {
		bm->pixel[2][3]=GREEN;
	}
	if (((minutes / 8) % 2) == 1) {
		bm->pixel[3][3]=GREEN;
	}
	if (((minutes / 16) % 2) == 1) {
		bm->pixel[4][3]=GREEN;
	}
	if (((minutes / 32) % 2) == 1) {
		bm->pixel[5][3]=GREEN;
	}
}

void display_seconds(int seconds, pi_framebuffer_t *dev) {
	pi_framebuffer_t *fb=getFrameBuffer();
	sense_fb_bitmap_t *bm=fb->bitmap;

	if ((seconds % 2) == 1) {
		bm->pixel[0][0]=RED;
	}
	if (((seconds / 2) % 2) == 1) {
		bm->pixel[1][0]=RED;
	}
	if (((seconds / 4) % 2) == 1) {
		bm->pixel[2][0]=RED;
	}
	if (((seconds / 8) % 2) == 1) {
		bm->pixel[3][0]=RED;
	}
	if (((seconds / 16) % 2) == 1) {
		bm->pixel[4][0]=RED;
	}
	if (((seconds / 32) % 2) == 1) {
		bm->pixel[5][0]=RED;
	}
}

void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *dev) {

	pi_framebuffer_t *fb=getFrameBuffer();
	sense_fb_bitmap_t *bm=fb->bitmap;
	display_colons(fb);
	display_hours(hours,fb);
	display_minutes(minutes,fb);
	display_seconds(seconds,fb);
	
}

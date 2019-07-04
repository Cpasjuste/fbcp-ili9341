//
// Created by cpasjuste on 04/07/19.
//

#ifndef FBCP_ILI9341_FBCP_H
#define FBCP_ILI9341_FBCP_H

#include <stdint.h>

// if targetFramebuffer == NULL, use dispmanx framebuffer
int FBCPInit(uint16_t *targetFramebuffer = NULL, int width = 0, int height = 0, int bpp = 0);

void FBCPExit();

int FBCPProcessFrame();

#endif //FBCP_ILI9341_FBCP_H

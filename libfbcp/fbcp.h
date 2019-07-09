//
// Created by cpasjuste on 04/07/19.
//

#ifndef FBCP_ILI9341_FBCP_H
#define FBCP_ILI9341_FBCP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// if targetFramebuffer == NULL, use dispmanx framebuffer
int fbcp_init(uint16_t* targetFramebuffer, int width, int height, int bpp);

int fbcp_process();

void fbcp_exit();

#ifdef __cplusplus
}
#endif

#endif //FBCP_ILI9341_FBCP_H


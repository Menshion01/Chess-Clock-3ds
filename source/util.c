#include "util.h"
#include "main.h"
#include "text.h"

u32 clrWhite;
u32 clrGray;
u32 clrBlack;
u32 clrPink;
u32 clrGreen;

void initiate() {
    romfsInit();
	cfguInit(); // Allow C2D_FontLoadSystem to work
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    //consoleInit(GFX_TOP, NULL);
}

void initColours() {
    clrWhite = C2D_Color32(255, 255, 255, 255);
    clrBlack = C2D_Color32(49, 49, 49, 255);
    clrGray  = C2D_Color32(69, 69, 69, 255);
    clrPink = C2D_Color32(255, 189, 189, 255);
    clrGreen = C2D_Color32(4, 151, 64, 255);
}

void end() {

    C2D_TextBufDelete(Timer_Buf);
    C2D_TextBufDelete(Timer_Buf_two);
    C2D_TextBufDelete(sign_buf);

    C2D_FontFree(font[0]);
    C2D_FontFree(font[1]);

    C2D_Fini();
    C3D_Fini();
    gfxExit();
}
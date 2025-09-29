#include "main.h"
#include "text.h"
#include "touch.h"
#include "util.h"

C2D_Font font[2];

C2D_TextBuf Timer_Buf;
C2D_TextBuf Timer_Buf_two;
C2D_TextBuf Increment_Buf;
C2D_TextBuf Textprompt_Buf;

C2D_TextBuf sign_buf;

void initText() {
    font[0] = C2D_FontLoad("romfs:/monaco.bcfntx");
    font[1] = C2D_FontLoad("romfs:/arial.bcfntx");


    Timer_Buf = C2D_TextBufNew(8);
    Timer_Buf_two = C2D_TextBufNew(8);
    Increment_Buf = C2D_TextBufNew(8);
    Textprompt_Buf = C2D_TextBufNew(32);
    sign_buf = C2D_TextBufNew(8);
}

void addText(const char *toPrint, C2D_Text* gtext, C2D_TextBuf g_staticBuf, int whatFont) {
    C2D_TextBufClear(g_staticBuf);
    C2D_TextFontParse(gtext, font[whatFont], g_staticBuf, toPrint);
	C2D_TextOptimize(gtext);
}

void sceneRender(C2D_Text *gtext, float x, float y, float size, C2D_TextBuf g_staticBuf) {
    if (x < 0) {
        x = BOT_SCREEN_WIDTH/2 + x;
        C2D_DrawText(gtext, C2D_AtBaseline, x, y, 0, size, size);
    }
    else {
        C2D_DrawText(gtext, C2D_AtBaseline, x, y, 0, size, size);
    }
}

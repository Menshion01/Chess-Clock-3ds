#include <citro2d.h>

#include "main.h"
#include "render.h"
#include "touch.h"
#include "util.h"
#include "text.h"
#include "ui.h"
#include "time.h"

void render(C3D_RenderTarget *bot, C3D_RenderTarget *top) {

    // Initalise rendering
    C3D_FrameEnd(0); // Render the scene
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_SceneBegin(top);
    
    C2D_TargetClear(bot, clrGray);
    C2D_TargetClear(top, clrBlack);

    //C2D_DrawRectSolid(RectX, RectY, 0, 100, 50, clrWhite);

    //When touching bottom screen turn it white if bellow pink bar
    if (touch.py > 60) {
        C2D_TargetClear(bot, clrWhite);
    }

    C2D_DrawRectSolid(25,(SCREEN_HEIGHT-150)/2,0,170,150, (turn && !paused) ? clrGreen : clrGray);
    C2D_DrawRectSolid((SCREEN_WIDTH-150-25 - 20),(SCREEN_HEIGHT-150)/2,0,170,150, (!turn && !paused) ? clrGreen : clrGray);
    
    sceneRender(&g_timer, 27, 150, 2.45f, Timer_Buf);     // Render Timer
    sceneRender(&g_timer_two, SCREEN_WIDTH-23-170, 150, 2.45f, Timer_Buf_two);     // Render Timer 2
    sceneRender(&g_signature, 335, 232, 0.5f, sign_buf);    // Render My name
    
    C2D_SceneBegin(bot); // Render on bottom screen
    C2D_DrawRectSolid( 0,0,0,BOT_SCREEN_WIDTH, 60, clrPink); // Bar top
    C2D_DrawRectSolid( (BOT_SCREEN_WIDTH - 6 )/2,0,0,6, BOT_SCREEN_HEIGHT, clrPink); // Bar down middle

    //big button is 157 wide, 180 tall
    C2D_DrawRectSolid(0,60,0,157,BOT_SCREEN_HEIGHT-60, (turn || paused) ? clrGreen : clrGray);
    C2D_DrawRectSolid(157+6,60,0,157,BOT_SCREEN_HEIGHT-60, (!turn || paused) ? clrGreen : clrGray);
    
    sceneRender(&g_increment, 178, 45, 1.0f, Increment_Buf); // Render increment
    C2D_DrawRectSolid(210, 18,0,40,30, clrWhite); // Increment button 1
    C2D_DrawRectSolid(260, 18,0,40,30, clrWhite); // Increment button 2
    
    //Pause rectangles
    C2D_DrawRectSolid( 40,18,0,10,30, clrWhite);
    C2D_DrawRectSolid( 40 + 15,18,0,10,30, clrWhite); 

    sceneRender(&g_textprompt, 39, 58, 0.4f, Textprompt_Buf); // print instructions

    C3D_FrameEnd(0);

}
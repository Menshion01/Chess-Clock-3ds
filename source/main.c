#include "main.h"

int userSec = 600;
int incrementAmount = 2;
char incrementAmountString[] = "";
float time_left_one = 0;
float time_left_two = 0;
bool turn = false;

int main() {
	
	initiate();
	initColours();
	initText();

	paused = true;
	turn = false;

	// Create screen(s)
	C3D_RenderTarget *bot = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
	C3D_RenderTarget *top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	
	while (aptMainLoop()) {
		updateTouch(); 
		
		stopwatchFunction();
		addUI();
		addText("pause    up/down for min        more    less", &g_textprompt, Textprompt_Buf, 0);
				
		// Check if a key is down, if it's start then close the app
		u32 kDown = hidKeysDown();
		if (kDown) buttonPress(kDown); //Dpad press => solutionNum logic 
		
		render(bot, top);
	}


	end();
	return 0;
}

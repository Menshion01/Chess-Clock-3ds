#include "main.h"
#include "touch.h"
#include "time.h"
#include "text.h"

touchPosition touch;

void updateTouch() {
    hidScanInput();
    hidTouchRead(&touch);
}


bool buttonPress(u32 buttonPressed) {

    if (buttonPressed & KEY_DRIGHT || buttonPressed & KEY_DDOWN) userSec -= 60;
    if (buttonPressed & KEY_DLEFT || buttonPressed & KEY_DUP) userSec += 60;

    if (buttonPressed & KEY_B) {
        if (incrementAmount > 0 ) incrementAmount --;
    }
    else if (buttonPressed & KEY_X) {
        if (incrementAmount < 9 ) incrementAmount ++;
    }

    if (buttonPressed & KEY_SELECT) {
        if (turn) time_left_one -= stop_stopwatch();
        else time_left_two -= stop_stopwatch();
        //stop_stopwatch();
        
        paused = true;
    }
    
    if (buttonPressed & KEY_START) {
        stop_stopwatch();
        paused = true;
        turn = 0;
        time_left_one = 0;
        time_left_two = 0;
    }
        return 0.0;
}


// Point to rectangle collusion script
bool collusion(float x, float y, float width, float height, float ox, float oy) {
    // If specified as 0, default to mouse position
    if (!x) x = touch.px;
    if (!y) y = touch.py;

    if (ox <= x && x <= ox+width) {

        if (oy <= y && y <= oy + height) {
            return true;
        }
    }
    return false;
}
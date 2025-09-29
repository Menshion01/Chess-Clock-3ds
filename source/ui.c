#include "ui.h"
#include "util.h"
#include "text.h"

// Text decleration
C2D_Text g_timer;
C2D_Text g_timer_two;
C2D_Text g_increment;
C2D_Text g_textprompt;
C2D_Text g_signature;

int tapingOnTheGlass = 0;
bool paused;

void addUI() {
    snprintf(incrementAmountString, 8, "+%d", incrementAmount);
    addText(incrementAmountString, &g_increment, Increment_Buf, 1);

    // timer veriable is only set to the time when screen is pressed, inbetween it interprets it
    if (turn) {
        if (!paused) addText(makeSexagesimal(time_left_one - get_elapsed_time()), &g_timer, Timer_Buf, 1);
        else addText(makeSexagesimal(time_left_one), &g_timer, Timer_Buf, 1);

        addText(makeSexagesimal(time_left_two), &g_timer_two, Timer_Buf_two, 1);
    }
    else {
        if (!paused) addText(makeSexagesimal(time_left_two - get_elapsed_time()), &g_timer_two, Timer_Buf_two, 1); // Print changing timer 2
        else addText(makeSexagesimal(time_left_two), &g_timer_two, Timer_Buf_two, 1);

        addText(makeSexagesimal(time_left_one), &g_timer, Timer_Buf, 1);                              // Print still timer 1
    }
    addText("By Mason", &g_signature, sign_buf, 0);

    // Check for pause button press
    if (collusion(0,0,50,45,20,10)) {

        if (turn) time_left_one -= stop_stopwatch();
        else time_left_two -= stop_stopwatch();
        //stop_stopwatch();

        paused = true;
    }

    //Up/Down increment on bottom screen
    if (collusion(0, 0, 40, 30, 210, 18) && tapingOnTheGlass == 0) {
        tapingOnTheGlass = 1;
    }
    else if (!collusion(0, 0, 40, 30, 210, 18) && tapingOnTheGlass == 1  ) {
        if (incrementAmount < 9) incrementAmount ++;
        tapingOnTheGlass = 0;
    }
    
    if (incrementAmount != 0 && collusion(0, 0, 40, 30, 260, 18) && tapingOnTheGlass == 0) {
        tapingOnTheGlass = 2;
    }
    else if (!collusion(0, 0, 40, 30, 260, 18) && tapingOnTheGlass == 2  ) {
        incrementAmount --;
        tapingOnTheGlass = 0;
    }
}
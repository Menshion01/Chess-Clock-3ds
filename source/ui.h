#ifndef UI_H
#define UI_H

#include <citro2d.h>
#include "main.h"
#include "time.h"
#include "text.h"

// Text decleration
extern C2D_Text g_timer;
extern C2D_Text g_timer_two;
extern C2D_Text g_increment;
extern C2D_Text g_signature;
extern C2D_Text g_textprompt;

extern bool paused;

extern void addUI();

#endif
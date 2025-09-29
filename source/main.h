#ifndef MAIN_H
#define MAIN_H

#include <citro2d.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "main.h"
#include "touch.h"
#include "util.h"
#include "text.h"
#include "ui.h"
#include "render.h"
#include "time.h"

extern int userSec;
extern int incrementAmount;
extern char incrementAmountString[];
extern float time_left_one;
extern float time_left_two;
extern bool turn;

extern u32 kDown;

#endif
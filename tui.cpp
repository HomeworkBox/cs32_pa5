//
//  tui.cpp
//  pa5
//
//  Created by Tyler Weimin Ouyang on 9/3/14.
//  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
//

#include <stdio.h>
#include "tui.h"

//class color
const int color::black = 0;
const int color::red = 1;
const int color::green = 2;
const int color::yellow = 3;
const int color::blue = 4;
const int color::magenta = 5;
const int color::cyan = 6;
const int color::white = 7;
const int color::system_default = 9;

//class pen
pen::pen(int fg_color, int bg_color, char sign, bool brightness):
_fg_color(fg_color), _bg_color(bg_color), _sign(sign), _brightness(brightness){
}
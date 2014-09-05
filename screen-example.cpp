//
//  screen-example.cpp
//  pa5
//
//  Created by Tyler Weimin Ouyang on 9/3/14.
//  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
//

#include <iostream>
#include "screen.h"

int main() {
    
	using namespace tui;

	screen scr;
	scr.clear();

	point ptred('@', 1, 3, false);
	point ptblue('#', 4, 0, true);

	scr.set_rect(0, 0, scr.ncols() - 1, scr.nrows() - 1, ptred);
	scr.set_circle(30, 15, 10, ptblue);

	scr.render();
    
	return 0;
}

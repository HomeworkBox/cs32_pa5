//
//  main.cpp
//  pa5
//
//  Created by Tyler Weimin Ouyang on 9/3/14.
//  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
//

#include <iostream>
#include "screen.h"
#include "tui.h"

using namespace tui;

int main() {
	screen scr;
	canvas canv(scr);

	// -- creating a few pens ------------------------------------------------

	pen pen_magenta(color::magenta, color::system_default, '&', true);
	pen pen_red(color::yellow, color::red, '@', true);
	pen pen_green(color::white, color::green, '$', false);
	pen pen_blue(color::blue, color::blue, '*', true);
	pen pen_white(color::black, color::white, 'O', true); 

	// -- drawing shapes -----------------------------------------------------
	
	rectangle rect1(0, 0, scr.ncols(), scr.nrows());
	canv.add(&rect1, pen_magenta);

	// keeping addresses of objects created using placement new (such objects
	// need to be _explicitly_ destructed)
	vector<shape*> trash;

	// creating a list of pens, for convenience
	vector<pen> pens;
	pens.push_back(pen_red);
	pens.push_back(pen_green);
	pens.push_back(pen_blue);
	pens.push_back(pen_white);

	// filling the left part of window with nested rectangles
	int width = (scr.ncols() - 2) / 2;
	int height = scr.nrows() - 2;
	for(int i = 1; i <= (scr.ncols() - 2) / 8; i++) {
		shape* addr = (shape*)alloca(sizeof(rectangle));
		trash.push_back(addr);
		new (addr) rectangle(i, i, width, height);
		canv.add(addr, pens[i % pens.size()]);
		width -= 2;
		height -= 2;
		if(width <= 0 || height <= 0)
			break;
	}

	// filling the right part of the window with nested circles
	int x = 1 + 3 * (scr.ncols() - 2) / 4;
	int y = (scr.nrows() - 2) / 2;
	for(int rad = ((scr.ncols() - 2) >> 3) - 2; rad > 0; rad -= 2) {
		shape* addr = (shape*)alloca(sizeof(circle));
		trash.push_back(addr);
		new (addr) circle(x, y, rad);
		canv.add(addr, pens[(rad >> 1) % pens.size()]);
	}
	
	// -- updating screen -----------------------------------------------------

	canv.show();

	// -- manually destructing objects created using placement new ------------
	
	for(int i = 0; i < (int)trash.size(); i++)
		trash[i]->~shape();
	
	// !notice these objects have been allocated on the stack, so
	// there is no need to manually release the memory the objects
	// have occupied (it is done automatically). But destructors are
	// not called automatically when we use placement new.

	return 0;
}

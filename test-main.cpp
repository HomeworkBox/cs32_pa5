//
//  test-main.cpp
//  pa5x
//
//  Created by Tyler Weimin Ouyang on 9/5/14.
//  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
//

#include <iostream>
#include "screen.h"
#include "tui.h"

using namespace tui;

int main() {
    std::cout << color::system_default << std::endl;
    
    screen scr;
    scr.clear();
    
    pen pen_magenta(color::magenta, color::system_default, '&', true);
    pen pen_blue(color::blue, color::black, '$', true);

    rectangle rec1(0, 0, 7, 7 );
    rec1.draw(scr, pen_magenta);
    circle cir1(5,5,5);
    cir1.draw(scr, pen_magenta);
    
    canvas cas(scr);
    shape *test = new circle(6,6,6);
    cas.add(test, pen_blue);
    
    scr.render();
    return 0;
}
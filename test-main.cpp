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
    //scr.set_rect(0, 0, scr.ncols() - 1, scr.nrows() - 1, pen_magenta.returnP());
    //scr.set_circle(30, 15, 10, pen_magenta.returnP());
    rectangle::rectangle rec1(0, 0, 7, 7 );
    rec1.draw(scr, pen_magenta);
    circle::circle cir1(5,5,5);
    cir1.draw(scr, pen_magenta);
    //scr.set_rect(0, 0, scr.ncols() - 1, scr.nrows() - 1, pen_magenta.returnP());
    scr.render();
    return 0;
}
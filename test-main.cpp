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
    //std::cout << color::system_default << std::endl;
    
    screen scr;
    scr.clear();
    canvas cas(scr);

    pen pen_magenta(color::magenta, color::system_default, '&', true);
    pen pen_blue(color::blue, color::black, '$', true);

    rectangle rec1(0, 0, 17, 17 );
    rectangle rec2(0, 0, 10, 10 );

    //rec1.draw(scr, pen_magenta);
    circle cir1(5,5,5);
    circle cir2(3,3,3);
    //cir1.draw(scr, pen_magenta);
      shape *test = (shape*)alloca(sizeof(circle));
    shape *test2 = (shape*)alloca(sizeof(rectangle));

//   // trash.push_back(test);
    new (test) circle(6, 6, 6);
    new (test2) rectangle(0, 0, scr.ncols(), scr.nrows());

//    cas.add(test, pen_blue);
//    cas.add(test2, pen_magenta);
//    
//    scr.render();
    
    cas.show();
    cas.clear();
    return 0;
}
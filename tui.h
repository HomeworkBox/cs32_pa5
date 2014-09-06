//
//  tui.h
//  pa5
//
//  Created by Tyler Weimin Ouyang on 9/3/14.
//  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
//
#include "screen.h"

#ifndef pa5_tui_h
#define pa5_tui_h
class color{
public:
    const static int black ;
    const static int red ;
    const static int green ;
    const static int yellow ;
    const static int blue ;
    const static int magenta ;
    const static int cyan ;
    const static int white ;
    const static int system_default ;
};

class pen {
private:
    int _fg_color;
    int _bg_color;
    char _sign;
    bool _brightness;
public:
    pen(int fg_color, int bg_color, char sign, bool brightness);
    tui::point returnP() const;
};

class shape{
private:
    
public:
   virtual void draw(tui::screen &scr, const pen &p) const {};
    //virtual ~shape();
};


class rectangle: public shape{
private:
    int _x0;
    int _y0;
    int _x1;
    int _y1;
public:
    rectangle(int x0, int y0, int x1, int y1);
    int get_x0() const{
        return _x0;
    }
    int get_y0() const{
        return _y0;
    }
    int get_x1() const{
        return _x1;
    }
    int get_y1() const{
        return _y1;
    }
    void draw(tui::screen &scr, const pen &p) const;
};

class circle{
private:
    int _x;
    int _y;
    int _rad;
public:
    circle(int x, int y, int rad);
    int get_x() const{
        return _x;
    }
    int get_y() const{
        return _y;
    }
    int get_rad() const{
        return _rad;
    }
    void draw(tui::screen &scr, const pen &p) const;
};

class canvas{
private:
    //tui::screen _scr;
public:
    canvas(tui::screen);
    void add(shape*, pen);
    void clear();
    void show();
};

#endif

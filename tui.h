//
//  tui.h
//  pa5
//
//  Created by Tyler Weimin Ouyang on 9/3/14.
//  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
//

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
};

class shape{
private:
    
public:
    
};


class rectangle{
private:
    
public:
    
};

class circle{
private:
    
public:
    
};

class canvas{
private:
    
public:
};

#endif

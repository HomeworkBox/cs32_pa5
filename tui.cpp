//
//  tui.cpp
//  pa5
//
//  Created by Tyler Weimin Ouyang on 9/3/14.
//  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
//
#include <stdio.h>
#include "tui.h"
#include <iostream>

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
pen::pen(){}
pen::pen(const pen& other): _fg_color(other._fg_color), _bg_color(other._bg_color), _sign(other._sign), _brightness(other._brightness){}
pen::pen(int fg_color, int bg_color, char sign, bool brightness):
_fg_color(fg_color), _bg_color(bg_color), _sign(sign), _brightness(brightness){
}
tui::point pen::returnP() const{
    tui::point po(_sign, _fg_color, _bg_color, _brightness);
    return po;
}

//class rectangle
rectangle::rectangle(int x0, int y0, int x1, int y1): _x0(x0), _y0(y0), _x1(x1), _y1(y1){
}

void rectangle::draw(tui::screen &scr, const pen &p) const{
    scr.set_rect(get_x0(), get_y0(), get_x0()+get_x1()-2, get_y0()+get_y1()-2, p.returnP());
}

void rectangle::draw(int x0, int y0, int x1, int y1, tui::screen &scr, pen p){
    scr.set_rect(x0,y0,x1-1,y1-1,p.returnP());
}

//class circle
circle::circle(int x, int y, int rad): _x(x), _y(y), _rad(rad){
}
void circle::draw(tui::screen &scr, const pen &p) const{
    scr.set_circle(get_x(), get_y(), get_rad(), p.returnP());
}

//class canvas
canvas::canvas(tui::screen &scr): _scr(scr){
}

void canvas::add(shape* sh, pen p){
    std::pair< shape*, pen > s;
    s = std::make_pair(sh,p);
    _v.push_back(s);
}
void canvas::add(rectangle* sh, pen p){
    sh->draw(sh->get_x0(),sh->get_y0(),sh->get_x1(),sh->get_y1(), _scr, p);
}//overload add for rectangle

void canvas::show(){
    for (int i=0; i<_v.size(); i++){
        _v[i].first->draw(_scr, _v[i].second);
    }
    _scr.render();
    clear();
}

void canvas::clear(){
    _v.clear();
    _scr.clear();
}
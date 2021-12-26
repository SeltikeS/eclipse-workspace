/*
 * rectangle.h
 *
 *  Created on: 25 ���. 2021 �.
 *      Author: SeltikeS
 */

#pragma once

class Rectangle {
public:
    Rectangle(int width, int height);

    int GetArea() const;

    int GetPerimeter() const;

    int GetWidth() const;
    int GetHeight() const;

private:
    int width_, height_;
};





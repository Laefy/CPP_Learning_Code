#pragma once

#include <ostream>

class Rectangle {
public:
    /*Rectangle(float length, float width)
        : _length { length }
        , _width { width } {}*/
    Rectangle(float length, float width);
    Rectangle(float size);
    Rectangle();

    float get_length() const { return _length; }
    float get_width() const { return _width; }

    static void set_default_size(float default_size);

    /*void scale(float ratio) {
        _length *= ratio;
        _width *= ratio;
    }*/
    void scale(float ratio);

private:
    float        _length;
    float        _width;
    static float _default_size;
};

std::ostream& operator<<(std::ostream& stream, const Rectangle& rect);
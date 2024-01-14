#pragma once

class Rectangle
{
public:
    Rectangle(float length, float width)
        : _length { length }
        , _width { width }
    {}

    float get_length() const { return _length; }
    float get_width() const { return _width; }

    void scale(float ratio)
    {
        _length *= ratio;
        _width *= ratio;
    }

private:
    float _length;
    float _width;
};

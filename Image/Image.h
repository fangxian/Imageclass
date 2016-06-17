//
// Created by YuFangxian on 16/6/17.
//

#ifndef IMGE_S_IMAGE_H
#define IMGE_S_IMAGE_H

#include <cstdint>
#include <cassert>
#include <curses.h>
#include "Dim2u.h"
#include "Position2u.h"


namespace Im {

    //incomplete
    //to do..
    template<typename T>
    class Image
    {
    public:
        typedef T ValueType;
        typedef uint32_t SizeType;

        Image(Dim2u dim, ValueType *data) : _width(dim.width), _height(dim.height), _stride(dim.width), _data(data) { };
        Image() :_width(0), _height(0), _stride(0), _data(0) {};

        Image(Dim2u dim, SizeType stride, ValueType *data) :
                _stride(stride), _width(dim.width), _height(dim.width), _data(data) { };
        ~Image() { };

        Dim2u getDimension() const;

        SizeType getIndex(const Position2u &pos) const;
        SizeType getWidth() const;
        SizeType getHeight() const;
        SizeType getStride() const;

        ValueType getPixel(const Position2u &pos) const;
        ValueType* getData() const;

        void setDimension(const Dim2u& dim);
        void setPixel(const Position2u &pos, T val);
        void setData(ValueType* data);

        bool isInImage(const Position2u& pos) const;


    private:
        SizeType _width;
        SizeType _height;
        SizeType _stride;
        ValueType* _data;
    };

    //get the image data
    template<typename T>
    typename Image<T>::ValueType* Image<T>::getData() const
    {
        return _data;
    }

    //get the image dimension, width and height
    template<typename T>
    Dim2u Image<T>::getDimension() const
    {
        Dim2u dim2u;
        dim2u.width = _width;
        dim2u.height = _height;
        return dim2u;
    }

    //get the specify pixel value
    template<typename T>
    typename Image<T>::ValueType Image<T>::getPixel(const Position2u &pos) const
    {
        assert(isInImage(pos));
        return _data[pos.x * _stride + pos.y];
    }

    template <typename T>
    typename Image<T>::SizeType Image<T>::getStride() const
    {
        return _stride;
    }

    template <typename T>
    typename Image<T>::SizeType Image<T>::getHeight() const
    {
        return _height;
    }

    template <typename T>
    typename Image<T>::SizeType Image<T>::getWidth() const
    {
        return _width;
    }

    template <typename T>
    void Image<T>::setData(ValueType *data)
    {
        _data = data;
    }

    template <typename T>
    void Image<T>::setDimension(const Dim2u &dim)
    {
        _width = dim.width;
        _height = dim.height;
        _stride = dim.width;
    }
    //to do
    //set the pixel value
    template <typename T>
    void Image<T>::setPixel(const Position2u &pos, T val)
    {
        assert(isInImage(pos));
        _data[pos.x * _stride + pos.y] = val;
    }

    //to do...
    //get the index of image, get the x axis and y axis
    template <typename T>
    typename Image<T>::SizeType Image<T>::getIndex(const Position2u &pos) const
    {
        assert(isInImage(pos));
        uint32_t index;
        assert(isInImage(pos));
        index = pos.x * _stride + pos.y;
        return index;
    }
    template <typename T>
    bool Image<T>::isInImage(const Position2u &pos) const
    {
        if(pos.x > 0 && pos.x <= _width)
            if(pos.y > 0 && pos.y <= _height)
                return true;
        return false;
    }

}
#endif //IMGE_S_IMAGE_H

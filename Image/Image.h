//
// Created by YuFangxian on 16/6/17.
//

#ifndef IMGE_S_IMAGE_H
#define IMGE_S_IMAGE_H

#include <cstdint>
#include <cassert>
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

        Image(Dim2u dim, T *data) : _width(dim.width), _height(dim.height), _data(data) { };
        Image() :_width(0), _height(0), _data(0) {};

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
        assert(getIndex(pos) < _height * _width);
        return _data[pos.x * _width + pos.y];
    }
    //to do
    //set the pixel value
    template <typename T>
    void Image<T>::setPixel(const Position2u &pos, T val)
    {
        uint32_t stride= getStride();
        _data[pos.x * stride + pos.y] = val;
    }

    //to do...
    //get the index of image, get the x axis and y axis
    template <typename T>
    typename Image<T>::SizeType Image<T>::getIndex(const Position2u &pos) const
    {
        uint32_t index;
        uint32_t stride = getStride();
        index = pos.x * stride + pos.y;
        return index;
    }

}
#endif //IMGE_S_IMAGE_H

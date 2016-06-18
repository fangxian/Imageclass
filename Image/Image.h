//
// Created by YuFangxian on 16/6/17.
//

#ifndef IMGE_S_IMAGE_H
#define IMGE_S_IMAGE_H

#include <cstdint>
#include <cassert>
#include <limits>
#include <string.h>
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

        void generateRNDImage();
        void generateSpecPixelImage(ValueType small, ValueType big);
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

    //get image stride
    template <typename T>
    typename Image<T>::SizeType Image<T>::getStride() const
    {
        return _stride;
    }

    //get the height of image
    template <typename T>
    typename Image<T>::SizeType Image<T>::getHeight() const
    {
        return _height;
    }

    //get the width of the image
    template <typename T>
    typename Image<T>::SizeType Image<T>::getWidth() const
    {
        return _width;
    }

    //copy the data to the image _data
    template <typename T>
    void Image<T>::setData(ValueType *data)
    {
        _data = data;
    }

    //set the width, height and stride
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

    //get the index of image
    template <typename T>
    typename Image<T>::SizeType Image<T>::getIndex(const Position2u &pos) const
    {
        assert(isInImage(pos));
        uint32_t index;
        assert(isInImage(pos));
        index = pos.x * _stride + pos.y;
        return index;
    }

    //judge the position is in the image
    template <typename T>
    bool Image<T>::isInImage(const Position2u &pos) const
    {
        if(pos.x > 0 && pos.x <= _width)
            if(pos.y > 0 && pos.y <= _height)
                return true;
        return false;
    }

    //generate the image data randomly
    template <typename T>
    void Image<T>::generateRNDImage()
    {
        SizeType length = _width * _height;
        uint32_t* buffer = new uint32_t[length];
        ValueType limit_min = std::numeric_limits<ValueType >::min();
        ValueType limit_max = std::numeric_limits<ValueType >::max();
        for(uint32_t i =0; i < length; i++)
        {
            buffer[i] = (rand())%(limit_max-limit_min) + limit_min; //generate pixel value in limit_min~limit_max
        }
        memcpy(_data, (T *)buffer, length);

    }

    //generate the image data which in the section between a and b
    template <typename T>
    void Image<T>::generateSpecPixelImage(ValueType small, ValueType big)
    {
        SizeType length = _width * _height;
        uint32_t* buffer = new uint32_t[length];
        for(uint32_t i =0; i < length; i++)
        {
            buffer[i] = (rand())%(big-small) + small; //generate pixel value in limit_min~limit_max
        }
        memcpy(_data, (T *)buffer, length);
    }

}
#endif //IMGE_S_IMAGE_H

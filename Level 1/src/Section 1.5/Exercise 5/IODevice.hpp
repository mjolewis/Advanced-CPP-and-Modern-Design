//
// Created by Michael Lewis on 6/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_IODEVICE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_IODEVICE_HPP

//Forward declarations
class Circle;
class Line;

/**
 * An abstract interface for concrete IO devices
 */
class IODevice
{
public:
    virtual ~IODevice() = default;

    virtual void operator << (const Circle& source) = 0;
    virtual void operator << (const Line& line) = 0;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_IODEVICE_HPP

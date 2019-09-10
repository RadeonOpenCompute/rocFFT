/*******************************************************************************
 * Copyright (C) 2016 Advanced Micro Devices, Inc. All rights reserved.
 ******************************************************************************/

#ifndef RIDER_H
#define RIDER_H

#include <chrono>

//	Boost headers that we want to use
#define BOOST_PROGRAM_OPTIONS_DYN_LINK
#include <boost/program_options.hpp>

struct Timer
{
    std::chrono::time_point<std::chrono::system_clock> start, end;

public:
    Timer() {}

    void Start()
    {
        start = std::chrono::system_clock::now();
    }

    double Sample()
    {
        end                                   = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        // Return elapsed time in seconds
        return elapsed.count();
    }
};

#endif // RIDER_H

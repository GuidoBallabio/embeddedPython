#pragma once
#include "image_union.h"

#include <fstream>
#include <iostream>

static void Export_CSV(Image data)
{
    std::ofstream f;
    f.open("image_processed.csv", std::ios::out | std::ios::trunc);
    
    if(!f.is_open())
    {
        std::cout << "Failed exporting file, could not open file" << std::endl;
        return;
    }

    for (int i = 0; i < ELEMENTS-1; ++i)
        f << data.vect[i] << ",";

    f << data.vect[ELEMENTS-1] << std::endl;
}

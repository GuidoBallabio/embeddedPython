#pragma once
#include "image_union.h"

#include <fstream>
#include <iostream>

static void Export_CSV(Image data, std::string fileName)
{
    std::ofstream f;
    f.open(fileName, std::ios::out | std::ios::trunc);
    
    if(!f.is_open())
    {
        std::cout << "Failed exporting file, could not open file" << std::endl;
        return;
    }

    for (int i = 0; i < ELEMENTS; i++)
        f << (int) data.vect[i] << std::endl;

}

static void Export_CSV(floatImage data, std::string fileName)
{
    std::ofstream f;
    f.open(fileName, std::ios::out | std::ios::trunc);
    
    if(!f.is_open())
    {
        std::cout << "Failed exporting file, could not open file" << std::endl;
        return;
    }

    for (int i = 0; i < ELEMENTS; i++)
        f << (float) data.vect[i] << std::endl;

}
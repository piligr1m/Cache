//
//  main.cpp
//  LW2
//
//  Created by Stanislav Martynov on 23/09/2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//


#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include "cache.h"

using namespace std;

int main()
{
    int min_kb, max_kb;
    string travel;
    
    
    min_kb = 128;
    max_kb = 6144;
    Cache cache(min_kb, max_kb);
    int directSize, reverseSize, randomSize;
    Cache::Experiment *direct = cache.MakeTest("direct", directSize);
    Cache::Experiment *reverse = cache.MakeTest("reverse", reverseSize);
    Cache::Experiment *random = cache.MakeTest( "random", randomSize);
}

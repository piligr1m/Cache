//
//  cache.h
//  LW2
//
//  Created by Stanislav Martynov on 23/09/2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#include <iostream>
#include <string>
#include <chrono>
#include <cmath>

using namespace std;

class Cache
{
    const int LOOPS = 1000;
    int *buffer;
    int *buff_size;
    int size;
    int KB2Size(int kb); // size
    void initbuffer(int n); // filling the buffer
    void directTest(int n); //direct test
    void reverseTest(int n); // reverse test
    void randomTest(int n); //random test
public:
    struct Experiment
    {
        int id;
        string name;
        double time;
    };
    Cache(int min_kb, int max_kb); // determines how many experiments will be done
    Experiment* MakeTest(string travel, int& experimentsSize); //making tests
};

int Cache::KB2Size(int kb)
{
    return kb * 1024 / sizeof(int);
}

void Cache::initbuffer(int n)
{
    if (buffer != nullptr)
        delete[] buffer;
    buffer = new int[n];
    for ( int i = 0; i < n; i++)
        buffer[i] = rand() % n;
}

void Cache::directTest(int n)
{
    for ( int loop = 0; loop < LOOPS; loop++)
    {
        for ( int i = 0; i < n; i++)
            int v = buffer[i];
    }
}

void Cache::reverseTest(int n)
{
    for ( int loop = 0; loop < LOOPS; loop++)
    {
        for (int i = n - 1; i >= 0; i--)
            int v = buffer[i];
    }
}

void Cache::randomTest(int n)
{
    for ( int loop = 0; loop < LOOPS; loop++)
    {
        for (int i = 0; i < n; i++)
            int v = buffer[rand() % n];
    }
}

Cache::Experiment* Cache::MakeTest(string travel, int &experimentsSize)
{
    cout << "investigation:" << endl;
    cout << "   travel variant: " << travel << endl;
    cout << "   experiments:" << endl;
    experimentsSize = size;
    Experiment *experiments = new Experiment[size + 1];
    for (int i = 0; i < size; i++)
    {
        int n = KB2Size(buff_size[i]);
        initbuffer(n);
        auto start = chrono::high_resolution_clock::now();
        if (travel == "direct") {
            directTest(n);
        }
        else if (travel == "reverse") {
            reverseTest(n);
        }
        else {
            randomTest(n);
        }
        auto finish = std::chrono::high_resolution_clock::now();
        experiments[i].id = i + 1;
        experiments[i].name = travel;
        experiments[i].time = (chrono::duration_cast<chrono::nanoseconds>(finish - start).count() / LOOPS);
        cout << "   - experiment:" << endl;
        cout << "       number: " << (i + 1) << endl;
        cout << "       input data:" << endl;
        cout << "         buffer size: " << buff_size[i] << "KB" << endl;
        cout << "       results:" << endl;
        cout << "         duration: " << (chrono::duration_cast<chrono::nanoseconds>(finish - start).count() / LOOPS) << "ns" << endl;
    }
    cout << endl;
    return experiments;
}

Cache::Cache(int min_kb, int max_kb)
{
    size = log2(max_kb / min_kb) + 3;
    buff_size = new int[size];
    int n = 0;
    min_kb /= 2;
    while (min_kb <= max_kb * 3 / 2)
    {
        buff_size[n++] = min_kb;
        min_kb *= 2;
    }
    buff_size[n++] = max_kb * 3 / 2;
    buffer = nullptr;
    cout << endl << "Buffer sizes: ";
    for (int i = 0; i < n; i++)
        cout << buff_size[i] << " ";
    cout << endl;
}

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

void useBubble(vector<int> vec, double SumTime, double iter)
{
    for(unsigned int i = 0; i < iter; i++)
    {
        vector<int> v = vec;
        // BubbleSort
        chrono::steady_clock::time_point t_beginB = chrono::steady_clock::now();

        BubbleSort(v);

        chrono::steady_clock::time_point t_endB = chrono::steady_clock::now();

        double timeElapsedBubble = chrono::duration_cast<chrono::nanoseconds> (t_endB - t_beginB).count();

        SumTime += timeElapsedBubble;
    }
    double MeanBubble = SumTime/iter;
    cout << "Bubble medium time: " << MeanBubble << " ns" << endl;
}

void useMerge(vector<int> vec, double SumTime, double iter)
{
    for(unsigned int i = 0; i < iter; i++)
    {
        vector<int> v = vec;
        // MergeSort
        chrono::steady_clock::time_point t_beginM = chrono::steady_clock::now();

        MergeSort(v);

        chrono::steady_clock::time_point t_endM = chrono::steady_clock::now();

        double timeElapsedMerge = chrono::duration_cast<chrono::nanoseconds> (t_endM - t_beginM).count();

        SumTime += timeElapsedMerge;
    }
    double MeanMerge = SumTime/iter;
    cout << "Merge medium time: " << MeanMerge << " ns" << endl;
}

int main()
{
    double iter = 100;
    cout << "Insert size of the vector : ";
    size_t dimV;
    cin >> dimV;
    vector<int> v1(dimV);
    cout << endl;

    //First test
    iota(v1.begin(), v1.end() ,dimV);
    double SumTimeBubbleOrdinated = 0;
    double SumTimeMergeOrdinated = 0;

    cout << "Ordinated vectors: " << endl;
    useBubble(v1, SumTimeBubbleOrdinated, iter);
    vector<int> v2 = v1;
    useMerge(v2, SumTimeMergeOrdinated, iter);

    cout << endl;

    //Second test
    reverse(v1.begin(),v1.end());
    double SumTimeBubbleInverted = 0;
    double SumTimeMergeInverted = 0;

    cout << endl;

    cout << "Inverted ordinated vectors: " << endl;
    useBubble(v1, SumTimeBubbleInverted, iter);
    vector<int> v3 = v1;
    useMerge(v3, SumTimeMergeInverted, iter);

    cout << endl;

    //Third test
    vector<int> v4(dimV);
    for(unsigned int i = 0; i < dimV; i++)
    {
        v4[i] = rand()%1000;
    }
    double SumTimeBubbleRandom = 0;
    double SumTimeMergeRandom = 0;

    cout << endl;

    cout << "Random ordinated vectors: " << endl;
    useBubble(v4, SumTimeBubbleRandom, iter);
    vector<int> v5 = v4;
    useMerge(v5, SumTimeMergeRandom, iter);

    cout << endl;

    //Fourth test
    size_t halfDimV = dimV / 2.0;
    vector<int> v6(dimV);
    iota(v6.begin(), v6.end(), halfDimV);
    vector<int> v7(halfDimV);
    for(unsigned int i = 0; i < halfDimV; i++)
    {
        v7[i] = rand()%1000;
    }
    for (unsigned int i = 0; i < halfDimV; i++)
    {
        v6[halfDimV + i] = v7[i];
    }
    // HOHR = Half Ordinated Half Random

    double SumTimeBubbleHOHR = 0;
    double SumTimeMergeHOHR = 0;

    cout << endl;

    cout << "HOHR vectors: " << endl;
    vector<int> v8 = v6;
    useBubble(v6, SumTimeBubbleHOHR, iter);
    useMerge(v8, SumTimeMergeHOHR, iter);

    cout << endl;

    return 0;
}


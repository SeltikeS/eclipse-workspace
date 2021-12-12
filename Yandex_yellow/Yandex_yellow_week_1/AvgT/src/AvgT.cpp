//============================================================================
// Name        : AvgT.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> temp_list;
    int64_t sum = 0;

    for(int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        temp_list.push_back(temp);
        sum += temp;
    }

    int v_size = static_cast<int>(temp_list.size());

    double avg = sum / v_size;

    int k = 0;
    vector<int> numbers;
    for(int i = 0; i < v_size; ++i)
    {
        if(temp_list[i] > avg)
        {
            ++k;
            numbers.push_back(i);
        }
    }

    cout << k << endl;
    for(const auto& item : numbers)
    {
        cout << item << ' ';
    }


    return 0;
}

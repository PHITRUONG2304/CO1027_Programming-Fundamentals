#include <iostream>
#include <string>
using namespace std;


int pascal1(int i, int j)
{
    if (j == 0 || i == j)
        return 1;
    else if (j > i)
        return 0;
    else
        return pascal1(i - 1, j) + pascal1(i - 1, j - 1);
}

int sum(int arr[], int size)
{
    if (size == 0)
        return 0;
    else
        return arr[size - 1] + sum(arr, size - 1);
}

// Ví dụ n = 600
// arr = 50, 100, 20, 200, 500
// size = 5
// số cách có thể trả tiền cho 600. Ví dụ: 6 tờ 100 là 1 cách.
void count(int arr[], int size, int n, int &ways)
{
    if(n == 0) 
        ways++;
    else if(n < 0)
        ways = ways;
    else 
    {
        for(int i=0; i < size; i++)
        {
            count(arr, size, n-arr[i], ways);
        }
    }
}

int Fibonaci(int n)
{
    if (n < 0)
        return 0;
    else if (n == 0 || n == 1)
        return 1;
    else
        return Fibonaci(n - 1) + Fibonaci(n - 2);
}

int takeFibonaciNearest(int maxValue)
{
    int i = 0;
    while (1)
    {
        if (maxValue < Fibonaci(i))
            break;
        i++;
    }
    return Fibonaci(i - 1);
}

int getMax(string events, int length, bool firstly, int &index)
{
    int max = INT_MIN, i = 0, first = 0, last = 0;
    index = -1;
    while (i < length)
    {
        last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;
        if ((max < stoi(events.substr(first, last - first))) && firstly)
        {
            max = stoi(events.substr(first, last - first));
            index = i;
        }
        else if ((max <= stoi(events.substr(first, last - first))) && !firstly)
        {
            max = stoi(events.substr(first, last - first));
            index = i;
        }
        first = last + 1;
        i++;
    }
    
    return max;
}

int getMin(string events, int length, bool firstly, int &index)
{
    int min = INT_MAX, i = 0, first = 0, last = 0;
    index = -1;
    while (i < length)
    {
        last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;

        if (min > stoi(events.substr(first, last - first)) && firstly)
        {
            min = stoi(events.substr(first, last - first));
            index = i;
        }
        else if (min >= stoi(events.substr(first, last - first)) && !firstly)
        {
            min = stoi(events.substr(first, last - first));
            index = i;
        }
        first = last + 1;

        i++;
    }
    
    return min;
}

int meetMushRoomType3(string events, int length)
{
    string changed_events = "";
    int first = 0, last = 0, i = 0;
    int temp_number;
    while (i < length)
    {
        last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;
        temp_number = stoi(events.substr(first, last - first));
        if (temp_number < 0)
            temp_number = -temp_number;
        
        temp_number = (17 * temp_number + 9) % 257;
        changed_events += to_string(temp_number) + ',';

        first = last + 1;
        i++;
    }
    changed_events = changed_events.substr(0, changed_events.length() - 1);
    cout << changed_events << endl;
    int indexMax, indexMin;
    getMax(changed_events, length, true, indexMax);
    getMin(changed_events, length, true, indexMin);

    return indexMax + indexMin;
}

int isMountainPeak(string events, int length)
{
    int indexMaxNumber;
    int maxNumber = getMax(events, length, true, indexMaxNumber);
    int first = 0, last = 0, i = 0;
    int previous;
    if (indexMaxNumber == 0)
    {
        previous = INT_MAX;
        while (i < length)
        {
            last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;
            if(previous <= stoi(events.substr(first, last - first)))
                return -2 + -3;

            previous = stoi(events.substr(first, last - first));
            first = last + 1;
            i++;
        }
        return maxNumber;
    }
    else if (indexMaxNumber == length - 1)
    {
        first = 0, last = 0, i = 0;
        previous = INT_MIN;
        while (i < length)
        {
            last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;
            if(i != 0 && i != (length - 1))
                if(previous >= stoi(events.substr(first, last - first)))
                    return -2 + -3;

            previous = stoi(events.substr(first, last - first));
            first = last + 1;
            i++;
        }
        return length - 1 + maxNumber;
    }
    else
    {
        bool accending = true;

        first = 0, last = 0, i = 0;
        previous = INT_MIN;

        while (i < length)
        {
            last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : events.length();
            if(i != 0)
            {
                if(accending)
                {
                    if(previous >= stoi(events.substr(first, last - first)))
                        return -2 + -3;
                    if (i == indexMaxNumber)
                        accending = false;
                }
                else
                {
                    if(previous <= stoi(events.substr(first, last - first)))
                        return -2 + -3;
                }
            }

            previous = stoi(events.substr(first, last - first));
            first = last + 1;
            i++;
        }
        return maxNumber + indexMaxNumber;
    }
}

int main()
{
    // int index;
    // int result = getMax("1,2,-10,5,6,-8,-10", 7, true, index);
    // cout << "The max value is: " << result << " at: " << index << endl;

    // result = getMin("1,2,-10,5,6,-8,-10", 7, false, index);
    // cout << "The min value is: " << result << " at: " << index << endl;

    // // cout << isMountainPeak("30,10,9,8,7,5,-5", 7) << endl;
    // int arr[2] = {2,4};
    // int number = 0;
    // count(arr, 2, 6, number);
    // cout << "The number of ways: " << number << endl; 

    int a = 10;
    int b = 5;
    int* const pointer_1 = &a;
    const int *pointer_2 = &b;

    pointer_1 = &b;
    *pointer_2 = a;
    // cout << pointer << endl;
    // cout << &a << endl;
    // cout << &pointer << endl;
    return 0;
}
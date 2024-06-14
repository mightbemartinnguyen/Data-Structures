#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void greetings() {
    cout << "Martin Nguyen\t\t\t CIST004B Spring 2023";
    cout << "\n\nMinimum, Maximum, Mean, Median and Mode Calculator\n\n";
    return;
}


int main()
{
    int vectorSize{ 0 }, inputValue{ 0 }, modeIndex{ 0 }, mode{ 0 }, median{ 0 };
    int max = INT_MAX;
    int min = INT_MIN;
    float mean{ 0.0f }, sum{ 0.0f };

    greetings();

    do {
        cout << "How many numbers are in your list (1 to 100)? ";
        cin >> vectorSize;
    } while (vectorSize < 1 || vectorSize > 100);

    vector<int>  numberVector(vectorSize);

    for (int i = 0; i < numberVector.size(); i++) {
        do {
            cout << "For number " << i + 1 << ", enter an integer between 1 and 1000: ";
            cin >> inputValue;
        } while (inputValue < 1 || inputValue > 1000);
        numberVector[i] = inputValue;
    }

    sort(numberVector.begin(), numberVector.end());

    for (int element : numberVector) {
        sum += element;
    }
    mean = sum / static_cast<float>(vectorSize);

    min = numberVector.front();
    max = numberVector.back();
    median = numberVector[vectorSize / 2];

    vector<int> counter(max+1);
  
    for (auto index : numberVector) {
        ++counter[index];
        for (int i{ 0 }; i < max + 1; i++) {
            if (counter[i] > mode) {
                mode = counter[i];
                modeIndex = i;
            }
        }
    }




    cout << "\nThe list of numbers has the following characteristics:";
    cout << "\nThe Minimum is: " << min;
    cout << "\nThe Maximum is: " << max;
    cout << "\nThe Mean is: " << mean;
    cout << "\nThe Median is: " << median;
    cout << "\nThe Mode is: " << modeIndex;
    return 0;
}


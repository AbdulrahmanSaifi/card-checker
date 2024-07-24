#include <iostream>
#include <vector>
using namespace std;

int luhn_algorithm(long long card);

vector<int> intToArray(long long num);

int main()
{
    long long card;
    cout << "*******************" << "\n";
    cout << "  CARD VALIDATION " << "\n";
    cout << "*******************" << "\n";
    cout << " " << "\n";
    cout << "Enter the Card number" << "\n";
    cin >> card;
    int result = luhn_algorithm(card);
    if(result == 1){
        cout << "Is vaild";
    }else{
        cout << "Is Not vaild";

    }
    return 0;
}

int luhn_algorithm(long long card)
{
    vector<int> array = intToArray(card);
    int sum = 0;

    for (int i = array.size() - 1; i >= 0; i--)
    {
        int num = array[i];
        if ((array.size() - 1 - i) % 2 != 0)
        {
            num *= 2;
            if (num > 9)
                num -= 9;
        }
        sum += num;
    }

    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

vector<int> intToArray(long long num)
{
    vector<int> array;
    while (num > 0)
    {
        array.insert(array.begin(), num % 10);
        num /= 10;
    }
    return array;
}

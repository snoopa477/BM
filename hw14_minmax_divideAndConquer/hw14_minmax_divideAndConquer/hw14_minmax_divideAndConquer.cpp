#include <iostream>
#include <vector>
#include <algorithm>    // std::min

using namespace std;

vector<int> min_max(vector<int>& items);
vector<int> min_max(vector<int>& items, int left, int right);

int main()
{
    {
        cout << endl;
        vector<int> items{ 1, 3 ,4, 7 ,5 , 6, 2, 8 };
        vector<int> result = min_max(items);

        cout << "vector: ";
        for (int i = 0; i < items.size(); i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;

        //check before u access indeces
        if (result.size() == 2)
        {
            cout << "min is " << result[0] << "; max is " << result[1] << endl;
        }
        else
        {
            cout << "0 elements to compare!" << endl;
        }
    }


    {
        cout << endl;
        vector<int> items{ 3 ,4, 7 ,5 , 1, 8, 6, 2 };
        vector<int> result = min_max(items);

        cout << "vector: ";
        for (int i = 0; i < items.size(); i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;

        if (result.size() == 2)
        {
            cout << "min is " << result[0] << "; max is " << result[1] << endl;
        }
        else
        {
            cout << "0 elements to compare!" << endl;
        }
    }


    {
        cout << endl;
        vector<int> items{ 99 };
        vector<int> result = min_max(items);

        cout << "vector: ";
        for (int i = 0; i < items.size(); i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;

        if (result.size() == 2)
        {
            cout << "min is " << result[0] << "; max is " << result[1] << endl;
        }
        else
        {
            cout << "0 elements to compare!" << endl;
        }
    }


    {
        cout << endl;
        vector<int> items{ 3 ,4, 7  };
        vector<int> result = min_max(items);

        cout << "vector: ";
        for (int i = 0; i < items.size(); i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;

        if (result.size() == 2)
        {
            cout << "min is " << result[0] << "; max is " << result[1] << endl;
        }
        else
        {
            cout << "0 elements to compare!" << endl;
        }
    }


    {
        cout << endl;
        vector<int> items{ };
        vector<int> result = min_max(items);

        cout << "vector: ";
        for (int i = 0; i < items.size(); i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;

        if (result.size() == 2)
        {
            cout << "min is " << result[0] << "; max is " << result[1] << endl;
        }
        else
        {
            cout << "0 elements to compare!" << endl;
        }
    }

    system("pause");
}



vector<int> min_max(vector<int>& items)
{
    return min_max(items, 0, items.size() - 1);
}



vector<int> min_max(vector<int>& items, int left, int right)
{
    if (left <= right)
    {
        if (left == right)
        {
            //vector<int> result{ items[left], items[right] };
            //return result;
            return vector<int> { items[left], items[right] };
        }
        else
        {
            int middle = left + (right - left) / 2;

            vector<int> min_max_left = min_max(items, left, middle);
            vector<int> min_max_right = min_max(items, middle + 1, right);

            if (min_max_left.size() == 0)
            {
                return min_max_right;
            }
            else if(min_max_right.size() == 0)
            {
                return min_max_left;
            }
            else
            {
                int min = std::min(min_max_left[0], min_max_right[0]);
                int max = std::max(min_max_left[1], min_max_right[1]);

                return vector<int> {min, max };

            }
        }

    }
    else
    {
        //return nullptr;
        return vector<int> { };
    }

}
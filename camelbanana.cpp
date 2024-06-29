#include <iostream>

using namespace std;

int main()
{
    int total;
    int maxCapacity;
    int distance;
    int lose, start, i;

    cout << "Enter no. of bananas at starting : ";
    cin >> total;
    cout << "Enter distance you want camel to cover : ";
    cin >> distance;
    cout << "Enter max load capacity of your camel : ";
    cin >> maxCapacity;

    lose = 0;
    start = total;

    for (i = 0; i < distance; i++)
    {
        while (start > 0)
        {
            start = start - maxCapacity;

            if (start == 1)
            {
                lose = lose - 1;
            }

            lose = lose + 2;
        }
        lose = lose - 1;

        start = total - lose;
        if (start == 0)
        {
            break;
        }
    }

    cout << "\nTotal banana delivered after " << distance << "kms : " << start << endl;
    return 0;
}

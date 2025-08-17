#include <iostream>
using namespace std;

int main()
{
    int a[10][10], n, m;
    cout << "Enter rows and cols: ";
    cin >> n >> m;

    cout << "Enter matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int noOfElements = m * n;
    int count = 0;
    while (count < m * n / 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
                count++;
            }
        }
    }

    cout << "Transpose:\n";
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

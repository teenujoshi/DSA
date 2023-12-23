#include <iostream>
using namespace std;
int Power(int b, int ex)
{
    if (ex == 1)
        return b;
    if (ex == 0)
        return 1;
    return b * Power(b, ex - 1);
}
int main()
{
    int n;
    cout << "enter the degree: ";
    cin >> n;
    int poly[n + 1];
    for (int i = n; i >= 0; i--)
    {
        cout << "coefficient of "<< "n^" << i << ": ";
        cin >> poly[i];
    }
    cout << "polynomial is: " << endl;
    for (int i = n; i >= 0; i--)
    {
        if (poly[i] != 0 && i != 0)
            cout << poly[i] << "n^" << i << " + ";
        if (i == 0)
            cout << poly[0] << endl;
    }
    int input;
    cout << "enter an element of which you find the value: ";
    cin >> input;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int power = Power(input, i);
        power *= poly[i];
        ans += power;
    }
    cout << "The anser is : " << ans << endl;
}
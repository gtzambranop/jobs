#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 0)
       return 1;
    return n * factorial(n - 1);
}

int pw(int a, int b)
{
    int result = a;
    for (int i = a; i < b; i++)
    {
        result *=a;
    }
    return result;
}

void summation(int x, int n)
{
    float total = 0,
        aux = 0,
        a = 0,
        b = 0;
    for(int i = 1; i < n; i++)
    {
        a = pw(-1, i) * pw(x, 2*i);
        b = factorial(2*i);
        aux = a/b;
        total = total + aux;
        cout << "Término " << i << " = " << aux << "\n";
    }
    cout << "La sumatoria es: " << total << "\n";
}


int main()
{
    int x;
    int n;
    cout << "\tIngrese el valor de la variable X:\t";
    cin >> x;
    cout << "\tIngrese la cantidad N de términos que desea ver:\t";
    cin >> n;

    summation(x, n);

    return 0;
}

/*
f2(){

}

f1(){
    f2()
}

main()
*/
#include <iostream>
using namespace std;
class polynominal
{
private:
    int p[30][2];

public:
    polynominal()
    {
        for (int i = 0; i < 30; i++)

        {
            p[i][0] = 0;
            p[i][1] = 0;
        }
    }
    void get()
    {
        int i = 0, j = 0;
        while (1)
        {
            cout << " Enter a and b for ax^b: ";
            cin >> i >> j;
            if (i == 0 && j == 0)
                break;
            else if (j < 0)
                cout << endl
                     << "b < 0 please try again!";
            else
            {
                p[j][0] = i;
                p[j][1] = j;
            }
        }
    }
    void print()
    {
        for (int i = 30; i > 0; i--)
        {
            if (p[i][0] != 0)
                cout << p[i][0] << "x^" << p[i][1];
            if (p[i - 1][0] > 0)
                cout << " + ";
        }
        if (p[0][0] != 0)
            cout << p[0][0] << endl;
    }

    polynominal operator+(polynominal &ref);
    polynominal operator-(polynominal &ref)
    {
        polynominal s;
        for (int i = 0; i < 30; i++)
        {
            s.p[i][0] = p[i][0] - ref.p[i][0];
            s.p[i][1] = i;
        }
        return s;
    }
    polynominal &operator=(polynominal &ref);
    friend polynominal operator*(polynominal &s1, polynominal &s2);
    int operator==(polynominal &ref)
    {
        for (int i = 0; i < 30; i++)
        {
            if (p[i][0] == ref.p[i][0] && p[i][1] == ref.p[i][1])
                return 1;
            return 0;
        }
    }
    polynominal operator+=(polynominal &ref)
    {
        for (int i = 0; i < 30; i++)
        {
            p[i][0] += ref.p[i][0];
            p[i][1] = i;
        }
        return *this;
    }
    polynominal operator-=(polynominal &ref)
    {
        for (int i = 0; i < 30; i++)
        {
            p[i][0] -= ref.p[i][0];
            p[i][1] = i;
        }
        return *this;
    }
};
polynominal polynominal::operator+(polynominal &ref)
{
    polynominal s;
    for (int i = 0; i < 30; i++)
    {
        s.p[i][0] = p[i][0] + ref.p[i][0];
        s.p[i][1] = i;
    }
    return s;
}

polynominal operator*(polynominal &s1, polynominal &s2)
{
    polynominal s;
    for (int i = 0; i < 30; i++)
    {
        s.p[i][0] = s1.p[i][0] * s2.p[i][0];
        s.p[i][1] = s1.p[i][1] + s2.p[i][1];
    }
    return s;
}
polynominal &polynominal::operator=(polynominal &ref)
{

    for (int i = 0; i < 30; i++)
    {
        p[i][0] = ref.p[i][0];
        p[i][1] = ref.p[i][1];
    }
    return *this;
}

int main()
{
    polynominal r1, r2;
    r1.get();
    cout << "\n\n\n";
    r2.get();
    polynominal r3 = r1 + r2;
    cout << "r1+r2=" << endl;
    cout << "(";
    r1.print();
    cout << ")+(";
    r2.print();
    cout << ")=";

    r3.print();
    cout << endl;
    polynominal r4 = r1 - r2;
    cout << "r1-r2=" << endl;
    cout << "(";
    r1.print();
    cout << ")-(";
    r2.print();
    cout << ")=";

    r4.print();
    cout << endl;
   polynominal  y = r1 * r2;
    cout << "r1*r2=" << endl;
    cout << "(";
    r1.print();
    cout << ")*(";
    r2.print();


    cout << ")=";

    y.print();
    cout << endl;
    r3 = r1;
    r1 += r2;
    cout << "r1+=r2" << endl;
    cout << "(";
    r3.print();
    cout << ")+=";
    r2.print();
	 cout<<"--------->";
    r1.print();
    cout << endl;
    r1 = r3;
    r1 -= r2;
    cout << "r1-=r2" << endl;
    cout << "(";
    r3.print();
    cout << ")-=(";
    r2.print();
    cout << "=======>>";

    r1.print();

    cout << endl;
    return 0;
}




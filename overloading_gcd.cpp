#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
     if (b==0)
            return a;
    else
        return gcd(b, a%b);
}
class Fraction{
private:
    int sorat;
    int makhraj;

public:
    Fraction(int a=0, int b=1)
    {
        this->sorat=a;
        if(b==0)
        {
            cout<<"Cannot Assainment Zero to Domenator\n";
            this->makhraj=1;
        }
        else
        {
            this->makhraj=b;
        }
    }

    friend int gcd(int a, int b);
void simplify()
{
  int com=gcd(sorat,makhraj);
  this->sorat/=com;
  this->makhraj/=com;
}
Fraction operator +(const Fraction & other)
{
    Fraction Result;
    Result.sorat=sorat*other.makhraj+other.sorat*makhraj;
    Result.makhraj=makhraj*other.makhraj;
    Result.simplify();

    return Result;
}
Fraction operator -(const Fraction & other)
{
    Fraction Result;
    Result.sorat=sorat*other.makhraj-other.sorat*makhraj;
    Result.makhraj=makhraj*other.makhraj;
    Result.simplify();
}
friend ostream & operator <<(ostream & out,const Fraction & Frac)
    {
        out<<Frac.sorat<<"/"<<Frac.makhraj<<endl;
        return out;
    }
};
int main()
{
   Fraction F1(3,7);
   Fraction F2(8,3),F3;
   F1.simplify();
   cout<<F1;
}

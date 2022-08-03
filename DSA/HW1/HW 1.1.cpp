#include <iostream>
#include <cmath>
using namespace std;

double S_A(double a,double d,double n);
double S_G(double a,double r, double d);
double S_I_G(double a,double r);

struct  Z
{
	double X;
	double Y;
};
Z display(Z b)
{
	cout<<"{ "<<b.X<<","<<b.Y<<" }"<<endl;
	return b;
}
int main()
{
	int c;
	double ans1,ans2;
	double a=3,d=4,r=5,n=6;
    cout<<"Sum of Arithmetic series: "<<S_A(a,d,n)<<endl;
	cout<<"Sum of Geometric series:  "<<S_G(a,r,n);
	cout<<"\nSum of Infinite Geometric series:  "<<S_I_G(a,r)<<endl;
	ans1=S_G(a,r,n);
	ans2=S_I_G(a,r);
	struct Z p;
	p.X=ans1;
    p.Y=ans2;
    p=display(p);
     	
}

double S_A(double a,double d,double n)
{
	return (n/2)*(2*a+(n-1)*d);
}
double S_G(double a,double r,double n)
{
	double s,s1;
	if(r>1)
	{
	    s=(a*(pow(r,n)-1 ))/(r-1);
		return s;
	}
	else if (r<1)
	{
		s1=(a*(1-pow(r,n)))/(1-r);
		return s1;
	}
}
double S_I_G(double a,double r)
{
	if(r>1)
	{
	    return a/(r-1);
	}
	else if (r<1)
	{
		return a/(1-r);
	}
		
}


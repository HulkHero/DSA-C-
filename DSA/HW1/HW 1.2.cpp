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
	double a,d,r,n,a1,r1;
	char t='y';
	do
	{
	cout<<"Enter 1 for Arthimatic sum\n";
	cout<<"Enter 2 for Geometeric sum\n";
	cout<<"Enter 3 for Infinite Geometeric sum\n";
	cout<<"Enter 4 for function that returns struct \n";
	cin>>c;
	
	if(c==1)
	{
		cout<<"Enter the values of a,d,n respectively\n";
		cin>>a>>d>>n;
		cout<<"Sum of Arithmetic series: "<<S_A(a,d,n)<<endl;
	}
	else if (c==2)
	{
		cout<<"Enter the values of a,r,n \n";
	    cout<<"r should be greater or less than 1\n";
		cin>>a>>r>>n;
		cout<<"sum of Geometric series:  "<<S_G(a,r,n)<<endl;
		
	}
	else if (c==3)
	{
		cout<<"Enter the value a,r \n";
		cout<<"r should be greater or less than 1\n";
		cin>>a>>r;
		cout<<"Sum of infinite Geometric series:  "<<S_I_G(a,r)<<endl;
	}
	else if (c==4)
	{
		cout<<"\nEnter the values of a,r,n,for geometric sum \n";
		cin>>a>>r>>n;
		cout<<"Enter the values of a,r for infinite geometric sum \n";
		cin>>a1>>r1;
		ans1=S_G(a,r,n);
	    ans2=S_I_G(a1,r1);
		struct Z p;
	    p.X=ans1;
     	p.Y=ans2;
     	p=display(p);
	}
	else
	{
		cout<<"Invalid input.Enter 1,2,3 or 4 for respective functions";
	}
	cout<<"\nEnter y for another calculation"<<endl;
	cin>>t;
} while( t='y');

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


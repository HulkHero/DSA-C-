# include <iostream>
# include <new> 
using namespace std;
struct matrix
{
	int r,c,*p3;
};
void input_data(int r,int c,  int *p3);
void print(int r,int c,  int *p3);
double det(int r1,int *p1);
matrix m_m(int r1,int c1,int r2,int c2,int *p1,int *p2 )
{
	matrix mat;
	try 
	{
		if((c1==r2)) //to check if muliplication possible
		{
			mat.r = r1;
			mat.c = c2;
			mat.p3 =  new int [r1 * c2]; //allocates space=r1*c2 in memory e-g(2*2 it will allocate space of 4 intergers which is 01-17 i-e 01,05,09,0D,11;)
			int a,b,c,sum;
			for(int i=0;i<r1;++i)
			{
				for (int j =0;j<c2;++j)
				{
					sum=0;
					for (int k=0;k<c1;++k)
					{
						a = *(p1+ i*c1 + k);   //loop 1;i=0,j=0,k=0,sum=0 a=(01+0+0),b=(01+0+0)...X11*Y11 take place 
						b = *(p2+ k*c2 + j);  // loop 1.01;i=0,j=0,k=1,sum=X11*Y11 a=(01+0+1*(4))=05,b=(01+1*2*(4) + 0)=09;...X12*Y21 take place
						sum+=a*b;	             //now sum =X11*Y11+X12*Y21;...loops will go on like this
					}
                	*(mat.p3 + i*c2 +j)=sum;    //first loop  contents of address(01+0+0)=01 will be updated to value of sum; e-g sum=4; *(01)=4;
				}                              //in other words if sum=20, 20 will updated to content of address(01+0+0);
			}
		}
		else throw (c1);	
	}
	catch (...)
	{
	    cout<<"\nColumn of matrix X is not equall to Row of matrix Y ,so multiplication not possible\n";
		mat.c= 0;
		mat.r = 0;
		mat.p3=NULL;
	}
	return mat;
}
double det(int r1,int *p1)
{
	double ans=0,inner_sol, inner_det;
	int X11,X12,X21,X22;
	if((r1==1)or(r1==2))  //if order of X matrix is 1 or 2 easy(following) way is used
	{
		if (r1==1)
		ans=*p1;   //ans= contents of location/address of p1;
		else
		{
			X11=*p1;        //(01)
			X12=*(p1+1);    //(05)   
			X21=*(p1+2);    //(09)
			X22=*(p1+3);    //(D)
			ans=(X11*X22)-(X21*X12);  
		}
		
	}
	else
	{
		int l,sign,basic,element;
		int n=0;
		sign=  +1;
		int *h;
		h=new int [(r1-1)*(r1-1)];   //allocates space in memory
		for (int i=0;i<r1;i++)
		{
			l=0; //l variable allow to move the elements of outer matrix one by one
			n=0;  //to move from element to other one by one in inner matrix
			basic=*(p1+i); //in case 3 by 3 matrix ,basic =a11(in firt iteration),a12(2nd iteration),a13(in 3rd iteration);
			for(int j=0;j<r1;j++)
			{
				for(int k=0;k<r1;k++)
				{
					element=*(p1+l);
					if ((j==0)or (i==k));//discarding rows and columns
					else
					{
						*(h+n)=element;  //contents of address h+n will be updated to element;
						n=n+1;	
					}
					l=l+1;
				}
				
			}
			inner_det=det((r1-1),h);  //recursive call, passing a smaller matrix
			inner_sol=sign*basic*inner_det; 
			ans=ans + inner_sol;
			sign=sign * -1;   
		}
		delete []h;
		
	}
		return ans;	
}   
void input_data(int r,int c,  int *p)
{
    int k;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
		{ 
			cin>>k;
			*(p+ i*c +j)=k;    //loop 1;i=0,j=0; contents of this adress (01+0+0)=01 are updated to value of k; e-g k=2 then *(01)=2;
 		}                      // loop1.1;i=0,j=1; contents of address(01 +0 + 1*(4))=05 are updated to k;
	}
	return;	
}
void print(int r,int c,  int *p)
{
	for(int i=0;i<r;i++)
	{
		cout<<"[ ";
		for(int j=0;j<c;j++)
		{
			cout<<*p<<" ";
			p=p+1;               //incrementing pointer  01,05,09,0D...;
		}
		cout<<"]"<<endl;
	}
    return;
}
int main()
{
	int r1,c1,r2,c2, *p1, *p2;
	string name;
	cout<<"Dear user, please enter your name \n";
	cin>>name;
	cout<<"\nDear "<<name<<", please enter the dimensions of X matrix \n";
	cin>>r1>>c1;
	cout<<"\nDear "<<name<<", please enter the contents of X matrix\n";
	p1 = new int [r1*c1];  //allocates space in memory=r1*c1*4,4 because of int, allocates p the address of 0th index
	input_data( r1,c1,p1);
	cout<<"\nDear "<<name<<", matrix X is:\n";
	print(r1,c1,p1);
	cout<<"\nDear "<<name<<", please enter the dimensions of Y matrix\n";
	cin>>r2>>c2;
	p2 = new int [r2*c2];
	cout<<"\nDear "<<name<<", please enter the contents of Y matrix "<<endl;
	input_data( r2,c2,p2);
	cout<<"\nDear "<<name<<" , matrix Y is:"<<endl;
	print(r2,c2,p2);
	matrix mat; // mat is an object of type matrix
	cout<<"\nDear"<<name<<" , Z = X * Y matrix:\n";
	mat = m_m(r1,c1,r2,c2,p1,p2);
	print(mat.r, mat.c, mat.p3);
	if(r1==c1)
	{
		cout<<"\nZ=det(X)=  "<<det(r1,p1);
	}
	else
	{
		cout<<"\nX is not a square matrix,so determinant is not possible";
	}
	// deleting dangling pointers
	delete [] p1;
	delete [] p2;
	delete [] mat.p3;
	return 0;	
}


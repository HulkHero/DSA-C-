# include <iostream>
# include <new> 
# include <fstream>
# include <cstring> 
# include <cmath> 
using namespace std;
struct matrix
{
	int r,c,*p3;
	double *p4;
};
double det(int r1,int *p1);
void print(int r,int c,auto *p,ofstream &write);
matrix m_m(int r1,int c1,int r2,int c2,int *p1,int *p2,ofstream &write)
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
	    write<<"\nColumn of matrix X is not equall to Row of matrix Y ,so multiplication not possible\n";
		mat.c= 0;
		mat.r = 0;
		mat.p3=NULL;
	}
	return mat;
}
matrix m_a(int r1,int c1,int r2,int c2,int *p1,int *p2,ofstream &write)
{
	matrix m2;
	try 
	{
		if((r1==r2)&&(c1==c2))
		{
			m2.c = c1;
			m2.r = r1;
			m2.p3 =  new int [r1*c1];   //allocates space 
			int i,j,a,b,c;
			for (i=0;i<r1;i++)
			{
				for (j=0;j<c1;j++)
				{
				a = *(p1+ i*c1 +j);      //first iteration a=01;
				b = *(p2+ i*c1 +j);      //b=01;
				c = a+b;                      //addition   a+b
				 *(m2.p3+ i*c1 +j)=c;	       // value of c will be updated to content of address(01+0+0)...first loop
				}
			}
		}
	else throw (r2);	
	}
	catch (...)
	{
		
	    write<<"\ndimensions are not same,so addition  not possible\n";
		m2.c= 0;
		m2.r = 0;
		m2.p3=NULL;
	}
	return m2;
}
matrix transpose(int r1,int c1,int *p1)
{
	matrix mat3;
	mat3.c = c1;
	mat3.r = r1;
	mat3.p3 = new int[mat3.r * mat3.c];
	int  a;
	for (int i = 0; i<r1; i++) 
	{
		for (int j = 0; j<c1; j++)
		{
            a=*(p1+i*c1+j);                  
			*(mat3.p3 + j*r1 + i) = a;  
		}
	}
    return mat3;
}
matrix file_read(ifstream &read,int &r,int &c,char *file)
{
	matrix mat;
	if(!read)
	{
		cout<<file<<"file not opened";
		
	}
	else
	{
		int number;
		string s;
		r = 0; 
		c = 0;
		while (getline(read,s))
		{                              // to find the number of rows and columns
			c = 0;
			for (int i = 0; i < s.length(); i++)   
			{
				if (s[i] != ' ')
				{
					c++;
				}
			}
			r++;
		}
		read.close();
		read.open(file);
		mat.c=c;
		mat.r=r;
		mat.p3=new int [r*c];  
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
			read>>number;                   //data from file will be stored in number,with each iteration
			*(mat.p3+i*c+j)=number;         //value of number will be updated to (mat.p3+i*c+j)
		    }
		}
	}
    return mat ;
}
matrix inverse(int r, int c, int *p1)
{
	matrix mi;
	mi.r = r;
	mi.c = c;
	mi.p3 = new int [r * c];
	{
		if (r == 2 && c== 2) //for matrix of order 2
		{
			*(mi.p3) = *(p1 + 3);
			*(mi.p3 + 1) = *(p1 + 1) * (-1);
			*(mi.p3 + 2) = *(p1 + 2) * (-1);
			*(mi.p3 + 3) = *(p1);
		}
		else
		{                         //for matrix of order greater than 2
			int *p;
			p = new int [(r-1) * (r-1)];
			int i, j, k, l;
			for (i = 0; i < r; i++)
			{
				for (j = 0; j < c; j++)
				{
					int g = 0;
					int n = 0;
					for (k = 0; k < r; k++)
			        {
				        for (int o= 0;l<c; o++)
				        {
					        int element = *(p1 + g);
							if ((j == o) or (i == k));   //discarding rows and columns
					        else
					        {
					        	*(p+ n) = element;
					        	n++;
							}
							g++;
				        }
			        }
			        int sign = pow (-1, (i +1) + (j + 1));
			        double value = sign * det ((r-1), p);   //passing a smaller matrix
			        *(mi.p3 + i*c + j) = value;
		        }
	        }
	        mi = transpose(mi.r, mi.c, mi.p3);       //transpose of adjoint
	    }
    }
    double determinent = det (r, p1);  
    matrix inverse;
    inverse.r = mi.r;
    inverse.c = mi.c;
    inverse.p4 = new double [inverse.r * inverse.c];
    int i, j;
	for (i = 0; i < mi.r; i++)
	{
		for (j = 0; j < mi.c; j++)
		{
	        double value = (*(mi.p3 + i*c + j)/determinent);    
	        *(inverse.p4 + i*c + j) = value;         
	    }
	}
	return inverse;
}

int main(int argc,char * argv[])
{
	try
	{
	    if ( argc != 4)
		throw (argc);
		else
		{
			char *X_file,*Y_file,*output;
			X_file=argv[1];
			Y_file=argv[2];
			output=argv[3];
			ofstream write; 
			write.open(output); //open output file
	        //reading X file
			int r1=0,c1=0,*p1;
    		matrix m1;
			ifstream read;
			read.open(X_file);
		    m1=file_read(read,r1,c1,X_file);
			read.close();
			p1=new int [r1*c1];
			write<<"Matrix X is: \n";
			for(int i=0;i<r1;i++)
			{
				for (int j=0;j<c1;j++)
				*(p1+i*c1+j)=*(m1.p3+i*c1+j);
			}
			delete [] m1.p3;
			print(r1,c1,p1,write);
			//reading Y matrix;
			matrix m9;
			int r2=0,c2=0,*p2;
			ifstream reade;
			reade.open(Y_file);
			m9=file_read(reade,r2,c2,Y_file);
			reade.close();  //closing Y_file
			p2=new int [r2*c2];
			for(int i=0;i<r2;i++)
			{
				for(int j=0;j<c2;j++)
				*(p2+i*c2+j)=*(m9.p3+i*c2+j);
			}
			delete [] m9.p3;
			write<<"\nMatrix Y is: \n";
			print(r2,c2,p2,write);
			//determinant
			if(r1==c1)
			{
				write<<"\nZ=det(X)=  "<<det(r1,p1);
			}
			else
			{
				write<<"\nX is not a square matrix,so determinant is not possible\n";
			}
			//multiplication
			matrix mat;
			mat=m_m(r1,c1,r2,c2,p1,p2,write);
			write<<"\nZ=X*Y is: \n";
			print(mat.r,mat.c,mat.p3,write);
			//addition
			matrix m2;
			write<<"\nZ=X+Y is:\n";
			m2=m_a(r1,c1,r2,c2,p1,p2,write);
			print(m2.r,m2.c,m2.p3,write);
		    //transpose of X
			matrix mat3;
			mat3=transpose(r1,c1,p1);
			write<<"\nTranspose of matrix X is:\n";
			print(mat3.c,mat3.r,mat3.p3,write); //passing columns in place of rows and vice verse to change the order for transpose
			//inverse
			double dete=det(r1,p1);
			if((dete!=0)and(r1==c1))
			{
				matrix in;
				write<<"\nInverse of matrix X is:\n";
				in=inverse(r1,c1,p1);
				print(in.r,in.c,in.p4,write);
			}
			else
			{
				write<<"inverse not possible\n";
				
			}
		    cout<<"Dear,user output stored in file output.txt";
			write.close();   //closing the output file
			//deleting dangling pointers
			delete [] p1;
			delete [] p2;
			delete [] mat3.p3;
			delete [] mat.p3;
			}
		}
	catch(...)
    {
		cout<<"Dear user this program needs four inputs\n";
		cout<<"[1] program.exe\n";
		cout<<"[2] Name of file containing matrix X: for example, X.txt or input_1.txt or matrix_1.txt\n";
		cout<<"[3] Name of file containing matrix Y: for example, Y.txt or input_2.txt or matrix_2.txt\n";
		cout<<"[4] Name of output file: for example, output.txt or out.txt\n";
		cout<<"[-] program.exe X.txt Y.txt output.txt";
	}
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
			sign=sign * -1;  	 //alternating signs
		}
		delete []h;
	}
	return ans;	
} 
void print(int r,int c,auto *p,ofstream & write)  
{
	for(int i=0;i<r;i++)
	{
		write<<"[ ";
		for(int j=0;j<c;j++)
		{
			write<<*p<<" ";   //write will write/input the content of p
			p=p+1;             // with iterations p=01,05,09,D...
		}
		write<<"]"<<endl;
	}
	return;
}

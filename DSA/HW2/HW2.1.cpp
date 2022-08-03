#include <iostream>
#include <cstring>
using namespace std;
struct student
{
	string name;
	double m_math;
	double m_chem;
	double m_phy;
	
};
void calculate_avg (int n,student students[]); 
void bubble_sort(int n,student students[]);
void input_data(int len,student students[]);
int main()
{
	student students[10];
	int len=10;
    input_data(len,students);
    calculate_avg (len,students);
    bubble_sort(len,students);
    return 0;
}
void input_data(int len,student students[])
{
	cout<<"Please input the names and marks of 10 students"<<endl;
	for (int i=0;i<len;i++)
	{
		cout<<"Name "<<i+1<<" : ";
		cin>>students[i].name;
		cout<<"["<<i+1 <<".1] "<<students[i].name<<"-Math marks: ";
		cin>>students[i].m_math;
		cout<<"["<<i+1<<".2] "<<students[i].name<<"-Chemistry marks: ";
		cin>>students[i].m_chem;
		cout<<"["<<i+1<<".3] "<<students[i].name<<"-Physics marks: ";
		cin>>students[i].m_phy;
		cout<<endl;	
	}
}
void calculate_avg(int n,student students[])
{
	cout<<"\nThe combined average of the three courses for 10 studentss is as follows: \n";
	double a_math=0;
	for(int i=0;i<n;i++)
	{
		a_math=a_math+students[i].m_math;
	}
    cout<<"Math: "<<a_math/n<<endl;
    
    double a_chem=0;
	for(int i=0;i<n;i++)
	{
		a_chem=a_chem+students[i].m_chem;
		
	}
    cout<<"Chemistry: "<<a_chem/n<<endl;
    
    double a_phy=0;
	for(int i=0;i<n;i++)
	{
		a_phy=a_phy+students[i].m_phy;
		
	}
    cout<<"Physics: "<<a_phy/n<<endl;
	
}
void bubble_sort(int n,student students[])
{
	
	string temp;
	double temp1,temp2,temp3;
	for(int i=0;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
        if(students[i].name>students[j].name)
        {
            temp=students[i].name;
            students[i].name=students[j].name;
            students[j].name=temp;
                
            temp1=students[i].m_math;
            students[i].m_math=students[j].m_math;
            students[j].m_math=temp1;
                
            temp2=students[i].m_chem;
            students[i].m_chem=students[j].m_chem;
            students[j].m_chem=temp2;
                
            temp3=students[i].m_phy;
            students[i].m_phy=students[j].m_phy;
            students[j].m_phy=temp3;
            }
        }

    }
    cout<<"\nMarks sheet for spring 2021\n";
   	for(int i=0;i<n;i++)
	{
		cout<<"["<<i+1<<"] "<<students[i].name<<": math("<<students[i].m_math<<") chemistry("<<students[i].m_chem;
		cout<<") physics("<<students[i].m_phy<<") \n"<<endl;

	}
	
}

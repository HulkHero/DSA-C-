#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
struct student
{
	string name;
	float m_math;
	float m_chem;
	float m_phy;
	
};

void bubble_sort(int len,student *ptr[]);
void input_data(int len,student *ptr[]);
void print_data(int len,student *ptr[]);
int main()
{

	int len=10;
	student students[10];
	student *ptr[10];
	for(int i=0;i<10;i++)
	{
		ptr[i]=&students[i];
	}
    input_data(len,ptr);
    cout<<endl<<setw(80)<<"UNSORTED marks sheet of spring 2021\n";
    for(int i=0;i<len;i++)
	{
		cout<<"["<<i+1<<"] "<<ptr[i]->name<<": math("<<ptr[i]->m_math<<") chemistry("<<ptr[i]->m_chem;
		cout<<") physics("<<ptr[i]->m_phy<<") \n"<<endl;

	}
    bubble_sort(len,ptr);
    print_data(len,ptr);
    return 0;
}
void input_data(int len,student *ptr[])
{
	cout<<setw(85)<<"Please input the names and marks of 10 students\n"<<endl;
	for (int i=0;i<len;i++)
	{
		cout<<"Name "<<i+1<<" : ";
		cin>>ptr[i]->name;
		cout<<"["<<i+1 <<".1] "<<ptr[i]->name<<"-Math marks: ";
		cin>>ptr[i]->m_math;
		cout<<"["<<i+1<<".2] "<<ptr[i]->name<<"-Chemistry marks: ";
		cin>>ptr[i]->m_chem;
		cout<<"["<<i+1<<".3] "<<ptr[i]->name<<"-Physics marks: ";
		cin>>ptr[i]->m_phy;
		cout<<endl;	
	}
}

void bubble_sort(int len,student *ptr[])
{
	
	string temp;
	float temp1,temp2,temp3;
	for(int i=0;i<len;i++)
    {
    	for(int j=i+1;j<len;j++)
    	{
        if(ptr[i]->name>ptr[j]->name)
        {
            temp=ptr[i]->name;
            ptr[i]->name=ptr[j]->name;
            ptr[j]->name=temp;
                
            temp1=ptr[i]->m_math;
            ptr[i]->m_math=ptr[j]->m_math;
            ptr[j]->m_math=temp1;
                
            temp2=ptr[i]->m_chem;
            ptr[i]->m_chem=ptr[j]->m_chem;
            ptr[j]->m_chem=temp2;
                
            temp3=ptr[i]->m_phy;
            ptr[i]->m_phy=ptr[j]->m_phy;
            ptr[j]->m_phy=temp3;
            }
        }
    }
}
void print_data(int len,student *ptr[])
{
	cout<<setw(79)<<"SORTED marks sheet of spring 2021\n"<<endl;
	for(int i=0;i<len;i++)
	{
		cout<<"["<<i+1<<"] "<<ptr[i]->name<<": math("<<ptr[i]->m_math<<") chemistry("<<ptr[i]->m_chem;
		cout<<") physics("<<ptr[i]->m_phy<<") \n"<<endl;

	}
	
	
	
	
	
}

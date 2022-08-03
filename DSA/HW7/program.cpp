#include <iostream>
#include <new>
#include <fstream>
#include <cstring>
using namespace std;
struct node           
{
	int num;
	node * next;	
};
node *start=NULL;
int len=0;
void file_reading(ifstream &read);  //declaring fucntions
void create(int n);
void add(int n);
int choice ();
void add_node(int s);
void deleting (int n);
void lenght();
void traverse ();
void traverse_writing(ofstream &write);
int main(int argc,char *argv[])
{
	try
	{
		if(argc!=2) throw(2);
		else
		{
			char *input;
			input=argv[1];
			int n,x;
			ifstream read;   //opening input file
			read.open(input);
			file_reading(read);
			read.close();
			cout<<"\nlinked list created\n";
			traverse();
			bool f=true;
			do{
				n=choice();
				if(n==1)
				{
					cout<<"\nenter the number,you want to add\n"; //to add a node
					cin>>x;
					cout<<"User: "<<x; 
					add_node(x);
					traverse();
				}
				else if(n==2)
				{
					cout<<"enter the number to delete \n"; //to delete a node
					cin>>x;
					cout<<"User: "<<x;
					deleting(x);
					traverse();
				}
				else if(n==3)
				{
			    	traverse();     //enumerate
				}
				else if(n==4)
				{
					lenght(); //length of list
				}
				else if(n==5)
				{
					ofstream write;                    //opening output file
					write.open("output.txt");
					cout<<"list printed in the output file"<<endl;
					traverse_writing(write);             //writing in the ouput file;
					write.close();           //closeing file
					f=false;
					return 0;
				}
				cout<<"\nwhat you want to do next;\n";    
			}while(f=true);
		}
	}
	catch(...)
	{
		cout<<"Dear User, the program requires two inputs\n";
		cout<<"[1] program.exe\n";
		cout<<"[2] Name of file containing list of numbers: for example, input.txt or file.txt\n";
		cout<<" E.g: program.exe input.txt\n";
	}
}
void file_reading(ifstream &read)
{
	int n;
	while(read>>n)              //reading from file
	{
		if(len==0)
		{
			create(n);          //to create the first node
		}
		else
		{
			add(n);           //to add the nodes in the list
		   
		}	
	}
}
void create(int n)
{
	if(len==0)    
	{
		start=new node;                   //creating first node and initializing start
		start->num=n;
		start->next=NULL;
	    len++;                          
	}
	else
	{
		cout<<"list is not empty,try add \n";
		
	}
}
void add(int n)                
{
	try
	{
		if(len==0) throw(n);
		else
		{
		node *a;
		a=start;
		while(a->next!=NULL)
		{
			a=a->next;               //travsersing the list till the end 
		}
		node *b;                     	//adding node at the end of list
		b=new node;
		b->num=n;
		b->next=NULL;
		a->next=b;
		len++;                    //incrementing the lenght of list
		}
	}
	catch(int n)
	{
		cout<<"list is empty,try create\n";
	}
	return;
}
int choice ()   //asking for user choice
{ 	
	int option;
	cout<<"Dear user,Options are : \n[1] ADD \n[2] DELETE \n[3] Enumrate \n[4] Length \n[5] stop the process and print the list in file \nUser: ";
	cin>>option;
	cout<<endl;
	return option;
}
void traverse ()
{
	try
	{
		if (len == 0)
		throw(1);
		else
		{
			cout<<"\nlinked list : \n";
			node *a;
			a = start;
			int i=1;
			while(a->next!=NULL)
			{
				cout<<"["<< i <<"]: "<<a->num<<endl;        //printing the list
				a=a->next;                                  //travsersing through the list till it reachers last node
				i=i+1;
			}
			cout<<"["<< i <<"]: "<<a->num<<endl;	 	// to print the last node value
		}
	}
	catch(...)
	{
		cout<<"List is empty\n";
	}
	return ;
}
void add_node(int s)                 //function to insert the node in the linked list with sorting
{
	node *a,*newp;
	a=start;
	newp=new node;
	newp->num=s;
	if(start->next==NULL || s<start->num)   //if s is less than the first node value
	{
		newp->next=start;
		start=newp;
	}
	else
	{
		while(a->next!=NULL and a->next->num<s)    //if s is greater than the first node value
		{
			a=a->next;            
		}
		newp->next=a->next;
		a->next=newp;
		len=len+1;                     //incrementing lenght of list
	}
	cout<<"\n"<<s<<" added\n";      
}
void deleting (int n)      //function to delete the node from the list
{
	if(len == 0)
	cout<<"List is empty,Nothing is to delete\n";
	else
	{
		node *c , *p;
		c = start;
		while ((c->next!= NULL)&&(c->num!= n))
		{
			p= c;
			c= c-> next;
		}
		if (c-> num = n)
		{
			if (c==start)               //delete the first node
				start = c-> next;
			else
				p->next = c->next;
			delete c;
			len = len - 1;
		}
		else 
		{
			cout<<"Node with value " << n << " not found. There's nothing to delete" << endl;
		}
	}
	return;
}
void lenght()        
{
	cout<<"lenght of the linked list is: "<<len;
}
//writing in the output file
void traverse_writing(ofstream &write)
{
	try
	{
		if (len == 0)
		throw(1);
		else
		{
			write<<"list is : \n";
			node *a;
			a = start;
			int i=1;
			while(a->next!=NULL)
			{
				//printing the list  value in the output file till the node->next==NULL;
				write<<"["<< i <<"]: "<<a->num<<endl;
				a=a->next;
				i=i+1;
			}
			write<<"["<< i <<"]: "<<a->num<<endl;	
		}
	}
	catch(...)
	{
		write<<"List is empty\n"; 
	}
	return ;
}

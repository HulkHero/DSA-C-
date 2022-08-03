#include <iostream>
#include <new>
#include <fstream>
#include <cstring>
using namespace std;
struct node           
{
	int value;
	node *head;
	node *tail;	
};
node *start=NULL;
int len=0;
void file_reading(ifstream &read);  //declaring fucntions
void create(int n);
void add(int n);
int choice ();
void add_node(int s);
void deleting (int n);
int lenght();
void traverse ();
void trav_back();
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
					cout<<"\nEnter the number,you want to add\n"; //to add a node
					cin>>x;
					cout<<"User: "<<x; 
					add_node(x);
					traverse();
				}
				else if(n==2)
				{
					cout<<"Enter the number to delete \n"; //to delete a node
					cin>>x;
					cout<<"User: "<<x;
					deleting(x);
					traverse();
				}
				else if(n==3)
				{
					cout<<"\nFor Forward enumrate press 1 and For backward press any number: \n";
					int u;
					cin>>u;
					if(u==1)                //enumrate
					{
						traverse();
					}
					else
					{
						trav_back();
					} 
				}
				else if(n==4)
				{
					cout<<"\n lenght of the list is : "; //length of list
					int a;
					a=lenght();
					cout<<a<<endl;
				}
				else if(n==5)
				{
					ofstream write;                    //opening output file
					write.open("output.txt");
					cout<<"list printed in the output file"<<endl;
					traverse_writing(write);             //writing in the ouput file;
					write.close();                    //closeing file
					f=false;
					return 0;
				}
				cout<<"\nwhat you want to do next;\n\n";    
			}while(f=true);
		}
	}
	catch(...)
	{
		cout<<"Dear User, the program requires two inputs\n";
		cout<<"[1] program.exe\n";
		cout<<"[2] Name of file containing list of valuebers: for example, input.txt or file.txt\n";
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
		start=new node;           	//creating first node
		start->value=n;
		start->head=NULL;
		start->tail=NULL;
	    len++;
	}
	else
	{
		cout<<"list is not empty \n";
		
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
		while(a->tail!=NULL)       //travsersing the list till the end 
		{
			a=a->tail;   
		}
		node *b;               //adding node at the end of list
		b=new node;
		b->value=n;
		b->tail=NULL;  
		b->head=a;                //new node's head pointing to the previous last node
		a->tail=b;
		len++;                   //incrementing lenght
		}
}
	catch(int n)
	{
		cout<<"list is empty,try add"<<endl;
	}
	return;
}
int choice ()   //asking for user choice
{ 	
	int option;
	cout<<"Dear user,Options are : \n[1] ADD \n[2] DELETE \n[3] Enumrate(forward and backward) \n[4] Length \n[5] stop the process and print the list in file \nUser: ";
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
			while(a->tail!=NULL)
			{
				cout<<"["<< i <<"]: "<<a->value<<endl;        //printing the list
				a=a->tail;                                  //travsersing through the list till it reachers last node
				i=i+1;
			}
			cout<<"["<< i <<"]: "<<a->value<<endl;	 	// to print the last node value
		}
	}
	catch(...)
	{
		cout<<"List is empty\n";
	}
	return ;
}
void add_node(int s)                        //fuction to insert the node in the linked list in sorting
{
	node *a,*newp,*pre;
	a=start;
	newp=new node;
	newp->value=s;
	if(start->tail==NULL || s<start->value)         //adding node at first position
	{
		newp->tail=start;
		newp->head=NULL;                      
		start->head=newp;                 
		start=newp;
	}
	else
	{
		while(a->tail!=NULL and a->value<s)          
		{
			a=a->tail; 
		}
		if(s<a->value)                          //adding node at the middle
		{
	        pre=a->head;
	        a->head=newp;
			newp->head=pre;
			newp->tail=a;
			pre->tail=newp;
			len=len+1;
		}
		else                                 //adding node at the end of list
		{
			a->tail=newp;
			newp->head=a;
			newp->tail=NULL;
			len++;	
		}
	}      
}
void deleting (int n)      //function to delete the node from the list
{
	if(len == 0)
	cout<<"List is empty,Nothing is to delete\n";
	else
	{
		node *c , *p,*m;
		c = start;
		while ((c->tail!= NULL)&&(c->value!= n))
		{
			p= c;
			c= c->tail;
		}
		if (c==start)               //delete the first node
		{
			start = c->tail;
			start->head=NULL;
			delete c;
			len = len - 1;
		}
		else if(c->value==n and c->tail!= NULL)    //to delete the middle node
		{
			p=c->head;
			m=c->tail;
			p->tail=m;
			m->head=p;
			delete c;
			len--;
		}
		else if(c->tail== NULL and c->value==n)    //to delete the last node
		{
			p=c->head;
			p->tail=NULL;
			delete c;
			len--;
		}
		else 
		{
			cout<<"Node with value " << n << " not found. There's nothing to delete" << endl;
		}
	}
	return;
}
int lenght()        
{
	return len;
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
			while(a->tail!=NULL)
			{
				write<<"["<< i <<"]: "<<a->value<<endl;    	//printing the list  value in the output file till the node->tail==NULL;
				a=a->tail;
				i=i+1;
			}
			write<<"["<< i <<"]: "<<a->value<<endl;	
		}
	}
	catch(...)
	{
		write<<"List is empty\n"; 
	}
	return ;
}
void trav_back ()       //function to traverse backward
{
	try
	{
		if (len == 0)
		throw(1);
		else
		{
			node *a;
			a = start;
			int static i=1;
			cout<<"\n Backward List is: \n";
			while(a->tail!=NULL)    //traversing till the end of the node
			{
				a=a->tail;
				i++;
			}
		    while(a->head!=NULL)        //traversing from last node to first node using head
			{
				cout<<"["<<i<<"]: "<<a->value<<" \n";
				a=a->head;
				i--;
			}	
			cout<<"["<<i<<"]: "<<a->value;
		}
	}
	catch(...)
	{
		cout<<"List is empty"<<endl;
	}
	return ;
}

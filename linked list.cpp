#include <iostream>
using namespace std;

class node{
	public:
	
	int value;
	node*next;
	
	node()
	{
		value =0;
		next=NULL;
		}
		
	node( int newval)
	{
		value= newval;
		next=NULL;
		}
	};
	
class linklist{
	public:
	
	node*head;
	
	linklist(){
		head=NULL;
		}
	
	void insert(int newval){
		node*temp=new node( newval);
		if(head==NULL){
			head=temp;
			}
		else{
			node*current=head;
			while(current -> next!=NULL)
			{
				current=current->next;
			}
			current->next =temp;
			}
		}
		
	void delet(){
		node*temp=new node();
		head=head->next;
		delete temp;
		}
		
	void display(){
		node*current = head;
		while(current!=NULL){
			cout<<current->value<<"->";
			current=current->next;
			
			}
		cout<<"NULL\n";
		}
		
	int count(){
		node*current=head;
		int i=0;
		while(current!=NULL){
			
			i++;
			current=current->next;
			}
			return i;
		}
		
	node*posi (int pos)
	{
		node*current=head;
		int x = 0;
		while(x < (pos-1))
		{
			current=current->next;
			x++;
			}
		return current;
		}
	
	void insertat (int pos, int newval)
	{
		if(pos < 1 || (pos > (count() + 1)))
		{
			cout<<"unvalid position\n";
			return;
			}
			
		node*current = posi(pos-1);
		
		if (pos ==1)
		     insert(newval);
		     
		 else{
			 node*temp=new node(newval);
			 temp->next = current ->next;
			 current -> next = temp;
			 }
		}
		
	void deleteat (int pos)
	{
		if(pos < 1 || (pos > (count() + 1)))
		{
			cout<<"unvalid position\n";
			return;
			}
			
		node*current = posi(pos-1);
		
		if (pos ==1)
		     delet();
		     
		 else{
			 node*temp=current->next;
			 current->next=current->next->next;
			 delete temp;
			 }
		}
	
	};
	
	
int main(){
	linklist l1;
	l1.insert(2);
	l1.insert(6);
	l1.insert(8);
	for( int y = 11 ; y <20; y++){
		l1.insert(y);
		}
	cout<<l1.count()<<endl;
	l1.insert(5);
	l1.insertat(4,2);
	l1.display();
	l1.delet();
	l1.display();
	l1.deleteat(8);
	l1.display();
	
	}


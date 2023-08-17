#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    //constructor 1st way
    node(int d){
        next = NULL;  //initially pointer ko null pe point krate hai
        data = d; //kuch data bhi store krega

    }

    //constructor 2nd way
    // node(int d):data(d),next(NULL){  //initialization list ki help se

    // }

    
};

//INSERTION
void inseratfront(node* &head, node* &tail,int data){  //kyuki agar pass by value kiya tih change neeche reflect ni hoga, toh head aur tail update ni honge, agar bina & ke kroge toh ans ni aega kuch, kyuki head aur tail null pe hi pointed rahega fir
        node* n = new node(data);
        if(head==NULL){   //head bhi null tail bhi null yani linked list abhi bni hi nhi
            head = n;     //first node of our linked list
            tail = n;
        }
        else{
            n->next = head;
            head = n;

        }
        
    }

void insertatend(node* &head, node* &tail,int data){
    node* n = new node(data);
        if(head==NULL){   //head bhi null tail bhi null yani linked list abhi bni hi nhi
            head = n;     //first node of our linked list
            tail = n;
        }
        else{
            tail->next=n;
            tail=n;
        }

}




//iterative way
int length(node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}
//recursive way
int lengthrec(node* head){
    if(head==NULL){
        return 0;
    }
    return 1+lengthrec(head->next);
}

void insertatanyposition(node* &head, node* &tail,int data,int pos){
    if(pos==0){
        inseratfront(head,tail,data);
    }
    else if(pos>=length(head)-1){
        insertatend(head,tail,data);
    }
    else{
        node* temp=head;
        node* n=new node(data);
        for(int i=1;i<=pos-1;i++){
            temp = temp->next;   //temp ko pos-1 pe le jane ke liye

        }
        n->next = temp->next;
        temp->next = n;
    }

}



//DELETION
void deleteatfront(node* &head,node* &tail){
	if(head==NULL){ //if ll is empty
		return;
	}
	else if(head->next==NULL){ //if we have only one node in ll
		delete head;
		head=NULL;
		tail=NULL;

	}
	else{
		node*n=head;
		head=head->next;
		delete n;
	}
}

void deleteatend(node* &head,node* &tail){
    if(head==NULL){ //if ll is empty
		return;
	}
	else if(head->next==NULL){ //if we have only one node in ll
		delete head;
		head=NULL;
		tail=NULL;

	}
    else{
        node* temp=head;
        while(temp->next!=tail){ //ya length-2 jumps bhi kra skte ho
           temp = temp->next;

        }
        delete tail;
        tail=temp;
        tail->next=NULL;
    }

}

void deleteatanyposition(node* head,node* tail,int pos){
    if(pos==0){
        deleteatfront(head,tail);
    }
    else if(pos>=length(head)-1){
        deleteatend(head,tail);
    }
    else{
        node* temp=head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        node* n=temp->next;
        temp->next=n->next;
        delete n;

    }
}


//SEARCHING
node* searchiteratively(node* head,node* tail,int key){
    while(head!=NULL){
        if(head->data==key){
            return head;
        }
        head= head->next;
    }
    return NULL;

}

node* searchrecursively(node* head,node* tail,int key){
    //base case
    if(head==NULL){
        return NULL;
    }
    //recursive case
    if(head->data==key){
        return head;
    }
    return searchrecursively(head->next,tail,key);
}


//FINDING MID OF LL
node* findmid(node* head){
    if(head==NULL){
        return head;
    }
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}

//REVERSING LL
void reversell(node* &head){
    // node*temp=head; //agar tail ko bhi krana h tumhe change,toh last me tail=temp,zarurat hai ni though abhi hme

	node*c=head;
	node *prev=NULL;
	node*n=NULL;
	// while(c!=NULL)
		while(c){
			n=c->next;
			c->next=prev;  //forming the link
			prev=c;
			c=n;
            }
		head=prev;

}

//MERGE TWO SORTED LINKED LISTS
node* merge(node* a,node* b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    node* newhead;
    if(a->data<b->data){
        newhead = a;
        node* c = merge(a->next,b);
        newhead->next = c;
    }
    else{
        newhead = b;
        node* d = merge(a,b->next);
        newhead->next = d;
    }
    return newhead;
    
}

//MERGE SORT
node* mergesort(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* m=findmid(head);
    node* b= head;
    node*c = m->next;
    m->next = NULL;
    b= mergesort(b);
    c= mergesort(c);
    node* finalhead = merge(b,c);
    return finalhead;


}

//CYCLIC LINKED LIST
bool iscyclic(node*head){
	node*fast=head;
	node*slow=head;
	while(fast!=NULL&&fast->next!=NULL){ //linear
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			return true;

		}

	}
	return false;
}


void createcycle(node*head){
	node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head->next->next;
}
//or..
// void createcycle(node*head,node* &tail){  //kyuki ab mujhe tail ni chahiye,kho jaye ll me
    
//     tail->next = head->next->next;
// }


void breakcycle(node*head){
	node*fast=head;
	node*slow=head;
    // node* prev =NULL;
	while(fast!=NULL&&fast->next!=NULL){ //linear
		fast=fast->next->next;
        // prev = prev->next->next;
		slow=slow->next;
		if(fast==slow){
			break;

		}

	}
	
	node*prev=head;
	while(prev->next!=fast){
		prev=prev->next;
	}
	slow=head;
	while(slow!=fast){
		prev=fast;
		fast=fast->next;
		slow=slow->next;
	}
	prev->next=NULL;



}



void printll(node* head){  //ab by referenece pass ni krna kyuki isme hm head update kra rhe h bs print krne ke liye, hm ni chhate vo chamge reflect ho
     while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
     }
     cout<<endl;

}


int main(){
    // node n1(3);
    // node n2(4);
    // n1.next=&n2; //to create link
    // cout<<n1.data<<" "<<(*n1.next).data;
    

    node* head=NULL;
    node* tail=NULL;
    inseratfront(head,tail,1);
    inseratfront(head,tail,2);
    inseratfront(head,tail,3);
    inseratfront(head,tail,4);

    printll(head);

    insertatend(head,tail,5);
    insertatend(head,tail,6);
    insertatend(head,tail,8);
    printll(head);
    
    insertatanyposition(head,tail,9,3);
    printll(head);
    // cout<<"length of linked list = "<<length(head)<<endl;
    // cout<<"length of linked list = "<<lengthrec(head);

    cout<<"after deleting at front"<<endl;
    deleteatfront(head,tail);
    deleteatfront(head,tail);
    printll(head);

    cout<<"after deleting at end"<<endl;
    deleteatend(head,tail);
    // deleteatend(head,tail);
    printll(head); 

    cout<<"after deleting at a particular position"<<endl;
    deleteatanyposition(head,tail,2);
    
    printll(head);

    // node* x= searchiteratively(head,tail,9);
    // if(x==NULL){
    //     cout<<"key not found"<<endl;
    // }
    // else{
    //     cout<<"value of node is "<<x->data<<endl;
    // }

    node* x= searchrecursively(head,tail,9);
    if(x==NULL){
        cout<<"key not found"<<endl;
    }
    else{
        cout<<"value of node is "<<x->data<<endl;
    }

    node* y=findmid(head);
    if(y==NULL){
        cout<<"mid not available"<<endl;
    }
    else{
        cout<<"mid is : "<<y->data<<endl;
      
    }

    reversell(head);
	cout<<"ll after reverse"<<endl;

	printll(head);


    node* head1=NULL;
    node* tail1=NULL;
    inseratfront(head1,tail1,9);
    inseratfront(head1,tail1,7);
    inseratfront(head1,tail1,2);
    inseratfront(head1,tail1,1);
    printll(head1);

    node* head2=NULL;
    node* tail2=NULL;
    inseratfront(head2,tail2,6);
    inseratfront(head2,tail2,4);
    inseratfront(head2,tail2,3);
    printll(head2);

    cout<<"After merging : "<<endl;

    node* final=merge(head1,head2);
    printll(final);
    cout<<endl;

    node* head3=NULL;
    node* tail3=NULL;
    inseratfront(head3,tail3,2);
    inseratfront(head3,tail3,7);
    inseratfront(head3,tail3,9);
    inseratfront(head3,tail3,1);
    inseratfront(head3,tail3,10);

    printll(head3);
    
    cout<<"After merge sort : "<<endl;
    node*finalhead = mergesort(head3);
    printll(finalhead);
    
    node* head4=NULL;
    node* tail4=NULL;
    insertatend(head4,tail4,1);
	insertatend(head4,tail4,2);
	insertatend(head4,tail4,3);
	insertatend(head4,tail4,4);
	insertatend(head4,tail4,5);
	insertatend(head4,tail4,6);
	insertatend(head4,tail4,7);
	insertatend(head4,tail4,8);
	printll(head4);

	if(iscyclic(head4)){
		cout<<"yes this is cyclic ll"<<endl;
	}
	else{
		cout<<"this is not cyclic ll"<<endl;
	}

	createcycle(head4);




	if(iscyclic(head4)){
		cout<<"yes this is cyclic ll"<<endl;
	}
	else{
		cout<<"this is not cyclic ll"<<endl;
	}

    breakcycle(head4);
    printll(head4);







    




    



    
    

    return 0;
}

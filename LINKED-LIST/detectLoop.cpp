/*
struct Node {
	int data;
	struct Node * next;
};
*/

int detectLoop(struct Node * head)
{
	if(!head)
	return 0;
	else{
		if(head->next==head)
		return 1;
		struct Node * slow=head;
		struct Node * fast=head->next;
		while(fast!=NULL&&fast->next!=NULL)
		{
			
			slow=slow->next;
			fast=fast->next->next;
			if(fast==slow)
			return 1;
		}
		return 0;
	}
}



//void removeLoop(struct Node * head)
//{
//	if(!head)
//	return ;
//	else{
//		if(head->next==head)
//		{	head->next=NULL
//			return ;
//		}
//		struct Node * temp=head;
//		while(temp->next!=head)
//		{
//			temp=temp->next;
//		}
//		temp->next=NULL;
//	}
//}

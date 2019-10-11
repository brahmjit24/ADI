import java.util.*;
class QueueNode
{
  int data;
  QueueNode next;

  public QueueNode(int data) 
  {
    this.data = data;
  }
}

class QueueLinkedList
{
  public QueueNode front, rear;
  public void EnQueue(int data)
  {
    QueueNode temp=new QueueNode(data) ;
     if(front==null&&rear==null)
       front =rear=temp;
    else
    {
      rear.next=temp;
      rear=temp;
    }
  }    

  public int DeQueue()
  {
    if(front==null)
      return -1;
    int item=front.data;
    front=front.next;
     if (this.front == null) 
            this.rear = null;
    return item;
  }    
}

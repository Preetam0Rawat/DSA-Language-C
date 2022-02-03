#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};


void enqueue(struct queue **front, struct queue **rear, int val)
{  struct queue *node = malloc(sizeof(struct queue));
    if(node == NULL)
       printf("Queue full\n");

    else 
    { struct queue *n = malloc(sizeof(struct queue));
      n->data = val;
      n->next = NULL;
       if(*front == NULL )
          {
               *front  = *rear = n;

          }
         else  
            {
                (*rear)->next = n;
                 *rear = n;
            } 
        printf("Enqueued elemetn is : %d\n", (*rear)->data);
    } 
}

void dequeue(struct queue **front, struct queue **rear)
{   int val;
    if(*front == NULL)
      printf("Queue empty\n");
      else
      {
        struct queue *ptr = *front;
        val = (*front)->data;
        *front = (*front)->next;
        free(ptr);
        printf("Dequeued elemennt is %d\n", val);
      }
       
}

void traverse (struct queue *front, struct queue *rear)
{ 
   struct queue *ptr = front;
   
    while(ptr != rear->next)
    {
        printf("Element is : %d\n",  ptr->data);
        ptr= ptr->next;
    }
}

int main()
{
   struct queue *front = NULL;
   struct queue *rear = NULL;
    
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    traverse(front, rear);

    dequeue(&front, &rear);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    
   

    traverse(front, rear);


}
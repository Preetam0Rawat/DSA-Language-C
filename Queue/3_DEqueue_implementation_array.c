#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f, r;
    int *arr;
};

int isfull(struct queue *qp) {                                                                           
    if(qp->r == qp->size-1)                                                
       return 1;
    else 
       return 0;
}


int isempty(struct queue *qp){
    if(qp->f == -1 || qp->r == -1)
       return 1;
    else 
       return 0;
}


void enqueue(struct queue *qp, int val)
{
    if(isfull(qp))
         printf("Queue full\n");
       
    else
    {if(qp->f == -1)
         {
             qp->f = 0;
         }
      qp->r++;
      qp->arr[qp->r] = val;
      printf("Enqueued element is %d\n", val);
    }
}

void dequeue(struct queue *qp)
{   int val;
    if(isempty(qp)){
        printf("Queue empty\n");
    
     }
     else if(qp->f == qp->r)
     {    val = qp->arr[qp->f];
          printf("Dequeued element is %d\n", val);
          qp->f = -1; qp->r =-1;
     }
    else{
        val = qp->arr[qp->f];
        qp->f++;
        printf("Dequeued element is %d\n", val);
    
    }
}

void fenqueue(struct queue *qp, int val)
{
    if(qp->f == 0)
        printf("Can't enqueue from the front. QUEUE FULL\n");
    else{
        qp->f--;
        qp->arr[qp->f] = val;
        printf("Enqueud value at the front is %d\n", val);
    }
}

void rdequeue(struct queue *qp)
{
    int val;
    if(isempty(qp)){
        printf("Can't dequeue from the rear. QUEUE EMPTY\n");
    
     }
     else if(qp->r == qp->f)
     {    val = qp->arr[qp->r];
          printf("Dequeued element is %d\n", val);
          qp->f = -1; qp->r =-1;
     }
    else{
        val = qp->arr[qp->r];
        qp->r--;
        printf("Dequeued element is %d\n", val);
    
    }   
}
void traverse(struct queue *qp)
{   if(isempty(qp))
             printf("Stack Empty. Nothing to display \n");
    else{
    int i = 0, j;
    j = qp->f;
    for(j; j<= qp->r; j++)
    {  
         printf("Element %d is : %d\n", i+1, qp->arr[j]);
         i++;
    }
  }
}

int main()
{
    struct queue qp;
    qp.size = 8;
    qp.f = qp.r = -1;

    qp.arr = malloc (qp.size * sizeof(int));
  
    
    enqueue(&qp, 10);
    enqueue(&qp, 20);
    enqueue(&qp, 30);
    enqueue(&qp, 40);
    enqueue(&qp, 50);

    traverse(&qp);


     dequeue(&qp);
     dequeue(&qp);
     dequeue(&qp);

    traverse(&qp);

    fenqueue(&qp, 30);
    fenqueue(&qp, 20);
    fenqueue(&qp, 10);
    



    traverse(&qp);

    rdequeue(&qp);
    rdequeue(&qp);
    rdequeue(&qp);

    traverse(&qp);

}
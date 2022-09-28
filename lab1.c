#include <stdio.h>
# define SIZE 100

void enqueue();
void dequeue();
void searchE();
void show();
void sort();
void reverse();
void heapify();
void priority();
void swap();
void exit();

int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;

int main()
{
    int ch;
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Search an element\n");
        printf("4.Sort\n");
        printf("5.Reverse\n");
        printf("6.Priority queue\n");
        printf("7.Circular queue \n");
        printf("8.Display the Queue\n");
        printf("9.Exit\n");
        printf("\nEnter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: enqueue(); printf("\n");
            break;
            case 2: dequeue(); printf("\n");
            break;
            case 3: searchE(); printf("\n");
            break;
            case 4: sort(); printf("\n");
            break;
            case 5: reverse(); printf("\n");
            break;
            case 6: priority(); printf("\n");
            break;
            case 7: printf("Nu funtioneaza :( \n");
            break;
            case 8: show(); printf("\n");
            break;
            case 9: exit(0);
            default: printf("Incorrect choice \n"); printf("\n");
        } 
    } 
} 
 
void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)
      
        Front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
    }
} 
 
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
} 
 
void show()
{
    
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}

void searchE() 
{
    int insert_item, aux = 0;
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Enter the number that are you trying to find: ");
        scanf("%d", &insert_item);
        for (int i = Front; i <= Rear; i++)
        {
            if (inp_arr[i] == insert_item) 
                aux = 1;
        }
        if (aux == 1)
            printf("The number is in the queue\n");
        else  printf("The number is not in the queue\n");
    }
}

void sort() 
{
    int a, n = 0;
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        for (int i = Front; i <= Rear; i++)
            n++;
        for (int i = Front; i <= Rear; i++) 
        {
            for (int j = i + 1; j < n; ++j)
            {
 
                if (inp_arr[i] > inp_arr[j]) 
                {
 
                    a =  inp_arr[i];
                    inp_arr[i] = inp_arr[j];
                    inp_arr[j] = a;
                }
 
            }
        }
        show();
    }
}

void reverse() 
{
    int a, n = 0;
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        for (int i = Front; i <= Rear; i++)
            n++;
        for (int i = Front; i <= Rear; i++) 
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (inp_arr[i] < inp_arr[j]) 
                {
 
                    a =  inp_arr[i];
                    inp_arr[i] = inp_arr[j];
                    inp_arr[j] = a;
                }
 
            }
        }
        show();
    }
}

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void priority() 
{
    for (int i = Front; i <= Rear; i++)
            heapify(inp_arr, SIZE, i);
    show();
}

void heapify(int inp_arr[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && inp_arr[l] > inp_arr[largest])
      largest = l;
    if (r < size && inp_arr[r] > inp_arr[largest])
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&inp_arr[i], &inp_arr[largest]);
      heapify(inp_arr, size, largest);
    }
  }
}
/*
// Check if the queue is full - functia pt Circular queue
int isFull()
{
    if ((Front == Rear + 1) || (Front == 0 && Rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() 
{
  if (Front == -1) return 1;
  return 0;
}
*/
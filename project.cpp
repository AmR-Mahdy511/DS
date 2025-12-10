#include <bits/stdc++.h>
#define MAX_SIZE 5
using namespace std;

int space = 0;

struct order
{
    int order_id;
    string order_name;
    string order_size;
};

class Queue {
public:
    
    int front, rear;
    order arr[MAX_SIZE];
    Queue() { front = rear = -1; }

    bool isEmpty()
    {
        if (front == rear && front == -1) return 1;
        return 0;
    }

    bool isFull()
    {
        if ((rear + 1) % MAX_SIZE == front) return 1;
        return 0;
    }

    void enqueue(order val)
    {
        if (this->isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if(rear == -1 && front == -1)
        {
            rear++;
            front++;
            arr[rear] = val;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
    }

    void dequeue()
    {
        if (this->isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        front = (front + 1) % MAX_SIZE;
    }
 
    void finish_orders()
    {
    if(this->isEmpty())
    {
        cout << "There is No orders now\n";
        return;
    }
    cout <<"ID : "  << arr[front].order_id << " , Name :" << arr[front].order_name << " , Size : " << arr[front].order_size << "\n";
    dequeue();
    }

    void print_orders()
    {
        if(this->isEmpty())
        {
        cout << "There is No order now\n";
        return;            
        }
        cout << "Current orders are : " << "\n";
        int i = front;
        while(true)
        {
            cout << "Id: " << arr[i].order_id << " | Name: " << arr[i].order_name << " | Size: " << arr[i].order_size << endl;
            if(i == rear) break;
            i =  (i + 1) % MAX_SIZE;
        }
    }

    int remaining_space(){
       return MAX_SIZE-space;
    }
    
};


order place_order(order x){
    cout << "please enter meal ID : ";
    cin >> x.order_id;
    cout << "please enter meal name : ";
    cin >> x.order_name;
    cout << "please choose a size : ";
    cin >> x.order_size;
    return x;
};

int main()
{
    Queue q;
    
    cout<<"Welcome to Ptizza Restaurant \n";
    bool loop = true;
    while(loop)
    {
        cout<<"1. Place order\n";
        cout<<"2. Finish order\n";
        cout<<"3. Print orders\n";
        cout<<"4. Free order spaces\n";
        cout<<"5. Exist\n";
        int i = 0;
        cin >> i;
        switch(i)
        {
            case 1:
            {
                order X;
                // place_order(X);
                if(q.remaining_space() == 0)
                {
                    cout << "There is no Free space Now !\n";
                    break;
                }
                q.enqueue(place_order(X));
                cout << "Added to queue. \n";
                space++;
                break;
            }
            case 2:
            {
                q.finish_orders();
                space--;
                break;
            }
            case 3:
            {
                q.print_orders();
                cout << "\n";
                break;
            }
            case 4:
            {
                cout<<"Remaining space : "<<q.remaining_space() << endl;
                break;
            }
            case 5:
            {
                loop = false;
                break;
            }
    }

}
}

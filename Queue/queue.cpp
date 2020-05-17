#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
class CircularQueue {
public:
    
    CircularQueue(int k) {
        size = k;
        buffer = (T*)malloc(sizeof(T)*k);
        head = -1; 
        tail = -1; 
    }
    
    /*
        This function inserts an element into CircularQueue
        Args:
            - int value: value to be inserted
    */
    bool enQueue(T value) {
        if (isFull()){

            return false;
        }
        cout << "DEBUG size == 0 or Full" << endl;

        if (isEmpty()) {
            head = 0;
            tail = 0;    
        }

        else 
            tail = (tail + 1) % size;
                
        buffer[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;

        buffer[head] = 0;
        if (head == tail) {
            head = tail = -1;
        }
        else
            head = (head + 1) % size;

        return true;
    }
    
    /** Get the front item from the queue. */
    T Head() {
        return buffer[head];
    }
    
    /** Get the last item from the queue. */
    T Tail() {
        return buffer[tail];
    }
    

    void print() {

        for (int i = 0; i < size; ++i) {
            cout << buffer[i] << " ";
        }
        cout << endl;
        cout << "head = " << head << " tail = " << tail << endl;
    }

private:

    T *buffer;
    int size;
    int head; 
    int tail; 

    bool isEmpty() {
        return (head == -1 && tail == -1);
    }
    
    bool isFull() {
        return  size == 0 || head == ((tail+1) % size);
    }

};

/*Usage: 
	en x : enqueue x number to the end of our queue
	de   : dequeue head number
		
*/
int main() {
    string command;
    double key;
    CircularQueue <double>qu = CircularQueue<double>(6);

    while (true) {

        cin >> command;
        if (command == "en") {
            cin >> key;
            qu.enQueue(key);
            qu.print();
        }
        if (command == "de") {
            qu.deQueue();
            qu.print();
        }

        if (command == "exit")
            break;
    }
    
    return 0;
}

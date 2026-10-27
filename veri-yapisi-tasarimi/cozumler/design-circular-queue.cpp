class MyCircularQueue {

    int head = -1;
    int tail = -1;
    int[] q;
    int k;

    public MyCircularQueue(int k) {
        q = new int[k];
        this.k = k;
    }

    public boolean enQueue(int value) {
        if(head == -1 && tail == -1) {

            head = tail = 0;
            q[tail] = value;
            return true;
        }
        if((tail == k-1 && head == 0) || tail+1 == head) {

            return false;
        }
        tail++;
        if(tail == k)
            tail = 0;
        q[tail] = value;
        return true;
    }

    public boolean deQueue() {
        if(head == -1) {

            return false;
        }
        if(head == tail) {

            head = tail = -1;
            return true;
        }
        head++;
        if(head == k)
            head = 0;
        return true;
    }

    public int Front() {
        if(head == -1)
            return -1;
        return q[head];
    }

    public int Rear() {
        if(tail == -1)
            return -1;
        return q[tail];
    }

    public boolean isEmpty() {
        if(head == -1 && tail == -1)
            return true;
        return false;
    }

    public boolean isFull() {
        if(tail == k-1 || tail+1 == head)
            return true;
        return false;
    }
}

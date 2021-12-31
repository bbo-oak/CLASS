#include <iostream>

using namespace std;

class PFArrayI {

public:
    PFArrayI();
    PFArrayI(int n);
    PFArrayI(const PFArrayI& cp);

    void addElement(int n);

    bool full() const { return capacity == used; }
    int getCapacity() const { return capacity; }
    int getNumberUsed() const { return used; }
    void emptyArray() { used = 0; }

    int& operator[](int n);
    PFArrayI& operator=(const PFArrayI& rightside);
    ~PFArrayI();

private:
    int *arr;
    int capacity;
    int used;
};

PFArrayI::PFArrayI() : capacity(50), used(0) {
    arr = new int[capacity];
}

PFArrayI::PFArrayI(int size) : capacity(size), used(0) {
    arr = new int[capacity];
}

PFArrayI::PFArrayI(const PFArrayI& pfaObject) 
: capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed()){
    arr = new int[capacity];
    for (int i = 0; i < used; i++) {
        arr[i] = pfaObject.arr[i];
    }
}

void PFArrayI::addElement(int n){
    if(used >= capacity){
        cout << "Attempt to exceed capacity in PFArrayI.\n";
        exit(0);
    }

    arr[used] = n;
    used++;
}

PFArrayI& PFArrayI::operator=(const PFArrayI& rightside){
    if(capacity != rightside.capacity){
        delete [] arr;
        arr = new int[rightside.capacity];
    }

    capacity = rightside.capacity;
    used = rightside.used;

    for(int i = 0; i < used; i++)
        arr[i] = rightside.arr[i];

    return *this;
}

int& PFArrayI::operator[](int n) {
    return arr[n];
}

PFArrayI::~PFArrayI(){
    delete [] arr;
}

int main(){
    int cap;

    cout << "Enter capacity of this super array: ";

    cin >> cap;

    PFArrayI temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";

    cout << "Place a negative number at the end.\n";

    int next;

    cin >> next;

    while ((next >= 0) && (!temp.full( )))

    {

    temp.addElement(next);

    cin >> next;

    }

    cout << "You entered the following "

    << temp.getNumberUsed( ) << " numbers:\n";

    int index;

    int count = temp.getNumberUsed( );

    for (index = 0; index < count; index++)
        cout << temp[index] << " ";

    cout << endl;
}
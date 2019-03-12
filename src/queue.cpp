#include <iostream>
#include <queue.h>

using namespace std;

template <class T>
ConcurrentQueue<T>::ConcurrentQueue(int size) {
    if (size < 1) {
        cerr << "List size should be greater than 1." << endl;
        exit(1);
    }
    // this->arr = static_cast<T*>( malloc( size * sizeof(T) ) );
    this->arr = new T[size];
    this->finished = 0;
    this->head = 0;
    this->tail = 0;
    this->max_size = size;
    this->full = 0;
    this->current_size = 0;
    pthread_mutex_init(&(this->mutex), NULL);
}

template <class T>
void ConcurrentQueue<T>::add(T item) {
    pthread_mutex_lock(&(this->mutex));
    this->arr[this->head] = item;
    this->head++;
    pthread_mutex_unlock(&(this->mutex));
}

template <class T>
T ConcurrentQueue<T>::remove() {
    this->head--;
    return this->arr[this->head];
}


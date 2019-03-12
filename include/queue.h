#include <cstdlib>
#include <pthread.h>

using namespace std;

/*
 * https://www.techiedelight.com/queue-implementation-using-templates-cpp/
 */

template <class T>
class ConcurrentQueue {
    private:
        int head;
        int tail;
        int full;
        int current_size;        
        int max_size;
        int finished;
        T *arr;
        pthread_mutex_t mutex;

    public:    
        ConcurrentQueue(int size);

        void add(T item);
        T remove();
        
        // void init();
        // void finish();

        // int is_full();
        // int is_empty();
        // int is_finished();       
};
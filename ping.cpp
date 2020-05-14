#include <iostream>
#include <pthread.h>
#include "pingp.h"
#include <unistd.h>
using namespace std;


void * thread_func(void * arg)
{
    cout << "Thread " << pthread_self() << " work" << endl << endl;
    sleep(1);
    cout << endl << "Thread " << pthread_self() << " done" << endl;
    return NULL;
}

int main()
{
    pthread_t thread;
    char host[BUFF_LEN] = { 0, };
    cout << "Enter IP: ";
    cin.get(host, BUFF_LEN);
    cout << endl;
    if (pthread_create(&thread, NULL, thread_func, NULL) != 0)
    {
        return EXIT_FAILURE;
    }
    ping(host);
    if (pthread_join(thread, NULL) != 0)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
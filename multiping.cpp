#include <iostream>
#include <unistd.h>
#include <fstream>
#include "pingp.h"
#include <pthread.h>
using namespace std;


void * thread_func(void * arg)
{
    cout << "Thread " << pthread_self() << " work" << "\n";
    cout << endl << "Thread " << pthread_self() << " done" << endl;
    return NULL;
}

int main()
{
    pthread_t thread;
    ifstream fout;
    fout.open("input2.txt");
    char host[BUFF_LEN] = { 0, };
    while (!fout.eof())
    {
        fout >> host;
        if (pthread_create(&thread, NULL, thread_func, NULL) != 0)
        {
            return EXIT_FAILURE;
        }
        ping(host);
    }
    if (pthread_join(thread, NULL) != 0)
    {
        return EXIT_FAILURE;
    }
    return 0;
}
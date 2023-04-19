#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

void f1(long long n){
    long long k{};
    for (long long i=0;i<n;++i){++k;}
}
void f2(long long n){
    long long k{};
    for (long long i=0;i<n;++i){
    for (long long j=0;j<n;++j)++k;}
}

void f3(long long n){
    long long k{};
    for(long long i{};i<n;++i){
        for (long long j=1;j<n;j*=2)++k;
    }
}

int main (int argc, char *argv[])
{
    long long n;
    while (1){
        cout<<"input n\n";
        cin>>n;
        milliseconds start=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        /* f1(n); */
        /* f2(n); */
        f3(n);
        milliseconds end=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        cout<<"time used: "<< milliseconds(end).count()-milliseconds(start).count()<<"ms\n";
    }
    return 0;
}

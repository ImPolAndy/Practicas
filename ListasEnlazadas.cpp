#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int sum1( const int x,const int y)
{

    return x + y ;
}



double sum2( const double x , const double y )
{

    return x + y ;
}

int sum3( const int x , const int y , const int z ) {

    return x + y + z ;

}

int sum4( const int a , const int b , const int c , const int d ) {

    return a + b + c + d ;
}

int sum5( const int a, const int b, const int c = 0 , const int d = 0)
{
    return a + b + c + d ;
}

int sum6( const int numbers[],const int numbersLen ) {
    int sum = 0;
    for(int i = 0; i< numbersLen ; ++i )
    {
        sum+=numbers[i];
    }
    return sum;
}

int sum7( const int numbers [] , const int numbersLen ) {
    return numbersLen == 0 ? 0 : numbers [0] + sum7( numbers + 1 ,numbersLen - 1) ;
}

/*
int dartsInCircle = 0;

2 for(int i = 0; i < n ; ++ i ) {

3 double x = rand () / ( double ) RAND_MAX , y = rand () / ( double )

RAND_MAX ;
    if( sqrt(x*x+y*y) < 1 )
    {
        ++ dartsInCircle ;
    }
}

*/
double computePi ( const int n)
{
    srand (time(0)) ;

    int dartsInCircle = 0;

    for(int i=0;i<n;++i)
    {
        double x = rand () / ( double ) RAND_MAX , y = rand () / ( double )
            RAND_MAX ;
        if( sqrt ( x * x + y * y ) < 1 ) {
            ++dartsInCircle ;
        }
    }

// r^2 is 1 , and a/4 = dartsInCircle /n, yielding this for pi:
    return dartsInCircle/static_cast<double>(n)*4;
}

void printArray(const int arr[], const int len) {
    for(int i = 0; i < len; ++i )
    {
        cout<<arr[i];
        if(i<len-1) {
            cout <<", ";
        }
    }
}


void reverse0(int numbers[] ,const int numbersLen) {

    for(int i = 0; i < numbersLen / 2; ++ i )
    {

        int tmp = numbers [ i ];
        int indexFromEnd = numbersLen-i-1;
        numbers[i] = numbers[indexFromEnd];
        numbers[indexFromEnd] = tmp ;
    }
}

/*
void transpose(const int input[][LENGTH],int output[][WIDTH])
{

    for(int i = 0; i < WIDTH ; ++ i )
    {
        for (int j = 0; j < LENGTH ; ++ j ) {
            output [ j ][ i ] = input [ i ][ j ];
        }
    }
}

*/

void reverse1(int numbers [] , const int numbersLen ) {

    for(int i = 0; i < numbersLen / 2; ++ i )
    {
        int tmp = *( numbers + i ) ;
        int indexFromEnd = numbersLen - i - 1;
        *(numbers+i)=*(numbers+indexFromEnd);
        *(numbers+indexFromEnd)=tmp;
    }
}

int stringLength (const char *str) {

    int length = 0;
    while (*( str + length ) !='\0')
    {
        ++ length ;
    }
    return length ;
}

void swap0(int &x, int & y) {
    int tmp = x ;
    x = y ;
    y = tmp;
}

void swap1(int *x, int *y) {
    int tmp = *x ;
    *x = *y ;
    *y = tmp;
}

void swap2(int **x, int **y) {
    int *tmp = *x ;
    *x = *y ;
    *y = tmp;
}

int main()
{
    //int b,c;
    int a[]={2,3,4,5,6};
    cout<<sum1(4,7)<<'\n';
    cout<<sum2(3,5)<<'\n';
    cout<<sum3(2,5,9)<<'\n';
    cout<<sum4(3,6,7,9)<<'\n';
    cout<<sum5(2,4)<<'\n';
    cout<<sum6(a,5)<<'\n';
    cout<<sum7(a,5)<<'\n';
    cout<<computePi(5)<<'\n';
    //printArray(a,5)<<'\n';
    cout<<reverse0(a,5)<<'\n';
    return 0;

}

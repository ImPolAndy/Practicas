#include <iostream>
#include <stdexcept>

using namespace std;

template < typename T>
T min( const T t1 , const T t2)
{
    return t1 < t2 ? t1 : t2;
}

#define min(x, y) (x < y ? x : y)

template < class T> class Stack ;

template < class T>
Stack <T> operator +( const Stack <T> &s1 , const Stack <T> &s2);
{
    Stack <T> result = s1;

    for ( unsigned i = 0; i < s1. items . size (); ++i) {
    result.items.push_back(s2. items [i]);
    }

return result ;
}

template < class T>
class Stack
{
    friend Stack<T>operator +<>( const Stack <T> &s1 , const Stack <T> &s2);
    vector <T> items ;
    public :
    bool empty () const { return items . empty () ;}
    void push ( const T & item ) { items . push_back ( item );}
    T pop()
    {
        T last = items . back ();
        items . pop_back ();
        return last ;
    }
};

template < class T>
Stack <T> operator +( const Stack <T> &s1 , const Stack <T> &s2)
{
    Stack <T> result = s1;
    for( unsigned i = 0; i < s1. items . size (); ++i) {
        result.items.push_back(s2. items [i]);
    }
    return result ;
}

class Graph {
    protected :
    map <int , vector <int > > outgoing ;

public :
    Graph( const vector <int > & startPoints , const vector <int >&endPoints );
    int numOutgoing ( const int nodeID ) const ;
    const vector <int > & adjacent ( const int nodeID ) const ;
};

Graph :: Graph ( const vector <int > & startPoints , const vector <int > &
endPoints ) {
16 if( startPoints . size () != endPoints . size ()) {
17 throw invalid_argument (" Start /end point lists differ in
length ");
18 }
19
for( unsigned i = 0; i < startPoints . size (); i++ ) {
21 int start = startPoints [i], end = endPoints [i];
22 outgoing [ start ]. push_back (end);
23 outgoing [end ]; // Just to indicate this node exists
24 }
}

int Graph :: numOutgoing ( const int nodeID ) const
{
    return adjacent(nodeID).size();
}

const vector <int > & Graph :: adjacent( const int nodeID ) const
{
    map <int,vector <int > >:: const_iterator i = outgoing.find (nodeID);
    if(i == outgoing . end ()) {
    throw invalid_argument("Invalid node ID");
    }
    return i-> second ;
}


int main()
{

    return 0;
}

#include <iostream>

using namespace std;

struct BRIDGE
{
    int capacity;
    int duration;
    int tick;
    int people;
    bool occupied;
};

int main()
{
    int in1, in2, numBridges, numPeople, counter;
    
    cin >> in1;
    cin >> in2;
    while( in1 != 0 && in2 != 0 )
    {
        numBridges = -in1;
        numPeople = in2;
        
        BRIDGE* bridge = new BRIDGE[numBridges];
        int* group = new int[numBridges+1];
        
        //Initialize
        for( int i = 0; i < numBridges; i++ )
        {
            group[i] = 0;
            
            
            cin >> in1;
            cin >> in2;
            bridge[i].capacity = in1;
            bridge[i].duration = in2;
            bridge[i].tick = 0;
            bridge[i].people = 0;
            bridge[i].occupied = false;
        }
        group[numBridges] = 0;
        group[0] = numPeople;
        
        counter = 0;
        while( group[numBridges] != numPeople ) //Not everyone has made it across
        {
            for( int i = 0; i < numBridges; i++ )
            {
                if( !bridge[i].occupied && group[i] != 0)
                {
                    bridge[i].occupied = true;
                    bridge[i].tick = bridge[i].duration;
                    
                    if( group[i] <= bridge[i].capacity )
                    {
                        bridge[i].people = group[i];
                        group[i] = 0;
                    }
                    else
                    {
                        bridge[i].people = bridge[i].capacity;
                        group[i] -= bridge[i].capacity;
                    }
                }
                else if( bridge[i].occupied )
                {
                    bridge[i].tick--;
                    if( bridge[i].tick == 0 )
                    {
                        group[i+1] += bridge[i].people;
                        bridge[i].people = 0;
                        bridge[i].occupied = 0;
                        i--;
                    }
                }
            }
            counter++;
        }
        
        cout << --counter << endl;
        
        delete [] bridge;
        delete [] group;
        
        cin >> in1;
        cin >> in2;        
    }

    
    return 0;
}

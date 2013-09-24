#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int datasets, linenum, row, col, output;
    
    cin >> datasets;
    for( int line = 0; line < datasets; line++ )
    {
        cin >> linenum;
        cin >> row;
        cin >> col;
        
        if( row < 0 || col < 0 || col > row )
            output = 0;
        else if( col == 0 || col == row || row < 2 )
            output = 1;
        else if( col == 1 || col == (row-1) )
            output = row;
        else
        {
            if( col > row/2 )
                col = int( floor(row/2.0) - (col - ceil(row/2.0)) );
                
            int increment = row - 3;
            output = row;
            for( int i = 2; i <= col; i++ )
            {
                output += increment;
                increment -= 2;
            }
        }
        
        cout << linenum << " " << output << endl;
            
    }
    
    return 0;
}

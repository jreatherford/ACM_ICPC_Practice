#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    int datasets, linenum, repeat;
    string input;
    
    cin >> datasets;
    for( int i = 0; i < datasets; i++ )
    {
        cin >> linenum;
        cin >> repeat;
        cin >> input;
        
        string output = "";
        
        for( unsigned int j = 0; j < input.length(); j++ )
            for( int n = 0; n < repeat; n++ )
                output += input[j];
                
        cout << linenum << " " << output << endl;
    }
    
    return 0;
}

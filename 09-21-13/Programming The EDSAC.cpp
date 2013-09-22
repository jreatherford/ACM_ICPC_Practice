#include <iostream>
#include <string>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string to_bin( double );

string alphabet = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";

int main()
{
    unsigned int datasets, linenum, opcode, address;
    long double value;
    string bin;
    char wordsize;
    
   
    cin >> datasets;
    
    for( unsigned int i = 0; i < datasets; i++ )
    {
        cin >> linenum;
        cin >> value;
        
        opcode = 0;
        address = 0;
        wordsize = '\0';
        
        if( value < -1 || value >= 1 )
            cout << linenum << " INVALID VALUE" << endl;
        else
        {   
            if( value > 0 )        
                value = 0.0000152587890625 * floor(value / 0.0000152587890625);
            else
                value = 0.0000152587890625 * ceil(value / 0.0000152587890625);
                
            bin = to_bin( value );
            
            for( unsigned int i = 0; i < 5; i++ )
                opcode = opcode*2 + int( bin[i] - '0' );
            
            for( unsigned int i = 5; i < 16; i++ )
                address = address*2 + int( bin[i] - '0' );
            
            wordsize = ( bin[16] == '0'? 'F' : 'D' );
            
            cout << linenum << " " << alphabet[opcode] << " " << address << " " << wordsize << endl;
        }
    }
    
    return 0;
}

string to_bin( double value )
{
    string bin = "";
    bool negative, carry = 1;
    
    if( value < 0 )
    {
        negative = 1;
        value *= -1;
    }
    else
        negative = 0;
        
    while( bin.length() < 17 )
    {
        value *= 2;
        if( value >= 1 )
        {
            value -= 1;
            bin += ( negative? '0' : '1' );
        }
        else
            bin += ( negative? '1' : '0' );
    }
    
    //bin is in one's complement
    //add one to put into two's complement
    
    string complement = "";
    if( negative )
    {
        for( int i = 16; i >= 0; i-- )
        {
            if( bin[i] == '0' && carry == 0)
                complement = '0' + complement;
            else if( bin[i] == '0' && carry == 1 )
            {
                complement = '1' + complement;
                carry = 0;
            }
            else if( bin[i] == '1' && carry == 0 )
                complement = '1' + complement;
            else if( bin[i] == '1' && carry == 1 )
                complement = '0' + complement;
        }
        bin = '1' + complement;
    }
    else
        bin = '0' + bin;
    
    return bin;
}

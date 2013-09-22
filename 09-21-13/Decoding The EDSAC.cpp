#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string to_bin( unsigned int, unsigned int );
long double to_dec( string );

string alphabet = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";

int main()
{
    unsigned int datasets, linenum, op_index, address;
    long double value;
    string bin;
    char opcode, wordsize;
    
   
    cin >> datasets;
    
    for( unsigned int i = 0; i < datasets; i++ )
    {
        cin >> linenum;
        cin >> opcode;
        cin >> address;
        cin >> wordsize;
        
        op_index = alphabet.find(opcode);
        
        //Convert opcode to binary
        bin = to_bin( op_index, 5 );
        
        //Convert address value to binary    
        bin += to_bin( address, 11 );
        
        //Convert wordsize to binary
        bin += (wordsize == 'F'? '0' : '1');
        
        //Convert bin to decimal value
        value = to_dec( bin );
        
        
        string dec_str = "";
        unsigned int val;
        
        if( value < 0 )
        {
            dec_str += '-';
            value *= -1;
        }
        
        if( value == 1 )
            dec_str += "1.0";
        else if( value == 0 )
            dec_str += "0.0";
        else
        {
            dec_str += "0.";
            while( value > 0 )
            {
                value *= 10;
                val = int(value);
                value -= val;
                dec_str += '0' + val;
            }
        }
        
        cout << linenum << " " << dec_str << endl;
    }
    
    return 0;
}

string to_bin( unsigned int value, unsigned int pad )
{
    string bin = "";
    while( value > 0 )
    {
        bin = char('0' + value%2 ) + bin;
        value = value/2;
    }
    
    while( bin.length() < pad )
        bin = '0' + bin;
    
    return bin;
}

long double to_dec( string bin )
{
    double dec = 0;
    bool negative = bool(bin[0] - '0'), carry = 1;
    
    if( bin == "10000000000000000" )
        return -1;
    
    if( negative )
    {
        string complement = "";
        
        //Flip bits
        for( int i = 0; i < 17; i++ )
            complement += (bin[i] == '0'? '1': '0');
        bin = complement;
        
        //Add one
        complement = "";
        for( int i = 16; i >= 1; i-- )
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
        bin = '0' + complement;
    }
    
    //convert from binary to decimal
    double power = 0.5;
    for( int i = 1; i < 17; i++ )
    {
        dec += power * (bin[i] - '0');
        power /= 2;
    }
    
    if( negative )
        dec *= -1;
    
    return dec;
}

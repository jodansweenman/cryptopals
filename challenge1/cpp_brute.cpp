#include <iostream>
#include <string>

#define LOW_MASK 0b000000111111
#define HIGH_MASK 0b111111000000

using namespace std;

string temp_to_b64(int num){
    string result = "  ";
    uint16_t temp;
    uint16_t b64;
    for (int i = 0; i < 2; i++) {
        if (i == 0){
            temp = (num & HIGH_MASK) >> 6;
        }
        else {
            temp = (num & LOW_MASK); 
        }
        if (temp <= 25){
            b64 = temp + 65;
        }
        else if (temp > 25 && temp <= 51){
            b64 = temp + 71;
        }
        else if (temp > 51 && temp <= 61){
            b64 = temp - 4;
        }
        else if (temp == 62) {
            b64 = 43;
        }
        else {
            b64 = 61;
        }
        result[i] = char(b64);
    }
    return result;
}

int main()
{
    string b64_res;
    string b64_res2;
    string hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    for (int i=0;i<hex.length();i+=3) {
        string r = hex.substr(i, 3);
        uint16_t num = stoi(r, 0, 16);
        b64_res = temp_to_b64(num);
        cout << b64_res; 
    }
    return 0;
}

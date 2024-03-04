#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void point(){
    cout << "           ___________    ____" << endl;
    cout << "    ______/   \\__//   \\__/____\\" << endl;
    cout << "  _/   \\_/  :           //____\\\\" << endl;
    cout << " /|      :  :  ..      /        \\" << endl;
    cout << "| |     ::     ::      \\        /" << endl;
    cout << "| |     :|     ||     \\ \\______/" << endl;
    cout << "| |     ||     ||      |\\  /  |" << endl;
    cout << " \\|     ||     ||      |   / | \\" << endl;
    cout << "  |     ||     ||      |  / /_\\ \\" << endl;
    cout << "  | ___ || ___ ||      | /  /    \\" << endl;
    cout << "   \\_-_/  \\_-_/ | ____ |/__/      \\" << endl;
    cout << "                _\\_--_/    \\      /" << endl;
    cout << "               /____             /" <<endl;
    cout << "              /     \\           /" << endl;
    cout << "              \\______\\_________/" << endl;
}

void thumbs_up(){
    cout << endl;
    cout << "        $$$$" << endl;
    cout << "       $$  $" << endl;
    cout << "       $   $$" << endl;
    cout << "       $$   $$" << endl;
    cout << "        $    $$" << endl;
    cout << "        $$    $$$" << endl;
    cout << "         $$     $$" << endl;
    cout << "         $$      $$" << endl;
    cout << "          $       $$" << endl;
    cout << "    $$$$$$$        $$" << endl;
    cout << "  $$$               $$$$$$" << endl;
    cout << " $$    $$$$             $$$" << endl;
    cout << " $   $$$  $$$            $$" << endl;
    cout << " $$        $$$            $" << endl;
    cout << "  $$    $$$$$$            $" << endl;
    cout << "  $$$$$$$    $$           $" << endl;
    cout << "  $$       $$$$           $" << endl;
    cout << "   $$$$$$$$$  $$         $$" << endl;
    cout << "    $        $$$$     $$$$" << endl;
    cout << "    $$    $$$$$$    $$$$$$" << endl;
    cout << "     $$$$$$    $$  $$" << endl;
    cout << "       $     $$$ $$$" << endl;
    cout << "        $$$$$$$$$$\n" << endl;
}

string hexor(string init_hex, string mask_hex) {
    string result;
    stringstream ss;
    if(init_hex.length() != mask_hex.length()) {
        cout << "Uh Uh Uh! Those buffers are not of equal length" << endl;
        point();
        return "Fail";
    }
    else {
        for (int i=0;i<init_hex.length();i++) {
            string init_temp = init_hex.substr(i, 1);
            string mask_temp = mask_hex.substr(i, 1);
            uint16_t init_num = stoi(init_temp, 0, 16);
            uint16_t mask_num = stoi(mask_temp, 0, 16);
            uint16_t result_num = init_num ^ mask_num;
            ss << hex << result_num;
            result.append(ss.str());
        }
        result = ss.str();
        cout << "Nice job! Results below!" << endl;
        thumbs_up();
        return result;
    }
}

int main()
{
    string init_hex = "1c0111001f010100061a024b53535009181c";
    string mask_hex = "686974207468652062756c6c277320657965";
    cout << hexor(init_hex,mask_hex) << endl;
    return 0;
}

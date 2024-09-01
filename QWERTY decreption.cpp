#include <bits/stdc++.h>
using namespace std;
string sentence;
string translation;
// ans will be used to see if user wants to decrypt or encrypt | restart will be used to see if user wants to restart the code
char ans, restart;
bool run = true;

//C is map for encryption, while DC map is reverse C map used for decryption
map<char, char> c;
map<char, char> dc;

//Declaration of the map, fold for convinience
void declaration()
{
    c['Q'] = '1';
    c['W'] = '2';
    c['E'] = '3';
    c['R'] = '4';
    c['T'] = '5';
    c['Y'] = '6';
    c['U'] = '7';
    c['I'] = '8';
    c['O'] = '9';
    c['P'] = '0';
    c['A'] = 'Q';
    c['S'] = 'W';
    c['D'] = 'E';
    c['F'] = 'R';
    c['G'] = 'T';
    c['H'] = 'Y';
    c['J'] = 'U';
    c['K'] = 'I';
    c['L'] = 'O';
    c['Z'] = 'A';
    c['X'] = 'S';
    c['C'] = 'D';
    c['V'] = 'F';
    c['B'] = 'G';
    c['N'] = 'H';
    c['M'] = 'J';
    c[' '] = ' ';

    for(const auto& pair : c)
    {
        dc[pair.second] = pair.first;
    }
}

//Function that will encrypt the message
void encryption()
{
    for(char ch : sentence)
    {
        if(c.find(ch) != c.end())
        {
            translation.push_back(c.at(ch));
        }
        else
        {
            translation.push_back(ch); //Pushes back original character if a replacement not found
        }
    }

}
//Function that will decrypt the message
void decryption()
{
    for(char ch : sentence)
    {
        if(dc.find(ch) != c.end())
        {
            translation.push_back(dc.at(ch));
        }
        else
        {
            translation.push_back(ch);
        }
    }
}

int main()
{
    declaration();
    //Some user interface
    cout<<"======================================================================================================================== \n";
    cout<<"Welcome to QWERTY encrypt. Type out your sentence here, and we will encrypt/decrypt it for you. \n";
    cout<<"Please use only upper case letters!\n";

    //We use run boolean to check if the user wants to use the program again
    while(run)
    {
        translation.clear();
        cout<<"Do you wish to decrypt or to encrypt a message? D/E \n";
        cin>>ans;
        cin.ignore();
        cout<<"Sentence: \n";
        getline(cin, sentence);

        if(ans == 'D')
        {
            decryption();
        }
        else
        {
            encryption();
        }
        cout<<"Translate: "<<translation<<endl;
        cout<<"======================================================================================================================== \n";
        cout<<"Again? Y/N \n";
        cin>>restart;

        if(restart == 'Y')
        {
            run = true;
        }
        else
        {
            run = false;
        }

    }

    return 0;
}

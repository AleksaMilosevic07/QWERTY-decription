#include <bits/stdc++.h>
using namespace std;
string sentence;
string translation;
// ans stands for "answer" and we will use these value to see if user wants to encrypt or decrypt a message | restart is another value we will check to see if the user wants the code to run again
char ans, restart;
bool run = true;

//All characters we will use. Q = 1 and so on
char normal[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '_'};
char encrypted[]={'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'A', 'S', 'D', 'F', 'G', 'H', 'J', '_'};

map<char, char> c;

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
    for(int i = 0; i < sentence.length(); i++)
    {
        for(int k = 0; k < 27; k++)
        {
            if(sentence.at(i) == encrypted[k])
            {
                translation.push_back(normal[k]);
            }
        }
    }

}

int main()
{
    declaration();
    //Some user interface
    printf("======================================================================================================================== \n");
    printf("Welcome to QWERTY encrypt. Type out your word here, and we will encrypt/decrypt it for you. \n This is a good way to store your passwords, as you can just encrypt your name or something simple \n");
    printf("Please use only upper case letters! Use _ for spaces!\n");

    //We use run boolean to check if the user wants to use the program again
    while(run)
    {
        translation.clear();
        printf("Do you wish to decrypt or to encrypt a message? D/E \n");
        cin>>ans;
        printf("Sentence: \n");
        cin>>sentence;

        if(ans == 'D')
        {
            decryption();
        }
        else
        {
            encryption();
        }
        cout<<"Translate: "<<translation<<endl;
        printf("======================================================================================================================== \n");
        printf("Again? Y/N \n");
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

#include <bits/stdc++.h>
using namespace std;
string sentence;
string translation;
// ans stands for "answer" and we will use these value to see if user wants to encrypt or decrypt a message | restart is another value we will check to see if the user wants the code to run again
char ans, restart;
bool mama = true;
//All characters we will use. Q = 1 and so on
char normal[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '_'};
char encrypted[]={'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'A', 'S', 'D', 'F', 'G', 'H', 'J', '_'};

//Function that will encrypt the message
void encryption()
{
    for(int i = 0; i < sentence.length(); i++)
    {
        for(int k = 0; k < 27; k++)
        {
            if(sentence.at(i) == normal[k])
            {
                translation.push_back(encrypted[k]);
            }
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
    //Some user interface
    printf("======================================================================================================================== \n");
    printf("Welcome to QWERTY encrypt. Type out your word here, and we will encrypt/decrypt it for you. \n This is a good way to store your passwords, as you can just encrypt your name or something simple \n");
    printf("Please use only upper case letters! Use _ for spaces!\n");

    //Mama is a random boolean we will use to check to see if we need to go on. If you are asking yourself what does it mean, its means "mom" in Serbian. Do not ask, it is a joke you don't understand
    while(mama)
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
            mama = true;
        }
        else
        {
            mama = false;
        }

    }

    return 0;
}

#include<iostream>
#include <string> // allows use of std::string
#include <cstdlib> // for std::rand() and std::srand()
#include<time.h>
#include <cmath>
#include <cstring>
#include <cctype>



int getRandomInteger(); //function prototype

std::string getSentence(int num); //function prototype

std::string emptySentence(std::string sentence); //function prototype

std::string convertToString(char* a); //function prototype

void endTheGame(); //function prototype




int main()
{
    std::string str = getSentence(getRandomInteger()); // get a random sentence

    //convert string str to char array
    char* char_arr1;
    std::string str_obj1(str);
    char_arr1 = &str_obj1[0];

    int len = str.length();

    char ch = 's';

    std::string empty_sentence = emptySentence(str);
  

    //convert string empty_sentence to char array
    char* char_arr2;
    std::string str_obj2(empty_sentence);
    char_arr2 = &str_obj2[0];
    std::cout<<char_arr2<<'\n';

 
    //Keep going until the sentence is completed.
    while (convertToString(char_arr2) != str) 
    {
        std::cout << "Enter a character (Enter * to quit): ";
        std::cin >> ch; // get a character from the user

        if (ch == '*') //end the game if the user enters *
        {
            endTheGame();
        }

        //check if string contains the character or not
        for (int i = 0; i < len; i++)
        {
            if (char_arr1[i] == tolower(ch) || char_arr1[i] == toupper(ch))
            {
                if (char_arr1[i] == tolower(ch))
                    char_arr2[i] = tolower(ch);

                else
                    char_arr2[i] = toupper(ch);      
            }
            
        }

        std::cout<<char_arr2<<'\n';

    }

    std::cout << "==================================================================\n";
    std::cout << "==================================================================\n";
    std::cout << "Felicitación! You Win! (^_^)\n";
    std::cout << "==================================================================\n";
    std::cout << "The sentence was: " << str << '\n';
    std::cout << "==================================================================\n";
    std::cout << "==================================================================\n";

    
    return 0;
}

//This function ends the game.
void endTheGame()
{
    std::cout << "Au Revoir! (*_*)\n";
    exit(0);
}


//This function takes a sentence and returns an empty sentence.
std::string emptySentence(std::string sentence)
{
    std::string empty_sentence;
    int len = sentence.length();

    // convert string to char array
    char* char_arr;
    std::string str_obj(sentence);
    char_arr = &str_obj[0];

    for (int i = 0; i < len; i++)
    {
        if (char_arr[i] != ' ' && char_arr[i] != '.' && char_arr[i] != ',' && char_arr[i] != '?' && char_arr[i] != '!')
        {
            char_arr[i] = '_'; // replace chars (except space) with underscore
        }
    }

    // convert back char array to string
    empty_sentence = convertToString(char_arr);
    


    return empty_sentence;
}

//This function converts char array to string
std::string convertToString(char* a)
{
    std::string s = a;
    return s;
}

//This function returns a random sentence for the user to guess.
std::string getSentence(int num) 
{
    //filling strings with random sentences
    std::string str0 = "Sonya Blade uses gem5 for NoC optimization.";
    std::string str1 = "Bi Han and Kuai Liang are friends with Sonya.";
    std::string str2 = "Sonya Blade is married to Johnney Cage.";
    std::string str3 = "General Blade is in command of Special Forces.";
    std::string str4 = "Master Hassashi will have his revenge!";
    std::string str5 = "Johnney Cage is a movie star.";
    std::string str6 = "Cassie Cage is the daughter of Sonya and Johnney.";
    std::string str7 = "Ciber initiative is the work of Sektor.";
    std::string str8 = "Subzero will stop Sektor from turning Lin Kuei into Ciborgs.";
    std::string str9 = "Shadow Brotherhood is a secret organization.";

    switch (num)
    {
    case 0:
        return str0;
        break;

    case 1:
        return str1;
        break;

    case 2:
        return str2;
        break;

    case 3:
        return str3;
        break;
    
    case 4:
        return str4;
        break;

    case 5:
        return str5;
        break;

    case 6:
        return str6;
        break;

    case 7:
        return str7;
        break;

    case 8:
        return str8;
        break;

    case 9:
        return str9;
        break;
           
    default:
        return str5;
        break;
    }
}

// This function returns a random integer between 0 and 9
int getRandomInteger()
{
    // Use current time as seed for random generator
    srand(time(0));
    // get a random number between 0 and RAND_MAX
    double random_double = (std::rand() / static_cast<double>(RAND_MAX)) * 10;

    while (random_double >= 9)
    {
        random_double = (std::rand() / static_cast<double>(RAND_MAX)) * 10;
    }
    
    return round(random_double);
}



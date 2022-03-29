#include <fstream>
#include <iostream>
#include <string>

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Basic file I/O  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//File I/O in C++ works very similarly to normal I/O (with a few minor added complexities). There are 3 basic 
//file I/O classes in C++: ifstream (derived from istream), ofstream (derived from ostream), and fstream 
//(derived from iostream). These classes do file input, output, and input/output respectively. To use the 
//file I/O classes, you will need to include the fstream header.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//*************************************************************************************************************
//This is extremely simple: to open a file for reading and/or writing, simply instantiate an object of the 
//appropriate file I/O class, with the name of the file as a parameter. Then use the insertion (<<) or 
//extraction (>>) operator to write to or read data from the file. Once you are done, there are several 
//ways to close a file: explicitly call the close() function, or just let the file I/O variable go out of 
//scope (the file I/O class destructor will close the file for you).
//**************************************************************************************************************


int main()
{
    // ofstream is used for writing files
    // We'll make a file called Sample.txt
    std::ofstream outf{ "Sample.txt" };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    // We'll write two lines into this file
    outf << "Bonjour mon ami!" << '\n';
    outf << "Salut! Ca va?" << '\n';
    outf << "Ca va bien, Merci. Je doit aller a la gare dans deux minutes." << '\n';
    outf << "Daccord; A demain!" << '\n';
    outf.close(); // explicitly close the file

    //*******************************************************************************


    // ifstream is used for reading files
    // We'll read from a file called Sample.txt
    std::ifstream inf{ "Sample.txt" };

    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        std::getline(inf, strInput);
        std::cout << strInput << '\n';
    }

    return 0;

    // When outf goes out of scope, the ofstream
    // destructor will close the file

    // When inf goes out of scope, the ifstream
    // destructor will close the file
}






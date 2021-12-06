#include <iostream> //iostream is a header file

//A using directive tells the compiler to check the std namespace when resolving identifiers with no prefix.
//When using a using directive in this manner, any identifier we define may conflict 
//with any identically named identifier in the std namespace. Even worse, while an 
//identifier name may not conflict today, it may conflict with new identifiers added 
//to the std namespace in future language revisions. This was the whole point of moving 
//all of the identifiers in the standard library into the std namespace in the first place!

using namespace std; //This is a bad practice and must be avoided.

int main()
{
    //commenting is fun!
    cout << "Hello, World!\n";
    cout << "Bonjour du le monde!\n";

    /* Ha Ha Ha
     * This is a multi-line comment
     * programming is fun!
     */

    //brace initialization is preferrred to avoid data loss (best practice)
    int height{6};
    int width{7};
    int area = width * height;
    cout << "The area of a rectangle with width " << width << " and height " << height << " is " << area << endl;

    return 0;
}

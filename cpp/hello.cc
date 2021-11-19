#include <iostream>
using namespace std;

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

/// Compiled with GNU GCC Compiler
/// This program ouputs a Johnson Tropper permutation generation

#include <iostream>

using namespace std;

int main()
{
    int elements;
    bool isMobile = true;
    int count = 1;

    do {                                                // User enters amount n number of permutations greater than 1
        cout << "Enter a number of elements: ";
        cin >> elements;
    } while(elements < 1);

    int eleList[elements+1];                              // Initialization and establishment of number and direction lists
    string dirList[elements];

    for(int i = 0; i < elements; i++) {
        eleList[i] = i + 1;
        dirList[i] = "<";
    }
    cout << count << ".\t";
    for(int i = 0; i < elements; i++)                      // Output the initial set
        cout<< eleList[i] << dirList[i] << " ";
    cout<<endl;
    count++;

    while(isMobile) {                                       // Generate permutations as long as it's possible
        isMobile = false;
        int mobileIndex = elements;
        eleList[elements] = 0;

        for(int i = 0; i < elements; i ++) {                // Find the greatest mobile integer
            if(dirList[i] == "<" && i > 0){                 // If integer is not on the edge of the list and pointing away from an integer
                if(eleList[i] > eleList[i-1] && eleList[i] > eleList[mobileIndex]) {        // If Integer is greater than the one it's pointing to and
                    isMobile = true;                                                        // greater than the previously found mobile integer
                    mobileIndex = i;
                }
            }
            else if(dirList[i] == ">" && i < elements-1) {
                if(eleList[i] > eleList[i+1] && eleList[i] > eleList[mobileIndex]) {
                    isMobile = true;
                    mobileIndex = i;
                }
            }
        }

        if(isMobile) {                                      // If there is a valid mobile integer swap with the one it's pointing to
            int tempVal;
            string tempDir;
            if(dirList[mobileIndex] == "<") {               // Integers pointing left
                tempVal = eleList[mobileIndex];
                tempDir = dirList[mobileIndex];
                eleList[mobileIndex] = eleList[mobileIndex - 1];
                dirList[mobileIndex] = dirList[mobileIndex - 1];
                eleList[mobileIndex - 1] = tempVal;
                dirList[mobileIndex - 1] = tempDir;

                for(int i = 0; i < elements; i++) {         // Change the direction of every integer greater than the mobile integer
                    if(eleList[i] > eleList[mobileIndex - 1]){
                        if(dirList[i] == "<")
                            dirList[i] = ">";
                        else
                            dirList[i] = "<";
                    }
                }
            }
            else {                                          // Integers pointing right
                tempVal = eleList[mobileIndex];
                tempDir = dirList[mobileIndex];
                eleList[mobileIndex] = eleList[mobileIndex + 1];
                dirList[mobileIndex] = dirList[mobileIndex + 1];
                eleList[mobileIndex + 1] = tempVal;
                dirList[mobileIndex + 1] = tempDir;

                for(int i = 0; i < elements; i++) {         // Change the direction of every integer greater than the mobile integer
                    if(eleList[i] > eleList[mobileIndex +
                        1]){
                        if(dirList[i] == "<")
                            dirList[i] = ">";
                        else
                            dirList[i] = "<";
                    }
                }
            }
            cout << count << ".\t";
            for(int i = 0; i < elements; i++)                    // Output list of elements and directions
                cout<< eleList[i] << dirList[i] << " ";
            cout<<endl;
            count++;
        }
    }
}

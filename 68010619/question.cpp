#include <iostream>

int main()
{
int vec1[] = {1,-1,0};
int output[3];

for ( int i = 0; i < 3; i++) { //for loop to go through each element in vector
        if (vec1[i] < 0){
            output[i] = -1;
        } else if (vec1[i] == 0){
            output[i] = 0;
        } else {
            output[i] = 1;
        }
    }

    std::cout << output[0];
    std::cout << output[1];
    std::cout << output[2];
    return 0;

}

#include <iostream>

int main(){

    // Removing the ; at the end of line 6 will create a compile time error.
    std::cout << "Hello World!" << std::endl;
    
    //This is a runtime error, trying to divide by 0 is a no-no.
    int value = 7/0;
    std::cout << "value : " << value << std::endl;
    
    
      return 0;
}
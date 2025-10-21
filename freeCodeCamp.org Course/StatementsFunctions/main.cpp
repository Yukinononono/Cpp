#include <iostream>

int multNumbers(int first_param, int second_param){

    int result = first_param * second_param;
    return result;
}

int main(){
    
    std::cout << "Product : " << multNumbers(5, 10) << std::endl;

    return 0;
}
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout<<"This is the Begining!"<<std::endl;
    for(uint32_t index = 0; index < argc; index++){
        std::cout << "Arg [" << index << "] = " << argv[index] << std::endl;
    }
    return 0;
}

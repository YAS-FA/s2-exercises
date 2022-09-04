#include <iostream>
#include <string>

bool positive_number(char *str);
bool is_prime(int in_num);

int main(int argc, char* argv[])
{
    uint32_t width  = 20;
    uint32_t height = 10;
    char prime      = 'x';
    char not_prime  = '-';

    if((argc>1) && (argc<5)){
        std::cout<<"Missing arguments, please enter all optional values:"<<std::endl;
        std::cout<<"HEIGHT(positive) WIDTH(positive) PRIME_CHAR NO-PRIME_CHAR"<<std::endl;
        std::cout<<"example : 12 6 - O"<<std::endl;
        return -1;
    }
    if(argc>1) {
        if(!((positive_number(argv[1]) && positive_number(argv[2])))){
            std::cout<<"Invalid arguments"<<std::endl;
            std::cout<<"Usage abox HEIGHT(positive) WIDTH(positive) [OPTIONS]"<<std::endl;
            return -1;
        }else{
            width      = atoi(argv[1]);
            height     = atoi(argv[2]);
            prime      = argv[3][0];
            not_prime  = argv[4][0];
        }
    }

    uint32_t data = 1;
    for(uint32_t row=0; row<width; row++){
        for(uint32_t col=0; col<height; col++){
            if(is_prime(data)){
                std::cout << prime;
            } else {
                std::cout << not_prime;
            }
            data++;
        }
        std::cout << '\n';
    }


    return 0;
}

bool is_prime(int in_num) {
    if (in_num == 1) {
        return false;
    }
    uint32_t i = 2;
    while (i*i <= in_num) {
        if (in_num % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}

bool positive_number(char *str)
{
    uint32_t index = 0;
    while(str[index] != 0){
        if(!isdigit(str[index])){
            return false;
        } 
        index++;
    }
    return true;
}
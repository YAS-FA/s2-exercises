#include <iostream>
#include <string>

bool legal_int(char *str);
void print_line(int len,  char e,  char m);

int main(int argc, char** argv){
    if(argc<3){
        std::cout<<"Missing arguments"<<std::endl;
        std::cout<<"Usage abox HEIGHT(positive) WIDTH(positive) [OPTIONS]"<<std::endl;
        return -1;
    }
    if(!((legal_int(argv[1]) && legal_int(argv[2])))){
        std::cout<<"Invalid arguments"<<std::endl;
        std::cout<<"Usage abox HEIGHT(positive) WIDTH(positive) [OPTIONS]"<<std::endl;
        return -1;
    }

    uint32_t length = atoi(argv[1]);
    uint32_t width  = atoi(argv[2]);
    char star  = '*';
    char edge  = '+';
    char vchar = '|';
    char hchar = '-';
    char space = ' ';

    if(argc>3){
        if(argv[3] != std::string("wire")){
            char given_char = argv[3][0];
            edge = star = hchar = vchar = given_char;
        } 
    } else {
        edge = star = hchar = vchar = star;
    }

    print_line(width, edge, hchar);
    if(length > 2){
        for(uint32_t row = 0; row < length-2; row++){
                std::cout<<vchar;
                for(uint32_t col = 0; col < width-2; col++){
                    std::cout<<space;
                }
                std::cout<<vchar<<std::endl;
            }
       print_line(width, edge, hchar);
    }
    
    return 0;
}

void print_line(int len, char e,  char m){
    if(len > 1){
        std::cout<<e;
        for(uint32_t col = 0; col <len-2; col++){
            std::cout<<m;
        }
    }
    std::cout<<e<<std::endl;
}

bool legal_int(char *str)
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
#include <iostream>
#include <vector>

bool argument_check(int argc, char* argv[]);
void create_table(std::vector<int> y_vec, int max, int min);

int main(int argc, char* argv[]){
    bool check = argument_check(argc, argv);
    if(check){       
        int max_y = 0;
        int min_y = 0;
        uint32_t matrix_size = argc - 1;
        std::vector<int> y_vec;
        for(uint32_t index = 1; index < argc; index++){
            int new_y = std::stoi(argv[index]);
            y_vec.push_back(new_y);
            if(new_y > max_y){
                max_y = new_y;
            }
            if(new_y < min_y){
                min_y = new_y;
            }
        }
        create_table(y_vec, max_y, min_y);
    }   
    return 0;
}

void create_table(std::vector<int> y_vec, int max, int min){
    int length = max - min + 3;
    std::cout << '^' <<'\n';
    for(int row = 1; row < (max + 1); row++){
        std::cout << '|';
        int y = max + 1 - row;
        for(int col = 0; col < y_vec.size(); col++){
            if(y_vec[col] >= y)  {
                std::cout << '#' ;
            }else{
                std::cout << ' ' ;
            }
        }
        std::cout << '\n' ;
    }
    std::cout << '+' << "###################" << '\n';

    for(int row = (max + 1); row < (length - 1); row++){
        std::cout << '|';
        int y = max - row;
        for(int col = 0; col < y_vec.size(); col++){
            if(y_vec[col] <= y)  {
                std::cout << '#' ;
            }else{
                std::cout << ' ' ;
            }
        }  
        std::cout << '\n';
    }
    std::cout << 'v';
}

bool argument_check(int argc, char* argv[]){
    if(argc < 2){
        return false;
    }
    for(uint32_t index = 1; index < argc; index++){
        std::string st = argv[index];
        if(!(isdigit(st[0])) && (st[0] != '-')){
            return false;
        }
        for(uint32_t ind = 1; ind < st.size(); ind++){
            if(!(isdigit(st[ind]))){
                return false;
            }
        }
    }
    return true;
}
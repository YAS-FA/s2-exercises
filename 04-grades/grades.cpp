#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

const static uint32_t max_valid_option = 4;
const static uint32_t pass_mark = 10;

class grade{
public:
    std::string student_name;
    double mark;
    grade * head;
    grade * prev;
    grade * next;
    grade():head{NULL}{};
    grade(std::string name, double mark):student_name{name}, mark{mark}{};


    void failed_list(){
        std::cout << "Failed Students: " << '\n';
        grade* this_g = this->head;
        double best{0.0};
        std::string top_student = " ";
        while(this_g != NULL){
            if(this_g->mark < pass_mark){
                std::cout << this_g->student_name << ":  " << this_g->mark << '\n';
            }
            this_g = this_g->next;
        }
    }

    void best_mark(){
        grade* this_g = this->head;
        double best{0.0};
        std::string top_student = " ";
        while(this_g != NULL){
            if(this_g->mark > best){
                best = this_g->mark;
                top_student = this_g->student_name;
            }
            this_g = this_g->next;
        }
        std::cout << "Class Best Grade Is: " << best << " from " << top_student << '\n';
    }
    void average_mark(){
        grade* this_g = this->head;
        double sum{0.0};
        double avrg{0.0};
        uint32_t count{0};
        while(this_g != NULL){
            count++;
            sum += this_g->mark;
            this_g = this_g->next;
        }
        avrg = sum/count;
        std::cout << "Class Average Grade Is: " << avrg << '\n';
    }
    void print_all(){
        std::cout << "Class Grades: " << '\n';
        grade* this_g = this->head;
        while(this_g != NULL){
            std::cout << std::setw(20) << std::left << this_g->student_name << ": " << this_g->mark << "\n";
            this_g = this_g->next;
        }
    }
    void add_to_end(std::string name, double mark) {
        grade* new_g = new grade();
        new_g->student_name = name;
        new_g->mark  = mark;
        new_g->next  = NULL;
        // std::cout << "name : " << std::setw(25) << std::left << new_g->student_name << ", mark : " << new_g->mark << '\n';

        if(head == NULL){
            head         = new_g;
            head->next   = NULL;
            return;
        }
        grade* this_g = head;
        while(this_g->next != NULL){
            this_g = this_g->next;
        }
        new_g->prev  = this_g;
        this_g->next = new_g;
    }

};

bool check_action_validity(int action);
void process_action(int action, grade grade_inst);
void print_action_list();
void print_line( std::string input_line, int line_size);
bool create_grade_list(char * file_name, grade& this_class);


int main(int argc, char **argv)
{
    char file_name[50] = "grades.txt";
    if (argc > 1)
    {
        std::cout << "Unexpected Argument Is Discarded! " << '\n';
    }
    grade cpp_class;

    if(create_grade_list(file_name, cpp_class)){
        print_action_list();
        int new_option = -1;
        while(new_option != 0){
            std::cout << "Choose an Action>";
            std::cin >> new_option;
            if(check_action_validity(new_option)){
                process_action(new_option, cpp_class);
            }else{
                std::cout << "Invalid Action!\n";
            }
        }
    }


}

bool check_action_validity(int action)
{
    if(action > max_valid_option || action < 0){
        return false;
    }
    return true;
}

void print_line( std::string input_line, int line_size){
    std::cout << "# " << std::setw(line_size) << std::left << input_line << " #\n";
}

void print_action_list()
{
    int line_size = 33;
    std::string header_footer = "#####################################";
    std::string seperator_1 = "# --------------------------------- #";
    std::string seperator_2 = "#                                   #";
    std::string title = "#      Class Grades Management      #";

    std::cout << header_footer << '\n';
    std::cout << title << '\n';
    std::cout << seperator_1 << '\n';
    std::cout << seperator_2 << '\n';

    print_line("1. Display All Grades "             , line_size);
    print_line("2. Show The Best Grade "            , line_size);
    print_line("3. Calculate Class Average Grade "  , line_size);
    print_line("4. Get List of Failed Students "    , line_size);
    print_line("0. Exit "                           , line_size);

    std::cout << header_footer << '\n';
}

bool create_grade_list(char * file_name, grade& grade_inst){
    std::string name;
    double mark;

    std::fstream grade_file;
    grade_file.open(file_name);
    if (!grade_file.is_open()) {
        std::cout << "Grade File Not Found!\n";
        return false;
    }

    bool empty = (grade_file.peek() == std::ifstream::traits_type::eof());
    if(empty){
        std::cout << "File Is Empty !\n";
        return false;
    }

    while(!grade_file.eof()){
        grade_file >> mark >> name;
        grade_inst.add_to_end( name, mark);
    }
    grade_file.close();
    return true;
}

void process_action(int action, grade grade_inst){
    if(action == 0){
        return;
    }
    else if(action == 1){
        grade_inst.print_all();
    }
    else if(action == 2){
        grade_inst.best_mark();
    }
    else if(action == 3){
        grade_inst.average_mark();
    }
    else if(action == 4){
        grade_inst.failed_list();
    }else{
        std::cout << "Invalid Action!" << '\n';
    }
}
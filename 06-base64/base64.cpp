#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

std::string text_suffix = ".txt";
std::string bin_suffix  = ".bin";
std::string b64_suffix  = ".b64";

enum action_type{
    ACTION_DECODE = 0,
    ACTION_ENCODE = 1,
    ACTION_UNDEF  = 2
};

static const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

bool process_command(int argc, char* argv[], action_type & command_action, std::string & srce_file, std::string & dest_file );

std::string base64_encode(const char* buf, unsigned int bufLen);
std::vector<unsigned char> base64_decode(std::string const&);
static inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}


int main(int argc, char* argv[])
{   
    std::string srce_file, dest_file;
    action_type command_action = ACTION_UNDEF;
    bool valid_cmd = process_command(argc, argv, command_action, srce_file, dest_file );
    if(valid_cmd){
        int in_size = 3; //3 bytes of data for each read 
        if(command_action == ACTION_ENCODE){
            std::fstream bin_in;
            std::fstream b64_out;
            bin_in.open(srce_file, std::ios::binary| std::ios::in);
            b64_out.open(dest_file, std::ios::out);
            std::cout << "1" <<std::endl;

            std::stringstream buffer;
            buffer << bin_in.rdbuf();
            int data_len = buffer.str().size();
            std::string encoded = base64_encode(buffer.str().c_str(), data_len);
            b64_out << encoded;

            bin_in.close();
            b64_out.close();
        }else{
            std::fstream bin_out;
            std::fstream b64_in;
            bin_out.open(dest_file, std::ios::out);
            b64_in.open(srce_file , std::ios::in);
            std::cout << "2" <<std::endl;

            std::stringstream buffer;
            buffer << b64_in.rdbuf();
            int data_len = buffer.str().size();
            std::vector<unsigned char> decoded = base64_decode(buffer.str());
            for(uint32_t index=0; index<decoded.size();index++){
                bin_out << decoded[index];
            }
            bin_out.close();
            b64_in.close();
        }
    }
    return 0;
}

std::string base64_encode(const char* buf, unsigned int bufLen) {
    std::string ret;
    int i = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    int remaining = bufLen%3;
    int new_len   = bufLen + 3 - remaining;
    char* data_array = new char[new_len];
    memcpy(data_array, buf, bufLen);
    for(int index = 0; index < remaining; index++){
        data_array[bufLen + index] = '\0';
    }
    while (new_len--) {
        char_array_3[i++] = *(data_array++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0]) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1]) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2]) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            if(new_len > 0){
                for(i = 0; (i <4) ; i++){
                    ret += base64_chars[char_array_4[i]];
                }
            }else{
               for(i = 0; (i <1+remaining) ; i++){
                    ret += base64_chars[char_array_4[i]];
                } 
            }
            i = 0;
        }
    }
    if(remaining > 0){
        for(int index = 0; index < 3-remaining; index++){
            ret += '=';
        }
    }
    return ret;
}

std::vector<unsigned char> base64_decode(std::string const& encoded_string) {
    int in_len = encoded_string.size();
    int last_valid = encoded_string.find('=');
    std::string raw_input = encoded_string;
    if(last_valid > 0){
        in_len = last_valid;
        raw_input = encoded_string.substr(0, last_valid-1);
    }
    int remaining = raw_input.size() % 4;
    std::string new_input = raw_input;
    for(uint32_t  index = 0; index < remaining; index++){
        new_input.append("\0");
    }
    int new_len   = new_input.size();

    int i = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::vector<unsigned char> ret;

    // while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    while (in_len--) {
        char_array_4[i++] = encoded_string[in_++]; //in_++;
        if (i ==4) {
            for (i = 0; i <4; i++){
                char_array_4[i] = base64_chars.find(char_array_4[i]);
            }

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = (char_array_4[1] << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = (char_array_4[2] << 6) +   char_array_4[3];

            if(in_len == 0){
                for (i = 0; (i < remaining-1); i++){
                    ret.push_back(char_array_3[i]);
                }
            }else{
                for (i = 0; (i < 3); i++){
                    ret.push_back(char_array_3[i]);
                }
            }
            i = 0;
        }
    }
    return ret;
}

bool process_command(int argc, char* argv[], action_type & command_action, std::string & srce_file, std::string & dest_file ){
    if (argc < 4)
    {
        std::cout << "Missing arguments" << '\n';
        std::cout << "Enter base64 [enc/dec] SRC_FILE DST_FILE" << '\n';
        return false;
    }
    std::string EC = "enc";
    std::string DC = "dec";
    if(argv[1] == EC){
        command_action = ACTION_ENCODE;
    }else if (argv[1] == DC){
        command_action = ACTION_DECODE;
    }else{
        std::cout<<argv[1]<<'\n';
        std::cout << "Invalid arguments" << '\n';
        return false;
    }

    srce_file = argv[2];
    dest_file = argv[3];
    int txt_pos;
    int srce_pos;
    int dest_pos;

    if(command_action == ACTION_ENCODE){
        txt_pos  = srce_file.find(text_suffix);
        srce_pos = srce_file.find(bin_suffix);
        dest_pos = dest_file.find(b64_suffix);
        if(((srce_pos != std::string::npos) ||(txt_pos != std::string::npos)) && (dest_pos != std::string::npos)){
            return true;
        } else{
            return false;
        }
    }
    else if(command_action == ACTION_DECODE){
        srce_pos = srce_file.find(b64_suffix);
        dest_pos = dest_file.find(bin_suffix);
        txt_pos  = dest_file.find(text_suffix);
        if((srce_pos != std::string::npos) && ((dest_pos != std::string::npos) || (txt_pos != std::string::npos))){
            return true;
        } else{
            return false;
        }
    }
    return false;
}
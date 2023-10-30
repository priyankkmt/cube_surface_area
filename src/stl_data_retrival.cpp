#include<iostream>
#include<string>
#include<fstream>

#include"../header/stl_data_retrival.h"

stl_retrive :: stl_retrive (){}

void stl_retrive :: get_stl_data(){
    std::ifstream file("..\\resource\\model.stl",std::ios::in);
    std::fstream os("..\\resource\\data.txt",std::ios::out);

    std::string ver="";
    int count=0;
    std::string firstline;
    if(file.is_open()){
        std::cout<<"is opened file"<<std::endl;
        while(file.eof() != true){
            getline(file,ver);
            // std::cout<<ver<<std::endl;
            size_t index;
            if(ver.find("vertex") != ver.npos){
                index = ver.find("vertex");
                if(count == 0){
                    firstline=ver.substr(index+7);
                }
                os<<ver.substr(index+7)<<std::endl;
                count++;
                if(count == 3){
                    os<<firstline<<std::endl;
                    count=0;
                }
            } 
        }
    }
    else{
        std::cout<<"is not opend file"<<std::endl;
    }
    file.close();
    os.close();
}

stl_retrive :: ~stl_retrive(){}
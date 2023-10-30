#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>

#include"../header/txt_to_gnu.h"

class_txt_to_gnu :: class_txt_to_gnu(){}

void class_txt_to_gnu :: get_data_to_gnu(){
    std::ifstream f_input("..\\resource\\data.txt",std::ios::in);
    float surface_area = 0;
    std::string l1,l2,l3,l4;
    while(f_input.eof() != true){
        // std::cout<<l1<<std::endl;
        getline(f_input, l1,'\n');
        getline(f_input, l2,'\n');
        getline(f_input, l3,'\n');
        getline(f_input, l4,'\n');
        surface_area += cal_area(l1,l2,l3,l4);
        // std::cout<<"Total surface are is "<<surface_area<<std::endl;
    }
    std::cout<<"Total surface are is "<<surface_area<<std::endl;
    f_input.close();
}

float class_txt_to_gnu :: cal_area(std::string l1, std::string l2, std::string l3, std::string l4){
    float line1 = cal_line(l1,l2);
    float line2 = cal_line(l2,l3);
    float line3 = cal_line(l3,l4);
    return cal(line1,line2,line3);
}

float class_txt_to_gnu :: cal(float line1, float line2, float line3){
    float semiperimeter = (line1 + line2 + line3)/2;
    return sqrt(semiperimeter*(semiperimeter-line1)*(semiperimeter-line2)*(semiperimeter-line3));
}

float class_txt_to_gnu :: cal_line(std::string l1, std::string l2){
    std::vector<float> v1,v2;
    std::string temp;
    for(char c:l1){
        if(c == ' '){
            // std::cout<<"spaces: "<<std::endl;
            v1.push_back(stof(temp));
            temp="";
        }
        else{
            temp+=c;
        }
    }
    v1.push_back(stof(temp));
    temp="";
    for(char c:l2){
        if(c == ' '){
            v2.push_back(stof(temp));
            temp="";
        }
        else{
            temp+=c;
        }
    }
    v2.push_back(stof(temp));
    return sqrt((v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[1]-v2[1])*(v1[1]-v2[1]) + (v1[2]-v2[2])*(v1[2]-v2[2])); 
}

class_txt_to_gnu :: ~class_txt_to_gnu(){}
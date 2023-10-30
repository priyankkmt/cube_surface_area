#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>

#include"../header/stl_data_retrival.h"
#include"../header/txt_to_gnu.h"

int main(){

    char c{'n'};
    std::cout<<"Have you retrive data from stl ? "; 
    std::cin>>c;
    if(c == 'n' || c == 'N'){
        stl_retrive obj;
        obj.get_stl_data();
    }

    std::cout<<"Have you retrive data from txt? "; 
    class_txt_to_gnu obj;
    obj.get_data_to_gnu();

    std::cout << "Press any key to exit...";
    std::cin.ignore();  
    std::cin.get();
    return 0;
}
#pragma once

class class_txt_to_gnu{
    private: 
    float cal_area(std::string l1, std::string l2, std::string l3, std::string l4);
    float cal(float line1, float line2, float line3);
    float cal_line(std::string l1, std::string l2);

    public:
    class_txt_to_gnu();
    void get_data_to_gnu();
    ~class_txt_to_gnu();
};
#include "number-shape.hpp"

vector<vector<string>> getNumberShapeList() {
    vector<vector<string>> number_shape_list;

    number_shape_list.push_back({
        " _ ", 
        "| |", 
        "|_|"
    });
    number_shape_list.push_back({
        " _ ", 
        " | ", 
        " | "
    });
    number_shape_list.push_back({
        " _ ", 
        " _|", 
        "|_ "
    });
    number_shape_list.push_back({
        " _ ", 
        " _|", 
        " _|"
    });
    number_shape_list.push_back({
        "  _", 
        "|_|", 
        "  |"
    });
    number_shape_list.push_back({
        " _ ", 
        "|_ ", 
        " _|"
    });
    number_shape_list.push_back({
        " _ ", 
        "|_ ", 
        "|_|"
    });
    number_shape_list.push_back({
        " _ ", 
        "  |", 
        "  |"
    });
    number_shape_list.push_back({
        " _ ", 
        "|_|", 
        "|_|"
    });
    number_shape_list.push_back({
        " _ ", 
        "|_|", 
        " _|"
    });

    return number_shape_list;
}

vector<vector<string>> number_shape_list = getNumberShapeList();
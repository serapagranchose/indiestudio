/*
** EPITECH PROJECT, 2021
** str_to_word_array.cpp
** File description:
** str_to_word_array
*/

#include <string>
#include <vector>
#include <iterator>

std::vector<std::string> str_to_word_array(std::string string)
{
    std::vector<std::string> array;
    std::vector<std::string>::iterator it = array.begin();

    if (string.find('\n') == string.npos) {
        array.push_back(string);
        return (array);
    }   
    while (string.find('\n') != string.npos) {
        while (string.find('\n') == 0) {
            string.erase(string.begin());
        }
        array.push_back(string.substr(0, string.find('\n')));
        it =  array.end();
        it--;
        while (string.find('\n') != 0 && string.find('\n') != string.npos)
            string.erase(string.begin());
    }
    return (array);
}
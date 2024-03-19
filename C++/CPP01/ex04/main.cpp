/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:54:36 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/19 11:47:40 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string customReplace(const std::string& original, const std::string& s1, const std::string& s2) {
    std::string result = original;
    size_t pos = 0;
    while ((pos = result.find(s1, pos)) != std::string::npos) {
        result = result.substr(0, pos) + s2 + result.substr(pos + s1.length());
        pos += s2.length();
    }
    return result;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
        return (1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        return (1);
    }
    std::string line;
    std::string content;
    while (std::getline(file, line))
    {
        content += line + "\n";
    }
    file.close();
	
	content = customReplace(content, s1, s2);
    std::ofstream output(filename + ".replace");
    output << content;
    output.close();
    return (0);
}

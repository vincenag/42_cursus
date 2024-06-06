/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:28:14 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/06 13:13:58 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>


bool isInt(const std::string &s) {
    for (char c : s) {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [int] [int] ..." << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (!isInt(argv[i])){
            std::cerr << "Invalid input" << std::endl;
            return 1;
        }
        try
        {
            std::stoi(argv[i]);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Invalid input" << '\n';
            return 1;
        }     
    }
   

    std::list<int> myList;
    std::deque<int> myDeque;

    for (int i = 1; i < argc; i++) {
        myList.push_back(atoi(argv[i]));
        myDeque.push_back(atoi(argv[i]));
    }

    int count = 0;
    std::cout << "Before: ";
    bool printAll = true;
    for (auto &i : myList) {
        if (printAll) 
            std::cout << i << " ";
        else {
            std::cout << "[...]" << std::endl;
            break;
        }
        if (++count >= 5) // Incrementamos el contador y comprobamos si hemos llegado al límite
            printAll = false;
    }
    if (myList.size() <= 5)
        std::cout << std::endl;

    
    PmergeMe p;

    // Medir tiempo de ordenamiento de la lista
    auto startTimeList = std::chrono::high_resolution_clock::now();
    p.mergeSort(myList);
    auto endTimeList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> timeTakenList = endTimeList - startTimeList;

    // Medir tiempo de ordenamiento del vector
    auto startTimeDeque = std::chrono::high_resolution_clock::now();
    p.mergeSort(myDeque);
    auto endTimeDeque = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> timeTakenDeque = endTimeDeque - startTimeDeque;

    count = 0;
    std::cout << "After: ";
    printAll = true;
    for (auto &i : myList) {
        if (printAll) 
            std::cout << i << " ";
        else {
            std::cout << "[...]" << std::endl;
            break;
        }
        if (++count >= 5) // Incrementamos el contador y comprobamos si hemos llegado al límite
            printAll = false;
    }
    if (myList.size() <= 5)
        std::cout << std::endl;

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << timeTakenList.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << timeTakenDeque.count() << " us" << std::endl;

    return 0;

}
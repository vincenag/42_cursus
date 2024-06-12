/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:28:14 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/12 11:49:25 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>


bool isInt(const std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '-' && i == 0)
            continue;
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

void printList(const std::list<int> &myList) {
    int count = 0;
    bool printAll = true;
    for (typename std::list<int>::const_iterator i = myList.begin(); i != myList.end(); i++)
    {
        if (count < 5)
            std::cout << *i << " ";
        else if (printAll)
        {
            std::cout << "[...]";
            std::cout << std::endl;
            printAll = false;
        }
        count++;
    }
    if (myList.size() <= 5)
        std::cout << std::endl;
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
    }
   
    std::list<int> myList;
    std::deque<int> myDeque;

    for (int i = 1; i < argc; i++) {
        myList.push_back(atoi(argv[i]));
        myDeque.push_back(atoi(argv[i]));
    }

    std::cout << "Before: ";
    printList(myList);
    
    PmergeMe p;

    // Medir tiempo de ordenamiento de la lista
    struct timeval start, end;
    gettimeofday(&start, NULL);
    p.mergeSort(myList);
    gettimeofday(&end, NULL);
    double timeTakenList = (end.tv_sec - start.tv_sec);
    timeTakenList = (timeTakenList + (end.tv_usec - start.tv_usec));

    // Medir tiempo de ordenamiento de la deque
    gettimeofday(&start, NULL);
    p.mergeSort(myDeque);
    gettimeofday(&end, NULL);
    double timeTakenDeque = (end.tv_sec - start.tv_sec);
    timeTakenDeque = (timeTakenDeque + (end.tv_usec - start.tv_usec));
    
    std::cout << "After: ";
    printList(myList);

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << timeTakenList << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << timeTakenDeque << " us" << std::endl;

    return 0;

}
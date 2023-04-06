#include "jackson.cpp"
#include <bits/stdc++.h>
#include <chrono>
#include <stdlib.h> 
int main(){

    /*
    std::vector<int> numberOfTasks{1000, 7000, 25000, 75000, 150000, 300000, 450000, 600000, 750000, 900000, 1200000, 1500000, 1800000, 2000000};
    std::vector<Task> tasks;
    std::fstream timeFile;
    timeFile.open("time.txt");
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    double executionTime = 0;
    
    for(int i = 0; i < numberOfTasks.size(); i++){
        tasks = Jackson::getRandomTasks(numberOfTasks[i], 2, 3); 
        start = std::chrono::high_resolution_clock::now();
        Jackson::computeCForEachTask(tasks);
        end = std::chrono::high_resolution_clock::now();
        executionTime = std::chrono::duration_cast<std::chrono::microseconds> (end - start).count(); // in mircoseconds
        std::cout << executionTime << "\n";
        timeFile << executionTime << "\n";
    }
    timeFile.close();
    */


    int numberOfTasks = 10000000;
    std::vector<Task> tasks = Jackson::getRandomTasks(numberOfTasks, 1, numberOfTasks);
    auto start = std::chrono::high_resolution_clock::now();
    int FinalC = Jackson::computeCForEachTask(tasks);
    auto end = std::chrono::high_resolution_clock::now();
    double executionTime = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count(); // in nanoseconds
    std::cout << "Liczba zadań: " << numberOfTasks << " Final C: " << FinalC << " Czas wykonania: " << executionTime  << "ms" << "\n";
    return 0;
}
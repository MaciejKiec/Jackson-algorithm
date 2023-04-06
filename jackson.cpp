#include "task.cpp" 
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>



class Jackson{
    public:
    static std::vector<Task> getTasksFromFile(std::string fileName){
        std::vector<Task> tasksFromFile;
        std::string line;
        std::ifstream file(fileName);
        std::string r, p;
        int i = 0;

        std::getline(file, line); //ingore first line

        while(std::getline(file, line)){
            std::istringstream iss(line);
            iss >> r >> p;
            tasksFromFile.push_back(Task(i, stoi(r), stoi(p)));
            i++;
        }
        return tasksFromFile;
    }

    static std::vector<Task> getRandomTasks(int numberOfTasks, int minTime, int maxTime){
        std::vector<Task> randomTasks;
        std::random_device rd;
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> distr(minTime, maxTime); 

        for(int i = 0; i < numberOfTasks; i++){
            randomTasks.push_back(Task(i, distr(gen), distr(gen)));
        }

        return randomTasks;
    }

    static long long computeCForEachTask(std::vector<Task> &tasks){
        std::sort(tasks.begin(), tasks.end());
        long long C[tasks.size()];
        for (int i = 0; i < tasks.size(); i++) {
            C[i] = std::max((i > 0) ? C[i - 1] : 0,
                    tasks[i].getReleaseTime()) + tasks[i].getExecutionTime();
            tasks[i].setC(C[i]);
        }
        return C[tasks.size()-1]; 
    }

    static void printVectorOfTasks(std::vector<Task> tasks){
    for(int i = 0; i < tasks.size(); i++){
       std::cout << i << " " << tasks[i].getReleaseTime() << " " << tasks[i].getExecutionTime() << " " << tasks[i].getC() << "\n";
    }
    }

};

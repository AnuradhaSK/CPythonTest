//
// Created by anuradha on 8/2/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>
#include "Trainer.h"
#include "API.h"
#include "Python.h"
char *converter(const std::string &s) {
    char *pc = new char[s.size() + 1];
    std::strcpy(pc, s.c_str());
    return pc;
}

void Trainer::initiateTrainingLocally(std::string graphID,std::string trainingArgs){
    std::cout<<"In training initiator"<<std::endl;
    int thread_count = 3;
    std::thread *workerThreads = new std::thread[thread_count];
    for(int i=0;i<thread_count;i++){
        std::cout<<"create thread"<<std::endl;
        workerThreads[i] = std::thread(initiateTrain, trainingArgs+" --train_worker "+ std::to_string(i));
    }

    for(int i=0;i<thread_count;i++){
        workerThreads[i].join();
        std::cout<<"Joined Thread "+std::to_string(i)<<std::endl;
    }
}

bool Trainer::initiateTrain(std::string trainingArgs){
    std::cout<<"in"<<std::endl;
    std::vector<std::string> trainargs;
    std::string token;
    std::istringstream tokenStream(trainingArgs);
    while (std::getline(tokenStream, token, ' ')) {
        trainargs.push_back(token);
    }
    std::cout<<"string vector"<<std::endl;
    std::vector<char *> vc;
    std::transform(trainargs.begin(), trainargs.end(), std::back_inserter(vc), converter);
    API::train(vc.size(), &vc[0]);
    std::cout<<"Invoke API"<<std::endl;
}

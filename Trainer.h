//
// Created by anuradha on 8/2/19.
//

#ifndef CPYTHONTEST_TRAINER_H
#define CPYTHONTEST_TRAINER_H

#endif //CPYTHONTEST_TRAINER_H

#include <stdio.h>
#include <stdlib.h>
#include <thread>

class Trainer {
public:

    void initiateTrainingLocally(std::string graphID,std::string trainingArgs);

    static bool initiateTrain(std::string trainingArgs);

};

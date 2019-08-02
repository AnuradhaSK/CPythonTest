#include <iostream>
#include <thread>
#include "Trainer.h"

int main() {
    std::string graph_id = "1";
    std::string trainArgs = "CpythonTest test --graph_id "+ graph_id +" --learning_rate 0.02";
    Trainer *trainer = new Trainer();
    trainer->initiateTrainingLocally(graph_id,trainArgs);
    std::cout<<"Invoke initateTrainingLocally"<<std::endl;
    return 0;
}

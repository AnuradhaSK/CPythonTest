//
// Created by anuradha on 8/2/19.
//
#include <iostream>
#include "Python.h"
#include "API.h"
void API::train(int argc, char *argv[]) {
    std::cout<<"In API"<<std::endl;
    FILE* file;
    wchar_t* _argv[argc];
    for(int i=0; i<argc; i++){
        wchar_t *arg = Py_DecodeLocale(argv[i], NULL);
        _argv[i] = arg;
    }

    if(Py_IsInitialized() == 0){
        Py_Initialize();
    }
    PySys_SetArgv(argc, _argv);
    file = fopen("./test.py","r");
    PyRun_SimpleFile(file, "./test.py");
    Py_Finalize();
}
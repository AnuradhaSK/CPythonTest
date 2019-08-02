//
// Created by anuradha on 8/2/19.
//
#include "Python.h"
#include "API.h"
void API::train(int argc, char *argv[]) {
    FILE* file;
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    wchar_t** _argv;
    for(int i=0; i<argc; i++){
        wchar_t *arg = Py_DecodeLocale(argv[i], NULL);
        _argv[i] = arg;
    }
//    Py_SetProgramName(program);
    if(Py_IsInitialized() == 0){
        Py_Initialize();
    }
    PySys_SetArgv(argc, _argv);
    file = fopen("./test.py","r");
    PyRun_SimpleFile(file, "./test.py");
    Py_Finalize();
}
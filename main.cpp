#include <iostream>
using namespace std;
#include "process.h"
int main() {
   TaskList t;
//    System Idle Process              0 Services                   0          8 K
//    System                           4 Services                   0      3,852 K
//    Registry                       148 Services                   0     33,204 K
//    smss.exe                       632 Services                   0      1,088 K
   t.AddProcess(Process("System Idle Process",0,"Services",0,8));
   t.AddProcess(Process("System",4,"Services",0,3852));
   t.AddProcess(Process("Registry",148,"Services",0,33204));
   t.AddProcess(Process("smss.exe",632,"Services",0,1088));
   t.DisplayProgram();
}

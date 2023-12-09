#ifndef TASKMANAGER_PROCESS_H
#define TASKMANAGER_PROCESS_H
#include <bits/stdc++.h>
using namespace std;
class Process
{
public:
    int Memory,PID,Session;
    string Image_name,Session_name;
    Process(string image_name,int pid, string session_name, int session, int memory);
    Process();
    bool operator <(const Process& other) const;
    bool operator >(const Process& other) const;
};
class TaskList:public Process
{
private:
    set<Process>List;
public:
    TaskList();
    void AddProcess(Process p);
    void RemoveProcess(Process p);
    void DisplayProgram();


};

#endif //TASKMANAGER_PROCESS_H

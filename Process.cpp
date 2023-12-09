//
// Created by JOO🖤 on 12/10/2023.
//

#include "Process.h"

Process::Process(string image_name,int pid, string session_name, int session, int memory)
{
    Image_name=image_name;
    PID=pid;
    Session_name=session_name;
    Session=session;
    Memory=memory;
}

bool Process::operator<(const Process &other) const {
    if (PID != other.PID)
        return PID < other.PID;

    return Memory < other.Memory;
}

Process::Process() {}

bool Process::operator>(const Process &other) const {
    if (PID != other.PID)
        return PID > other.PID;

    return Memory > other.Memory;
}

TaskList::TaskList() : Process(){}

void TaskList::AddProcess(Process p) {
    List.insert(p);
}

void TaskList::RemoveProcess(Process p) {
    List.erase(p);
}

void TaskList::DisplayProgram() {
    int Sz[5];
    Sz[0]=11;
    Sz[1]=4;
    Sz[2]=13;
    Sz[3]=9;
    Sz[4]=10;
    for(auto p:List)
    {
        Sz[0]= max((int)p.Image_name.size(),Sz[0]);
        Sz[1]= max((int)to_string(p.PID).size(),Sz[1]);
        Sz[2]= max((int)p.Session_name.size(),Sz[2]);
        Sz[3]= max((int)to_string(p.Session).size(),Sz[3]);
        Sz[4]= max((int)to_string(p.Memory).size(),Sz[4]);
    }
    cout<<"Image Name"<<string (max(0,Sz[0]-9),' ')
    <<"PID"<<string(max(0,Sz[1]-2),' ')
    <<"Session Name"<<string (max(0,Sz[2]-11),' ')
    <<"Session#"<<string (max(0,Sz[3]-7),' ')
    <<"Mem Usage"<<string (max(0,Sz[4]-8),' ')<<'\n';
    for (int i = 0; i < 5; ++i) {
        cout<<string(Sz[i],'=')<<' ';
    }
    cout<<'\n';
    for(auto p:List)
    {
        cout<<p.Image_name<<string (max(0,(Sz[0]-(int)p.Image_name.size())+1),' ')
            <<p.PID<<string(max(0,Sz[1]-(int)(to_string(p.PID)).size()+1),' ')
            <<p.Session_name<<string (max(0,Sz[2]-(int)p.Session_name.size()+1),' ')
            <<p.Session<<string (max(0,Sz[3]-(int)to_string(p.Session).size()+1),' ')
            <<p.Memory<<string (max(0,Sz[4]-(int) to_string(p.Memory).size()+1),' ')<<'\n';
    }
}

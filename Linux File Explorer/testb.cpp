#include<iostream>
#include<algorithm>
#include<string>
#include"RenderContext.h"
int main(){
    RenderContext r;
    r.setComdAndRun("ls");
    int his = 1;
     string hiscomd  = to_string(his)+"." ;
    string s = std::to_string(his);
    //string s = r.getNthOutput(0);
    std::cout <<hiscomd<< std::endl;
}

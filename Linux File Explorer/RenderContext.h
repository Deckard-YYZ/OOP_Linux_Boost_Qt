/* 
Author: Yunzhuo Zhang
Date: 2021/10/3
The header file of class RenderContext
*/
#ifndef RENDER_H
#define RENDER_H

#include <boost/process.hpp>
#include<iostream>
#include<algorithm>
#include<string>
#include<QtCore/QString>
#include<vector>

class RenderContext {
private:
std::string command_text; //the current command
std::string result; //the current output(result)
std::vector<std::string> outputs;//the vector stores all strings
int ExitNum;//the exit status
public:
RenderContext();
std::string getcommand();
std::vector<std::string> getoutputs();
std::string getResult();
std::string getNthOutput(int n);
int getexitStatus();
QString setComdAndRun(std::string s);
void setcomd(std::string s);
void setResult(std::string s);
void setExit(int i);
~RenderContext();


};


#endif

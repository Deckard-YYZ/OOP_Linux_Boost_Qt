/* 
Author: Yunzhuo Zhang 
Date: 2021/10/3  
The file of class RenderContext, which recieves command from GUI user input
and create a sub process runing the command, set everything neccessary then return output to GUI.
*/
#include"RenderContext.h"
using namespace boost::process;
using namespace std;
/**
 * Fuction: RenderContext
 * Description: constructor
 * Parameter: None
 * Return: None
*/
RenderContext::RenderContext(){
vector<string> outputs;//string vector contains all history outputs
string command_text;
string result;
ExitNum = 9;
}
/**
 * Fuction: getexitStatus
 * Description: return exit status
 * Parameter: None
 * Return: the exit status number
*/
int RenderContext::getexitStatus(){
    return ExitNum;
}
/**
 * Fuction: getoutputs
 * Description: get all the history outputs store in the vector
 * Parameter: None
 * Return: vector store all history outputs
*/
vector<string> RenderContext::getoutputs(){
    return outputs;
}
/**
 * Fuction: getcommand
 * Description: get the command of current runing command
 * Parameter: None
 * Return: the command string
*/
string RenderContext::getcommand(){
    return command_text;
}
/**
 * Fuction: getResult
 * Description: get the result of current runing command
 * Parameter: None
 * Return: the output(result) string
*/
string RenderContext::getResult(){
    return result;
}
/**
 * Fuction: getNthOutput
 * Description: get the history result of the Nth command
 * Parameter: int command index
 * Return: the output(result) string at Nth index
*/
string RenderContext::getNthOutput(int n){
    return outputs[n];
}
/**
 * Fuction: setComdAndRun
 * Description: set the current runing command and create a subprocess to run it.
 * Parameter: string the command string
 * Return: the result(output of the command) as a QString
*/
QString RenderContext::setComdAndRun(string s){
    command_text = s;
    string one_comd;
    ipstream pipe_stream;
    try{
    child c(command_text, (std_out & std_err) > pipe_stream);
    string line;
    while (pipe_stream && std::getline(pipe_stream, line)) {
        one_comd = one_comd + line+'\n';
    }
    
    
    c.wait();
    this->setExit(1);
    }catch(boost::process::process_error e){
        one_comd = one_comd + command_text + ": command not found.\n";
        this->setExit(-1);
    }
    outputs.push_back(one_comd);
    this->setResult(one_comd);
    return QString::fromStdString(one_comd);

}
/**
 * Fuction: setResult
 * Description: set the result of current runing comd.
 * Parameter: string the result
 * Return: None
*/
void RenderContext::setResult(string s){
    result = s;
}
/**
 * Fuction: setcomd
 * Description: set the comd
 * Parameter: string the comd
 * Return: None
*/
void RenderContext::setcomd(string s){
    command_text = s;
}
/**
 * Fuction: setExit
 * Description: set the exit status
 * Parameter: string the int exit status
 * Return: None
*/
void RenderContext::setExit(int i){
    ExitNum = i;
}
/**
 * Fuction: ~RenderContext
 * Description: the empty destorctor 
 * Parameter: None
 * Return: None
*/
RenderContext::~RenderContext(){
    
}



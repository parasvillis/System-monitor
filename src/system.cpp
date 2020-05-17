#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include <bits/stdc++.h>

#include "process.h"
#include "processor.h"
#include "system.h"


#include "linux_parser.h"
using namespace LinuxParser;

using std::set;
using std::size_t;
using std::string;
using std::vector;

using std::sort;

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes

bool System::compareProcesses(Process a, Process b) {
  return b < a;
}

vector<Process>& System::Processes() {
  
  processes_ = {};
  vector<int> p_ids = LinuxParser::Pids();
  
  for(int& p_id: p_ids) {
    
    Process p;
    int& p_pid = p.Pid();
    float& cpuUtil = p.CpuUtilization();
    
    p_pid = p_id;
    
    long time = LinuxParser::UpTime() - LinuxParser::UpTime(p_id);
    cpuUtil = ((float)ActiveJiffies(p_id) / sysconf(_SC_CLK_TCK)) / time;
    processes_.push_back(p);
    
  }
  
  sort(processes_.begin(), processes_.end(), compareProcesses);
  
  return processes_; 
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { 
  return LinuxParser::Kernel(); 
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() {
  return LinuxParser::MemoryUtilization();
}

// TODO: Return the operating system name
std::string System::OperatingSystem() {
  return LinuxParser::OperatingSystem();
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() {
  return LinuxParser::RunningProcesses();
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() {
  return LinuxParser::TotalProcesses();
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() {
  return LinuxParser::UpTime();
}



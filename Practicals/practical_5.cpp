#include <iostream>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
using namespace std;

int main(){
    struct utsname s1;
    int i = uname(&s1);
    if(i==0){
        cout<<"Operating System name : "<<s1.sysname<<endl;
        cout<<"Version name : "<<s1.version<<endl;
        cout<<"Machine name : "<<s1.machine<<endl;
        // system("grep-m1 'model name'/proc/CPUinfo");
    }else
        cout<<"Error"<<endl;
        
    return 0;
}

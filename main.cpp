#include "func.hpp"

int main(int argc, char** argv)
{   
    cout<<NAMEOFTHIS<<endl;
    if(argc==1){
        mode=New;
        name="untitled";
    }else if (argc==2){
        mode=Write;
        name=argv[1];
    }else{
        mode=Read;
        name=argv[1];
    }
    if (!init()){
        cout<<"Error occurred during initialization."<<endl;
        cout<<"Check locations of font file and target text file."<<endl;
        exit(1);
    }   
    

    mainloop();
    
    return 0;
}
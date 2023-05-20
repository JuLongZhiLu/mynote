#include<iostream>
#include<fstream>
#include<cstring>
int main(int argc,char* argv[]){
	if(argc!=1){
		if(strcmp(argv[0],"myNote")==0){
			std::ofstream ofs("data.txt",std::ios::app);
			std::string line(argv[1]);
			line=line+"\n";
			ofs<<line;
			ofs.close();
			std::cout<<"Save successfully"<<std::endl;
			return 0;
		}
	}

	while(true){
		std::ofstream ofs("data.txt",std::ios::app);
		std::cout<<"myNote> ";
		std::string line;
		std::getline(std::cin, line);
		
		if(line==".quit"){
		 	 ofs.close();
		 	 break;
		}
		if(line==".version"){
			std::cout<<"Welcome to myNote"<<std::endl;
			std::cout<<"Author:JuLongZhiLu"<<std::endl;
			std::cout<<"Version:1.0.0 (2023/5/19)"<<std::endl;
          		std::cout<<"From:2023/5/19"<<std::endl;
			std::cout<<"If you want to know more,please go to CSDN or Github"<<std::endl;
			ofs.close();
			continue;
		}
		
		line=line+"\n";
		ofs<<line;
		ofs.close();
	}
}

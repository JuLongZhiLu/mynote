#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#define TEST 

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#include <Windows.h>
	#include <direct.h>
	#define mkdir(path,mode) _mkdir(path)
	#define folder_path "C:\\mynoteData"
	#define default_text_file "C:\\mynoteData\\mynoteDefaultData.txt"
        bool isFolderExist(const std::string& path){
        	DWORD dwAttrib = GetFileAttributesA(path.c_str());
        	return (dwAttrib != INVALID_FILE_ATTRIBUTES && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
    	}
#elif __unix__
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <unistd.h>
	#include <cstdlib>
	#define mkdir(path,mode) mkdir(path,mode)
	
	const char* home_dir = getenv("HOME");
    	std::string path = std::string(home_dir) + "/mynoteData";
	std::string text_file_path=path+"/mynoteDefaultData.txt";
	#define folder_path path
	#define default_text_file text_file_path.c_str()
	bool isFolderExist(const std::string& path){
        	struct stat info;
        	if (stat( path.c_str(), &info ) != 0){
            		return false;
        	}
        	else if(info.st_mode & S_IFDIR){
            		return true;
		}
        	else{
            		return false;
        	}
 	}
#endif

bool createFolder(const std::string& path){
	int result=mkdir(path.c_str(),0777);
	if(result==-1){
		return false;
	}
	else{
		return true;
	}
}

int main(int argc,char* argv[]){
	std::string dir_path=folder_path;
	if(isFolderExist(dir_path)){
		//do nothing
		//TEST std::cout<<"FolderExist"<<std::endl;
	}	 
	else{
		bool ret= createFolder(dir_path);
		TEST if(ret==true) std::cout<<"Create folder /home/mynoteData successfully"<<std::endl;	
	}
	
	if(argc!=1){
		if(strcmp(argv[0],"mynote")==0){
			std::ofstream ofs(default_text_file,std::ios::app);
			std::string line(argv[1]);
			line=line+"\n";
			ofs<<line;
			ofs.close();
			std::cout<<"Save successfully"<<std::endl;
			return 0;
		}
	}

	while(true){
		std::ofstream ofs(default_text_file,std::ios::app);
		std::cout<<"mynote> ";
		std::string line;
		std::getline(std::cin, line);
		
		if(line==".quit"){
		 	 ofs.close();
		 	 break;
		}
		if(line==".version"){
			std::cout<<"Welcome to mynote"<<std::endl;
			std::cout<<"Author:JuLongZhiLu"<<std::endl;
			std::cout<<"Version:1.0.8 (2023/5/20)"<<std::endl;
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



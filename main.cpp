#ifdef __GNUC__
    #include <ext/stdio_sync_filebuf.h>    
    typedef __gnu_cxx::stdio_sync_filebuf<char> popen_filebuf;
#elif _MSC_VER
    #include<fstream>
    typedef std::filebuf popen_filebuf;
    FILE*(*popen)(const char*, const char*) = _popen;
#else
    static_assert(false, "popen_filebuf is not available for this platform");
#endif

#include <cstdlib>
#include <string>

#include <iostream>
#include <filesystem>

#ifndef __has_include
  static_assert(false, "__has_include not supported");
#else
#  if __has_include(<filesystem>)
#    include <filesystem>
     namespace fs = std::filesystem;
#  elif __has_include(<experimental/filesystem>)
#    include <experimental/filesystem>
     namespace fs = std::experimental::filesystem;
#  elif __has_include(<boost/filesystem.hpp>)
#    include <boost/filesystem.hpp>
     namespace fs = boost::filesystem;
#  endif
#endif
// #include "headers/graph.h"
// #include "headers/aristotle.h"


int main(int argc, const char **argv) {
	/*
	auto CFGCategory = llvm::cl::OptionCategory("CFG");
	clang::tooling::CommonOptionsParser OptionsParser(argc, argv, CFGCategory);
	clang::tooling::ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());
	// run the Clang Tool, creating a new FrontendAction.
	Tool.run(new ToolFactory);
	*/
	std::string program_name = argv[1];
	std::cout << "Current path is " << fs::current_path() << '\n';
	
	// return -1;
	// std::system(("sources/evaluate.py " + program_name).c_str());
	// std::cout << "First Call" << std::endl;
	// std::cout << std::system(("python sources/evaluate.py " + program_name).c_str()) << std::endl;

	FILE* file = popen("prog -opt | sources/evaluate.cpython-37.pyc", "w");

    popen_filebuf buffer(file);
    std::ostream fileStream(&buffer);

    fileStream << "some data";
	int i = 0;
	while(i--)
	{
		// std::cout << std::system(("python sources/evaluate.py " + program_name + " " + std::to_string(i)).c_str()) << std::endl;
	}

	





	return 0;
}


/* To get file coverage we first call compiler with follwoing commands
	1) g++ -o test	-fprofile-arcs -ftest-coverage test.cpp 
	2) we run the program with tests
	3.1) we call follwiing program next
	3.2) gcov test.cpp
	4) we read our what our gcov returns*/
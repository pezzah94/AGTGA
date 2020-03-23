#include <cstdlib>


#include "headers/graph.h"
#include "headers/aristotle.h"


int main(int argc, const char **argv) {
	/*
	auto CFGCategory = llvm::cl::OptionCategory("CFG");
	clang::tooling::CommonOptionsParser OptionsParser(argc, argv, CFGCategory);
	clang::tooling::ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());
	// run the Clang Tool, creating a new FrontendAction.
	Tool.run(new ToolFactory);
	*/
	std::string program_name = argv[1];

	std::system(("python sources/evaluate.py " + program_name).c_str());
	// std::cout << std::system(("python sources/evaluate.py " + program_name).c_str()) << std::endl;


	// int i = 10;
	// while(--i)
	// {
	// 	std::cout << std::system("./_test") << std::endl;
	// 	std::cout << std::system(std::string("gcov " + program_name).c_str()) << std::endl;
	// 	std::system("rm test.cpp.gcov");
	// }

	// or call python script here










	return 0;
}


/* To get file coverage we first call compiler with follwoing commands
	1) g++ -o test	-fprofile-arcs -ftest-coverage test.cpp 
	2) we run the program with tests
	3.1) we call follwiing program next
	3.2) gcov test.cpp
	4) we read our what our gcov returns*/
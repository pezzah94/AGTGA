#ifndef ARISTOTLE_H
#define ARISTOTLE_H
// Clang includes
#include <clang/AST/ASTConsumer.h>
#include <clang/AST/ASTContext.h>
#include <clang/AST/Stmt.h>

#include <clang/ASTMatchers/ASTMatchFinder.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/Analysis/CFG.h>
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/LangOptions.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>

#include <iostream>
#include <string>

// LLVM includes
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/raw_ostream.h>

#include "../sources/graph.cpp"

//ponoviti ovu zavrzlamu sa makefile-om i sa inkludovanjem stvari

using namespace clang;
#define d(X) std::cout << X << '\n';

Graph g;


class Aristotle {


class MyCallback : public clang::ast_matchers::MatchFinder::MatchCallback {
 public:
  MyCallback(){}
  void run(const clang::ast_matchers::MatchFinder::MatchResult &Result){
    const auto* Function = Result.Nodes.getNodeAs<clang::FunctionDecl>("fn");
    const auto CFG = clang::CFG::buildCFG(Function,
                                        Function->getBody(),
                                        Result.Context,
                                        clang::CFG::BuildOptions());
    
    
    //Function->getBody()->dumpColor();
    //Function->getBody()->dumpPretty(*Result.Context); //korisno stampa kod iz Stmt
    //return;
    //Function->getBody()->viewAST();  // ovo kaze da nemam instaliran gv 
    //auto f = (*CFG).front(); //tipa CFGBlock
    //auto elementf = f.front();
    
    //elementf.dump(); 
    
//     elementf.dumpToStream(std::cout); //ne postoji
    
//     std::cout << elementf; // ne moze da se pise na izlaz
    
  //  print_elem(std::cout, ,elementf);
    //std::cout << f.getLabel();
    //Graph g;
    for (const auto* blk : *CFG){
       blk->dump();    
       // Prints Basic Blocks.
       //blk->getLabel()->dump();
       
//        std::cout << blk->Elements;
//         for(std::reverse_iterator<ImplTy::iterator> it=blk->begin; it != blk->end();it++)
//             (*it)->dump();
       
       //blk->dumpColor(); 
       
       //d(blk->getBlockID());
      //auto succs = blk->succs();  
      
      //obilazak unutrasnjih
       //ovde dodati proveru ako ima sledbenika, jer dodaje 0--> , ovako nesto 
      for(const auto &s : blk->succs()){
                //std::cout << s.getBlockID();// znaci s je AdjescentBlock i nema getBlockID
          
          //razjasniti sta je tacno reachableBlock
          if(s.isReachable()) {     
            //d(s.getReachableBlock()->getBlockID());
            g.add_edge(
                std::to_string(blk->getBlockID()),
                std::to_string(s.getReachableBlock()->getBlockID())
            
            );
          }
        }
      
      
      // do something more.
    }
    
    //g.print_graph(std::cout);
    	/*static int counter = 0;
		std::cout << CFG->getNumBlockIDs() << std::endl;
		std::cout << CFG->isLinear() << std::endl;
		CFG->dump(nullptr, true);
        std::cout << typeid(*CFG).name();
        return;
		for (const auto* blk : *CFG){
			std::cout << "#####" << counter << "#####" << std::endl;
			blk->dump();				// Prints Basic Blocks
			std::cout << "Block size : "<< blk->size() << std::endl;
			std::cout << "Block succ size : " << blk->succ_size() << std::endl;
			std::cout << "Block pred size : " << blk->pred_size() << std::endl;
			std::cout << "Stmt label : "  << blk->getLabel() << std::endl;
			std::cout << "Block ID : "  << blk->getBlockID() << std::endl;
			std::cout << blk->succs();
            
            std::cout << "###########" << std::endl;
	
		}
		counter++;*/
		
    
    
  }
};

class MyConsumer : public clang::ASTConsumer {
public:
  explicit MyConsumer() : handler() {
    const auto matching_node = clang::ast_matchers::functionDecl(clang::ast_matchers::isExpansionInMainFile()).bind("fn");
    match_finder.addMatcher(matching_node, &handler);
  }
  void HandleTranslationUnit(clang::ASTContext& ctx) {
    match_finder.matchAST(ctx);
  }  
private:  
  MyCallback handler;  
  clang::ast_matchers::MatchFinder match_finder;  
};

class MyFrontendAction : public clang::ASTFrontendAction {
 public:
  std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(clang::CompilerInstance&, llvm::StringRef) override {
    return std::make_unique<MyConsumer>();
  }
};

struct ToolFactory : public clang::tooling::FrontendActionFactory {
  clang::FrontendAction* create() override {
    return new MyFrontendAction();
  }
};

public:
    Aristotle (int argc, const char **argv){
       
        auto CFGCategory = llvm::cl::OptionCategory("CFG");
        clang::tooling::CommonOptionsParser OptionsParser(argc, argv, CFGCategory);
        clang::tooling::ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());
        // run the Clang Tool, creating a new FrontendAction.
        Tool.run(new ToolFactory);
    }
//     void make_graph(int argc, const char **argv){
//         auto CFGCategory = llvm::cl::OptionCategory("CFG");
//         clang::tooling::CommonOptionsParser OptionsParser(argc, argv, CFGCategory);
//         clang::tooling::ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());
//         run the Clang Tool, creating a new FrontendAction.
//         Tool.run(new ToolFactory);
//     }
    Graph get_graph() const {
        return g; 
    };


};
// int main(int argc, const char **argv) {
//   auto CFGCategory = llvm::cl::OptionCategory("CFG");
//   clang::tooling::CommonOptionsParser OptionsParser(argc, argv, CFGCategory);
//   clang::tooling::ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());
//   run the Clang Tool, creating a new FrontendAction.
//   return Tool.run(new ToolFactory);
// }





#endif // ARISTOTLE_H

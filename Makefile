# TARGET := AGTA

TARGET := main

HEADERS_DEPENDENCIES :=  \
	headers/aristotle.h \
	headers/graph.h

# SOURCES_DEPENDENCIES := \
#	sources/aristotle.cpp \
#	sources/graph.cpp

HEADERS := -isystem `llvm-config-9 --includedir`
WARNINGS := -Wall -Wextra -pedantic -Wno-unused-parameter 
CXXFLAGS := $(WARNINGS) -std=c++14 -fno-exceptions -fno-rtti -O3 -Os
LDFLAGS := `llvm-config-9 --ldflags`

CLANG_LIBS := \
	-lclangFrontendTool \
	-lclangRewriteFrontend \
	-lclangDynamicASTMatchers \
	-lclangToolingCore \
	-lclangTooling \
	-lclangFrontend \
	-lclangASTMatchers \
	-lclangParse \
	-lclangDriver \
	-lclangSerialization \
	-lclangRewrite \
	-lclangSema \
	-lclangEdit \
	-lclangAnalysis \
	-lclangAST \
	-lclangLex \
	-lclangBasic

LIBS := $(CLANG_LIBS) `llvm-config-9 --libs --system-libs`

all: main

.phony: clean
.phony: run

clean:
	rm $(TARGET) || echo -n ""


main: graph.o aristotle.o
	@echo "Creating main.."
	$(CXX) $(HEADERS) $(LDFLAGS) $(CXXFLAGS) $(TARGET).cpp $(LIBS) -o $(TARGET)
	rm -rvf *.o

graph.o: sources/graph.cpp $(HEADERS_DEPENDENCIES)
	@echo "Creating object.."
	$(CXX) $(HEADERS) $(LDFLAGS) $(CXXFLAGS) -c sources/graph.cpp $(LIBS) 

aristotle.o: sources/aristotle.cpp $(HEADERS_DEPENDENCIES)
	@echo "Creating object.."
	$(CXX) $(HEADERS) $(LDFLAGS) $(CXXFLAGS)	-c sources/aristotle.cpp $(LIBS)
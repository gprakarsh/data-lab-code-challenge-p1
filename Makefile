# =================== SETTINGS ===================
EXENAME := EquivalentExpression

CXX			:=	clang++
CXXFLAGS	:=  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic -Iheaders
LD			:=	clang++
LDFLAGS		:=	-std=c++1y -stdlib=libc++ -lc++abi -lm -Iheaders
ALL_HEADERS	:=	headers/BFS.h headers/Edge.h headers/FullBFS.h headers/Graph.h headers/Mock.h headers/SCCGraph.h headers/Vertex.h headers/ArgumentParser.h
#----------------------------------------------


.PHONY: all-data all clean

# $^ = all dependencies
# $< = first dependency
# $@ = target

all : $(EXENAME)

$(EXENAME): EquivalentExpression.o 
	$(LD) $^ $(LDFLAGS) -o $@

EquivalentExpression.o: EquivalentExpression.cpp 
	$(CXX) $(CXXFLAGS) $< -o $@

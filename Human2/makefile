# test
MAIN := HumanTest.exe
HEADER := Human.h
OBJECT := Human.cpp HumanTest.cpp
CXX := g++
CXXOPTION = -g -O2 -c 
O_OBJECT := $(OBJECT:.cpp=.o)

HELLO: $(O_OBJECT)
	$(CXX)  -o  $(MAIN) $(O_OBJECT)

%.o : %.c $(HEADER)
	$(CXX) $(CXXOPTION) $< -o $@

.PHONY: clean
clean:
	rm -f *.out *.o
clean2:
	rm -f *.exe *.out *.o
run:
	./$(MAIN)

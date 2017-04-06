# test
MAIN := list1.exe
HEADER := 
OBJECT := list1.cpp
CXX := g++
CXXOPTION = -O2 -Werror -c 
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

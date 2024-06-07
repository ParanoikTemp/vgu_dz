.PHONY: all clean install

OBJFILES = main.o calculations.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
  g++ -o $(TARGET) $(OBJFILES)

main.o: main.cpp
  g++ -c main.cpp

calculations.o: calculations.cpp calculations.h
  g++ -c calculations.cpp

clean:
  rm -rf $(TARGET) $(OBJFILES) *~

install: $(TARGET)
  mkdir -p ~/bin
  mv $(TARGET) ~/bin/$(TARGET)

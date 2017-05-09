
CXXFLAGS = -g -I./src -I./includes -Wno-write-strings
LDFLAGS = 
LIBS = -lcurl

vpath %.hpp ./src ./includes
vpath %.cpp ./src

all: weatherReporter

weatherReporter: weatherReport.o
	g++ ${CXXFLAGS} ${LDFLAGS} -o ./bin/weatherReporter.exe $+ ${LIBS}

weatherReport.o: weatherReport.cpp


clean:
	rm *.o



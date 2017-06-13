
CXXFLAGS = -g -I./src -I./includes -I./ -I/usr/include/libxml2 -Wno-write-strings
LDFLAGS = 
LIBS = -lcurl -lxml2

vpath %.hpp ./src ./includes
vpath %.cpp ./src

all: weatherReporter

weatherReporter: weatherReport.o xmlparser.o curlWrapper.o
	g++ ${CXXFLAGS} ${LDFLAGS} -o ./bin/weatherReporter.exe $+ ${LIBS}

weatherReport.o: weatherReport.cpp

xmlparser.o: xmlparser.cpp xmlparser.hpp

curlWrapper.o: curlWrapper.cpp curlWrapper.hpp

clean:
	rm *.o



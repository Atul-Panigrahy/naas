all: naas

naas: main.o subscriber.o agent.o manager.o
		g++ main.o subscriber.o agent.o manager.o -o naas

main.o: main.cpp
		g++ -c main.cpp

subscriber.o: subscriber.cpp
		g++ -c subscriber.cpp

agent.o: agent.cpp
		g++ -c agent.cpp

manager.o: manager.cpp
		g++ -c manager.cpp

clean:
		rm -rf *o naas
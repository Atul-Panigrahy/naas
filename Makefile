all: naas

naas: main.o subscriber.o agent.o manager.o
		g++ main.o subscriber.o agent.o manager.o -o naas

main.o: main.cpp
		g++ -c main.cpp

user.o: user.cpp
		g++ -c user.cpp

subscriber.o: subscriber.cpp
		g++ -c subscriber.cpp

agent.o: agent.cpp
		g++ -c agent.cpp

manager.o: manager.cpp
		g++ -c manager.cpp

payment.o: payment.cpp
		g++ -c payment.cpp

cash.o: cash.cpp
		g++ -c cash.cpp

cheque.o: cheque.cpp
		g++ -c cheque.cpp

clean:
		rm -rf *o naas
client: requests.cpp client.cpp dirtyModules.cpp
	g++ requests.cpp client.cpp dirtyModules.cpp -lcurl -o client -Wall

test: requests.cpp test.cpp dirtyModules.cpp
	g++ -g requests.cpp test.cpp dirtyModules.cpp -lcurl -o test -Wall 
clean:
	rm -r *.o teste client

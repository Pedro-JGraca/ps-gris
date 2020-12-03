#macros
CC=						g++
LD=						g++

CFLAGS=		 			-fPIE -Wall -c -g -I/usr/include/python3.8
LFLAGS=		 			-fPIE -Wall -pthread

CFLAGS2 =  -I/usr/include/python3.8 -I/usr/include/python3.8  -Wno-unused-result -Wsign-compare -fdebug-prefix-map=/build/python3.8-fKk4GY/python3.8-3.8.2=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector -Wformat -Werror=format-security  -DNDEBUG -fwrapv -O3 -Wall 

LFLAGS_AFTER= 			-lpython3.8

CLIENT_OBJS=			client.o
CLIENT_MANAGER_OBJS=	clientManager.o

OBJECTS=				$(CLIENT_OBJS)\
						$(CLIENT_MANAGER_OBJS)

CLIENT_FILE=			client.cpp
CLIENT_MANAGER_FILE=	clientManager.cpp


FILES=	 				$(CLIENT_FILE)\
						$(CLIENT_MANAGER_FILE)


EXEC= client

#rules

all:					$(EXEC)\
						$(OBJECTS)\
						$(FILES)

$(EXEC): $(OBJECTS)
	$(LD) $(LFLAGS)  $(OBJECTS) -o $@ $(LFLAGS_AFTER)

$(CLIENT_OBJS): 		$(CLIENT_FILE)

$(CLIENT_MANAGER_OBJS):	$(CLIENT_MANAGER_FILE)

$(OBJECTS): 
	$(CC) $(CFLAGS) $(CFLAGS2) $? -o $@

clean:
	rm $(OBJECTS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJECTS)
	rm $(EXEC)
#macros
CC=						g++
LD=						g++

CFLAGS=		 			-Wall -c
LFLAGS=		 			-Wall

LFLAGS_AFTER= 			-lcurl

CLIENT_OBJS=			client.o

DIRTY_MODULES_OBJS=		dirtyModules.o

SIMPLE_CURL_OBJS=		simpleCurl.o

HTTP_MANAGER_OBJS=		httpManager.o

OBJECTS=				$(CLIENT_OBJS)\
						$(DIRTY_MODULES_OBJS)\
						$(SIMPLE_CURL_OBJS)\
						$(HTTP_MANAGER_OBJS)

CLIENT_FILE=			client.cpp

DIRTY_MODULES_FILE=		dirtyModules.cpp

SIMPLE_CURL_FILE=		simpleCurl.cpp

HTTP_MANAGER_FILE=		httpManager.cpp



FILES=	 				$(CLIENT_FILE)\
						$(DIRTY_MODULES_FILE)\
						$(SIMPLE_CURL_FILE)\
						$(HTTP_MANAGER_FILE) 


EXEC= client

#rules

all:					$(EXEC)\
						$(OBJECTS)\
						$(FILES)

$(EXEC): $(OBJECTS)
	$(LD) $(LFLAGS) $(OBJECTS) -o $@ $(LFLAGS_AFTER)

$(CLIENT_OBJS):			$(CLIENT_FILE)

$(DIRTY_MODULES_OBJS):	$(DIRTY_MODULES_FILE)
						
$(SIMPLE_CURL_OBJS):	$(SIMPLE_CURL_FILE)

$(HTTP_MANAGER_OBJS):	$(HTTP_MANAGER_FILE) 

$(OBJECTS): 
	$(CC) $(CFLAGS) $? -o $@

clean:
	rm $(OBJECTS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJECTS)
	rm $(EXEC)
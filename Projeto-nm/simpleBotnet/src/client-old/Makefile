#macros
#macros
CC=						g++
LD=						g++

CFLAGS=		 			-fPIE -Wall -c -I/usr/include/python3.8
LFLAGS=		 			-fPIE -Wall -pthread

CFLAGS2 =  -I/usr/include/python3.8 -I/usr/include/python3.8  -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.8-fKk4GY/python3.8-3.8.2=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall 
LDFLAGS2 = -L/usr/lib/python3.8/config-3.8-x86_64-linux-gnu -L/usr/lib  -lcrypt -lpthread -ldl  -lutil -lm -lm 


LFLAGS_AFTER= 			-lpython3.8

MAIN_OBJS=				main.o
MANAGER_OBJS=			manager.o

OBJECTS=				$(MAIN_OBJS)\
						$(MANAGER_OBJS)

MAIN_FILE=				main.cpp
MANAGER_FILE=			manager.cpp


FILES=	 				$(MAIN_FILE)\
						$(MANAGER_FILE)


EXEC= botnet

#rules

all:					$(EXEC)\
						$(OBJECTS)\
						$(FILES)

$(EXEC): $(OBJECTS)
	$(LD) $(LFLAGS) $(LFLAGS2) $(OBJECTS) -o $@ $(LFLAGS_AFTER)

$(MAIN_OBJS): 			$(MAIN_FILE)

$(MANAGER_OBJS):		$(MANAGER_FILE)

$(OBJECTS): 
	$(CC) $(CFLAGS) $(CFLAGS2) $? -o $@

clean:
	rm $(OBJECTS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJECTS)
	rm $(EXEC)

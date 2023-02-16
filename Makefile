SRC = mandatory/client.c

SSRC = mandatory/server.c

SNAME = server

CNAME = client

HEADER_MANDA = mandatory/minitalk.h

CC = CC

CFLAGS = -Wall -Wextra -Werror

all: $(SNAME) $(CNAME)

$(CNAME): $(SRC) $(HEADER_MANDA)
	$(CC) $(CFALGS) $(SRC) -o $(CNAME)

$(SNAME): $(SSRC) $(HEADER)
	$(CC) $(CFALGS) $(SSRC) -o $(SNAME)

fclean: clean

clean:
	rm -rf $(SNAME) $(CNAME)

re: clean all
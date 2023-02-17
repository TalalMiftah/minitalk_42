SNAME = server

CNAME = client

SNAME_B = server_bonus

CNAME_B = client_bonus

CC = CC

HEADER = minitalk.h

CFLAGS = -Wall -Wextra -Werror

all: $(SNAME) $(CNAME)

bonus: $(CNAME_B) $(SNAME_B)

$(CNAME): mandatory/client.c $(HEADER)
	$(CC) $(CFLAGS) mandatory/client.c -o $(CNAME)

$(SNAME): mandatory/server.c $(HEADER)
	$(CC) $(CFLAGS) mandatory/server.c -o $(SNAME)

$(CNAME_B): bonus/client_bonus.c $(HEADER)
	$(CC) $(CFLAGS) bonus/client_bonus.c -o $(CNAME_B)

$(SNAME_B): bonus/server_bonus.c $(HEADER)
	$(CC) $(CFLAGS) bonus/server_bonus.c -o $(SNAME_B)

clean:
	rm -rf $(SNAME) $(CNAME) $(CNAME_B) $(SNAME_B)

fclean: clean

re: clean all
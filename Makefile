
# Thomas erstes eigenes "Makefile"
# ---------------------------------
#
# $Id$
# $Log$
#----------------------------------

CC = g++
OPT=-march=x86-64

#
# Erstes Programm
#

PGM = risk
OBJS = risk.o
$(PGM) : $(OBJS)
	$(CC) -o $(PGM) $(OBJS) -I/usr/lib -I/home/thomas/bin/cc/risk -L/usr/include/g++ $(OPT)
$(OBJS) : $(PGM).c++
	$(CC) -c $(PGM).c++ $(OPT) -I/home/thomas/bin/cc/risk

.PHONY : clean
.PHONY : install
clean :
	rm *.o
install :
	cp risk /usr/local/bin/

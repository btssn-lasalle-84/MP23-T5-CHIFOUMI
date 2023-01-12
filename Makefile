TARGET = chifoumi.out
MAIN = main
JOUEUR = Joueur
PARTIE = Partie
HISTORIQUE = Historique
IHM = IHM
SYMBOLE = Symbole

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)

CFLAGS = -std=c++11 -Wall -I.
CXX = g++ $(CFLAGS) -c
LD = g++ -o
RM = rm -f
LDFLAGS =

all: $(TARGET)

$(TARGET): $(MAIN).o $(JOUEUR).o $(PARTIE).o $(HISTORIQUE).o $(IHM).o $(SYMBOLE).o
	$(LD) $@ $(LDFLAGS) $^

$(MAIN).o: $(MAIN).cpp
	$(CXX) $(CFLAGS) $^

$(JOUEUR).o: $(JOUEUR).cpp $(JOUEUR).h
	$(CXX) $(CFLAGS) $<

$(PARTIE).o: $(PARTIE).cpp $(PARTIE).h
	$(CXX) $(CFLAGS) $<

$(HISTORIQUE).o: $(HISTORIQUE).cpp $(HISTORIQUE).h
	$(CXX) $(CFLAGS) $<

$(IHM).o: $(IHM).cpp $(IHM).h
	$(CXX) $(CFLAGS) $<

$(SYMBOLE).o: $(SYMBOLE).cpp $(SYMBOLE).h
	$(CXX) $(CFLAGS) $<

.PHONY: check cppcheck format clean cleanall

check:
	clang-tidy $(SOURCES) --quiet -header-filter='.*' -checks=-*,boost-*,bugprone-*,performance-*,readability-*,portability-*,modernize-use-nullptr,clang-analyzer-*,cppcoreguidelines-* --format-style=none -- -std=c++11

cppcheck:
	cppcheck --enable=all --std=c++11 --platform=unix64 --suppress=missingIncludeSystem --quiet $(SOURCES)

format:
	find . -regex '.*\.\(cpp\|h\)' -exec clang-format -i --style=file {} \;

clean:
	$(RM) *.o

cleanall:
	$(RM) *.o* *.*~ $(TARGET)
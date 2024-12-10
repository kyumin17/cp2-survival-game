CC = g++
CFLAGS = -Wall
LDFLAGS = -lncurses -lpng

SRC = ./component/component.cpp ./component/enemy.cpp ./component/player.cpp ./component/weapon.cpp \
	./page/play.cpp ./page/start.cpp ./page/check-quit.cpp ./page/end.cpp \
	./etc/character.cpp ./etc/display.cpp ./component/block.cpp ./etc/game.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = game

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
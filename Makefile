CC = g++
CFLAGS = -Wall
LDFLAGS = -lncurses

SRC = ./component/component.cpp ./component/enemy/enemy.cpp ./component/player/player.cpp ./component/weapon/weapon.cpp ./component/block/block.cpp \
	./component/weapon/bow.cpp ./component/weapon/arrow.cpp ./component/weapon/sword.cpp \
	./page/play.cpp ./page/start.cpp ./page/check-quit-game.cpp ./page/check-quit-stage.cpp ./page/end.cpp \
	./manage/ui.cpp ./manage/display.cpp ./manage/game.cpp \
	./image/image.cpp ./image/player/player-image.cpp \
	./image/enemy/explosion-image.cpp ./image/enemy/man-image.cpp ./image/enemy/slime-image.cpp ./image/enemy/worm-image.cpp \
	./image/weapon/arrow-image.cpp ./image/weapon/bow-image.cpp ./image/weapon/sword-image.cpp \
	main.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = game

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
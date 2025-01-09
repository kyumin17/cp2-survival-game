CC = g++
CFLAGS = -Wall
LDFLAGS = -lncurses

SRC = ./component/component.cpp ./component/enemy/enemy.cpp ./component/player/player.cpp ./component/weapon/weapon.cpp ./component/block/block.cpp \
	./component/block/block_container.cpp ./component/enemy/enemy_container.cpp ./component/weapon/weapon_manager.cpp \
	./component/weapon/type/bow.cpp ./component/weapon/type/arrow.cpp ./component/weapon/type/sword.cpp \
	./page/play.cpp ./page/start.cpp ./page/check_quit_game.cpp ./page/check_quit_stage.cpp ./page/end.cpp \
	./page/asset/draw.cpp ./page/asset/option.cpp ./page/asset/score.cpp ./page/asset/number_shape.cpp ./page/asset/get_direction.cpp \
	./component/display/display.cpp \
	./image/image.cpp ./image/player/player_image.cpp \
	./image/enemy/explosion_image.cpp ./image/enemy/man_image.cpp ./image/enemy/slime_image.cpp ./image/enemy/worm_image.cpp \
	./image/weapon/arrow_image.cpp ./image/weapon/bow_image.cpp ./image/weapon/sword_image.cpp \
	main.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = game

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
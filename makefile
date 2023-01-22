
setup:
	cmake -H. -GNinja -B build

compile: setup
	cd "./build" && ninja

run: compile setup
	"./build/minecraft-clone" $(args)

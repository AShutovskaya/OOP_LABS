#include "keyboard.hpp"

int main()
{
	AS::Keyboard key;

	key.addCommand("B", "2");
	key.addCommand("C", "3");
	key.addCommand("ctrl+C", "Copy");
	key.addCommand("ctrl+V", "Paste");
	key.addCommand("W", "Forward");	
	key.addCommand("A", "Left");
	key.addCommand("S", "Back");
	key.addCommand("D", "Right");
	

	key.WorkFlow("B C ctrl+C ctrl+V W A S D");

	key.Undo();
	key.Undo();
	key.Undo();
	key.Undo();
	key.Undo();

	return 0;

}
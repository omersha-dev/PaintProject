#include "UndoRedo.h"

vector<Shapes*> UndoRedo::Undo()
{
	if (!undo.empty())
	{
		redo.push(undo.top());
		undo.pop();
		tmp.pop_back();
	}
	return tmp;
}

vector<Shapes*> UndoRedo::Redo()
{
	if (!redo.empty())
	{
		undo.push(redo.top());
		tmp.push_back(redo.top());
		redo.pop();
	}
	return tmp;
}

void UndoRedo::Delete()
{
	while (!redo.empty())
		redo.pop();
	while (!undo.empty())
		undo.pop();
	while (!tmp.empty())
		tmp.pop_back();
}

void UndoRedo::Move(Shapes *shape)
{
	tmp.push_back(shape);
	undo.push(shape);
}

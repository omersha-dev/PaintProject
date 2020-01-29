#pragma once
#include "Shapes.h"
#include "stdafx.h"
#include <vector>
#include <stack>

#pragma once
using namespace std;

class UndoRedo {
public:
	UndoRedo() {};
	vector <Shapes*> Undo();
	vector <Shapes*> Redo();
	void Delete();
	void Move(Shapes*);

private:
	stack<Shapes*> undo;
	stack<Shapes*> redo;
	vector<Shapes*> tmp;
};
#include "ADTMatrix.h"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int nrLines, int nrColumns)
{
	matrix = new SLL();
	lines = nrLines;
	columns = nrColumns;

	for (int i= lines-1;i>=0;i--)
		for (int j = columns-1; j >=0; j--)
		{
			SLLNode * matrixNode = new SLLNode();
			matrixNode->info.line = i;
			matrixNode->info.column = j;
			matrixNode->info.element = 0;

			if (i == lines-1 && j == columns-1)
			{
				matrix->head = matrixNode;
				matrixNode->next = nullptr;
				matrix->tail = matrixNode;
			}
			else
			{
				matrixNode->next = matrix->head;
				matrix->head = matrixNode;
			}
		}

}

int Matrix::nrLines() const
{
	return lines;
}

int Matrix::nrColumns() const
{
	return columns;
}


TElem Matrix::element(int i, int j) const
{
	if (i < 0 || i >= lines || j < 0 || j >= columns)
	{
		throw std::invalid_argument("wrong input");
	}

	SLLNode* current = matrix->head;
	while (current != matrix->tail) {
		if (current->info.line == i && current->info.column == j)
			break;
		current = current->next;
	}
	return current->info.element;
}

TElem Matrix::modify(int i, int j, TElem e)
{
	if (i < 0 || i >= lines || j < 0 || j >= columns)
		throw std::invalid_argument("wrong input");
	SLLNode* current = matrix->head;
	SLLNode* toReturn = new SLLNode();
	while (current != matrix->tail) {
		if (current->info.line == i && current->info.column == j)
		{
			break;
		}
		current = current->next;
	}
	toReturn = current;
	current->info.element = e;
	return toReturn->info.element;
}

void Matrix::resize(int newLines, int newColumns)
{
	if (newLines <=0 || newColumns <= 0)
		throw std::invalid_argument("wrong input");
	for (int i = newLines - 1; i >= 0; i--)
		for (int j = newColumns - 1; j >= 0; j--)
		{
			if (i < 0 || i >= lines || j < 0 || j >= columns)
			{
				SLLNode * matrixNode = new SLLNode();
				matrixNode->info.line = i;
				matrixNode->info.column = j;
				matrixNode->info.element = 0;

				if (i == newLines - 1 && j == newColumns - 1)
				{
					matrix->head = matrixNode;
					matrixNode->next = nullptr;
					matrix->tail = matrixNode;
				}
				else
				{
					matrixNode->next = matrix->head;
					matrix->head = matrixNode;
				}
			}
			else
			{
				SLLNode * matrixNode = new SLLNode();
				matrixNode->info.line = i;
				matrixNode->info.column = j;
				matrixNode->info.element = element(i,j);
				if (i == newLines - 1 && j == newColumns - 1)
				{
					matrix->head = matrixNode;
					matrixNode->next = nullptr;
					matrix->tail = matrixNode;
				}
				else
				{
					matrixNode->next = matrix->head;
					matrix->head = matrixNode;
				}
			}

		}
	lines = newLines;
	columns = newColumns;
}



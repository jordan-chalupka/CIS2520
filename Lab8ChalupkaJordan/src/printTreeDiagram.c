// Jordan Chalupka 0928258

#include "printTreeDiagram.h"

int printTree (char * fileName) {
	FILE * file = openFile(fileName);

	Tree * nameTree = createBinTree(compareName, destroyRestaurant);
	Tree * ratingTree = createBinTree(compareRating, destroyRestaurant);
	if (!(nameTree && ratingTree)) {
		printf("ERROR CREATING TREE\n");
	}
	collectFile(file, nameTree, ratingTree);

	initNCurses();

	traversePreOrder(nameTree, 0);
	traverseInOrder(ratingTree,0);

	
	printInOrder(ratingTree, simplePrint);
	printf("Here\n");

	
	getchar();
	exitNCurses();


	destroyBinTree(nameTree);	
	destroyBinTree(ratingTree);


	return 0;
}

int main () {

	printTree("testFiles/data.txt");

	return 0;
}

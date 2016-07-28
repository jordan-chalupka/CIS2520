// Jordan Chalupka 0928258
int getOrderTree (char * fileName, int order) {
	FILE * file = openFile(fileName);

	Tree * nameTree = createBinTree(compareName, destroyRestaurant);
	Tree * ratingTree = createBinTree(compareRating, destroyRestaurant);
	if (!(nameTree && ratingTree)) {
		printf("ERROR CREATING TREE\n");
	}
	collectFile(file, nameTree, ratingTree);

	initNCurses();

	if (treeType == 0) {
		traverseInOrder(ratingTree,0);
	} else {
		traverseInOrder(nameTree,0);
	}
	
	
	
	printInOrder(ratingTree, simplePrint);
	printf("Here\n");

	
	getchar();
	exitNCurses();

	fclose(file);

	return 0;
}

int main (void) {
	getOrderTree("testFiles/data.txt",0);
	getOrderTree("testFiles/data2.txt",0);
	getOrderTree("testFiles/data3.txt",0);
	return 0;
}
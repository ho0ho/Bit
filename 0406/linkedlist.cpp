
#include <iostream>
using namespace std;

class LList {
private:
	typedef struct Node {
		int key;
		struct Node *link;
	} Node;

	Node *head;
	int size;

public:
	LList() : size(0), head(NULL) {}
	~LList() {
		// delete all
		delete_all();
	}

	void init() {

	}





};
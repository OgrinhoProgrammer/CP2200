#include <iostream>
using namespace std;

class NumberList
{
	private:
		typedef struct ListNode
		{
			int value;						// The value of the numbers in the list
			int index;						// Index of the numbers in the list
			ListNode* next;					// To point to the next node
		} *nodePtr; 						// Abbreviate ListNode to nodePtr when making new objects

	nodePtr head;							// To point to the head of the list

	public:
		NumberList()  						// Default constructor
		{
			head = nullptr;					// Initialize pointer head to null
		}
	
		NumberList(int value)				// No default constructor with value as parameter
		{
			NumberList();					// Calling default constructor to set head to null
			appendNode(value);				// Insert the value in appendNode method
		}

		NumberList(int value, int index)	// No default constructor with value and index as parameter
		{
			NumberList();					// Calling default constructor to set head to null
			insertNode(value, index);		// Insert the value and index in insertNode method
		}
	
		~NumberList()						// Destructor
		{
			nodePtr temp = nullptr;			// Temporary pointer
			nodePtr nextNode = nullptr;		// To point to the next node
			
			temp = head;					// Temp points to the head of the list
			
			while(temp)						// While temp is not null, delete it and then go the the next node until temp is null
			{
				delete temp;		
				temp = temp->next;
			}
		}
	
		// NumberList methods
		void appendNode(int);
		void insertNode(int, int);
		void delete_by_value(int);
		void delete_by_position(int);
		int getValue(int);
		int search(int);
		int length();
		void print();

};

// Append node to the end of the list
void NumberList::appendNode(int value)
{
	nodePtr newNode = new ListNode;				// Point to a new node
	nodePtr temp = nullptr;						// Temporary pointer
	
	newNode->value = value;						// Set the newNode value to the argument value
	newNode->next = nullptr;					// Set the next of the newNode to null

	int countIndex = 0;							// To count the indexes of each value in the list

	if (!head)									// if head has no value
	{
		head = newNode;							// head will become the newNode
		head->index = countIndex;				// Set the index to the value of countIndex
	}

	else
	{
		countIndex++;							// To start with 1 so that it does not start with 0 as in head
		temp = head;							// Point to head

		while (temp->next)						// To count what is the index of each value in the list
		{
			temp = temp->next;
			countIndex++;
		}

		temp->next = newNode;					// Point to the newNode
		newNode->index = countIndex;			// newNode index will equal to the countIndex
	}
}

// Insert node to the desired index
void NumberList::insertNode(int value, int index)
{
	nodePtr newNode = new ListNode;				// Point to a new node
	nodePtr temp = nullptr;						// Temporary pointer
	nodePtr prev = nullptr;						// Previous of the new node
	nodePtr nextNode = nullptr;					// Next of the new node

	newNode->value = value;						// Set newNode value equals to the argument value
	newNode->index = index;						// Set index to the argument index
	newNode->next = nullptr;					// Set newNode next to null

	int countIndex = 0;							// count the index of each number of the list

	if (!head)									// if head is null
		head = newNode;							// head will equals the newNode

	else
	{
		temp = head;							// Temp points to the head of the list

		while (temp && temp->index < index)		// To check the place that the value needs to be inserted according to the index input
		{
			prev = temp;
			temp = temp->next;
		}

		if (prev == nullptr)					// If the index input is 0, the head will be the newNode and the set the old head value to the next node
		{
			head = newNode;
			head->next = temp;
		}

		else								   // Set the value to the desired index and place the previous value to next
		{
			prev->next = newNode;
			newNode->next = temp;
		}

		while (temp)						   // Let all indexes in order when inserting new nodes
		{
			prev = temp;
			temp->index++;
			temp = temp->next;
		}
		
		temp = head;
		
		while(temp->next)
		{
			prev = temp;
			temp = temp->next;
		}		
		
		if(prev->index + 2 < temp->index)		// If the index of the value inserted is not in order, set it previous index + 1
		{
			temp->index = prev->index + 1;
		}
	}
}

// Delete node by value
void NumberList::delete_by_value(int value)
{
	nodePtr temp = nullptr;
	nodePtr prev = nullptr;
	nodePtr nextNode = nullptr;

	if (!head)
		return;

	if (head->value == value)
	{
		temp = head->next;

		nextNode = temp;

		while (nextNode)
		{
			nextNode->index--;
			nextNode = nextNode->next;
		}

		delete head;
		head = temp;
	}

	else
	{
		temp = head;

		while (temp && temp->value != value)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp)
		{
			prev->next = temp->next;

			nextNode = temp;

			while (nextNode)
			{
				nextNode->index--;
				nextNode = nextNode->next;
			}
			
			delete temp;
		}
	}
}

// Delete node by index
void NumberList::delete_by_position(int index)
{
	nodePtr temp = nullptr;
	nodePtr prev = nullptr;
	nodePtr nextNode = nullptr;

	if (!head)
		return;

	if (head->index == index)
	{
		temp = head->next;

		nextNode = temp;

		while (nextNode)
		{
			nextNode->index--;
			nextNode = nextNode->next;
		}
		
		delete head;
		head = temp;

	}

	else
	{
		temp = head;

		while (temp && temp->index != index)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp)
		{
			prev->next = temp->next;
			nextNode = temp->next;

			while (nextNode)
			{
				nextNode->index--;
				nextNode = nextNode->next;
			}
			delete temp;
		}
	}
}

// Get the value by the index on the list
int NumberList::getValue(int index)
{
	nodePtr temp = nullptr;
	nodePtr prev = nullptr;

	if (!head)
		return -1;

	else
	{
		temp = head;

		while (temp && temp->index != index)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp)
		{
			return temp->value;
		}

		return -1;
	}

}


// Search the index by the value on the list
int NumberList::search(int value)
{
	nodePtr temp = nullptr;
	nodePtr prev = nullptr;

	if (!head)
		return -1;

	else
	{
		temp = head;

		while (temp && temp->value != value)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp)
			return temp->index;

		return -1;
	}
}

// Length of the list
int NumberList::length()
{
	nodePtr temp = nullptr;

	int countLength = 0;

	if (!head)
		return 0;

	else
	{
		temp = head;

		while (temp)
		{
			countLength++;
			temp = temp->next;
		}

		return countLength;
	}
}

// Output the list
void NumberList::print()
{
	while (head)
	{
		cout << "Value: " << head->value;
		cout << "				Index: " << head->index << endl;
		head = head->next;
	}

}

int main()
{
	// NumberList object
	NumberList list;
	NumberList list2(2, 3);


	// Calling methods from NumberList class
	list.appendNode(1);
	list.appendNode(2);
	list.appendNode(4);
	
	list.insertNode(0, 0);
	list.appendNode(5);
	
	list.insertNode(3, 2);
	
	list.delete_by_position(0);
	list.delete_by_value(1);
	
	list.appendNode(6);
	list.appendNode(10);
	list.appendNode(10);
	
	list.insertNode(29, 20);
	list.insertNode(50, 400);
	
	list.delete_by_position(3);
	list.delete_by_value(10);
	
	list.appendNode(7);
		
	// Variables to hold the values of non void methods
	int getValue = list.getValue(4);
	int search = list.search(50);
	int length = list.length();

	// Output list
	list.print();

	// Output non void method types
	cout << "\nThe value of the input index is " << getValue << ".\n";
	cout << "\nThe value is in the index " << search << ".\n";
	cout << "\nThe length of the list is: " << length << "\n\n";

	return 0;
}

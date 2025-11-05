#include <iostream>
#include <string>
using namespace std;



//Define Node Class
class NodeObj
{
	public:
		int value;
		NodeObj *RightChild;
		NodeObj *LeftChild;
		NodeObj *ParentNode;
};


//Function that Creates a new Node with given value and parent
NodeObj* CreateNode(int EnteredValue, NodeObj *parent)
{
	NodeObj *CreatedNode;
	CreatedNode = new NodeObj();
	CreatedNode -> value = EnteredValue;
	CreatedNode -> RightChild = 0;
	CreatedNode -> LeftChild = 0;
	CreatedNode -> ParentNode = parent;
	return CreatedNode;
	
}


int main()
{
	//Define Root Node
	NodeObj *RootNode;
	
	//User enters a Number to Sort, if Number = 0 end UserInput
	cout << "Enter a Number to add to tree, and enter 0 to stop" << endl;
	int UserInput;
	cin >> UserInput;
	
	if(UserInput != 0)
	{
		//Set First Entered into Root of Tree
		RootNode = CreateNode(UserInput,0);

		//Get Next Number
		
		cin >> UserInput;
		
		while(UserInput != 0)
		{
			//Create Ref to Node being Used, Target Root
			NodeObj *TargetNode;
			TargetNode = RootNode;
			while(true)
			{
				//If Greater than Target Node, Add to the Right Side
				if(UserInput > TargetNode->value)
				{
					if(TargetNode->RightChild != 0)
					{
						//If Target has a Right Child, Target Right Child and Check Again
						TargetNode = TargetNode->RightChild;
					}
					else
					{
						//If Target does NOT have a right child, make Entered Value right Child
						TargetNode->RightChild = CreateNode(UserInput,TargetNode);

						break;
					}		
				}
				
				else
					//If Less than Target Node, Add to the Left Side
					if(UserInput < TargetNode->value)
					{
						if(TargetNode -> LeftChild != 0)
						{
							//If Target has a Left Child, Target Left Child and check Again
							TargetNode = TargetNode->LeftChild;	
						}
						else
						{
						//If Target does NOT have a left child, make Entered Value left Child
							TargetNode->LeftChild = CreateNode(UserInput, TargetNode);
						
						break;
						}
					}
					else
					{
						// If Number has been Entered previously, inform user and Try Again;
						cout << "Number Previously Entered" << endl;
						break;
					}	
			}
			//Continue Loop
			cin >> UserInput;
		}
		
		//At this Point, User has Entered 0 and Ended Loop, and Tree Has been Created
		
		printTree(RootNode,0);
		
		/*
		cout << "Please enter number to find, or enter 0 to exit" << endl;
		cin >> UserInput;
		
		NodeObj *TargetNode;
		while(UserInput != 0)
		{
			TargetNode = RootNode;
		
		
			while(TargetNode != 0)
			{
				if (UserInput == TargetNode->value)
					break;
				else
					if (UserInput > TargetNode->value)
						TargetNode = TargetNode->RightChild;
					else
						TargetNode = TargetNode->LeftChild;
			}
		
			if (TargetNode != 0)
				cout << "Contained" << endl;
			else
				cout << "Not contained" << endl;
				
			cin >> UserInput;
		}
		*/
		
		
	}
	
	
	


	
}




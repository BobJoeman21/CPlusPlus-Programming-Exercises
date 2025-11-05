#include <iostream>
using namespace std;

class NodeObj
{
	public:
		int value;
		NodeObj *RightChild;
		NodeObj *LeftChild;
		NodeObj *ParentNode;



	
};



void CreateNode(int EnteredValue, NodeObj *parent)
{
	NodeObj *CreatedNode;
	CreatedNode = new NodeObj();
	CreatedNode -> value = EnteredValue;
	CreatedNode -> RightChild = 0;
	CreatedNode -> LeftChild = 0;
	CreatedNode -> ParentNode = parent;
}

int main()
{
	//Define Root Node
	NodeObj *RootNode;
	
	//User enters a Number to Sort, if Number = 0 end UserInput
	int UserInput;
	cin >> UserInput;
	
	if(UserInput != 0)
	{
		//Set First Entered into Root of Tree
		CreateNode(UserInput,0);
		/*
		RootNode = new NodeObj();
		RootNode -> value = UserInput;
		RootNode -> LeftChild = 0;
		RootNode -> RightChild = 0;
		RootNode -> ParentNode = 0;
		*/
		
		//Get Next Number
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
						CreateNode(UserInput,TargetNode);

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
						CreateNode(UserInput, TargetNode);
						
						break;
						}
					}
					else
					{
						// If Number has been Entered previously, inform user and Try Again;
						cout << "Number Previously Entered";
						break;
					}	
			}
			//Continue Loop
			cin >> UserInput;
		}
		
		//At this Point, User has Entered 0 and Ended Loop, and Tree Has been Created
	}
	
	
	


	
}




#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

//resource used to help code: https://www.cs.cmu.edu/~tcortina/15-121sp10/Unit06B.pdf

using namespace std;

const int MAX_SIZE = 100000; //the maximum amount of elements our heap should have.

template <typename Object>
class Heap
{
	public:
		Heap()
		{
			elements = 0;
		};

		// Add the object pointer item to the heap
		void insert(Object* item)
		{
			//Check if heap is full
			if(elements >= MAX_SIZE)
			{
				cout << "Heap is full; can't insert "<< endl;
				return;
			}

			//Otherwise insert
			else
			{
				elements++;
				int newIndex = elements - 1;	//index of new element

				array[newIndex] = item;
				array[newIndex]->position = newIndex; //access position info

				upHeap(array[newIndex]->position); //add node to heap
				return;	
			}

		};  	

		//Remove the smallest element in the heap and restructure heap
		Object* remove_min()
		{
			//Check if heap is empty
			if (elements == 0)
			{
				cout << "empty heap error, can't delete"<<endl;
			}

			Object* temp = array[0];
			array[0] = array[elements-1];//replace smallest val w next obj in array
			array[0]->position = 0;//correct position
			temp->position = -1;//set position of min being removed

			elements--;
	
			downHeap(array[0]->position);//restructure heap

			return temp;
		};
   
		//Decrease key in pos to val
		void decreaseKey(int pos, int val)
		{
			array[pos]->key = val;
			upHeap(array[pos]->position);//restructure heap
		}; 
   
		//Check if empty
		bool IsEmpty() const 
		{  
			return (elements <= 0);
		};

		//Check if full
		bool IsFull() const 
		{
			return (elements >=MAX_SIZE );
		};

		///Return number of elements
		int count() const 
		{
			return elements;
		};
		
		//Return a pointer to an object in heap position pos
		Object* value(int pos) const
		{
			if (pos >= elements)
			{
				cout << "Out of range of heap " << pos << "elements " << elements << endl;
			}
			return (array[pos]);
		};  

	protected:
		Object* array[MAX_SIZE];
		int elements; //  how many elements are in the heap

	private:
		//Starting with element in position pos, sift if down the heap until it is in final min-heap position
		void downHeap(int pos)
		{
			Object* item = array[pos];
			int left = 2*pos+1; //locate left child of pos

			while(left <= elements)
			{
				//check if left child is greater than the right child
				if(array[left]->key > array[left+1]->key && left < elements-1)
				{
					left++;
				}

				//swap elements if left child key is less than the right child
				if(array[left]->key < array[pos]->key)
				{
					array[pos] = array[left];
					array[left] = item;
					array[pos]->position = pos;
					array[left]->position = left;

					pos = left;
					//assign left to the next left child
					left = 2*pos+1;
				}
				//otherwise break while loop
				else break;
			}	

		}; 

		//Starting with element in position int, sift it up the heap until it is in final min-heap position
		void upHeap(int new_pos)
		{
			Object* item = array[new_pos];
			int val = (new_pos-1)/2;
      
			while(array[new_pos]->key < array[val]->key)
			{
				if (new_pos == 0) {
					break;
				}

				else
				{
					item = array[new_pos];
					array[new_pos] = array[val];
					array[val] = item;
					array[new_pos]->position = new_pos;
					array[val]->position = val;
					new_pos = val; 
				}
				return;
			} 
		};   
};
#endif

/*
Student Name:
Student Number:
Project Number: 2
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "RestaurantOrganizer.h"

using namespace std;


RestaurantOrganizer::RestaurantOrganizer(const vector<int>& tableCapacityInput){
    numberOfTables = tableCapacityInput.size();
    for(int i=0;i<numberOfTables;i++){
        tableCapacity[i] = tableCapacityInput[i];
        heap[i] = i;
        heapUp(i);
    }
}

void RestaurantOrganizer::addNewGroup(int groupSize, ofstream& outFile) {
    if(tableCapacity[0]>=groupSize){
        outFile << heap[0] << endl;
        tableCapacity[0] = tableCapacity[0] - groupSize;
        heapDown(0);
    }else{
        outFile << -1 << endl;
    }
}


void RestaurantOrganizer::heapUp(int index){
    if(index> 0){
        if(tableCapacity[(index+1)/2-1]==tableCapacity[(index)]&&heap[(index+1)/2-1]>heap[index]){
            int arbitrary = heap[index];
            heap[index] = heap[(index+1)/2-1];
            heap[(index+1)/2-1] = arbitrary;

            arbitrary = tableCapacity[index];
            tableCapacity[index] = tableCapacity[(index+1)/2-1];
            tableCapacity[(index+1)/2-1] = arbitrary;
            heapUp((index+1)/2-1);
        }else if(tableCapacity[(index+1)/2-1]<tableCapacity[index]){
            int arbitrary = heap[index];
            heap[index] = heap[(index+1)/2-1];
            heap[(index+1)/2-1] = arbitrary;

            arbitrary = tableCapacity[index];
            tableCapacity[index] = tableCapacity[(index+1)/2-1];
            tableCapacity[(index+1)/2-1] = arbitrary;
            heapUp((index+1)/2-1);
        }
    }
}

void RestaurantOrganizer::heapDown(int index){
    int arbitrary;
    if((index+1)*2<=numberOfTables){
        if(tableCapacity[(index+1)*2-1]==tableCapacity[(index+1)*2]){
            if(heap[(index+1)*2-1]<heap[(index+1)*2]){
                if(tableCapacity[index]<tableCapacity[(index+1)*2-1]){
                    arbitrary=heap[(index+1)*2-1];
                    heap[(index+1)*2-1] = heap[index];
                    heap[index] = arbitrary;

                    arbitrary=tableCapacity[(index+1)*2-1];
                    tableCapacity[(index+1)*2-1] = tableCapacity[index];
                    tableCapacity[index] = arbitrary;
                    heapDown((index+1)*2-1);
                }else if(tableCapacity[index]==tableCapacity[(index+1)*2-1]&&heap[index]>heap[(index+1)*2-1]){
                    arbitrary=heap[(index+1)*2-1];
                    heap[(index+1)*2-1] = heap[index];
                    heap[index] = arbitrary;

                    arbitrary=tableCapacity[(index+1)*2-1];
                    tableCapacity[(index+1)*2-1] = tableCapacity[index];
                    tableCapacity[index] = arbitrary;
                    heapDown((index+1)*2-1);
                }
            }else{
                if(tableCapacity[index]<tableCapacity[(index+1)*2]){
                    arbitrary=heap[(index+1)*2];
                    heap[(index+1)*2] = heap[index];
                    heap[index] = arbitrary;

                    arbitrary=tableCapacity[(index+1)*2];
                    tableCapacity[(index+1)*2] = tableCapacity[index];
                    tableCapacity[index] = arbitrary;
                    heapDown((index+1)*2);
                }else if(tableCapacity[index]==tableCapacity[(index+1)*2]&&heap[index]>heap[(index+1)*2]){
                    arbitrary=heap[(index+1)*2];
                    heap[(index+1)*2] = heap[index];
                    heap[index] = arbitrary;

                    arbitrary=tableCapacity[(index+1)*2];
                    tableCapacity[(index+1)*2] = tableCapacity[index];
                    tableCapacity[index] = arbitrary;
                    heapDown((index+1)*2);
                }
            }
        }else if(tableCapacity[(index+1)*2-1]<tableCapacity[(index+1)*2]){
            if(tableCapacity[(index+1)*2]==tableCapacity[index]&&heap[index]>heap[(index+1)*2]){
                arbitrary=heap[(index+1)*2];
                heap[(index+1)*2] = heap[index];
                heap[index] = arbitrary;

                arbitrary=tableCapacity[(index+1)*2];
                tableCapacity[(index+1)*2] = tableCapacity[index];
                tableCapacity[index] = arbitrary;
                heapDown((index+1)*2);
            }else if(tableCapacity[(index+1)*2]>tableCapacity[index]){
                arbitrary=heap[(index+1)*2];
                heap[(index+1)*2] = heap[index];
                heap[index] = arbitrary;

                arbitrary=tableCapacity[(index+1)*2];
                tableCapacity[(index+1)*2] = tableCapacity[index];
                tableCapacity[index] = arbitrary;
                heapDown((index+1)*2);
            }
        }else{
            if(tableCapacity[index]<tableCapacity[(index+1)*2-1]){
                arbitrary=heap[(index+1)*2-1];
                heap[(index+1)*2-1] = heap[index];
                heap[index] = arbitrary;

                arbitrary=tableCapacity[(index+1)*2-1];
                tableCapacity[(index+1)*2-1] = tableCapacity[index];
                tableCapacity[index] = arbitrary;
                heapDown((index+1)*2-1);
            }else if(tableCapacity[index]==tableCapacity[(index+1)*2-1]&&heap[index]>heap[(index+1)*2-1]){
                arbitrary=heap[(index+1)*2-1];
                heap[(index+1)*2-1] = heap[index];
                heap[index] = arbitrary;

                arbitrary=tableCapacity[(index+1)*2-1];
                tableCapacity[(index+1)*2-1] = tableCapacity[index];
                tableCapacity[index] = arbitrary;
                heapDown((index+1)*2-1);
            }
        }
    }else if((index+1)*2-1<=numberOfTables){
        if(tableCapacity[index]<tableCapacity[(index+1)*2-1]){
            arbitrary=heap[(index+1)*2-1];
            heap[(index+1)*2-1] = heap[index];
            heap[index] = arbitrary;

            arbitrary=tableCapacity[(index+1)*2-1];
            tableCapacity[(index+1)*2-1] = tableCapacity[index];
            tableCapacity[index] = arbitrary;
            heapDown((index+1)*2-1);
        }else if(tableCapacity[index]==tableCapacity[(index+1)*2-1]&&heap[index]>heap[(index+1)*2-1]){
            arbitrary=heap[(index+1)*2-1];
            heap[(index+1)*2-1] = heap[index];
            heap[index] = arbitrary;

            arbitrary=tableCapacity[(index+1)*2-1];
            tableCapacity[(index+1)*2-1] = tableCapacity[index];
            tableCapacity[index] = arbitrary;
            heapDown((index+1)*2-1);
        }
    }
}

void RestaurantOrganizer::printSorted(ofstream& outFile){
    for(int i=0; i<numberOfTables; i++){
        outFile << tableCapacity[0] << " " ;
        tableCapacity[0] = tableCapacity[numberOfTables-1-i];
        tableCapacity[numberOfTables-1-i] = -1;
        heapDown(0);
    }
}

// YOU CAN ADD YOUR HELPER FUNCTIONS


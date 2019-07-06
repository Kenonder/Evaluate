#include <iostream>
#include <fstream>
#include <vector>
#include "evaluate.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;
using std::ifstream;
using std::vector;
using std::stoi;


int main(int,char* argv[]){
	
	// Local variables
	//
	ifstream dimacs;
	int numVars;
	int numClauses;
	string thisChar;
	string fileName = argv[1];
	int flag=0;
	int testNumber=1000;

	


	while(flag<testNumber){
	// Read DIMACS CNF Expression
	//

	dimacs.open(fileName);
	if(!dimacs){
		cerr<<"Unable to open the file"<<endl;
		exit(1);
	}	

	dimacs>>numVars>>numClauses;



//			function(array,numVars);
	vector<vector<int>> array(numClauses);  //create the vector of DIMACS CNF 
	for (int i = 0; i < array.size(); i++){
		 array[i].resize(numVars);
	}
 	function1(array,0);

    int row = 0;
	while(dimacs >> thisChar){
		if(thisChar == "0"){ 
		row++;
		}else{
			int i = stoi(thisChar);
			if(i > 0){
				array[row][i-1]=1;
			}else{
				int absolute_i=-1*i;
				array[row][absolute_i-1]=-1;
			}
		}
	}	
	dimacs.close();
	
	// Read Input values sets
	//	
	while(cin >> thisChar){//put the test values to the right place of DIMACS CNF 
			
		int testNumber = stoi(thisChar);
		if(thisChar == "0"){
			 vector<int> row_result(numClauses,-1);
			
		for(int i = 0; i < array.size(); i++){	
			for(int j=0;j < array[0].size();j++){
				if(array[i][j]>0){
					row_result[i]=1;
				}
			}
		}
		
		int result = function2(row_result,numClauses);	
			if(result>0){
				cout<<"true";
			} else{
				cout<<"false";
			}
			 cout<<endl;
			 break;
		}else{
			for(int i = 0; i < array.size(); i++){
			if(testNumber > 0){ 	
			array[i][testNumber-1]=array[i][testNumber-1]*testNumber;	
			}else{
				int absolute_testNumber=0;
				absolute_testNumber=-1*testNumber;
				array[i][absolute_testNumber-1]=array[i][absolute_testNumber-1]*testNumber;	
			}
		} 
	}
	
	}
	flag++;
}
 return 0;
}
 
 void function1(vector<vector<int>> argument1, int argument2){
 		for(int i = 0; i < argument1.size(); i++){
		for (int j = 0; j < argument1[0].size();j++){
			argument1[i][j] = argument2;
		}
	}
 }
 
int function2( vector<int> row_result,int numClauses){
 	int a=1;
	 for(int i=0;i<numClauses;i++){
			if(row_result[i]<0){
				a=-1;
			}
		}
		return a;
 }
 
 
 


 
 
 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //per std::sort
#include <thread>
#include <chrono>
#include "randfiller.h"
#include "algorithms.hpp"
#include "timecounter.h"


// Confronto algoritmi sort con quelli della libreria standard

int main() {
	randifiller rf; //inizializzo oggetto per riempimento casualedei vettori
	timecounter tc; //inizializzo timecounter
	
	std::cout<< "Dimensione, BubbleSort, InsertionSort, SelectionSort, StdSort"<< "\n"; 
	
	//dimensione dei vari vettori raddoppia ad ongi passo
	for (int n = 2; n <= 8192; n*=2) {
		
		std::vector<int> v; 
		v.resize(n); 
		rf.fill(v, -1000, 1000); //riempimento casuale dei vettori ridimensionati
		
		//stampo dimensione n considerata 
		std::cout<< n; 
		
		//---misura bubble sort---
		std::vector<int> v1= v; 
		
		tc.tic(); //start
		bubble_sort(v1); 
		double secs1 = tc.toc(); //stop
		std::cout<<","<< secs1 ; 
		
		//---misura insertion sort---
		
		std::vector<int> v2= v; 
		
		tc.tic(); 
		insertion_sort(v2); 
		double secs2 = tc.toc(); 
		std::cout<<","<< secs2 ; 
		
		//---misura selection sort---
		std::vector<int> v3 = v; 
		
		tc.tic(); 
		selection_sort(v3); 
		double secs3 = tc.toc();
		std::cout<<","<< secs3 ; 

	
		//---misura standard sort---
		std::vector<int> v4 = v; 
		
		tc.tic(); 
		std::sort(v4.begin(), v4.end()); 
		double secs3 = tc.toc();
		std::cout<<","<< secs4 ; 
		
		//vado a capo per l'iterazione successiva
		std::cout<< "\n"; 
	}
	return EXIT_SUCCESS; 
}
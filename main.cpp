#include"header.h"

#include<sstream>
#define N 3



using namespace std;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int k; //number of iterations
	if(argc!=2)
	{
		cout << "You need to give 1 argument: a number for iterations." <<  endl;
		return 1;
	}
	else
	{
		k = atoi(argv[1]);
	}
	
	Atom **atoms;
	
	atoms = new Atom*[N];
	int ComboundCounter = 4*N;
	int HydrogenCounter=1;
	int randomCarbon1,randomCarbon2;
	int Combound; //0 for carbon , 1 for hydrogen
	int randomCombound;
	
	for(int i=0; i<N; i++){
		string str;          //The string
		ostringstream temp;  //temp as in temporary
		temp<<i+1;
		str=temp.str();      //str is temp as string
		atoms[i] = new Atom("c", str,N );
		cout <<  atoms[i]->getTitle()<<endl; ;
	}

	while(1){
		

		randomCarbon1=rand()%N;
		Combound = rand()%2; // returns 0 for combination with randomCarbon or 1 for combination with hydrogen
		if(Combound==0){
			randomCarbon2=rand()%N;
			int check = atoms[randomCarbon1]->carbonsCombound(atoms,randomCarbon1,randomCarbon2 );
			if (check==0){
				continue;
			}
			else if(check==1){
				//success
				ComboundCounter-=2;
			}
		
		}
		else{	
			string str;          //The string
                	ostringstream temp;  //temp as in temporary
                	temp<<HydrogenCounter;
                	str=temp.str();      //str is temp as string

			Atom* hydrogen=new Atom("h",str, N);
			int check = atoms[randomCarbon1]->hydrogensCombound(atoms,randomCarbon1,hydrogen);
			if (check == 0){
				delete hydrogen;
				continue;
			}
			ComboundCounter-=1;
			HydrogenCounter++;
 
		}


		if(ComboundCounter==0) break;
	}
		
}

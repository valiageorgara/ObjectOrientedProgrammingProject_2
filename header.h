#include<iostream>
#include<ostream>
#include<string>
#include<cstdlib>
#include<cmath>



using namespace std;

class Atom {
	private:
		Atom **electrons;
		string type; // carbon or hydrogen
		int *desmoi;
		
		
		
	public:
		Atom(string t, string n, int carbons){
			type = t + n;
			if (t=="c"){
				electrons = new Atom*[4];
				for (int i=0;i<4;i++)
					electrons[i]=NULL;
			}
			else{
				electrons = new Atom*[1];
				for (int i=0;i<1;i++)
                                        electrons[i]=NULL;

			}
			desmoi = new int [carbons];
			
			
		}
		~Atom(){
			
			
		}
		
		string getTitle(){
			return type;
		}
		int empty(Atom**a,int c){
			for(int i=0;i<4;i++){
				if (a[c]->electrons[i]==NULL)
					return i;
			}
			return -1;
		}
		int carbonsCombound(Atom** a, int c1, int c2){
			if (a[c1]->getTitle()== a[c2]->getTitle() ){
				return 0;
			}
			if(a[c1]->desmoi[c2]==3 ){
				return 0;
			}
			
			int spotc1 = empty(a,c1);
			if(spotc1==-1)return 0;
			int spotc2 = empty(a,c2);
			if(spotc2==-1)return 0;

			a[c1]->electrons[spotc1] = a[c2];
			a[c2]->electrons[spotc2] = a[c1];
			a[c1]->desmoi[c2]++;
			a[c2]->desmoi[c1]++;
			return 1;
		}
		

		int hydrogensCombound(Atom**a, int c1, Atom* h){
			 int spotc1 = empty(a,c1);
                        if(spotc1==-1)return 0;
			a[c1]->electrons[spotc1] = h;
			h->electrons[0]=a[c1];
			return 1;
		}		
};

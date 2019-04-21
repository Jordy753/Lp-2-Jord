#include<iostream>

using namespace std;

int main(){
	int cantid,aux,lista[12];
	while(cin>>cantid){
		if(cantid>=6){
			for (int i = 0; i < cantid; i++){
				cin>>lista[i];
			}	
			for (int a = 0; a < cantid - 5; a++)
				for (int b = a + 1; b < cantid - 4; b++)
					for (int c = b + 1; c < cantid - 3; c++)
						for (int d = c + 1; d < cantid - 2; d++)
							for (int e = d + 1; e < cantid - 1; e++)
								for (int f = e + 1; f < cantid; f++)
                                	cout<<lista[a]<<" "<<lista[b]<<" "<<lista[c]<<" "<<lista[d]<<" "<<lista[e]<<" "<<lista[f]<<"\n";			
		}
	}		
	return 0;
}	


#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int ExitDoors(int& boyut,int doors[]){ // & boyut diyerek b nin kopyasýný deðil kendisini aldýk
	
	int exit;
	if(boyut == 1){
		exit = doors[0];
	}else{

	
	int n = rand() % (boyut-1); // n deðerine dizi için index deðeri random olarak atanýr
	exit=doors[n]; // random alýnan index deðeri ile dizi elemaný alýnýr
	
	doors[n] = doors[boyut-1]; // kullanýlan dizi deðeri silinir
	boyut --;
	return exit;
		}
}

int monsterDoors(int& boyut , int doors[]){
	
	int monster;
	if(boyut == 1){
		monster = doors[0]; 
	}else{

	
	int n = rand() % (boyut-1);
	monster = doors[n];
	
	doors[n] = doors[boyut-1];
	boyut--;
	return monster;
		}
}


int guardDoors(int& boyut , int doors[]){
	
	int guard;
	if(boyut == 1){
		guard = doors[0];
	}else{

	
	int n = rand() % (boyut-1);
	guard = doors[n];
	
	doors[n] = doors[boyut-1];
	boyut--;
	return guard;
		}
}

int nullDoors(int& boyut , int doors[]){
	
	int null;
	if(boyut == 1){
		null = doors[0];
	}else{

	
	int n = rand() % (boyut-1);
	null = doors[n];
	
	doors[n] = doors[boyut-1];
	boyut--;
	return null;
		}
}



int Control(int select , int doors[] ,int& life ,int exit , int monster , int guard ,int null){
	
/*	cout<<endl;
	cout<<exit<<" "<<monster<<" "<<guard<<" "<<null<<endl;
	cout<<endl;
	
	// doðru çalýþýp çalýþmadýðýný gözlemlemek için olan blok
*/
	if(life>0){
	
	
	
		if(select == exit){
				cout<<"tebrikler kurtuldun.."<<"    "<<"Kalan Canin  : "<<life<<endl;
				return 0;
		}
		else if(select == monster){
				cout<<"Eyvah!! Canavarrrr.. 30 can kaybettin.."<<endl;
				life=life-30;
				cout<<"Kalan Canin  : "<<life<<endl;
		}
		else if(select == guard){
				cout<<"hay aksiii,nobetciye, yakalandýnn.. 15 can kaybettin"<<endl;
				life=life-15;
				cout<<"Kalan Canin  : "<<life<<endl;
		}
		else if(select == null){
				cout<<"neyseki bos kapi actin. +5 can.."<<endl;
				life=life+5;
		
					if(life>100){
						life =100;	// can puaný en fazla 100 olabilir
					}
		
				cout<<"Kalan Canin  :"<<life<<endl;
		}
		else{
		cout<<"gecerli kapi numarasi girinizz..."<<endl;
	}
	
	return 1;
	
	}
	else{
		cout<<"Canin bitti . Oyunu Kaybettin";
		return 0;
	}
	
}


int main() {

	srand(time(0));

	int life = 100;
	int select,durum;
	cout<< "100 canin var. Hazirsan oyun baþlýyor..."<<endl;
	
	do{
	

	int doors[]={1,2,3,4}; // kapi numarasinin her asamada yeniden ve doðru karisabilmesi icin dizi döngü icinde tanýmlanmalýdýr
	int size = sizeof(doors) / sizeof(doors[0]);
	cout<<endl;
	cout<<"Bir kapi numarasi seciniz : 1  2  3  4 "<<endl;
	cin>>select;

	
	int exit = 	ExitDoors(size,doors);
	int monster = 	monsterDoors(size,doors);
	int guard = guardDoors(size,doors);
	int null = nullDoors(size,doors);
	

	
	durum =Control(select, doors ,life , exit , monster , guard , null);
	
	 
	}while(durum == 1); // return 0 dönmediði sürece (oyun bitmediði) döngü devam eder..

}




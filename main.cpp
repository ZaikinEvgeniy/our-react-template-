#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
 
 struct listusers
{
   string Numreq;
   string LastName;
   string FirstName;
   string AppleID;
   string Card;
   string DateRec;
};
 
int main()
{
    string iPhone7,iPhone6,str;
    int countrec = 0;
    
    cout << "Enter name iPhone7 file : " ;
    getline(cin, iPhone7);
    
	ifstream f7inp(iPhone7.c_str());
    if (!f7inp.is_open()) {
      cout << "Read file error!" << endl;
      system("pause");
      return 0;
	}

    while (!f7inp.eof())
    {
    	getline(f7inp, str);
        countrec++;
    }	
    f7inp.close();
    
    listusers* arrlist = new listusers[countrec];
    listusers* reslist = new listusers[countrec];
    
    string elem;
    string search = ",";
	int comaPos;
	int i = 0;
	ifstream f7in(iPhone7.c_str(),ios::binary);
	
    for (int i=0; i<countrec; i++)
       {
           f7in>>arrlist[i].Numreq>>arrlist[i].LastName>>
           arrlist[i].FirstName>>arrlist[i].AppleID>>
           arrlist[i].Card>>arrlist[i].DateRec;

           reslist[i].Numreq = "-"; 
           reslist[i].LastName = "-"; 
           reslist[i].FirstName = "-"; 
           reslist[i].AppleID = "-"; 
           reslist[i].Card = "-"; 
           reslist[i].DateRec = "-"; 
           
       }

    string Numreq;
    string LastName;
    string FirstName;
    string AppleID;
    string Card;
    string DateRec;
    
    bool finds = false;

    for (int x = 0; x < countrec ; x++)
    {
      Numreq = arrlist[x].Numreq;
      LastName = arrlist[x].LastName;
      FirstName = arrlist[x].FirstName;
      AppleID = arrlist[x].AppleID;
      Card = arrlist[x].Card;
      DateRec = arrlist[x].DateRec;
      finds = false;
      for (int y = 0; y < countrec ; y++)
      {
	     if (LastName == reslist[y].LastName &&
	      FirstName == reslist[y].FirstName &&
	      AppleID == reslist[y].AppleID &&
	      Card == reslist[y].Card &&
	      DateRec == reslist[y].DateRec)
		  {
		  	finds = true;
		  }
	  }
	 
	   if (finds == false){
        for (int z = 0; z < countrec ; z++)
        {
          if (reslist[z].AppleID == "-") 
		  {
		  	  reslist[z].Numreq = Numreq;
		      reslist[z].LastName = LastName;
		      reslist[z].FirstName = FirstName;
		      reslist[z].AppleID = AppleID;
		      reslist[z].Card = Card;
		      reslist[z].DateRec = DateRec;
              break;
		  }
		} 
      }
     
   }

    ofstream out7(iPhone7.c_str());
    for (int x = 0; x < countrec ; x++)
    {    
      if (reslist[x].AppleID != "-")
	   {
	     out7 << reslist[x].Numreq << " " <<
		       reslist[x].LastName << " " <<
               reslist[x].FirstName << " " <<
               reslist[x].AppleID << " " <<
               reslist[x].Card << " " <<
               reslist[x].DateRec  << "\n";
  	   }
	 }
	 
    out7.close();

    cout << "Enter name iPhone6 file : " ;
    getline(cin, iPhone6);
	ifstream f6inp(iPhone6.c_str(),ios::binary);
    if (!f6inp.is_open()) {
      cout << "Read file error!" << endl;
      system("pause");
      return 0;
	}
	int countrec6 = 0;
    while (!f6inp.eof())
    {
    	getline(f6inp, str);
        countrec6++;
    }	
    f6inp.close();
    
    listusers* arrlist6 = new listusers[countrec6];

	i = 0;
	ifstream f6in(iPhone6.c_str(),ios::binary);

    for (int i=0; i<countrec6; i++)
       {
           f6in>>arrlist6[i].Numreq>>arrlist6[i].LastName>>
           arrlist6[i].FirstName>>arrlist6[i].AppleID>>
           arrlist6[i].Card>>arrlist6[i].DateRec;
       }

    f6in.close();
    int countrec7 = 0;
	ifstream f7res(iPhone7.c_str());
	
    while (!f7res.eof())
    {
    	getline(f7res, str);
        countrec7++;
    }	
    f7res.close();

   string iPhone67;
   cout << "Enter name iPhone67 file : " ;
   getline(cin, iPhone67);
   ofstream out67(iPhone67.c_str());

    finds = false;

    for (int x = 0; x < countrec7 ; x++)
    {
      LastName = reslist[x].LastName;
      FirstName = reslist[x].FirstName;
      AppleID = reslist[x].AppleID;
      Card = reslist[x].Card;
      finds = false;
      for (int y = 0; y < countrec6 ; y++)
      {
	     if (LastName == arrlist6[y].LastName &&
	      FirstName == arrlist6[y].FirstName &&
	      AppleID == arrlist6[y].AppleID &&
	      Card == arrlist6[y].Card )
		  {
		  	finds = true;
		  }
	  }
	 
	   if (finds == true){
		   out67 << LastName << " " <<
		            FirstName << " " <<
		            AppleID << " " <<
		            Card << endl;
      }
   }
   out67.close();
   delete[]arrlist;
   delete[]reslist;
   delete[]arrlist6;
   
   system("pause");
   return 0;
}

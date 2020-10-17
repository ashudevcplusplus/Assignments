

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;


struct Train
{
    int id;
    int arr_hr;
    int arr_min;
    int dep_hr;
    int dep_min;
    int delay;
};

using namespace std;

void swap(Train *A, Train *B){
    Train *temp;
    *temp = *A;
    *A = *B;
    *B = *temp;
}


bool compare_two_trains(Train a, Train b) 
{ 
 
    if (a.arr_hr < b.arr_hr ) 
        return 1; 
        
        
    if (a.arr_hr > b.arr_hr  ) 
        return 0;     
  

    if (a.arr_hr == b.arr_hr )
    if (a.arr_min > b.arr_min )
        return 0;
        
}
/* Data used 

Train_id           arrival_hr:arrival_min            departure_hr:departurel_min        delay_min                                                                                                                                                                       
0                          10:00                             10:10                         10
1                          10:10                             10:20                         15                                                              
2                          10:30                             10:40                         10                                                                       
3                          10:35                             10:45                         10                                                      
4                          11:20                             11:40                         15                                                             



*/

int main()
{
    int n=5;
    
    Train all[5];
    all[0].id = 0; all[0].arr_hr = 10; all[0].arr_min = 00; all[0].dep_hr = 10; all[0].dep_min = 10; all[0].delay = 10;
    all[1].id = 1; all[1].arr_hr = 10; all[1].arr_min = 10; all[1].dep_hr = 10; all[1].dep_min = 20; all[1].delay = 15;
    all[2].id = 2; all[2].arr_hr = 10; all[2].arr_min = 30; all[2].dep_hr = 10; all[2].dep_min = 40; all[2].delay = 10;
    all[3].id = 3; all[3].arr_hr = 10; all[3].arr_min = 35; all[3].dep_hr = 10; all[3].dep_min = 45; all[3].delay = 10;
    all[4].id = 4; all[4].arr_hr = 11; all[4].arr_min = 20; all[4].dep_hr = 11; all[4].dep_min = 40; all[4].delay = 15;
    
    
    
    
    std::cout << "Time table of trains at Allahabad Station and current time is 09:59:59"<< std::endl;
    std::cout << "Train_id           arrival_hr:arrival_min            departure_hr:departurel_min        delay_min"<< std::endl;
    std::cout << "0                          10:00                             10:10                         10"<< std::endl;
    std::cout << "1                          10:10                             10:20                         15"<< std::endl;
    std::cout << "2                          10:30                             10:40                         10"<< std::endl;
    std::cout << "3                          10:35                             10:45                         10"<< std::endl;
    std::cout << "4                          11:20                             11:40                         15"<< std::endl;
    
    
    int curr_hr=10;
    int curr_min=00;
    
    for(int i=0; i<n; i++){
        if(all[i].arr_min+all[i].delay < 60)
        {
        all[i].arr_min=all[i].arr_min+all[i].delay%60;
        }
        else
        {
        all[i].arr_min=all[i].arr_min+all[i].delay%60;
        all[i].arr_hr=(all[i].arr_hr + 1) % 24;
        }
        
        
        
        if(all[i].dep_min+all[i].delay < 60)
        {
        all[i].dep_min=all[i].dep_min+all[i].delay%60;
        }
        else
        {
        all[i].dep_min=all[i].dep_min+all[i].delay%60;
        all[i].dep_hr=(all[i].dep_hr + 1) % 24;
        }
        
       
    }
    
     
     sort(all, all+5, compare_two_trains);
     
      for(int i=0; i<n; i++)
     {
            cout<<all[i].arr_hr<<":"<<all[i].arr_min<<"   "<<all[i].dep_hr<<":"<<all[i].dep_min<<endl;
     }
     cout<<"==============================================================================="<<endl;
    
    //swap(all[0],all[1]);
    
          for(int i=0; i<n; i++)
     {
            cout<<all[i].arr_hr<<":"<<all[i].arr_min<<"   "<<all[i].dep_hr<<":"<<all[i].dep_min<<endl;
     }
   /* for(int i=1 ; i<n ;i++){
    if(all[i-1].dep_hr == all[i].arr_hr)
    if(all[i-1].dep_min > all[i].arr_min)
    all[i].arr_min+=all[i-1].dep_min - all[i].arr_min+1;
    all[i].dep_min+=all[i-1].dep_min - all[i].arr_min+1;
    }
   */ 
    
    
         cout<<"==============================================================================="<<endl;
    
    //swap(all[0],all[1]);
    
          for(int i=0; i<n; i++)
     {
            cout<<all[i].id <<"    "<<all[i].arr_hr<<":"<<all[i].arr_min<<"   "<<all[i].dep_hr<<":"<<all[i].dep_min<<endl;
     }
    
    
    
    
    

    return 0;
}

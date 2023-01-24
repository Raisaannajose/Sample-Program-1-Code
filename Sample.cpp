#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class DataSet{                          //to store the distance and time inputs and the speed calculated
    public:
    float distance,time1,speed;
};
class UserInput{
    public:
    int i;
    DataSet arrinput[10];    
    void Method1(){  
                                //Method1 to set the 10 user inputs(distance and time) into Attribute1
        for(i = 0; i < 10; i++)
        {
            cout<<"Enter the distance travelled in km:";
            cin>>arrinput[i].distance;
            cout<<"Enter the time taken in hours:";
            cin>>arrinput[i].time1;
            if(i==9){
                break;
            }
            cout<<"Add another input\n";
        }
        
    }
};
class Measure 
{
    public:
    void MeasureSpeed(DataSet o[]){                                      //MeasureSpeed to measure the speed of all user inputs and update it into Attribute1
        for(int i=0;i<10;i++){
         o[i].speed=o[i].distance/o[i].time1;
        }
     }
};
class ShowResults 
{
    public:
    void WriteToFile(DataSet arr[])                                     //WriteToFile() to print distance,time and calculated speed from Attribute1 to a csv file
    {
        ofstream myfile("output.csv",ios::out|ios::app);   //output in "sample.csv"
        if(myfile.is_open()){
            for(int i=0;i<10;i++){
                {
                    myfile<<arr[i].distance<<",";
                    myfile<<arr[i].time1<<",";
                    myfile<<arr[i].speed;
                }
            myfile<<"\n";
            }
            myfile.close();
        }
    }

};

int main(){
    UserInput obj;
    obj.Method1();
    Measure obj1;
    obj1.MeasureSpeed(obj.arrinput);
    ShowResults obj3;
    obj3.WriteToFile(obj.arrinput);
    return 0;
}

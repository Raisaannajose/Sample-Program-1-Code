#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
float Attribute1[10][3];
class DataSet{                          //to store the distance and time inputs and the speed calculated
    public:
    float arr[10][3];
    void Data(float a[][3]){
        for(int i=0;i<10;i++)
        {
            arr[i][0]=a[i][0];
            arr[i][1]=a[i][1];
            arr[i][2]=a[i][2];
            cout<<arr[i][0]<<":"<<arr[i][1]<<":"<<arr[i][2]<<endl;       //the stored values are displayed
            
        }
    } 
};
class UserInput{
    public:
    int k=0;
    float distance,time1;
    
    void Method1(){                                       //Method1 to set the 10 user inputs(distance and time) into Attribute1
        while(k<10){
            cout<<"Enter the distance travelled in km:";
            cin>>distance;
            cout<<"Enter the time taken in hours:";
            cin>>time1;
            Attribute1[k][0]=distance;
            Attribute1[k][1]=time1;
            if(k==9){
                break;
            }
            k++;
            cout<<"Add another input\n";
        }
    }
};
class Measure
{
    public:
    void MeasureSpeed(){                                      //MeasureSpeed to measure the speed of all user inputs and update it into Attribute1
        for(int i=0;i<10;i++){
         Attribute1[i][2]= Attribute1[i][0]/Attribute1[i][1];
        }
     }
};
class ShowResults
{
    public:
    void WriteToFile()                                     //WriteToFile() to print distance,time and calculated speed from Attribute1 to a csv file
    {
        ofstream myfile("sample.csv",ios::out|ios::app);   //output in "sample.csv"
        if(myfile.is_open()){
            for(int i=0;i<10;i++){
                for(int j=0;j<3;j++){
                 if(j==2){
                   myfile<<Attribute1[i][j]; 
                 }
                 else{
                 myfile<<Attribute1[i][j]<<",";
                 }
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
    obj1.MeasureSpeed();
    DataSet obj2;
    obj2.Data(Attribute1);                 //to store the values in DataSet class
    ShowResults obj3;
    obj3.WriteToFile();
    return 0;
}

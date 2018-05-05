#include <iostream>
#include <string>
#include <fstream>
#include <math.h>



using namespace std;

class loan_calculation
{
private:
    int amount,time,n,remain;
    double interest,PPM=0;

public:
int calculations()
{
    cout<<"Enter Loan Required"<<endl;
    cin>>amount;
    cout<<"How much time will be required to pay off loan (in months) "<<endl;
    cin>>time;
    cout<<"Enter Interest Rate"<<endl;
    again:
    cin>>interest;
    if(interest<6)
    {
        cout<<"We dont allow interest less than 6%"<<endl<<"kindly type again"<<endl;
        goto again;
    }
    interest=interest/12;
    PPM=((pow(1+interest,time)-1)/(interest*(pow(interest+1,time))));
    PPM=(amount/PPM)/100;
    cout<<"Your monthly Payments will be : "<<"$"<<PPM;
    cout<<endl;
}
void update(int amount)
{
    if(PPM!=0)
    {
    cout<<" UPDATION OF LOAN " <<endl;
    cout<<"Enter Installment no. "<<endl;
    cin>>n;
    amount=amount-(n*PPM);
    cout<<"Total Payable Amount Updated"<<endl;
    cout<<"Remaining Payable Loan $"<<amount<<endl;
    remain=amount;
    }
    else
    {
        cout<<"Loan is not yet calculated"<<endl<<"calculate before updation"<<endl;
    }
}
double getinstall()
{
    return PPM;
}
double getrem()
{
    return remain;
}


};

int main()
{
    int Age,ID,Salary,amount,c;
    string Name,Job,Address;
    char ch;
    uint64_t CNIC;
    loan_calculation l;
    ifstream infile;
    infile.open("Data.txt");
    infile>>Name>>Age>>ID>>CNIC>>Job>>Salary>>Address>>amount;
    cout<<"Enter Operation to perform"<<endl;
    another:
    cout<<"1.Calculate Loan Payments"<<endl;
    cout<<"2.Update Existing installments"<<endl;
    cin>>c;
    if(c==1)
    {
    l.calculations();
    }
    else
    {
    l.update(amount);
    }
    cout<<"Futher Operation? (Y/N) : ";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        goto another;
    }
    infile.close();
    ofstream outfile;
    outfile.open("Data.txt",std::ios::app);
    outfile << l.getinstall();
    outfile <<endl<< l.getrem();
    return 0;
}

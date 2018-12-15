#include<iostream>
#include<cstdlib>
#include<string.h>
#include<ctime>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<unistd.h>
#include<string>
using namespace std;
int timeout ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
    return  1;
}

int index=0;
class stack
{
             long long int stk[12];
             long long int  top;
      public:
             stack()
              {
                top=-1;
               }
             void push(long long int x)
              {
                 if(top >  11)
                       {
                           cout <<"stack over flow";
                           return;
                       }
                 stk[++top]=x;
               }
             long long int pop()
               {
                  if(top <0)
                   {
                         cout <<"stack under flow";
                         return 0;
                    }
                   return stk[top];
                   stk[top--];
                }
             void display()
               {
                   if(top<0)
                    {
                            cout <<" stack empty";
                            return;
                    }
                    for(int i=top;i>=0;i--)
                    cout <<stk[i] <<" ";
                }
};

struct Detail{
    int len;
    string word;
    int doorno;
    string alphanumeric;
    char area[20];
    char city[20];
    long long int pincode;
    long long int phoneno;
    char companyname[50];
    int choice;
    int index;
    };
void CompanyDetails(){

    struct Detail c;
    ofstream fp;
    fp.open("companyDetails.txt",ios::app);
    cout<<endl;
    cout<<"ENTER THE COMPANY NAME  :";
    cin>>c.companyname;
    cout<<endl;
    cout<<"CHOOSE YOUR COMPANY FIELD FROM BELOW :\n";
    cout<<"\t1.AUTOMOBILES AND VEHICLE PARTS\n\t2.FURNITURES\n\t3.ELECTRONICS AND SPARES\n\t4.TEXTILES AND PROVISIONS\n\t5.ENTERTAINTMENT SERVICES";
    cin>>c.choice;
    cout<<"ENTER THE COMPANY'S PHONE NUMBER :\n";
    cin>>c.phoneno;
    cout<<"ENTER YOUR ADDRESS IN FORMAT (NUMBER,AREA,CITY,PINCODE) :\n";
    cin>>c.doorno>>c.area>>c.city>>c.pincode;

    cout<<"CREATE A PASSWORD FOR YOUR ACCOUNT .......";
    int length;
    int numCharacters;
    cout << "Please enter how many characters you would like your\npassword to be.";
    cout << " Your password must be at least 8 characters long." << endl;
    cin >> numCharacters;
    while (numCharacters < 8)
    {
        cout << "Please enter a password length of at least 6 characters." << endl;
        cin >> numCharacters;
    }

    cout << "Please enter a password that contains at least one uppercase letter, ";
    cout << "one\nlowercase letter, and at least one digit." << endl;

    cin >> c.word;
    length = c.word.length();

    while (length != numCharacters)
    {
        cout << "Your password is not the size you requested. ";
        cout << "Please re-enter your password." << endl;
        cin >> c.word;
        length = c.word.length();
    }

    bool aUpper = false,
		 aLower = false,
		 aDigit = false ;
	for ( int i = 0 ; c.word[i]!='\0' ; ++i ){
		if ( isupper(c.word[i]) )
			aUpper = true ;
		else if ( islower(c.word[i]) )
			aLower = true ;
		else if ( isdigit(c.word[i]) )
			aDigit = true ;
    }
	if ( aUpper && aLower && aDigit )

        cout << "Your password is valid." << endl;
    else
    {
        cout << "Your password is not valid. ";
        cout << "Please refer to the above warning message." << endl;
}

    system("CLS");
    cout<<"\n\n\t\tWAIT FOR FEW MINUTES WHILE WE ARE PROCESSING YOUR REQUEST..............";

    if( timeout(10) == 1 )
	 {
            system("CLS");
         	cout<<"\n\n\t\tCONGRATS....!!!!\n\n\t\t     YOU HAVE SUCESSFULLY REGISTERED .......!!!!!!";
	 }
    cout<<"\n\n";
    cout<<"NOTE DOWN  YOUR COMPANY CODE FOR FUTURE REFERENCE.....";
    cout<<endl;
    static const string charList = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	srand(time(0));


	for(int i = 0; i < 8; i++) {
		c.alphanumeric += charList [rand() % charList.size()];
	}

	cout << "YOUR COMPANY CODE  " << c.alphanumeric << endl;
	fp<<index<<endl<<c.companyname<<endl<<c.choice<<endl<<c.doorno<<endl<<c.area<<endl<<c.city<<endl<<c.pincode<<endl<<c.phoneno<<endl<<c.alphanumeric<<endl<<c.word<<endl;
	index++;
	fp.close();

}

void setCompanyShares(){

    int p,n,sum=0;
    long long int shares,a[20][12];
    string code,pass;
    ifstream fp;
    int ele;
    struct Detail c[20];
    fp.open("companyDetails.txt",ios::in);
    while(fp!=NULL){
            system("CLS");
            cout<<"ENTER YOUR COMPANY CODE  :";
            cin>>code;
            cout<<"ENTER YOUR PASSWORD       :";//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          t<<"ENTER YOUR PASSWORD      :";
            cin>>pass;
            for(int i=0;(!fp.eof());i++){
               fp>>c[i].index>>c[i].companyname>>c[i].choice>>c[i].doorno>>c[i].area>>c[i].city>>c[i].pincode>>c[i].phoneno>>c[i].alphanumeric>>c[i].word;
               cout<<c[i].alphanumeric<<"  "<<c[i].word<<"  "<<code<<"   "<<pass;
               if((c[i].alphanumeric==code)&& (c[i].word==pass)){
                    cout<<"CHOOSE YOUR OPTION :\n\t1.ENTER SHARES FOR A YEAR\n\t2.FOR A SERIES OF YEARS";
                    cin>>p;
                    if(p==1){
                            cout<<"\nYOU HAVE CHOOSEN FOR A PARTICULAR YEAR..!!";
                            stack s;
                            cout<<"\nENTER THE SHARES FOR THE ANY YEAR  :\n";
                            for(int i=0;i<12;i++)
                                cout<<"\nENTER THE SHARE FOR MONTH "<<i+1<<"  :";
                                cin>>shares;
                                s.push(shares);
                    }
                else if(p==2){
                        cout<<"\nYOU HAVE CHOOSEN FOR A SERIES OF YEARS....!!";
                        stack s[10];
                        cout<<"\nENTER THE TOTAL NUMBER OF YEARS :";
                        cin>>n;
                        for(int j=0;j<n;j++){
                                cout<<"\nENTER THE LIST OF SHARES FOR THE "<<j+1<<" TH YEAR....\n";
                            for(int i=0;i<12;i++)
                            {
                                cout<<"\nENTER THE SHARE FOR MONTH "<<i+1<<"  :";
                                cin>>shares;
                                a[j][i]=shares;
                                s[j].push(shares);
                            }
                        }
                        stack avgshares;
                        for(int j=0;j<n;j++){

                            for(int i=0;i<12;i++){
                                    sum=sum+a[j][i];
                            }
                            sum=sum/12;
                            avgshares.push(sum);
                        }
                        cout<<"THE AVERAGE SHARES FOR YOUR COMPANY OVER THE YEARS IS :\n";
                        while(avgshares.pop());{
                            cout<<avgshares.pop()<<"  ->  ";
                        }
                }
                else
                    cout<<"PLEASE ENTER THE CORRECT CHOICE....!!!";
            }

        }
    }

        fp.close();
}

int QuestionareAutomobile(){
    int a[5][5]={0};
    int sum=0;
    system("CLS");
    int option;
    cout<<"1.RATE THE COMPANY'S SERVICES AND CARES ?";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[0][option-1]=1;
    cout<<"2.HOW ABOUT THE COMPANY'S PARTS ?";
    cout<<"1.NOT UPTO THE MARK\t2.AVERAGE PERFORMANCE\t3.GOOD PERFORMANCE";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[1][option-1]=1;
    cout<<"\n3.HOW DO YOU FIND THE RESALE VALUE OF THE PARTS ?";
    cout<<"1.LOW COST\t2.CANOFFERD TO BUY;\t3.VALUE FOR MONEY ";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[2][option-1]=1;
    cout<<"\n4..HOW OFTEN/GOOD ARE THE SALES/OFFERS ?";
    cout<<"\n1.NO SALES TILL NOW\t2.VERY RARE\t3.COMMON AND ADVANTAGEOUS";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[3][option-1]=1;
    cout<<"\n5.RATE THE SAFETY OF THE PARTS :";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD AND SAFETY";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[4][option-1]=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]>0){
                sum=sum+a[i][j];
                }
        }
    }
    sum=sum/5;
    cout<<"\n***************THANK YOU FOR TAKING THE QUESTIONARE....!!!!*********************";
    return sum;
}

int QuesFurniture(){
    int a[5][5];
    int sum=0,option;
    system("CLS");
    cout<<"\n1.RATE THE COMPANY'S SERVICES AND CARES.";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[0][option]=1;
    cout<<"\n2.RATE THE QUALITY AND DURABILITY OF THE FURNITURE";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[1][option]=1;
    cout<<"\n3.RATE THE QUALITY OF THE MATERIAL USED IN THE FURNITURE";
    cout<<"\n1.BAD MATERIAL\t2.AVERAGE MATERIAL\t3.GOOD MATERIAL\t4.EXCELLENT MATERIALS";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[2][option]=1;
    cout<<"\n4.ARE THE FURNITURES WATER AND INSECT RESISTANT ?";
    cout<<"\n1.NO,VERY BAD\t2.WATER ONLY\t3.INSECT ONLY\t4.BOTH AND EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[3][option]=1;
    cout<<"\n5.RATE THE DESIGN AND STYLE OF THE FURNITURES ";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[4][option-1]=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]>0){
                sum=sum+a[i][j];
                }
        }
    }
    sum=sum/5;
    cout<<"\n***************THANK YOU FOR TAKING THE QUESTIONARE....!!!!*********************";
    return sum;
}


int QuesElectronics(){
    int a[5][5];
    int sum=0,option;
    system("CLS");
    cout<<"\n1.RATE THE COMPANY'S SERVICES AND CARES.";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[0][option]=1;
    cout<<"\n2.RATE THE QUALITY AND DURABILITY OF THE ELECTRONIC ITEM";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[1][option]=1;
    cout<<"\n3.RATE THE QUALITY OF THE MATERIAL USED IN THE ELECTRONIC ITEM";
    cout<<"\n1.BAD MATERIAL\t2.AVERAGE MATERIAL\t3.GOOD MATERIAL\t4.EXCELLENT MATERIALS";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[2][option]=1;
    cout<<"\n4.RATE THE USER-INTERFACE / ANDROID VERSION ?";
    cout<<"\n1.VERY BAD\t2.HANGS A LOT\t3.NEEDED TO IMPROVE ANDROID VERSION\t4.BOTH ARE EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[3][option]=1;
    cout<<"\n5.RATE THE DESIGN AND STYLE OF THE ITEM ";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[4][option-1]=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]>0){
                sum=sum+a[i][j];
                }
        }
    }
    sum=sum/5;
    cout<<"\n***************THANK YOU FOR TAKING THE QUESTIONARE....!!!!*********************";
    return sum;
    }
int QuesTextile(){

    int a[5][5];
    int sum=0,option;
    system("CLS");
    cout<<"\n1.RATE THE COMPANY'S SERVICES AND CARES.";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[0][option]=1;
    cout<<"\n2.RATE THE QUALITY AND DURABILITY OF THE TEXTILES";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[1][option]=1;
    cout<<"\n3.RATE THE QUALITY OF THE MATERIALS SOLD IN THE COMPANT";
    cout<<"\n1.BAD MATERIAL\t2.AVERAGE MATERIAL\t3.GOOD MATERIAL\t4.EXCELLENT MATERIALS";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[2][option]=1;
    cout<<"\n4..HOW OFTEN/GOOD ARE THE SALES/OFFERS ?";
    cout<<"\n1.NO SALES TILL NOW\t2.VERY RARE\t3.COMMON AND ADVANTAGEOUS";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[3][option]=1;
    cout<<"\n5.RATE THE DESIGN AND STYLE OF THE ITEM ";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[4][option-1]=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]>0){
                sum=sum+a[i][j];
                }
        }
    }
    sum=sum/5;
    cout<<"\n***************THANK YOU FOR TAKING THE QUESTIONARE....!!!!*********************";
    return sum;
    }
int QuesEntertaintment(){

     int a[5][5];
    int sum=0,option;
    system("CLS");
    cout<<"\n1.RATE THE COMPANY'S SERVICES AND CARES.";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[0][option]=1;
    cout<<"\n2.RATE THE QUALITY OF THE DISPLAY";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[1][option]=1;
    cout<<"\n3.RATE THE SHOWS/SERIALS TELECASTED ";
    cout<<"\n1.BORING SHOWS\t2.AVERAGE SHOWS\t3.GOOD SHOWS\t4.INTERESTING SHOWS AND SERIALS";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[2][option]=1;
    cout<<"\n4..HOW OFTEN ARE THERE AD BREAKS ?";
    cout<<"\n1.HUGE NUMBER AND IRRITATING\t2.VERY LONG DURATION \t3.SHORT AND LESS DURATION";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[3][option]=1;
    cout<<"\n5.RATE THE DESIGN AND STYLE THE SHOWS AND SERIALS ";
    cout<<"\n1.BAD\t2.AVERAGE\t3.GOOD\t4.EXCELLENT";
    cin>>option;
    if(option>4){
        cout<<"Default rating taken to 2...!!!";
        option=2;
    }
    a[4][option-1]=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]>0){
                sum=sum+a[i][j];
                }
        }
    }
    cout<<"\n***************THANK YOU FOR TAKING THE QUESTIONARE....!!!!*********************";
    sum=sum/5;
    return sum;
    }
void CustomerReviews(){

        system("CLS");
        string code;
        char review[200];
        ifstream fp;
        int ch,rate=0;
        ofstream ptr;
        ptr.open("companyreviews.txt",ios::app);
        struct Detail c[20];
        fp.open("companyDetails.txt",ios::in);
        int rating=0;
        cout<<"ENTER THE COMPANY CODE  :";
        cin>>code;
        for(int i=0;(!fp.eof());i++){
                fp>>c[i].index>>c[i].companyname>>c[i].choice>>c[i].doorno>>c[i].area>>c[i].city>>c[i].pincode>>c[i].phoneno>>c[i].alphanumeric>>c[i].word;
                if(code==c[i].alphanumeric){
                    ptr<<c[i].alphanumeric<<endl;
                    cout<<"\nYOU HAVE CHOOSEN  :"<<c[i].companyname<<"   COMPANY ";
                    cout<<"\nCHOOSE YOUR OPTION :";
                    cout<<"\n\t\t1.TAKE A QUESTIONAIRE \n\t\t2.WRITE A REVIEW\n\t3.RATE IN OUT OF FIVE\n\t";
                    cin>>ch;
                    switch(ch){
                            case 1:
                                {
                                    cout<<"\nYOU HAVE CHOOSE TO TAKE A QUESTIONAIRE :";
                                    if(c[i].choice==1){
                                        rate=QuestionareAutomobile();
                                        ptr<<c[i].alphanumeric<<endl<<rate<<endl;
                                    }
                                    else if(c[i].choice==2){
                                        rate=QuesFurniture();
                                        ptr<<c[i].alphanumeric<<endl<<rate<<endl;
                                    }
                                    else if(c[i].choice==3){
                                        rate=QuesElectronics();
                                        ptr<<c[i].alphanumeric<<endl<<rate<<endl;
                                    }
                                    else if(c[i].choice==4){
                                        rate=QuesTextile();
                                        ptr<<c[i].alphanumeric<<endl<<rate<<endl;
                                    }
                                    else if(c[i].choice==5)
                                        rate=QuesEntertaintment();
                                        ptr<<c[i].alphanumeric<<endl<<rate<<endl;
                                }
                                break;

                            case 2:
                                {
                                    cout<<"\nYOU HAVE CHOOSEN TO WRITE A REVIEW...!!";
                                    cout<<"\nWRITE AN REVIEW ABOUT "<<c[i].companyname<<"  :\n";
                                    gets(review);
                                    ptr<<c[i].alphanumeric<<endl<<review<<endl;
                                }
                                break;

                            case 3:
                                {
                                    cout<<"\n GIVE YOUR RATING ABOUT THE  "<<c[i].companyname<<" (OUT OF FIVE) :\n";
                                    cin>>rate;
                                    ptr<<c[i].alphanumeric<<endl<<rate<<endl;
                                }
                                break;
                            default:
                                cout<<"\nENTER THE CORRECT OPTION......!!!!";

                        }
                }

        }
        fp.close();
        ptr.close();
}

int main()
{
    int z,u;
    cout<<"\n ***************************WELCOME TO THE PACKAGE   (COMPANY USER INTERFACE)  ************************************";
    cout<<"\n\nYOU   ARE    A \n\t\t1.COMPANY \n\t\t2.CUSTOMER"<<endl;
    cin>>z;
    if(z==1){
        cout<<"\n\nCHOOSE YOUR OPTION \n\t\t1.ALREADY REGISTERED AND WANT TO INPUT SHARES\n\t\t2.HAVE TO REGISTER"<<endl;
        cin>>u;
        if(u==1){
            setCompanyShares();
        }
        else if(u==2){
            CompanyDetails();
        }

    }
    else if(z==2){
        cout<<"\nYOU ARE A CUSTOMER";
        cout<<"\n\tYOU CAN GIVE REVIEWS ABOUT THE COMPANY "<<endl;
        CustomerReviews();
    }
    else
        cout<<"PLEASE ENTER THE VALID OPTION....!!!";
    return 0;
}

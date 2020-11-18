#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

 int check_flight(string fno)
 {
     fstream new_file;           //File name is new_file
     new_file.open("schu_data.txt");
     string data;
     int flag=0;
     while(new_file)
     {
         getline(new_file,data);
         if(data==fno)         //Data == flight number
         {
             flag=1;
             break;
         }
     }
     if(flag==1)
     {
         return 0;
     }
     else
     {
         return 1;
     }
     new_file.close();
 }

//CLASS FOR ADMIN/MANAGEMENT

class management{
    int n,m,j,k;
    string no,a,b;
    public:
    void delay_alt();
    void record();
    void add();
};

void management::add()
{
    int dda,mma;
    cout<<"Enter date and month: ";
    cin>>dda>>mma;
    string sa;
    stringstream qs;
    int i=6;
    while(1){
    i++;
    qs<<dda<<"/"<<mma<<"-"<<i;
    qs>>sa;
    if(check_flight(sa)==1){
        break;
    }
    }
    string yu,uy,tyu;
    cout<<"Enter takeoff point and landing point: ";
    cin>>yu>>uy;
    cout<<"Enter time of departure: ";
    cin>>tyu;
    fstream qyu;
    qyu.open("schu_data.txt",ios::app);
    qyu<<sa<<endl<<yu<<" to "<<uy<<endl<<tyu<<endl;
    cout<<"New flight added successfully. flight number:-"<<sa<<endl;
    qyu.close();
}

void management::delay_alt()
{
    string msg;
    incrrr:
    cout<<"Enter flight number to add delay or any other alert";
    cin>>no;
    if(check_flight(no)==1){
        cout<<"Flight not found\n";
        goto incrrr;
    }
    else{
        cout<<"Enter message\n";
        cin.ignore();
        getline(cin,msg);
    }
    fstream vb;
    vb.open("Alert.txt",ios::app);
    vb<<no<<endl<<msg<<endl;
    vb.close();
}
void management::record()
{
    cout<<"\n1.Search record by name\n2.Search flight record\n\n";
    cin>>n;
    fstream qp,re;
    string gv,vg,po,xzx;
    switch(n){
        case 1:
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,a);
        qp.open("data.txt");
        while(qp){
        getline(qp,gv);
        getline(qp,vg);
        if(vg==a){
            cout<<"Flight no:- "<<gv<<endl;
            getline(qp,po);
            cout<<"Age:- "<<po<<endl<<endl;
        }
        else
            getline(qp,po);
        }
        qp.close();
        break;
        case 2:
        cout<<"Enter flight number: ";
        cin>>xzx;
        cout<<"Names of passengers:- \n";
        re.open("data.txt");
        while(re){
            getline(re,gv);
            if(gv==xzx){
            getline(re,vg);
            cout<<"Name:- "<<vg<<endl;
            getline(re,po);
            cout<<"Age:- "<<po<<endl;
            }
            else{
                getline(re,gv);
                getline(re,gv);
            }
        }
        re.close();
        break;
        default:
        cout<<"Enter valid option\n\n";
        }

}

//CLASS FOR CUSTOMER/CONTROLS
class controls
{
    int m,d,mm,dd,yy,age;
    string n,name;
    public:
    void book();
    void details();
    void schudule();
    void alert();
};

void controls::book(){
        wrnof:
        cout<<"Enter flight number(see schedule for flight number) ";
        cin>>n;
        cout<<"finding flight info...\n";
        if(check_flight(n)==1){
        cout<<"Flight number not found\n ";
        goto wrnof;
        }
        else{
        cout<<"Flight found...\n";
        fstream jk;
        jk.open("alert.txt");
        string nm,nnm;
        while(jk){
        getline(jk,nm);
        if(nm==n){
        getline(jk,nnm);
        cout<<nnm<<endl<<endl;
        }
        else{
            getline(jk,nm);
        }
    }
    jk.close();
        fstream f1;
        f1.open("data.txt");
        string abc;
        int count=0;
        while (f1) {
            getline(f1, abc);
            if(abc==n){
                count++;
            }
        }
        f1.close();
        if(count>=10){
            cout<<"All seats are booked\n";
        }
        else{
            cout<<"Enter full name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter age: ";
            cin>>age;
        }
        fstream f;
        f.open("data.txt",ios::app);
        f<<n<<endl<<name<<endl<<age<<endl;
        f.close();
        cout<<"Ticket booked successfully";
    }
}

void controls::schudule()
{
    incrrrrr:
    cout<<"Enter date in dd/mm/yyyy format: ";
    cin >> dd;
    cin.get();
    cin >> mm;
    cin.get();
    cin >> yy;
    if(dd>31 ||mm>12 ||yy!=2020)
    {
        cout<<"Date incorrect"<<endl;
        goto incrrrrr;
    }
    stringstream ss;
    ss<<dd<<"/"<<mm;
    string s;
    ss>>s;
    fstream fa;
    string qqww,qqw;
    fa.open("schu_data.txt");
    while(fa){
        getline(fa,qqww);
        string str2 = qqww.substr(0,5);
        if(str2==s){
            getline(fa,qqw);
            cout<<"Details:-"<<qqw<<endl;
            getline(fa,qqw);
            cout<<"Time:- "<<qqw<<endl;
            cout<<"Flight number: "<<qqww<<endl<<endl;
        }
        else{
            getline(fa,qqw);
            getline(fa,qqw);
        }
    }
    fa.close();
}

void controls::details()
{
    cout<<"Enter flight number: ";
    string sono;
    cin>>sono;
    fstream jk;
        jk.open("alert.txt");
        string nm,nnm;
        while(jk){
        getline(jk,nm);
        if(nm==sono){
        getline(jk,nnm);
        cout<<nnm<<endl<<endl;
        }
        else{
            getline(jk,nm);
        }
    }
    jk.close();
    fstream faaa;
    faaa.open("schu_data.txt",ios::app);
    string qw;
    while(faaa){
        getline(faaa,qw);
        if(qw==sono){
            getline(faaa,qw);
            cout<<"Details:-"<<qw<<endl;
            getline(faaa,qw);
            cout<<"Time:- "<<qw<<endl<<endl;
            break;
        }
        else{
            getline(faaa,qw);
            getline(faaa,qw);
        }
    }
    faaa.close();
    cout<<"Enter name to check status(for same flight)";
    string pp,op,opp;
    cin.ignore();
    getline(cin, pp);
    fstream ll;
    ll.open("data.txt");
    int fpl=0;
    while(ll){
        getline(ll,op);
        if(op==sono){
            getline(ll,opp);
            if(opp==pp){
                fpl=1;
                break;
            }
        }
        else{
            getline(ll,opp);
        }

    }
    if(fpl==1){
        cout<<"Booking found\n";
    }
    else
    {
        cout<<"Booking not found\n";
    }
    ll.close();
    
}
void controls::alert(){
    string cv,nm,nnm;
    fstream jk;
    int fgl=0;
    jk.open("alert.txt");
    cout<<"Enter flight number to see alerts";
    cin>>cv;
    while(jk){
        getline(jk,nm);
        if(nm==cv){
        fgl=1;
        getline(jk,nnm);
        cout<<nnm<<endl<<endl;
        }
        else{
            getline(jk,nnm);
        }
    }
    if(fgl==0){
        cout<<"No alert message found for this flight\n";
    }
    jk.close();

}

    //MAIN FUNCTION
int main()
{
    int ch = 0,ch1 = 0,ch2=0;   //For Switch case
    management m1;
    controls c2;
    loop1:
    while(ch!=3)
    {
    cout<<"\n-----------\nMENU\n1.User\n2.Admin\n3.Exit\n";
        cin>>ch;
    switch(ch)
        {
        case 1:      //Menu - user
            {
            cout<<"\nUser-\n 1.Book tickets\n 2.Flight details \n 3.Flight Schedule \n 4.Alerts\n 5.Go To Main-Menu\n";
            cin>>ch1;
            switch(ch1)
            {
            case 1:
                cout<<"Book Tickets\n";
                c2.book();                  //booking tickects -USER
                break;
            case 2:
                c2.details();    //flight details for user
                break;
            case 3:
                c2.schudule();    //flight schedule
                break;
            case 4:
                c2.alert();       //alert messages for users
                break;
            case 5:
                goto loop1;
                break;
            }
            break;
            }
                
        case 2:      //Menu- admin
            {
            cout<<"Admin-\n 1.Adding delay alert\n 2.Showing records \n 3.Add flight \n 4.Go To Main-Menu\n";
            cin>>ch2;
            switch(ch2)
            {
                case 1:
                    cout<<"Add Delay Alert\n";
                    m1.delay_alt();
                    break;
                case 2:
                    cout<<"Displaying Records\n";
                    m1.record();
                    break;
                case 3:
                    cout<<"Add Flight\n";
                    m1.add();
                    break;
                case 4:
                    goto loop1;
                    break;
                default:
                cout<<"Entre Correct Choice\n";
             }
             break;
             }
        case 3:
         cout<<"Thank You!";
         break;
}    //END OF SWITCH CASE
    
}    //END OF WHILE LOOP
    return 0;
}   //MAIN FUNCTION END
 

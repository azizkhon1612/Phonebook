#include <iostream>
#include <string>
using namespace std;

class contact
{
public:
    string name;
    int dateofbth;
    string phn;
    void add();
    void print();
    void history();
};

void contact::add()
{
    cin>>name;
    cin>>dateofbth;
    cin>>phn;
}
void contact::print()
{
    cout<<name<<endl;
}

void contact::history()
{
    cout<<name<<" "<<dateofbth<<" "<<phn<<endl;


}



int main()
{
    int cnt=0,f=0;
    int i,j;
    char c;
    string fin;


    contact *st=new contact[100];
    contact temp;

    contact *st2=new contact[100];

    while(c!='e')
    {
        cin>>c;
        switch(c)
        {
        case 'n':
            st[cnt].add();
            cnt++;
            break;

        case 's':
            if(cnt!=0)
            {
                for(int i=0; i<cnt-1; i++)
                {
                    for(j=0; j<cnt-i-1; j++)
                    {
                        if(st[j].name>=st[j+1].name)
                        {
                            temp=st[j];
                            st[j]=st[j+1];
                            st[j+1]=temp;

                        }
                    }


                }
                for(int i=0; i<cnt; i++)
                {
                    st[i].print();
                }


            }
            else
            {
                cout<<"is empty"<<endl;
            }



            break;
        //If find button is pressed it will save to history
        case 'f':
            if(cnt!=0)
            {
                cin>>fin;
                for(i=0; i<cnt; i++)
                {
                    if(st[i].name==fin)
                    {
                        st[i].history();

                        st2[f]=st[i];

                    }

                }
                f++;


            }
            else
            {
                cout<<"is empty"<<endl;
            }
            break;
      //History will print elements which you have searched for
        case 'h':
            if(f!=0)
            {
                for(i=0; i<f; i++)
                {
                    if(st2[i].name!=st2[i+1].name)
                    {
                        st2[i].history();
                    }
                }

            }
            else
            {
                cout<<"is empty"<<endl;
            }
            break;
        }

    }






    return 0;
}

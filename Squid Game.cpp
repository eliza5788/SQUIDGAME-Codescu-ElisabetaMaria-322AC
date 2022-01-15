//Codescu Elisabeta Maria 322AC

#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#include<cstring>
#include <random>
#include <bits/stdc++.h>
using namespace std;

class Users
{
public:
    char surname[20];
    char name[20];
    char city[20];
    int debt;
    int weight;
    Users()
    {
        strcpy(surname,"default");
        strcpy(name,"default");
        strcpy(city,"default");
        debt = 0;
        weight = 0;
    }
     ~Users()
     {
         delete[] surname;
         delete[] name;
         delete[] city;
     }
    void setsurname(char s[20])
    {
        strcpy(surname,s);
    }
    void setname(char s[20])
    {
        strcpy(name,s);
    }
    void setcity(char s[20])
    {
        strcpy(city,s);
    }
    void setdebt(int x)
    {
        debt = x;
    }
    void setweight(int x)
    {
        weight = x;
    }
};

class Superviser : public Users
{
public:
    char maskshape[20];
    int nrsuperviser;
    void setmaskshape(char s[20])
    {
        strcpy(maskshape,s);
    }
    void setnrsuperviser(int x)
    {
        nrsuperviser = x;
    }
};

class Contestant : public Users
{
public:
    int nrcontestant;
    int nrsupervisercont;
    void setnrcontestant(int x)
    {
        nrcontestant = x;
    }
    void setnrsupervisercont(int x)
    {
        nrsupervisercont = x;
    }

};
class Superviserreward
{
public:
    long long reward;
    char surname[20];
    char name[20];
    int supervisernr;
    void setsurname(char s[20])
    {
        strcpy(surname,s);
    }
    void setname(char s[20])
    {
        strcpy(name,s);
    }
    void setreward(int x)
    {
        reward = x;
    }
    void setsupervisernr(int x)
    {
        supervisernr = x;
    }
};
int minvalue(int x, int y)
{
    if (x<y)
        return x;
    return y;
}

template <typename T>
T rockpaperscissors(T rps1, T rps2)
{
    if (rps1==1)
    {
        if (rps2==2)
            return rps2;
        return rps1;
    }
    if (rps1==2)
    {
        if (rps2==1)
            return rps1;
        return rps2;
    }
    if (rps1==3)
    {
        if (rps2==1)
            return rps2;
        return rps1;
    }
}
string converttostring(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
int main()
{
    int i, j, n, index=1, k, w=0, random, randomweight, nr, min1=0, min2=0, min3=0, nrnou, f1=0, f2=0, nrelim=1, nr1=1, nr2=1, nr3=1, nr4=1, winner=0;
    int weight1=0, weight2=0, weight3=0, weight4=0, randomnr1, randomnr2, cont1_size, cont2_size, rps1, rps2, nrfinalists, totaldebt=0;
    string s_cont1, s_cont2;
    long long randomdebt;
    Users u[108];
    Contestant c[99], eliminated[98], phase1[50], phase2[14], phase3[7], winnerrps;
    Superviser s[9];
    Superviserreward sr[9];
    fstream newfile;
    newfile.open("surnames.txt",ios::in);
    if (newfile.is_open())
   {
       string strrow;
       while(getline(newfile, strrow))
       {
        n = strrow.length();
        char row[n + 1];
        strcpy(row, strrow.c_str());
        u[index].setsurname(row);
        if (index<=99)
        {
            c[index].setnrcontestant(index);
            c[index].setsurname(row);

        }
        else
        {
            s[index-99].setsurname(row);
            s[index-99].setnrsuperviser(index);
            sr[index-99].setsurname(row);
            sr[index-99].setsupervisernr(index);
            if (index>=100 && index<=102)
                s[index-99].setmaskshape("square");
            if (index>=103 && index<=105)
                s[index-99].setmaskshape("triangle");
            if (index>=106 && index<=108)
                s[index-99].setmaskshape("circle");
        }
        index++;
       }
       newfile.close();
   }
   newfile.open("names.txt",ios::in);
    if (newfile.is_open())
   {
       string strrow;
       index=1;
       while(getline(newfile, strrow))
       {
        n = strrow.length();
        char row[n + 1];
        strcpy(row, strrow.c_str());
        u[index].setname(row);
        if (index<=99)
            c[index].setname(row);
        else
          {
            s[index-99].setname(row);
            sr[index-99].setname(row);
            }
        index++;
       }
       newfile.close();
   }
   newfile.open("cities.txt",ios::in);
    if (newfile.is_open())
   {
       string strrow;
       index=1;
       while(getline(newfile, strrow))
       {
        n = strrow.length();
        char row[n + 1];
        strcpy(row, strrow.c_str());
        u[index].setcity(row);
        randomdebt = 10000 + (rand() % 90001);
        u[index].setdebt(randomdebt);
        randomweight = 50 + (rand() % 51);
        u[index].setweight(randomweight);
        if (index<=99)
           {
               c[index].setcity(row);
               c[index].setdebt(randomdebt);
               c[index].setweight(randomweight);
               totaldebt=totaldebt+c[index].debt;
           }
        else
           {
               s[index-99].setcity(row);
               s[index-99].setdebt(randomdebt);
               s[index-99].setweight(randomweight);
               sr[index-99].setreward(0);
           }
        index++;
       }
       newfile.close();
   }
    index = 1;
    for (i=1; i<=9; i++)
        for (j=1; j<=11; j++)
        {
            c[index].setnrsupervisercont(i);
            index++;
        }
    for (k=1; k<=99; k++)
        {
            if (c[k].nrcontestant % 2 == 0)
            {
                eliminated[nrelim].setsurname("eliminated");
                eliminated[nrelim].setname(" ");
                eliminated[nrelim].setcity("-");
               eliminated[nrelim].setdebt(c[k].debt);
               eliminated[nrelim].setweight(0);
               eliminated[nrelim].setnrcontestant(c[k].nrcontestant);
               eliminated[nrelim].setnrsupervisercont(c[k].nrsupervisercont);
               nrelim++;
            }
            else
            {
                phase1[nr1].setsurname(c[k].surname);
                phase1[nr1].setname(c[k].name);
                phase1[nr1].setcity(c[k].city);
                phase1[nr1].setdebt(c[k].debt);
                phase1[nr1].setweight(c[k].weight);
                phase1[nr1].setnrcontestant(c[k].nrcontestant);
                phase1[nr1].setnrsupervisercont(c[k].nrsupervisercont);
               nr1++;
            }
        }
    cout<<endl<<"\tAfter the RED LIGHT, GREEN LIGHT game took place,\n     these are the contestants still left in the game:"<<endl;
   nr1--;
   for (i=1; i<=nr1; i++)
        cout<<phase1[i].surname<<" "<<phase1[i].name<<" "<<phase1[i].nrcontestant<<endl;
    for (i=1; i<=12; i++)
        weight1=weight1+phase1[i].weight;
    for (i=13; i<=24; i++)
        weight2=weight2+phase1[i].weight;
    for (i=25; i<=36; i++)
        weight3=weight3+phase1[i].weight;
    for (i=37; i<=48; i++)
        weight4=weight4+phase1[i].weight;
    cout<<"\t\tWELCOME TO TUG OF WAR!"<<endl<<endl<<"Rules: The teams will duel 1 vs 1.\n       The team with the bigger total weight will advance to the next round."<<endl;
    cout<<endl<<"\tFIRST SEMIFINAL: TEAM 1 VS TEAM 2"<<endl<<"\t    TEAM 1 TOTAL WEIGHT: "<<weight1<<endl<<"\t    TEAM 2 TOTAL WEIGHT: "<<weight2<<endl;
    min1=minvalue(weight1,weight2);
    try
    {
        if (min1==weight1)
            {
                f1=2;
                throw(f1);
                }
        else
        {
            f1=1;
            throw(f1);
        }
    }
    catch (int f1)
    {
        if (f1 == 1)
        {
            cout<<endl<<"\t         RESULTS:";
            cout<<endl<<"\t   TEAM 2 HAS BEEN ELIMINATED!"<<endl<<"\t   TEAM 1 ADVANCES TO THE FINALS."<<endl;
            for (j=13; j<=24; j++)
                    {

                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
        else
        {
            cout<<endl<<"\t         RESULTS:";
            cout<<endl<<"\t   TEAM 1 HAS BEEN ELIMINATED!"<<endl<<"\t   TEAM 2 ADVANCES TO THE FINALS."<<endl;
            for (j=1; j<=12; j++)
                    {

                        phase1[j].setsurname("eliminated");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
    }
    cout<<endl<<"\tSECOND SEMIFINAL: TEAM 3 VS TEAM 4"<<endl<<"\t    TEAM 3 TOTAL WEIGHT: "<<weight3<<endl<<"\t    TEAM 4 TOTAL WEIGHT: "<<weight4<<endl;
    min2=minvalue(weight3,weight4);
    try
    {
        if (min2==weight3)
            {
                f2=4;
                throw(f2);
                }
        else
        {
            f2=3;
            throw(f2);
        }
    }
    catch (int f2)
    {
        if (f2 == 4)
        {
            cout<<endl<<"\t         RESULTS:";
            cout<<endl<<"\t   TEAM 3 HAS BEEN ELIMINATED!"<<endl<<"\t   TEAM 4 ADVANCES TO THE FINALS."<<endl;
            for (j=25; j<=36; j++)
                    {
                        phase1[j].setsurname("eliminated");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
        if (f2==3)
        {
            cout<<endl<<"\t         RESULTS:";
            cout<<endl<<"\t   TEAM 4 HAS BEEN ELIMINATED!"<<endl<<"\t   TEAM 3 ADVANCES TO THE FINALS."<<endl;
            for (j=37; j<=48; j++)
                    {

                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
    }
    if (f1==1 && f2==3)
    {
        cout<<endl<<"\tFINAL: TEAM 1 VS TEAM 3"<<endl<<"\t    TEAM 1 TOTAL WEIGHT: "<<weight1<<endl<<"\t    TEAM 3 TOTAL WEIGHT: "<<weight3<<endl;
        min3=minvalue(weight1,weight3);
        if (min3==weight1) //team 3 wins
        {
            cout<<endl<<"\t    RESULTS OF TUG OF WAR:";
            cout<<endl<<"\t      TEAM 3 WINS!!!"<<endl;
            for (j=1; j<=12; j++)
                    {
                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
        else //team 1 wins
        {
            cout<<endl<<"\t    RESULTS OF TUG OF WAR:";
            cout<<endl<<"\t      TEAM 1 WINS!!!"<<endl;
            for (j=25; j<=36; j++)
                    {
                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
    }
    if (f1==1 && f2==4)
    {
        cout<<"FINAL: TEAM 1 VS TEAM 4"<<endl<<"\t    TEAM 1 TOTAL WEIGHT: "<<weight1<<endl<<"\t    TEAM 4 TOTAL WEIGHT: "<<weight4<<endl;
        min3=minvalue(weight1,weight4);
        if (min3==weight1) //team 4 wins
        {
            cout<<endl<<"\t    RESULTS OF TUG OF WAR:";
            cout<<endl<<"\t      TEAM 4 WINS!!!"<<endl;
            for (j=1; j<=12; j++)
                    {
                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
        else //team 1 wins
        {
            cout<<endl<<"\t    RESULTS OF TUG OF WAR:";
            cout<<endl<<"\t      TEAM 1 WINS!!!"<<endl;
            for (j=37; j<=48; j++)
                    {
                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
    }
    if (f1==2 && f2==3)
    {
        cout<<"FINAL: TEAM 2 VS TEAM 3"<<endl<<"\t    TEAM 2 TOTAL WEIGHT: "<<weight2<<endl<<"\t    TEAM 3 TOTAL WEIGHT: "<<weight3<<endl;
        min3=minvalue(weight2,weight3);
        if (min3==weight2) //team 3 wins
        {
            cout<<endl<<"\t    RESULTS OF TUG OF WAR:";
            cout<<endl<<"\t      TEAM 3 WINS!!!"<<endl;
            for (j=13; j<=24; j++)
                    {
                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
        else //team 2 wins
        {
            cout<<endl<<"\t    RESULTS OF TUG OF WAR:";
            cout<<endl<<"\t      TEAM 2 WINS!!!"<<endl;
            for (j=25; j<=36; j++)
                    {
                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
    }
    if (f1==2 && f2==4)
    {
        cout<<"FINAL: TEAM 2 VS TEAM 4"<<endl<<"\t    TEAM 2 TOTAL WEIGHT: "<<weight2<<endl<<"\t    TEAM 4 TOTAL WEIGHT: "<<weight4<<endl;
        min3=minvalue(weight2,weight4);
        if (min3==weight2) //team 4 wins
        {
            cout<<endl<<"\t    RESULTS OF TUG OF WAR:";
            cout<<endl<<"\t      TEAM 4 WINS!!!"<<endl;
            for (j=13; j<=24; j++)
                    {
                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
        else //team 2 wins
        {
            cout<<endl<<"\t    RESULTS OF TUG OF WAR:";
            cout<<endl<<"\t      TEAM 2 WINS!!!"<<endl;
            for (j=37; j<=48; j++)
                    {
                        phase1[j].setsurname("contestant");
                        phase1[j].setname("eliminated");
                        phase1[j].setcity(" - ");
                        phase1[j].setweight(0);
                    }
        }
    }
    cout<<endl;
     cout<<"\tAfter the game Tug of War took place,\n    these are the contestants still left in the game:"<<endl<<endl;
     for (i=1; i<=nr1; i++)
     {
         if (strcmp(phase1[i].surname,"contestant")!=NULL && strcmp(phase1[i].name,"eliminated")!=NULL)
         {
                cout<<"         "<<phase1[i].surname<<" "<<phase1[i].name<<endl;
                phase2[nr2].setsurname(phase1[i].surname);
                phase2[nr2].setname(phase1[i].name);
                phase2[nr2].setcity(phase1[i].city);
                phase2[nr2].setdebt(phase1[i].debt);
                phase2[nr2].setweight(phase1[i].weight);
                phase2[nr2].setnrcontestant(phase1[i].nrcontestant);
                phase2[nr2].setnrsupervisercont(phase1[i].nrsupervisercont);
                nr2++;
         }
         else
         {
                eliminated[nrelim].setsurname("eliminated");
                eliminated[nrelim].setname(" ");
                eliminated[nrelim].setcity("-");
                eliminated[nrelim].setdebt(phase1[i].debt);
                eliminated[nrelim].setweight(0);
                eliminated[nrelim].setnrcontestant(phase1[i].nrcontestant);
                eliminated[nrelim].setnrsupervisercont(phase1[i].nrsupervisercont);
                nrelim++;
         }
     }
     cout<<endl;
     nr2--;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    cout<<"\t\tWELCOME TO MARBLES!"<<endl<<endl<<"  Rules: The contestants still left in the game will be divided in pairs of 2..\n         Each contestant will choose a random number, between 1-1000.\n         The contestant with the smaller number advances to the next round."<<endl<<endl;
     i=1;
     while(i<=13)
     {
         cout<<"  A new pair is now fighting.";
         randomnr1=dis(gen);
         randomnr2=dis(gen);
         min1=minvalue(randomnr1,randomnr2);
         cout<<"   "<<randomnr1<<" vs "<<randomnr2<<endl;
         if (min1==randomnr1)
         {
                cout<<" The contestant who chose number "<<randomnr1<<" advances to the next round."<<endl;
                phase3[nr3].setsurname(phase2[i].surname);
                phase3[nr3].setname(phase2[i].name);
                phase3[nr3].setcity(phase2[i].city);
                phase3[nr3].setdebt(phase2[i].debt);
                phase3[nr3].setweight(phase2[i].weight);
                phase3[nr3].setnrcontestant(phase2[i].nrcontestant);
                phase3[nr3].setnrsupervisercont(phase2[i].nrsupervisercont);
                nr3++;
                eliminated[nrelim].setsurname("eliminated");
                eliminated[nrelim].setname(" ");
                eliminated[nrelim].setcity("-");
                eliminated[nrelim].setdebt(phase2[i+1].debt);
                eliminated[nrelim].setweight(0);
                eliminated[nrelim].setnrcontestant(phase2[i+1].nrcontestant);
                eliminated[nrelim].setnrsupervisercont(phase2[i+1].nrsupervisercont);
                nrelim++;
         }
         else
         {
                cout<<" The contestant who chose number "<<randomnr2<<" advances to the next round."<<endl;
                phase3[nr3].setsurname(phase2[i+1].surname);
                phase3[nr3].setname(phase2[i+1].name);
                phase3[nr3].setcity(phase2[i+1].city);
                phase3[nr3].setdebt(phase2[i+1].debt);
                phase3[nr3].setweight(phase2[i+1].weight);
                phase3[nr3].setnrcontestant(phase2[i+1].nrcontestant);
                phase3[nr3].setnrsupervisercont(phase2[i+1].nrsupervisercont);
                nr3++;
                eliminated[nrelim].setsurname("eliminated");
                eliminated[nrelim].setname(" ");
                eliminated[nrelim].setcity("-");
                eliminated[nrelim].setdebt(phase2[i].debt);
                eliminated[nrelim].setweight(0);
                eliminated[nrelim].setnrcontestant(phase2[i].nrcontestant);
                eliminated[nrelim].setnrsupervisercont(phase2[i].nrsupervisercont);
                nrelim++;
         }
         i=i+2;
     }
     nr3--;
     cout<<endl<<"After the game of Marbles took place, the contestants below \nhave advanced and will participate in the Genken / Rock, Paper, Scissors game,\nin the descending order of their respective numbers. This is their order:"<<endl<<endl;
     for (i=nr3; i>=1; i--)
        cout<<"        "<<phase3[i].surname<<" "<<phase3[i].name<<" (number "<<phase3[i].nrcontestant<<")"<<endl;
    cout<<"RULES: The 7 contestants left in the game will play Genken 1 vs 1, in descending order.\nRock=1, Paper = 2, Scissors = 3\n\n"<<endl;
    nrfinalists=7;
    winnerrps.setsurname(phase3[nrfinalists].surname);
    winnerrps.setname(phase3[nrfinalists].name);
    winnerrps.setcity(phase3[nrfinalists].city);
    winnerrps.setdebt(phase3[nrfinalists].debt);
    winnerrps.setweight(phase3[nrfinalists].weight);
    winnerrps.setnrcontestant(phase3[nrfinalists].nrcontestant);
    winnerrps.setnrsupervisercont(phase3[nrfinalists].nrsupervisercont);
    nrfinalists--;
    uniform_int_distribution<> genken(1, 3);
    while (nrfinalists>1)
    {
        rps1=genken(gen);
        rps2=genken(gen);
        while (rps1==rps2)
        {
            rps1=genken(gen);
            rps2=genken(gen);
        }
        winner=rockpaperscissors(rps1,rps2);
        if (winner==rps1)
        {
                eliminated[nrelim].setsurname("eliminated");
                eliminated[nrelim].setname("contestant");
                eliminated[nrelim].setcity("-");
                eliminated[nrelim].setdebt(phase3[nrfinalists].debt);
                eliminated[nrelim].setweight(0);
                eliminated[nrelim].setnrcontestant(phase3[nrfinalists].nrcontestant);
                eliminated[nrelim].setnrsupervisercont(phase3[nrfinalists].nrsupervisercont);
                nrelim++;
                phase3[nrfinalists].setsurname(winnerrps.surname);
                phase3[nrfinalists].setname(winnerrps.name);
                phase3[nrfinalists].setcity(winnerrps.city);
                phase3[nrfinalists].setdebt(winnerrps.debt);
                phase3[nrfinalists].setweight(winnerrps.weight);
                phase3[nrfinalists].setnrcontestant(winnerrps.nrcontestant);
                phase3[nrfinalists].setnrsupervisercont(winnerrps.nrsupervisercont);
        }
        else
        {
            eliminated[nrelim].setsurname("eliminated");
            eliminated[nrelim].setname("contestant");
            eliminated[nrelim].setcity("-");
            eliminated[nrelim].setdebt(winnerrps.debt);
            eliminated[nrelim].setweight(0);
            eliminated[nrelim].setnrcontestant(winnerrps.nrcontestant);
            eliminated[nrelim].setnrsupervisercont(winnerrps.nrsupervisercont);
            nrelim++;
            winnerrps.setsurname(phase3[nrfinalists].surname);
            winnerrps.setname(phase3[nrfinalists].name);
            winnerrps.setcity(phase3[nrfinalists].city);
            winnerrps.setdebt(phase3[nrfinalists].debt);
            winnerrps.setweight(phase3[nrfinalists].weight);
            winnerrps.setnrcontestant(phase3[nrfinalists].nrcontestant);
            winnerrps.setnrsupervisercont(phase3[nrfinalists].nrsupervisercont);
        }
        nrfinalists--;
    }
    cout<<"THE WINNER OF SQUID GAME IS: "<<winnerrps.surname<<" "<<winnerrps.name<<endl<<"\nHis debt is $"<<winnerrps.debt<<endl;
    totaldebt=totaldebt-winnerrps.debt;
    cout<<"He will receive $"<<totaldebt<<"."<<endl;
    int winnersuperviser=winnerrps.debt*10;
    cout<<endl<<"His superviser will receive $"<<winnersuperviser<<".";
    int nrspr=eliminated[1].nrsupervisercont;
    for (i=1; i<nrelim; i++)
    {
        if (nrspr==eliminated[i].nrsupervisercont)
        {
            sr[nrspr].reward=sr[nrspr].reward+eliminated[i].debt;
        }
        else
        {
            nrspr=eliminated[i].nrsupervisercont;
            sr[nrspr].reward=eliminated[i].debt;
        }
    }
    cout<<endl<<"The money received by the supervisers is:\n"<<endl;
    for (i=1; i<=9; i++)
        cout<<sr[i].surname<<" "<<sr[i].name<<" $"<<sr[i].reward<<endl;
    return 0;
}

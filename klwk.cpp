#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    for(int gs=1;;gs++) {
        int n[7][7] = {{3,5,3,3,3,3,3},
                       {5,1,0,0,0,0,3},
                       {3,0,0,0,0,0,3},
                       {3,0,0,0,0,0,3},
                       {3,0,0,0,0,0,3},
                       {3,0,0,0,0,2,3},
                       {3,3,3,3,3,3,3}};
        int a=1, b=1;
        int ah, bh;
        srand(time(0));
        ah = rand()%5+1;
        if(ah==1) {
            bh = rand()%4+2;
        } else if(ah==5) {
            bh = rand()%4+1;
        } else {
            bh = rand()%5+1;
        }
        n[ah][bh] = 4; // �޸�����������ķֺ�
        
        int ah2, bh2;
        ah2 = rand()%5+1;
        if(ah2==1) {
            bh2 = rand()%4+2;
        } else if(ah2==5) {
            bh2 = rand()%4+1;
        } else {
            bh2 = rand()%5+1;
        }
        
        while(ah==ah2 and bh==bh2) {
            ah2 = rand()%5+1;
            if(ah2==1) {
                bh2 = rand()%4+2;
            } else if(ah2==5) {
                bh2 = rand()%4+1;
            } else {
                bh2 = rand()%5+1;
            }
        }
        n[ah2][bh2] = 4;
        
        for(;;) {
            n[a][b] = 1;
            for(int i=0; i<=6; i++) {
                for(int j=0; j<=6; j++) {
                    if(n[i][j]==1) {
                        cout<<"��";
                    } else if(n[i][j]==0) {
                        cout<<"__";
                    } else if(n[i][j]==2) {
                        cout<<"��"; 
                    } else if(n[i][j]==3) {
                        cout<<"ǽ";
                    } else if(n[i][j]==4) {
                        cout<<"��";
                    } else {
                        cout<<"��";
                    } 
                }
                cout<<endl;
            }
            
            cout<<endl;
            cout<<"��ǰ������"<<gs<<endl;
            if(gs==5) {
                cout<<"PS������������ddd�����������Դ�����"<<endl;
            }
            
            if(a==5 and b==5) {
                cout<<"\nvictory"<<endl;
                system("pause");
                break; 
            } else if((a==ah and b==bh) or (a==ah2 and b==bh2)) {
                cout<<"\nlose"<<endl;
                system("pause");
                return 0;
            }
            
            int gl;
            gl = rand()%2;
            
            if((a==1 and b==0) or (a==0 and b==1)) {
                if(gl==1) {
                    cout<<"\nvictory"<<endl;
                    system("pause");
                    break;
                } else {
                    cout<<"\nlose"<<endl;
                    system("pause");
                    return 0;
                }
            }		
            
            char ru;
            cout<<"������ƶ� ";
            cin>>ru;
            
            if(ru=='s') {
                if(a<5) {
                    a++;
                    n[a-1][b] = 0;
                }
            } else if(ru=='w') {
                if(a>1) {
                    a--;
                    n[a+1][b] = 0;
                } else if(a==1 and b==1) {
                    a--;
                    n[1][1] = 0;
                }	
            } else if(ru=='d') {
                if(b<5) {
                    b++;
                    n[a][b-1] = 0;
                }
            } else if(ru=='a') {
                if(b>1) {
                    b--;
                    n[a][b+1] = 0;
                } else if(a==1 and b==1) {
                    b--;
                    n[1][1] = 0;
                }
            } else {
                cout<<"\n��"<<endl;
                system("pause");
                return 0;
            }
            
            system("cls");
        }
        
        system("cls");
    }	 
}

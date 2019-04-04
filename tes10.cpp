
#include <windows.h>
#include <graphics.h>
#include "boolean.h"
#include "Atthoriq.h"
#include "Khalid.h"
#include "Nadira.h"
#include "Fauzan.h"
#include "Bambang.h"
#include "Maulana.h"

  #include <unistd.h>

 //void des_tile(int x,int y);
 
int main(){
		
	initwindow(1320,820);
 	
	int mousex,mousey;
 	char pil;
	
	bgm();
	
	while(!ismouseclick(WM_LBUTTONDOWN)){
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    outtextxy(470,200,"JUST STANCE"); 
    // play
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
    outtextxy(580,280,"PLAY");

    //high score
    outtextxy(500,350,"HIGHSCORE");

    // exit
 
     outtextxy(580,420,"EXIT");
 
 
    }
     
     
    while(1)
    {
    getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
     //buat buka map
    if ((mousex>440) && (mousex<700) && (mousey>270)&&(mousey<300)){
 
    isiMain();
    	delay(1000);
        getch();
        closegraph(-1); 
     	
 	}
 	}
     getch();	
 }
 
 void isiMain(){
 	
 	cleardevice();
 	int i, j, x=40, y=640;
 	
 	int point=0;
 	setviewport(0,0,1320,720,1);
 	matrix();
 	matrix2();
 	status_fall = false;
 	status_rope = false;
 	status_menang = false;
 	lantai_dasar = false;
    int ch;
    char gerak;
    char diem;
    while(1){
     	setviewport(0,0,1320,720,1);
     	if(status_fall == false&&lantai_dasar != true)
     	{
     		gerak = getch();
     		switch(gerak)                                            //check if a key is pressed
 	        {
 		        case 'w':                           //move upward
 		        {
 		        	move_upward( x, &y);
 		        	fflush(stdin);
 		        	count++;
 		        	break;
 		        }
 		        case 'a':                           //move left
 		        {
 					move_left( &x, y);
 					cek_jatoh();
 					cek_ambil(&point);
 					count++;				
 					break;
 		 		}
 		        case 'd':                           //move right
 		    	{
 		        	move_right( &x, y);
 		        	cek_jatoh();
 		        	cek_ambil(&point);
 					count++;	
 		        	break;
 				}  	
 				case 's':                           //move down
 				{
 					cek_jatoh();
 					if(status_rope)
 					{
 						status_fall = true;
 					}
 					move_down( x, &y);
 					count++;
 					break;
 				}
 				case ',':{
 					check_tileL( x, y);
 					break;
 				}
 				case '.':{
 					check_tileR( x, y);
 					break;
 				}	
 		        if(ch==27)                           //exit when esc pressed
 		        {
 		            exit(1);
 		        }
 	        }
 		}
 		else if(status_fall == true)
 		{
 			fall( x, &y);
 			cek_jatoh();
 		}
 		cek_jatoh();
 	}
     getch();
 }
 
 void fall(int x, int *y)
 {
 	int k=4;
 	status_rope=false;
 	move(&k);
 	delay(120);
 	matrix2();
 	if(k==10)
 	{
 		setviewport(x,*y,x+41,*y+41,1);
 		clearviewport();
 		*y=*y+40;	
 	}
 	else{
 		setviewport(x,*y,x+41,*y+41,1);
 		clearviewport();
 		*y=*y+40;
 	}
 }
 
void cek_lantai(int *i)
{
	if(*i==17){
		lantai_dasar = true;
		status_fall = false;
	}else{
		lantai_dasar = false;
		status_fall = true;
	}
}
 void cek_jatoh()
 {
 	int i,j;
 	i=0;
     int awal=0;
     while(i<18){
         j=0;
         while(j<33){
         	if(test.player[i][j]==2 && test.map[i][j]==4 )
         	{
         		status_rope = true;
 				status_fall = false; 
 			}
 			if(test.player[i][j]==2 && test.map[i+1][j]==0 && test.map[i][j]==0)
 			{
 				status_fall = true;
 				cek_lantai(&i);
 			}
 			if(test.player[i][j]==2 && test.map[i+1][j]==1)
 			{
 				status_fall = false;
 			}
 			if(test.player[i][j]==2 && test.map[i+1][j]==4 )
 			{
 				status_fall = true;				
 			}
 			if(test.player[i][j]==2 && test.map[i+1][j]==3)
 			{
 				status_fall = false;
 			}
 			if(test.player[i][j]==2 && test.map[i][j]==8)
 			{
 				lantai_dasar = true;
 			}
         j++;
         }
     i++;
     }
 }
 
 void cek_ambil(int *point)
 {
 	int i,j;
 	i=0;
 	while (i<18){
 		j=0;
 		while(j<33){
 			if(test.player[i][j]==2 && test.map[i][j]==5){
 				test.map[i][j]=0;
 				*point = *point + 200;
 				if(*point >= 1200)
 				{
 					status_menang= true;
 					setviewport(0,0,1320,720,1);
 					matrix2();
 					break;
 				}
 			}
 			j++;	
 		}
 		i++;	
 	}
 }
 void check_tileL(int x,int y){
 	int i,j;
 	i=0;
 	while (i<18){
 		j=0;
 		while(j<33){
 			if(test.map[i][j-1] != 3 && test.map[i][j] != 4)
 			{
 				if(test.player[i][j]==2 && test.map[i+1][j-1]==1){
 					test.map[i+1][j-1] = 0;
 					//sleep(1000L);
 					//test.map[i+1][j-1] = 1;
 					setviewport(x,y+41,x-41,y+81,1);
 					clearviewport();
 					break;
 				}
 			}
 			j++;
 		}                         
 		i++;
 	}
 }
 
 void check_tileR(int x,int y){
 	int i,j;
 	i=0;
 	while (i<18){
 		j=0;
 		while(j<33){
 			if(test.map[i][j+1] != 3 && test.map[i][j] != 4)
 			{
 				if(test.player[i][j]==2 && test.map[i+1][j+1]==1){
 				test.map[i+1][j+1] = 0;
 				setviewport(x+41,y+41,x+81,y+81,1);
 				clearviewport();
 				//sleep(1000L);
 				//test.map[i+1][j+1] = 1;
 				//setviewport(x+41,y+41,x+81,y+81,1);
 				//clearviewport();
 				break;
 				}
 			}
 			j++;
 		}
 		i++;
 	}
 }
 
 void bgm(){
 	sndPlaySound("jazz.wav", SND_FILENAME | SND_ASYNC);
 }
 
 void move_down(int x, int *y)
 {
 	int k=4;
 	move(&k);
 	//delay(60);
 //	matrix2();
 	climb();
 	//setviewport(x,*y,x+41,*y+41,1);
 	//clearviewport();
 	if(k==10)
 	{
 		//move(&k);
 		//delay(60);
 		//matrix2();
 		setviewport(x,*y,x+41,*y+41,1);
 		clearviewport();
 		*y=*y+40;
 	}
 	else if(k==15)
 	{
 		readimagefile("ladder2.jpg",x,*y,x+40,*y+40);
 		*y=*y+40;
 	}
 	else if(k==20)
 	{
 		readimagefile("rope4.jpg",x,*y,x+40,*y+40);
 		*y=*y+40;
 	}
 }
 void move_upward(int x, int *y)
 {
 	int k=2;
 	move(&k);
 //	matrix2();
 	climb();
 	if(k==10)
 	{
 		//setviewport(x,*y,x+41,*y+41,1);
 		//clearviewport();
 		readimagefile("ladder2.jpg",x,*y,x+40,*y+40);
 		*y=*y-40;
 	}
 }
 void move_left(int *x,int y)
 {
 	int k=1,z;
 	move(&k);
 //	matrix2();
 	kiwo();
 	if(k==10)
 	{
 		setviewport(*x,y,*x+41,y+41,1);
 		clearviewport();
 		*x=*x-40;	
 	}
 	else if(k==15)
 	{
 		readimagefile("ladder2.jpg",*x,y,*x+40,y+40);
 		*x=*x-40;	
 	}
 	else if(k==20)
 	{
 		readimagefile("rope4.jpg",*x,y,*x+40,y+40);
 		*x=*x-40;	
 	}
 	else{
 		
 	}
 }
  
 void move_right(int *x, int y)
 {
 	int k=3;
 	move(&k);
 //	matrix2();
 	tengen();
 	if(k==10)
 	{
 		setviewport(*x,y,*x+41,y+41,1);
 		clearviewport();
 		*x=*x+40;
 	}
 	else if(k==15)
 	{
 		readimagefile("ladder2.jpg",*x,y,*x+40,y+40);
 		*x=*x+40;	
 	}
 	else if(k==20)
 	{
 		readimagefile("rope4.jpg", *x, y, *x+40, y+40);
 		*x=*x+40;	
 	}
 }
 
 void matrix()
 {
 	int i,j;
 	i=0;
     int awal=0;
     while(i<18){
         j=0;
         while(j<33){
             if(test.map[i][j]==1){
                 readimagefile("brick.jpg", awal+40*j, awal+40*i, 40+40*j, 40+40*i);
             }
             else if(test.map[i][j]==3){
                 readimagefile("ladder2.jpg", awal+40*j, awal+40*i, 40+40*j, 40+40*i);
             }
         	else if(test.map[i][j]==4){
                 readimagefile("rope4.jpg", awal+40*j, awal+40*i, 40+40*j, 40+40*i);
             }
             else if(test.map[i][j]==5){
             	readimagefile("coin2.jpg", awal+40*j, awal+40*i, 40+40*j, 40+40*i);
 			}
 			else if(test.map[i][j]==7){
             	readimagefile("polos.jpg", awal+40*j, awal+40*i, 40+40*j, 40+40*i);
 			}
 			else if(test.map[i][j]==8){
             	readimagefile("zombie.gif", awal+40*j, awal+40*i, 40+40*j, 40+40*i);
 			}
 			else if(test.player[i][j]==2)
 			{
 				readimagefile("stance2.gif", awal+40*j, awal+40*i, 40+40*j, 40+40*i);
 			}
         j++;
         }
     i++;
     }
 } 
 void matrix2()
 {
 	int i,j;
 	i=0;
     int awal=0;
     while(i<18){
         j=0;
         while(j<33){
            if(test.player[i][j]==2){
                //readimagefile("stance2.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
            }
            else if(status_menang)
 			{
 				if(test.map[i][j]==6)
 				{
 					test.map[i][j]=3;
 					readimagefile("ladder2.jpg",awal+40*j,awal+40*i,40+40*j,40+40*i);
 				}
 			}
         j++;
         }
     i++;
     }
 }
 
 void move(int *k)
 {
 	int i,j;
 	i=0;
     while(i<18){
         j=0;
         while(j<33){
         	if(*k==3)
         	{
         		if(test.player[i][j]==2)
 				{
                 	test.player[i][j]=0;
                 	j++;
                 	test.player[i][j]=2;
                 	if(test.map[i][j]==1){
 						test.player[i][j]=0;
 						j--;
 						test.player[i][j]=2;
 					} 
 					else if(test.map[i][j-1]==3)
 					{
 					*k=15;
 					break;
 					}
 					else if(test.map[i][j-1]==4)
 					{
 					*k=20;
 					break;
 					}
 					else{
 					*k=10;
 					break;
 					}
            		}
 			}
 			if(*k==1)
 			{
 				if(test.player[i][j]==2)
 				{
 	               	test.player[i][j]=0;
 	               	j--;
 	               	test.player[i][j]=2;
 	            	if(test.map[i][j]==1){
 						test.player[i][j]=0;
 						j++;
 						test.player[i][j]=2;
 					}
 					else if(test.map[i][j+1]==3)
 					{
 					*k=15;
 					break;
 					}
 					else if(test.map[i][j+1]==4)
 					{
 					*k=20;
 					break;
 					}
 					else{
 					*k=10;
 					break;
 					}
 				}
 			}
 			if(*k==2)
 			{
 				if(test.player[i][j]==2 && test.map[i][j]==3)
 				{
 					test.player[i][j]=0;
 	               	i--;
 	               	test.player[i][j]=2;
 	               	if(test.map[i][j]==1){
 						test.player[i][j]=0;
 						i++;
 						test.player[i][j]=2;
 					} else{
 					*k=10;
 					break;
 					}
 				}
 			}
 			if(*k==4)
 			{
 				if(test.player[i][j]==2 )
 				{
 					i++;
 					if(test.map[i][j]==3 || test.map[i][j]==0 || test.map[i][j]==4)
 					{
 						test.player[i][j]=2;
 						i--;
 		        	    test.player[i][j]=0;
 						if(test.map[i][j]==1){
 							test.player[i][j]=0;
 							i++;
 							test.player[i][j]=2;
 							*k=11;
 						}
 						else if(test.map[i+1][j]==test.map[i][j])
 						{
 						*k=15;
 						break;
 						}
 						else if(test.map[i][j]==4)
 						{
 						*k=20;
 						break;
 						}
 						else{
 						*k=10;
 						break;
 						} 
 					}
 				}
 			}
         j++;
         }
     i++;
     }
 }
 void stanceright()
 {
 	int i,j;
 
 	i=0;
     int awal=0;
     while(i<15){
         j=0;
         while(j<20){
             if(test.player[i][j]==2){
                 readimagefile("stance1.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
             }
         j++;
         }
     i++;
     }
 }
 void stanceleft()
 {
 	int i,j;
 
 	i=0;
     int awal=0;
     while(i<18){
         j=0;
         while(j<33){
              if(test.player[i][j]==2){
                 readimagefile("stance2.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
             }
         j++;
         }
     i++;
     }
 }
 
 void climb()
 {
 	int i,j;
 
 	i=0;
     int awal=0;
     while(i<18){
         j=0;
         while(j<33){
         	if(test.map[i][j]==3){
         		if(count%2 == 0){
 					if(test.player[i][j]==2){
 			        	readimagefile("laddergif1.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 			        }
 				}else if(count%2 == 1){
 					if(test.player[i][j]==2){
 	    		    	readimagefile("laddergif3.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		    }
 				}//else if(count%4 == 2){
 				//	if(test.player[i][j]==2){
 	    		//    	readimagefile("laddergif3.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		//    }
 				//}else if(count%4 == 3){
 				//	if(test.player[i][j]==2){
 	    		//    	readimagefile("laddergif4.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		//    }
 				//}
 			}else if(test.map[i][j]!=3 && test.map[i+1][j]==3){
 				if(test.player[i][j]==2){
 	    		   	readimagefile("stance1.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		}
 			}else if(status_menang)
 			{
 				if(test.map[i][j]==6)
 				{
 					test.map[i][j]=3;
 					readimagefile("ladder2.jpg",awal+40*j,awal+40*i,40+40*j,40+40*i);
 				}
 			}
         	j++;
 		}
 		i++;
     }
 }
 	
 void kiwo(){
 	int i,j;
 
 	i=0;
     int awal=0;
     while(i<18){
         j=0;
         while(j<33){
         	if(test.player[i][j]==2 && test.map[i][j-1]==1){
         		if(test.map[i][j]==3)
         		{
         			readimagefile("laddergif1.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
				}else
				{
					readimagefile("runleftgif3.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
				}
				break;
 			}
         	else if(test.map[i][j]==0 || test.map[i][j]==3 || test.map[i][j]==5 || test.map[i][j]==4){
         		if(count%4 == 0){
 					if(test.player[i][j]==2){
 			        	readimagefile("runleftgif1.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 			        }
 				}else if(count%4 == 1){
 					if(test.player[i][j]==2){
 	    		    	readimagefile("runleftgif3.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		    }
 				}else if(count%4 == 2){
 					if(test.player[i][j]==2){
 	    		    	readimagefile("runleftgif5.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		    }
 				}else if(count%4 == 3){
 					if(test.player[i][j]==2){
 	    		    	readimagefile("runleftgif7.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		    }
 				}
 			}else if(test.map[i][j]==3){
 				climb();
 			}
 			else if(status_menang)
 			{
 				if(test.map[i][j]==6)
 				{
 					test.map[i][j]=3;
 					readimagefile("ladder2.jpg",awal+40*j,awal+40*i,40+40*j,40+40*i);
 				}
 			}
         	j++;
 		}
 		i++;
     }
 }
 	
 
 void tengen(){
 	int i,j;
 
 	i=0;
     int awal=0;
     while(i<18){
         j=0;
         while(j<33){
         	if(test.player[i][j]==2 && test.map[i][j+1]==1){
         		if(test.map[i][j]==3)
         		{
         			readimagefile("laddergif1.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
				 }else{
				 	readimagefile("runrightgif3.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
				 }	
				break;
 			}
         	else if(test.map[i][j]==0 || test.map[i][j]==3 || test.map[i][j]==5 || test.map[i][j]==4){
         		if(count%4 == 0){
 					if(test.player[i][j]==2){
 			        	readimagefile("runrightgif1.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 			        }
 				}else if(count%4 == 1){
 					if(test.player[i][j]==2){
 	    		    	readimagefile("runrightgif3.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		    }
 				}else if(count%4 == 2){
 					if(test.player[i][j]==2){
 	    		    	readimagefile("runrightgif5.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		    }
 				}else if(count%4 == 3){
 					if(test.player[i][j]==2){
 	    		    	readimagefile("runrightgif7.gif",awal+40*j,awal+40*i,40+40*j,40+40*i);
 	    		    }
 				}
 			}else if(test.map[i][j]==3){
 				climb();
 			}
 			else if(status_menang)
 			{
 				if(test.map[i][j]==6)
 				{
 					test.map[i][j]=3;
 					readimagefile("ladder2.jpg",awal+40*j,awal+40*i,40+40*j,40+40*i);
 				}
 			}
         	j++;
 		}
 		i++;
     }
 }
 


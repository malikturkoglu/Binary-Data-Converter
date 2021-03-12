#include "stdio.h"                // system programming project #1 : Malik Türkoðlu : 150116044 : 24.03.2019 
#define MAXCHAR 1500             //bazý özel durumlarda variable larda overflow durumu ortaya çýkabilmektedir. 
#include <stdio.h>              // Onun dýþýnda her bir fonksiyon yazýlmýþtýr.
#include<locale.h>            
#include <string.h>             //floating pointlerde, eðer exponent hep 1 veya 0 ise hep sabit sayý döndürmekte, mesela byte-3 için -170141183460469230000000000000000000000.000000
#include <stdio.h>              // veya sýfýr döndürmekte, 6-byte ta deðeri direk 0 a yuvarlamakta , fakat tüm deðerler (exponent,sign,fration,mantissa) bunlar komutta yazmaktadýr.
#include <string.h>             // kaynakça en alt kýsýmdadýr , kullanmýþ olduðum bazý bilgiler o internet siteleri aracýyla öðrenmiþ bulunmaktayým.
#include <math.h>

void HexConvertBin(char* hexdec,char* s)        // This help us for the convert hex to binary form.
{ 
int len = strlen(s);
	long int i = 0; 

	while (hexdec[i]) { 

		switch (hexdec[i]) { 
		case '0': 
		strcat( s, "0000" );
		
			break; 
		case '1': 
		
			strcat( s, "0001" );
			break; 
		case '2': 
		
			strcat( s, "0010" );
			break; 
		case '3': 
		
			strcat( s, "0011" ); 
			break; 
		case '4': 
		
			strcat( s, "0100" );
			break; 
		case '5': 
		
			strcat( s, "0101" ); 
			break; 
		case '6': 
		
			strcat( s, "0110" );
			break; 
		case '7': 
		 
			strcat( s, "0111" );
			break; 
		case '8': 
		
			strcat( s, "1000" );
			break; 
		case '9': 
		
			strcat( s, "1001" );
			break; 
		case 'A': 
		case 'a': 
		
			strcat( s, "1010" );
			break; 
		case 'B': 
		case 'b': 
		
			strcat( s, "1011" );
			break; 
		case 'C': 
		case 'c': 
		
			strcat( s, "1100" );
			break; 
		case 'D': 
		case 'd': 
		
			strcat( s, "1101" );
			break; 
		case 'E': 
		case 'e': 
			
			strcat( s, "1110" );
			break; 
		case 'F': 
		case 'f': 
			strcat( s, "1111" );
		
			break; 
		default: 
			printf("\nInvalid hexadecimal digit %c", 
				hexdec[i]); 
		} 
		i++; 
	} 
} 

int getNum(char ch)
{
    int num=0;
    if(ch>='0' && ch<='9')
    {
    	switch(ch)
        { 
            case '0':num=0; break;
        	case '1':num=1; break;
            case '2':num=2; break;
            case '3':num=3; break;
            case '4':num=4; break;
            case '5':num=5; break;
            case '6':num=6; break;
            case '7':num=7; break;
            case '8':num=8; break;
            case '9':num=9; break;
      }
    }
    else
    {
        switch(ch)
        {   
            case 'A': case 'a': num=10; break;
            case 'B': case 'b': num=11; break;
            case 'C': case 'c': num=12; break;
            case 'D': case 'd': num=13; break;
            case 'E': case 'e': num=14; break;
            case 'F': case 'f': num=15; break;
            default: num=0;
        }
    }
    return num;
}
 
unsigned int hex2int( char hex[])
{
    unsigned int x=0;
    x=(getNum(hex[1]))*16+(getNum(hex[0]));
}

void selectedbyte(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}


int main() {	
	FILE * fp;
	
   fp = fopen ("output.txt","w");
	FILE *pToFile = fopen("input.txt","r");                                             // read the file and copy to a char array
char isim[MAXCHAR];
 isim[0] = '\0';	
	int line = 0;
	
	char input[512];
	
	while( fgets( input, 512, pToFile )) {
		line++;
		strcat(isim,input);	                                           // I put whole things in char isim[maxchar] array.
	
	}

	fclose(pToFile);                                                                                 
                                                                                          // take the inputs from user
int selectedEndian;
int selectedType;
int selectedByte;
printf("System programming-Project 1 \n");
printf("Please give inputs : \n");
printf("Byte ordering: Big Endian (0) Little Endian(1)\n");
scanf("%d", &selectedEndian);
printf("Data type: Unsigned number(0) , signed number(1), Floating point(2)\n");
scanf("%d", &selectedType);
printf("Data type size: 1-byte(1), 2-bytes(2), 3-bytes(3),4 bytes(4),6-bytes(6) \n");
scanf("%d", &selectedByte);

int userbyte=selectedByte;
int userbyte1=userbyte*2;
int byte;
if(userbyte==1)
byte=2*userbyte+(2*userbyte+1)/3;	



	
else
byte=2*userbyte+1+(2*userbyte+1)/3;
int x=0;
size_t len = strlen(isim);                                                                         //burdan itibaren while loop koymayý düþünüyorum
while(x<len-6){
	
char str[1024];	                        // this store to selected bytes.
str[0]='\0';


	for(int i=0+x; i<byte+x ; i++){             // copy to selected bytes to str
		if((i+1)%3==0){                     //  delete whole space.
			continue;
		}
		selectedbyte(str, isim[i]);

	}
	
printf("\n-selected byte:%s\n",str);                //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

char little[1024];
little[0]='\0';


if(selectedEndian==1){                                      // for little endian

int order=userbyte*2-1;

selectedbyte(little, str[order-1]);
int i;	
int a=0;
for(i=1; i<userbyte1 ;i++){
	
selectedbyte(little, str[order+a]);	
	
if(i%2==0)
a++;

if(i%2==1){
a--;
a--;
a--;
}	
		
}	
strcpy(str, little);                    // Burda , little ending için , little in içeriðini str ye atadýk, böylece little ending oldu.
	printf("little ending :%s\n",str);             //ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss	
}


if(selectedType==0){                         //unsigned integer 

int power=0;
unsigned long int x=0;
int uns;
for(uns=userbyte1-1 ;-1<uns ; uns--){                                  
	
	
	x=x+(getNum(str[uns]))*pow(16,power);
	power++;
	 
}

 printf("unsigned value is: %d\n",x);
 fprintf (fp, "%d    ",x);
}



if(selectedType==1){                               //signed integer 
	
char binarySigned[1024];
binarySigned[0]='\0';		
HexConvertBin(str,binarySigned); 	
printf("binary :%s\n",binarySigned);                           // sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
double signedNumber=0;
int i;
int a=0;
for(i=(selectedByte*8)-1; -1<i ;i--){
	
	if(i==0){
	signedNumber=signedNumber-(binarySigned[i]-'0')*pow(2,a);
	continue;	
	}
		
signedNumber=signedNumber+(binarySigned[i]-'0')*pow(2,a);	
a++;	
}
printf("signedNumber :%f\n",signedNumber);  
fprintf (fp, "%f    ",signedNumber);	
}






char binary[1024];	                        // this store binary
binary[0]='\0';
if(selectedType==2){                         //if the user select floating point
	
	
	
	
	
			if(userbyte==1){                                              // floating point ( 1 BYTE )
		
	HexConvertBin(str,binary); 	
printf("Binary :%s\n",binary);
double bias=pow(2,4-1)-1;
printf("Bias:%.f\n",bias);
int sign=binary[0]-'0';

printf("sign:%d\n",sign);
int exponent=0;
int a=0;  // base of two
for(int i=4; 0<i ;i--){          // Exponent calculation

exponent=exponent+(binary[i]-'0')*pow(2,a);

a++;
   
	}
	
printf("Exponent:%d\n",exponent);


double fraction=0;                             // fraction calculation
int b=-1;
for(int i=5; 8>i ;i++){
	
	fraction=fraction+(binary[i]-'0')*pow(2,b);
b--;
	
}
printf("fraction:%f\n",fraction);
double mantissa;
double decimal;	
	if(exponent==0){
	mantissa=0+fraction; 
	exponent=1;	
	}
	else{
	mantissa=1+fraction;
	decimal=pow(-1,sign)*mantissa*pow(2,exponent-bias);
		
	}
	
	
	printf("mantissa:%f decimal :%f\n",mantissa,decimal);	
fprintf (fp, "%f    ",decimal);		
}                         // 111111111111111111111111111111111111111111 end
	

		if(userbyte==2){                                              // floating point ( 2 BYTE )
		

HexConvertBin(str,binary); 	
printf("binary :%s",binary);
double bias=pow(2,6-1)-1;
printf("\n bias:%.f",bias);
int sign=binary[0]-'0';

printf("\n sign:%d",sign);
int exponent=0;
int a=0;  // base of two
for(int i=6; 0<i ;i--){          // Exponent calculation

exponent=exponent+(binary[i]-'0')*pow(2,a);

a++;
   
	}
	
printf("\n exponent:%d",exponent);


double fraction=0;                             // fraction calculation
int b=-1;
for(int i=7; 20>i ;i++){
	
	fraction=fraction+(binary[i]-'0')*pow(2,b);
b--;
	
}
printf("\n fraction:%f",fraction);
double mantissa;
double decimal;	
	if(exponent==0){
	mantissa=0+fraction; 
	exponent=1;	
	}
	else{
	mantissa=1+fraction;
	decimal=pow(-1,sign)*mantissa*pow(2,exponent-bias);
		
	}
	
	
	printf("\n mantissa:%f decimal :%f",mantissa,decimal);	
fprintf (fp, "%f    ",decimal);		
}                         // 22222222222222222222222222222222222222222222 end
	

	if(userbyte==3){                                              // floating point ( 3 BYTE )
		

HexConvertBin(str,binary); 	
printf("binary :%s",binary);
double bias=pow(2,8-1)-1;
printf("\n bias:%.f",bias);
int sign=binary[0]-'0';

printf("\n sign:%d",sign);
int exponent=0;
int a=0;  // base of two
for(int i=8; 0<i ;i--){          // Exponent calculation

exponent=exponent+(binary[i]-'0')*pow(2,a);

a++;
   
	}
	
printf("\n exponent:%d",exponent);


double fraction=0;                             // fraction calculation
int b=-1;
for(int i=9; 22>i ;i++){
	
	fraction=fraction+(binary[i]-'0')*pow(2,b);
b--;
	
}
printf("\n fraction:%f",fraction);
double mantissa;
double decimal;	
	if(exponent==0){
	mantissa=0+fraction; 
	exponent=1;	
	}
	else{
	mantissa=1+fraction;
	decimal=pow(-1,sign)*mantissa*pow(2,exponent-bias);
		
	}
	
	
	printf("\n mantissa:%f decimal :%f",mantissa,decimal);	
fprintf (fp, "%f    ",decimal);		
}                         // 333333333333333333333333333333333333333333 end
	
	if(userbyte==4){                                              // floating point ( 4 BYTE )
		
	
HexConvertBin(str,binary); 	
printf("binary :%s",binary);
double bias=pow(2,10-1)-1;
printf("\n bias:%.f",bias);
int sign=binary[0]-'0';

printf("\n sign:%d",sign);
int exponent=0;
int a=0;  // base of two
for(int i=10; 0<i ;i--){          // Exponent calculation

exponent=exponent+(binary[i]-'0')*pow(2,a);

a++;
   
	}
	
printf("\n exponent:%d",exponent);


double fraction=0;                             // fraction calculation
int b=-1;
for(int i=11; 24>i ;i++){
	
	fraction=fraction+(binary[i]-'0')*pow(2,b);
b--;
	
}
printf("\n fraction:%f",fraction);
double mantissa;
double decimal;	
	if(exponent==0){
	mantissa=0+fraction; 
	exponent=1;	
	}
	else{
	mantissa=1+fraction;
	decimal=pow(-1,sign)*mantissa*pow(2,exponent-bias);
		
	}
	
	
	
	
	
	
	

printf("\n mantissa:%f decimal :%f",mantissa,decimal);		
fprintf (fp, "%f    ",decimal);	

}                                                             // 4444444444444444444444444444444444444444 end


	if(userbyte==6){                                              // floating point ( 6 BYTE )
		
HexConvertBin(str,binary); 	
printf("binary :%s",binary);
double bias=pow(2,12-1)-1;
printf("\n bias:%.f",bias);
int sign=binary[0]-'0';

printf("\n sign:%d",sign);
int exponent=0;
int a=0;  // base of two
for(int i=12; 0<i ;i--){          // Exponent calculation

exponent=exponent+(binary[i]-'0')*pow(2,a);

a++;
   
	}
	
printf("\n exponent:%d",exponent);


double fraction=0;                             // fraction calculation
int b=-1;
for(int i=13; 26>i ;i++){
	
	fraction=fraction+(binary[i]-'0')*pow(2,b);
b--;
	
}
printf("\n fraction:%f",fraction);
double mantissa;
double decimal;	
	if(exponent==0){
	mantissa=0+fraction; 
	exponent=1;	
	}
	else{
	mantissa=1+fraction;
	decimal=pow(-1,sign)*mantissa*pow(2,exponent-bias);
		
	}
	
	
	
	
	
	
	

printf("\n mantissa:%f decimal :%f",mantissa,decimal);		
fprintf (fp, "%f    ",decimal);	

}                                                             // 66666666666666666666666666666666666666 end


}


x=x+byte;
}
fclose (fp);
return 0;
}
// https://www.rapidtables.com    :          https://www.geeksforgeeks.org       :          https://codeforwin.org     


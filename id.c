'#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*typedef enum{
    A=127, B=192, C=224, D=240, E=255; 
}Class;
*/
void DATA_OUTPUT();
void registration(int *number, int *number2, int *number3, int *number4);


int main(){
    DATA_OUTPUT();
}


void DATA_OUTPUT(){
    char *data=NULL;
    data=getenv("QUERY_STRING");
    int i=0,
	number1=0,
	number2=0,
	number3=0,
        number4=0;

    while(data[i]!='\0'){
        i++;
    }
    if(i>15){ 
        printf("content-type: text/html\n\n");
        printf("    <!DOCTYPE HTML>");
        printf("    <HTML>");
        printf("    <LINK rel=\"stylesheet\" href=\"fond.css\"/>");
        printf("    <LINK rel=\"stylesheet\" href=\"Style.css\"/>");
        printf("        <FORM ACTION=\"id.cgi\" METHOD=\"get\">");
        printf("        Invalid IP. Please try again,</BR>");
        printf("        <LABEL FOR=\"Data\">IP:</LABEL>");
        printf("        <INPUT TYPE=\"text\" NAME=\"Data\" PLACEHOLDER=\"E.g: xxx.xxx.xxx.xxx\" required></P>");        
        printf("        <INPUT TYPE=\"SUBMIT\" VALUE=\"Send\">");        
        printf("        </FORM></BR>");    
        printf("        </BODY>");
        printf("    </HTML>");    
    }else{
        sscanf(data, "Data=%d.%d.%d.%d", &number1, &number2, &number3, &number4);
        registration(&number1, &number2, &number3, &number4);
    }
}

void registration(int *number1, int *number2, int *number3, int *number4){
    int Not_IP=256;

    printf ("content-type: text/html\n\n"); 
    printf("<!DOCTYPE HTML>\n");
    printf("<HTML>");
    printf("    <LINK rel=\"stylesheet\" href=\"fond.css\"/>");
    printf("    <LINK rel=\"stylesheet\" href=\"Style.css\"/>");
    printf("    <BODY>");
    printf("        %d.%d.%d.%d</BR>", *number1, *number2, *number3, *number4);
    printf("    </BODY>");
    printf("</HTML>");

    if (*number1 >= Not_IP||*number1 < 0||*number2 >= Not_IP||*number2 < 0||*number3 >= Not_IP||*number3 < 0||*number4 >= Not_IP||*number4 < 0){ 
        printf("<!DOCTYPE HTML>\n");
        printf("<HTML>");
        printf("    <LINK rel=\"stylesheet\" href=\"fond.css\"/>");
        printf("    <LINK rel=\"stylesheet\" href=\"Style.css\"/>");
        printf("    <BODY>");
        printf("        <B>invalid IP adress</B></BR>");
        printf("    </BODY>");
        printf("</HTML>");
    }
    else{
        printf("<!DOCTYPE HTML>\n");
        printf("<HTML>");
        printf("    <LINK rel=\"stylesheet\" href=\"fond.css\"/>");
        printf("    <LINK rel=\"stylesheet\" href=\"Style.css\"/>");
        printf("    <BODY>");
        printf("        <B>valid IP adress</B></BR>");

        if (*number1>=0 && *number1<=127){
            printf("        ID: A Class</BR>");
        }
        else if(*number1>127 && *number1<=191){
            printf("        ID: B Class</BR>");
        }
        else if(*number1>191 && *number1<=223){
            printf("        ID: C Class</BR>");
        }
        else if(*number1>223 && *number1<=239){
            printf("        ID: D Class</BR>");
        }
        else if(*number1>239 && *number1<=255){
            printf("        ID: E Class</BR>");
        }
        printf("    </BODY>");
        printf("</HTML>");
    }
}

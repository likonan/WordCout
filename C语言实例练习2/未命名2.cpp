#include <stdio.h>
#include <stdlib.h>
int main()
{  
	char sex;				//性别
	char sports;			//爱好运动
	char diet;				//饮食习惯良好
	float myHeight;			//我的身高
	float faHeight;			//父亲身高
	float moHeight;			//母亲身高
	/*********Begin*********/
    printf("Are you a boy(M) or a girl(F)?");
        scanf(" %c",&sex);
    switch(sex)
    {
        case 'm':  case 'M':  case 'f':  case 'F': 
            printf("\nPlease input your father's height(cm):");
        scanf("%f",&faHeight);
            printf("\nPlease input your mother's height(cm):");
        scanf("%f",&moHeight);
            if(sex=='m'||sex=='M')
        myHeight=(faHeight + moHeight) * 0.54;
            else if(sex=='f'||sex=='F')
        myHeight=(faHeight * 0.923 + moHeight) / 2;
            switch(sports)
            {
                case 'y':  case 'Y': 
                case 'n':  case 'N':
                if(sports=='y'||sports=='Y') 
                    {myHeight=myHeight*1.02;
                    switch(diet)
                    {
                    case 'y':  case 'Y':  case 'n':  case 'N':
                     	if(diet=='y'||diet=='Y')
                        myHeight=myHeight*1.015;
                    printf("\nYour future height will be %f(cm)",myHeight);
                    break;
                    default:
                    printf("\nInput diet error!");
                    break;
	                        }   
                        }
                break;
                	default:
                	printf("\nInput sports error!");
                 	break;
                    }
			    break;
        			default:
        			printf("\nInput sex error!");
       				break;
            }
return 0;
    }
 
	/*********End**********/ 
     


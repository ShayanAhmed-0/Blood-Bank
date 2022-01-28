/*
reciptant or donor
ask blood type
reciptant -> ?type of blood
returns chart of blood
donor->number of bags
stroe blood type,age,gender in blood.txt
*/
#include<stdio.h>
struct shayan{
	char blood[6][3]={"A+","A-","B+","B-","O+","O-"};
	int nobg[6]={60,50,40,30,20,10};
};
void donor(){
	int i,da[34];
	FILE *files=NULL;
	files=fopen("blood.txt","w");
	char name[34][34],dbt[34][34],dg[34][34];
	int donatebag,nod;
	printf("ThankYou for Donating in Our Bank\n");
	printf("how many donors?: ");
	scanf("%d",&nod);
	for(i=0;i<nod;i++){
    printf("Name of %d donor: ",i+1);
    scanf("%s",&name[i]);
    fprintf(files,"%s\n",name[i]);
    
	printf("Blood type of %d donor: ",i+1);
    scanf("%s",&dbt[i]);
	fprintf(files,"%s\n",dbt[i]);
	
	printf("Age of %d donor: ",i+1);
    scanf("%d",&da[i]);
	fprintf(files,"%d\n",da[i]);
	
	printf("Gender of %d donor: ",i+1);
    scanf("%s",&dg[i]);
	fprintf(files,"%s\n",dg[i]);
	}
	fclose(files);
	printf("\nStored info is\n");
	files=fopen("blood.txt","r");
	for(i=0;i<nod;i++){
	
	fscanf(files,"%s",&name[i]);
	printf("\nName is:%s",name[i]);
	
	fscanf(files,"%s",&dbt[i]);
	printf("\nBlood Type is: %s",name[i]);
	
	fscanf(files,"%d",&da[i]);
	printf("\nDonor Age is: %d",da[i]);
	
	fscanf(files,"%s",&dg[i]);
	printf("\nDonor gender is: %s",dg[i]);
	}
}
void chart(){
	shayan x;
	printf("type of Blood \t\t number of bags\n");
	printf("%s \t\t\t  %d\n%s \t\t\t  %d\n%s \t\t\t  %d\n%s \t\t\t  %d\n%s \t\t\t  %d\n%s \t\t\t  %d",x.blood[0],x.nobg[0],x.blood[1],x.nobg[1],x.blood[2],x.nobg[2],x.blood[3],x.nobg[3],x.blood[4],x.nobg[4],x.blood[5],x.nobg[5],x.blood[6],x.nobg[6]);
}
void reciptant(){
	shayan x;
	int nb,select;
	printf("\nWhat is The Blood Type You Want?\n1.A+\n2.A-\n3.B+\n4.B-\n5.O+\n6.O-\nSelect");
	scanf("%d",&select);
	chart();
	printf("\n\nnumber of bags you want?: ");
	scanf("%d",&nb);
	if(nb>x.nobg[select])
	printf("Sorry We dont have that Much");
	printf("%d number of %s will be delivered to you shortly",nb,x.blood[select-1]);
}
main(){
	int s;
	char bloodtype[5];
	printf("Welcome to blood Bank\n");
	printf("\n1.Reciptant\n2.Donor\n3.Exit\nSelect: ");
	scanf("%d",&s);
	printf("what is blood type: ");
	scanf("%s",&bloodtype);
	switch(s){
		case 1:
			reciptant();
			break;
		case 2:
		    donor();
			break;
		case 3:
		    return 0;
			break;
		default:
		    printf("Try again");		
	}
}

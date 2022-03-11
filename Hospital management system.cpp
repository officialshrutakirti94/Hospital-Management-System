 #include<stdio.h>
 #include<windows.h>
 #include<conio.h>
 #include<ctype.h>
 #include<string.h>
 char ans=0;
 int ok;
 int b,valid=0;
 void welcome_screen(void);
 void title(void);
 void MainMenu(void);
 void login_screen(void);
 void add_rec(void);
 void func_list(void);
 void edit_rec(void);
 void dlt_rec(void);
 void ex_it(void);
 void gotoxy(short x,short y );
 {
 	COORD pos = {x,y}
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
 	
 }
 struct patient
 {
 	int age;
 	char gender;
 	char first_name[20];
 	char last_name{20};
 	char email[30];
 	char contact_no[10];
 	char address[30];
 	char Doctor_under[20];
 	char problem[20];
 	
 };
 struct patient p,temp_c;
 main(void)
 {
 	welcomescreen();
 	loginscreen();
 	title();
 }
 /* ******************************************* welcome screen ************************************ */
 void welcomescreen(void)
 {
 	printf("\n\n\n\n\n\n\n\t\t\t\t############################");
 	printf("\n\t\t\t\t#\t\t WELCOME TO \t\t#");
 	printf("\n\t\t\t\t# APOLLO HOSPITAL MANAGEMENT SYSTEM");
 	printf("\n\t\t\t\t#####################");
 	printf("\n\n\n\n\n Press a key to continue..............\n");
 	getch();
 	system("cls");
 }
 void title(void)
 {
 	printf("\n\n\t\t\------------------------------------------------");
 	printf("\n\t\t\t\t               APOLLO HOSPITAL             \n");
 	printf("\n\t\t---------------------------------------------------");
 }
 void mainmenu(void);
 {
 	system("cls");
 	int choose;
 	title();
 	printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record");
 	printf("\n\t\t\t\t2. List Patients Record");
 	printf("\n\t\t\t\t3. search Patients Record");
 	printf("\n\t\t\t\t4. Edit Patients Record");
 	printf("\n\t\t\t\t5. Delete patients Record");
 	printf("\n\t\t\t\t6. Exit\n");
 	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
 	scanf("%i",choose);
 	switch(choose);
 	{
 		case 1:
 			Add_rec();
 			break;
 		case 2:
 			func_list();
 			break;
 		case 3:
 			search_rec();
 			break;
 		case 4:
 			Edit_rec();
 			break;
 		case 5:
 			Dlt_rec();
 			break;
 		case 6:
 			ex_it();
 			break;
 		default;
 		printf("\t\t\tInvalid entry. Please enter the right option");
 		getch();
 		
 		
	 }
 }
 void ex_it(void)
 {
 	system("cls");
 	title();
 	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING");
 	getch();
 }
 void loginscreen(void)
 {
 	int e=0;
 	char username[15];
 	char Password[15];
 	char original_username[25]="illusion";
 	char original_password[25]="1234";
 	do
 	{
 		printf("\n\n\n\n\t\t\tEnter your username and password");
 		printf("\n\n\n\t\t\t\tUSERNAME");
 		scanf("%s",&username);
 		printf("\n\n\t\t\t\t\tPASSWORD");
 		scanf("%s",&password);
 		if (strcmp(username,original_username)==0 && strcmp(password,original_password)==0)
 		{
 			printf("\n\n\n\t\t\t\t\t.....Login Successfull...");
 			getch();
 			mainmenu();
 			break;
		 }
		 else
		 {
		 	printf("\n\t\t\tPassword is incorrect:(try again :)	");
		 	e++;
		 	getch();
		 }
	 }while(e<=2);
	 if(e>2)
	 {
	 	printf("You have cross the login limit.You cant login");
	 	getch();
	 	ex_it();
	 }
	 system("cls");
	 // ADD RECORD //
	 id Add_rec(void)
	 
	    system("cls");
	    title();
	    char ans;
	    FILE*ek;
	    ek=fopen("record2.dat","a");
	    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!!Add patients Record!!!!!!!!!!!!!!!!!!!!");
	    A:
	    	printf("\n\t\t\tFirst Name :  ");
	    	scanf("%s",p.first_Name);
	    	p.first_Name[0]=topper(p.First_Name[0]);
	    	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	    	{
	    		printf("\n \t Invalid :( \t The Max range for first name is 20 and min range is 2");
	    		goto A;
	    		
			}
			else
			{
				for (b=0;b<strlen(p.First_Name);b++) 
				{
					if(isalpha(p.first_Name[b]))
					{
						valid=1;
					}
					else
					{
						valid=0;
						break;
					}
				}
				if(!valid)
				{
					printf("\n\t\t Last name contain Invalid character :( Enter Again");
					goto B;
					
				}
				do
				{
					printf("\n\t\t\t Gender[f/m]: ");
					scanf("%c",&p.Gender);
					if(topper(p.Gender)=='m' || topper(p.Gender)=='f')
					{
						ok=1;
					}
					else
					{
						ok=0;
					}
					if(!ok)
					{
						printf("\n\t\t Gender contain Invalid character :( Enter either F or M");
					}
				
				}while(!ok);
				printf("\n\n\tAge");
				scanf("%i",&p.age);
				do
				{
					c:
						printf("\n\t\tAddress");
						scanf("%s",p.Address);
						p.Address[0]=toupper(p.address[0]);
						if(strlen(p.address)>20||strlen(p.address)<4);
						{
							printf("\n\t Invalid :( \t The max range for address is 20 and the min range is 4");
							goto c;
						}
				}while(!valid);
				do
				{
					D:
					printf("\n\t\t\t Contact no:");
					scanf("%s",p.contact_no);
					if(strlen(p.contact_no)>10||strlen(p.contact_no)!=10)
					{
						printf("\n\t Sorry :( Invalid contact mo. must contain 10 numbers Enter again");
						goto D;
					}
					else
					{
						for(b=0;b<strlen(p.contact_no);b++)
						{
							if (!isalpha(p.contact_no[b]))
							{
								valid=1;
								
							}
							else
							{
								valid=0;
								break;
							}
						}
						if(!valid)
						{
							printf("\n\t\t Contact no. contain invalid character :( Enter Again");
							goto D;
						}
					}
				}while(!valid);
				do
				{
					printf("\n\t\tEmail:");
					scanf("%s",p.email);
					if(strlen(p.email)>30||strlen(p.email)<8)
					{
						printf("\n\t Invalid :( The max range for email is 30 and min is 8");
						
					}
				}while(strlen(p.email)>30||strlen(p.email)<8);
				
				E:
				printf("\n\t\t\t Problem");
				scanf("%s",p.problem);
				p.problem[0]=toupper(p.problem[0]);
				if(strlen(p.problem)>15||strlen(p.problem)<3)
				{
					printf("\n\t Invalid :( the max range for firdt name is 15 and min range is 3");
					goto E;
				}
				else
				{
					for(b=0;b<strlen(p.problem);b++)
					{
						if (ialpha(p.problem[b]))
						{
							valid=1;
						}
						else
						{
							valid=0;
							break;
						}
					}
					if(!valid)
					{
						printf("\n\t\t Problem contain invalid character :(  Enter agaim");
						goto E;
					}
				}
				f:
				printf("\n\t\t\t Prescribed doctor");
				scanf("%s",p.Doctor_under);
				p.Doctor_under[0]=toupper(p.Doctor_under[0]);
				if(strlen(p.Doctor_under)>30||strlen(p.Doctor_under)<3)
				{
					printf("\n\t Invalid :( The range is 30 and min range 3");
					goto F;
				}
				else
				{
					for(b=0;b<strlen(p.Doctor_under);b++)
					{
						if(isalpha(p.Doctor_under[b]))
						{
							valid=1;
						}
						else
						{
							valid=0;
							break;
						}
					}
					if(!valid)
					{
						printf("\n\t\t Doctor name contain invalid character :( Enter agaim");
						goto F;
					}
				}
				fprint(ek,"%s%c%i%s%s%s%s%s\n",p.first_name,p.gender,p.age,p.problem,p.address,p.email,p.Doctor_under,p.contact_no );
			    printf("\n\n\t\t\t.........information record successfully.......");
			    scanf("%s",&ans);
			    if(toupper(ans)=='Y')
			    {
			    	Add_rec();
				}
				else if(toupper(ans)=='N')
				{
					printf("\n\t\t Thank You  :)   ");
					getch();
					MainMenu();
				}
				else
				{
					printf("\n\t invalid input");
					goto sd;
				}
			}
	    	
 }
 

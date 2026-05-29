#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STUDENTS 5

const int studentMax = 5;

struct sinfo {
	char fname[50];
	char lname[50];
	int roll;
	float cgpa;
	int cid[5];
};

//char targetRoll[5];
	struct sinfo students[STUDENTS];
	int studentCount = 0;
	
	
int main() {
	
	int choice = 0;
	while (choice != 8) {
		
		printf("\n Student Information Management System \n");
		printf("1. Student Details \n");
		printf("2. Bulk Import Student Files\n");
		printf("3. Export all files \n");
		printf("4. Search for Roll number\n");
		printf("5. Search by first name\n");
		printf("6. Update by roll number\n");
		printf("7. Delete\n");
		printf("8. Exit\n");
		printf("Enter choice: "); 
		
	//int choice;
	if (scanf(" %d", &choice) != 1) {
		choice = 0;
	}
	while (getchar() != '\n'); 
	//printf("I'm coming....\n");
	

switch (choice) {
	
	case 1: {
	printf("Add details\n");
	//scanf("%d", choice);
	
	
	if (studentCount >= STUDENTS) {
		printf("Storage full\n");
		break;
	}
	int targetRoll;
	printf("Enter Roll number: ");
	scanf("%d", &targetRoll);
	
	
	int found = 0;
	for (int i = 0; i < studentCount; i++) {

//while (i < studentCount) {
	//if (strcmp(students[i].fname, targetRoll) == 0) { 
	// }
	
	
	if (students[i].roll == targetRoll) {
		found = 1;
		break;
		}

	}
	if (found == 1) {
		printf("Roll number already exists.");
		break;
	}
	
		students[studentCount].roll = targetRoll;
		
		printf("Enter First Name: ");
		scanf("%s", students[studentCount].fname);
		
		
		printf("Enter Last Name: ");
		scanf("%s", students[studentCount].lname);
		
		
		//printf("Reg. number: ");
		//scanf("%d", &students[studentCount].roll);
		
		
		printf("Enter CGPA: ");
		scanf("%f", &students[studentCount].cgpa);
		
		
		printf("Five course IDs: \n");
		
		for (int i = 0; i < 5; i++) {
		//	printf("Course 1: Course 2: Course 3: Course 4: Course 5: \n");
		    //printf("Course %d: ", i + 1);
			scanf("%d", &students[studentCount].cid[i]);
			//printf("Course 1: %d Course 2: %d Course 3: %d Course 4: %d Course 5: \n");
		}
		while (getchar() != '\n');
			studentCount++;
			printf("Added successful\n");
			break;
		//	return 0;
	
	break;
	}


	
	case 2: {
		printf("Bulk Import Students File\n");
		FILE* file = fopen("students.txt", "r");
		if (file == NULL) {
			printf("File not found\n");
			break;
		}
		
		int importCount = 0;
		struct sinfo students[studentCount];
		while (fscanf(file, "%49s %49s %d %f %d %d %d %d %d",
		students[studentCount].fname,
		students[studentCount].lname,
		&students[studentCount].roll,
		&students[studentCount].cgpa,
		
		&students[studentCount].cid[0],
		&students[studentCount].cid[1],
		&students[studentCount].cid[2],
		&students[studentCount].cid[3],
		&students[studentCount].cid[4]) == 9) 
		
	{
		if (studentCount >= STUDENTS) {
				printf("Maximum Storage Reached.\n");
				break;
				}
		
			studentCount++;
			importCount++;
	}
			
			fclose(file); 
			printf("Imported. \nTotal Students: %d\n", studentCount);
		
			
	break;
	}
	
	case 3: {
		printf("Export All File\n");
		
		if (studentCount == 0) {
			printf("No student record found\n");
			break;
		}
		FILE *file = fopen("students.txt", "w");
		//int found = 0;
		
		if (file == NULL) {
			printf("Error\n");
			break;
		}
		
		for (int i = 0; i < studentCount; i++) {
			fprintf(file, "%s %s %d %.1f %d %d %d %d %d\n",
			students[i].fname,
			students[i].lname,
			students[i].roll,
			students[i].cgpa,
			students[i].cid[0],
			students[i].cid[1], students[i].cid[2], students[i].cid[3], students[i].cid[4]);
		}
		fclose(file);
		printf("Export Successful.\n");
		
		break;
	}
	
	case 4: {
		printf("Search for roll number\n");
		int searchRoll;
		printf("Enter Roll number: ");
		scanf("%d", &searchRoll);
		int found = -1;
		
		for (int i = 0; i < studentCount; i++) {
			//int (searchRoll = i);
			if (students[i].roll == searchRoll) {
				found = i;
		break;
			}
		}
		if (found == -1) {
			printf("Roll Number %d Not Saved.\n", searchRoll);
			//break;
		} 
		else {
			//printf("Search: roll number");
			//scanf("%d", &searchRoll);
			
			printf("\nStudent Details Found\n");
			printf("Roll number: %d\n", students[found].roll);
			printf("Name: %s %s\n", students[found].fname, students[found].lname);
			printf("CGPA: %.2f\n", students[found].cgpa);
			printf("Course IDs: \n");
			
			for (int j = 0; j < 5; j++) {
				printf("%d \n", students[found].cid[j]);
			}
			
		}
		break;
	}

	
	case 5: {
		printf("Search by first name\n");
		char findName[50];
	//	int target roll;
		printf("Type name: ");
		scanf("%s", findName);
		
		int found = 0;
		for (int i = 0; i < studentCount; i++) {
		//	int (findName == i);
			if (students[i].fname == findName) {
				found = 1;
				printf("Found \n Student Details\n");
				printf("Roll number: %d\n", students[i].roll);
				printf("First Name: %s %s\n", students[i].fname, students[i].lname);
				printf("CGPA: %.2f\n", students[i].cgpa);
				printf("Course IDs: \n");
				for (int j = 0; j < 5; j++) {
				printf("%d \n", students[i].cid[j]);
			}
			
		  }
		}
			if (! found) {
				printf("Does not exist.\n");
			}
		
		break;
   	}
	
	case 6: {
		printf("Roll number to update\n");
		//while(0){
			int targetRoll;
			printf("Input roll number: ");
			scanf("%d", &targetRoll);
			
			int updateIndex = -1;
			for (int i = 0; i < studentCount; i++) {
			//	int (updateIndex = i);
				if (students[i].roll == targetRoll) {
					updateIndex = i;
					break;
					}
				}
			if (updateIndex == -1) {
				printf("Not found.\n");
				//break;
			}
			else {
				//students[updateIndex].roll = updateIndex;
				printf("Update roll number: ");
				scanf("%d", &students[updateIndex].roll);
				
				printf("Update CGPA: ");
				scanf("%f", &students[updateIndex].cgpa);
				
				printf("Update Successful \n");
				
				}
				break;
				
				}
	
	case 7: {
		printf("Input roll number to be deleted\n");
		int targetRoll;
		printf("Enter: ");
		scanf("%d", &targetRoll);
		
		int deleteIndex = -1;
		for (int i = 0; i < studentCount; i++) {
			if (students[i].roll == targetRoll) {
				deleteIndex = i;
				break;
			}
		}
		if (deleteIndex == -1) {
			printf("Record Not Found.\n");
		}
		else {
		students[deleteIndex] = 
		students[studentCount - 1];
		studentCount--;
		printf("Delete Successful.\n");
		}
		break;
	}
	
	case 8: {
		printf("Exiting program, Goodbye!\n");
		return 0;
	}
	
	default: {
	printf("Invalid choice. \n choose between 1 to 8\n");
	
	break;
	}
	}
	}
	return 0;
	
	
}
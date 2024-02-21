/*subject details function is working 
CGPA is working
Instruction is working
GPA giving wrong answer*/

#include<iostream>
#include <conio.h>                   
#include<vector>
#include<string>
#include <limits>
using namespace std;
struct subject {
	int num ;
	vector<string> name;
	int exam_weight;
	int assignment_weight;
	int quizz_weight;
	vector<int>credit;
};



//function for subject details and marks
void subjectDetails(struct subject* s) {
	cout << "\033[2J\033[1;1H";
	cout<<"-------------------------------------------------------------------------------------------------\n";
	cout<<"                                          Subject Info                                           \n";
	cout<<"--------------------------------------------------------------------------------------------------\n";
	cout<<"--------------------------------------------------------------------------------------------------\n\n";
	cout<<"\tNumber of Subjects: ";
	cin>>s->num;
	s->name.resize(s->num);
	s->credit.resize(s->num);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for(int i=0;i<s->num;i++) {
		cout<<"\tEnter name of Subject "<<i+1<<": ";
		getline(cin, s->name[i]);
		cout<<"\tEnter credit given to pass student in "<<s->name[i]<<": ";
		cin>>s->credit[i];
	}
	cout<<endl;
	int sum=0;
	do {
		cout << "\033[2J\033[1;1H";
		cout<<"-------------------------------------------------------------------------------------------------\n";
		cout<<"                                         Marks info                                              \n";
		cout<<"-------------------------------------------------------------------------------------------------\n";
		cout<<"-------------------------------------------------------------------------------------------------\n\n";
		if(sum<100 && sum != 0) {
			cout<<"    Total marks of one subject is less than 100. Try again!\n\n";
		}
		else if(sum>100) {
			cout<<"    Total marks of one subject is greater than 100. Try again!\n\n";
		}
		cout<<"\tEnter maximum marks of Exam: ";
	    cin>>s->exam_weight;
    	cout<<"\tEnter maximum marks of assignment: ";
    	cin>>s->assignment_weight;
	    cout<<"\tEnter maximum marks of Quiz: ";
    	cin>>s->quizz_weight;
    	sum=s->exam_weight+s->assignment_weight+s->quizz_weight;
		
	}while(sum!=100);
	
	
}

//function to check range of marks entered 
int range(int num, int low,int high) {
	if(num>=low && num<=high) {
		return num;
	}
	else {
		cout<<"\t\tError! Number is not in the range of "<<low<<"-"<<high<<" Enter again: ";
		cin>>num;
		range(num,low,high);
	}
}
//grade point for entered subjects marks
int gradePoint(int marks ) {
    
    
         if(marks>=90) return 10;
         else if(marks>=80) return 9;
         else if(marks>=70) return 8;
         else if(marks>=60) return 7;
         else if(marks>=50) return 6;
         else if(marks>=40) return 5;
         else return 0;
    
     
 }
 
 bool detailsEntered = false;

void calculateGPA(struct subject* sub) {
	
	if(!detailsEntered) {
        cout << "\n\tPlease enter subject details first.\n" << endl;
        cout<<"\tPress any key to go to main menu\n";
        getch();
        return;
    }
	
	string name;
	int exam_marks[sub->num], assignment_marks[sub->num],quiz_marks[sub->num];
	int marks[sub->num],grades[sub->num];
	int num;
	int n;  //stopping point for function
	do {
		cout << "\033[2J\033[1;1H";
		cout<<"----------------------------------------------------------------------------------------------\n";
	    cout<<"                                          |GPA|                                               \n";
	    cout<<"----------------------------------------------------------------------------------------------\n";
    	cout<<"----------------------------------------------------------------------------------------------\n\n";
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\t\tEnter name of student: ";
		getline(cin,name);
		for(int i=0;i<sub->num;i++) {
			cout<<"\t\t For "<<sub->name[i]<<":\n";
			cout<<"\t\t  Enter marks of exam: ";
			cin>>num;
			exam_marks[i]=range(num,0,sub->exam_weight);      //Input for written exam marks
			cout<<"\t\t  Enter marks of assignment: ";
			cin>>num;
			assignment_marks[i]=range(num,0,sub->assignment_weight);     //Input for assignment marks
			cout<<"\t\t  Enter marks of quiz: ";
			cin>>num;
			quiz_marks[i]= range(num,0,sub->quizz_weight);    
			marks[i]=exam_marks[i]+assignment_marks[i]+quiz_marks[i];  //total marks out of 100
			grades[i]= gradePoint(marks[i]);
			cout<<"\t\t\tGrade point: "<<grades[i]<<endl;
			cout<<"\t\t------------------------------------------------------------------\n";
		}
		
	    float sum=0 , sum_of_credit=0;
	    for(int i=0;i<sub->num;i++) {
	    	sum += grades[i]*sub->credit[i];    //sum of student poins
		    sum_of_credit += sub->credit[i];    //Sum of credit
	    }
	    cout<<"\t\t GPA of "<<name<<" is: "<<sum/sum_of_credit;
	    cout<<endl<<endl;
	    cout<<"\tEnter '1' to calculate other's GPA\n";
	    cout<<"\tEnter '2' to modify subject details\n";
	    cout<<"\tAny other number to exit\n";
	    cout<<"\t Enter: ";
	    cin>>n;
	    if(n==1) continue;
	    else if(n==2) {
	    	subjectDetails(sub);
	    	continue;
		}
	    
	    
    }while(n<3);
	cout<<"\n\nPress any key to go to main menu";	
	
}

void calculateCGPA() {
	cout << "\033[2J\033[1;1H";
	cout<<"-------------------------------------------------------------------------------------------------\n";
	cout<<"                                         | CGPA |                                                \n";
	cout<<"-------------------------------------------------------------------------------------------------\n";
	cout<<"-------------------------------------------------------------------------------------------------\n";
	float sum=0;
	int sem;
	cout<<"\t Enter number of semester: ";
	cin>>sem;
	float gpa[sem];
	for(int i=0;i<sem;i++) {
		cout<<"\t Enter GPA in semester "<<i+1<<": ";
		cin>>gpa[i];
		sum += gpa[i];
	}
	cout<<endl<<endl;
	cout<<"\t\tCGPA: "<<sum/sem<<endl<<endl<<endl;
	cout<<"\t Press any key to exit\n";
	getch();
}

void instruction() {
	cout << "\033[2J\033[1;1H";
		
	cout<<"-------------------------------------------------------------------------------------------------\n";
	cout<<"                                        Instruction                                              \n";
	cout<<"-------------------------------------------------------------------------------------------------\n";
	cout<<"-------------------------------------------------------------------------------------------------\n";
	cout<<endl<<endl;
	
	cout<<"\tGPA = (Sum of (points*credit))/Sum of credits";
	cout<<endl<<endl;
	cout<<"\tCGPA = Sum of GPA / Number of semester";
	cout<<endl<<endl;
	
	cout<<"\tScaling factor: 10\n";
	cout<<"\t-------------------------------------------------\n";
	cout<<"\t               Grade distribution                \n";
	cout<<"\t-------------------------------------------------\n";
	
	cout<<endl;
	cout<<"\t---------------------------------------\n";
	cout<<"\t\tGrade\t\tScale of 10\n";
	cout<<"\t---------------------------------------\n";
	cout<<"\t\t  O \t\t 9-10\n";
	cout<<"\t\t  A \t\t 8-9\n";
	cout<<"\t\t  B \t\t 7-8\n";
	cout<<"\t\t  C \t\t 6-7\n";
	cout<<"\t\t  D \t\t 5-6\n";
	cout<<"\t\t  E \t\t 4-5\n";
	cout<<"\t\t  F \t\t 0-4\n";
	cout<<endl<<endl;
	cout<<"\tPress any key to return to main menu.\n";
	getch();
}
int main() {
	struct subject sub;
	int n;
	
	do{
		cout << "\033[2J\033[1;1H";
		
		cout<<"--------------------------------------------------------------------------------------------\n";
    	cout<<"                              |GPA & CGPA Calculator|                                       \n";
    	cout<<"--------------------------------------------------------------------------------------------\n";
		cout<<"--------------------------------------------------------------------------------------------\n\n";
		cout<<"\t1) Enter subject details & marks\n";
		cout<<"\t2) Calculate CGPA\n";
		cout<<"\t3) Calculate GPA\n";
		cout<<"\t4) Formula used in this calcultor\n";
		cout<<"\t5) Quit\n\n\n";
		cout<<"\t   Select a option: ";
		cin>>n;
		if(n==1) {
			detailsEntered = true;
			subjectDetails(&sub);
		}
		else if(n==2) calculateCGPA();
		else if(n==3) calculateGPA(&sub);
		else if(n==4) instruction();
		else if(n==5) exit(0);
		else cout<<"Wrong choice Try again!\n";
		
    }while(n != 5);
	return 0;
	getch();
}


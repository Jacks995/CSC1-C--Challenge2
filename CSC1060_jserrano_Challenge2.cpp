//Jaqueline Serrano
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	while (true) {
		//display a menu with the different levelled courses and ask the user for their course level
		int level, credits, years;
		cout << endl << "CCA Tuition Program" << endl;
		cout << "-------------------" << endl;
		cout << endl << "1. 000 Level Courses" << endl;
		cout << "2. 100 Level Courses" << endl;
		cout << "3. 200 Level Courses" << endl;
		cout << "4. Exit Program" << endl;
		cout << "Select the course level or Exit: ";
		cin >> level;

		//this stops program if the user chooses to exit (4)
		if (level == 4) {
			return 0;
		}
		else if (level >= 1 && level <= 3) {
			cout << "Enter the number of credit hours for this semester: ";
			cin >> credits;
			cout << "Enter the number of years to display (excluding year 1): ";
			cin >> years;

			const double PERCENT = 1.032;
			double tuition0, tuition1, tuition2, newTuition, finalTuition;

			//acess and open the files
			ifstream tuitionAmount;
			ofstream tuitionReport;

			tuitionAmount.open("C:\\Users\\jacki\\Downloads\\tuitionAmounts.txt");
			tuitionReport.open("C:\\Users\\jacki\\Downloads\\tuitionReports.txt");

			//use a switch statement to evaluate the tuition levels based on what the user chooses
			switch (level) {
			case 1:
				//grab corresponding tuition amounts
				tuitionAmount.ignore(19, '$');
				tuitionAmount >> tuition0;

				//display chart for the results
				tuitionReport << "Community College of Aurora Tuition Report" << endl;
				tuitionReport << "------------------------------------------" << endl;
				tuitionReport << "Year" << setw(14) << "Tuition" << endl;
				tuitionReport << "-----" << setw(13) << "--------" << endl;

				//math for first year
				newTuition = (tuition0 * credits) * 2;
				tuitionReport << fixed << setprecision(2) << "Year 1" << setw(5) << "$" << newTuition << endl;

				//loop through the years provided by user
				for (int i = 2; i <= (years + 1); i++) {
					//calculate tuition cost for each year after the first year
					//algebra: 
					finalTuition = newTuition * PERCENT;
					tuitionReport << fixed << setprecision(2) << "Year " << i << setw(5) << "$" << finalTuition << endl;
					newTuition = finalTuition;
				}
				break;
			case 2:
				//grab corresponding tuition amounts
				tuitionAmount.ignore(44, '\n').ignore(44, '$');
				tuitionAmount >> tuition1;

				//display chart for the results
				tuitionReport << endl << "Community College of Aurora Tuition Report" << endl;
				tuitionReport << "------------------------------------------" << endl;
				tuitionReport << "Year" << setw(14) << "Tuition" << endl;
				tuitionReport << "-----" << setw(13) << "--------" << endl;

				//math for first year
				newTuition = (tuition1 * credits) * 2;
				tuitionReport << fixed << setprecision(2) << "Year 1" << setw(5) << "$" << newTuition << endl;


				//loop through the years provided by user
				for (int i = 2; i <= (years + 1); i++) {
					//calculate tuition cost for each year after the first year
					//algebra: 
					finalTuition = newTuition * PERCENT;
					tuitionReport << fixed << setprecision(2) << "Year " << i << setw(5) << "$" << finalTuition << endl;
					newTuition = finalTuition;
				}
				break;
			case 3:
				//grab corresponding tuition amounts
				tuitionAmount.ignore(69, '\n').ignore(69, '\n').ignore(69, '$');
				tuitionAmount >> tuition2;

				//display chart for the results
				tuitionReport << endl << "Community College of Aurora Tuition Report" << endl;
				tuitionReport << "------------------------------------------" << endl;
				tuitionReport << "Year" << setw(14) << "Tuition" << endl;
				tuitionReport << "-----" << setw(13) << "--------" << endl;

				//math for first year
				newTuition = (tuition2 * credits) * 2;
				tuitionReport << fixed << setprecision(2) << "Year 1" << setw(5) << "$" << newTuition << endl;

				//loop through the years provided by user
				for (int i = 2; i <= (years + 1); i++) {
					//calculate tuition cost for each year after the first year
					//algebra: 
					finalTuition = newTuition * PERCENT;
					tuitionReport << fixed << setprecision(2) << "Year " << i << setw(5) << "$" << finalTuition << endl;
					newTuition = finalTuition;
				}
				break;
			}
			tuitionAmount.close();

		}
		else {
			cout << endl << "Invalid choice, choose again." << endl;
		}
	}
	return 0;
}
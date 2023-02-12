/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: t813g195
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SalesReport(float* SalesData, char** Months)   // Sales report taking in sales numbers and the months
{
	printf("\nMonthly Sales Report for 2022:\n"); // print statements
	printf("------------------------------\n------------------------------\n------------------------------\n\n");
	printf("MONTH\tSALES\n\n");

	for(int i = 0; i < 12; i++) // iterating through sales data
    {   
		printf("%s\t", Months[i]);
		printf("$%.2f\n", SalesData[i]);    // printing the sales data to the user 
	}
}   // end of function

void MinMaxAvg(float* SalesData, char** Months) // sales summary taking in sales numbers and the months
{
    float sum = 0, min = SalesData[0], max = SalesData[0];  // initial values for total sum, min, max
    int min_month, max_month;
    for (int i = 0; i < 12; i++)    // iterating through sales data
    {
        sum = sum + SalesData[i];   // calculating total sum
        
        if (SalesData[i] < min) // checking for min value
        {
            min = SalesData[i]; // storing the min value
            min_month = i;
        }

        if (SalesData[i] > max) // checking for min value
        {
            max = SalesData[i]; // storing the max value
            max_month = i;
        }
    }
    float avg = sum / 12;   // calculating the average
    printf("\nSales Summary:\n\n"); // printing the sales data to the user
    printf("Minimum sales:\t$%.2f\t(%s)\n", min, Months[min_month]);
	printf("Maximum sales:\t$%.2f\t(%s)\n", max, Months[max_month]);
	printf("Average sales:\t$%.2f\n" , avg);
}   // end of function

void MovingAvg(float* SalesData, char** Months) // six month moving average taking in sales numbers and the months
{
    printf("\nSix-Month Moving Average Report:\n\n");   // print statement
    for (int i = 0; i < 7; i++) // iterating through each set of 6 months
    {
        float MvgAvg = (SalesData[i] + SalesData[i + 1] + SalesData[i + 2] + SalesData[i + 3] + SalesData[i + 4] + SalesData[i + 5]) / 6;   // calculating average
        printf("%s\t - \t%s\t", Months[i], Months[i + 5]);  // printing the sales data to the user
		printf("$%.2f\n", MvgAvg);

    }

}   // end of function

void HiLo(float* SalesData, char** Months)// sales report from highest to lowest taking in sales numbers and the months
{
    printf("\nSales Report (Highest to Lowest):\n\n");    // print statements
    printf("MONTH\tSALES\n\n");
    for(int i = 0; i < 12; i++) // iterating through the sales data
    {
		for(int j = i + 1; j < 12; j++) // iterating through the sales data 
        {
			if(SalesData[j] > SalesData[i]) // selection sort
            {
				float temp = SalesData[i];  // sorting values
				char* temp_month = Months[i];
				SalesData[i] = SalesData[j];
				Months[i] = Months[j];
				SalesData[j] = temp;
				Months[j] = temp_month; // sorting values
			}
		}
	}
    for(int i = 0; i < 12; i++) // iterating through sorted array
    {
		printf("%s\t$%.2f\n", Months[i], SalesData[i]); // printing the sales data to the user
	}
}   // end of function


int main()
{

    /* This block of code is for receiving the name
    of the input file from the user, opening the file,
    and reading the file to create an array of sales
    data to be used to then generate reports*/
    char u_file[100];
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 
    printf("Enter the name of the input file: ");
    scanf("%s", u_file);  // getting the file from the user
    FILE *fptr = fopen(u_file, "r");    // opening the file to read data
    if (fptr == NULL) {exit(EXIT_FAILURE);} // checking if file is empty
    float float_array[12], file_line;
    int i = 0;
    while( fscanf(fptr, "%f", &file_line) != EOF )  // iterating through the file
    {
        float_array[i++] = file_line;  // storing the data from the file in an array
    }
    float *salesdata = float_array; // making a pointer
    fclose(fptr);   // closing the file   
    /* end of block of code*/


    /* This block of code is used to generate the tabular sale report*/
    SalesReport(salesdata, months); // Sales Report
    MinMaxAvg(salesdata, months);// minimum, maximum, and average of the monthly sales.
    MovingAvg(salesdata, months);// six-month moving averages
    HiLo(salesdata, months); // monthly sales report from highest to lowest.
    /* end of block of code*/



    






    return 0;   // end of program
}


/*
for( int i = 0; i < 12; i++ )
    {
        printf("%0.2f\n", float_array[i]);
    }
*/
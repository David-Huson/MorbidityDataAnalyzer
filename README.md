# Morbidity Data Analysis
[![Points badge](../../blob/badges/.github/badges/points.svg)](../../actions)

## Project Outcomes:
Develop a C++ program that uses:
- File input
- Makefiles and modular design
- Dynamic array allocation/management
- Basic statistical calculations

## Preparatory Readings:
- ZyBook chapters 1-9
- Canvas ***Arrays and Pointers*** page

## Background Information:
### Project overview:
Parsing data from databases and flat files (such as comma-delimited files - csv) is universally important in our modern world.
The ability to take a raw data set and store the data for queries through a front end application is what drives many business, personal, and academic decisions.

Statistics is a complex sub-field of mathematics that boils down to trying to find important trends, correlations, and outlying data to garner insight into the ever-growing complexity of our digital world.
In this project, we'll keep it simple and use only statistical functions you are already familiar with (well maybe one that you are not familiar with).

#### Mean
The average, denoted **&mu;**, of a data set is usually referred to as the *mean* of the data.
For a data set `1, 3, 3, 5, 6`, the mean of that set is the sum of all the data divided by the number of data points.
e\.g\.

<img src="https://latex.codecogs.com/png.image?\dpi{110}&space;\bg_white&space;\frac{1&plus;2&plus;3&plus;5&plus;6}{5}=3.4" title="average" />

#### Standard Deviation
Standard deviation, often denoted **&sigma;** is calculated as follows:

<img src="https://latex.codecogs.com/png.image?\dpi{110}&space;\bg_white&space;\sigma=\sqrt{\frac{\Sigma\(x_{i}-\mu\)^{2}}{N}}" title="standard deviation formula" />

`N` is the number of data points in the set (referred to in statistics as a _population_).
So, for the sample data set `1, 2, 3, 5, 6`, the mean calculated above is 3.4. Plugging in for &sigma;, we'd get

<img src="https://res.cloudinary.com/dm3fdmzec/image/upload/v1597336594/stdev.png" alt="Standard deviation example" width=600 />

The importance of the standard deviation is that any data more than two standard deviations from the mean is considered statistically significant and is referred to as an outlier.
As such, it can be used to identify data that was improperly measured, or is otherwise unexpected.

#### This Project
We'll be using the above functions on a set of input data to help identify unusual morbidity data reports broken out by state.
The data from the CDC was sourced here https://data.cdc.gov/NCHS/Weekly-Counts-of-Deaths-by-State-and-Select-Causes/muzy-jte6 and here https://data.cdc.gov/NCHS/Weekly-Counts-of-Deaths-by-State-and-Select-Causes/3yf8-kanr.

### Project Requirements:
Your application must function as described below:
1. In order to ensure that your statistical calculations are correct, your program must pass all of the given tests in the `*.cpp` files in the test directory, e.g. [test/test-stats.cpp](test/test-stats.cpp).
	1. The test suites are:
		1. [test-week-object](test/test-week-object.cpp) - This tests the object used to store the data for a given week.
		1. [test-stats](test/test-stats.cpp) - This tests the static methods needed to do the necessary calculations.
		1. [test-state-object](test-state-object.cpp) - This tests the object used to store the data for a given state.
		1. [test-morbidity](test/test-morbidity.cpp) - This tests your file reading functions and is essentially an integration test.
			Once it is running, you are ready to build the main program (which should at that point be rather trivial).
	1. Running all of these tests must be possible by running `make test-all`.
1. Building an executable called **main** must be possible by running `make main`.
1. Running the main program should prompt a user for the input file name.
	1. If the input file is not present, ***Unable to read input file*** should be displayed to the user and they should be prompted again to enter a file name.
1. Once the file has been loaded, your program should offer the ability to query for the following things:
	1. All-time average (mean) for a given state.
	1. List of weeks that are statistical outliers for a given state.
	1. List all states and their respective number of statistically significant (more than two standard deviations from the mean) weeks.
1. Your project will lose points if memory leaks exist.

#### Sample data
The data will be in the following format.
For this project, it is safe assume the data is properly formatted, that is exactly 3 columns will be present in each row of data.
```
State,Week Ending Date,All Cause
Florida,2014-01-04,2101
Florida,2014-01-11,3877
Florida,2014-01-18,3800
```


## Sample Run
<pre><code>Welcome to the somber data viewer. Enter the file name with the morbidity data: <b>foo.bar</b>
Unable to read input file!
Enter the file name with the morbidity data: <b>data.csv</b>
	1 - Output the mean for a state
	2 - Get a list of outliers for a state
	3 - List all states with statistically significant data points
	anything other than 1-3 will end the application.
Please choose an option from the above menu: <b>1</b>
Enter the name of the state to search: <b>Texas</b>
-------------------------
The mean deaths for Texas is 4000.91
-------------------------
	1 - Output the mean for a state
	2 - Get a list of outliers for a state
	3 - List all states with statistically significant data points
	anything other than 1-3 will end the application.
Please choose an option from the above menu: <b>2</b>
Enter the name of the state to search: <b>North Carolina</b>
-------------------------
Statistical outliers for North Carolina
	2020-12-19 - total deaths: 2588
	2020-12-26 - total deaths: 2670
	2021-01-02 - total deaths: 2837
	... Sample output truncated for brevity
	2021-07-24 - total deaths: 495
	2021-07-31 - total deaths: 434
	2021-08-07 - total deaths: 319
-------------------------

	1 - Output the mean for a state
	2 - Get a list of outliers for a state
	3 - List all states with statistically significant data points
	anything other than 1-3 will end the application.
Please choose an option from the above menu: <b>3</b>
-------------------------
	Alabama: 16 outlying weeks
	Alaska: 18 outlying weeks
	... Sample output truncated for brevity
	Wisconsin: 14 outlying weeks
	Wyoming: 18 outlying weeks
-------------------------
	1 - Output the mean for a state
	2 - Get a list of outliers for a state
	3 - List all states with statistically significant data points
	anything other than 1-3 will end the application.
Please choose an option from the above menu: <b>9999</b></code></pre>

## Implementation Notes:
1. Create a project that is object oriented, therefore there should be several classes.
1. The input file will match the exact format given above.
1. Ensure that `make test-all` passes all test assertions, otherwise you will not get full credit.
1. Don't forget to build _main.cpp_, it too is required for full credit.

### UML
Below is the UML of a possible solution to this project

![UML of Stats class](https://res.cloudinary.com/dm3fdmzec/image/fetch/http://www.plantuml.com/plantuml/png/SoWkIImgAStDuSh8J4bLICqjAAbKo4tDJKejAkPApaaiBbO8BaaiALQevj9MA0QoCfCLt5DBV5CJynGqmbDJirqIInAZOtKKClDADAqKKl9Bat9IuKg1UbrIo_0ehELoICrB0LeF0000)
![UML of Week class](https://res.cloudinary.com/dm3fdmzec/image/fetch/http://www.plantuml.com/plantuml/png/LSz1gi8m4CRnVKung_BAqmk4K0ejU0JNGpjgCKqaymKNujrDiHIxI_x9_61Q1IVasPl1iogTHUuzWytB76baY2N5QAqYJU5A9RBt7MSLjJG5B2KmSk9z_Tya-li1wjt3SZi9Uc7SkfW3Ig8X1iMg6ESkQP8mDWt5XoH6JCwjOYoay5nHp3XynpQxecSvrPPsFytRj0LRjlq0)
![UML of State class](http://www.plantuml.com/plantuml/png/RP0_JyCm4CNtV8gRK5E4r8N5KgKM6XXG6aI5oXQvzK4Z_0VvpcL0yDcnSL4IgKlYEx_xlNTU44lFmUXYhoKHR5WombTn1LOQ542iX23sdNs3sFn4V2S1s_XRIPPJIC9WTkYRrzHuT9tbA8XVcCEik3m19qDE8fVzrTvPubnSbD3ta-HdSBv7NakJ2lWR6OUBWgLIATZ8h1HmT9s2F5-Zj2kKVA01HRcmqvWKEKczV6dNp_LDzTGsT-ssgXus_mjTpsOPr0JM7New7sQQjr1uXCc9RgBp6SSUTUk2vHwN39F0VQ2Nx3pCnmy5_a2bo0KKtyK2hGf6_m80)
![UML of Morbidity class](http://www.plantuml.com/plantuml/png/TP5FImCn4CNl-HHpR2iUzR0Wj6hN5bmBtIhUocmpAu5i8icaAAAVtUmVs5JgOG_lDoylRoTpp-WuD5eSD7eFXNMLaee_uKjSWZBlWJFmBBDCrPuTOGEHIsGiEpKCuqYPjz5WGbEHszGb8vFFOX17wWVLqTaiaeCrdg5OlEwVdelRvNQ_oVVbRh5RbjqPk87hgsWxebPotPR9bQOCAckrYFo1U6qaVUJMTPamITfC-_G-I8YBvDycqoX__kX7Y_8U6QFAu6YLX0YtX78LFt8fRYyk2Ctv-wGDbQR1jWci5Rax6mp_N-_4wy_x4ZPh3wpGlvpi1IQ3jrzGwoc9nt6Q2dKa1XkQZkQnmThKDhTkeNN_W4bocY6-nPoC38t-1G00)

### Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted" the assignment.
	1. After pushing, with `git push origin main`, visit the web URL of your repository to verify that your code is there.
	If you don't see the code there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your score for your submission.
	1. The auto-grading build should begin automatically when you push your code to GitHub.
	2. If your program will not compile, the graders will not be responsible for trying to test it.
	3. You should get an email regarding the status of your build, if it does not pass, keep trying.

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects received after that time will get a grade of zero.
- Please review the academic honesty policy.
	- Note that viewing another student's solution, whether in whole or in part, is considered academic dishonesty.
	- Also note that submitting code obtained through the Internet or other sources, whether in whole or in part, is considered academic dishonesty.
	- All programs submitted will be reviewed for evidence of academic dishonesty, and all violations will be handled accordingly.

## Grading
- View on GitHub:
	1. On your GitHub repo page, Click the :arrow_forward: **Actions** tab to see your graded results.
	1. If it isn't a green check mark (:heavy_check_mark:) then at least part of the testing failed.
	1. Click the commit message for the failing version then click "Autograding" on the left side of the page.
	1. Follow the :x: path and expand things to see what errors exist.
	1. At the bottom of the _education/autograding_ section, you can view the score for the auto-grading portion of the rubric.
		It will look something like ***40/90***.
